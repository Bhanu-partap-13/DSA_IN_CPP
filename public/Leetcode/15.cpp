class Solution {
public:
    vector<vector<int>> res;

    void twoSum(vector<int>& nums, int target, int i, int j){
        //here first we to use two pointer approach
        while(i < j){
            if(nums[i] + nums[j] > target) j--;
            else if(nums[i] +nums[j] < target) i++;
            else{
                while(i<j && nums[i] == nums[i+1])i++;
                while(i<j && nums[j] == nums[j-1]) j--;
                res.push_back({-target, nums[i], nums[j]});
                i++; j--;
            } 
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        //so we have given a vector where we have to check whether the triplets sum of the array is 0 and they hould not be duplicate
        int n = nums.size();
        if(n<3) return {}; // agar size hi 2 h toh triplets kaise ayenge
        sort(nums.begin(), nums.end());
        res.clear();
        for(int i=0; i<n-2; i++){
            // this loop is to fix the n1 and we have to also check if i==i-1
            if(i>0 && nums[i] == nums[i-1]){
                continue; // so we have to continue bcz we have no other option
            }
            int n1 = nums[i];
            int target = -n1;
            twoSum(nums, target, i+1, n-1);
        }
    return res;
    }
};