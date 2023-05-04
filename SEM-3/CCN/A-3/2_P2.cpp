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
bool checkIP(string s){
	string a="";
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
		if(c>255) return false;
	}
	return true;
	
}

int main(){
	string s="10.100.24.20";
	if(checkIP(s)){
		cout<<endl<<s<<" :***It is a Valid IP Address***"<<endl;
	}
	else{
		cout<<endl<<s<<" :***Invalid IP Address***"<<endl;
	}

	s = "10.300.24.20";
	if (checkIP(s)){
		cout<<endl<<s<<" :***It is a Valid IP Address***"<<endl;
	}
	else{
		cout<<endl<<s<<" :***Invalid IP Address***"<<endl;
	}
}