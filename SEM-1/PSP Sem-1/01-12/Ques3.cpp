/*Write a program in C/C++ to make the words  lowercase and
 Uppercase alternatively in a string. 
Test Data :
Input the string : This one is the BEST university in the World.
Expected Output :
this ONE is THE best UNIVERSITY in THE world.*/

#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s,t;
    cout<<"Enter a String :";
    getline(cin,s);
    int a=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]==' ')
        {
            if(a==0)
            a=1;
            else
            a=0;
            
            t=t+" ";
        }
        else if(a==0)
        {
            s[i]=tolower(s[i]);
            t = t +s[i];
        }
        else
        {
            s[i]=toupper(s[i]);
            t = t + s[i];
        }
    }
    cout<<t;
}