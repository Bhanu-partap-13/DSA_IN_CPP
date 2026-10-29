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

//optimized
class Solution {
  public:
    vector<vector<int>> getPairs(vector<int>& arr) {
        vector<vector<int>> res;
        sort(arr.begin(), arr.end());

        int left = 0;
        int right = arr.size() - 1;

        while (left < right) {
            int sum = arr[left] + arr[right];

            if (sum == 0) {
                res.push_back({arr[left], arr[right]});

                while (left < right && arr[left] == arr[left + 1]) left++;
                while (left < right && arr[right] == arr[right - 1]) right--;

                left++;
                right--;
            } 
            else if (sum < 0) {
                left++;
            } 
            else {
                right--;
            }
        }
        return res;
    }
};
