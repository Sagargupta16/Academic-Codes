// Inline functions
#include<iostream>
using namespace std;

inline int even(int x)
{
    return !(x%2);
}

int main()
{
    if(even(10))//whole function is called here
    {
        cout<<"10 is even"<<endl;
    }
    if(even(11))//whole function is called here
    {
        cout<<"11 is even"<<endl;
    }
}