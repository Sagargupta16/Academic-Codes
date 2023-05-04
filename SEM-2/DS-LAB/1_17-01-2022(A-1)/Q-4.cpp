#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter size of array : ";
    cin>>n;
    int ar[n];
    cout<<"Enter Elements of array : ";
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    int i,j;
    cout<<"Enter i value for finding ith largest element : ";
    cin>>i;
    cout<<"Enter j value for finding jth smallest element : ";
    cin>>j;

    for (int i=0;i<n-1;i++){
        for (int j=0;j<n-i-1;j++){
            if (ar[j]>ar[j+1]){
                int t = ar[j];
                ar[j] = ar[j+1];
                ar[j+1] = t;
            }
        }
    }
    cout<<"ith largest element is : "<<ar[n-i]<<endl;
    cout<<"jth smallest element is : "<<ar[j-1]<<endl;
    return 0;
}