#include<bits/stdc++.h>
using namespace std;

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
///T.c O(m+n) S.c O(m+n)

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int size = m+n;

        int idx1 = size/2-1;
        int idx2 = size/2;
        int element1 = -1, element2 = -1;

        int i=0, j=0, k=0;
        while(i<n && j<m){
            if(nums1[i] < nums2[j]){
                if(k==idx1) element1 = nums1[i];
                if(k==idx2) element2 = nums1[i];
                i++;
            }
            else{
                if(k==idx1) element1 = nums2[j];
                if(k==idx2) element2 = nums2[j];
                j++;
            }
            k++;
        }
        while(i < n){
            if(k == idx1) element1 = nums1[i];
            if(k == idx2) element2 = nums1[i];
            i++;
            k++;
        }
        while(j < m){
            if(k == idx1) element1 = nums2[j];
            if(k == idx2) element2 = nums2[j];
            j++;
            k++;
        }
        if(size%2==1) return element2;
    
    return (element1+element2)/2.0;
    }
};
///T.c O(m+n) S.c O(1)