#include<iostream>
using namespace std;

class Stack
{
    private :
        int Top=-1,ar[1000];
    public :
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
            if(Top==-1){
                cout<<"Stack is Empty !"<<endl;
                return -1;
            }
            else{
                Top--;
                return ar[Top+1];
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
    int c;
    Stack s;

    abc:
    cout<<endl<<"1. Push"<<endl;
    cout<<"2. Pop"<<endl;
    cout<<"3. Display"<<endl;
    cout<<"4. Quit"<<endl;
    cout<<"Enter your choice : ";
    cin>>c;
    cout<<endl;

    switch(c)
    {
    case 1:
        int x;
        cout<<"Enter Element you want to push : ";
        cin>>x;
        s.push(x);
        goto abc;
        break;

    case 2:
        cout<<"Popped Element is : "<<s.pop()<<endl;
        goto abc;
        break;
    
    case 3:
        cout<<"Elements in Stack are"<<endl;
        s.display();
        goto abc;
        break;

    case 4:
        break;

    default:
        cout<<"Enter Valid Choice ! "<<endl;
        goto abc;
        break;
    }
    return 0;
}