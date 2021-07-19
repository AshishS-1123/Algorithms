#include <bits/stdc++.h>

using namespace std;

int max_sum(vector<int> arr) {
	int n = arr.size();

	vector<int> cum_sum(n+1);
	cum_sum[0] = 0;
	int max_sum = INT_MIN;

	for(int i = 0; i < n; ++i) {
		cum_sum[i+1] = cum_sum[i] + arr[i];
	}

	for(int start = 0; start < n; ++start) {
		for(int end = start; end < n; ++end) {
			int curr_sum = cum_sum[end+1] - cum_sum[start];
			max_sum = max(max_sum, curr_sum);
		}
	}

	return max_sum;
}

int main() {
	int n;
	cin >> n;

	vector<int> arr(n);
	for(int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	cout << "Max Sum :: " << max_sum(arr) << "\n";

	return 0;
}