#include<iostream>
using namespace std;

class rbtreeNode{
    public:
        int data;
        rbtreeNode *left;
        rbtreeNode *right;
        rbtreeNode *parent;
        bool color;
        rbtreeNode(int data){
            this->data = data;
            left = NULL;
            right = NULL;
            parent = NULL;
            color = 0;
        }
};

class rbtree{
    rbtreeNode *root;
    rbtreeNode *TNULL;
    public:
        rbtree(){
            TNULL = new rbtreeNode(0);
            TNULL->color = 0;
            TNULL->left = NULL;
            TNULL->right = NULL;
            root = TNULL;
        }
        void insert(int data){
            rbtreeNode *node = new rbtreeNode(data);
            node->parent = NULL;
            node->data = data;
            node->left = TNULL;
            node->right = TNULL;
            node->color = 1;
            rbtreeNode *y = NULL;
            rbtreeNode *x = this->root;
            while(x != TNULL){
                y = x;
                if(node->data < x->data)
                    x = x->left;
                else
                    x = x->right;
            }
            node->parent = y;
            if(y == NULL)
                root = node;
            else if(node->data < y->data)
                y->left = node;
            else
                y->right = node;
            if(node->parent == NULL){
                node->color = 0;
                return;
            }
            if(node->parent->parent == NULL)
                return;
            insertFix(node);
        }
        void insertFix(rbtreeNode *k){
            rbtreeNode *u;
            while(k->parent->color == 1){
                if(k->parent == k->parent->parent->right){
                    u = k->parent->parent->left;
                    if(u->color == 1){
                        u->color = 0;
                        k->parent->color = 0;
                        k->parent->parent->color = 1;
                        k = k->parent->parent;
                    }
                    else{
                        if(k == k->parent->left){
                            k = k->parent;
                            rightRotate(k);
                        }
                        k->parent->color = 0;
                        k->parent->parent->color = 1;
                        leftRotate(k->parent->parent);
                    }
                }
                else{
                    u = k->parent->parent->right;
                    if(u->color == 1){
                        u->color = 0;
                        k->parent->color = 0;
                        k->parent->parent->color = 1;
                        k = k->parent->parent;
                    }
                    else{
                        if(k == k->parent->right){
                            k = k->parent;
                            leftRotate(k);
                        }
                        k->parent->color = 0;
                        k->parent->parent->color = 1;
                        rightRotate(k->parent->parent);
                    }
                }
                if(k == root)
                    break;
            }
            root->color = 0;
        }
        
        void leftRotate(rbtreeNode *x){
            rbtreeNode *y = x->right;
            x->right = y->left;
            if(y->left != TNULL)
                y->left->parent = x;
            y->parent = x->parent;
            if(x->parent == NULL)
                this->root = y;
            else if(x == x->parent->left)
                x->parent->left = y;
            else
                x->parent->right = y;
            y->left = x;
            x->parent = y;
        }
        void rightRotate(rbtreeNode *x){
            rbtreeNode *y = x->left;
            x->left = y->right;
            if(y->right != TNULL)
                y->right->parent = x;
            y->parent = x->parent;
            if(x->parent == NULL)
                this->root = y;
            else if(x == x->parent->right)
                x->parent->right = y;
            else
                x->parent->left = y;
            y->right = x;
            x->parent = y;
        }
        void print(){
            printHelper(this->root, "", true);
        }
        void printHelper(rbtreeNode *root, string indent, bool last){
            if(root != TNULL){
                cout << indent;
                if(last){
                    cout << "R----";
                    indent += "   ";
                }
                else{
                    cout << "L----";
                    indent += "|  ";
                }
                string sColor = root->color?"RED":"BLACK";
                cout << root->data << "(" << sColor << ")" << endl;
                printHelper(root->left, indent, false);
                printHelper(root->right, indent, true);
            }
        }
};

int main(){
    rbtree tree;
    tree.insert(7);
    tree.insert(3);
    tree.insert(18);
    tree.insert(10);
    tree.insert(22);
    tree.insert(8);
    tree.insert(11);
    tree.insert(26);
    tree.insert(2);
    tree.insert(6);
    tree.insert(13);
    tree.print();
    return 0;
}
