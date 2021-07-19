#include <bits/stdc++.h>

using namespace std;

// select the smallest element in unsorted array and
// swap with smallest element at beginning of unsorted array
vector<int> selection_sort(vector<int> arr) {
	// i points to the first element of unsorted array.
	// j loops through the remaining points and compares with arr[i]
	// if arr[j] < arr[i] means it could be the smallest elements. so swap

	int n = arr.size();
	
	for(int i = 0; i < n-1; ++i) {
		for(int j = i+1; j < n; ++j) {
			if(arr[j] < arr[i]) {

				int temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
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

	arr = selection_sort(arr);

	for(auto item : arr) {
		cout << item << " ";
	}
	cout << "\n";

	return 0;
}