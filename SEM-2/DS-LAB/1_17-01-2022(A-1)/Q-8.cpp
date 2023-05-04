#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter number of element in array : ";
    cin>>n;
    int ar[n];
    cout<<"Enter Elements of Array : ";
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }

    cout<<"Peak Elements are : ";
    if(ar[0]>ar[1]){
        cout<<ar[0]<<" ";
    }
    for(int i=1;i<n-1;i++){
        if(ar[i]>ar[i-1] && ar[i]>ar[i+1]){
            cout<<ar[i]<<" ";
        }
    }
    if(ar[n-1]>ar[n-2]){
        cout<<ar[n-1]<<" ";
    }

    return 0;
}