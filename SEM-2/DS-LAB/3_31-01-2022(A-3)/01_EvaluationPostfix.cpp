#include<iostream>
using namespace std;
class Stack{
    private:
        int Top=-1;
        int ar[100];
    public:
        bool isEmpty(){
            if(Top==-1){
                return true;
            }
            else{
                return false;
            }
        }
        int pop(){
            if(!isEmpty()){
                Top--;
                return ar[Top+1];
            }
            return -1;
        }
        void push(int x){
            if(Top==99){
                cout<<"Stack is Full "<<endl;
            }
            else{
                Top++;
                ar[Top]=x;
            }
        }
        void display(){
            int a;
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

void PostFix(string u){
    Stack s;
    int x,y,z,w=0;
    for(int i=0;i<u.length();i++){
        if(u[i]==' '){
            continue;
        }
        z=0;
        w++;
        if(u[i]>='0' &&u[i] <='9'){
            if(u[i+1]==' '){
                z = int(u[i])-48;
            }
            else{
                while(u[i]!=' '){
                    z=z*10+(int(u[i])-48);
                    i++;
                }
            }
            s.push(z);
        }
        else{
            x=s.pop();
            y=s.pop();
            if(u[i]=='*'){
                y=y*x;
            }
            else if(u[i]=='/'){
                y=y/x;
            }
            else if(u[i]=='+'){
                y=y+x;
            }
            else if(u[i]=='-'){
                y=y-x;
            }
            s.push(y);
        }
        cout<<w<<".Stack : ";
        s.display();
        cout<<endl;
    }
    cout<<"Final Result is : "<<s.pop()<<endl;
}

int main(){
    string u;
    cout<<"Enter Expression Space Seprated : ";
    getline(cin,u);
    PostFix(u);
    return 0;
}