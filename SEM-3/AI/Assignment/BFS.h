// #include "Common.h"

int bfs(vector<vector<int>>& v, vector<vector<vector<int>>> visited){
    queue<vector<vector<int>>> q;
    q.push(v);
    visited.push_back(v);
    int cnt=0;
    while(!q.empty()){
        if(cnt>=1000) return cnt;
        vector<vector<int>> temp = q.front();
        q.pop();
        if(isGoal(temp)){
            return cnt;
        }
        int n = 3;
        int x,y;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(temp[i][j] == 0){
                    x = i;
                    y = j;
                }
            }
        }
        if(x-1 >= 0){
            vector<vector<int>> temp1 = temp;
            swap(temp1[x][y], temp1[x-1][y]);
            if(find(visited.begin(), visited.end(), temp1) == visited.end()){
                q.push(temp1);
                visited.push_back(temp1);
            }
        }
        if(x+1 < n){
            vector<vector<int>> temp1 = temp;
            swap(temp1[x][y], temp1[x+1][y]);
            if(find(visited.begin(), visited.end(), temp1) == visited.end()){
                q.push(temp1);
                visited.push_back(temp1);
            }
        }
        if(y-1 >= 0){
            vector<vector<int>> temp1 = temp;
            swap(temp1[x][y], temp1[x][y-1]);
            if(find(visited.begin(), visited.end(), temp1) == visited.end()){
                q.push(temp1);
                visited.push_back(temp1);
            }
        }
        if(y+1 < n){
            vector<vector<int>> temp1 = temp;
            swap(temp1[x][y], temp1[x][y+1]);
            if(find(visited.begin(), visited.end(), temp1) == visited.end()){
                q.push(temp1);
                visited.push_back(temp1);
            }
        }
        cnt++;
    }
    return cnt;
    
}

int breadthFirstSearch(){
    int counter,sum=0;
    vector<vector<int>> v(3, vector<int>(3));
    vector<vector<vector<int>>> visited;
    int ex = 1,flag=0;
    for(int i=0;i<ex;i++){
        do{
            getRandom(v);
        }while(!isSolvable(v));
        counter = 0;
        flag=0;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(v[i][j] == 0){
                    counter = bfs(v,visited);
                }
            }
        }
        sum += counter;
        cout<<"Goal State: "<<counter<<endl;
    }
    return counter;
}