// Hybrid Inheritance
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


class fare
{
private:
    
public:
    fare();
};

fare::fare()
{
    cout<<"fare"<<endl;
}

class Bus : public vehicle,public fare
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
    Bus obj1;
    car obj2;
    return 0;
}