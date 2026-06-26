#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    while(n--){
        int c, q;
        cin>>c>>q;
        vector<int>arr(c);
        for(int i = 0; i < c; i++){
            cin >> arr[i];
        }
        sort(arr.rbegin(), arr.rend());
        int sum = 0;
        for(int i=0; i<c; i++){
            sum += arr[i];
        }
        vector<long long> prev(c);
        prev[0] = arr[0];
        for(int i = 1; i<prev.size(); i++){
            prev[i] = prev[i-1] + arr[i];
        }
        while(q--){
            long long x;
            cin >> x;
            if(prev[c-1] < x){
                cout<<-1<<endl;
                continue;
            }
        
            int left = 0;
            int right = c - 1;
            int ans = -1;
        
            while(left <= right){
                int mid = left + (right - left)/2;
                if(prev[mid] >=x){
                    ans = mid;
                    right = mid - 1;
                }
                else{
                    left = mid + 1;
                }
            }
            if(ans == -1)cout<<-1<<endl;
            else cout<<ans+1<<endl;
        }
    }
}