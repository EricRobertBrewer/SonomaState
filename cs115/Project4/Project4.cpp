/*
Eric Brewer
12/11/08
Rivoire - CS 115
Project 4 - Tapatan
  Plays the board game Tapatan. It's a tic-tac-toe
  variant in which players take turns placing three
  pieces each onto a three-by-three board. After 
  their pieces are placed, they take turns moving
  pieces to adjacent squares attempting to create
  a line vertically, horizontally, or diagonally.
  Players can only make diagonal move on the main
  diagonal.

*/

#include <iostream>
#include <cmath>  // Only used for the absolute value function.

using namespace std;

const int PIECES_PER_PLAYER = 3;  // Could theoretically be changed.
const int DIM = 3;  // Number of dimensions on the square board.
const int NUM_PLAYERS = 2;  // Shouldn't be changed - code is meant for two players only.
const char PLAYER_SYMBOLS[NUM_PLAYERS] = {'X', 'O'};  // Players get to be X or O.

bool CheckArgs(int num_args);
void InitBoard(char board[][DIM]);
void DisplayBoard(char board[][DIM]);
void Toggle(int& count);
void PlacementPhase(char board[][DIM], char* player[]);
bool WinnerCheck(char board[][DIM], char symbol);
void MovementPhase(char board[][DIM], char symbol, char* name);

int main(int argc, char* argv[]){
  if (!CheckArgs(argc))
    return 0;
  char board[DIM][DIM];
  InitBoard(board);
  char* player[NUM_PLAYERS] = {argv[1], argv[2]};
  cout << player[0] << ", you will be " << PLAYER_SYMBOLS[0] << ".\n"
       << player[1] << ", you will be " << PLAYER_SYMBOLS[1] << ".\n";
  PlacementPhase(board, player);
  
  bool winner = false;
  bool p1WinsInPlacement = false;
  bool p2WinsInPlacement = false;
  p1WinsInPlacement = WinnerCheck(board, PLAYER_SYMBOLS[0]);  // Checks the odd case in which a
  p2WinsInPlacement = WinnerCheck(board, PLAYER_SYMBOLS[1]);  //  player wins during tic-tac-toe.
  if (p1WinsInPlacement || p2WinsInPlacement)
    winner = true;
  
  int turn = 0;  // Keeps track of whose turn it is - used in many places.
  while (!winner) {
    MovementPhase(board, PLAYER_SYMBOLS[turn], player[turn]);
    winner = WinnerCheck(board, PLAYER_SYMBOLS[turn]);
    if (!winner)
      Toggle(turn);
  }

  // After the main loop is closed, announces the winner and possibly how he/she won.
  DisplayBoard(board);
  if (p1WinsInPlacement)
    cout << player[0] << " wins in the placement phase!\n";
  if (p2WinsInPlacement)
    cout << player[1] << " wins in the placement phase!\n";
  if (p1WinsInPlacement && p2WinsInPlacement)
    cout << "Both " << player[0] << " and " << player[1] << " win in the placement phase!\n";
  else
    cout << player[turn] << " wins!!\n";

  return 0;
}

// Returns true if there aren't any problems with the command line.
bool CheckArgs(int num_args){
  if (num_args < (NUM_PLAYERS + 1)){
    cout << "Too few command line arguments. Exiting.\n";
    return false;
  }
  if (num_args > (NUM_PLAYERS + 1)){
    cout << "Too many command line arguments. Exiting.\n";
    return false;
  }
  return true;
}

// Initializes a board of dimensions DIM*DIM to all hyphens.
void InitBoard(char board[][DIM]){
  for (int i = 0; i < DIM; i++){
    for (int j = 0; j < DIM; j++){
      board[i][j] = '-';
    }
  }
}

// Creates a visual for the array that stores the board spaces.
// This particular function can't be used for a board of any size, unfortunately.
void DisplayBoard(char board[][DIM]){
  cout << "\n-------------\n"
       << "| " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << " |\n"
       << "| " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " |\n"
       << "| " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " |\n"
       << "-------------\n";
}

// Only zero or one may be passed to this function.
// This function changes zero to one OR one to zero.
void Toggle(int& count){
  count--;
  count = fabs(count);
}

// Iterates enough times to place every piece on the board.
// Checks for invalid input, an invalid square, or an occupied square.
void PlacementPhase(char board[][DIM], char* player[]){
  int turn = 0;
  for (int i = 0; i < (NUM_PLAYERS * PIECES_PER_PLAYER); i++){
    bool errors;
    int row;
    int column;
    do {
      errors = true;
      DisplayBoard(board);
      cout << player[turn] << ", place your piece.\n"
	   << "Enter row number followed by column number.\n";
      cin >> row >> column;	
      if (!cin.fail()){
	if (row > 0 && row <= DIM && column > 0 && column <= DIM){
	  if (board[row-1][column-1] == '-'){
	    errors = false;
	  }
	  else
	    cout << "That space is already taken.\n";
	}
	else
	  cout << "Not a square on the board.\n";
      }
      else {
	cout << "Invalid input.\n";
	cin.clear();
	cin.ignore(250, '\n');
      }
    } while(errors);
    
    board[row-1][column-1] = PLAYER_SYMBOLS[turn];
    Toggle(turn);
  }
}

// Returns true if someone actually manages to win this crazy game.
// Checks rows and columns separately via nested for-loops.
// Solid checks for both diagonal wins.
bool WinnerCheck(char board[][DIM], char symbol){
  for (int i = 0; i < DIM; i++){
    bool rowWin = true;
    for (int j = 0; j < DIM; j++){
      if (board[i][j] != symbol)
	rowWin = false;
    }
    if (rowWin)
      return true;
  }
  for (int i = 0; i < DIM; i++){
    bool columnWin = true;
    for (int j = 0; j < DIM; j++){
      if (board[j][i] != symbol)
	columnWin = false;
    }
    if (columnWin)
      return true;
  }
  bool diagWin = true;
  for (int i = 0; i < DIM; i++){
    if (board[i][i] != symbol)
      diagWin = false;
  }
  if (diagWin)
    return true;
  bool diagWin2 = true;
  for (int i = 0; i < DIM; i++){
    if (board[i][DIM-1-i] != symbol)
      diagWin2 = false;
  }
  if (diagWin2)
    return true;

  return false;
}

// The big one and the one that happens most often.
// Checks for invalid input, invalid squares, non-adjacent attempts,
//   squares that don't belong to the current player, squares
//   that are blank, squares that are blocked, and the most confusing,
//   diagonal moves that aren't across the main diagonal.
// Entering the same square as the source and destination is caught
//   by the line that cathches occupied square move attempts.
void MovementPhase(char board[][DIM], char symbol, char* name){
  bool errors = true;
  int rowStart = 0;
  int columnStart = 0;
  int rowEnd = 0;
  int columnEnd = 0;
  do {
    errors = true;
    rowStart = 0;
    columnStart = 0;
    rowEnd = 0;
    columnEnd = 0;
    DisplayBoard(board);
    cout << name << ", which piece would you like to move?\n"
	 << "Enter row number followed by column number.\n";
    cin >> rowStart >> columnStart;
    cout << "To where?\n"
	 << "Enter row number followed by column number.\n";
    cin >> rowEnd >> columnEnd;
    if (!cin.fail()){
      if (rowStart > 0 && rowStart <= DIM && columnStart > 0 && columnStart <= DIM){
	if (rowEnd > 0 && rowEnd <= DIM && columnEnd > 0 && columnEnd <= DIM){
	  if (fabs(rowStart - rowEnd) <= 1 && fabs(columnStart - columnEnd) <= 1){
	    if (board[rowStart-1][columnStart-1] == symbol){
	      if (board[rowEnd-1][columnEnd-1] == '-'){
	        if (fabs(rowStart - rowEnd) == 1 && fabs(columnStart - columnEnd) == 1){
	          if (rowEnd == columnEnd || ((rowEnd - 1) + (columnEnd - 1)) == (DIM - 1)){
	            errors = false;
	          }
	          else
	            cout << "Illegal diagonal move.\n";
	        }
	        else
	          errors = false;
	      }
	      else
		cout << "That space is already taken.\n";
	    }
	    else
	      cout << "You don't have a piece there.\n";
	  }
	  else
	    cout << "You can't move more than one square in any direction.\n";
	}
	else
	  cout << "Ending space is off the board.\n";
      }
      else
	cout << "Starting space is off the board.\n";
    }
    else {
      cout << "Invalid input.\n";
      cin.clear();
      cin.ignore(250, '\n');
    }
} while(errors);
  
  board[rowStart-1][columnStart-1] = '-';
  board[rowEnd-1][columnEnd-1] = symbol;
}
