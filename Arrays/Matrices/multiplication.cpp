#include <bits/stdc++.h>

using namespace std;

int main() {
  // Dimensions of first matrix: m x n
  // Dimensions of second matrix: n x p
  int m,n,p;
  cin >> m >> n >> p;

  int first[m][n];
  int second[n][p];

  cout << "Enter 1st Matrix\n";
  for(int i = 0; i < m; ++i) {
    for(int j = 0; j < n; ++j) {
      cin >> first[i][j];
    }
  }

  cout << "Enter 2nd Matrix\n";
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < p; ++j) {
      cin >> second[i][j];
    }
  }

  int ans[m][p];

  // loop for row of first mat
  for(int i = 0; i < m; ++i) {
    // loop for col of second mat
    for(int j = 0; j < p; ++j) {
      // loop to multiply elements
      ans[i][j] = 0;
      for(int k = 0; k < n; ++k) {
        ans[i][j] += first[i][k] * second[k][j];
      }
    }
  }

  cout << "Result\n";
  for(int i = 0; i < m; ++i) {
    for(int j = 0; j < p; ++j) {
      cout << ans[i][j] << " ";
    }
    cout << "\n";
  }
  return 0;
}
