/* Q-2 Merge two sorted arrays and return it as a sorted array. 
Input: l1 = [1,2,4], l2 = [1,3,4]
Output: [1,1,2,3,4,4]*/

#include<iostream>
#include<string>
using namespace std;

int main()
{
    int n,m;
    cout<<"Enter no. of Element in 1st Array :";
    cin>>n;
    cout<<"Enter no. of Element in 2nd Array :";
    cin>>m;
    cout<<"Enter 1st array "<<n<<" Elements in sorted order : ";
    int ar[n],br[m];
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    cout<<"Enter 2nd array "<<m<<" Elements in sorted order : ";
    for(int i=0;i<m;i++)
    {
        cin>>br[i];
    }
    int j=0,k=0;
    for(int i=0;i<n+m;i++)
    {
        if(ar[j]<br[k])
        {
            cout<<ar[j]<<" ";
            j++;
        }
        else{
            cout<<br[k]<<" ";
            k++;
        }
    }
}
