#include <bits/stdc++.h>

using namespace std;

//Question : Find no. of connected components in graph & print them

const int N = 1e3+10;
vector<int> g[N];
bool visited[N];

vector<vector<int>> connected_comp;
vector<int> current_cc;

void dfs(int vertex)
{
	visited[vertex] = true;
	current_cc.push_back(vertex);

	for(int child: g[vertex])
	{
		if(visited[child]) continue;

		dfs(child);
	}
}

int main()
{
	int n, m;
	cin>>n>>m;

	for(int i=0; i<m; i++)
	{
		int v1,v2;
		cin>>v1>>v2;

		g[v1].push_back(v2);
		g[v2].push_back(v1);
	}

	int count=0;

	for(int i=1; i<=n; i++)
	{
		if(visited[i] == true) continue;

		current_cc.clear(); //Contains all connected comp from a vertex
		dfs(i);
		connected_comp.push_back(current_cc);
		count++;
	}
	cout<<count<<endl;

	//Printing connected components
	for(int j=0; j<count; j++)
	{
		for(int k=0; k<connected_comp[j].size(); k++)
			cout << connected_comp[j][k] <<" ";
		
		cout << endl;
	}
	

	return 0;

}