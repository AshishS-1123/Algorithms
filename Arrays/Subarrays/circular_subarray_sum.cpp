#include <bits/stdc++.h>

using namespace std;

int circular_kadane(vector<int> arr) {
	// in case the max circular subarray sum is formed from a non wrapping subarray, normal kadane algo is used
	// this is done with no_wrap_sum and max_no_wrap_sum
	// for the wrapping case, we negate the array and use wrap_sum and max_wrap_sum
	// the rest is similiar to kadane, but after computing max_wrap_sum, add the sum of all elements to it
	
	int n = arr.size();

	int wrap_sum = 0;
	int max_wrap_sum = INT_MIN;

	int no_wrap_sum = 0;
	int max_no_wrap_sum = INT_MIN;

	int total = 0;

	for(int i = 0; i < n; ++i) {
		total += arr[i];
		no_wrap_sum += arr[i];
		wrap_sum -= arr[i];

		if(no_wrap_sum < 0) {
			no_wrap_sum = 0;
		}
		if(wrap_sum < 0) {
			wrap_sum = 0;
		}


		max_wrap_sum = max(max_wrap_sum, wrap_sum);
		max_no_wrap_sum = max(max_no_wrap_sum, no_wrap_sum);
	}

	max_wrap_sum = total + max_wrap_sum;

	return max(max_wrap_sum, max_no_wrap_sum);
}

int main() {
	int n;
	cin >> n;

	vector<int> arr(n);
	for(int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	cout << "Max Circular Sum using Kadane :: " << circular_kadane(arr) << "\n";

	return 0;
}