//Q4 Write a program to reverse the words in a given String
#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s,q="";
    cout<<"Enter a String :";
    getline(cin,s);
    for(int i=0;i<s.length();i++)
    { 
        if(s[i]!=' ')
        { 
            q=s[i]+q;
        }
        else
        {
            cout<<q<<" ";
            q="";
        } 
    } 
    cout<<q;

    return 0;
}

