#include <bits/stdc++.h>

using namespace std;

// repeatedly swap 2 elements if they are in wrong order
vector<int> bubble_sort(vector<int> arr) {
	// i counts the number of passes
	// j is used to denote 2 adjacent elements
	// in every iteration, the largest element bubbles to the last position
	// j only goes to n-i elements because the rest have been sorted

	int n = arr.size();

	for(int i = 1; i < n; ++i) {
		for(int j = 0; j < n-i; ++j) {
			if(arr[j+1] < arr[j]) {
				int temp = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = temp;
			}
		}
	}

	return arr;
}

int main() {

	int n;
	cin >> n;

	vector<int> arr(n);
	for(int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	arr = bubble_sort(arr);

	for(auto item : arr) {
		cout << item << " ";
	}
	cout << "\n";

	return 0;
}