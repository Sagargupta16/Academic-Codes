#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

class GeneralTree{
public:
    Node* root;
    GeneralTree(){
        root = NULL;
    }
    void insert(int d){
        if(root == NULL){
            root = new Node(d);
        }
        else{
            Node* temp = root;
            
        }
    }
    void print(){
        Node* temp = root;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->left;
        }
    }
};

int main(){
    GeneralTree t;
    t.insert(1);
    t.insert(2);
    t.insert(3);
    t.insert(4);
    t.insert(5);
    t.insert(6);
    t.insert(7);
    t.insert(8);
    t.insert(9);
    t.insert(10);
    t.print();
    return 0;
}