#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

int main(){
    Node* head = NULL;
    Node* tail = NULL;
    Node* temp = NULL;
    int n;
    cout<<"Enter the number of nodes: ";
    cin>>n;
    cout << "Enter the data: ";
    for (int i=0;i<n;i++){
        temp = new Node;
        cin>>temp->data;
        temp->next = NULL;
        if (head==NULL){
            head = temp;
            tail = temp;
        }
        else{
            tail->next = temp;
            tail = temp;
        }
    }
    temp = head;
    cout<<"The linked list is: ";
    while (temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}