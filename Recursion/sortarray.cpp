// Sort an array completely using recursion

#include <bits/stdc++.h>

using namespace std;

void insert(vector<int> &v, int temp)
{
	//Base case:
	if(v.size()==0 or v[v.size()-1] <= temp)
	{
		v.push_back(temp);

		return;
	}

	//Hypo
	int val = v[v.size()-1];

	v.pop_back();

	insert(v,temp);

	//Ind
	v.push_back(val);
}

void sort(vector<int> &v)
{
	//Base case
	if(v.size() == 1) return;

	//Hypo
	int temp = v[v.size()-1]; //Last element;

	v.pop_back(); //Smaller input

	sort(v);

	//Induction
	insert(v,temp);
}

int main()
{
	int n;

	cin>>n;

	vector<int> v = {9,1,4,0,7};

	sort(v);

	for(auto i:v)
	{
		cout << i << " ";
	}
}