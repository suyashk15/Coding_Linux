//Leetcode 46: Permutations
// Print all possible permutations of an array

#include <bits/stdc++.h>

using namespace std;

void printperm(int index, vector<int> &arr, int n)
{
	if(index==n)
	{
		for(auto i:arr)
			cout << i << " ";
		cout << endl;

		return;
	}

	for(int i=index; i<n; i++)
	{
		swap(arr[index], arr[i]);  //Do

		printperm(index+1, arr, n);

		swap(arr[index], arr[i]);  //Undo

	}	
}

int main()
{
	int n;

	cin>>n;

	vector<int> arr = {1,2,3};

	printperm(0,arr,n);
}