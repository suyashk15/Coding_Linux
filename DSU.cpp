#include <bits/stdc++.h>

using namespace std;

// Time complexity: Amortized O(alpha(n))
// Almost constant, doesnt go beyond 4

const int N = 1e5+10;

int parent[N];
int size[N];

void make(int v)
{
	parent[v] = v;
	size[v] = 1;
}

int find(int v)
{
	if(parent[v] == v) return v;

	// Using Path compression
	return parent[v] = find(parent[v]);
}

void Union(int a, int b)
{
	a = find(a);  // Find the parent
	b = find(b);

	if(a == b) return;  //They have same parent, hence they are in same set

	// Union by size (Minimizing depth of union tree)
	else
	{
		if(size[a] < size[b]) swap(a,b);

		parent[b] = a;  // Inserting smaller tree under big one

		size[a] += size[b];  // Size after union
	}
}

int main()
{
	// Example: Finding no. of distinct connected comp. using DSU
	int n, k;
	cin>>n>>k;

	for(int i=1; i<=n; i++)
	{
		make(i);
	}

	while(k--)
	{
		int u, v;
		cin>> u>> v;

		Union(u,v);
	}

	// Logic: No. of distinct roots = No. of connected comps

	connected_comps = 0;

	for(int i=1; i<=n; i++)
	{
		if(find(i) == i) connected_comps++;
	}


}