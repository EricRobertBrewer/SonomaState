#include"Maze.h"

Maze :: Maze()
{
  numRows = 21;
  numCols = 32;
  grid = new char*[numRows];
  for(int i = 0; i < numRows; i++)
    grid[i] = new char[numCols];
  /*
  strcpy (grid[0], "###############################");
  strcpy (grid[1], "#O#     #             #   #   #");
  strcpy (grid[2], "# # ### ##### # ##### ### # ###");
  strcpy (grid[3], "# # # #     # #     #   #     #");
  strcpy (grid[4], "# # # # # # ### ### ### # ### #");
  strcpy (grid[5], "# # #   # #   #   #   #     # #");
  strcpy (grid[6], "# # # ### ### ####### ##### # #");
  strcpy (grid[7], "#   # #     # #       #   # # #");
  strcpy (grid[8], "########### # # ######### # ###");
  strcpy (grid[9], "#           # # #   #         #");
  strcpy(grid[10], "# # # ####### # # # # # ##### #");
  strcpy(grid[11], "# # #   #   #   # # # # #     #");
  strcpy(grid[12], "### ### # # ##### ### # #######");
  strcpy(grid[13], "#   # # # #     #     # #   # #");
  strcpy(grid[14], "# # # # # # ############# # # #");
  strcpy(grid[15], "# # #   # #             # #   #");
  strcpy(grid[16], "# # ##### ##### ####### # #####");
  strcpy(grid[17], "# #     # #     #     #   #   #");
  strcpy(grid[18], "# ####### # ### # ### ##### # #");
  strcpy(grid[19], "#         #   #     #       #X#");
  strcpy(grid[20], "###############################");
  */
  for(int g = 0; g < 21; g++)
    {
      grid[g][0] = '#';
      grid[g][30] = '#';
    }
  for(int h = 0; h < 31; h++)
    {
      grid[0][h] = '#';
      grid[20][h] = '#';
    }
  for(int m = 1; m < 20; m++)
    for(int n = 1; n < 30; n++)
      grid[m][n] = ' ';

  srand(time(NULL));
  Divide(0, 20, 0, 30);

  endRow = 19;
  endCol = 29;
  currentRow = 1;
  currentCol = 1;
  
  grid[1][1] = 'O';
  grid[19][29] = 'X';
}

Maze :: Maze(const int & R, const int & C)
{
  if(R < 38 && C < 59)
    {
      numRows = ((2 * (R / 2)) + 1);
      numCols = ((2 * (C / 2)) + 2);
      
      grid = new char*[numRows];
      for(int i = 0; i < numRows; i++)
	grid[i] = new char[numCols];
      
      for(int g = 0; g < numRows; g++)
	{
	  grid[g][0] = '#';
	  grid[g][numCols-2] = '#';
	}
      for(int h = 0; h < numCols-1; h++)
	{
	  grid[0][h] = '#';
	  grid[numRows-1][h] = '#';
	}
      for(int m = 1; m < numRows - 1; m++)
	for(int n = 1; n < numCols - 2; n++)
	  grid[m][n] = ' ';

      if(numRows > 4 && numCols > 4)
	{
	  srand(time(NULL));
	  Divide(0, numRows-1, 0, numCols-2);
	}

      endRow = numRows - 2;
      endCol = numCols - 3;
      currentRow = 1;
      currentCol = 1;
  
      grid[currentRow][currentCol] = 'O';
      grid[endRow][endCol] = 'X';
    }
  else
    cout << "Dimensions are too large.";
}

Maze :: Maze(const Maze & other)
{
  numRows = other.numRows;
  numCols = other.numCols;
  grid = new char*[numRows];
  for(int i = 0; i < numRows; i++)
    grid[i] = new char[numCols];
  for(int j = 0; j < numRows; j++)
    strcpy(grid[j], other.grid[j]);
  endRow = other.endRow;
  endCol = other.endCol;
  currentRow = other.currentRow;
  currentCol = other.currentCol;
}

Maze :: ~Maze()
{
  delete [] grid;
}

Maze & Maze :: operator = (const Maze & other)
{
  if (&other != this)
    {
      numRows = other.numRows;
      numCols = other.numCols;
      grid = new char*[numRows];
      for(int i = 0; i < numRows; i++)
	grid[i] = new char[numCols];
      for(int j = 0; j < numRows; j++)
	strcpy(grid[j], other.grid[j]);
      endRow = other.endRow;
      endCol = other.endCol;
      currentRow = other.currentRow;
      currentCol = other.currentCol;
    }
  return *this;
}

void Maze :: Instructions(ostream & outs)
{
  outs << "Try to reach the X square with your O square.\n"
       << "W: Up\n"
       << "A: Left\n"
       << "S: Down\n"
       << "D: Right\n"
       << "Good luck, you probably won't need it.";
}

void Maze:: Display(ostream & outs)
{
  outs << endl;
  for (int i = 0; i < numRows; i++)
    {
      for (int j = 0; j < numCols; j++)
	outs << grid[i][j] << ' ';
      outs << endl;
    }
}

bool Maze :: Move(char dir)
{
  switch (dir)
    {
    case 'w' : if (grid[currentRow-1][currentCol] != '#')
	{
	  grid[currentRow-1][currentCol] = 'O';
	  grid[currentRow][currentCol] = '.';
	  currentRow--;
	}
      break;
    case 'a' : if (grid[currentRow][currentCol-1] != '#')
        {
          grid[currentRow][currentCol-1] = 'O';
          grid[currentRow][currentCol] = '.';
          currentCol--;
        }
      break;
    case 's' : if (grid[currentRow+1][currentCol] != '#')
        {
          grid[currentRow+1][currentCol] = 'O';
          grid[currentRow][currentCol] = '.';
          currentRow++;
        }
      break;
    case 'd' : if (grid[currentRow][currentCol+1] != '#')
        {
          grid[currentRow][currentCol+1] = 'O';
          grid[currentRow][currentCol] = '.';
          currentCol++;
        }
      break;
    }
  dir = ' ';
  if (currentRow == endRow && currentCol == endCol)
    return true;
  return false;
}

void Maze :: Message(bool completed, ostream & outs)
{
  if(completed)
    outs << "Hooray! Let's celebrate. I'll buy you a cold one." << endl;
  else
    outs << "Wow, you're pretty terrible if you can't get through a kid's programming project." << endl;
}

void Maze :: Divide(int U, int D, int L, int R)
{
  int horiz = (U + 2 * (rand()%(((D - U) - 2) / 2)) + 2);
  int vert = (L + 2 * (rand()%(((R - L) - 2) / 2)) + 2);

  for(int i = L; i < R; i++)
    grid[horiz][i] = '#';
  for(int j = U; j < D; j++)
    grid[j][vert] = '#';

  int noDoor = rand()%4;
  if(noDoor != 0)
    grid[horiz][L + 2 * (rand()%((vert - L) / 2)) + 1] = ' ';
  if(noDoor != 1)
    grid[U + 2 * (rand()%((horiz - U) / 2)) + 1][vert] = ' ';
  if(noDoor != 2)
    grid[horiz][vert + 2 * (rand()%((R - vert) / 2)) + 1] = ' ';
  if(noDoor != 3)
    grid[horiz + 2 * (rand()%((D - horiz) / 2)) + 1][vert] = ' ';

  if((vert - L) != 2 && (horiz - U) != 2)
    Divide(U, horiz, L, vert);
  if((R - vert) != 2 && (horiz - U) != 2)
    Divide(U, horiz, vert, R);
  if((vert - L) != 2 && (D - horiz) != 2)
    Divide(horiz, D, L, vert);
  if((R - vert) != 2 && (D - horiz) != 2)
    Divide(horiz, D, vert, R);
}
