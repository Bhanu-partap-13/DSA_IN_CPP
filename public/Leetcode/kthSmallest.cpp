#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {10,20,-4,5,6,2,42,1,-7,56};
    int k = 4;
    int n = sizeof(arr)/4;
    priority_queue<int> pq;

    for(int i=0; i<n; i++){
        pq.push(arr[i]);
        if(pq.size() > k)pq.pop();
    }
    cout<<pq.top()<<endl;
}
