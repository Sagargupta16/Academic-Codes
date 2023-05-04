#include <iostream>
using namespace std;
int main(){
    int A[]={0,1,20,2,20,21,32,31,0,60,0,0,16,1,17,18,32,31,0,61};
    int n = sizeof(A)/sizeof(A[0]);
    int pagesize = 3,hit=0,a=0,b=0;
    int B[pagesize];

    for(int i=0;i<pagesize;i++){
        B[i]=A[i];
    }

    for(int i=0;i<pagesize;i++){
        for(int j=0;j<=i;j++){
            cout<<B[j]<<"  ";
        }
        cout<<endl;
    }
    
    for(int i=pagesize;i<n;i++){
        a=0;
        for(int j=0;j<pagesize;j++){
            if(A[i]==B[j]){
                hit++;
                cout<<A[i]<<"  Hit"<<endl;
                a=1;
                break;
            }
        }
        if(a==1){
            continue;
        }
        else{
            B[b]=A[i];
            if(b==2){
                b=-1;
            }
            b++;
        }
        for(int j=0;j<pagesize;j++){
            cout<<B[j]<<"  ";
        }
        cout<<endl;
    }
    cout<<endl<<"Hit Ratio = "<<hit<<"/"<<n<<endl;
    cout<<endl<<"Miss Ratio = "<<n-hit<<"/"<<n<<endl<<endl;
}