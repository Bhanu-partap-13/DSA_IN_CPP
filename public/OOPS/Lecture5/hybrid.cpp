#include<iostream>
using namespace std;

class Human{
    protected:
    string name;
    int age;
    public:
    void work(){
        cout<<"I am working"<<endl;
    }

};

//human <- boy -> male
//human <- girl -> female

Class Male{
    public:
    void display(){
        cout<<"I am a male"<<endl;
    }
};

Class Female{
    public:
    void display(){
        cout<<"I am a female"<<endl;
    }
};

class Boy: public Human, public Male{
    public: 
    void display(){
        cout<< "I a"