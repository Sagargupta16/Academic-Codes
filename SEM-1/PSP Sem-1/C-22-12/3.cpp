#include<iostream>
using namespace std;

class yourclass;

class myclass
{
private:
    int a;
public:
    myclass(int a1);
    friend int compare(myclass obj1,yourclass obj2);
};
myclass::myclass(int a1)
{
    a=a1;
}

class yourclass
{
private:
    int a;
public:
    yourclass(int a1);
    friend int compare(myclass obj1,yourclass obj2);
};
yourclass::yourclass(int a1)
{
    a=a1;
}

int main()
{
    myclass o1(10);
    yourclass o2(20);
    cout<<compare(o1,o2)<<endl;
}

int compare(myclass obj1,yourclass obj2){
    return (obj2.a-obj1.a);
}