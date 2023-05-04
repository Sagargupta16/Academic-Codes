#include<iostream>
using namespace std;

class stack{
    int *data;
    int size;
    int top;
public:
    stack(int size){
        this->size = size;
        data = new int[size];
        top = -1;
    }
    ~stack(){
        delete [] data;
    }
    void push(int value){
        if(top == size - 1){
            cout << "Stack is full" << endl;
            return;
        }
        data[++top] = value;
    }
    int pop(){
        if(top == -1){
            cout << "Stack is empty" << endl;
            return -1;
        }
        return data[top--];
    }
    bool isEmpty(){
        return top == -1;
    }
    bool isFull(){
        return top == size - 1;
    }
};

class fifo{
    stack s1;
    stack s2;
public:
    fifo(int size):s1(size),s2(size){}
    void push(int value){
        s1.push(value);
    }
    int pop(){
        if(s2.isEmpty()){
            while(!s1.isEmpty()){
                s2.push(s1.pop());
            }
        }
        return s2.pop();
    }
    bool isEmpty(){
        return s1.isEmpty() && s2.isEmpty();
    }
    bool isFull(){
        return s1.isFull();
    }
};

int main(){
    fifo fifo(5);
    fifo.push(12);
    fifo.push(22);
    fifo.push(32);
    fifo.push(42);
    fifo.push(52);
    fifo.push(62);
    while(!fifo.isEmpty()){
        cout << fifo.pop() << endl;
    }
    fifo.pop();
    return 0;
}