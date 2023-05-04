//Q-4) Calculate area of circle using pointers. 
#include<iostream>
using namespace std;

int areaCircle(int* p)
{
    int r = *p;//derefrencing
    int area = (22*r*r)/7;
    return area;
}

int main()
{
    int r;
    cout<<"Enter Radius Of Circle :";
    cin>>r;
    int* p=&r;//refrencing
    int area = areaCircle(p);
    cout<<area;
}