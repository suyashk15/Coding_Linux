// Problem: Combination sum
// Print all combinations that sum up to target. Can use one element 
// multiple times.

#include <bits/stdc++.h>

using namespace std;

void combsum(int index, vector<int> &v, int arr[], int n, int target)
{
	if(index == n)
	{
		if(target == 0)
		{
			for(auto i : v)
				cout << i << " ";
			
			cout << endl;
			return;
		}
		return;
	}

	// Pick the element

	if(arr[index] <= target)
	{
		v.push_back(arr[index]);

		target -= arr[index];

		combsum(index, v, arr, n, target);

		v.pop_back();

		target += arr[index];
	}

	// Not pick

	combsum(index+1, v, arr, n, target);
}

int main()
{
	int arr[] = {2,3,6,7};

	int target = 7;

	int n;

	cin >> n;

	vector<int> v;

	combsum(0,v,arr,n,target);
}