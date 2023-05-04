// Single Inheritance
#include<iostream>
using namespace std;

class vehicle
{
private:
public:
    vehicle();
};

class car : public vehicle
{
private:
public:
    car(){
        cout<<"MCA";
    }
};

vehicle::vehicle()
{
    cout<<"Vehicle"<<endl;
}

int main(){
    car obj;
    return 0;
}