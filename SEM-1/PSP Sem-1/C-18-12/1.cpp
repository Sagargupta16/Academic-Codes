#include<iostream>
using namespace std;

class demo{
    private:

    static int x;
    static int y;

    public:

    static void print(){
        cout<<x<<" "<<y<<endl;
    }
};

int demo::x=10;
int demo::y=20;

int main()
{
    demo d;
    d.print();
    demo::print();
}