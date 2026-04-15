#include<iostream>
using namespace std;

class Animal{
    public:
    //virtual void eat() = 0; pure virtual function // Hum isko abstract class bhi kehte h
    virtual void eat(){
        cout<<"I am eating"<<endl;
    }
};
class Dog: public Animal{
    public:
    void eat(){
        cout<<"I am eating dog food"<<endl;
    }
};

int main(){
    Animal *d = new Dog();
    d->eat(); // abhi agar virtual keyword nhi lgaya toh ye chlega parent class main par object toh child class ka 
    return 0;
}