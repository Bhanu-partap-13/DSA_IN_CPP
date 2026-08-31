#include<bits/stdc++.h>
using namespace std;

int main(){
    priority_queue<int> maxHeap; // This is a max heap ye default main bnta h
    pq.push(10);
    pq.push(110);
    pq.push(180);
    pq.push(-180);
    cout << pq.top() << endl; // isme 180 ayega
    pq.pop(); // ab 180 ud jayega
    cout << pq.top() << endl; // ab 110 ayega
}