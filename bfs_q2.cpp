#include <bits/stdc++.h>

using namespace std;

// Concept: Finding shortest path in an unweighted graph using BFS
// Question: SPOJ - NAKANJ
// Find the min no. of moves for horse to reach dest from src
// From source, make a graph of all possible points on board
// and run a BFS
// Input ex: a1 h8

const int inf = 1e9+10;

int visited[8][8];
int level[8][8];

int getX(string s) // Get x-cord from string
{
	return s[0] - 'a';
}

int getY(string s)
{
	return s[1] - '1';
}

// Checks if movement lies whitin the chessboard
bool isValid(int x, int y)
{
	return x>=0 && y>=0 && x<8 && y<8;
}

// Vector of all possible moves
vector<pair<int,int> > movements =
{
	{-1,2} , {1,2} ,
	{-1,-2}, {1,-2},
	{2,-1} , {2,1} ,
	{-2,-1}, {-2,1},
};


int bfs(string src, string dest)
{
	int srcX = getX(src);
	int srcY = getY(src);

	int destX = getX(dest);
	int destY = getY(dest);

	//BFS starts:
	queue<pair<int,int> > q; //In matrix que, make queue of pair

	q.push({srcX, srcY});

	visited[srcX][srcY] = 1;
	level[srcX][srcY] = 0;

	while(!q.empty())
	{
		pair<int,int> v = q.front();

		q.pop();

		int x = v.first, y = v.second;

		for(auto movement : movements)
		{
			int childX = movement.first + x;

			int childY = movement.second + y;

			if(!isValid(childX, childY)) continue;

			if(!visited[childX][childY])
			{
				q.push({childX, childY});

				visited[childX][childY] = 1;

				level[childX][childY] = level[x][y] + 1;
			} 
		}
		//Optimization:
		if(level[destX][destY] != inf) break;
	}

	return level[destX][destY];
}

// As code runs for multiple test cases, reset visited and level
void reset()
{
	for(int i=0; i<8; i++)
	{
		for(int j=0; j<8; j++)
		{
			visited[i][j] = 0;
			level[i][j] = inf;
		}
	}
}

int main()
{
	int n;
	cin>>n;

	while(n--)
	{
		string s1, s2; // src and dest

		cin>>s1>>s2;

		reset();

		cout << bfs(s1,s2) <<'\n';
	}

	return 0;
}
