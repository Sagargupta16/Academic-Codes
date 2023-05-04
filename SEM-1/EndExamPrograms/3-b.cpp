// Q-3 b) Example for Function with argument and with return value.
#include<iostream>
using namespace std;

int sum(int a,int b)
{
    cout<<"This is Function with argument and return value "<<endl;
    return a+b;
}

int main(){
    int a=5,b=6;
    int c=sum(a,b);
    cout<<c<<endl;
    return 0;
}