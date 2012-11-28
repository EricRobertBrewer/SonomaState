#include"CMaze.h"

CMaze :: CMaze()
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

/*
CMaze :: CMaze(const int & R, const int & C)
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
*/

CMaze :: CMaze(const CMaze & other)
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

CMaze :: ~CMaze()
{
  delete [] grid;
}

CMaze & CMaze :: operator = (const CMaze & other)
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

void CMaze :: Init(int R, int C, CFrameWnd * windowP)
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
    windowP->MessageBox("Dimensions too large");
}

void CMaze :: Instructions(CFrameWnd * windowP)
{
  windowP->MessageBox("Use the arrow keys to move.");
  windowP->MessageBox("Try to reach the X square with your O square!");
}

void CMaze:: Display(CRect squ, CFrameWnd * windowP)
{
  CPaintDC dc(windowP);
  int height = squ.Height() / numRows;
  int width = squ.Width() / numCols;
  for (int i = 0; i < numRows; i++)
    {
      for (int j = 0; j < numCols; j++)
	  {
		  int ulx = j * width;
		  int uly = i * height;
		  int lrx = (j+1) * width;
		  int lry = (i+1) * height;
		  
		  if(grid[i][j] == '#')
		  {
			  CBrush roller;
			  roller.CreateSolidBrush (RGB(0, 0, 0));
			  CBrush * axel = dc.SelectObject(&roller);
			  dc.Rectangle (ulx, uly, lrx, lry);
			  dc.SelectObject(axel);
		  }
		  else if(grid[i][j] == 'O')
		  {
			  CBrush roller;
			  roller.CreateSolidBrush (RGB(255, 0, 0));
			  CBrush * axel = dc.SelectObject(&roller);
			  dc.Rectangle (ulx, uly, lrx, lry);
			  dc.SelectObject(axel);
		  }
		  else if(grid[i][j] == ' ')
		  {
			  CBrush roller;
			  roller.CreateSolidBrush (RGB(0, 255, 0));
			  CBrush * axel = dc.SelectObject(&roller);
			  dc.Rectangle (ulx, uly, lrx, lry);
			  dc.SelectObject(axel);
		  }
		  else if(grid[i][j] == '.')
		  {
			  CBrush roller;
			  roller.CreateSolidBrush (RGB(0, 0, 255));
			  CBrush * axel = dc.SelectObject(&roller);
			  dc.Rectangle (ulx, uly, lrx, lry);
			  dc.SelectObject(axel);
		  }
		  else if(grid[i][j] == 'X')
		  {
			  CBrush roller;
			  roller.CreateSolidBrush (RGB(0, 127, 127));
			  CBrush * axel = dc.SelectObject(&roller);
			  dc.Rectangle (ulx, uly, lrx, lry);
			  dc.SelectObject(axel);
		  }
      }
    }
}

char CMaze :: CMove(char dir)
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

  return dir;
}

void CMaze :: Message(CFrameWnd * windowP)
{
  if(Finished())
  {windowP->MessageBox("Gadzooks! You have finished a maze created by a child! Congratulations!");
  exit(1);}
}

bool CMaze :: Finished()
{
	return (currentRow == endRow && currentCol == endCol);
}

void CMaze :: Divide(int U, int D, int L, int R)
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