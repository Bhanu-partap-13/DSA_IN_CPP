#include<bits/stdc++.h>
using namespace std;

int rob(vector<int> arr, int low, int high){
    int prev=0;
    int prev2=0;
    if(arr.size()==1)return arr[0];
    for(int i=low;i<high;i++){
        int pick = arr[i]+prev2;
        int skip  = prev;
        int curr = max(pick, skip);
        prev2=prev;
        prev=curr;
    }
    return prev;
}
int house(vector<int> &nums){
    if(nums.size()==1)return nums[0];
    int ans1=rob(nums, 0, nums.size()-1);
    int ans2=rob(nums, 1, nums.size());
    return max(ans1, ans2);
}
int main(){
    vector<int> nums={1,2,3,1};
    cout<<house(nums);
    return 0;
}