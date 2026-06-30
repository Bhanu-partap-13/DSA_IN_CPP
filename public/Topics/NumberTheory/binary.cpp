#include<iostream>
using namespace std;

int bin(int a, int b){
    if(b == 0) return 1;
    
    int ans = bin(a, b/2);
    ans = ans * ans;
    if(b % 2 == 1){
        ans *= a;
    }
    return ans;
}
int main(){
    int a, b;
    cin >> a >> b;

    cout << bin(a, b) << endl;
}