#include<iostream>
using namespace std;

// class Human{
//     public:
//     string name;
//     int age, weight;
//     // protected: 
//     // string name;
//     // int age, weight;
// };



// class Student: public Human {
//     int rollNo, marks; // default ye private access modifier. nd hum isko bhi access nhi access kr skte
//     //protected wallah idhar bhi protected main show hoga and we cannot perform it into int main();

// };

// int main(){ 
//     Student S1;
//     S1.name = "BHanu";
//     cout << S1.name;
// }


class Human{
    string Religion, caste;
    public: // agar ye private hota tih hum isko age pass nhi kr skte  par agar hum isko protected main daalte toh run kar jata
    string name;
    int age, weight;
};

// class Student: private Human { // we can als use protected here
//     int rollNo, marks; // default ye private access modifier. nd hum isko bhi access nhi access kr skte
//     // wo public modiferes is class main, protected main show hoga and we cannot perform it into int main();
//     public:

//     void set(string n, int a, int w){
//         name = n;
//         age = a;
//         weight = w;
//     }
//     void display(){
//         cout<<name<<" "<<age<<" "<<weight<<" "; 
//     }
// };

class Student: private Human { // we can also use protected, private here only if the parent class has public
    int rollNo, marks; // default ye private access modifier. nd hum isko bhi access nhi access kr skte
    // wo public modiferes is class main, protected main show hoga and we cannot perform it into int main();
    public:

    Student(string name, int age, int weight, int rollNo, int marks){
        this->name = name;
        this->age = age;
        this->weight = weight;
        this->rollNo = rollNo;
        this->marks = marks;
    }
    void display(){
        cout<<  marks<<" "<<    age<<" "<<  weight<<" "<<   rollNo<<" "<<   marks<<" ";
    }
};

class Teacher : public Human{
    public:
    int salary, id;
};

int main(){ 
    Student S1("Bhanu", 23, 80, 23, 100);
    S1.display();
    Teacher B;
    B.name = "Partap Saab";
}