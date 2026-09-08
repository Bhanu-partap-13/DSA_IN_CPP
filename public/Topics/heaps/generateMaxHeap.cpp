#include<bits/stdc++.h>
using namespace std;

class MaxHeap {
    int idx;
    vector<int> arr;
    MaxHeap(){
        idx=1;
        for(int i=1; i<=50; i++){
            arr[i] = 0;
        }
    }
    int size(){
        return idx-1;
    }
    int top(){
        return arr[1];
    }
    void push(int x){
        arr[idx] = x;
        int i = idx;
        idx++;

        while(i > 1){
            int parent = i/2;
            if(arr[i] < arr[parent]){
                swap(arr[i], arr[parent]);
            }
        else break;
        i = parent;
        }
    }
    void pop(){
        idx--;
        arr[1] = arr[idx];
        int i = 1;

        while(true){
            int left = 2*i;
            int right = 2*i+1;

            if(left > idx - 1){
                break;
            }
            if(right > idx - 1){
                if(arr[i] < arr[left]){
                    swap(arr[i], arr[left]);
                    i = left;
                }
            }
            if(arr[left] > arr[right]){
                if(arr[i] < arr[left]){
                    swap(arr[i], arr[left]);
                    i = left;
                }
                else break;
            }
            else{
                if(arr[i] < arr[right]){
                    swap(arr[i], arr[right]);
                    i = right;
                }
                else break;
            }
        }
    }
    void display(){
        for(int i = 1; i < idx; i++){
            cout << arr[i] << " ";
        }
    }
};