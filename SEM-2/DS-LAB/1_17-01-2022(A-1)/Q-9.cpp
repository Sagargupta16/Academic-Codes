#include<iostream>
using namespace std;

int gcd(int i, int j)
{
    if(i==j){
        return i;
    }
    else if (i>j){
        return gcd(i-j,j);
    }
    else{
        return gcd(i,j-i);
    }
}
int main()
{
    int n,z=0;
    cout<<"Enter Order for finding farey Series : ";
    cin>>n;
    int ar[n*n];
    int br[n*n];
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
           if(gcd(i,j)==1)
           {
               ar[z]=i;
               br[z]=j;
               z++;
           }
        }
    }
    for(int i=0;i<z-1;i++)
    {
        for(int j=0;j<z-1;j++)
        {
            if((ar[j]*br[j+1])>(ar[j+1]*br[j]))
            {
                int t=ar[j];
                ar[j]=ar[j+1];
                ar[j+1]=t;

                t=br[j];
                br[j]=br[j+1];
                br[j+1]=t;

            }
        }
    }
    cout<<"Farey Series of order "<<n<<" is "<<endl;
    cout<<"0/1 ";
    for(int i=0;i<z;i++){
        cout<<ar[i]<<"/"<<br[i]<<" ";
    }
    cout<<"1/1";
}