// #include<iostream>
// #include<vector>
// #include<climits>
// using namespace std;

// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int n = nums.size();
//         int maxi = INT_MIN;

//         for(int i=0; i<n; i++){
//             int sum  = 0;
//             for(int j=i; j<n; j++){
//                 sum += nums[j];
//                 maxi = max(sum , maxi);
//             }
//         }
//     return maxi;
//     }
// };

//but what if we want to return the subarray as well ?

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    vector<vector<int>> maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        int start = 0;
        int end = 0;
        int tempStart = 0;
        int sum = 0;

        for(int i=0; i<n; i++){
            if(sum < 0) {
                sum = 0;
                tempStart = i;
            }
            if(sum > maxi){
                maxi = sum;
                start = tempStart;
                end = i;
            }
            vector<int> ans;
            for(int i=start; i<=end; i++){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};
