#include<iostream>
using namespace std;

class Node{
public:
    int x,y;
    Node *left,*right;
    Node(int x,int y){
        this->x=x;
        this->y=y;
        left=right=NULL;
    }
};

Node* CountructPST(int arr[][2],int n){
    if(n==0) return NULL;
    int maxy=arr[0][1],yc=0;
    for(int i=0;i<n;i++){
        if(arr[i][1]>maxy){
            maxy=arr[i][1];
            yc=i;
        }
    }
    Node *root=new Node(arr[yc][0],arr[yc][1]);
    int mr = n/2;
    int ml = n-mr-1;
    int left[ml][2],right[mr][2];
    int l=0,r=0;
    for(int i=0;i<n;i++){
        if(i==yc)
            continue;
        if(l<ml){
            left[l][0]=arr[i][0];
            left[l][1]=arr[i][1];
            l++;
        }
        else{
            right[r][0]=arr[i][0];
            right[r][1]=arr[i][1];
            r++;
        }
    }
    root->left=CountructPST(left,ml);
    root->right=CountructPST(right,mr);
    return root;

}

void PrintPST(Node *root){
    if(root==NULL) return;
    cout<<"("<<root->x<<","<<root->y<<") ";
    PrintPST(root->left);
    PrintPST(root->right);
}

bool Search(Node *root,int x,int y){
    if(root==NULL) return false;
    if(root->y<y) return false;
    if(root->x==x && root->y==y) return true;
    Node* z = root->left;
    if(z==NULL) return Search(root->right,x,y);
    int l = root->left->x;
    while(z->right!=NULL){
        if(l<z->right->x)
            l=z->right->x;
        z=z->right;
    }
    if(x<=l) return Search(root->left,x,y);
    else return Search(root->right,x,y);
}

int main(){
    int ar[8][2] = {{5,45},{25,35},{35,40},{50,10},{60,75},{80,65},{85,15},{90,5}};
    int n = 8;
    Node *root = CountructPST(ar,n);
    PrintPST(root);
    cout<<endl;
    Search(root,5,45)?cout<<" Found":cout<<" Not Found";
    cout<<endl;
    Search(root,90,5)?cout<<" Found":cout<<" Not Found";
    cout<<endl;
    Search(root,10,50)?cout<<" Found":cout<<" Not Found";
    return 0;
}