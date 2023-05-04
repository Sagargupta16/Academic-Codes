#include<iostream>
using namespace std;
int main(){
    // Given Conditions
    // a[4]+a[2]=14;
    // a[3]=1+a[1];
    // a[0]=2*a[1]-1;
    // a[1]+a[2]=10;
    // a[0]+a[1]+a[2]+a[3]+a[4]+a[5]=30;

    int a[5] = {7,4,6,5,8};

    cout<<"sum of 5th and 3rd element is : "<<a[2]+a[4]<<endl;
    cout<<"4th value of array is (2nd value + 1) : "<<1+a[1]<<endl;
    cout<<"1st value of array is (double of 2nd value - 1) : "<<2*a[1]-1<<endl;
    cout<<"Sum of 2nd value and 3rd value is : "<<a[1]+a[2]<<endl;
    cout<<"Sum of All Element of Array : "<<a[0]+a[1]+a[2]+a[3]+a[4]<<endl<<endl;;

    cout<<"5 Elements are in order or code is ";
    for(int i=0;i<5;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}