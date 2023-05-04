#include <iostream>
using namespace std;

void swappointer(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int a = 10 , b = 20;
    cout<<"Before swapping: a = "<<a<<" b = "<<b<<endl;
    swappointer(&a, &b);
    cout<<"After swapping: a = "<<a<<" b = "<<b<<endl;
}