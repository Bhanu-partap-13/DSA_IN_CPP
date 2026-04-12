//q1
// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     int n;
//     cin >> n;
//     cout<<n<<"\n";
//     return 0;
// }

//q2
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    while(n--){
    int sum = 0;
    int x = 7;
    vector<int> arr(x);
    for(int i=0; i<x; i++){
        cin>> arr[i];
    }

    for(int i=0; i<x; i++){
        sort(arr.begin(), arr.end());
    }
    for(int i=0; i<x-1; i++){
        arr[i] = -arr[i];
    }
    for(int i=0; i<x; i++){
        sum+=arr[i];
        }
    cout << sum << endl;
    }
}

