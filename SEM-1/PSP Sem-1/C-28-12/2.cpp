// MultiLevel Inheritance
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

class fourwheeler : public vehicle
{
private:
    
public:
    fourwheeler();
};

fourwheeler :: fourwheeler()
{
    cout<<"Four Wheeler"<<endl;
}

class car : public fourwheeler
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
    car obj;
    return 0;
}