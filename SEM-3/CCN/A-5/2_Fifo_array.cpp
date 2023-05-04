#include<iostream>
using namespace std;

class Fifo{
    int *data;
    int size;
    int head;
    int tail;
    int count;
public:
    Fifo(int size){
        this->size = size;
        data = new int[size];
        head = 0;
        tail = 0;
        count = 0;
    }
    ~Fifo(){
        delete [] data;
    }
    void push(int value){
        if(count == size){
            cout << "Fifo is full" << endl;
            return;
        }
        data[tail] = value;
        tail = (tail + 1) % size;
        count++;
    }
    int pop(){
        if(count == 0){
            cout << "Fifo is empty" << endl;
            return -1;
        }
        int value = data[head];
        head = (head + 1) % size;
        count--;
        return value;
    }
    bool isEmpty(){
        return count == 0;
    }
    bool isFull(){
        return count == size;
    }
};

int main(){
    Fifo fifo(5);
    fifo.push(1);
    fifo.push(2);
    fifo.push(3);
    fifo.push(4);
    fifo.push(5);
    fifo.push(6);
    while(!fifo.isEmpty()){
        cout << fifo.pop() << endl;
    }
    fifo.pop();
    return 0;
}