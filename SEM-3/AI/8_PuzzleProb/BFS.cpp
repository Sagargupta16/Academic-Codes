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

int bfs(vector<vector<int>>& v, vector<vector<vector<int>>> visited){
    queue<vector<vector<int>>> q;
    q.push(v);
    visited.push_back(v);
    int cnt=0;
    while(!q.empty()){
        if(cnt>=100) return cnt;
        vector<vector<int>> temp = q.front();
        q.pop();
        print(temp);
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

int main(){
    int counter,sum=0;
    vector<vector<int>> v(3, vector<int>(3));
    vector<vector<vector<int>>> visited;
    int ex = 5,flag=0;
    for(int i=0;i<ex;i++){
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
                    counter = bfs(v,visited);
                }
            }
        }
        sum += counter;
        if(counter>=100) cout<<endl<<"Not Solvable"<<endl;
        else cout<<endl<<"Goal State: "<<counter<<endl;

    }
    cout <<endl<< "Average number of nodes generated: " << sum/ex << endl;

    return 0;
}