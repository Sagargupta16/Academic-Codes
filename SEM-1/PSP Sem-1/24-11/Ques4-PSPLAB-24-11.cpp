/*Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

	Input: num1 = "123", num2 = "456"
	Output: "56088"
	Input: num1 = "23", num2 = "2"
	Output: "46"
*/

#include<iostream>
#include<string>
using namespace std;
int main()
{
    int x=0,y=0;
    string s1,s2,s3="";
    cout<<"Enter 2 Strings containg numbers only :";
    cin>>s1>>s2;
    for(int i=0;i<s1.length();i++)
    {
        x=x*10+int(s1[i]-48);
    }
    for(int i=0;i<s2.length();i++)
    {
        y=y*10+int(s2[i]-48);
    }
    int z = x*y,a;
    char b;
    while(z!=0)
    {
        a = z%10;
        b = char(a+48);
        s3 = b + s3;
        z=z/10;
    }
    cout<<s3;
}