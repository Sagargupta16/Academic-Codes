//Q-3) Swapping 2 numbers using pointers.
#include<iostream>
using namespace std;
void swaping(int *a,int *b){
    *a= (*a)*(*b);
    *b= (*a)/(*b);
    *a= (*a)/(*b);
}
int main (){
    int a,b;
    cout<<"Enter 2 numbers: ";
    cin>>a>>b;
    cout<<"a before Swap  = "<<a<<endl<<"b before Swap = "<<b<<endl;
    int* p1=&a,*p2=&b;//refrencing
    swaping(p1,p2);
    cout<<"a after Swap = "<<a<<endl<<"b after Swap = "<<b<<endl;

    return 0;
}