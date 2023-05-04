/*Write a c/c++ program to keep records of N students in an array of pointers to Student structure. 
Each student have name(string), roll number(int), subject marks out of 100 ( array of integers of length 5), Age (int).
Implement a function which takes roll number as argument( call by reference)  and returns student details (Name , roll number, age and percentage ) .
Input : 
No. of student: 1
Karan kumar
201
34 56 67 23 56
21
Enter roll number: 201

Output:
Name : Karan kumar
Roll No. :  201 */

#include<iostream>
#include<string>
using namespace std;

struct student
{
    string name;
    int rollno;
    int Marks[5];
    int age;
}

void getData()
{
    cout<<"Enter name : ";
    cin>>s[i].name;
    cout<<"Enter Age : ";
    cin>>s[i].age;
    cout<<"Enter Marks of 5 subjects : ";
    for(int j=0;j<5;j++)
    {
        cin>>s[i].Marks[j];
    }
}

void Display(int x)
{
    cout<<"name : "<<s[x].name<<endl;
    cout<<"Age : "<<s[x].;
    cout<<"Percentage of 5 subjects : ";

}

bool Search(int x,int i)
{

}

int main()
{
    int n;
    cout<<"Enter Number of Students :";
    cin>>n;
    struct student s[n];
    cout<<"Input 1 if you want to input a data of student "<<endl;
    cout<<"Input 2 to view the data of student "<<endl;

    int a,i=0,x;
    cin>>a;
    bool b;
    switch(a)
    {
        case 1: 
        cout<<"Enter Roll Number :";
        cin>>x;
        Search(x,i);

        
        break;
        case 2: 
        cout<<"Enter Roll number : ";
        cin>>x;
        Search(x);

    }
    
}

