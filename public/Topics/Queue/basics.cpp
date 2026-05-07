#include<bits/stdc++.h>
using namespace std;

void display(queue<int> &q){
    int n = q.size();
    for(int i=0; i < n; i++){
        int x = q.front();
        cout<< x << " ";
        q.pop();
        q.push(x);
    }
    cout<< endl;
}

void reverse(queue<int> &q){
    stack<int> st;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        st.push(x);
    }
    while(!st.empty()){
        int x = st.top();
        st.pop();
        q.push(x);
    }

}
int main()  {
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    cout<< q.size() << endl;
    cout << q.front() << endl; //As in Queue we have FIFO concept , here we will get 10 as out
    cout << q.back() << endl;  //As in Queue we have FIFO concept, here we will get 50 as out
    display(q);
    q.pop(); //As in Queue we have FIFO concept, here we will pop 10 as out
    cout<< q.size() << endl;
    cout << q.front() << endl; //As in Queue we have FIFO concept, here we will get 20 as out
    cout << q.back() << endl;  //As in Queue we have FIFO concept, here we will get 50 as out
    reverse(q);
    display(q);
}

//insertion happens only at the back, pop from front.
// front - we can access front element of queue (like top element of stack)
// back - we can access back element of queue (like bottom element of stack)
// empty - to check whether queue size is zer0 or not
// underflow - if we try to pop from empty queue, it will give underflow error
// overflow - if we try ti push into a full queue, it will give overflow error

//array implementation of queue - 

//  arr[] = [1,2,3,4,5];
//  we will take front as 0, rear as 4, size as 5
// int size(){
//     return rear - front;
// }
// void pop(){
//     if(size()==0) return;
//     front++;
// }
    // void front(){
    //     if(size()==0) return;
    //     return arr[front];
    // }
    // void back(){
    //     if(size()==0) return;
    //     return arr[rear];
    // }
// void push(int x){
//     if(rear==size()-1) return;
//     rear++;
//     arr[rear] = x;
// }.
