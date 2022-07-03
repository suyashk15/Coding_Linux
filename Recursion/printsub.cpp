#include <bits/stdc++.h>

using namespace std;

// Problem : Print all subsequences of an array

void printsub(int index, vector<int> &v, int arr[], int n)
{
	if(index >= n)
	{
		if(v.size() == 0) 
		{
			cout << "{}" <<"\n";
			return;
		}

		for(auto it : v)
		{
			cout << it << " ";
		}
		cout << "\n";

		return;
	}

	//Pick the element
	v.push_back(arr[index]);

	printsub(index+1, v, arr, n);

	v.pop_back();

	//Dont pick the element
	printsub(index+1, v, arr, n);

}

int main()
{
	int n;
	cin>>n;

	int arr[] = {3,1,2};

	vector<int> v;

	printsub(0, v, arr, n);
}