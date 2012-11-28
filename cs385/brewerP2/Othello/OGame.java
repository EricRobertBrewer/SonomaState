package Othello;

// file: OGame.java
// CS 385 - Spring 2007 - Watts
// February 2007
// Written by Dr. Watts
// Modified by Eric Brewer
/*
Two player Othello game
This class holds, tests, and modifies the current game state
*/

import java.lang.*;
import java.awt.*;

class OGame
{
	int rows;		// holds number of rows in game
	int cols;		// holds number of columns in game
	int needed;		// holds number needed to win
	int grid [][];		// grid to hold game status - 0: not used, 1: Green, 2 : Purple
	int player = 1;		// current player - Green starts new game session
	int move = 0;		// number of moves made so far

	OGame (int R, int C, int N)
	{
		rows = R;
		cols = C;
		needed = N;
		grid = new int [rows+2][cols+2];	// space for playing and border of 0's
		player = 1;
		move = 0;
	}

	OGame (OGame Oth)
	{ // deep copy function
		rows = Oth.rows;
		cols = Oth.cols;
		needed = Oth.needed;
		grid = new int [rows+2][cols+2];
		for (int r = 1; r <= rows; r++)
			for (int c = 1; c <= cols; c++)
				grid [r][c] = Oth.grid [r][c];
		player = Oth.player;
		move = Oth.move;
	}

	public boolean equals (OGame Oth)
	{ // compares contents of game objects
		for (int r = 1; r <= rows; r++)
			for (int c = 1; c <= cols; c++)
				if (grid [r][c] != Oth.grid [r][c])
					return false;
		return true;
	}

	public String toString ()
	{ // prints a string of 'B', 'W', and '_' to illustrate current game state
		String string = "";
		String letter [] = {" ", "B", "W"};
		for (int r = 1; r <= rows; r++)
			for (int c = 1; c <= cols; c++)
				string += letter [grid[r][c]];
		return string;
	}

	boolean isNewGame ()
	{ // returns true if the game game has just started
		if (move == 0)
			return true;
		return false;
	}

	String getLetter (int r, int c)
	{ // returns letter corresponding to number in grid position (r,c)
		String letter [] = {" ", "B", "W"};
		return letter [grid[r][c]];
	}

	Color getColor (int r, int c)
	{ // returns color corresponding to number in grid position (r,c)
		Color color [] = {null, Color.black, Color.white};
		return color [grid[r][c]];
	}

	boolean moveOK (int r, int c)
	{ // returns true if grid position (r,c) is unused
		if( grid [r][c] == 0 )
			for( int i = -1; i < 2; i++ )
				for( int j = -1; j < 2; j++ ){
					int k = i;
					int l = j;
					while( grid[r+k][c+l] == 3-player ){
						k += i;
						l += j;
					}
					if( grid[r+k][c+l] == player && grid[r+i][c+j] == 3-player )
						return true;
				}

		return false;
	}

	void makeMove (int r, int c)
	{ // modifies game to reflect move at grid position (r,c)
		grid [r][c] = player;
		for( int i = -1; i < 2; i++ )
			for( int j = -1; j < 2; j++ ){
				int k = i;
				int l = j;
				while( grid[r+k][c+l] == 3-player ){
					k += i;
					l += j;
				}
				if( grid[r+k][c+l] == player && grid[r+i][c+j] == 3-player ){
					k -= i;
					l -= j;
					while( grid[r+k][c+l] == 3-player ){
						grid[r+k][c+l] = player;
						k -= i;
						l -= j;
					}
				}
			}
		move++;
		player = 3-player;
	}

	void compMove()
	{
		if( moveOK( 1, 1 ) ){
			makeMove( 1, 1 );
			return;
		}
		if( moveOK( rows, cols ) ){
			makeMove( rows, cols );
			return;
		}
		if( moveOK( rows, 1 ) ){
			makeMove( rows, 1 );
			return;
		}
		if( moveOK( 1, cols ) ){
			makeMove( 1, cols );
			return;
		}

		for( int i = 1; i < rows+1; i++ )
			if( moveOK( i, 1 ) ){
				makeMove( i, 1 );
				return;
			}
		for( int i = 1; i < cols+1; i++ )
			if( moveOK( 1, i ) ){
				makeMove( 1, i );
				return;
			}
		for( int i = rows; i > 0; i-- )
			if( moveOK( i, cols ) ){
				makeMove( i, cols );
				return;
			}
		for( int i = cols; i > 0; i-- )
			if( moveOK( rows, i ) ){
				makeMove( rows, i );
				return;
			}

		for( int i = 1; i < rows+1; i++ )
			for( int j = 1; j < cols+1; j++ )
				if( moveOK( i, j ) ){
					makeMove( i, j );
					return;
				}
	}

	void undoMove (int r, int c)
	{ // modifies game to reflect undo of move at grid position (r,c)
		grid [r][c] = 0;
		move--;
		player = 3 - player;
	}

	void reset ()
	{ // resets grid to initial state - does not reset player
		for (int r = 1; r <= rows; r++)
			for (int c = 1; c <= cols; c++)
				grid[r][c] = 0;
		move = 0;
	}

	int checkForWinner ()
	{ // when board is filled, tally pieces
		if( move == rows * cols ){
			int p1total = 0;
			int p2total = 0;
			for( int i = 0; i < rows; i++ )
				for( int j = 0; j < cols; j++ )
					if( grid[i][j] == 1 )
						p1total++;
					else
						p2total++;
			if( p1total > p2total )
				return 1;
			if( p1total < p2total )
				return 2;
			return 3;
		}
		return 0;
	}
}
