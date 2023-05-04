#include<iostream>
using namespace std;

class Stack{
    public:
        int Top=-1,a;
        char ar[1000];
        void pop(){
            if(!isEmpty()){
                Top--;
            }
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
        bool isEmpty(){
            if(Top==-1){
                return true;
            }
            else{
                return false;
            }
        }
        
};

int main(){
    Stack s;
    string s1;
    cout<<"Enter Expression : ";
    cin>>s1;

    for(int i=0;i<s1.length();i++){
        if(s1[i]==')' && s.ar[s.Top]=='('){
            s.pop();
        }
        else if(s1[i]=='}' && s.ar[s.Top]=='{' ){
            s.pop();
        }
        else if(s1[i]==']' && s.ar[s.Top]=='['){
            s.pop();
        }
        else if(s1[i]==')' || s1[i]=='('||s1[i]==']' || s1[i]=='['||s1[i]=='}' || s1[i]=='{' ){
            s.push(s1[i]);
        }        
    }

    if(s.isEmpty()){
        cout<<"Given Expression is Balanced "<<endl;
    }
    else{
        cout<<"Given Expression is not balanced "<<endl;
    }

    return 0;
}