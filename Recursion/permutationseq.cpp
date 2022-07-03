// Leetcode 60: Permutation sequence
// Given n and k, return the kth permutation sequence

#include <bits/stdc++.h>

using namespace std;

string getperm(int n, int k)
{
	vector<int> numbers;

	int fact = 1;

	for(int i=1; i<n; i++)
	{
		numbers.push_back(i);

		fact = fact*i;
	}

	numbers.push_back(n);

	k = k-1; //Zero based indexing

	string ans = "";

	while(true)
	{
		ans = ans + to_string(numbers[k/fact]);

		numbers.erase(numbers.begin() + k/fact);

		if(numbers.size()==0) break;

		k = k%fact;

		fact = fact/numbers.size();
	}

	return ans;
}

int main()
{
 
    int n, k = 3;

    cin>>n;
 
    string kthsequence = getperm(n, k);
 
    cout << kthsequence << endl;
 
    return 0;
}