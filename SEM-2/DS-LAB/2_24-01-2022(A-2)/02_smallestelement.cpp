#include<iostream>
using namespace std;

class Stack{
    private:
        int Top=-1,ar[1000],y;
    public:
        void push(int a){
            if(Top==-1){
                y=a;
            }
            if(y>a){
                y=a;
            }
            Top++;
            ar[Top]=a;
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
        int min_element(){
            return y;
        }
};

int main(){
    Stack s;
    int c,n;
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
        cout<<"Minimum element of Stack is : "<<s.min_element()<<endl;
        goto abc;
        break;
    
    case 4:
        break;

    default:
        cout<<"Enter Valid Choice ! "<<endl;
        goto abc;
        break;
    }

    // s.min_element() is of O(1)
    return 0;
}