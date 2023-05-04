#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Input the number of elements to be stored in the array :";
    cin>>n;
    int ar[n],br[3]={0},cr[3]={1,1,1};
    int a=0;
    cout<<"Input 3 elements in the array :"<<endl;
    for(int i=0;i<n;i++){
        cout<<"element - "<<i<<" : ";
        cin>>ar[i];
        if(br[0]==ar[i]){
            cr[0]++;
            continue;
        }
        if(br[1]==ar[i]){
            cr[1]++;
            continue;
        }
        if(br[2]==ar[i]){
            cr[2]++;
            continue;
        }
        br[a]=ar[i];
        a++;
    }
    for(int i=0;i<3;i++){
        cout<<br[i]<<" occurs "<<cr[i]<<" times "<<endl;
    }
    return 0;
}