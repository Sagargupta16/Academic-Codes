#include<iostream>
using namespace std;

class bstNode{
public:
    int data;
    bstNode *left;
    bstNode *right;
    bstNode(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

class BST{

    public:
        int height(bstNode* x){
            if(x==NULL){
                return 0;
            }
            int a=height(x->left);
            int b=height(x->right);
            return a>b ? a+1 : b+1;
        }//O(n);

        bstNode* predecessor(bstNode* r){
            while(r && r->right!=NULL){
                r=r->right;
            }
            return r;
        }//O(n)

        bstNode* successor(bstNode* r){
            while(r && r->left!=NULL){
                r=r->left;
            }
            return r;
        }//O(n)

        bstNode* insertElement(bstNode* r,int d){
            if(r==NULL){
                bstNode* a = new bstNode(d);
                return a;
            }
            if(r->data>=d){
                r->left=insertElement(r->left,d);
            }
            else{
                r->right=insertElement(r->right,d);
            }
            return r;
        }//O(log(n))

        bstNode* deleteElement(bstNode* r,int d){
            if(r==NULL){
                return NULL;
            }
            else if(r->left==NULL && r->left==NULL && r->data==d){
                delete r;
                r=NULL;
            }
            else if(d<r->data){
                r->left=deleteElement(r->left,d);
            }
            else if(d>r->data){
                r->right=deleteElement(r->right,d);
            }
            else{
                if(height(r->left)>height(r->right)){
                    bstNode* q=predecessor(r->left);
                    r->data = q->data;
                    r->left = deleteElement(r->left,q->data);
                }
                else{
                    bstNode* q=successor(r->right);
                    r->data = q->data;
                    r->right = deleteElement(r->right,q->data);
                }
            }
            return r;
        }

        //Inorder = >  left/root/right
        void InorderDisplay(bstNode* r){
            if(r==NULL){
                return;
            }
            InorderDisplay(r->left);
            cout<<r->data<<" ";
            InorderDisplay(r->right);
        }//O(n)

        //Preorder = > root/left/right
        void PreorderDisplay(bstNode* r){
            if(r==NULL){
                return;
            }
            cout<<r->data<<" ";
            PreorderDisplay(r->left);
            PreorderDisplay(r->right);
        }//O(n)

        //Postorder = > left/right/root
        void PostorderDisplay(bstNode* r){
            if(r==NULL){
                return;
            }
            PostorderDisplay(r->left);
            PostorderDisplay(r->right);
            cout<<r->data<<" ";
        }//O(n)
};

int main(){

    BST b;
    bstNode* root = NULL;

    root = b.insertElement(root,15);
    root = b.insertElement(root,10);
    root = b.insertElement(root,20);
    root = b.insertElement(root,12);
    root = b.insertElement(root,17);

    cout<<"Inorder   : ";
    b.InorderDisplay(root);
    cout<<endl;

    cout<<"Preorder  : ";
    b.PreorderDisplay(root);
    cout<<endl;

    cout<<"Postorder : ";
    b.PostorderDisplay(root);
    cout<<endl;

    root = b.deleteElement(root, 12);
    root = b.deleteElement(root, 15);

    cout<<"Inorder   : ";
    b.InorderDisplay(root);
    cout<<endl;

    return 0;
}