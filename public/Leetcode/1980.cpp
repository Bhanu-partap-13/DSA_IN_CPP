//cantor diagonal algorithm
//In this code we have given an string ar, in which there is same length  of binary strings only in 0 && 1
//Assume the input is: [10,01] so we have to find the string which is not present in the nums array, 
// so we can use the cantor algo. as it says that the new strign will not be present in the list,
//  as the list length is already infinite, so we usally do the pow of that string and then it is 2^n.

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string s(n, '0');
        for(int i=0;i<n;i++){
            s[i] = (nums[i][i] == '0') ? '1':'0';
        }
        return s;
    }
};