//Q-2) Write a C program pointers with Variable with an Example.
#include<iostream>
using namespace std;
int main()
{
    int a = 10;
    int *p = &a;
    cout<<"Value of a = "<<*p<<endl;
    cout<<"Address of a = "<<p<<endl;
    return 0;
}