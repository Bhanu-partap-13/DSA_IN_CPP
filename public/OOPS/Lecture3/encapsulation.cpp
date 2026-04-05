#include<iostream>
using namespace std;

class Customer{
    public:
    string name;
    int acc_no, balance;
    static int total_customers; //It wil be created only once
    static int total_balance;
    public:
    Customer(string name, int acc_no, int balance){
        this->name = name;
        this->acc_no = acc_no;
        this->balance = balance;
        total_customers++;
    }
    void withdraw(int amount){
        if(balance >= amount){
            balance -= amount;
            total_balance -= amount;
        }
    }
    void deposit(int amount){
        if(amount > 0){
            balance += amount;
        }
        else{
            cout<<"Invalid amount"<<endl;
        }
    }
    void display(){
        cout<<name<<" "<<acc_no<<" "<<balance<<" "<<total_customers<<endl;
    }
};
int Customer::total_customers = 0; // static variable ko initialize karna padta hai
int Customer::total_balance = 0; // static variable ko initialize karna padta hai
int main(){
    Customer C1("bhanu", 123, 1020);
    Customer C2("relativity", 324, 1020);
    C1.display();
    C2.display();
}