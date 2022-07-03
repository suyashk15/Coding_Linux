//Leetcode 131: Given string s print all palindrome partitions of s

#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string s, int start, int end)
{
	if(start == end) return true;

	while(start <= end)
	{
		if(s[start++] != s[end--]) return false;
	}

	return true;
}

void solve(int index, string s, vector<string> &v, int n)
{
	if(index == n)
	{
		for(auto i:v)
			cout << i << " ";
		
		cout << endl;

		return;
	}

	for(int i=index; i<n; i++)
	{
		if(isPalindrome(s, index, i) == true)
		{
			v.push_back(s.substr(index, i-index+1)); //Do

			solve(i+1, s, v, n); //Recur

			v.pop_back(); // Undo
		}
	}
}

int main()
{
	string s = "nitin";

	vector<string> v;

	int n;

	cin>>n;

	solve(0,s,v,n);
}