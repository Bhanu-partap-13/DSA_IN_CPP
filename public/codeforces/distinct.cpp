#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        string s;
        cin >> s;
        
        vector<int> prefix(26,0);
        vector<int> suffix(26,0);
        int maxi = -1;
        int countS = 0;
        for(char c : s){
            if(suffix[c - 'a'] == 0){
                countS++;
            }
            suffix[c - 'a']++;
        }
        
        int countP = 0;
        
        for(int i=0; i<x-1; i++){
            char c = s[i];
            if(prefix[c - 'a'] == 0){
                countP++;
            }
            prefix[c - 'a']++;
            suffix[c - 'a']--;
            if(!suffix[c - 'a']){
                countS--;
            }
            maxi = max(maxi, countP + countS);
        }    
        cout << maxi << endl;
    }
        return 0;
}