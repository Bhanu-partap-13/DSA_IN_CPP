#include<iostream>
using namespace std;

class Human{
    private:
    int a;
    protected:
    int b;
    public:
    int c;
    void fun(){
        a = 10;
        b = 20; 
        c = 30;
    }
};

int main(){
    Human Rohit;
    //Rohit.a = 10;     | This will give error because the private members cannot be accessible to other class
    //Rohit.b = 20;     | This is also not accessible to another class
    Rohit.c = 30;
    Rohit.fun();    // This will not giveany error, Also it will also work in protected view.
}

