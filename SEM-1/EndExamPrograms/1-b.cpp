// Q-1 b) Number Factorial

#include<iostream>
using namespace std;

long long int factorial(int n)
{
    if(n > 1)
        return n * factorial(n - 1);
    else
        return 1;
}

int main(){
    int n;
    cout<<"Enter Number : ";
    cin>>n;
    cout<<"Factorial of "<<n<<" is "<<factorial(n)<<endl;
    return 0;
}