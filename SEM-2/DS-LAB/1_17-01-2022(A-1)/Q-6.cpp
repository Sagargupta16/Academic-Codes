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
    int g;
    cout<<"After replacement, the modified array is: ";
    for(int i=0;i<n-1;i++){
        g=0;
        for(int j=i+1;j<n;j++){
            if(ar[j]>g){
                g=ar[j];
            }
        }
        ar[i]=g;
        cout<<ar[i]<<" ";
    }
    ar[n-1]=0;
    cout<<ar[n-1]<<endl;
    return 0;
}