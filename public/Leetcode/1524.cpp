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

//optimized method
class Solution {
public:
    int M = 1e9 + 7;
    int numOfSubarrays(vector<int>& arr) {
        //hmne ek prefix sum bnaliya jisme hum dekhenge pehle ke odd, even numbers
        int n = arr.size();
        vector<int> prefix(n, 0);
        prefix[0]= arr[0];

        for(int i=1; i<n; i++){
            prefix[i] = prefix[i-1] + arr[i];
        }
        int odd = 0, even = 1;
        int count = 0;

        for(int i=0; i<n; i++){
            if(prefix[i] % 2 == 0)// mtlb wo odd h
            {
                count = (count+odd)%M;
                even++;//agar even h toh odd add kro and vice versa
            }
            else{
                count = (count+even)%M;
                odd++;
            }
        }
    return count;
    }
};
