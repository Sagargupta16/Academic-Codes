#include<iostream>
using namespace std;

class LinearProbing{
    private:
        int *A;
        int size;
    public:
        LinearProbing(int s){
            size = s*2;
            A = new int[size];
            for(int i=0;i<size;i++){
                A[i]=0;
            }
        }
        void insert(int d){
            cout<<"Inserting "<<d<<" in the Hash Table"<<endl;
            int i=0;
            if(A[d%size]==0){
                A[d%size]=d;
                return;
            }
            while(A[(d+i)%size]){
                i++;
            }
            A[(d+i)%size]=d;
        }
        bool search(int d){
            int i=0;
            while(A[(d+i)%size]){
                if(A[(d+i)%size]==d){
                    return true;
                }
                i++;
            }
            return false;
        }
        void display(){
            cout<<endl<<"Hash Table: ";
            for(int i=0;i<size;i++){
                cout<<A[i]<<" ";
            }
        }
};

int main(){
    int A[] = {4,22,5,17,2,12,25,7,15};
    int n = sizeof(A)/sizeof(A[0]);
    LinearProbing l(n);
    for(int i=0;i<n;i++){
        l.insert(A[i]);
    }
    l.display();
    cout<<endl;

    cout<<endl<<"Searching 15 in the Hash Table : ";
    if(l.search(15)){
        cout<<"Key Found"<<endl;
    }
    else{
        cout<<"Key Not Found"<<endl;
    }

    return 0;
}