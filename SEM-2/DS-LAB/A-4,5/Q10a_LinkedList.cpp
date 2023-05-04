#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int d){
        data=d;
        next=NULL;
    }
};
class LinkedList{
    private:
        Node *head;
    public:
        LinkedList(){
            head=NULL;
        }
        void insertAtStart(int d){
            Node *a = new Node(d);
            a->next = head;
            head = a;
        } // O(1)
        void insertAtPos(int d, int pos){
            Node *a = new Node(d);
            if (pos == 1){
                a->next = head;
                head = a;
                return;
            }
            Node *p = head;
            Node *q = head->next;
            int cnt = 1;
            while (cnt != pos - 1){
                cnt++;
                if (p->next == NULL){
                    break;
                }
                p = p->next;
                q = q->next;
            }
            p->next = a;
            a->next = q;
        } // O(n)
        void insertAtEnd(int d){
            Node *p = head;
            Node *a = new Node(d);
            if (p == NULL)
            {
                head = a;
            }
            else
            {
                while (p->next != NULL)
                {
                    p = p->next;
                }
                p->next = a;
            }
        }//O(n)
        void deleteAtStart(){
            if(head!=NULL){
                Node *a = head;
                head = head->next;
                delete a;
            }
            else{
                cout << "List is Empty ! " << endl;
            }
        } // O(1)
        void deleteAtPos(int pos){
            Node *b = head;
            Node *c = head->next;
            if (pos == 1)
            {
                deleteAtStart();
                return;
            }
            int cnt = 2;
            while (cnt != pos)
            {
                b = b->next;
                c = c->next;
                cnt++;
            }
            b->next = c->next;
            c->next = NULL;
            delete c;
        } // O(n)
        void deleteAtEnd(){
            Node* p = head;
            if(head==NULL){
                cout << "List is Empty ! " << endl;
            }
            else if(head->next==NULL){
                delete p;
                head=NULL;
            }
            else{
                while(p->next->next!=NULL){
                    p=p->next;
                }
                delete p->next;
                p->next=NULL;
            }
        } // O(n)
        void display(){
            Node *a = head;
            while (a != NULL)
            {
                cout << a->data << " ";
                a = a->next;
            }
            cout << endl;
        } // O(n)
};

int main(){
    int c,d,pos;
    LinkedList l;
    cout << endl<< "Linked List Menu" << endl;
    cout << "1. Insert in Start " << endl;
    cout << "2. Insert at Position " << endl;
    cout << "3. Insert at End " << endl;
    cout << "4. Delete From Start " << endl;
    cout << "5. Delete at Position " << endl;
    cout << "6. Delete at End " << endl;
    cout << "7. Display Linked List " << endl;
    cout << "8. Quit" << endl;
    do{
        cout<<"Enter your Choice : ";
        cin>>c;

        switch (c)
        {
        case 1:
            cout<<"Enter data You want to Insert : ";
            cin>>d;
            l.insertAtStart(d);
            break;

        case 2:
            cout << "Enter data You want to Insert : ";
            cin >> d;
            cout<<"Enter Position at which you want to Insert : ";
            cin>>pos;
            l.insertAtPos(d,pos);
            break;

        case 3:
            cout << "Enter data You want to Insert : ";
            cin >> d;
            l.insertAtEnd(d);
            break;

        case 4:
            l.deleteAtStart();
            break;

        case 5:
            cout << "Enter Position at which you want to Delete Node : ";
            cin >> pos;
            l.deleteAtPos(pos);
            break;

        case 6:
            l.deleteAtEnd();
            break;

        case 7:          
            l.display();
            break;
        
        case 8:
            break;

        default:
            cout<<"Enter Valid Choice!"<<endl;
            break;

        }
    }while(c!=8);

    return 0;
}