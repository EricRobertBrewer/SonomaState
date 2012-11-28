/*
Eric Brewer
CS315 - Dr. Kooshesh
Due: Sept. 25, 2009 at 8:00PM
Worm Project - A standard game of "worm" that
 utilizes the curses library.
*/

#include <curses.h>
#include "prototypes.hpp"
#include "Cell.hpp"
#include <ctime>
#include <cstdlib>

const int ROWS = 28;
const int COLUMNS = 90;
const int WORM_LENGTH = 8;

int main(){
  
  Cell body[(ROWS - 2) * (COLUMNS - 2)];
  int head = 0;
  int tail = 0;
  int wormSize = 0;
  int growthFromFood = WORM_LENGTH - 1;
  Cell map[(ROWS - 2) * (COLUMNS - 2)];
  int mapLast = 0;
  int board[ROWS][COLUMNS];
  int munchieLocation = 0;
  int munchieValue = 0;
  srand(time(NULL));
  bool deadWorm = false;
  Cell newHead;
  char c = ' ';

  startup2();

  //mvaddstr(0, 2, "Score:");
  mvaddstr(0, COLUMNS - 11, "Score:");
  refresh();

  for(int i = 0; i < COLUMNS; i++){
    board[0][i] = -1;
    mvaddch(1, i, '*');
    board[ROWS - 1][i] = -1;
    mvaddch(ROWS, i, '*');
  }
  for(int j = 0; j < ROWS; j++){
    board[j][0] = -1;
    mvaddch(j + 1, 0, '*');
    board[j][COLUMNS - 1] = -1;
    mvaddch(j + 1, COLUMNS - 1, '*');
  }
  
  for(int r = 1; r < ROWS - 1; r++)
    for(int c = 1; c < COLUMNS - 1; c++){
      board[r][c] = mapLast;
      map[mapLast].row = r;
      map[mapLast].col = c;
      mapLast++;
    }
  mapLast--;

  body[head] = map[mapLast / 2 + COLUMNS / 2];
  newHead = body[head];
  board[map[mapLast].row][map[mapLast].col] = mapLast / 2 + COLUMNS / 2;
  board[map[mapLast / 2 + COLUMNS / 2].row][map[mapLast / 2 + COLUMNS / 2].col] = -1;
  mvaddch(map[mapLast / 2 + COLUMNS / 2].row + 1, map[mapLast / 2 + COLUMNS / 2].col, '@');
  munchieLocation = rand() % mapLast;
  munchieValue = rand() % 9 + 1;
  mvaddch(map[munchieLocation].row + 1, map[munchieLocation].col, munchieValue + '0');
  move(0, 0);
  refresh();
  map[mapLast / 2 + COLUMNS / 2] = map[mapLast];
  mapLast--;
  wormSize++;
  
  while(!deadWorm){
    c = get_char();
    switch(c){
    case 'a': 
      newHead.col = body[head].col - 1;
      break;
    case 's': 
      newHead.row = body[head].row + 1;
      break;
    case 'w':
      newHead.row = body[head].row - 1;
      break;
    case 'd':
      newHead.col = body[head].col + 1;
      break;
    case 'p':
      while( get_char() == 'p' );
      continue;
    default:
      continue;
    }

    mvaddstr(0, COLUMNS - 4, WORM_LENGTH - 8);
    
    if(board[newHead.row][newHead.col] == -1)
      deadWorm = true;
    
    if(!deadWorm){
      board[map[mapLast].row][map[mapLast].col] = board[newHead.row][newHead.col];
      map[board[newHead.row][newHead.col]] = map[mapLast];
      mvaddch(body[head].row + 1, body[head].col, 'o');
      head++;
      head %= mapLast;
      body[head] = newHead;
      if(board[body[head].row][body[head].col] == munchieLocation){
	growthFromFood += munchieValue;
	munchieLocation = rand() % mapLast;
	munchieValue = rand() % 9 + 1;
	mvaddch(map[munchieLocation].row + 1, map[munchieLocation].col, munchieValue + '0');
      }
      board[body[head].row][body[head].col] = -1;
      mvaddch(body[head].row + 1, body[head].col, '@');
      if(!growthFromFood){
	board[body[tail].row][body[tail].col] = mapLast;
	map[mapLast] = body[tail];
	mvaddch(body[tail].row + 1, body[tail].col, ' ');
	tail++;
	tail %= mapLast;
      }
      else{
	growthFromFood--;
	mapLast--;
	wormSize++;
      }
    }
    mvprintw(0, COLUMNS - 3, "%i", wormSize - 8);
    move(0, 0);
    refresh();
  }
  move(0, 0);
  refresh();
  terminate2();
  cout << "Score: " << wormSize - 8 << '\n';
  //return 0;
}

void startup2(void){
  initscr();
  clear();
  noecho();
  cbreak();
}

void terminate2(void){
  mvcur(0, COLS - 1, LINES - 1, 0);
  clear();
  refresh();
  endwin();
}
