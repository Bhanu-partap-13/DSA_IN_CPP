#include<bits/stdc++.h>
using namespace std;

vector<int> primeFactor(int x){
    vector<int> factors;
    
    while(x % 2 == 0){
        factors.push_back(2);
        x/=2;
    }
    
    for(int i=3; i*i<=x; i++){
        while(x % i == 0){
            factors.push_back(i);
            x/=i;
        }
    }
    if(x > 1)  factors.push_back(x);
    return factors;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    for(int i=0; i<n;i++){
        cin>>arr[i];
    }
  
    for(int i=0; i<n; i++){
        vector<int> factors = primeFactor(arr[i]);
        cout<< arr[i]<<": ";
        for(int f : factors){
            cout << f << " "<<"X"<<" ";
        }
        cout<<1;
        cout << endl;
    }
    return 0;
}
