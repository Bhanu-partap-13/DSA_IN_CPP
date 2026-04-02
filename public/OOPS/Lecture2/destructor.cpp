#include<iostream>
using namespace std;

// class Solution {
//     public:
//     string name;
//     int* roi;

//     Solution(){
//         name= "bhanu";
//         roi = new int[10];
//         *roi = 10;
//         cout<<"constructor called\n";
//     }
//     // ek hi baar create hoga
//     ~Solution(){
//         delete roi;
//         cout<<"destructor called";
//     }
// };

// int main(){
//     Solution S1, S2, S3;
// }


class Solution {
    public:
    string name;
    int* roi;
    Solution(){
        name = "4";
        cout<<"constructor called for "<<name<<endl;
    }
    Solution(string name){
        this->name= name;
        cout<<name<<endl;
    }
    // asc order wise;

    ~Solution(){
        cout<<"destructor called for "<<name<<endl;
    }
    //reverse order
};

int main(){
    Solution S1("1"), S2("2"), S3("3");
    Solution* S4 = new Solution; // destructor will not be called for this object because it is created in heap memory and we have to delete it manually to call the destructor.
    delete S4; // destructor will be called for this object because we have deleted it manually
}