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

string binaryIP(string s){
	
	string a="",ans="";
	int j=0;
	int n = s.length();
	for(int i=0;i<4;i++){
		a="";
		while(s[j]!='.'&&j<n){
			a+=s[j];
			j++;
		}
		j++;
		int c=stoie(a);
		a="";
		if(c==0) a='0';
		while(c!=0){
			if(c%2!=0) a='1'+a;
			else a='0'+a;
			c=c/2;
		}
		while(a.length()!=8){
			a='0'+a;
		}
		ans+=a;
		if(i!=3) ans+='.';
	}
	return ans;
}

int main(){
	string s ="127.0.0.1";
	cout<<endl<<"IP Address : "<<s<<endl;
	string t = binaryIP(s);
	cout<<endl<<"Binary Value : "<<t<<endl;
}
