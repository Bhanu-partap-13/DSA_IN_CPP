//Dequeue - Double Ended queue - insertion and deletion from both ends at O(1)
// we will see the implementation using Doubly Linked List

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int data){
        this->data = data;
        next = prev = NULL;
    }
};
class Dequeue{
    public:
    Node* head;
    Node* tail; 
    int size;
    Dequeue(){
        head = tail = NULL;
        size = 0;
    }
    void pushFront(int data){
        Node* temp = new Node(data);
        if(!head){
            head = tail = temp;
        }
        else{
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        size++;
    }
    void pushBack(int data){
        Node* temp = new Node(data);
        if(!head) head = tail = temp;
        else{
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        size++;
    }
    void popFront(){
        Node* temp = head;
        if(!head){
            return;
        }
        else{
            head = head->next;
            delete temp;
        }
        size--;
    }
    void popBack(){
        Node* temp = tail;
        if(!tail){
            return;
        }
        else{
            tail = tail->prev;
            delete temp;
        }
        size--;
    }
    int front() {
        if(!head) return -1;
        return head->data;
    }
    int back() {
        if(!tail) return -1;
        return tail->data;
    }
};

int main(){
    Dequeue dq;
    dq.pushBack(10);
    dq.pushFront(100);
    dq.pushBack(20);
    dq.pushFront(200);
    dq.pushBack(30);
    dq.pushFront(300);
    dq.pushBack(40);
    dq.pushFront(400);
}