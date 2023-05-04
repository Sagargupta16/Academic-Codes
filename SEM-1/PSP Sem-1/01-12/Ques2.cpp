/* Q-2 Write a program in C/C++ to find the largest and smallest word in a string. 
Test Data :
Input the string : It is a string with smallest and largest word.
Expected Output :
The largest word is 'smallest'
and the smallest word is 'a' */

#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s;
    string q[100];
    cout<<"Enter a String :";
    getline(cin,s);
    int a=s.length(),z=0;
    for(int i=0;i<a;i++)
    {
        if(s[i]!=' ')
        {
            q[z]=q[z]+s[i];
        }
        else{
            z++;
        }
    }
    string large=q[0],small=q[0];
    for(int i=0;i<=z;i++)
    {
        if(q[i].length()>large.length())
        {
            large = q[i];
        }
        if(q[i].length()<small.length())
        {
            small = q[i];
        }
    }
    cout<<"The largest word is : "<<large<<endl;
    cout<<"The smallest word is : "<<small<<endl;
    return 0;
}
