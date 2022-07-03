// GfG question: M-coloring problem
// Determine if a graph can be colored with atmost M colors such
// that no adjacent nodes have same colors

#include <bits/stdc++.h>

using namespace std;

bool isSafe(int node, int color[], int col, int N, bool graph[101][101])
{
	//Check for all adjacent nodes

	for(int i=0; i<N; i++)
	{
		if(i!=node and graph[i][node]==1 and color[i]==col)
			return false;
	}
	//graph[i][node] checks if there is an edge or not
}

bool solve(int node, int color[], int m, int N, bool graph[101][101])
{
	if(node == N) return true; 
	//If we reached node N, means we color every node

	// Check for every color
	for(int i=1; i<m; i++)
	{
		if(isSafe(node, color, i, N, graph) == true)
		{
			color[node] = i; //Do

			solve(node+1, color, m, N, graph); //Recur

			color[node] = 0; //Undo
		}
	}

	return false;
}

bool graphcolor(int m, int N, bool graph[101][101])
{
	int color[N] = {0};

	if(solve(0,color,m,N,graph) == true) return true;

	else return false;
}

int main()
{
	return 0;
}