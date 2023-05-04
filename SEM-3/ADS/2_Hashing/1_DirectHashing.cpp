#include <iostream>
using namespace std;

class directHashing{
    private:
        int *A;
        int size;
    public:
        directHashing(int s){
            A = new int [s];
            size = s;
            for (int i=0;i<s;i++){
                A[i]=-1;
            }
        }
        void insert(int d){
            A[d%size] = d;
        }
        bool search(int d){
            if (A[d%size]==d) return true;
            return false;
        }
        void display(){
            cout<<"Hash Table: ";
            for (int i=0;i<size;i++){
                cout<<A[i]<<" ";
            }
            cout<<endl;
        }
};

int main(){
    int a[]={4,1,5,0,17,2,14,5,7,15};
    int n=sizeof(a)/sizeof(a[0]);
    int max=a[0];
    for(int i=1;i<n;i++){
        if(a[i]>max) max=a[i];
    }
    directHashing dh(max+1);
    for(int i=0;i<n;i++){
        dh.insert(a[i]);
    }
    dh.display();
    int e = 5;
    if(dh.search(e)) cout<<e<<" is present in the Hash Table"<<endl;
    else cout<<e<<" is not present in the Hash Table"<<endl;

    return 0;
}