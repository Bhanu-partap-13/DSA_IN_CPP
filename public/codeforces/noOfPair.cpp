#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n1;
    cin >> n1;
    while(n1--){
        int n,l,r;
        cin>>n>>l>>r;
        vector<int> arr(n);
        
        for(int i=0;i<n;i++){
            cin>> arr[i];
        }
        sort(arr.begin(), arr.end());
        
        int l1 = 0;
        int low = 0;
        ll ans1 = 0;
        ll ans2 = 0;
        int high = arr.size() - 1;
        while(low < high){
            if(arr[low] + arr[high] <= r){
                ans1 += high - low;
                low++;
            }
            else{
                high--;
            }
        }
        low = 0;
        high = n-1;
        while(low < high){
            if(arr[low] + arr[high] < l){
                ans2 += high - low;
                low++;
            }
            else{
                high--;
            }
        }
        ll ans = ans1 - ans2;
        cout << ans << endl;
    }
    return 0;
}