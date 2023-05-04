#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* prev;
        Node* child;
        Node(int d){
            data = d;
            next = NULL;
            prev = NULL;
            child = NULL;
        }
};

Node *Create(){
    Node* a1 = new Node(1);
    Node* a2 = new Node(2);
    Node* a3 = new Node(3);
    Node* a4 = new Node(4);
    Node* a5 = new Node(5);
    Node* a6 = new Node(6);
    Node* a7 = new Node(7);
    Node* a8 = new Node(8);
    Node* a9 = new Node(9);
    Node* a10 = new Node(10);
    Node* a11 = new Node(11);
    Node* a12 = new Node(12);
    a1->next = a2;
    a2->next = a3;
    a2->prev = a1;
    a3->child = a7;
    a3->next = a4;
    a3->prev = a2;
    a4->next = a5;
    a4->prev = a3;
    a5->next = a6;
    a5->prev = a4;
    a6->prev = a5;
    a7->next = a8;
    a8->child = a11;
    a8->next = a9;
    a8->prev = a7;
    a9->next = a10;
    a9->prev = a8;
    a10->prev = a9;
    a11->next = a12;
    a12->prev = a11;
    
    return a1;
}

Node* flattenLL(Node* head){
    Node* x = head;
    if(x==NULL){
        return x;
    }
    Node* y = NULL;
    if(x->child==NULL){
        flattenLL(head->next);
    }
    else{
        y = x->next;
        x->next = x->child;
        x->child->prev = x;
        x->child = NULL;
        Node* z = flattenLL(x);
        while(z->next!=NULL){
            z = z->next;
        }
        z->next = y;
    }
    return head;
}

void Display(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

int main(){
    
    Node* head = Create();
    Display(head);
    head=flattenLL(head);
    Display(head);
    return 0;
}