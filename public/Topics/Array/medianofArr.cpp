class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        vector<int> temp;
        int i=0, j=0;
        while(i<n && j<m){
            if(nums1[i] < nums2[j]){
                temp.push_back(nums1[i]);
                i++;
            }
            else{
                temp.push_back(nums2[j]);
                j++;
            }
        }
        while(i<n)  {temp.push_back(nums1[i]); i++;}
        while(j<m)  {temp.push_back(nums2[j]); j++;}
        
        int size = m+n;
        if(size%2==1) return temp[size/2];

    return (temp[size/2] + temp[(size/2) - 1])/2.0;
    }
};