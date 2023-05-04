#include <iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    int *a = new int[n];
    for (int i=0;i<n;i++){
        a[i] = i+1;
    }
    int *b = a;
    for (int i=0;i<n;i++,b++){
        cout<<*b<<" ";
    }
    cout<<endl;
}