class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // this question is similar as three sum where i ahve ti return the triplet in which their combine sum should be exact equal or nearly of the target and proceed
        int n = nums.size();
        if(n < 3) return {};
        sort(nums.begin(), nums.end());
        int closestSum = 1000000;

        for(int k=0; k<n-2; k++){
            int i = k+1;
            int j = n-1;
            //now we can do their sum
            while(i < j){
                int sum = nums[i] + nums[j] + nums[k];

                if(abs(target - sum) < abs(target - closestSum)) closestSum = sum;
                
                if(sum < target)i++;
                else j--;
            }
        }
    return closestSum;
    }
};