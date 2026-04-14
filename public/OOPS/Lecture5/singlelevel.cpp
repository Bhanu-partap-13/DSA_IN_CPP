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
    ~Human(){
        cout<<"I am human class"<<endl;
    }
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
    ~Student(){
        cout<<" Getting deleted from the student class"<<" ";
    }
};

int main(){
    Student S1("Bhanu", 20, 23, 12);
    S1.work();
}

//Human wala constructor pehle call hoga and fir student wala kyunki wo uski child class h,
//Destructor pehle call hoga child wala, and fir call hoga parent wala.



//M2: Hum aisa bhi kr skte h

// #include<iostream>
// using namespace std;

// class Human{
//     protected:
//     string name;
//     int age;
//     public:
//     Human(string name,int age) {
//         this->name = name;
//         this->age = age;
//     }
// };

// class Student: public Human{
//     int rollNo, fees;
//     public:

//     Student(string name, int age, int rollNo, int fees): Human(name, age){
//         this->rollNo = rollNo;
//         this->fees = fees;
//     }
//     ~Student(){
//         cout<<" Getting deleted from the student class"<<" ";
//     }
     //   void display(){
    //         cout<<name<<" "<<age<<" "<<rollNo<<" "<<fees;
    //    }
// };

// int main(){
//     Student S1("Bhanu", 20, 23, 12);
// }

