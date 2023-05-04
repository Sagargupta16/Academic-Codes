#include<bits/stdc++.h>
using namespace std;
int getInvCount(vector<int>& arr){
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

int isGoal(vector<vector<int>> v){
    vector<vector<int>> goal = {{1,2,3},{4,5,6},{7,8,0}};
    int n = 3;
    int cnt=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(v[i][j] == goal[i][j]) cnt++;
        }
    }
    return cnt;
}

void Astar(priority_queue<pair<int,vector<vector<int>>>>& pq,int& cnt,vector<vector<vector<int>>>& visited){
    if(isGoal(pq.top().second) == 9) return;
    for(int i=0; i<visited.size(); i++){
        if(visited[i] == pq.top().second){ 
            pq.pop();
            i=-1;
        }
    }
    visited.push_back(pq.top().second);
    cnt++;
    vector<vector<int>> v = pq.top().second;
    cout<<endl;
    print(v);
    pq.pop();
    int x,y;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(v[i][j] == 0){
                x = i;
                y = j;
                break;
            }
        }
    }
    if(x-1>=0){
        swap(v[x][y],v[x-1][y]);
        pq.push({isGoal(v),v});
        swap(v[x][y],v[x-1][y]);
    }
    if(x+1<3){
        swap(v[x][y],v[x+1][y]);
        pq.push({isGoal(v),v});
        swap(v[x][y],v[x+1][y]);
    }
    if(y-1>=0){
        swap(v[x][y],v[x][y-1]);
        pq.push({isGoal(v),v});
        swap(v[x][y],v[x][y-1]);
    }
    if(y+1<3){
        swap(v[x][y],v[x][y+1]);
        pq.push({isGoal(v),v});
        swap(v[x][y],v[x][y+1]);
    }
    Astar(pq,cnt,visited);
}

int main(){
    int counter,sum=0;
    vector<vector<int>> v(3, vector<int>(3));
    priority_queue<pair<int,vector<vector<int>>>> pq;
    vector<vector<vector<int>>> visited;
    int flag = 0,runs=3;
    for(int i=0; i<runs; i++){
        v = vector<vector<int>>(3,vector<int>(3));
        pq = priority_queue<pair<int,vector<vector<int>>>>();
        visited = vector<vector<vector<int>>>();
        do{
            getRandom(v);
        }while(!isSolvable(v));
        print(v);
        counter = 0;
        pq.push({isGoal(v),v});
        Astar(pq,counter,visited);
        sum += counter;
        cout<<endl<<"Number of nodes expanded: "<<counter<<endl;
    }
    cout<<endl<<"Average number of nodes expanded: "<<sum/runs<<endl;
    return 0;
}