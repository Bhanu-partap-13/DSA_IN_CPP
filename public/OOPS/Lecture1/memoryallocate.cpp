//static and dynamic memory 

#include<iostream>
using namespace std;

class Student{
    public:
    int age;
    string name;
    string grade;
    int rollno;
};

int main(){
    Student *s1 = new Student;
    s1->age = 20;
    s1->name = "bhanu";
    s1->grade = "A+";
    s1->rollno = 123;
    //OR
    (*s1).age = 20;
    (*s1).name = "bhanu";
    (*s1).grade = "A+";
    (*s1).rollno = 123;

    cout<<s1->age<<" "<<s1->name<<" "<<s1->grade<<" "<<s1->rollno<<endl;
}
