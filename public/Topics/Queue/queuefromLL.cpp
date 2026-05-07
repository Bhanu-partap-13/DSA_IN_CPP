#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};
class Queue{
    public:
    int size;
    Node *head;
    Node *tail;
    Queue(){
        size = 0;
        head = tail = NULL;
    }
    void push(int val){
        Node* temp =  new Node(val);
        if(head == NULL){
            head = tail = temp;
        }
        else{
            tail->next = temp;
            tail = temp;
        }
    }
    void pop(){
        if(head == NULL) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    int front(){
        if(head == NULL) return -1;
        return head->data;
    }
    int back(){
        if(head == NULL) return -1;
        return tail->data;
    }
    void display(){
        Node* temp = head;
        while(!temp){
            cout<< temp->data << " ";
            temp = temp->next;
        }
        cout<< endl;
    }
};

int main(){
    Queue q;
    q.push(10);
    q.push(100);
    q.push(1000);
    q.push(10000);
    q.display();
}

//advantages: 1. Unlimited Size, Natural lik LL implementation, wastage of size
//dis ad: for each element we have val, node, so more space is required
