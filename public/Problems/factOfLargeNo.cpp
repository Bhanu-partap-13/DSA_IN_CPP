// Compute n! when the result does not fit in built-in integer types.
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> digits{1}; // Stored least-significant digit first.

	for (int factor = 2; factor <= n; ++factor) {
		int carry = 0;

		for (int& digit : digits) {
			int value = digit * factor + carry;
			digit = value % 10;
			carry = value / 10;
		}

		while (carry > 0) {
			digits.push_back(carry % 10);
			carry /= 10;
		}
	}

	for (auto it = digits.rbegin(); it != digits.rend(); ++it) {
		cout << *it;
	}
	cout << '\n';

	return 0;
}
