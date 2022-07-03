#include <bits/stdc++.h>

using namespace std;

// Questions : Find sum of all elements of subtree for a node
// Count no. of even numbers in subtree of a node
// To achieve time comp. of N, we pre compute subtree sum, even count

const int N = 1e3+10;

vector<int> tree[N];

int subtree_sum[N];
int even_count[N];


void dfs(int vertex, int parent)
{
	for(int child : tree[vertex])
	{
		if(child == parent) continue;

		dfs(child, vertex);

		// Action before exiting the child (Upar aate hue)
		subtree_sum[vertex] += subtree_sum[child];
		even_count[vertex] += even_count[child];
	}

	subtree_sum[vertex] += vertex;

	if(vertex%2 == 0) even_count[vertex]++;
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

	for(int i=1; i<=n; i++)
	{
		cout<<"Node: "<<i<<'\n';
		cout<<"Sum of Subtree: "<<subtree_sum[i]<<" "<<"Even count: "<<even_count[i];
		cout<<'\n';
		cout<<'\n';
	}
}