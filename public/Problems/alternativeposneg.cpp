class Solution {
  public:
    void rearrange(vector<int> &arr) {
        // code here
        vector<int> pos, neg;
        
        for(int num : arr){
            if(num >= 0) pos.push_back(num);
            if(num < 0) neg.push_back(num);
        }
        int c = 0;
        for(int i=0; i<pos.size() || i< neg.size(); i++){
            if(i < pos.size()) arr[c++]=pos[i];
            if(i < neg.size()) arr[c++]=neg[i];
        }
    }
};