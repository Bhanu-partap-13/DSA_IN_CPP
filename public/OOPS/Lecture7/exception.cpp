#include<iostream>
using namespace std;

class Bank{
    string name;
    int balance;
    int acc_number;

    public:
    Bank(string name, int balance, int acc_number){
        this->name = name;
        this->balance = balance;
        this->acc_number = acc_number;
    }
    //void deposit
    void deposit(int amount){
        if(amount>0){
            balance+=amount;
            cout<<amount<<" rs is credited successfully";
        }
        else{
            throw "amount should be greater than 0\n";
        }
    }
    //withdraw
    void withdraw(int amount){
        if(amount >=0 && balance>=amount){
            balance -= amount;
            cout<<amount<<" rs is debited successfully";
        }
        else if(amount<0){
            throw "amount should be greater than 0\n";
        }
        else{
            throw "Insufficient balance\n";
        }
    }
};

int main(){
    Bank B1("Bhanu", 50000, 101);
    try{
        B1.deposit(100);
        B1.withdraw(7000);
    }
    catch(const char *e){
        cout<<"Exceptiion occured: "<<e;
    }
    return 0;
}


#include<iostream>
using namespace std;

int main(){
    try{
        int a, b;
        cin>>a>>b;
        if(b==0)    throw "We cannot divide a number by zero";
        cout<<a/b;
    }
    catch(const char *e)
    {
        cout<<"Exception occur: "<<e<<endl;
    }
    return 0;
}