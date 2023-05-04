//Q-4 write a c program to find diameter , circumference and area of circle.
#include<iostream>
using namespace std;
int main()
{
    int r,d;
    cout<<"Enter Radius of Circle :";
    cin>>r;
    d = r*2;
    cout<<"Diameter of Circle is : "<<d<<endl;
    double c =(44*r)/7;
    cout<<"Circumference of Circle is : "<<c<<endl;
    double area = (22*r*r)/7;
    cout<<"Area of Circle is : "<<area<<endl;
}