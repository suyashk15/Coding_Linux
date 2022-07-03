//GfG : Rat in a Maze I
// Take rat from (0,0) to (n-1,n-1) in a nxn graph. Rat can move
// up,down,left and right. 0 represents forbidden cell. Print all moves
// in lexiographical order.

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> visited;

bool isValid(int x, int y, int n, vector<vector<int>> &a)
{
	if(x>=0 and y>=0 and x<n and y<n and !visited[x][y] and a[x][y]==1)
		return true;

	else return false;
}


void solve(int i, int j, int n, vector<vector<int>> &visited,
	vector<string> &ans, vector<vector<int>> &a, string move, int di[], int dj[])
{
	if(i==n-1 and j==n-1) 
	{
		ans.push_back(move);

		return;
	}

	string directions = "DLRU"; //down,left etc in lex order

	//Trying all 4 directions

	for(int index = 0; index<4; index++)
	{
		int nexti = i + di[index];

		int nextj = j + dj[index];

		if(isValid(nexti,nextj,n,a)==true)
		{
			visited[nexti][nextj] = 1; //Do

			solve(nexti, nextj, n, visited, ans, a, move+directions[index], di, dj);

			visited[nexti][nextj] = 0; //Backtrack
		}
	}
}


vector<string> findPath(vector<vector<int>> &m, int n)
{
	int di[4] = {1,0,0,-1};

	int dj[4] = {0,-1,1,0};

	vector<string> ans;

	string move = "";

	if(m[0][0] == 1) solve(0,0,n,visited,ans,m,move,di,dj);

	return ans;
}

int main()
{
	return 0;
}