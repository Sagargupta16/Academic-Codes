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

int main(){
    Node *L1 = new Node(1);
    Node *L12 = new Node(2);
    Node *L13 = new Node(3);
    Node *L14 = new Node(5);
    Node *L15 = new Node(8);
    Node *L16 = new Node(27);
    Node *L17 = new Node(9);
    Node *L18 = new Node(36);
    Node *L19 = new Node(72);
    L1->next = L12;
    L12->next = L13;
    L13->next = L14;
    L14->next = L15;
    L15->next = L16;
    L16->next = L17;
    L17->next = L18;
    L18->next = L19;

    Node *L3 = new Node(6);
    Node *L32 = new Node(18);
    L3->next = L32;
    L32->next = L14;

    Node *L4 = new Node(4); 
    Node *L42 = new Node(12); 
    Node *L43 = new Node(25);
    L4->next = L42; 
    L42->next = L43; 
    L43->next = L16;

    Node *L2 = new Node(15);
    Node *L22 = new Node(45);
    Node *L23 = new Node(10);
    L2->next = L22;
    L22->next = L23;
    L23->next = L18;


    











    return 0;
}