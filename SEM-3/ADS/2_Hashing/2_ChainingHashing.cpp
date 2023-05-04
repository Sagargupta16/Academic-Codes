#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node(int d){
            data = d;
            next = NULL;
        }
};

class chainingHashing{
    private:
        Node* *A;
        int size;
    public:
        chainingHashing(int s){
            A = new Node* [s];
            size = s;
            for (int i = 0; i < s; i++){
                A[i] = NULL;
            }
        }
        void insert(int d){
            cout<<"Inserting "<<d<<" in the Hash Table"<<endl;
            Node *x = A[d%size];
            if (x == NULL){
                A[d%size]=new Node(d);
                return;
            }
            Node *z = new Node(d);
            if(x->data>d){
                A[d%size] = z;
                z->next = x;
                return;
            }
            if (x->next == NULL){
                x->next = z;
                return;
            }
            while (x->next->data<d){
                x = x->next;
                if (x->next==NULL){
                    x->next = z;
                    return;
                }
            }
            z->next = x->next;
            x->next = z;
        }
        bool search(int d){
            Node* x = A[d%size];
            while (x!=NULL){
                if (x->data>d) return false;
                if (x->data==d) return true;
                x = x->next;
            }
            return false;
        }
        void Delete(int d){
            Node *x = A[d%size];
            if (x->next == NULL) return;
            while (x->next->data != d){
                x = x->next;
                if (x->next == NULL) return;
            }
            Node *z = x->next;
            x->next = x->next->next;
            delete z;
        }
        void display(){
            cout<<endl<<"Hash Table: "<<endl;
            for (int i = 0; i < size; i++){
                cout<<i<<": ";
                Node *x = A[i];
                while (x!=NULL){
                    cout<<x->data<<" ";
                    x = x->next;
                }
                cout<<endl;
            }
            cout<<endl;
        }
};

int main()
{
    int A[] = {16,12,25,39,6,122,5,68,75,222};
    int n = sizeof(A)/sizeof(A[0]);
    chainingHashing c(10);
    for (int i = 0; i < n; i++){
        c.insert(A[i]);
    }
    c.display();

    cout<<endl<<"Search 122: ";
    if(c.search(122)){
        cout<<"Key Found"<<endl;
    }
    else{
        cout<<"Key Not Found"<<endl;
    }

    cout<<endl<<"Deleting 122!" <<endl;
    c.Delete(122);
    c.display();

    return 0;
}