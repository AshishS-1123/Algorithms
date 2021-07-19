#include <bits/stdc++.h>

using namespace std;

void print_subarrays(vector<int> arr) {
	// start points to first index of subarray
	// end point to last index of subarray
	// in the third loop, print all elements between these indices
	int n = arr.size();

	for(int start = 0; start < n; ++start) {
		for(int end = start; end < n; ++end) {
			for(int i = start; i <= end; ++i) {
				cout << arr[i] << " ";
			}
			cout << "\n";
		}
	} 
}

int main() {
	int n;
	cin >> n;

	vector<int> arr(n);
	for(int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	print_subarrays(arr);

	return 0;
}