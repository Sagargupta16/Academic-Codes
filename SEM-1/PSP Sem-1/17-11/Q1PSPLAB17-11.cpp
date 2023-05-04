//Q-1 Print a pyramid pattern of a value N.(using loops)

#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter a Number :";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            cout<<j+1<<" ";
        }
        cout<<endl;
    }
}
