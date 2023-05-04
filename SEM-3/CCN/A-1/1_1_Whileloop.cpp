#include <iostream>
using namespace std;

int main(){
    string s;
    cout<<"Enter the string: ";
    cin>>s;
    int i=0;
    while (i!=s.length()/2){
        swap(s[i],s[s.length()-i-1]);
        i++;
    }
    cout<<"Reversed String is : "<<s;
}