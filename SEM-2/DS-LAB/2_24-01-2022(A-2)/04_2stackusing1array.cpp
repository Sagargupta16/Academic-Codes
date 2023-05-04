#include<iostream>
using namespace std;

class Stack{
    private :
        int Top1=-1,Top2=999,ar[2000];
    public :
        void push(int s){
            int x;
            if(s==1){
                if(Top1==999){
                    cout<<"Stack is Full "<<endl;
                }
                else{
                    cout<<"Enter Element you want to push : ";
                    cin>>x;
                    Top1++;
                    ar[Top1]=x;
                    cout<<"Element Pushed!"<<endl;
                }
            }
            else if(s==2){
                if(Top2==2000){
                    cout<<"Stack is Full "<<endl;
                }
                else{
                    cout<<"Enter Element you want to push : ";
                    cin>>x;
                    Top2++;
                    ar[Top2]=x;
                    cout<<"Element Pushed!"<<endl;
                }
            }
        }

        void pop(int s){
            if(s==1){
                if(Top1==-1){
                    cout<<"Stack is Empty !"<<endl;
                }
                else{
                    cout<<"Popped Element is : "<<ar[Top1]<<endl;
                    Top1--;
                }
            }
            else if(s==1){
                if(Top2==999){
                    cout<<"Stack is Empty !"<<endl;
                }
                else{
                    cout<<"Popped Element is : "<<ar[Top2]<<endl;
                    Top2--;
                }
            }
        }

        void display(int s){
            int m;
            if(s==1){
                if(Top1==-1){
                    cout<<"Stack is Empty !"<<endl;
                }
                else{
                    cout<<"Elements in Stack are : "<<endl;
                    m=Top1;
                    while(m!=-1){
                        cout<<ar[m]<<endl;
                        m--;
                    }
                }
            }
            else if(s==2){
                if(Top2==999){
                    cout<<"Stack is Empty !"<<endl;
                }
                else{
                    cout<<"Elements in Stack are : "<<endl;
                    m=Top2;
                    while(m!=999){
                        cout<<ar[m]<<endl;
                        m--;
                    }
                }
            }
        }
};

int main(){

    Stack s;
    int c,a;

    abc:
    cout<<endl<<"Enter Stack you Want to Take Operations on (1 or 2) :";
    cin>>a;

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
        s.push(a);
        goto abc;
        break;

    case 2:
        s.pop(a);
        goto abc;
        break;
    
    case 3:
        s.display(a);
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