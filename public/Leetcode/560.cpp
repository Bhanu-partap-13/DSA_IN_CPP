class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        for(int i=0;i<nums.size();i++){
            int sum = nums[i];
            if(sum == k) {
                count++;
            }
            for(int j=i+1;j<nums.size();j++){
                sum += nums[j];
                if(sum==k) count++;
            }
        }
    return count;
    }
};

// new code

// new code
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int result = 0;
        int cumSum = 0;
        unordered_map<int, int>mpp;
        //pehle hum store krenge kiyaar hmne kya isko pehle dekha h kya, 
        mpp.insert({0,1});
        int n = nums.size();
        
        for(int i=0; i<n; i++){
            cumSum += nums[i];
//            isme hum pehle sum check kr rhe h and fir usko map main toh store kr hi rh h, jis time wo map main hoga toh hme pta lgg jayega hmm bhi ye toh tha, jaise malo [1,4, 1,2,6] and  k h = 3, pehle hme dekhenge 1 -3 kya -2 h hmare pass nhi fir 4 ko, milaki 5 hogya, and jaise 8 pe ayenge dekhenge ki 8-3 == 5 yrr ye toh pehle aya tha, humm toh sahi h
            if(mpp.find(cumSum-k) != mpp.end()){
                result += mpp[cumSum-k];
            }
            //cummulative sum jo mila h sko update bhi krna h na
            mpp[cumSum]++;
        }
        //return krdenge result 
    return result;
    }
};