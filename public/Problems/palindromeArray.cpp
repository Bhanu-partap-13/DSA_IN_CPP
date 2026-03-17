//Q. In how many operations the given array will become palindrome.
#include<bits/stdc++.h>
using namespace std;

int main(){
    //I have to check the palindrome number in the array
    //1 3 5 2 2
    //so in this we are planning if the numbers are same then eq. we have to move both of them, wither the smaller one.
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n; i++){
        cin>>arr[i];
    }
    int low = 0;
    int count = 0;
    int high = n-1;
    while(low<high){
        if(arr[low] == arr[high]){
            low++;
            high--;
        }
        else if(arr[low] < arr[high]){
            arr[low+1] += arr[low];
            low++;
            count++;
        }
        else{
            arr[high-1] += arr[high];
            high--;
            count++;
            
        }
    }
    cout<<count;
    return 0;
}
//In this we have to print that palindrome array after removing all the duplicates.