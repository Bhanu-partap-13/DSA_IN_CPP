class Solution {
public:
    string removeDuplicates(string s) {
        string t = "";
        int n = s.size();
        int i = 0;

        while(i < n){
            if(t.empty() || s[i] != t.back()){
                t.push_back(s[i]);
            }
            else{
                t.pop_back();
            }
            i++;
        }
        return t;
    }
};