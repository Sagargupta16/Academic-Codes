// #include "Common.h"

void AstarHelper(priority_queue<pair<int,vector<vector<int>>>>& pq,int& cnt,vector<vector<vector<int>>>& visited){
    if(isGoalC(pq.top().second) == 9) return;
    for(int i=0; i<visited.size(); i++){
        if(visited[i] == pq.top().second){ 
            pq.pop();
            i=-1;
        }
    }
    visited.push_back(pq.top().second);
    cnt++;
    vector<vector<int>> v = pq.top().second;
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
        pq.push({isGoalC(v),v});
        swap(v[x][y],v[x-1][y]);
    }
    if(x+1<3){
        swap(v[x][y],v[x+1][y]);
        pq.push({isGoalC(v),v});
        swap(v[x][y],v[x+1][y]);
    }
    if(y-1>=0){
        swap(v[x][y],v[x][y-1]);
        pq.push({isGoalC(v),v});
        swap(v[x][y],v[x][y-1]);
    }
    if(y+1<3){
        swap(v[x][y],v[x][y+1]);
        pq.push({isGoalC(v),v});
        swap(v[x][y],v[x][y+1]);
    }
    AstarHelper(pq,cnt,visited);
}

int Astar(){
    int counter,sum=0;
    vector<vector<int>> v(3, vector<int>(3));
    priority_queue<pair<int,vector<vector<int>>>> pq;
    vector<vector<vector<int>>> visited;
    int flag = 0,runs=1;
    for(int i=0; i<runs; i++){
        v = vector<vector<int>>(3,vector<int>(3));
        pq = priority_queue<pair<int,vector<vector<int>>>>();
        visited = vector<vector<vector<int>>>();
        do{
            getRandom(v);
        }while(!isSolvable(v));
        counter = 0;
        pq.push({isGoal(v),v});
        AstarHelper(pq,counter,visited);
        sum += counter;
        cout<<"Number of nodes expanded: "<<counter<<endl;
    }
    return counter;
}