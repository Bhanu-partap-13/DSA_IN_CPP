#include<bits/stdc++.h>
using namespace std;

int main(){
    long long c;
    cin>>c;
    while(c--){
        long long sum = 0;
        long long n;
        cin>>n;
        vector<long long> arr(n);
        
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        for(long long i=0; i<n; i++){
            if(arr[i] == 1) continue;
            sum=(sum+arr[i])%676767677;
        }
        sum=(sum+(arr[n-1]==1))%676767677;
    cout<<sum;
    cout<<endl;
    }
}