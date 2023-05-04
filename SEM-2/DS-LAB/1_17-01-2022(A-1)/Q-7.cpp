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
    int k,count=0;
    cout<<"Enter value of difference you want to find between array values : ";
    cin>>k;
    cout<<"The distinct pairs for difference "<<k<<" are : ";

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(ar[i]-ar[j]==k){
                cout<<"["<<ar[i]<<","<<ar[j]<<"] ";
                count++;
            }
        }
    }
    cout<<endl;
    cout<<"Number of distinct pairs for difference "<<k<<" are: "<<count<<endl;
    return 0;
}