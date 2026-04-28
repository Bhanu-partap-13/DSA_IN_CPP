#include<bits/stdc++.h>
using namespace std;

int main(){
    int c;
    cin>>c;
    while(c--){
       
        int n;
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        int count = 0;
        for(int i=0; i<n; i++){
            if(abs(arr[i] - arr[i+1])==1)count++;
        }
        cout<<count<<endl;
    }
}