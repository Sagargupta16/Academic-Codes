#include<iostream>
using namespace std;

int main(){

    int A[]={5,3,6,9,0,1,2,-2,6,11,-7};
    int n = sizeof(A)/sizeof(A[0]);

    cout<<"Array Before Sort is : ";
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;

    int i,j,z;
    for(i=1;i<n;i++){
        z=A[i];
        for(j=i-1;j>=0;j--){
            if(z<=A[j]){
                A[j+1] = A[j];
            }
            else{
                break;
            }
        }
        A[j+1]=z;
    }//O(n^2)

    cout<<"Array After Sort is : ";
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}