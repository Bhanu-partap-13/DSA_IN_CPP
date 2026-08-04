class Solution {
public:
    bool count(vector<int>& res){
        for(int& i : res){
            if(i != 0){
                return false;
            }
        }
    return true;
    }
    vector<int> findAnagrams(string s, string p) {
        int n = p.size();
        vector<int> res(26, 0);

        for(char& i : p){
            res[i - 'a']++;
        }

        int i=0; int j = 0;
        int k = s.size();
        vector<int> ans;
        while(j < k){
            res[s[j] - 'a']--;
            if(j-i+1 == n){
                if(count(res)){
                    ans.push_back(i);
                }
                res[s[i] - 'a']++;
                i++;
            }
            j++;
        }
    return ans;
    }
};