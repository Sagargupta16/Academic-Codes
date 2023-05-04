#include<iostream>
using namespace std;

char exor(char a, char b){
    return (a==b)?'0':'1';
}

void crc(string data,string key){
    int l_key = key.length();
    string app = data;
    for(int i=0;i<l_key-1;i++){
        app+='0';
    }
    string temp = app.substr(0,l_key);
    for(int i=0;i<app.length()-l_key+1;i++){
        if(temp[0]=='1'){
            for(int j=1;j<l_key;j++){
                temp[j-1] = exor(temp[j],key[j]);
            }
        }
        else{
            for(int j=1;j<l_key;j++){
                temp[j-1] = exor(temp[j],'0');
            }
        }
        temp[l_key-1] = app[i+l_key];
    }
    cout<<"Remainder: "<<temp<<endl;
    cout<<"Data to be sent: "<<data+temp<<endl;
    bool e=false;
    for(int i=0;i<temp.length();i++){
        if(temp[i]=='1'){
            e=true;
            break;
        }
    }
    if(e) cout<<endl<<"Error detected"<<endl;
    else cout<<endl<<"No error detected"<<endl;
}

int main(){
    string data,key;
    cout<<"Enter data : ";
    cin>>data;
    cout<<"Enter Key : ";
    cin>>key;
    crc(data,key);
    return 0;
}