#include<iostream>
using namespace std;
class Node{
    public:
        int coff,pow;
        Node* next;
        Node(int d1,int d2){
            coff=d1;
            pow=d2;
            next=NULL;
        }
};
class Polynomial
{
    public:
        Node *head,*tail;
        Polynomial(){
            head = NULL;
            tail = NULL;
        }
        void insert(int x,int y){
            Node * a = new Node(x,y);
            if(head==NULL){
                head=a;
                tail=a;
                return;
            }
            tail->next=a;
            tail=tail->next;
        }
        void Display(){
            Node * a = head;
            while(a->next!=NULL){
                cout<<a->coff<<"x^"<<a->pow;
                a=a->next;
                if (a->coff >= 0){
                    cout<<" +";
                }
                else{
                    cout<<" ";
                }
            }
            cout<<a->coff<<endl;
        }
};

Polynomial AddOperation(Node* a,Node *b){
    Polynomial C;
    while(a!=NULL && b!=NULL){
        if(a->pow==b->pow){
            C.insert(a->coff+b->coff,a->pow);
            a=a->next;
            b=b->next;
        }
        else if(a->pow>b->pow){
            C.insert(a->coff, a->pow);
            a=a->next;
        }
        else{
            C.insert(b->coff, b->pow);
            b = b->next;
        }
    }
    if(a==NULL){
        while(b!=NULL){
            C.insert(b->coff, b->pow);
            b = b->next;
        }
    }
    else if(b==NULL){
        while(a!=NULL){
            C.insert(a->coff, a->pow);
            a = a->next;
        }
    }
    return C;
}
Polynomial SubOperation(Node *a, Node *b)
{
    Polynomial C;
    while (a != NULL && b != NULL){
        if (a->pow == b->pow){
            C.insert(a->coff - b->coff, a->pow);
            a = a->next;
            b = b->next;
        }
        else if (a->pow > b->pow){
            C.insert(a->coff, a->pow);
            a = a->next;
        }
        else{
            C.insert(-b->coff, b->pow);
            b = b->next;
        }
    }
    if (a == NULL){
        while (b != NULL){
            C.insert(b->coff, b->pow);
            b = b->next;
        }
    }
    else if (b == NULL){
        while (a != NULL){
            C.insert(a->coff, a->pow);
            a = a->next;
        }
    }
    return C;
}
int main(){
    Polynomial p1,p2;
    int n,x,y;
    cout<<"Enter number of terms in 1st Equation : ";
    cin>>n;
    cout<<"Enter 1st Equation coefficient than Power ! "<<endl;
    for(int i=0;i<n;i++){
        cout<<"Enter Coefficient and Power : ";
        cin>>x>>y;
        p1.insert(x,y);
    }
    cout << "Enter number of terms in 2nd Equation : ";
    cin >> n;
    cout << "Enter 2nd Equation coefficient than Power ! "<<endl;
    for (int i=0;i<n;i++){
        cout << "Enter Coefficient and Power : ";
        cin >> x >> y;
        p2.insert(x, y);
    }

    cout<<endl<<"Equation 1 is : ";
    p1.Display();
    cout<<"Equation 2 is : ";
    p2.Display();

    Polynomial Add = AddOperation(p1.head,p2.head);
    cout<<"Addition of eq1 and eq2 is : ";
    Add.Display();

    Polynomial Sub = SubOperation(p1.head,p2.head);
    cout << "Subtraction of eq2 from eq1 : ";
    Sub.Display();

    return 0;
}