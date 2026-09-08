#include<iostream>
using namespace std;

void heapify(int i, int arr[], int n){
    while(true){ //jab tk koi statement nhi hogi break jaise toh ye chlta hi rhega
        int left = 2*i;
        int right = 2*i+1;
        
        if(left >= n) break;
        if( right >= n){
            if(arr[i] >  arr[left]){
                swap(arr[i], arr[left]);
                i = left;
            }
        
        }
        if(arr[left] < arr[right]){
             if(arr[i] > arr[left]){
                swap(arr[i], arr[left]);
                i = left;
                }
             else break;
            }
            else{
            if(arr[i] > arr[right]){
               swap(arr[i], arr[right]);
               i = right;
               }
            else break;
        }
    }   
}

void print(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[8] = {-7, 2, -3, 5, 8, 3, 1, 4};
    int n = sizeof(arr)/8;
    print(arr, n);

    for(int i= n/2; i>=0; i--){
        heapify(i, arr, n);
    }
    print(arr, n);
}