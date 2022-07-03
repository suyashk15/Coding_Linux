// Delete middle element of given stack
// mid is defined as k = size/2 + 1

#include <bits/stdc++.h>

using namespace std;

void solve(stack<int> &s, int k)
{
	if(k==1) 
	{
		s.pop();
		return;
	}

	int temp = s.top();

	s.pop();

	solve(s,k-1);

	s.push(temp);

	return;
}

int main()
{
	int n; 

	cin>>n;

	int k = n/2+1;

	int arr[n] = {1,4,6,3,9};

	stack<int> s;

	for(int i=0; i<n; i++)
	{
		s.push(arr[n-i-1]);
	}

	solve(s,k);

	while(s.size() != 0)
	{
		cout << s.top() << " ";

		s.pop();
	}
}