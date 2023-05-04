#include<iostream>
using namespace std;

class myclass
{
private:
    static int x;
public:
    static int y;
    int getx()
    {
        return x;
    }
    void setx(int x)
    {
        myclass::x=x;
    }
};

int myclass::x=1;
int myclass::y=2;

int main()
{
    myclass ob1,ob2;
    cout<<ob1.getx()<<endl;
    ob2.setx(5);
    cout<<ob1.getx()<<endl;
    cout<<ob1.y<<endl;
    myclass::y=10;
    cout<<ob2.y<<endl;
}