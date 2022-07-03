// Flloyd - Warshall Algorithm
// All pair shortest path algo
// Handles negative weights but not negative cycles
// Based on Dynamic Programming
// Time complexity is O(n3)

#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+10;
const int inf = 1e9+10;

vector<pair<int,int> > graph[N];
int dist[N][N];

int main()
{
	// dist of i from i is 0

	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			if(i==j) dist[i][j] = 0;

			else dist[i][j] = inf;
		}
	}


	int n,m;
	cin>>n>>m;

	for(int i=0; i<m; i++)
	{
		int x,y,wt;
		cin>>x>>y>>wt;

		graph[x].push_back({y, wt});

		dist[x][y] = wt;
	}

	
	//Algorithm:

	for(int k=1; k<=n; k++)
	{
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=n; j++)
			{
				// If condition to handle negative weights
				if(dist[i][k] != inf and dist[k][j] != inf)
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

			}
		}
	}

	// Printing:

	for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=n; j++)
			{
				if(dist[i][j] == inf) cout << 'I' <<" ";

				else cout << dist[i][j] << " ";
			}
			cout << '\n';
		}


}

//earth fox require palm into vague cat possible income naive page brick