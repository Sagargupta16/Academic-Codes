#include<iostream>
using namespace std;

class Stack{
    private:
        int Top=-1,ar[1000];
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
        void sortPush(int t){
            if(Top==-1 || t>ar[Top]){
                push(t);
            }
            else{
                int x = pop();
                sortPush(t);
                push(x);
            }
        }
        void sortStack(){
            if(Top>-1){
                int t = pop();
                sortStack();
                sortPush(t);
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

    cout<<"Stack Elements Before Sorting are : "<<endl;
    s.display();

    s.sortStack();

    cout<<"Stack Elements After Sorting are : "<<endl;
    s.display();

    return 0;
}