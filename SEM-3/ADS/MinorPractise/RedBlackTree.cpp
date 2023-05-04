#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        char color;
        Node* left;
        Node* right;
        Node* parent;
        Node(int d){
            data=d;
            color='r';
            left=NULL;
            right=NULL;
            parent=NULL;
        }
};

class RedBlackTree{
    private:
        Node* root;
    public:
        RedBlackTree(){
            root=NULL;
        }
        void insert(int d){
            insertHelper(root,d);
        }
        void insertHelper(Node* root,int d){
            if(root==NULL){
                root = new Node(d);
                root->color='b';
                return;
            }
            if(root->data>d){
                if(root->left==NULL){
                    root->left = new Node(d);
                    root->left->parent=root;
                    return;
                }
                insertHelper(root->left,d);
            }
            else{
                if(root->right==NULL){
                    root->right = new Node(d);
                    root->right->parent=root;
                    return;
                }
                insertHelper(root->right,d);
            }
        }
        void print(){
            printHelper(root);
        }
        void printHelper(Node* root){
            if(root==NULL){
                return;
            }
            printHelper(root->left);
            cout<<root->data<<" ";
            printHelper(root->right);
        }
};

int main(){
    RedBlackTree t;
    t.insert(10);
    t.insert(20);
    t.insert(30);
    t.insert(40);
    t.insert(50);
    t.insert(60);
    t.insert(70);
    t.insert(80);
    t.insert(90);
    t.insert(100);
    t.print();
    return 0;
}