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

//Another example of exception handling
// #include<iostream>
// using namespace std;

// int main(){
//     try{
//         int a, b;
//         cin>>a>>b;
//         if(b==0)    throw "We cannot divide a number by zero";
//         cout<<a/b;
//     }
//     catch(const char *e)
//     {
//         cout<<"Exception occur: "<<e<<endl;
//     }
//     return 0;
// }

//if else or try main kya difference h
//allocation of memory


#include<iostream>
#include<exception>
using namespace std;

class exception{
    protected:
    string msg;
    public:
    exception(string msg) this-> msg = msg;
    string what(){
        return msg;
    }
};
int main(){
    //int *ptr = new int[1000000000000];
    // if(ptr == nullptr){
    //     cout<<"Memory allocation failed\n";
    // }
    // else{
    //     cout<<"Memory allocated successfully\n";
    // }
    // if we use if,and else then we will not be able to handle th exception..
    try{
        int *ptr = new int[1000000000000];
        throw "Memory allocation success\n";
        delete []ptr;
    }
    catch(const exception &e){
        cout<<"Exception occur due to line: "<<e.what()<<endl; 
    }
}