#include <iostream>
using namespace std;

class myclass
{
private:
    int a;
public:
    myclass(int a1);

    friend void ff1(myclass obj);

};

myclass::myclass(int a1)
{
    a=a1;
}

void ff1(myclass obj)
{
    cout<<obj.a<<endl;
    myclass obj2(100);
    cout<<obj2.a<<endl;
}

int main()
{
    myclass obj1(10);
    ff1(obj1);
}