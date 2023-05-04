#include<iostream>
using namespace std;

class alpha{
	int data;
	public:
		alpha(){
			data=99;
		}
		friend class beta;
};

class beta{
	public:
	void alphaA(alpha a1){
		cout<<a1.data;
	}
};
int main(){
	alpha a;
	beta b;
	b.alphaA(a);
}