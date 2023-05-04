// #include "Common.h"

int dfs(vector<vector<int>>& v,int& cnt,int x,int y,vector<vector<vector<int>>>& visited,int& flag,int depth,int maxDepth){
    if(depth > maxDepth) return 0;
    if(isGoal(v)){
        flag = 1;
        return cnt;
    }
    for(int i=0; i<visited.size(); i++){
        if(visited[i] == v) return cnt;
    }
    if(flag == 1) return cnt;
    
    cnt++;

    visited.push_back(v);
    int ans = cnt;
    depth++;
    if(x+1<3){
        swap(v[x][y],v[x+1][y]);
        ans = dfs(v,cnt,x+1,y,visited,flag,depth,maxDepth);
        if(flag) return ans;
        swap(v[x][y],v[x+1][y]);
    }
    if(y+1<3){
        swap(v[x][y],v[x][y+1]);
        ans = dfs(v,cnt,x,y+1,visited,flag,depth,maxDepth);
        if(flag) return ans;
        swap(v[x][y],v[x][y+1]);
    }
    if(x-1>=0){
        swap(v[x][y],v[x-1][y]);
        ans = dfs(v,cnt,x-1,y,visited,flag,depth,maxDepth);
        if(flag) return ans;
        swap(v[x][y],v[x-1][y]);
    }
    if(y-1>=0){
        swap(v[x][y],v[x][y-1]);
        ans = dfs(v,cnt,x,y-1,visited,flag,depth,maxDepth);
        if(flag) return ans;
        swap(v[x][y],v[x][y-1]);
    }
    return ans;
}

int IterativeDeepeningSearch(){
    int counter;
    vector<vector<int>> v(3, vector<int>(3));
    vector<vector<vector<int>>> visited;
    int ex = 1,flag=0,limit=5,cnt=0;
    for(int i=0;i<ex;i++){
        do{
            getRandom(v);
        }while(!isSolvable(v));
        counter = 0;
        flag=0;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(v[i][j] == 0){
                    for(int k=0; k<=limit; k++){
                        visited = vector<vector<vector<int>>>();
                        dfs(v,counter,i,j,visited,flag,0,k);
                    }
                }
            }
        }
        if(flag){
            cout<<endl<<"Goal State Found "<<endl;
            cnt++;
        }
        else{
            cout<<endl<<"Goal State not found"<<endl;
        }
    }
    return cnt;
}