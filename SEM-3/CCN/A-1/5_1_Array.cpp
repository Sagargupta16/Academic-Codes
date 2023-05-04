#include <iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    int a[n];
    cout<<"Enter the elements of the array: ";
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"The elements of the array are: ";
    for (int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i>0) a[i] += a[i-1];
    }
    cout<<endl;
    cout<<"The cumulative sum of the array is: ";
    for (int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}