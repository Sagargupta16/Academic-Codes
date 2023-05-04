// hierarchical inheritance
#include<iostream>
using namespace std;

class vehicle
{
private:
    
public:
    vehicle();
};

vehicle::vehicle()
{
    cout<<"vehicle"<<endl;
}

class Bus : public vehicle
{
private:
    
public:
    Bus();
};

Bus :: Bus()
{
    cout<<"Bus"<<endl;
}

class car : public vehicle
{
private:
public:
    car();
};

car::car()
{
    cout<<"My car"<<endl;
}

int main(){
    car obj1;
    Bus obj2;
    return 0;
}