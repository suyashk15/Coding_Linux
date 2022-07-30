#include <bits/stdc++.h>

using namespace std;

// Question: Detect Cycle in graph

const int N = 1e3+10;
bool visited[N];
vector<int> g[N];

bool dfs(int vertex, int parent)
{
	visited[vertex] = true;

	bool isLoopExists = false;

	for(int child : g[vertex])
	{
		if(visited[child]== true && child == parent) continue;

		if(visited[child]) return true;

		isLoopExists |= dfs(child, vertex);
	}

	return isLoopExists;
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

	bool isLoopExists = false;

	for(int i=1; i<=n; i++)
	{
		if(visited[i]==true) continue;

		if(dfs(i,0))
		{
			isLoopExists = true;
			break;
		}
		
	}

	cout << isLoopExists;
	return 0;
}
