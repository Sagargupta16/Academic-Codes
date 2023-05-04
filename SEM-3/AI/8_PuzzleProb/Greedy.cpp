#include <bits/stdc++.h>
using namespace std;
#define N 3

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

class Node{
    public:
    Node *parent;
    int mat[N][N];
    int x,y,cost,level;
};

void printMatrix(int mat[N][N]){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++)
            cout<<mat[i][j]<<" ";
        cout<<endl;
    }
}

Node *newNode(int mat[N][N], int x, int y, int newX,int newY, int level, Node *parent){
    Node *node = new Node;
    node->parent = parent;
    memcpy(node->mat, mat, sizeof node->mat);
    swap(node->mat[x][y], node->mat[newX][newY]);
    node->cost = INT_MAX;
    node->level = level;
    node->x = newX;
    node->y = newY;
    return node;
}

int row[] = {1, 0, -1, 0};
int col[] = {0, -1, 0, 1};

int calculateCost(int initial[N][N], int final[N][N]){
    int count = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (initial[i][j] && initial[i][j] != final[i][j])
                count++;
    return count;
}

int isSafe(int x, int y){
    return (x >= 0 && x < N && y >= 0 && y < N);
}

void printPath(Node *root){
    if (root == NULL) return;
    // printPath(root->parent);
    // printMatrix(root->mat);
    // cout<<endl;
}

class comp{
    public:
    bool operator()(const Node *lhs, const Node *rhs) const{
        return (lhs->cost + lhs->level) > (rhs->cost + rhs->level);
    }
};

int solve(int initial[N][N], int x, int y,int final[N][N]){
    priority_queue<Node *, vector<Node *>, comp> pq;
    Node *root = newNode(initial, x, y, x, y, 0, NULL);
    root->cost = calculateCost(initial, final);
    pq.push(root);
    int cnt=0;
    while (!pq.empty()){
        if(cnt>1000) break;
        Node *min = pq.top();
        pq.pop();
        cnt++;
        if (min->cost == 0){
            printPath(min);
            return cnt;
        }
        for (int i = 0; i < 4; i++){
            if (isSafe(min->x + row[i], min->y + col[i])){
                Node *child = newNode(min->mat, min->x,min->y, min->x + row[i],min->y + col[i],min->level + 1, min);
                child->cost = calculateCost(child->mat, final);
                pq.push(child);
            }
        }
    }
    return cnt;
}

int main(){
    vector<vector<int>> v(3,vector<int>(3));
    int sum=0,counter=0,runs=5;
    vector<vector<vector<int>>> vv = {{{1,2,3},{4,5,6},{7,8,0}},{{1,2,3},{4,5,6},{7,0,8}},{{1,2,3},{4,5,6},{0,7,8}},{{1,2,3},{4,5,0},{7,8,6}},{{1,2,3},{4,5,6},{0,7,8}},{{1,2,3},{0,4,5},{7,8,6}},{{1,2,3},{4,0,6},{7,5,8}},{{1,2,3},{5,6,0},{4,7,8}},{{1,2,3},{4,0,5},{7,8,6}}};

    for(int i=0;i<vv.size();i++){
        do{
            getRandom(v);
        }while(!isSolvable(v));
        int initial[N][N] = {{vv[i][0][0],vv[i][0][1],vv[i][0][2]},{vv[i][1][0],vv[i][1][1],vv[i][1][2]},{vv[i][2][0],vv[i][2][1],vv[i][2][2]}};
        int final[N][N] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};
        int x , y ;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(initial[i][j]==0){
                    x=i;
                    y=j;
                }
            }
        }
        counter = solve(initial, x, y, final);
        sum+=counter;
        cout<<"Number of nodes expanded: "<<counter<<endl;
        counter=0;
    }
    cout<<"Average number of nodes expanded: "<<sum/runs<<endl;

    return 0;
}