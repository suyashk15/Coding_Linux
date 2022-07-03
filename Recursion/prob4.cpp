// Give the count of subsequences with sum k
// Remember the pattern

#include <bits/stdc++.h>

using namespace std;

int count(int index, int arr[], int n, int s, int sum)
{
	if(index == n)
	{
		// IMP
		if(s == sum) return 1;

		else return 0;
	}

	// pick
	s+= arr[index];

	int l = count(index+1, arr, n, s, sum);

	s-= arr[index];

	// not pick
	int r = count(index+1, arr, n, s, sum);

	return l+r;
}

int main()
{
	int arr[] = {1,2,1};

	int sum = 2;

	int n;

	cin >> n;

	cout << count(0,arr,n,0,sum);
}