class Solution {
public: 
    void printSubsets(vector<int> nums,vector<int> an, vector<vector<int>> &ans, int idx){
       if(idx == nums.size()){
        ans.push_back(an);
        return;
       }
       printSubsets(nums, an, ans, idx+1);
       an.push_back(nums[idx]);
       printSubsets(nums, an, ans, idx+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> an;
        vector<vector<int>> ans;
        printSubsets(nums, an, ans, 0);
        return ans;
    }
};