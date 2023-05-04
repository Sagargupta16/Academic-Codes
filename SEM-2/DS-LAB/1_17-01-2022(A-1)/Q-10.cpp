#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter number of element in array : ";
    cin>>n;
    int ar[n],br[n];
    cout<<"Enter Elements of Array : ";
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    int z;
    cout<<"Enter number z : ";
    cin>>z;

    for(int i=0;i<n;i++){
        if(z-ar[i]>0){
            br[i]=z-ar[i];
        }
        else{
            br[i]=ar[i]-z;
        }
    }
    for (int i=0;i<n-1;i++){
        for (int j=0;j<n-i-1;j++){
            if (br[j]>br[j+1]){
                int t = br[j];
                br[j] = br[j+1];
                br[j+1] = t;
                t = ar[j];
                ar[j] = ar[j+1];
                ar[j+1] = t;
            }
        }
    }
    cout<<"Sorted array on basis of absolute difference from "<<z<<" is :";
    for(int i=0;i<n;i++){
        cout<<ar[i]<<" ";
    }

    return 0;
}