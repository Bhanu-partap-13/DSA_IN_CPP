#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        long long coin;
        cin>>coin;
        vector<long long> costs(n);
        for(long long i=0; i<n; i++){
            long long arr;
            cin >> arr;
            costs[i] += arr + (i+1);
            
        }
        int count = 0;
      sort(costs.begin(), costs.end());
      for(int i=0; i<n; i++){
          if(coin >= costs[i]){
                coin -= costs[i];
                count++;
          }
          else{
              break;
          }
      }
        cout << count<<endl;
    }
    return 0;
}
