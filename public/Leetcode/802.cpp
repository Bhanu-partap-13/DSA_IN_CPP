class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        //pehle ye krle agar size 0 chla gya toh return krdenge 0
        int n  = courses.size();
        if(n <= 0) return 0;
        // ab sort krenge is 2d array ko bhi jo, uska second element hoga ek part. index pe [1] wala toh usme wo smaller wala pehle aye and baad main greater wala aye
        sort(courses.begin(), courses.end(), [](
            const vector<int>& a, vector<int>& b
        ){
            return a[1] < b[1];
        });
        //ab priprity queue bnayenge
        priority_queue<int> pq;
        int sum = 0;
        for(auto &i : courses){
            sum += i[0];
            pq.push(i[0]);

            if(sum > i[1]){
                sum -= pq.top();
                pq.pop();
            }
        }
    return pq.size();
    }
};