#include<iostream>
using namespace std;

class Sample
{
private:
    int x;
public:
    Sample(int i);
    ~Sample();
    void put_x(int i)
    {
        x=i;
    }
    int get_x(){
        return x;
    }
};

Sample::Sample(int i)
{
    x=i;
    cout<<i<<endl;
}

Sample::~Sample()
{
    cout<<x<<endl;
}

void afun(Sample s1)
{
    s1.put_x(2);
    cout<<"Local Func"<<endl;
    cout<<s1.get_x();
}

int main()
{
    Sample s(1);
    cout<<"main"<<endl;
    cout<<s.get_x()<<endl;
    afun(s);
}