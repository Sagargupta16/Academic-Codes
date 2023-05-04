#include<iostream>
using namespace std;

class Stack{
    private:
        int Top=-1,ar[1000],y=10000;
        bool z=true;
    public:
        void push(int a){
            if(Top==999){
                cout<<"Stack is Full "<<endl;

            }
            else{
                Top++;
                ar[Top]=a;
            }
        }

        int pop(){
             z=true;
            if(Top==-1){
                cout<<"Stack is Empty !"<<endl;
                return -1;
            }
            else{
                Top--;
                return ar[Top+1];
            }
        }
        void min_element(){
            int a;
            if(Top==-1){
                return;
            }
            else{
                a=pop();
                if(y>a){
                    y=a;
                }
                min_element();
                push(a);
            }
            if(z){
                cout<<"Minimum element of Stack is : "<<y<<endl;
                z=false;
            }
        }
        void display(){
            int a;
            if(Top==-1){
                return;
            }
            else{
                a=pop();
                cout<<a<<endl;
                display();
                push(a);
            }
        }
};

int main(){
    Stack s;
    int n,c;
    abc:
    cout<<endl<<"1. Push"<<endl;
    cout<<"2. Pop"<<endl;
    cout<<"3. Minimum Element"<<endl;
    cout<<"4. Quit"<<endl;
    cout<<"Enter your choice : ";
    cin>>c;
    cout<<endl;

    switch(c)
    {
    case 1:
        cout<<"Enter Element You want to push : ";
        cin>>n;
        s.push(n);
        goto abc;
        break;
    case 2:
        cout<<"Popped Element is : "<<s.pop()<<endl;
        goto abc;
        break;
    case 3:
        s.min_element();
        goto abc;
        break;
    
    case 4:
        break;

    default:
        cout<<"Enter Valid Choice ! "<<endl;
        goto abc;
        break;
    }
}