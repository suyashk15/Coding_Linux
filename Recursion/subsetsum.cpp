// Print the sum of all possible subsequences of an array

#include <bits/stdc++.h>

using namespace std;

void subsetsum(int index, vector<int> &v, int arr[], int n)
{
	if(index >= n)
	{
		int sum = 0;

		for(auto i : v)
			sum += i;

		cout << sum << endl;

		return;
	}

	//Pick
	v.push_back(arr[index]);

	subsetsum(index+1, v, arr, n);

	v.pop_back();

	//Not pick

	subsetsum(index+1, v, arr, n);
}

int main()
{
	int arr[] = {2,3};

	int n;

	cin >> n;

	vector<int> v;

	subsetsum(0,v,arr,n);
}