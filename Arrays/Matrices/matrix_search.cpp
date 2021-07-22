#include <bits/stdc++.h>

using namespace std;

// Problem: Search element in a matrix if it is given that the rows and columns are sorted in ascending order
void search(vector<vector<int>> arr, int key, int row, int col) {

  if(arr[row][col] == key) {
    cout << "Found at " << row << " " << col << "\n";
    return;
  }

  if(row >= arr.size()-1 || col < 0) {
    cout << "Not Found\n";
    return;
  }

  if(arr[row][col] < key) {
    search(arr, key, row+1, col);
  } else {
    search(arr, key, row, col-1);
  }
}

int main() {

  int n,m, key;
  cin >> n >> m >> key;

  vector<vector<int>> arr(n);
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < m; ++j) {
      int temp;
      cin >> temp;

      arr[i].push_back(temp);
    }
  }

  search(arr, key, 0, arr[0].size()-1);

  return 0;
}
