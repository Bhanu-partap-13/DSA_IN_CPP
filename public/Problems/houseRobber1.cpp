#include<bits/stdc++.h>
using namespace std;

int rov(vector<int> &nums){
    int prev1=0, prev2=0;
    for(int i=0;i<nums.size();i++){
        int pick = nums[i]+ prev2;
        int skip  =prev1;
        int curr = max(pick, skip);
        prev2=prev1;
        prev1=curr;

    }
    return prev1;
}
int main(){
    vector<int> nums={1,2,3,1};
    cout<<rov(nums);
    return 0;
}