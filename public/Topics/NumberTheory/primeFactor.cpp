#include<bits/stdc++.h>
using namespace std;

int primeFactor(int x){
    if(x <= 1) return x;
    for(int i = 2; i * i <= x; i++){
        if(x % i == 0) return i;
    }
    return x;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    for(int i=0; i<n;i++){
        cin>>arr[i];
    }
    //we have to find the smallest prime factor
    //[2,3,4,6,7,8] -> [2,3,2,2,7,2]
    //so first if you donot know how to find the prime number you will not be able to do it..
    vector<int> ans(n);
    
    for(int i=0; i<n; i++){
        ans[i] = primeFactor(arr[i]);
    }
    
    for(int i=0; i<n; i++){
        cout<< ans[i]<<" "<<endl;
    }
    return 0;
}

//prime numbers
/*
suppose if num = 29;//we have to check the prime numebr
0 is prime no, 1 no, 2 yes
if(num <= 1) not a prime
int count = 0
for(int i=0;i<=n;i++){
    //first we will calculate na count
    if(n%i==0) count++;
}
    if count > 2 not a prime 
    else prime
    ok now back to the problem
*/