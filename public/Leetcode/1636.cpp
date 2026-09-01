class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> mpp;

        for(int &i : nums){
            mpp[i]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for(auto idx : mpp){
            int ele = idx.first;
            int freq = idx.second;

            pq.push({freq, -ele});
        }
        vector<int> ans;

        while(!pq.empty()){
            int ele = -pq.top().second;
            int freq = pq.top().first;
            for(int i=0; i<freq; i++){
                ans.push_back(ele);
            }
            pq.pop();
        }
    return ans;
    }
};