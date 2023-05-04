#include<iostream>
using namespace std;

void countSort(int a[], int n) {
    int max=a[0];
    for(int i=1; i<n; i++) {
        if(a[i]>max) max=a[i];
    }
    int b[max+1]={0};
    for(int i=0; i<n; i++) {
        b[a[i]]++;
    }
    int k=0;
    for(int i=0; i<=max; i++) {
        for(int j=0; j<b[i]; j++) {
            a[k]=i;
            k++;
        }
    }
}

int main(){
    int a[10] = {15,978,763,893,6352,98,282,2814,4738,3};
    int n= sizeof(a)/sizeof(a[0]);
    cout<<"Before sorting: ";
    for(int i=0; i<n; i++) cout<<a[i]<<" ";
    cout<<endl;
    countSort(a, n);
    cout<<"After sorting: ";
    for(int i=0; i<n; i++) cout<<a[i]<<" ";
}