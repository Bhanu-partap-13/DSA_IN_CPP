#include<iostream>
using namespace std;

int main(){
    //In this code we will reverse the linked list, we will create a new linked list and copy the values of the old linked list to the new linked list in reverse order.
    class Node{
        public:
        int data;
        Node* next;
        Node(int data){
            this->data = data;
            next = nullptr;
        }
    };
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    
    Node* prev = NULL;
    Node* current = head;
    Node* future = NULL;
    
    while(current != NULL){
        future = current->next;
        current->next = prev;
        prev = current;
        current = future;
    }
    
    head = prev; // Update head to the new first node
    
    // Print the reversed linked list
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    return 0;

}