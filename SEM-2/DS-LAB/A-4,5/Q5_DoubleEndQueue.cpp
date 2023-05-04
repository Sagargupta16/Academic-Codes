#include <iostream>
using namespace std;

class Queue
{
private:
    int *A;
    int front,rear,size,length;

public:
    Queue(int x){
        front=-1;
        rear=-1;
        size = x;
        A = new int[size];
        length=0;
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
    void enqueueAtRear(int x){
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
        A[rear] = x;
        length++;
    }
    void enqueueAtFront(int x){
        if (isfull()){
            return;
        }
        else if(isempty()){
            front = 0;
            rear = 0;
        }
        else if(front==0){
            front=size-1;
        }
        else{
            front--;
        }
        A[front]=x;
        length++;
    }
    int dequeAtRear(){
        if (isempty()){
            return -1;
        }
        int x = A[rear];
        if(length==1){
            front = -1;
            rear = -1;
        }
        else if (rear==0){
            rear=size-1;
        }
        else{
            rear--;
        }
        length--;
        return x;
    }
    int dequeAtFront(){
        if (isempty()){
            return -1;
        }
        int x = A[front]; 
        if(length==1){
            front=-1;
            rear=-1;
        }
        else if(front==size-1){
            front=0;
        }
        else{
            front++;
        }
        length--;
        return x;
    }
    void Display(){
        if (isempty()){
            return;
        }
        int x = dequeAtFront();
        cout<<x<<" ";
        Display();
        enqueueAtFront(x);
    }
    ~Queue(){
        delete[] A;
    }
};

int main()
{
    int n, c, z;
    cout << "Enter Max Size of QUEUE : ";
    cin >> n;
    Queue Q(n);

    cout << endl << "QUEUE MENU" << endl;
    cout << "1. Insert or Enqueue Element in rear end " << endl;
    cout << "2. Insert or Enqueue Element in Front end " << endl;
    cout << "3. Deque Element from rear end " << endl;
    cout << "4. Deque Element from front end " << endl;
    cout << "5. Display " << endl;
    cout << "6. Quit " << endl;
    do
    {
        cout << "Enter Your Choice : ";
        cin >> c;

        switch (c)
        {
        case 1:
            if(Q.isfull()){
                cout << "QUEUE is FULL ! " << endl;
            }
            else{
                cout << "Enter Element you want to Insert : ";
                cin>>z;
                Q.enqueueAtRear(z);
            }
            break;

        case 2:
            if (Q.isfull()){
                cout << "QUEUE is FULL ! " << endl;
            }
            else{
                cout << "Enter Element you want to Insert : ";
                cin >> z;
                Q.enqueueAtFront(z);
            }
                break;

        case 3:
            if(Q.isempty()){
                cout << "QUEUE is EMPTY ! " << endl;
            }
            else{
                cout << "Dequeued Element is : "<< Q.dequeAtRear() << endl;
            }
            break;

        case 4:
            if (Q.isempty()){
                cout << "QUEUE is EMPTY ! " << endl;
            }
            else{
                cout << "Dequeued Element is : " << Q.dequeAtFront() << endl;
            }
            break;

        case 5:
            if (!Q.isempty())
            {
                cout << "Element In Queue Are : ";
                Q.Display();
                cout << endl;
            }
            break;

        case 6:
            break;

        default:
            cout << "Enter Valid Choice !" << endl;
            break;
        }
    } while (c != 6);

    return 0;
}