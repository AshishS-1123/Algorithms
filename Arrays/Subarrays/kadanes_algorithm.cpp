#include <bits/stdc++.h>

using namespace std;

int kadane(vector<int> arr) {
	// in this algorithm, we calculate the cumulative sum as the O(n2) algo
	// but if for any element, the cum_sum becomes negative, we make it 0
	// after this has been done for all elements, then the max sum is the largest element in cum_sum
	int n = arr.size();

	int cum_sum = 0;
	int max_sum = INT_MIN;

	for(int i = 0; i < n; ++i) {
		cum_sum += arr[i];

		if(cum_sum < 0) {
			cum_sum = 0;
		} else {
			max_sum = max(max_sum, cum_sum);
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

	cout << "Max Sum Using Kadane's Algo :: " << kadane(arr) << "\n";

	return 0;
}