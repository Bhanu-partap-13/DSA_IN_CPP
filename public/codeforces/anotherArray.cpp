#include<bits/stdc++.h>
using namespace std;

// typedef long long ll;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long>prime = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,71};
        long long ans = 1e9 + 7;
        for(int i=0; i<n; i++){
            int x;
            cin>>x;
            for(long long p : prime){
                if(x%p!=0){
                    ans = min(ans, p);
                    break;   
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}