#include<iostream>
using namespace std;

// class Student{
//     public:
//     char c;
//     char d;
//     int l;
//     double db;
// };

// int main(){
//     Student s1;
//     cout<<sizeof(s1)<<endl;
//     return 0;
// }

//------------------------------------------------------------------------
//| c | d | x | x | l | l | l | l | db | db | db | db | db | db | db | db |
//------------------------------------------------------------------------
//Here x -> padding. It will take total 16 bytes.


class Student{
    public:
    char c;
    int l;
    char d;
    double db;
};

int main(){
    Student s1;
    cout<<sizeof(s1)<<endl;
    return 0;
}

//---------------------------------------------------------------------------------------
//| c | x | x | x | l | l | l | l | d | x | x | x | db | db | db | db |db | db | db | db |  
//---------------------------------------------------------------------------------------
//  Here x -> padding. It will take total 24 bytes.

// Like in the OS we have the concept of OS, where we are allocating the memory in the blocks of 4 bytes, 
// So here we are allocating the memory in the blocks of 8 bytes, so we are taking the padding to make the size of the class a multiple of 8 bytes. 
// So that is why we are taking the padding.
