/*Implement a program to print factorial of N using recursion.
  
Input : 5
Output: 120*/

#include<iostream>
using namespace std;

int factorial(int n)
{
    if(n==1)
    {
        return 1;
    }
    else
    {
        return n*factorial(n-1);
    }

}
int main()
{
    int n;
    cin>>n;
    int a  =  factorial(n);
    cout<<a;
}
