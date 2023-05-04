#include<iostream>
using namespace std;

class Stack{
    public:
        int Top=-1;
        string ar[1000];
        bool isEmpty(){
            if(Top==-1){
                return true;
            }
            else{
                return false;
            }
        }
        string pop(){
            if(!isEmpty()){
                Top--;
                return ar[Top+1];
            }
            return "-1";
        }
        void push(string x){
            if(Top==999){
                cout<<"Stack is Full "<<endl;
            }
            else{
                Top++;
                ar[Top]=x;
            }
        }
        void display(){
            string a;
            if(isEmpty()){
                return;
            }
            else{
                a=pop();
                display();
                cout<<a<<" ";
                push(a);
            }
        }
};

void PostFixExpression(string x){
    Stack s;
    string z,a,b;
    int w=0;
    for(int i=0;i<x.length();i++){
        if(x[i]==' '){
            continue;
        }
        w++;
        z="";
        if(x[i]>='0' &&x[i] <='9'){
            if(x[i+1]==' '){
                z = z+x[i];
            }
            else{
                while(x[i]!=' '){
                    z=z+x[i];
                    i++;
                }
            }
            s.push(z);
        }
        else if(x[i]=='*'||x[i]=='/'||x[i]=='+'||x[i]=='-'){
            a=s.pop();
            b=s.pop();
            z='('+b+x[i]+a+')';
            s.push(z);
        }
        else{
            z=x[i];
            s.push(z);
        }
        cout<<w<<".Stack  :";
        s.display();
        cout<<endl<<endl;
    }
    cout<<"PostFix of Given Expression is : "<<s.pop();
}


int main(){
    string s;
    cout<<"Enter Expression Space Seprated : ";
    getline(cin,s);
    PostFixExpression(s);
}