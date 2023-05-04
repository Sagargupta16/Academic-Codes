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

char binaryIP(string s){
	int j=0;
	int n = s.length();
	string a="";
	while(s[j]!='.'&&j<n){
		a+=s[j];
		j++;
	}
	int c=stoie(a);
	if(c<127) return 'A';
	else if(c<192) return 'B';
	else if(c<224) return 'C';
	else if(c<240) return 'D';
	else return 'E';
}

int main(){
	string s ="125.0.0.1";
	cout<<endl<<"IP Address : "<<s<<endl;
	char t = binaryIP(s);
	cout<<"Class : "<<t<<endl;

	s= "145.124.134.141";
	cout<<endl<<"IP Address : "<<s<<endl;
	t = binaryIP(s);
	cout<<"Class : "<<t<<endl;
}
