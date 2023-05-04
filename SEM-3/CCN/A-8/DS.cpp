#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int gcd(int a, int h){
	int temp;
	while (1) {
		temp = a % h;
		if (temp == 0) return h;
		a = h;
		h = temp;
	}
}
void gen_publickey(int p, int q, ll &e){
    ll n = p * q;
	ll phi = (p - 1) * (q - 1);
	while (e < phi) {
		if (gcd(e, phi) == 1)
		break;
		else
		e++;
	}
}
void gen_privatekey(int p,int q,int e,ll &d){
    ll n = p * q;
	ll phi = (p - 1) * (q - 1);
    while(1){
        if((e*d) % phi ==1)
        break;
        d++;
    }
}
int encrypt(int msg,int e, ll n){
    int C= pow(msg,e);
    C=C%n;
    return C;
}
int decrypt(int C,int d, ll n){
    int msg= pow(C,d);
    msg=msg%n;
    return msg;
}
int main(){
	int p = 3;
	int q = 11;
    ll e=2,d=2;
    int msg;
    gen_publickey(p,q,e);
    gen_privatekey(p,q,e,d);
    cout<<"Enter your Plain Text= ";
    cin>>msg;
    int CipherText=encrypt(msg,e,p*q);
    cout<<"Cipher Text= "<<CipherText<<"\n";
    int OriginalText=decrypt(CipherText,d,p*q);
    cout<<"Original Text= "<<OriginalText<<"\n";
	return 0;
}

