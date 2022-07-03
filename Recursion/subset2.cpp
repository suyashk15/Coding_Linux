//Problem: Generate all subsets of given array without duplicate entries
#include <bits/stdc++.h>

using namespace std;

void printsub(int index, vector<int> &v, int arr[], int n)
{
	// No base condition here. We are priniting subsets of all sizes 
	for(auto i:v)
		cout << i << " ";
	cout << endl;

	// Remember this pattern of recursion:

	for(int i=index; i<n; i++)
	{
		//To avoid duplicates
		if(i != index and arr[i]==arr[i-1]) continue;

		v.push_back(arr[i]);

		printsub(index+1, v, arr, n);

		v.pop_back();
	}

}

int main()
{
	int n;
	cin>>n;

	int arr[] = {1,2,2};

	vector<int> v;

	sort(arr, arr+n);

	printsub(0, v, arr, n);
}