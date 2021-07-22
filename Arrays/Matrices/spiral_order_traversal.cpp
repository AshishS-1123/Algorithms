#include <bits/stdc++.h>

using namespace std;

void spiral_print(vector<vector<int>> arr, int st_1, int st_2) {
  int m = arr.size();
  int n = arr[0].size();

  if(st_1*2 > n || st_2*2 > m) {
    cout << "\nend\n";
    return;
  }

  for(int i = st_1; i < n-st_1; ++i) {
    cout << arr[st_2][i] << " ";
  }

  for(int i = st_2+1; i < m-st_2; ++i) {
    cout << arr[i][n-st_1-1] << " ";
  }

  if(st_1 >= n - st_1-1) {
    return;
  }
  if(st_2 >= m - st_2-1) {
    return;
  }

  for(int i = n-st_1-2; i >= st_1; --i) {
    cout << arr[m-st_2-1][i] << " ";
  }

  for(int i = m-st_2-2; i >= st_2+1; --i) {
    cout << arr[i][st_1] << " ";
  }

  spiral_print(arr, st_1+1, st_2+1);
}

int main() {
  int n,m;
  cin >> n >> m;

  vector<vector<int>> arr(n);

  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < m; ++j) {
      int temp;
      cin >> temp;

      arr[i].push_back(temp);
    }
  }

  spiral_print(arr, 0, 0);

  return 0;
}
