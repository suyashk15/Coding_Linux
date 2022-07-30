#include <bits/stdc++.h>

using namespace std;

// Concept: Height and Depth of a tree using DFS

// Depth is calculated while going down the tree.
// Depth of a child = Depth[Parent] + 1
// Depth of root node is zero

// Height is calculated while coming up from leaf nodes
// Height of a node = max(Heights of all childs) + 1
// Height of all leaf nodes is zero

// Visited array is not req in trees, passing parent to 
// avoid infinite loop

const int N = 1e3+10;
vector<int> tree[N];
int height[N];
int depth[N];

void dfs(int vertex, int parent)
{
	for(int child : tree[vertex])
	{
		if(child == parent) continue;

		depth[child] = depth[vertex] + 1;

		dfs(child, vertex);

		height[vertex] = max(height[vertex], height[child]+1);
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

	dfs(1,0);

	for(int i=1; i<=n; i++)
	{
		cout<<"Node: "<<i<<'\n';
		cout<<"Height: "<<height[i]<<" "<<"Depth: "<<depth[i]<<endl;
	}

	//Printing
	// for(int i=1; i<=n; i++)
	// {
	// 	for(int child : tree[i])
	// 	{
	// 		if(child == i) continue;
	// 		cout << i << " "<<child<< " ";
	// 	}
	// 	cout<<'\n';
	// }

	return 0;
}