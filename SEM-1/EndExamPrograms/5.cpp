// Q-5 Calculate Area of Square and Average of Given Five numbers 

#include<iostream>
using namespace std;

int sqarea(int s){
    return s*s;
}

float average(int a,int b,int c,int d,int e)
{
    return (a+b+c+d+e)/5;
}

int main(){
    // 1st Part of Question
    int s;
    cout<<"Enter Side Length of Square : ";
    cin>>s;
    int a = sqarea(s);
    cout<<"Area of Square with Side "<<s<<" is "<<a<<endl;

    // 2nd Part of Question
    int l,m,n,o,p;
    cout<<"Enter 5 Numbers : ";
    cin>>l>>m>>n>>o>>p;
    cout<<"Average of Entered 5 Numbers is : "<<average(l,m,n,o,p)<<endl;

    return 0;
}