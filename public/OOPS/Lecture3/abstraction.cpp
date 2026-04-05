#include<iostream>
using namespace std;

class Consumer{
    string name;
    int money;
    public:
    Consumer(string a, int b){
        name = a;
        money = b;
    }
    void deposit(int money){
        this->money += money;
    }
};
int main(){
    Consumer C1("bhanu", 1000);
    C1.deposit(500);
}