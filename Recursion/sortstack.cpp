// Sort a stack using recursion

#include <bits/stdc++.h>

using namespace std;

void insert(stack<int> &s, int temp)
{
	if(s.size()==0 or s.top() >= temp) // <= for decreasing order
	{
		s.push(temp);

		return;
	}

	int val = s.top();

	s.pop();

	insert(s,temp);

	s.push(val);
}

void sort(stack<int> &s)
{
	//Base case:
	if(s.size() == 1)
	{
		return;
	}

	//Hypo
	int temp = s.top();

	s.pop();

	sort(s);

	//Ind:

	insert(s,temp);
}

int main()
{
	int n;

	cin>>n;

	int arr[n] = {1,8,7,4,5};

	stack<int> s;

	for(int i=0; i<n; ++i)
		s.push(arr[i]);

	sort(s);

	while(s.size() != 0)
	{
		cout << s.top() << " ";

		s.pop();
	}


}