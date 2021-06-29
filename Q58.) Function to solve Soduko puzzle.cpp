#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

/*

 Function to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.



*/



bool place(lli row,lli col,char c,vector<vector<char>>&board)
{
	for(lli i=0;i<9;i++)
	{
		if(board[row][i]==c)
			return false;
		if(board[i][col]==c)
			return false;

		if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c)
			return false;
	}
	return true;
}

bool sudoku(vector<vector<char>>&board)
{
	for(lli i=0;i<board.size();i++)
	{
		for(lli j=0;j<board[0].size();j++)
		{
			if(board[i][j]=='.')
			{
				for(char c='1';c<='9';c++)
				{
					if(place(i,j,c,board))
					{
						board[i][j]=c;

						if(sudoke(baord)==true)
							return true;
						else
							board[i][j]='.';
					}
				}
				return false;
			}
		}
	}
	return true;
}


void solveSudoku(vector<vector<char>>& board) {
        
        sudoku(board);          
    }
    