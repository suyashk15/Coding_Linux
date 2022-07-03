#include <bits/stdc++.h>

using namespace std;

// Question: Codechef (Problem code: REVERSE)

// Concept: 0-1 BFS (Used in finding shortest path)

// Edges can have weights either 0 or 1.
// Deque is used instead of queue.
// If Edge weight is 0, it is pushed at the front of deque
// Visited array is not required. 

// In given question, we insert edges with weight 1 in reverse order
// of given edges and find shortest path from source node to
// destination.

const int N = 1e3+10;
const int inf = 1e9+10;

vector<pair<int,int> > graph[N];
vector<int> level(N, inf);
int n, m;

int bfs(int source)
{
	deque<int> q;

	q.push_back(source);

	level[source] = 0;

	while(!q.empty())
	{
		int curr_vertex = q.front();

		q.pop_front();

		for(auto child : graph[curr_vertex])
		{
			int node = child.first;   // child vertex
			int weight = child.second;

			// IMP shit
			// Analogous to visited array

			if(level[curr_vertex] + weight < level[node])
			{
				level[node] = level[curr_vertex] + weight;

				if(weight == 1) q.push_back(node);

				else q.push_front(node);
			}
		}					
	}

	return level[n] == inf ? -1 : level[n];
}

int main()
{
	cin>>n>>m;

	for(int i=0; i<m; i++)
	{
		int x,y;
		cin>>x>>y;

		if(x==y) continue; // To avoid self loops

		graph[x].push_back({y, 0});
		graph[y].push_back({x, 1});
	}

	cout << bfs(1);
}