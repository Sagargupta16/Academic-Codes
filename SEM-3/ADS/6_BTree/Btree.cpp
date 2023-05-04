#include<iostream>
using namespace std;

class btreeNode{
public:
    int *data;
    btreeNode **childPtr;
    bool leaf;
    int n;
    btreeNode(int m){
        data = new int[m-1];
        childPtr = new btreeNode*[m];
        leaf = true;
        n = 0;
    }
};

class btree{
    btreeNode *root;
    int m;
public:
    btree(int m){
        root = NULL;
        this->m = m;
    }
    void insertNonFull(btreeNode *x, int k){
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
    void splitChild(btreeNode *x, int i, btreeNode *y){
        btreeNode *z = new btreeNode(m);
        z->leaf = y->leaf;
        z->n = m/2-1;
        for(int j=0; j<m/2-1; j++)
            z->data[j] = y->data[j+m/2];
        if(!y->leaf){
            for(int j=0; j<m/2; j++)
                z->childPtr[j] = y->childPtr[j+m/2];
        }
        y->n = m/2-1;
        for(int j=x->n; j>=i+1; j--)
            x->childPtr[j+1] = x->childPtr[j];
        x->childPtr[i+1] = z;
        for(int j=x->n-1; j>=i; j--)
            x->data[j+1] = x->data[j];
        x->data[i] = y->data[m/2-1];
        x->n = x->n+1;
    }
    void insert(int k){
        if(root == NULL){
            root = new btreeNode(m);
            root->data[0] = k;
            root->n = 1;
        }
        else{
            if(root->n == m-1){
                btreeNode *s = new btreeNode(m);
                s->childPtr[0] = root;
                s->leaf = false;
                splitChild(s, 0, root);
                int i = 0;
                if(s->data[0] < k)
                    i++;
                insertNonFull(s->childPtr[i], k);
                root = s;
            }
            else
                insertNonFull(root, k);
        }
    }
    void deletee(int k){
        if(root == NULL){
            cout<<"Tree is empty"<<endl;
            return;
        }
        deletee(root, k);
        if(root->n == 0){
            btreeNode *tmp = root;
            if(root->leaf)
                root = NULL;
            else
                root = root->childPtr[0];
            delete tmp;
        }
    }
    void deletee(btreeNode *x, int k){
        int i = 0;
        while(i<x->n && k>x->data[i])
            i++;
        if(i<x->n && k == x->data[i]){
            if(x->leaf)
                removeFromLeaf(x, i);
            else
                removeFromNonLeaf(x, i);
        }
        else{
            if(x->leaf){
                cout<<"Element not found"<<endl;
                return;
            }
            bool flag = (i==x->n);
            if(x->childPtr[i]->n < m/2)
                fill(x, i);
            if(flag && i>x->n)
                deletee(x->childPtr[i-1], k);
            else
                deletee(x->childPtr[i], k);
        }
    }
    void removeFromLeaf(btreeNode *x, int i){
        for(int j=i+1; j<x->n; j++)
            x->data[j-1] = x->data[j];
        x->n--;
    }
    void removeFromNonLeaf(btreeNode *x, int i){
        int k = x->data[i];
        if(x->childPtr[i]->n >= m/2){
            int pred = getPred(x, i);
            x->data[i] = pred;
            deletee(x->childPtr[i], pred);
        }
        else if(x->childPtr[i+1]->n >= m/2){
            int succ = getSucc(x, i);
            x->data[i] = succ;
            deletee(x->childPtr[i+1], succ);
        }
        else{
            merge(x, i);
            deletee(x->childPtr[i], k);
        }
    }
    int getPred(btreeNode *x, int i){
        btreeNode *tmp = x->childPtr[i];
        while(!tmp->leaf)
            tmp = tmp->childPtr[tmp->n];
        return tmp->data[tmp->n-1];
    }
    int getSucc(btreeNode *x, int i){
        btreeNode *tmp = x->childPtr[i+1];
        while(!tmp->leaf)
            tmp = tmp->childPtr[0];
        return tmp->data[0];
    }
    void fill(btreeNode *x, int i){
        if(i!=0 && x->childPtr[i-1]->n >= m/2)
            borrowFromPrev(x, i);
        else if(i!=x->n && x->childPtr[i+1]->n >= m/2)
            borrowFromNext(x, i);
        else{
            if(i != x->n)
                merge(x, i);
            else
                merge(x, i-1);
        }
    }
    void borrowFromPrev(btreeNode *x, int i){
        btreeNode *child = x->childPtr[i];
        btreeNode *sibling = x->childPtr[i-1];
        for(int j=child->n-1; j>=0; j--)
            child->data[j+1] = child->data[j];
        if(!child->leaf){
            for(int j=child->n; j>=0; j--)
                child->childPtr[j+1] = child->childPtr[j];
        }
        child->data[0] = x->data[i-1];
        if(!child->leaf)
            child->childPtr[0] = sibling->childPtr[sibling->n];
        x->data[i-1] = sibling->data[sibling->n-1];
        child->n++;
        sibling->n--;
    }
    void borrowFromNext(btreeNode *x, int i){
        btreeNode *child = x->childPtr[i];
        btreeNode *sibling = x->childPtr[i+1];
        child->data[child->n] = x->data[i];
        if(!(child->leaf))
            child->childPtr[child->n+1] = sibling->childPtr[0];
        x->data[i] = sibling->data[0];
        for(int j=1; j<sibling->n; j++)
            sibling->data[j-1] = sibling->data[j];
        if(!sibling->leaf){
            for(int j=1; j<=sibling->n; j++)
                sibling->childPtr[j-1] = sibling->childPtr[j];
        }
        child->n++;
        sibling->n--;
    }
    void merge(btreeNode *x, int i){
        btreeNode *child = x->childPtr[i];
        btreeNode *sibling = x->childPtr[i+1];
        child->data[m/2-1] = x->data[i];
        for(int j=0; j<sibling->n; j++)
            child->data[m/2+j] = sibling->data[j];
        if(!child->leaf){
            for(int j=0; j<=sibling->n; j++)
                child->childPtr[m/2+j] = sibling->childPtr[j];
        }
        for(int j=i+1; j<x->n; j++)
            x->data[j-1] = x->data[j];
        for(int j=i+2; j<=x->n; j++)
            x->childPtr[j-1] = x->childPtr[j];
        child->n += sibling->n+1;
        x->n--;
        delete sibling;
    }
    bool search(int k){
        return search(root, k);
    }
    bool search(btreeNode *x, int k){
        int i=0;
        while(i<x->n && k>x->data[i])
            i++;
        if(x->data[i] == k)
            return true;
        if(x->leaf)
            return false;
        return search(x->childPtr[i], k);
    }

    void traverse(){
        cout<<endl;
        if(root != NULL) traverse(root);
        cout<<endl;
    }
    void traverse(btreeNode *x){
        int i;
        for(i=0; i<x->n; i++){
            if(!x->leaf)
                traverse(x->childPtr[i]);
            cout<<x->data[i]<<" ";
        }
        if(!x->leaf)
            traverse(x->childPtr[i]);
    }
};

int main(){
    btree t(4);
    int ch;
    while(ch!=5){
        cout<<endl;
        cout<<"Menu"<<endl;
        cout<<"1. Insertion"<<endl;
        cout<<"2. Deletion"<<endl;
        cout<<"3. Search"<<endl;
        cout<<"4. Traversal"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>ch;
        switch(ch){
            case 1: int k;
                    cout<<"Enter the element to be inserted: ";
                    cin>>k;
                    t.insert(k);
                    break;
            case 2: cout<<"Enter the element to be deleted: ";
                    cin>>k;
                    t.deletee(k);
                    break;
            case 3: cout<<"Enter the element to be searched: ";
                    cin>>k;
                    t.search(k);
                    break;
            case 4: t.traverse();
                    break;
            default: cout<<"Invalid choice"<<endl;
        }
        
    }

    return 0;
}