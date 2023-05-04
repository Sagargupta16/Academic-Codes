#include<iostream>
using namespace std;

int main(){
    int n,k;
    cout<<"Enter number of Elements in an Array : ";
    cin>>n;
    int ar[n];
    cout<<"Enter Array Values : ";
    for (int i = 0; i < n; i++)
    {
        cin>>ar[i];
    }
    cout<<"Enter 'K' Value : ";
    cin>>k;
    int count=0;
    cout<<"Pairs are : ";
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if((ar[i]+ar[j])%k==0){
                count++;
                cout<<"("<<ar[i]<<","<<ar[j]<<") ";
            }
        }
    }
    cout<<endl<<"No. of pairs are : "<<count<<endl;
    return 0;
}