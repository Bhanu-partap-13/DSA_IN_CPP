#include<iostream>
using namespace std;

class Human{
    protected:
    string name;
    int age;
    public:
    Human(){
        cout<<"I am human class"<<endl;
    }
    // ~Human(){
    //     cout<<"I am human class"<<endl;
    // }
    void work(){
        cout<<"I am working"<<endl;
    }

};

class Student: public Human{
    int rollNo, fees;
    public:

    Student(string name, int age, int rollNo, int fees){
        this->name = name;
        this->age= age;
        this->rollNo = rollNo;
        this->fees = fees;
    }
};

class Teacher: public Human{
    public:
    Teacher(int age, string name){
        this->name = name;
        this->age= age;
    }
    void display(){
        cout<<name<<" "<<age;
    }
//like we have to create default constructer in the parent class
};
int main(){
    Student S1("Bhanu", 20, 23, 12);
    S1.work();
    Teacher S2(20, "Bhanu");
    S2.display();
}
