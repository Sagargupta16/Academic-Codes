#include <iostream>
using namespace std;

struct student{
    string name;
    int roll;
    int marks;
};

int main(){
    student s1;
    s1.name = "Sagar";
    s1.roll = 47;
    s1.marks = 100;
    cout<<"Name : "<<s1.name<<endl;
    cout<<"Roll : "<<s1.roll<<endl;
    cout<<"Mark : "<<s1.marks<<endl;
}