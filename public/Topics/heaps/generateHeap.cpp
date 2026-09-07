#include<bits/stdc++.h>
using namespace std;

class MinHeap{
    public:
//    vector<int> mini(60); //ye hum nhi likh skte
    int arr[50];
    int idx;
    MinHeap(){
        idx = 1;
    }
    //now we will write the top method
    int top(){
        return arr[1];
    }
    void push(int x){
        arr[idx] = x;
        int i = idx; //i se hum swap krenge
        idx++;
        //swapping till i==1
        while(i > 1){
            int parent = i/2;
            if(arr[i] < arr[i/2])
                swap(arr[i], arr[i/2]);
            else break;
            i = parent;
        }
    }
    void pop() {
        idx--;
        arr[1] = arr[idx];
        int i = 1;

        while(true){ //jab tk koi statement nhi hogi break jaise toh ye chlta hi rhega
        int left = 2*i;
        int right = 2*i+1;
        
        if(arr[left] < arr[right]){
             if(arr[i] > arr[left]){
                swap(arr[i], arr[left]);
                i = left;
                }
             else{
                break;
             }
            }
            else{
            if(arr[i] > arr[left]){
               swap(arr[i], arr[left]);
               i = left;
               }
            else{
               break;
            }
        }
        }
    }
    int size(){
        return idx - 1;
    }

};

int main(){
    MinHeap h;
    h.push(4);
    h.push(7);
    h.push(10);
    h.push(20);
    h.push(40);
    h.push(12);
    cout<<h.top()<<endl;
    cout<<h.size()<<endl;
} 