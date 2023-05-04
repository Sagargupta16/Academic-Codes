//Q-2 Write a  program for counting frequency of an integer in an array.

#include<iostream>
using namespace std;
int main()
{
    int n,f,count=0;
    cout<<"Enter Number of Elements in Array :";
    cin>>n;
    int ar[100];
    cout<<"Enter "<<n<<" elements seprated by space : ";
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    cout<<"Enter number you want to find Frequency of :";
    cin>>f;
    for(int i=0;i<n;i++)
    {
        if(f==ar[i])
        {
            count++;
        }
    }
    cout<<"Frequency of "<<f<<" is "<<count;
}