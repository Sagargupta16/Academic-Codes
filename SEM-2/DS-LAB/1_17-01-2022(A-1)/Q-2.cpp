#include<iostream>
using namespace std;

int main(){
    int size,p=0,count=0;
    cout<<"Enter the size of message = ";
    cin>>size;
    int ar[size];
    cout<<"Enter the message bits : ";
    for(int i=0;i<size;i++){
        cin>>ar[i];
        if(ar[i]==1){
            count++;
        }
    }
    if(count%2!=0){
        p=1;
    }
    cout<<"Codeword = "<<p;
    for(int i=0;i<size;i++){
        cout<<ar[i];
    }

    return 0;
}