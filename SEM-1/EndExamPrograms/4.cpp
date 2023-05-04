// Q-4 Example for Function Argument and return Value , and Sum of 2 numbers and whether it is even or not
#include<iostream>
using namespace std;

void function(){
    cout<<"Function Without Argument and Return Type called "<<endl;
}

int sum(int a, int b){
    return a+b;
}

void iseven(int a){
    if(a%2==0){
        cout<<"Entered Number is EVEN"<<endl;
    }
    else{
        cout<<"Entered Number is ODD"<<endl;
    }
}

int main(){
    // 1st Part of Question
    function();

    // 2nd Part of Question
    int a,b;
    cout<<"Enter 2 number you want to sum : ";
    cin>>a>>b;
    int c = sum(a,b);
    cout<<"Sum of "<<a<<" and "<<b<<" is "<<c<<endl;

    // 3rd Part of Question
    int d;
    cout<<"Enter a Number You Want to Check if it is Even or Odd : ";
    cin>>d;
    iseven(d);

    return 0;
}