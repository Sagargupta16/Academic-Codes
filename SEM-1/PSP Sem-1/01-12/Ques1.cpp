/* Q-1  Write a C/C++ program to check whether a given substring is present in the given string. 
        Without using in built function (i.e. strstr( ) )for substring finding.
        Test Data :
        Input the string : This is a test string.
        Input the substring to be search : search
        Expected Output :
        The substring is not exists in the string.*/


#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s,q="",t;
    cout<<"Enter a String :";
    getline(cin,s);
    cout<<"Enter a substring to be Found in String :";
    getline(cin,t);

    int a=s.length(),b=t.length(),i,j;

    for(i=0;i<a-b;i++)
    {
        for(j=0;j<b;j++)
        {
            if(s[i+j]!=t[j])
            {
                break;
            }
        }
        if(j==b)
        {
            cout<<"The substring exists in the string ";
            break;
        }
    }
    if(i==a-b)
    {
        cout<<"The substring is not exists in the string ";
    }
    return 0;
}