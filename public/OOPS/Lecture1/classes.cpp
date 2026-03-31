#include<iostream>
using namespace std;

// int main(){
//     string name;
//     int age, rollNo;
//     string grade;
//     //like we have to write it again and again so we will use calsses and objects
//     cout<<"MY NAME"<<endl;
//     cin>>name;
//     cout<<"MY AGE"<<endl;
//     cin>>age;
//     cout<<"MY ROLL NO"<<endl;
//     cin>>rollNo;
//     cout<<"MY GRADE"<<endl;
//     cin>>grade;
// }

// class Student{
//     public: // by default the access modifier is private in the class so we ahve to mention the public
//     string name;
//     int age;
//     int rollno;
//     string grade;
// };

// int main(){
//     Student s1;
//     s1.name = "Bhanu";
//     s1.age = 20;
//     s1.rollno = 101;
//     s1.grade = "A+";
//     cout<<"MY NAME "<<s1.name<<endl;
//     cout<<"MY AGE: "<<s1.age<<endl;
//     cout<<"MY ROLL NO "<<s1.rollno<<endl;
//     cout<<"MY GRADE "<<s1.grade<<endl;
// }

/* Now we will do like we have to take care for the data security*/
class Student{
    private:
    string name;
    int age;
    int rollno;
    string grade;
    public:
    void setName(string n)  { name = n; }
    void setAge(int a) { age =  a; }
    void setGrade(string g) { grade = g; }
    void setRollNo(int r) { rollno = r; }
};

int main()
{
    Student s1;
    s1.setName("Bhanu");
    s1.setAge(19);
    s1.setGrade("A+");
    s1.setRollNo(101);
}
