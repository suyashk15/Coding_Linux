// Que: Print any one subsequence with sum k
// Trick : Stop recursion in the first time we get the ans

#include <bits/stdc++.h>

using namespace std;

bool printsub(int index, vector<int> &v, int arr[], int n, int s, int sum)
{
	if(index == n)
	{
		if(s==sum)
		{
			for(auto it : v)
				cout << it << " ";
			cout << endl;

			return true;
		}

		return false;
	}

	// Pick the element

	v.push_back(arr[index]);

	s += arr[index];

	if(printsub(index+1, v, arr, n , s, sum)==true) return true;

	v.pop_back();

	s -= arr[index];

	// Dont pick

	if(printsub(index+1, v, arr, n, s, sum)==true) return true;

	return false;
}

int main()
{
	int arr[] = {1,2,1};

	int sum = 2;

	int n;

	cin >> n;

	vector<int> v;

	printsub(0,v,arr,n,0,sum);
}