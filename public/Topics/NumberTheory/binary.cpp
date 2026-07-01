#include<bits/stdc++.h>
using namespace std;

long long bin(int a, int b){
    if(b == 0) return 1;
    const long long MOD = 1e9 + 7;
    long long ans = bin(a, b/2);
    ans = (ans * ans) % MOD;
    if(b % 2 == 1){
        ans = (ans * a) % MOD;
    }
    return ans;
}
int main(){
    int a, b;
    cin >> a >> b;

    cout << bin(a, b) << endl;
}