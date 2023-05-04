#include<bits/stdc++.h>
using namespace std;

int parityCount(int n){
    int r=1;
    while(pow(2,r)<n+r+1){
        r++;
    }
    return r;
}

string encode(string d){
    int r=parityCount(d.length());
    reverse(d.begin(),d.end());
    int j=0,k=0;
    string c="";
    for(int i=1;i<=d.length()+r;i++){
        if(i==pow(2,j)){
            c+='p';
            j++;
        }
        else{
            c+=d[k];
            k++;
        }
    }
    for(int i=0;i<r;i++){
        int x=pow(2,i);
        int count=0;
        for(int j=x-1;j<c.length();j+=x){
            for(int k=0;k<x;k++){
                if(c[j+k]=='1'){
                    count++;
                }
            }
        }
        if(count%2==0){
            c[x-1]='0';
        }
        else{
            c[x-1]='1';
        }
    }
    reverse(c.begin(),c.end());
    return c;
}

string decode(string c){
    int r=parityCount(c.length());
    reverse(c.begin(),c.end());
    int j=0,k=0;
    string d="";
    for(int i=1;i<=c.length();i++){
        if(i==pow(2,j)){
            j++;
        }
        else{
            d+=c[k];
            k++;
        }
    }
    reverse(d.begin(),d.end());
    return d;
}

int error(string d,string r){
    for(int i=0;i<d.length();i++){
        if(d[i]!=r[i]){
            return i+1;
        }
    }
    return -1;
}

int main(){
    string data;
    cout<<"Enter data: ";
    cin>>data;
    string code=encode(data);
    cout<<"Encoded data: "<<code<<endl;
    cout<<"Enter received data: ";
    cin>>code;
    string decoded=decode(code);
    cout<<"Decoded data: "<<decoded<<endl;
    
    int e=error(data,decoded);
    if(e==-1){
        cout<<"No error"<<endl;
    }
    else{
        cout<<"Error at position: "<<e<<endl;
    }
    return 0;

}