#include<iostream>
using namespace std;

class treeNode{
public:
    int data;
    treeNode *parent;
    treeNode *left;
    treeNode *right;
    treeNode(int data){
        this->data = data;
        left = NULL;
        right = NULL;
        parent = NULL;
    }
};

class SplayTree{
public:
    treeNode *root;
    SplayTree(){
        root = NULL;
    }
    void insert(int data){
        treeNode *newNode = new treeNode(data);
        if(root == NULL){
            root = newNode;
            return;
        }
        treeNode *temp = root;
        treeNode *parent = NULL;
        while(temp != NULL){
            parent = temp;
            if(data < temp->data){
                temp = temp->left;
            }
            else{
                temp = temp->right;
            }
        }
        if(data < parent->data){
            parent->left = newNode;
        }
        else{
            parent->right = newNode;
        }
        newNode->parent = parent;
        splay(newNode);
    }
    void splay(treeNode *node){
        while(node->parent != NULL){
            if(node->parent->parent == NULL){
                if(node->parent->left == node){
                    rightRotate(node->parent);
                }
                else{
                    leftRotate(node->parent);
                }
            }
            else if(node->parent->left == node && node->parent->parent->left == node->parent){
                rightRotate(node->parent->parent);
                rightRotate(node->parent);
            }
            else if(node->parent->right == node && node->parent->parent->right == node->parent){
                leftRotate(node->parent->parent);
                leftRotate(node->parent);
            }
            else if(node->parent->left == node && node->parent->parent->right == node->parent){
                rightRotate(node->parent);
                leftRotate(node->parent);
            }
            else{
                leftRotate(node->parent);
                rightRotate(node->parent);
            }
        }
    }
    void rightRotate(treeNode *node){
        treeNode *temp = node->left;
        node->left = temp->right;
        if(temp->right != NULL){
            temp->right->parent = node;
        }
        temp->parent = node->parent;
        if(node->parent == NULL){
            root = temp;
        }
        else if(node->parent->left == node){
            node->parent->left = temp;
        }
        else{
            node->parent->right = temp;
        }
        temp->right = node;
        node->parent = temp;
    }
    void leftRotate(treeNode *node){
        treeNode *temp = node->right;
        node->right = temp->left;
        if(temp->left != NULL){
            temp->left->parent = node;
        }
        temp->parent = node->parent;
        if(node->parent == NULL){
            root = temp;
        }
        else if(node->parent->left == node){
            node->parent->left = temp;
        }
        else{
            node->parent->right = temp;
        }
        temp->left = node;
        node->parent = temp;
    }
    void search(int data){
        treeNode *temp = root;
        while(temp != NULL){
            if(data == temp->data){
                splay(temp);
                return;
            }
            else if(data < temp->data){
                temp = temp->left;
            }
            else{
                temp = temp->right;
            }
        }
        cout << "Element not found" << endl;
    }
    void deleteNode(int data){
        search(data);
        if(root == NULL){
            return;
        }
        if(root->left == NULL){
            treeNode *temp = root;
            root = root->right;
            if(root != NULL){
                root->parent = NULL;
            }
            delete temp;
        }
        else{
            treeNode *temp = root->left;
            while(temp->right != NULL){
                temp = temp->right;
            }
            temp->right = root->right;
            if(root->right != NULL){
                root->right->parent = temp;
            }
            treeNode *temp2 = root;
            root = root->left;
            root->parent = NULL;
            delete temp2;
        }
    }
    void printInorder(treeNode *node){
        if(node == NULL){
            return;
        }
        cout << node->data << " ";
        printInorder(node->left);
        printInorder(node->right);
    }
};

int main(){
    SplayTree tree;
    tree.insert(5);
    tree.printInorder(tree.root);
    cout<<endl;
    tree.insert(3);
    tree.printInorder(tree.root);
    cout<<endl;
    tree.insert(6);
    tree.printInorder(tree.root);
    cout<<endl;
    tree.insert(2);
    tree.printInorder(tree.root);
    cout<<endl;
    tree.insert(4);
    tree.printInorder(tree.root);
    cout<<endl;
    tree.insert(7);
    tree.printInorder(tree.root);
    cout<<endl;
    cout << endl;
    tree.search(30);
    tree.printInorder(tree.root);
    cout << endl;
    tree.deleteNode(30);
    tree.printInorder(tree.root);
    cout << endl;
    return 0;
}
