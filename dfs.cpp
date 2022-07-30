#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+10;
bool visited[N];
vector<int> g[N];

void dfs(int vertex)
{
	// Take action on the vertex after entering the vertex
	cout << vertex << '\n';
	visited[vertex] = true;

	for(int child : g[vertex])
	{
		// Take action on the child before entering child node 
		cout << "Parent: "<<vertex<<"child: "<<child<<'\n';
		if(visited[child]) continue;

		dfs(child);

		// Take action on the child before exiting child node
	}

	// Take action on the vertex before exiting the vertex
}

int main()
{
	int n,m;
	cin>>n>>m;

	for(int i=0; i<m; i++)
	{
		int v1,v2;
		cin>>v1>>v2;

		g[v1].push_back(v2);
		g[v2].push_back(v1);
	}

	dfs(1);
	return 0;
}
