#include <bits/stdc++.h>

using namespace std;

// Concept: Finding Lowest common Ancestor of any 2 nodes
// LCA is a common ancestor of 2 nodes at max depth

// Algo: Store the path of 2 nodes using dfs in 2 arrays
//       Travel through those arrays and find a point upto which
//       they have same elements. That is LCA

const int N = 1e3+10;
vector<int> tree[N];
int par[N];

void dfs(int vertex, int parent=-1)
{
	par[vertex] = parent; // Storing path as parents

	for(int child : tree[vertex])
	{
		if(child == parent) continue;

		dfs(child,vertex);
	}
}

vector<int> pathfinder(int vertex)
{
	vector<int> ans;

	while(vertex != -1)
	{
		ans.push_back(vertex);

		vertex = par[vertex];	
	}

	reverse(ans.begin(), ans.end()); // Will be stored in opp order

	return ans;
}

int main()
{
	int n;
	cin>>n;

	for(int i=0; i<n-1; i++)
	{
		int x,y;
		cin>>x>>y;

		tree[x].push_back(y);
		tree[y].push_back(x);
	}

	//Nodes whose LCA is to be found:

	int node1, node2;
	cin>>node1>>node2;

	dfs(1);

	vector<int> p1 =  pathfinder(node1);

	vector<int> p2 =  pathfinder(node2);

	int min_size = min(p1.size(), p2.size());

	int lca = -1;

	for (int i = 0; i < min_size; ++i)
	{
		if(p1[i] == p2[i]) lca = p1[i];

		else break;
	}

	cout<< lca;
}