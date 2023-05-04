// Q-2b Data Smoothing (Cluster)
#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

// 2Clustering
void method2(vector<int> v){
    cout<<"Method 2: Clustering"<<endl;
    int n = v.size();
    int totalCluster = 4;
    int sum = 0 ,mn=v[0],mx=v[0];
    for(int i=0;i<n;i++){
        mn=min(mn,v[i]);
        mx=max(mx,v[i]);
        sum+=v[i];
    }
    int mean = sum/n;
    int clusterSize = (mx-mn)/totalCluster;
    int clusterStart = mn;
    int clusterEnd = clusterStart+clusterSize;
    for(int i=0;i<totalCluster;i++){
        int sum=0;
        int count=0;
        for(int j=0;j<n;j++){
            if(v[j]>=clusterStart && v[j]<=clusterEnd){
                sum+=v[j];
                count++;
            }
        }
        int mean = sum/count;
        for(int j=0;j<n;j++){
            if(v[j]>=clusterStart && v[j]<=clusterEnd){
                v[j]=mean;
            }
        }
        clusterStart+=clusterSize;
        clusterEnd+=clusterSize;
    }
    v[n-1]=v[n-2];
    printVector(v);
}

int main(){
    vector<int> v = {66,30,9,54,41,7,12,95,23,44,86,72,71,32,21,45,33,24,98,77};
    cout<<"Original Vector: ";
    printVector(v);
    sort (v.begin(), v.end());
    cout<<"Sorted Vector: ";
    printVector(v);
    method2(v);
}