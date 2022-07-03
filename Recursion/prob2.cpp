// Que: Print all subsequences with sum k

#include <bits/stdc++.h>

using namespace std;

void printsub(int index, vector<int> &v, int arr[], int n, int s, int sum)
{
	//Base case:
	if(index == n)
	{
		if(s==sum)
		{
			for(auto it : v)
				cout << it <<" ";
			cout << endl;
		}
		return;
	}

	// Pick the element
	v.push_back(arr[index]);

	s+= arr[index];

	printsub(index+1, v, arr, n, s, sum);

	v.pop_back();

	s-= arr[index];

	// Dont pick the element
	printsub(index+1, v, arr, n, s, sum);

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