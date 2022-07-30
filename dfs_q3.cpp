#include <bits/stdc++.h>

using namespace std;

// Question: Flood-fill (Leetcode 733)
// Key Points:
// For matrix type of questions, call dfs 4/8 times changing i,j
// No need of loop
// Find all edgecases and return them at the start

const int N = 1e3+10;
vector<vector<int>> graph[N];

// DFS for matrix inputs:

void dfs(int i, int j, int initailColor, int newColor, vector<vector<int>> &img)
{
	int n = img.size();     // Rows
	int m = img[0].size(); // Cols

	// Removing all edge-cases in the begining

	if(i<0 || i>=n) return;
	if(j<0 || j>=m) return;
	if(img[i][j] != initailColor) return; // Analogous to visited arr condition

	img[i][j] = newColor; //Analogous to marking visited, so dfs wont be called here 

	dfs(i, j+1, initailColor, newColor, img);
	dfs(i, j-1, initailColor, newColor, img);
	dfs(i-1, j, initailColor, newColor, img);
	dfs(i+1, j, initailColor, newColor, img);

}

vector<vector<int>> floodfill(vector<vector<int>> &img, int sr, int sc, int newColor)
{
	int initailColor = img[sr][sc];

	if(initailColor != newColor)
		dfs(sr, sc, initailColor, newColor, img);

	return img;
}

int main()
{
	int n,m;

	cin>>n>>m;

	for(int i=0; i<m; i++)
	{
		int x,y;
		cin>>x>>y;

		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	int newColor = 2;
	int sr = 0;
	int sc = 0;

	floodfill(graph, sr, sc, newColor);
}

