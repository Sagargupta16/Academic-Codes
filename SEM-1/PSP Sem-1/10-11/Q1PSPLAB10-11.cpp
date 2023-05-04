//Q-1 write a c++ program to compute the number of seconds passed since the beginning of the month.
#include <iostream>
#define lli long long int
using namespace std;
int main()
{
    lli year,month,day;
    cout<<"Enter number of year :";
    cin>>year;
    cout<<"Enter number of month :";
    cin>>month;
    cout<<"Enter number of day :";
    cin>>day;

    cout<<"Time in Seconds :"<<((year*365 + month)*30 +day)*86400;
}