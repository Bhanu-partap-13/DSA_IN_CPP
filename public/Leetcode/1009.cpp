//in this question we have to find the complement of a number in binary form and then convert it to decimal form

#include <bits/stdc++.h>
using namespace std;

int find(int n){
    if(n==0) return 1;
    int mask = 1;
    while(mask<=n){
        mask = mask<<1;
    }
    return (mask-1) ^ n;
}
int main(){
    int n=5;
    cout<<find(n);
    return 0;
}