class Solution {
  public:
    void swapSort(vector<int>& a, vector<int>& b, int i, int j){
        int m = a.size();
        int n = b.size();
        if(a[i] > b[j]){
            swap(a[i], b[j]);
        }
    }
    void mergeArrays(vector<int>& a, vector<int>& b) {
        // code here
        int m = a.size();
        int n = b.size();
        int len = m+n;
        
        int gap = (len/2) + (len%2);
        
        while(gap > 0){
        int i = 0;
        int j = i + gap;
            while(j < len){
                if(i<m && j>=m){
                 swapSort(a, b, i, j-m);   
                }
                else if(j<=m){
                 swapSort(a, a, i, j);   
                    
                }
                else{
                 swapSort(b, b, i-m, j-m);   
                }
                i++;j++;
            }
        if(gap==1) break;
        gap = (gap/2) + (gap%2);
        }
    }
};