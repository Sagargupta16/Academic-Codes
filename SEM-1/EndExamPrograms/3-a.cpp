// Q-3 a) Hierarchical inheritance 
#include<iostream>
using namespace std;

class A
{
private:
    
public:
    int a=1;
    A(){
        cout<<"A Class"<<endl;
    }
};

class B : public A
{
private:
    
public:
    int b=2;
    B(){
        cout<<"B Class"<<endl;
    }
};

class C : public A
{
private:
public:
    int c=3;
    C(){
        cout<<"C Class"<<endl;
    }
};

int main(){
    B obj1;
    C obj2;

    cout<<obj1.a<<" "<<obj1.b<<endl;
    cout<<obj2.a<<" "<<obj2.c<<endl;


    return 0;
}