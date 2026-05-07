#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
     
void file() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void solve() {
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++) cin >> arr[i];

	sort(arr, arr + n);
	int maxm = min(n - 1, arr[n - 1]);

	map<int, int> hm;
	for(auto i: arr) hm[i]++;

	// for(auto i : hm) cout << i.first << " " << i.second << endl << endl; 

	map<int, int> hm2;

	int curr = maxm;
	while(curr >= 0) {
		while(maxm >= curr) {
			if(hm.find(curr) != hm.end()) {
				hm[curr]--;
				if(hm[curr] == 0) hm.erase(curr);
				hm2[curr] = curr;
				curr--;
				break;
			}
			auto it = hm.lower_bound(2 * curr + 1);
			if(it != hm.end()) {
				
				hm[it->first]--;
				if(hm[it->first] == 0) hm.erase(it->first);
				hm2[curr] = it->first;
				curr--;
				break;
			}
			int val = hm2[maxm];
			maxm--;
			hm[val]++;
		}
		// for(auto i : hm) {
			// cout << i.first << " D " << i.second << endl;
		// }
		if(maxm < curr) curr--;
	}

	// for(auto i : hm) cout << i.first << " " << i.second << '\n';

	cout << maxm + 1 << '\n';

}
     
int main() {
    file();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}