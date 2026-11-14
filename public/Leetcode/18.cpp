class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        if(n<4) return {};
        set<vector<int>> st;

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                set<long long> hashSet;
                for(int k=j+1; k<n; k++){
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    long long fourth = target - sum;

                    if(hashSet.find(fourth) != hashSet.end()){
                        vector<int> temp = {nums[i], nums[j], nums[k], int(fourth)};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                    hashSet.insert(nums[k]);
                }
            }
        }
    vector<vector<int>> res(st.begin(), st.end());
    return res;
    }
};

//better solution

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        //-2,-1,0,0,1,2
        for(int i=0; i<n; i++){
            if(i>0 && nums[i] == nums[i-1]) continue;

            for(int j= i+1; j<n; j++){
                if(j != i + 1 && nums[j] == nums[j-1]) continue;

                int k = j+1;
                int l = n-1;

                while(k < l){
                    long long sum = nums[i]; sum += nums[j]; sum += nums[k]; sum += nums[l];
                    
                    if(sum == target){
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        res.push_back(temp);
                        k++;
                        l--;
                        while(k < l && nums[k] == nums[k-1]) k++;
                        while(k < l && nums[l] == nums[l+1]) l--;
                    }
                    else if(sum < target) k++;
                    else l--;
                }
            }
        }
    return res;
    }
};

//T.C. = O(n^3)
//S.c. = O(no of quartz) only used for returning the answer