// Combination sum II on leetcode
// New pattern of recursion used

#include<bits/stdc++.h>

using namespace std;

void combsum2(int index, vector<int> &v, int arr[], int n, int target)
{
	if(target==0)
	{
		for(auto i : v)
			cout << i << " ";
		cout << endl;

		return;
	}

	// New pattern

	for(int i=index; i<n; i++)
	{
		// To avoid duplicate sequences
		if(i>index and arr[i]==arr[i-1]) continue;

		if(arr[i] > target) break;

		v.push_back(arr[i]);

		combsum2(i+1, v, arr, n, target-arr[i]);

		v.pop_back();
	}
}

int main()
{
	int arr[] = {10,1,2,7,6,1,5};

	int target = 8;

	int n;

	cin >> n;

	vector<int> v;

	sort(arr, arr + n);

	combsum2(0,v,arr,n,target);

	return 0;
}