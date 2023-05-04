#include<iostream>
#include<vector>
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

void radixSort(vector<int>& a) {
    int n=a.size();
    int max=a[0];
    for(int i=1; i<n; i++) {
        if(a[i]>max) max=a[i];
    }
    int exp=1;
    while(max/exp>0) {
        vector<int> b(n);
        vector<Node*> c(10);
        for(int i=0; i<n; i++) {
            int e=a[i]/exp%10;
            if(c[e]==NULL) {
                c[e]=new Node(a[i]);
            } 
            else{
                Node* p=c[e];
                while(p->next!=NULL) p=p->next;
                p->next=new Node(a[i]);
            }
        }
        int k=0;
        for(int i=0; i<10; i++) {
            Node* p=c[i];
            while(p!=NULL) {
                b[k]=p->data;
                p=p->next;
                k++;
            }
        }
        a=b;
        exp*=10;
    }
}

void printVector(vector<int>& a) {
    for(int i=0; i<a.size(); i++) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> a = {15,978,763,893,6352,98,282,2814,4738,3};
    cout<<"Before sorting: ";
    printVector(a);
    radixSort(a);
    cout<<"After sorting: ";
    printVector(a);
}