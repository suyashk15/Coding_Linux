#include <bits/stdc++.h>

using namespace std;

// Concept: Edge Deletion type questions
// Question : Interviewbit Delete Edge!

// Algo : We precompute while coming up from dfs the total weights
//        of a subtree. Then for any edge deleted, we have one 
//        part as the value on one node, and other part is 
//        value on above node minus that value.

const int N = 1e3+10;
const int M = 1e9+7;

vector<int> tree[N];
int subtree_sum[N];
int weight[N];

void dfs(int vertex, int parent)
{
	subtree_sum[vertex] += weight[vertex];

	for(int child : tree[vertex])
	{
		if(child == parent) continue;

		dfs(child, vertex);

		subtree_sum[vertex] += subtree_sum[child];
	}
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

	dfs(1,0);

	long long prod = 0;

    //  Given cond. in que that 1 is always the root of the tree.
	// So we try to break all edges for other nodes

	for(int i=2; i<=n; i++)
	{
		int part_1 = subtree_sum[i];
		int part_2 = subtree_sum[1] - part_1;

		prod = max(prod, (part_1* 1LL * part_2)%M);

	}

	cout << prod;
}