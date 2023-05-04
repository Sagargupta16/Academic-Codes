#include<iostream>
using namespace std;

class dynamic
{
private:
    int *ptr;
public:
    dynamic()
    {
        ptr = new int;
        *ptr =100;
    }
    dynamic(int v)
    {
        ptr =new int;
        *ptr = v;
    }
    int display()
    {
        return (*ptr);
    }
};

int main()
{
    dynamic obj1,obj2(90);
    cout<<obj1.display()<<endl;
    cout<<obj2.display()<<endl;
}
