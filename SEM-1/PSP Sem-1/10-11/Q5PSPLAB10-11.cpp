//5) write a c program to calculate the simple intrest. Inputs:- principle = 200,Time = 2 and Rate = 5.4 .
#include<iostream>
using namespace std;
int main()
{
    int p=200,t=2;
    double r = 5.4,SI;
    SI = (p*r*t)/100;
    cout<<"Simple Interest if p=200 , t=2 and r = 5.4 is :"<<SI<<endl;
    
}