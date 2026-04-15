#include<iostream>
using namespace std;

class Human{
    protected:
    string name;
    int age;
    public:
    void work(){
        cout<<"I am working"<<endl;
    }

};

//human <- boy -> male
//human <- girl -> female

class Male{
    public:
    void display(){
        cout<<"I am a male"<<endl;
    }
};

class Female{
    public:
    void display(){
        cout<<"I am a female"<<endl;
    }
};

class Boy: public Human, public Male{
    public: 
    void display(){
        cout<< "I am a boy"<<endl;
    }
};

class Girl: public Human, public Female{
    public:
    void display(){
        cout<<"I am a Female"<<endl;
}
};

int main(){
    Boy b;
    Girl g;
    b.display();
    g.display();
    return 0;
}
