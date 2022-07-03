// Finding minimum spanning tree of a weighted undirected graph
// using Kruskal's algo
// Algo: Sort edges based on their weights
//		 Start inserting edges one by one and dont insert if 
//		 inserting that edge will result in a loop
//		 To detect if loop is created optimally, we use DSU's

#include <bits/stdc++.h>

using namespace std;

// Time complexity: O(logn)

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
	int n, m;
	cin>>n>>m;

	vector<pair<int, pair<int,int> >> edges;
	// wt, node1, node2

	for(int i=0; i<m; i++)
	{
		int u,v,wt;
		cin>>u>>v>>wt;

		edges.push_back({wt, {u,v}});
	}

	for(int i=1; i<=n; i++) make(i);

	// Sorting edges by weights

	sort(edges.begin(), edges.end());

	int total_weight = 0;

	for(auto &edge : edges)
	{
		int weight = edge.first;
		int n1 = edge.second.first;
		int n2 = edge.second.second;

		if(find(n1) == find(n2)) continue;

		Union(n1,n2);

		total_weight += weight;

		cout << n1 <<" "<< n2 << endl;
	}

	cout << total_weight;
}

//Input:
// 6 9 
// 5 4 9
// 1 4 1
// 5 1 4
// 4 3 5
// 4 2 3
// 1 2 2
// 3 2 3
// 3 6 8
// 2 6 7