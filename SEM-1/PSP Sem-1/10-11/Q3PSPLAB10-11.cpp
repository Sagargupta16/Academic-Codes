//Q-3 write the c program convert the days to year ,months and weeks 
#include <iostream>
#define lli long long int
using namespace std;
int main()
{
    lli year,month,day,week;
    cout<<"Enter number of Days :";
    cin>>day;
    year =  day/365;
    day = day%365;
    month = day/30;
    day =  day%30;
    week = day/7;
    day = day%7;
    cout<<year<<" Year "<<month<<" Months "<<week<<" Weeks and "<<day<<" Days "<<endl;

}