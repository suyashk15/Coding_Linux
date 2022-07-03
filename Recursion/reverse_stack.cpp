// Reverse a stack using recursion

#include <bits/stdc++.h>

using namespace std;

void insert(stack<int> &s, int temp)
{
	if(s.size()==0)
	{
		s.push(temp);

		return;
	}

	int val = s.top();

	s.pop();

	insert(s, temp);

	s.push(val);
}

void solve(stack<int> &s)
{
	if(s.size()==1) return;

	int temp = s.top();

	s.pop();

	solve(s);

	insert(s, temp);

	return;
}

int main()
{
	int n;

	cin>>n;

	int arr[n] = {1,8,7,4,5};

	stack<int> s;

	cout << "Original Stack:" << endl; 

	for(int i=0; i<n; ++i)
	{
		s.push(arr[i]);
		cout << arr[n-i-1] << " ";
	}

	cout << endl;

	solve(s);

	cout << "Reversed Stack:" << endl; 

	while(s.size() != 0)
	{
		cout << s.top() << " ";

		s.pop();
	}
}