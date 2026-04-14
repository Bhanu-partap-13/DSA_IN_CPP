#include<iostream>
using namespace std;

class Engineer{
    public:
    string career;
    void work(){
        cout<<"Work hard and be a job creator";
    }
};

class YouTuber{
    public:
    string channel;
    void grow(){
        cout<<"Keep going and shining and make best content and impress others"<<endl;
    }
};

class Person: public Engineer, public YouTuber{
    public:
    string name;

    Person(string career, string channel,string name){
        this->career = career;
        this->channel = channel;
        this->name = name;
    }
    void display(){
        cout<<career<<" "<<channel<<" "<<name<<" "<<endl;
    }
};

int main(){
    
}