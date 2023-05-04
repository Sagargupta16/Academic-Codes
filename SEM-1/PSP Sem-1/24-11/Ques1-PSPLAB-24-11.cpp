/* Q-1 Given a string s, return true if s is a good string, or false otherwise. A string s is good if all the characters
 that appear in s have the same number of occurrences (i.e., the same frequency).
Input: s = "abacbc"
Output: true*/

#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s;
    cout<<"Enter String in lowercase only or uppercase only :";
    cin>>s;
    int a=0,count=0;
    for(int i=0;i<s.length();i++)
    {
        count=0;
        for(int j=0;j<s.length();j++)
        {
            if(s[i]==s[j])
            {
                count++;
            }
        }
        if(i==0)
        {
            a = count;
        }
        else
        {
            if(count!=a)
            {
                cout<<"NO";
                break;
            }
        }
        if(i==s.length()-1)
        {
            cout<<"YES";
        }
    }
}