#include<iostream>
using namespace std;
struct Node {
    int data;
    Node *previous;
    Node *next;
};
class doubleLinkedList{
    private:
        struct Node *head;
    public:
        doubleLinkedList(){
            head=NULL;
        }
        void insertAtStart(int d){
            struct Node *a = new Node{{d}, {NULL}, {NULL}};
            a->next = head;
            head = a;
        } // O(1)
        void insertAtPos(int d, int pos){
            struct Node *a = new Node{{d}, {NULL}, {NULL}};
            if (pos == 1)
            {
                insertAtStart(d);
                return;
            }
            struct Node *p = head;
            struct Node *q = head->next;
            int cnt = 2;
            while (cnt != pos)
            {
                cnt++;
                if (p->next == NULL)
                {
                    break;
                }
                p = p->next;
                q = q->next;
            }
            p->next = a;
            a->previous = p;
            if (q != NULL)
            {
                a->next = q;
                q->previous = a;
            }
        } // O(n)
        void insertAtEnd(int d)
        {
            struct Node *p = head;
            struct Node *a = new Node{{d}, {NULL}, {NULL}};
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
                a->previous = p;
            }
        } // O(n)
        void deleteAtStart(){
            if(head==NULL){
                cout << "List is Empty ! " << endl;
            }
            else if(head->next==NULL){
                struct Node *a = head;
                delete a;
                head=NULL;
            }
            else{
                struct Node *a = head;
                head = head->next;
                head->previous = NULL;
                delete a;
            }
        } // O(1)
        void deleteAtPos(int pos){
            struct Node *b = head;
            struct Node *c = head->next;
            if (pos == 1){
                deleteAtStart();
                return;
            }
            int cnt = 2;
            while (cnt != pos){
                if (b->next == NULL){
                    return;
                }
                b = b->next;
                c = c->next;
                cnt++;
            }
            if (b->next != NULL){
                b->next = c->next;
            }
            if (c->next != NULL){
                c->next->previous = b;
            }
            delete c;
        } // O(n)
        void deleteAtEnd()
        {
            struct Node *p = head;
            if (head == NULL)
            {
                cout << "List is Empty ! " << endl;
            }
            else if (head->next == NULL)
            {
                delete p;
                head = NULL;
            }
            else
            {
                while (p->next->next != NULL)
                {
                    p = p->next;
                }
                delete p->next;
                p->next = NULL;
            }
        } // O(n)
        void display(){
            struct Node *a = head;
            while (a != NULL){
                cout << a->data << " ";
                a = a->next;
            }
            cout << endl;
        } // O(n)
};

int main(){
    int c, d, pos;
    doubleLinkedList dl;
    cout << endl << " Double Linked List Menu" << endl;
    cout << "1. Insert in Start " << endl;
    cout << "2. Insert at Position " << endl;
    cout << "3. Insert at End " << endl;
    cout << "4. Delete From Start " << endl;
    cout << "5. Delete at Position " << endl;
    cout << "6. Delete at End " << endl;
    cout << "7. Display Linked List " << endl;
    cout << "8. Quit" << endl;
    do
    {
        cout << "Enter your Choice : ";
        cin >> c;

        switch (c)
        {
        case 1:
            cout << "Enter data You want to Insert : ";
            cin >> d;
            dl.insertAtStart(d);
            break;

        case 2:
            cout << "Enter data You want to Insert : ";
            cin >> d;
            cout << "Enter Position at which you want to Insert : ";
            cin >> pos;
            dl.insertAtPos(d, pos);
            break;

        case 3:
            cout << "Enter data You want to Insert : ";
            cin >> d;
            dl.insertAtEnd(d);
            break;

        case 4:
            dl.deleteAtStart();
            break;

        case 5:
            cout << "Enter Position at which you want to Delete Node : ";
            cin >> pos;
            dl.deleteAtPos(pos);
            break;

        case 6:
            dl.deleteAtStart();
            break;

        case 7:
            cout<<"Elements are : ";
            dl.display();
            break;

        case 8:
            break;

        default:
            cout << "Enter Valid Choice!" << endl;
            break;
        }
    } while (c != 8);

    return 0;
}