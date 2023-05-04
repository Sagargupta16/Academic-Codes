//Q-1) Write a C Program to show the traverse array using pointer.Input:-10,34,13,76,5,46
#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter number of element in array :";
    cin>>n;
    int ar[n];
    cout<<"Enter elements in array :";
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    //traversing array by pointers
    int *p = ar;
    while(n--)
    {
        cout<<*p<<" ";
        *p++;
    }
}