class Solution {
  public:
    vector<vector<int>> getPairs(vector<int>& arr) {
        // code here
        
        set<pair<int, int>> st;
        
        for(int i=0; i<arr.size(); i++){
            for(int j=i+1; j<arr.size(); j++){
                if(i != j && arr[i] + arr[j] == 0){
                    st.insert({min(arr[i], arr[j]), max(arr[i], arr[j])});
                }
            }
        }
        vector<vector<int>> seen;
        for(auto p : st){
            seen.push_back({p.first, p.second});
        }
    return seen;
    }
};