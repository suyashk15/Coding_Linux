//Optimal solution to N-queens problem using hashing and backtracking

#include <bits/stdc++.h>

using namespace std;

void solve(int col, vector<string> &board, vector<vector<string>> &ans,
	vector<int> &leftrow, vector<int> &upperDiagonal,vector<int> &lowerDiagonal,int n)
{
	//Base case
	if(col == n)
	{
		ans.push_back(board);

		return;
	}

	for(int row=0; row<n; row++)
	{
		// IMP check to avoid attacks
		if(leftrow[row]==0 && lowerDiagonal[row+col]==0
			&& upperDiagonal[n-1 + col-row]==0)
		{
			// Do:

			board[row][col] = 'Q';

			leftrow[row] = 1;

			lowerDiagonal[row+col] = 1;

			upperDiagonal[n-1 + col-row] = 1;

			solve(col+1, board, ans, leftrow, upperDiagonal, lowerDiagonal, n);

			//Backtrack:

			board[row][col] = '.';

			leftrow[row] = 0;

			lowerDiagonal[row+col] = 0;

			upperDiagonal[n-1 + col-row] = 0;
		}
	}
}

vector<vector<string>> solveNqueens(int n)
{
	vector<vector<string>> ans;

	vector<string> board(n);

	string s(n, '.');

	for(int i=0; i<n; i++) board[i] = s; //Making nxn board

	//Initializing hash arrays

	vector<int> leftrow(n,0);

	vector<int> upperDiagonal(2*n-1,0);

	vector<int> lowerDiagonal(2*n-1,0);

	//Solving:

	solve(0,board,ans,leftrow,upperDiagonal,lowerDiagonal,n);

	return ans;
}

int main()
{
	int n;

	cin>>n;

	vector<vector<string>> v = solveNqueens(n);

	for(auto i: v)
	{
		for(auto j : i)
		{
			cout << j << '\n';
		}
		cout << endl;
	}

	return 0;	
}


