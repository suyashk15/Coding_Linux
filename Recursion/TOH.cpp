// Tower of Hanoi Problem

#include <bits/stdc++.h>

using namespace std;

void printway(int source, int dest, int helper, int n)
{
	// Base case
	if(n==1)
	{
		cout << "Move disc " << n << " from " << source << " to " << dest <<'\n';

		return;
	}

	//Hypo
	printway(source, helper, dest, n-1);

	cout << "Move disc " << n << " from " << source << " to " << dest <<'\n';

	//Ind
	printway(helper, dest, source, n-1);

	return;
}

int main()
{
	int s = 1;

	int d = 3;

	int h = 2;

	int n;

	cin>>n;

	printway(s,d,h,n);
}