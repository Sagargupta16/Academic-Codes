#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(int d){
            data = d;
            next = NULL;
        }
};
Node* numToLL(int d){
    if(d==0){
        return NULL;
    }
    Node* a = new Node(d%10);
    a->next = numToLL(d/10);
    return a;
}
Node* sumOfTwoLL(Node* h1,Node* h2){
    bool a = false;
    Node* h3 = h1;
    while(h1->next!=NULL && h2!=NULL){
        if(h1->next==NULL){
            h1->next = h2->next;
            h2->next = NULL;
        }
        if(h2!=NULL){
            h1->data = h1->data+h2->data;
            if(a){
                h1->data++;
                a=false;
            }
            if(h1->data>9){
                h1->data = h1->data%10;
                a = true;
            }
        }
        h1 = h1->next;
        h2 = h2->next;
    }
    if(a){
        while(h1->next!=NULL){
            if(a){
                h1->data++;
                a=false;
            }
            if(h1->data>9){
                h1->data = h1->data%10;
                a = true;
            }
            if(h1->next==NULL){
                break;
            }
            h1 = h1->next;
        }
        if(a){
            Node *z = new Node(1);
            h1->data++;
            if(h1->data>9){
                h1->data = h1->data%10;
            }
            h1->next = z;
        }
    }
    return h3;
}
void DisplayReverse(Node* x){
    if(x==NULL){
        return;
    }
    Display(x->next);
    cout<<x->data<<" ";
}

int main(){
    int a = 99971;
    int b = 998;
    Node* h1 = numToLL(a);
    Node* h2 = numToLL(b);
    Node* h3 = sumOfTwoLL(h1,h2);
    DisplayReverse(h3);
    return 0;
}