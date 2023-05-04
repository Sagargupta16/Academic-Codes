// Q-2a Data Smoothing (Binning)

#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

// 1a Binning with mean value
void method1a(vector<int> v){
    cout<<"Method 1a: Binning with Mean Value"<<endl;
    int n = v.size();
    int binSize = 4;
    int binCount = n/binSize;
    int binRemainder = n%binSize;
    int binStart = 0;
    int binEnd = binSize;
    for(int i=0;i<binCount;i++){
        int sum=0;
        for(int j=binStart;j<binEnd;j++){
            sum+=v[j];
        }
        int mean = sum/binSize;
        for(int j=binStart;j<binEnd;j++){
            v[j]=mean;
        }
        binStart+=binSize;
        binEnd+=binSize;
    }

    printVector(v);
}

// 1b Binning with median value
void method1b(vector<int> v){
    cout<<"Method 1b: Binning with Median Value"<<endl;
    int n = v.size();
    int binSize = 4;
    int binCount = n/binSize;
    int binRemainder = n%binSize;
    int binStart = 0;
    int binEnd = binSize;
    for(int i=0;i<binCount;i++){
        vector<int> v1;
        for(int j=binStart;j<binEnd;j++){
            v1.push_back(v[j]);
        }
        sort(v1.begin(),v1.end());
        int median = v1[binSize/2];
        for(int j=binStart;j<binEnd;j++){
            v[j]=median;
        }
        binStart+=binSize;
        binEnd+=binSize;
    }

    printVector(v);
}

// 1c Binning with Boundary value
void method1c(vector<int> v){
    cout<<"Method 1c: Binning with Boundary Value"<<endl;
    int n = v.size();
    int binSize = 4;
    int binCount = n/binSize;
    int binRemainder = n%binSize;
    int binStart = 0;
    int binEnd = binSize;
    for(int i=0;i<binCount;i++){
        vector<int> v1;
        for(int j=binStart;j<binEnd;j++){
            v1.push_back(v[j]);
        }
        int start = v1[0];
        int end = v1[binSize-1];
        for(int j=binStart;j<binEnd;j++){
            if(end-v[j] > v[j]-start){
                v[j]=start;
            }
            else{
                v[j]=end;
            }
        }
        binStart+=binSize;
        binEnd+=binSize;
    }
    printVector(v);
}

int main(){
    vector<int> v = {8,12,9,54,41,7,12,95,23,44,86,72,71,32,21,45};
    cout<<"Original Vector: ";
    printVector(v);
    sort (v.begin(), v.end());
    cout<<"Sorted Vector: ";
    printVector(v);
    method1a(v);
    method1b(v);
    method1c(v);
    cout<<endl;


}