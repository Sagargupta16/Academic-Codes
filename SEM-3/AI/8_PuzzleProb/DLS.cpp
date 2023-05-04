#include<bits/stdc++.h>
using namespace std;
int getInvCount(vector<int>& arr)
{
    int inv_count = 0;
    for (int i = 0; i < 9 - 1; i++)
        for (int j = i + 1; j < 9; j++)
            if (arr[j] && arr[i] && arr[i] > arr[j])
                inv_count++;
    return inv_count;
}

bool isSolvable(vector<vector<int>>& puzzle){
    vector<int> arr;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            arr.push_back(puzzle[i][j]);
    int invCount = getInvCount(arr);
    return (invCount % 2 == 0);
}

void getRandom(vector<vector<int>>& v){
    srand(time(0));
    int n = 3;
    vector<int> temp;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            temp.push_back(i*n+j);
        }
    }
    random_shuffle(temp.begin(), temp.end());
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            v[i][j] = temp[i*n+j];
        }
    }
}

void print(vector<vector<int>> v){
    int n = 3;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << v[i][j] << " ";
        }
    }
    cout<<" ";
}

bool isGoal(vector<vector<int>> v){
    vector<vector<int>> goal = {{1,2,3},{4,5,6},{7,8,0}};
    int n = 3;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(v[i][j] != goal[i][j]) return false;
        }
    }
    return true;
}

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

    cout<<endl;
    depth++;
    if(x+1<3){
        swap(v[x][y],v[x+1][y]);
        print(v);
        ans = dfs(v,cnt,x+1,y,visited,flag,depth,maxDepth);
        if(flag) return ans;
        swap(v[x][y],v[x+1][y]);
    }
    if(y+1<3){
        swap(v[x][y],v[x][y+1]);
        print(v);
        ans = dfs(v,cnt,x,y+1,visited,flag,depth,maxDepth);
        if(flag) return ans;
        swap(v[x][y],v[x][y+1]);
    }
    if(x-1>=0){
        swap(v[x][y],v[x-1][y]);
        print(v);
        ans = dfs(v,cnt,x-1,y,visited,flag,depth,maxDepth);
        if(flag) return ans;
        swap(v[x][y],v[x-1][y]);
    }
    if(y-1>=0){
        swap(v[x][y],v[x][y-1]);
        print(v);
        ans = dfs(v,cnt,x,y-1,visited,flag,depth,maxDepth);
        if(flag) return ans;
        swap(v[x][y],v[x][y-1]);
    }
    cout<<endl;
    return ans;
}

int main(){
    int counter;
    vector<vector<int>> v(3, vector<int>(3));
    vector<vector<vector<int>>> visited;
    int ex = 5,flag=0,limit=5,cnt=0;
    for(int i=0;i<ex;i++){
        visited = vector<vector<vector<int>>>();
        do{
            getRandom(v);
        }while(!isSolvable(v));
        cout<<"Initial State: ";
        print(v);
        counter = 0;
        flag=0;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(v[i][j] == 0){
                    dfs(v,counter,i,j,visited,flag,0,limit);
                }
            }
        }
        if(flag){
            cout<<endl<<"Goal State: "<<endl;
            cnt++;
        }
        else{
            cout<<endl<<"Goal State not found"<<endl;
        }
    }
    cout<<endl<<"Success Rate: "<<cnt*100/ex<<"%";

    return 0;
}