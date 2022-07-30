#include <bits/stdc++.h>

using namespace std;

// Concept: Diameter of a tree using DFS

// Diameter : Max path length b/w any two nodes of a tree

// Algo: 
// Run DFS twice
// Take any node as root and find the node at maximum
// depth wrt root.
// This node will be one end of the diameter (OP)
// Now taking this as the root, find node at max depth
// Sum of their paths is diameter

const int N = 1e3+10;
vector<int> tree[N];
int depth[N];

void dfs(int vertex, int parent=0)//Default value of parent is 0
{
	for(int child : tree[vertex])
	{
		if(child == parent) continue;

		// Action before entering a child (Neeche aate hue)
		depth[child] = depth[vertex] + 1;

		dfs(child, vertex);
	}
	
}

int main()
{
	int n; //Vertices
	cin>>n;

	//For a tree with n vertices, there are always n-1 edges thus m=n-1

	for(int i=0; i<n-1; i++)
	{
		int x,y;
		cin>>x>>y;

		tree[x].push_back(y);
		tree[y].push_back(x);
	}

	dfs(1); // Running DFS by taking any random node to find max_depth_node

	int max_depth = -1;
	int max_d_node;

	for(int i=1; i<=n; i++)
	{
		if(depth[i] > max_depth)
		{
			max_depth = depth[i];
			max_d_node = i;
		}

		depth[i] = 0; // Clearing depth array for running DFS again
	}

	dfs(max_d_node);

	max_depth = 0; //Resetting max depth for calculating diameter

	// Finding distance to max_depth, ie other end of diameter
	for(int i=1; i<=n; i++)
	{
		if(depth[i] > max_depth)
			max_depth = depth[i];
	}

	cout << max_depth << endl;
	return 0;
}