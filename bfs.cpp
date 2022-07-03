#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+10;
vector<int> tree[N];
bool visited[N];
int level[N];

void bfs(int source)
{
	queue<int> q;

	q.push(source);
	visited[source] = true;

	while(!q.empty())
	{
		int curr_vertex = q.front();
		q.pop();
		cout << curr_vertex << " ";

		for(int child : tree[curr_vertex])
		{
			if(visited[child] != true)
			{
				q.push(child);
				visited[child] = true;

				level[child] = level[curr_vertex] + 1;
			}
		}
	}

}

void dfs(int vertex, int parent)
{
	cout << vertex <<" ";

	for(int child : tree[vertex])
	{
		if(child == parent) continue;

		dfs(child, vertex);
	}
}

int main()
{
	int n;
	cin>>n;

	for (int i = 0; i < n-1; ++i)
	{
		int x,y;
		cin>>x>>y;

		tree[x].push_back(y);
		tree[y].push_back(x);
	}

	cout << "BFS Traversal: " <<'\n';

	bfs(1);

	cout << '\n';
	cout << '\n';

	cout << "DFS Traversal: " <<'\n';

	dfs(1,0);

}