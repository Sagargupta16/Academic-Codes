#include <iostream>
using namespace std;
class Stack
{
private:
    int Top;
    int ar[100];

public:
    Stack(){
        Top=-1;
    }
    bool isEmpty(){
        if (Top == -1){
            return true;
        }
        return false;
    }
    bool isFull(){
        if(Top == 99){
            return true;
        }
        return false;
    }
    int pop(){
        if (!isEmpty()){
            Top--;
            return ar[Top + 1];
        }
        return -1;
    }
    void push(int x){
        if (isFull()){
            cout << "Stack is Full " << endl;
        }
        else{
            Top++;
            ar[Top] = x;
        }
    }
    void display(){
        if (isEmpty()){
            return;
        }
        int a;
        a = pop();
        display();
        cout << a << " ";
        push(a);
    }
};

void PostFix(string u)
{
    Stack s;
    int x, y, z, w = 0;
    for (int i = 0; i < u.length(); i++){
        z = 0;
        w++;
        if (u[i] == ' '){
            continue;
        }
        else if (u[i] >= '0' && u[i] <= '9'){
            while (u[i] != ' '){
                z = z * 10 + (int(u[i]) - 48);
                i++;
            }
            s.push(z);
        }
        else{
            x = s.pop();
            y = s.pop();
            if (u[i] == '*'){
                cout<<"\t  "<<y<<"*"<<x<<endl;
                y = y * x;
            }
            else if (u[i] == '/'){
                cout<<"\t  "<<y<<"/"<<x<<endl;
                y = y / x;
            }
            else if (u[i] == '+'){
                cout << "\t  " << y << "+" << x << endl;
                y = y + x;
            }
            else if (u[i] == '-'){
                cout << "\t  " << y << "-" << x << endl;
                y = y - x;
            }
            s.push(y);
        }
        cout << w << ".Stack : ";
        s.display();
        cout << endl;
    }
    cout << "Final Result is : " << s.pop() << endl;
}

int main()
{
    string u;
    cout << "Enter Expression Space Seprated : ";
    getline(cin, u);
    PostFix(u);
    return 0;
}