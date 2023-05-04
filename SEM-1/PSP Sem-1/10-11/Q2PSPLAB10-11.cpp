//Q-2 write the c program to convert the temperature from degree celsius to fahrenheit.
#include <iostream>
using namespace std;
int main()
{
    int c;
    cout<<"Enter Temperature in Celcius :";
    cin>>c;
    double f = (c*9/5)+32;
    cout<<"Temperature in Fahrenheit is :"<<f;
}