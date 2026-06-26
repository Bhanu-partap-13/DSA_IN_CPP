#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    while(n--){
        int l, r;
        cin>>l>>r;
        int lucky = l;
        int maxi = -1;
        int ans = 1;
        
        while(lucky <= r){
            int temp = lucky;
            int maxD = 0;
            int minD = 9;
            
            while(temp > 0){
                int digit = temp%10;
                maxD = max(maxD, digit);
                minD = min(minD, digit);
                temp = temp/10;
            }
            int l3 = maxD - minD;
            
            if(l3 >= maxi){
                maxi = l3;
                ans = lucky;
            }
            if(maxi == 9){
                break;
            }
            lucky++;
        }
    cout << ans << endl;
    }
    return 0;
}