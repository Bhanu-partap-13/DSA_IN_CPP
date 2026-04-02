//It is a special function that invoked at the team of object creattion.
#include<iostream>
using namespace std;

//1. Default constructor

// class Consumer{
//     public:
//     string name;
//     int age;
//     int id;
//     Consumer(){ //this is default constructor
//         cout<< "constructor called"<<endl;
//     }
// };

// int main(){
//     Consumer c1;
//     c1.name = "bhanu";
//     c1.age = 20;
//     c1.id = 123;
//     cout<<c1.name<<" "<<c1.age<<" "<<c1.id<<endl;
// }

//2. Parameterized constructor

// class Consumer{
//     public:
//     string name;
//     int age;
//     Consumer(string n, int a){
//         name = n;
//         age = a;
//     }
// };

// int main(){
//     Consumer C1("bhanu", 20);
//     cout<<C1.name<<" "<<C1.age<<endl;
// }

//3. Using this pointer in constructor - CONSTRUCTOR OVERLOADING

class Consumer{
    public:
    string name;
    int acc_balance;
    int id;
    int* roi;

    Consumer(){ //initialize and resource chahiye wo mujhe mijayega to me use constructor
        name = "bhanu";
        acc_balance = 1000;
        id = 123;
        roi = new int(10);
        cout<<" this is the main default contructor"<<" ";
        cout<<endl;
    }
    //We are using here this pointer because the code thinks and take the near value for all the vaiables. So, to avoid that we are using this to make sure that we are using the correct variables of the class.
    Consumer(int name, int acc_balance, int id){
        this->name = name;
        this->acc_balance = acc_balance;
        this->id = id;
    }

    Consumer(int name, int acc_balance){
        this->name = name;
        this->acc_balance = acc_balance;
    }
    // //Inline constructor - we have commented this beacuse we cannot amke two same constructors with same parameters.
    // inline Consumer(string a, int b, int c): name(a), acc_balance(b), id(c){ 
    //    }
    
    Consumer(Consumer &c){
        name = c.name;
        acc_balance = c.acc_balance;
        id = c.id;
    }

    void display(){
        cout<<name<<" "<< acc_balance <<" " <<id<< " " << endl;
    }
};

//copy constructor - It is used to create a new object as a copy of existing object.
int main() {
    Consumer c1(123, 1000, 1);
    Consumer c2(123, 1000);
    Consumer c3 = c2;   //copy constructor
    c3.display();
    c1.display();
    c2.display();
   // cout<<c1.name<<" "<<c1.acc_balance<<" "<<c1.id<<endl;
}

