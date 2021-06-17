#include <bits/stdc++.h>

using namespace std;

int binary_search(int* arr, int start, int end, int key)
{
    int mid = (int) (start + end) / 2;

    if(start > end)
        return -1;

    if(arr[mid] == key)
        return mid;
    else if(arr[mid] > key)
        return binary_search(arr, start, mid-1, key);
    else
        return binary_search(arr, mid+1, end, key);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    int n, key;
    cin >> n >> key;

    int arr[n];
    for(int i = 0; i < n; ++i)
        cin >> arr[i];

    cout << "Element found at :: " << binary_search(arr, 0, n, key) << "\n";

    return 0;
}

