/*Write a C/C++ program to for keeping multiple students 
information( Name, roll number, gender, age) using structure. 
Create a function to get student information base on roll number.

Input: Enter student roll number: 50
Output: 
Name : Sumit Negi , 
Roll No. :  50, 
Gender: M, 
Age: 20*/

#include<iostream>
#include<string>
using namespace std;

struct student
{
    string name = "Sumit Negi";
    int rollno = 50;
    char gender = 'M';
    int age = 20;
}s;

int main()
{
    int n;
    cout<<"Enter Roll number of Student :";
    cin>>n;
    if(s.rollno==n)
    {
        cout<<"Name : "<<s.name<<endl;
        cout<<"Roll Number : "<<s.rollno<<endl;
        cout<<"Gender : "<<s.gender<<endl;
        cout<<"Age : "<<s.age<<endl;
    }
    else{
        cout<<"No student with given Roll number :"<<endl;
    }
}
