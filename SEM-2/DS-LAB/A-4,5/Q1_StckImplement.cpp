#include <iostream>
using namespace std;

class Stack
{
private:
    int Top,size;
    int *ar;
public:
    Stack(int a){
        Top=-1;
        size=a;
        ar = new int[size];
    }
    bool isfull(){
        if (Top == size - 1){
            return true;
        }
        return false;
    }
    bool isempty(){
        if (Top == -1){
            return true;
        }
        return false;
    }
    void push(int a){
        if (isfull()){
            return;
        }
        Top++;
        ar[Top] = a;
    }
    int TOP(){
        if (isempty()){
            return -1;
        }
        return ar[Top];
    }
    void pop(){
        if (isempty()){
            return;
        }
        Top--;
    }
    void display()
    {
        if (isempty()){
            return;
        }
        int a;
        a = TOP();
        pop();
        cout << a << endl;
        display();
        push(a);
    }//O(n)
};

int main()
{
    int c,a,x;
    cout<<"Enter Max Size of Stack : ";
    cin>>a;
    Stack s(a);
    cout << "Stack Menu "<<endl;
    cout << "1. Push "<<endl;
    cout << "2. Pop "<<endl;
    cout << "3. Display "<<endl;
    cout << "4. Quit "<<endl;
    do{
        cout << "Enter your choice : ";
        cin >> c;
        switch (c){
        case 1:
            if(s.isfull()){
                cout << "Stack is Full !" << endl;
            }
            else{
                cout << "Enter Element you want to push : ";
                cin >> x;
                s.push(x);
            }
            break;

        case 2:
            x = s.TOP();
            s.pop();
            if(x==-1){
                cout << "Stack is Empty !"<<endl;
            }
            else{
                cout << "Popped Element is : " <<x<<endl;
            }
            break;

        case 3:
            if(!s.isempty()){
                cout << "Elements in Stack are : " << endl;
                s.display();
            }
            break;

        case 4:
            break;

        default:
            cout << "Enter Valid Choice ! " << endl;
            break;
        }
    }while(c!=4);

    return 0;
}