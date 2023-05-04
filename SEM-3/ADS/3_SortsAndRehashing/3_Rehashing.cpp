#include<iostream>
using namespace std;

class LinearProbing{
    private:
        int *A;
        int size;
        int fill;
    public:
        LinearProbing(int s){
            size = s;
            fill = 0;
            A = new int[size];
            for(int i=0;i<size;i++){
                A[i]=0;
            }
        }
        void rehashing(){
            size = size*2;
            int B[size] = {0};
            for(int i=0;i<size/2;i++){
                if(A[i]!=0){
                    int j=0;
                    while(B[(A[i]+j)%size]!=0){
                        j++;
                    }
                    B[(A[i]+j)%size]=A[i];
                }
            }
            delete []A;
            A = new int[size];
            for(int i=0;i<size;i++){
                A[i]=B[i];
            }
        }
        void insert(int d){
            cout<<"Inserting "<<d<<" in the Hash Table"<<endl;
            int i=0;
            if(A[d%size]==0){
                A[d%size]=d;
                fill++;
                if(fill==size-1) rehashing();
                return;
            }
            while(A[(d+i)%size]){
                i++;
            }
            A[(d+i)%size]=d;
            fill++;
            if(fill==size-1){
                cout<<endl<<"--Rehashing!--"<<endl;
                rehashing();
            }
        }
        void display(){
            cout<<endl<<"Hash Table: ";
            for(int i=0;i<size;i++){
                cout<<A[i]<<" ";
            }
            cout<<endl;
        }
};

int main(){
    int a[10] = {15,978,763,893,6352,98,282,2814,4738,3};
    int n= sizeof(a)/sizeof(a[0]);
    LinearProbing l(5);
    l.display();
    cout<<endl;
    for(int i=0;i<4;i++){
        l.insert(a[i]);
    }
    l.display();
    cout<<endl;
    for(int i=4;i<n;i++){
        l.insert(a[i]);
    }
    l.display();
    cout<<endl;

}