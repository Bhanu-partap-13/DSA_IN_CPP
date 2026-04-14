#include<iostream>
using namespace std;

class Person{
    protected:
    string name;
    
    public:
    void work(){
        cout<<"Welcome to the work class"<<endl;
    }
};
class Employee: public Person{
    protected:
        int salary;
    public:
        void month_salary(){
            cout<<"This is my salary"<<salary<<endl;
        }
};
class Manager: public Employee{
    public:
    string promotion;
    Manager(string name, int salary, string promotion){
        this->name = name;
        this->salary = salary;
        this->promotion = promotion;
    }
    void result(){
        cout<<promotion<<" "<<name<<"You are the king of the company as you are the founder "<<salary<<endl;
    }
};

int main(){
    Manager M1("Bhanu", 1000000, "Yes");
    M1.result();
    M1.month_salary();
    M1.work();
}