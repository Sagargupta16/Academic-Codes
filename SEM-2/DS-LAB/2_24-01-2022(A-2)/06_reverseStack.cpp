#include<iostream>
using namespace std;

class Stack{
    private:
        int Top=-1,ar[1000];;
    public:
        void push(int a){
            Top++;
            ar[Top]=a;
        }
        int pop(){
            return ar[Top--];
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
        void reverseInsert(int x)
        {
            if(Top == -1){
                push(x);
            }
            else
            {
                int a = pop();
                reverseInsert(x);
                push(a);
            }
        }
        void reverse()
        {
            if(Top>-1)
            {
                int x = pop();
                reverse();
                reverseInsert(x);
            }
        }
};

int main(){
    Stack s;
    int n;
    cout<<"Enter number of element you want to push : ";
    cin>>n;
    int z;

    cout<<"Enter Elements you want to push : ";
    for(int i=0;i<n;i++){
        cin>>z;
        s.push(z);
    }

    cout<<"Stack Elements Before Reversing are : "<<endl;
    s.display();

    s.reverse();

    cout<<"Stack Elements After Reversing are : "<<endl;
    s.display();

    return 0;
}