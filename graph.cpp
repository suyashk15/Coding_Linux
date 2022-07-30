#include <iostream>
#include <bits/stdc++.h>

using namespace std;


const int N= 1e3+10;

vector<pair<int,int>> graph[N];  //Array of vectors

int main()
{
	//Creating the graph
	int n,m; //Vertices and edges
	cin>>n>>m;

	for(int i=0; i<m; i++)
	{
		int v1,v2,wt;
		cin>>v1>>v2>>wt;

		//Undirected graph
		graph[v1].push_back({v2,wt});
		graph[v2].push_back({v1,wt});
	}

	//Printing the graph
	for(int j=0; j<n; j++)
	{
		for(pair<int,int> child : graph[j])
			cout<< j <<" "<<child.first <<" "<<child.second<<'\n';
	}
	
	return 0;
}



