// Q-1 c) Multiple Inheritence
#include<iostream>
using namespace std;

class B
{
private:
    
public:
    int a = 1;
    B(){
        cout<<"B Class"<<endl;
    }
};

class C
{
private:
    
public:
    int b = 2;
    C(){
        cout<<"C Class"<<endl;
    }
};

class A : public B,public C
{
private:
public:
    int c = 3;
    A(){
        cout<<"A Class"<<endl;
    }
};

int main(){
    A obj;
    cout<<obj.a<<" "<<obj.b<<" "<<obj.c<<endl;;
    return 0;
}