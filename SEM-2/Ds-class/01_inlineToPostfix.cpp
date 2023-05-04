#include<iostream>
using namespace std;

class Stack{
    private:
        int Top=-1;
        char ar[1000];
    public:
        bool isEmpty(){
            if(Top==-1){
                return true;
            }
            else{
                return false;
            }
        }
        char pop(){
            if(!isEmpty()){
                Top--;
                return ar[Top+1];
            }
            return -1;
        }
        void push(char x){
            if(Top==999){
                cout<<"Stack is Full "<<endl;
            }
            else{
                Top++;
                ar[Top]=x;
            }
        }
        void display(){
            char a;
            if(isEmpty()){
                return;
            }
            else{
                a=pop();
                display();
                cout<<a;
                push(a);
            }
        }
        int TopValue(){
            return Top;
        }
};
int precedence(char a){
    if(c=='*' || c=='/'){
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
    Stack s,t;
    string x;

    cout<<"Enter Inline Expression without space : ";
    cin>>x;
    x='('+x+')';

    for(int i=0;i<x.length();i++){
        if((x[i]>='0' && x[i]<='9')||(x[i]>='A' && x[i]<='Z')||(x[i]>='a' && x[i]<='z')){
            s.push(x[i]);
        }
        else if(x[i]=='('){
            t.push(x[i]);
        }
        else if(x[i]==')'){
            while(t.A[TopValue()]!='('){
                s.push(t.pop());
            }
            t.pop();
        }
        else{
            while(!t.isEmpty() &&)
        }
            
    }
    s.display();

}
