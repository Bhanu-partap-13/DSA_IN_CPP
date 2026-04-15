// //first we will discuss about the function overloading

// #include<iostream>
// using namespace std;

// class Area{
//     public:
//     void area(int a){
//         cout<<"Area of Circle"<<3.14*a*a<<endl;
//     }
//     void area(int l, int b){
//         cout<<"Area of Rectangle"<<l*b<<endl;
//     }
// };

// int main(){
//     Area a1;
//     a1.area(5);
//     Area a2;
//     a2.area(5,6);
//     return 0;
// }

//Operator overloading

#include<iostream>
using namespace std;

class Complex{
    int real;
    int img;
    public:
    Complex(){

    };
    Complex(int real, int img){
        this->real = real;
        this->img = img;
    }
    void display(){
        cout<<real<<" + "<<img<<"i"<<endl;
    }
    Complex operator + (Complex &c){
        Complex temp;
         temp.real = real + c.real;
         temp.img = img + c.img;
         return temp;
    }
};

int main(){
    Complex C1(3,4);
    Complex C2(5,6);
    Complex C3 = C2 + C1;
    C3.display();
    return 0;
}