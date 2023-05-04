#include<iostream>
using namespace std;

int stoie(string s){
	int n=s.length();
	int ans=0;
	for(int i=0;i<n;i++){
		ans*=10;
		ans+=int(s[i]-'0');
	}
	return ans;
}

string decToHex(string d){
	int e = stoie(d);
	string x="";
	while(e!=0) {
		int z=e%16;
		if(z<10){
			x=char(z+'0')+x;
		} 
		else{
			x=char(z-10+'a')+x;
		}
		e/=16;
	}
	if(x.length()==0) x='0'+x;
	if(x.length()==1) x='0'+x;
	return x;
}

string ipToHex(string ip){
	string a[4]={""};
	int j=0;
	int n = ip.length();
	for(int i=0;i<4;i++){
		while(ip[j]!='.'&&j<n){
			a[i]+=ip[j];
			j++;
		}
		j++;
	}
	string ans="0x";
	for(int i=0;i<4;i++){
		ans+=decToHex(a[i]);
	}
	return ans;
}

int main(){
	string s = "127.0.0.1";
	cout<<endl<<"Ip Address : "<<s<<endl;
	string hex = ipToHex(s);
	cout<<endl<<"Hex value : "<<hex<<endl;
}