#include<iostream>
using namespace std;

class Queue{
    private:
        int *A;
        int front=-1,rear=-1,size;
    public:
        Queue(int x){
            size=x;
            A = new int[size];
        }
        bool isempty(){
            if(front==-1 && rear==-1){
                return true;
            }
            else{
                return false;
            }
        }
        bool isfull(){
            if(rear==size-1){
                return true;
            }
            else{
                return false;
            }
        }
        void enqueue(int x){
            if(isfull()){
                cout<<"QUEUE is FULL ! "<<endl;
            }
            else{
                if(rear==-1){
                    front++;
                }
                rear++;
                A[rear]=x;
            }
        }
        void deque(){
            if(isempty()){
                cout<<"QUEUE is EMPTY ! "<<endl;
            }
            else{
                if(front==rear){
                    front=-1;
                    rear=-1;
                }
                else{
                    front++;
                }
            }
        }
        void Display(){
            if (isempty())
            {
                return;
            }
            else{
                for(int i=front;i<=rear;i++){
                    cout<<A[i]<<" ";
                }
                cout << endl;
            }
        }
        ~Queue(){
            delete []A;
        }
};

int main(){
    int n,c;
    cout<<"Enter Max Size of QUEUE : ";
    cin>>n;
    Queue Q(n);

    do{
        cout<<endl<<"QUEUE MENU"<<endl;
        cout<<"1. Insert or Enque Element "<<endl;
        cout<<"2. Deque Element "<<endl;
        cout<<"3. Display "<<endl;
        cout<<"4. Quit "<<endl;
        cout<<"Enter Your Choice : ";
        cin>>c;

        switch (c)
        {
        case 1:
            cout<<"Enter Element you want to Insert : ";
            int z;
            cin>>z;
            Q.enqueue(z);
            break;

        case 2:
            Q.deque();
            break;

        case 3:
            Q.Display();
            break;
        
        case 4:
            break;

        default:
            cout<<"Enter Valid Choice !"<<endl;
            break;
        }
    }while(c!=4);

    return 0;
}