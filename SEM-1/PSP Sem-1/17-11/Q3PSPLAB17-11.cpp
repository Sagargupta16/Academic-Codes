//Q-3 Write a program to rotate array-elements to right by k th times
#include<iostream>
using namespace std;
int main()
{
    int n,k;
    cout<<"Enter Number of Elements in Array :";
    cin>>n;
    int ar[100],br[100];
    cout<<"Enter "<<n<<" elements separated by space : ";
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    cout<<"Enter how much time you want to move array by : ";
    cin>>k;
    for(int i=0;i<n-k;i++)
    {
        br[i+k] = ar[i]; 
    }
    for(int i=0;i<k;i++)
    {
        br[i]=ar[n-k+i];
    }
    for(int i=0;i<n;i++)
    {
        cout<<br[i]<<" ";
    }
}