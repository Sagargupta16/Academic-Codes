#include<iostream>
using namespace std;

class bplustreeNode{
public:
    int *data;
    bplustreeNode **childPtr;
    bplustreeNode *next;
    bool leaf;
    int n;
    bplustreeNode(int m){
        data = new int[m-1];
        childPtr = new bplustreeNode*[m];
        next = NULL;
        leaf = true;
        n = 0;
    }
};

class bplustree{
    bplustreeNode *root;
    bplustreeNode *head;
    int m;
public:
    bplustree(int m){
        root = NULL;
        head = NULL;
        this->m = m;
    }
    void insertNonFull(bplustreeNode *x, int k){
        int i = x->n-1;
        if(x->leaf){
            while(i>=0 && k<x->data[i]){
                x->data[i+1] = x->data[i];
                i--;
            }
            x->data[i+1] = k;
            x->n = x->n+1;
        }
        else{
            while(i>=0 && k<x->data[i])
                i--;
            i++;
            if(x->childPtr[i]->n == m-1){
                splitChild(x, i, x->childPtr[i]);
                if(k>x->data[i])
                    i++;
            }
            insertNonFull(x->childPtr[i], k);
        }
    }
    void splitChild(bplustreeNode *x, int i, bplustreeNode *y){
        bplustreeNode *z = new bplustreeNode(m);
        z->leaf = y->leaf;
        z->n = m/2-1;
        for(int j=0; j<m/2-1; j++)
            z->data[j] = y->data[j+m/2];
        if(!y->leaf){
            for(int j=0; j<m/2; j++)
                z->childPtr[j] = y->childPtr[j+m/2];
        }
        y->n = m/2;
        for(int j=x->n; j>=i+1; j--)
            x->childPtr[j+1] = x->childPtr[j];
        x->childPtr[i+1] = z;
        for(int j=x->n-1; j>=i; j--)
            x->data[j+1] = x->data[j];
        x->data[i] = y->data[m/2-1];
        x->n = x->n+1;
        if(y->leaf){
            z->next = y->next;
            y->next = z;
        }
    }
    void insert(int k){
        if(root == NULL){
            root = new bplustreeNode(m);
            root->data[0] = k;
            root->n = 1;
            head = root;
        }
        else{
            if(root->n == m-1){
                bplustreeNode *s = new bplustreeNode(m);
                s->childPtr[0] = root;
                s->leaf = false;
                splitChild(s, 0, root);
                int i = 0;
                if(s->data[0]<k)
                    i++;
                insertNonFull(s->childPtr[i], k);
                root = s;
            }
            else{
                insertNonFull(root, k);
            }
        }
    }
    void traverse(){
        bplustreeNode *x = head;
        while(x!=NULL){
            cout<<"|";
            for(int i=0; i<x->n; i++)
                cout<<x->data[i]<<"|";
            cout<<"   ";
            x = x->next;
        }
    }


};

int main(){
    bplustree t(5);
    t.insert(10);
    t.insert(20);
    t.insert(5);
    t.insert(6);
    t.insert(12);
    t.insert(30);
    t.insert(7);
    t.insert(17);
    t.insert(3);
    t.insert(1);
    t.insert(15);
    t.insert(18);
    t.insert(25);
    t.insert(13);
    t.insert(19);
    t.insert(24);
    t.insert(21);
    t.insert(23);
    t.insert(22);
    t.insert(11);
    t.insert(14);
    t.insert(16);
    t.insert(8);
    t.insert(9);
    t.insert(4);
    t.insert(2);
    t.insert(27);
    t.insert(28);
    t.insert(29);
    t.insert(26);
    t.traverse();
    return 0;
}
