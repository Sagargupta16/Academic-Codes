#include <iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    int a = 0, b = 1, c = 1;
    cout<<"Tribonacci Series: ";
    while(a<=n){
        if(a<=n) cout<<a<<" ";
        if(b<=n) cout<<b<<" ";
        if(c<=n) cout<<c<<" ";
        a += b + c;
        b += a + c;
        c += a + b;
    }
    cout<<endl;
}