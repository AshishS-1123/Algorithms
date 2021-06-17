#include <bits/stdc++.h>

using namespace std;

int linear_search(vector<int> arr, int key)
{
    for(int i = 0; i < arr.size(); ++i)
    {
        if(arr[i] == key)
            return i;
    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
	
    int n, key;
    cin >> n >> key;

    vector<int> arr(n);
    for(int i = 0; i < n; ++i)
        cin >> arr[i];

    cout << "Element found at :: " << linear_search(arr, key) << "\n";

    return 0;
}

