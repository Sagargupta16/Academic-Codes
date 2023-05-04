// Missing Value Treatment
#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

//1 Dropping Missing Values
void method1(vector<int> v){
    cout<<"Method 1: Dropping Missing Values"<<endl;
    vector<int> v1;
    for(int i=0;i<v.size();i++){
        if(v[i]!=-1){
            v1.push_back(v[i]);
        }
    }
    printVector(v1);
}

//2 Mean Imputation
void method2(vector<int> v){
    cout<<"Method 2: Mean Imputation"<<endl;
    int sum=0;
    int count=0;
    for(int i=0;i<v.size();i++){
        if(v[i]!=-1){
            sum+=v[i];
            count++;
        }
    }
    int mean = sum/count;
    for(int i=0;i<v.size();i++){
        if(v[i]==-1){
            v[i]=mean;
        }
    }
    printVector(v);
}

// 3 Filling with nearest next or previous value
void method3(vector<int> v){
    cout<<"Method 3: Filling with nearest next or previous value"<<endl;
    for(int i=0;i<v.size();i++){
        if(v[i]==-1){
            if(i==0){
                v[i]=v[i+1];
            }
            else if(i==v.size()-1){
                v[i]=v[i-1];
            }
            else{
                v[i]=(v[i-1]+v[i+1])/2;
            }
        }
    }
    printVector(v);
}

// 4 Filling with median
void method4(vector<int> v){
    cout<<"Method 4: Filling with median"<<endl;
    vector<int> v1;
    for(int i=0;i<v.size();i++){
        if(v[i]!=-1){
            v1.push_back(v[i]);
        }
    }
    sort(v1.begin(),v1.end());
    int median;
    if(v1.size()%2==0){
        median = (v1[v1.size()/2]+v1[v1.size()/2-1])/2;
    }
    else{
        median = v1[v1.size()/2];
    }
    for(int i=0;i<v.size();i++){
        if(v[i]==-1){
            v[i]=median;
        }
    }
    printVector(v);
}


int main(){
    vector<int> v = { 1,7,12,-1,16,18,19,21,-1,-1,28,54,56,78,89,-1,91,-1,100};
    cout<<"Original Vector: ";
    printVector(v);
    cout<<endl;
    
    method1(v);
    method2(v);
    method3(v);
    method4(v);

    return 0;
}