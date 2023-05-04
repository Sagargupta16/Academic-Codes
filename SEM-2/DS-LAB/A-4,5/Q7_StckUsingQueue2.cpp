#include <iostream>
using namespace std;

class Queue
{
private:
    int *A;
    int front, rear, size, length;
public:
    void QueueInitialize(int x){
        front = -1;
        rear = -1;
        length = 0;
        size = x;
        A = new int[size];
    }
    bool isempty(){
        if (length == 0){
            return true;
        }
        return false;
    }
    bool isfull(){
        if (length == size){
            return true;
        }
        return false;
    }
    void enqueue(int z){
        if (isfull()){
            return;
        }
        else if (isempty()){
            front = 0;
            rear = 0;
        }
        else if (rear == size - 1){
            rear = 0;
        }
        else{
            rear = rear + 1;
        }
        A[rear] = z;
        length++;
    }
    int deque()
    {
        if (isempty()){
            return -1;
        }
        int z = A[front];
        if (length == 1){
            front = -1;
            rear = -1;
        }
        else if (front == size - 1){
            front = 0;
        }
        else{
            front++;
        }
        length--;
        return z;
    }
    ~Queue(){
        delete[] A;
    }
};

class Stack
{
private:
    int Top, size;
    Queue q, r;
public:
    Stack(int a){
        Top = -1;
        size = a;
        q.QueueInitialize(a);
        r.QueueInitialize(a);
    }
    bool isempty(){
        if (Top == -1){
            return true;
        }
        return false;
    }
    bool isfull(){
        if (Top == size - 1){
            return true;
        }
        return false;
    }
    void push(int a){
        if (isfull()){
            cout << "Stack is Full! " << endl;
        }
        else{
            Top++;
            r.enqueue(a);
            while(!q.isempty()){
                r.enqueue(q.deque());
            }
            while (!r.isempty()){
                q.enqueue(r.deque());
            }
        }
    } // O(n) Linear Time
    int pop(){
        if (isempty()){
            return -1;
        }
        Top--;
        return q.deque();
    } // O(1) Constant time
    void display()
    {
        int a;
        if (isempty()){
            return;
        }
        else{
            a = pop();
            cout << a << endl;
            display();
            push(a);
        }
    }
};

int main()
{
    int c, x, y;
    cout << "Enter Size of Stack : ";
    cin >> y;
    Stack s(y);
    cout << endl << "1. Push" << endl;
    cout << "2. Pop" << endl;
    cout << "3. Display" << endl;
    cout << "4. Quit" << endl;
    do
    {
        cout << "Enter your choice : ";
        cin >> c;
        cout << endl;

        switch (c)
        {
        case 1:
            cout << "Enter Element you want to push : ";
            cin >> x;
            s.push(x);
            break;

        case 2:
            if (s.isempty())
            {
                cout << "Stack is Empty! " << endl;
            }
            else
            {
                cout << "Popped Element is : " << s.pop() << endl;
            }
            break;

        case 3:
            cout << "Elements in Stack are " << endl;
            s.display();
            break;

        case 4:
            break;

        default:
            cout << "Enter Valid Choice ! " << endl;
            break;
        }
    } while (c != 4);
    return 0;
}
