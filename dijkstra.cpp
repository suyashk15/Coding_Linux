#include <bits/stdc++.h>

using namespace std;

// Shortest path in weighted graph
// Cant handle negative weights
// Single source shortest path
// Time complexity is O(V + ElogV)

const int N = 1e3+10;
const int inf = 1e9+10;

int visited[N];
vector<int> dist(N, inf);

typedef pair<int, int> pi;

vector<pair<int,int> > graph[N]; // Weighted graph requires pair

void dijkstra(int source)
{
	priority_queue<pi, vector<pi>, greater<pi>> minh;

	// We need to first process node with minimum distance.
	// Thus pair in min heap will be {weight, node}

	minh.push({0, source});

	dist[source] = 0;

	while(minh.size()>0)
	{
		auto node = minh.top();

		int v = node.second;
		
		//cout << v << " " << node.first << '\n';

		minh.pop();

		if(visited[v] == 1) continue;

		visited[v] = 1;

		for(auto child : graph[v])
		{
			int child_v = child.first;
			int weight  = child.second;

			if(dist[v] + weight < dist[child_v])
			{
				dist[child_v] = dist[v] + weight;

				minh.push({dist[child_v], child_v});
			}
		}
	}

}

int main()
{
	int n,m;

	cin>>n>>m;

	for(int i=0; i<m; i++)
	{
		int x,y,wt;
		cin>>x>>y>>wt;

		graph[x].push_back({y, wt});
	}

	dijkstra(1);

	// Printing distances:

	for(int i=1; i<=n; i++)
	{
		cout << "Min distance of " << i << " from 1 is " << dist[i] << endl;

	}
}