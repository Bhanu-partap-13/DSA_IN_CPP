#include<bits/stdc++.h>
using namespace std;

class Queue{
    int f;
    int b;
    int arr[5];
    Queue(){
        f = 0;
        b = 0;
    }
    void push(int val){
        if(b==5){
            return;
        }
        arr[b] = val;
        b++;
    }
    int size(){
        return f-b;
    }
    void pop(){
        if(size() == 0) return;
        f++;
    }
    int back(){
        if(f-b == 0){
            return -1;
        }
        return arr[b-1];
    }
    int front(){
        if(size() == 0) return -1;
        return arr[f];
    }
    bool empty(){
        if(size() == 0) return true;
        else return false;
    }
    void display(){
        for(int i=f; i<b; i++){
            cout<<arr[i]<<" ";
                }
    }
};

int main(){

}