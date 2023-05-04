#include<bits/stdc++.h>
using namespace std;

void BestFit(vector<int> &processes, vector<int> &blocks){
    int n = processes.size(), m = blocks.size();
    vector<int> allocated(m, 0);
    int count = 0;
    cout<<endl;
    for(int i = 0; i < n; i++){
        int flag = 0;
        int min = INT_MAX, index = -1;
        for(int j = 0; j < m; j++){
            if(allocated[j] == 0 && blocks[j] >= processes[i] && blocks[j] - processes[i] < min){
                min = blocks[j] - processes[i];
                index = j;
            }
        }
        if(index != -1){
            cout<<"Process "<<i + 1<<" is allocated to block "<<index + 1<<endl;
            allocated[index] = 1;
            flag = 1;
            count++;
        }
        if(flag == 0){
            cout << "Process " << i + 1 << " cannot be allocated memory." << endl;
        }
    }
    cout <<endl<< count << " memory blocks are allocated." << endl <<endl;
}

int main(){
    vector<int> blockSize;
    cout<<"Enter the number of memory blocks: ";
    int m;
    cin>>m;
    cout<<"Enter the size of memory blocks: ";
    for(int i = 0; i < m; i++){
        int x;
        cin>>x;
        blockSize.push_back(x);
    }
    vector<int> processSize;
    cout<<"Enter the number of processes: ";
    int n;
    cin>>n;
    cout<<"Enter the size of processes: ";
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        processSize.push_back(x);
    }
    BestFit(processSize, blockSize);
    return 0;
}