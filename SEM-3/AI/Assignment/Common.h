#include "bits/stdc++.h"
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

bool isGoal(vector<vector<int>> v){
    vector<vector<int>> goal = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};
    int n = 3;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (v[i][j] != goal[i][j]) return false;
        }
    }
    return true;
}

int isGoalC(vector<vector<int>> v){
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
