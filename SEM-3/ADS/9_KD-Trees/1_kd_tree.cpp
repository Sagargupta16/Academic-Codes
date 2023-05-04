#include<iostream>
#include<queue>
using namespace std;

class Node{
public:
    int x,y;
    Node *left,*right;
    Node(int x,int y){
        this->x = x;
        this->y = y;
        left = right = NULL;
    }
};

class KDTree{
public:
    Node *root;
    KDTree(){
        root = NULL;
    }
    void insert(int x,int y){
        root = insert(root,x,y,0);
    }
    Node* insert(Node *root,int x,int y,int depth){
        if(root == NULL) return new Node(x,y);
        if(depth%2 == 0){
            if(x < root->x) root->left = insert(root->left,x,y,depth+1);
            else root->right = insert(root->right,x,y,depth+1);
        }
        else{
            if(y < root->y) root->left = insert(root->left,x,y,depth+1);
            else root->right = insert(root->right,x,y,depth+1);
        }
        return root;
    }
    void deleteNode(int x,int y){
        root = deleteNode(root,x,y,0);
    }
    Node* deleteNode(Node *root,int x,int y,int depth){
        if(root == NULL) return NULL;
        if(root->x == x && root->y == y){
            if(root->left == NULL && root->right == NULL){
                delete root;
                return NULL;
            }
            else if(root->left == NULL){
                Node *temp = root->right;
                delete root;
                return temp;
            }
            else if(root->right == NULL){
                Node *temp = root->left;
                delete root;
                return temp;
            }
            else{
                Node *temp = root->right;
                while(temp->left != NULL){
                    temp = temp->left;
                }
                root->x = temp->x;
                root->y = temp->y;
                root->right = deleteNode(root->right,temp->x,temp->y,depth+1);
            }
        }
        else{
            if(depth%2 == 0){
                if(x < root->x) root->left = deleteNode(root->left,x,y,depth+1);
                else root->right = deleteNode(root->right,x,y,depth+1);
            }
            else{
                if(y < root->y) root->left = deleteNode(root->left,x,y,depth+1);
                else root->right = deleteNode(root->right,x,y,depth+1);
            }
        }
        return root;
    }
    bool search(int x,int y){
        return search(root,x,y,0);
    }
    bool search(Node *root,int x,int y,int depth){
        if(root == NULL) return false;
        if(root->x == x && root->y == y) return true;
        if(depth%2 == 0){
            if(x < root->x) return search(root->left,x,y,depth+1);
            else return search(root->right,x,y,depth+1);
        }
        else{
            if(y < root->y) return search(root->left,x,y,depth+1);
            else return search(root->right,x,y,depth+1);
        }
    }
    void print(Node *root){
        if(root == NULL) return;
        print(root->left);
        cout<<"("<<root->x<<","<<root->y<<") ";
        print(root->right);
    }
    void print(){
        print(root,0);
        cout<<endl;
    }
    void print(Node* root, int depth) {
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                Node* node = q.front();
                q.pop();
                if (node == NULL) {
                    cout << "null ";
                    continue;
                }
                cout << "(" << node->x << "," << node->y << ") ";
                q.push(node->left);
                q.push(node->right);
            }
            cout << endl;
        }
    }
};

int main(){
    KDTree tree;
    tree.insert(3,6);
    tree.insert(17,15);
    tree.insert(13,15);
    tree.insert(6,12);
    tree.insert(9,1);
    tree.insert(2,7);
    tree.insert(10,19);
    tree.print();
    tree.search(10,19) ? cout<<"Found"<<endl : cout<<"Not Found"<<endl;
    tree.deleteNode(10,19);
    cout<<endl;
    tree.print();
    tree.search(10,19) ? cout<<"Found"<<endl : cout<<"Not Found"<<endl;
    
    return 0;
}
