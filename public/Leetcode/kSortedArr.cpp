#include<bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {100,81,73,55,48,22,10};
    int k = 4;
    int n = sizeof(arr)/sizeof(arr[0]);

    priority_queue<int, vector<int>, greater<int>> pq;
    
    int idx = 0;
    for(int i=0; i<n; i++){
        pq.push(arr[i]);
        if(pq.size() > k){
            arr[idx++] = pq.top(); //idx++ isliye lgaya h taki pehle jab 0 toh agle iteration main 1 hojyega and soon.
            pq.pop();
        }
    }
    while(!pq.empty()){
        arr[idx++] = pq.top(); //same here
        pq.pop();
    }
    for(int i=0; i<n; i++){
        cout << arr[i] << endl;
    }
return 0;
}