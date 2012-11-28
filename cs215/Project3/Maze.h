/*
Eric Brewer
3/24/09
CS215
Project 3 - The Maze Project:
 Creates a static maze of characters
 which indicate the walls. Try to 
 escape the maze by reaching the exit.
*Part 2 - The maze is now randomly 
 generated using a recursive
 algorithm to create a vertical and
 horizontal wall in each "chamber."
 Also punches three doors in these 
 walls so that each chamber should be
 connected.
*/

#ifndef MAZE_H
#define MAZE_H

#include<cstring>
#include<cstdlib>
#include<ctime>
#include<iostream>
using namespace std;

class Maze
{
 public:
  Maze();
  Maze(const int & R, const int & C);
  Maze(const Maze & other);
  ~Maze();
  Maze & operator = (const Maze & other);
  void Instructions(ostream & outs);
  void Display(ostream & outs);
  bool Move(char dir);
  void Message(bool completed, ostream & outs);

 private:
  char ** grid;
  int numRows, numCols;
  int currentRow, currentCol;
  int endRow, endCol;
  void Divide(int U, int D, int L, int R);
};

#endif
    
