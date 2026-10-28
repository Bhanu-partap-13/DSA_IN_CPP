class Solution {
public:
    int leftRange(vector<int>& nums, int target){
        int n = nums.size();

        int left = 0;
        int right = n-1;
        int res = -1;
        while(left <= right){
            int mid = left + (right - left)/2;
            if(nums[mid] == target){
                res = mid;
                right = mid - 1;
            }
            else if(nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
    return res;
    }
    int rightRange(vector<int>& nums, int target){
        int n = nums.size();
        int left = 0;
        int right = n-1;
        int res = -1;
        while(left <= right){
            int mid = left + (right - left)/2;
            if(nums[mid] == target){
                res = mid;
                left = mid+1;
            }
            else if(nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
    return res;
    }
    vector<int> searchRange(vector<int>& nums, int target) {

        int n = nums.size();
        int left = leftRange(nums, target);
        int right = rightRange(nums, target);
        return {left, right};
    }
};
