
#include<iostream>
using namespace std;

class myclass{
    private :
        int x;
    public: 
        myclass()
        {
            x=0;
        }
        void f(int n1)
        {
            x=n1+5;
        }
        void output(){
            cout<<x<<endl;
        }
};

class sample : public myclass
{
    private:
        int s1;
    public:
        sample(){
            s1=0;
        }
        void f1(int n1){
            s1=n1*10;
        }
        void output(){
            cout<<s1<<endl;
        }
};

int main(){
    sample s;
    s.f(10);
    s.output();
    return 0;
}