//Leetcode 37: Sudoku Solver using backtracking

#include <bits/stdc++.h>

using namespace std;

bool isValid(vector<vector<char>> &board, int row, int col, char c)
{
	for(int i=0; i<board.size(); i++)
	{
		if(board[row][i] == c) return false;

		if(board[i][col] == c) return false;

		//IMP logic to check 3x3 boxes

		if(board[3*(row/3) + i/3][3*(col/3) + i%3] == c) return false;
	}

	return true;
}

bool solve(vector<vector<char>> &board)
{
	//Finding empty cells:
	for(int i=0; i<board.size(); ++i)
	{
		for(int j=0; j<board.size(); ++j)
		{
			if(board[i][j] = '.')
			{
				for(char c = '1'; c<='9'; c++)
				{
					if(isValid(board, i, j, c) == true)
					{
						board[i][j] = c;

						if(solve(board) == true) return true;

						//Backtrack
						else board[i][j] = '.';
					}

				}
			//If none of chars from 1 to 9 were fixed, return false
			return false;
			}		
		}
	}
	return true; // If we dont get an empty cell above, means
	// we have a valid sudoku so return true
}

int main()
{
	return 0;
}