class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int count = 0;

        for(int i=0; i<n; i++){
                int sum = 0;
            for(int j=i; j<n; j++){
                    sum += arr[j];
                if(sum%2!=0) count++;
            }
        }
    return count;
    }
};