#include<iostream>
using namespace std;

class Stack{
    private:    
        int Top=-1;
        char ar[1000];
    public:
        char pop(){
            return ar[Top--];
        }

        void push(char a){
            Top++;
            ar[Top]=a;
        }

        bool duplicate(){
            int br[3]={0,0,0};
            char z;
            while(Top!=-1){
                z = pop();
                if(z=='{'){
                    if(br[0]==0){
                        br[0]=1;
                    }
                    else{
                        return true;
                    }
                }
                if(z=='['){
                    if(br[1]==0){
                        br[1]=1;
                    }
                    else{
                        return true;
                    }
                }
                if(z=='('){
                    if(br[2]==0){
                        br[2]=1;
                    }
                    else{
                        return true;
                    }
                }
            }
            return false;
        }
};

int main(){
    Stack s;
    string z;
    cout<<"Enter Balanced Expression : ";
    cin>>z;

    
    for(int i=0;i<z.length();i++){
        s.push(z[i]);
    }
    if(s.duplicate()){
        cout<<"Duplicate Parenthesis Found "<<endl;
    }
    else{
        cout<<"Duplicate Parenthesis Not Found "<<endl;
    }


    return 0;
}