#include<afxwin.h>

/*
enum sType{WALL, EMPTY, ME, GOAL, CRUMB}
enum dType{UP, DOWN, LEFT, RIGHT}
*/

class CMaze
{
public:
	CMaze();
	CMaze(const CMaze & other);
	~CMaze();
	CMaze & operator = (const CMaze & other);
	void Init (int R, int C, CFrameWnd * windowP);
	void Instructions(CFrameWnd * windowP);
	void Display(CRect squ, CFrameWnd * windowP);
	char CMove(char dir);
	void Message(CFrameWnd * windowP);
	bool Finished();

private:
	/*
	struct CMazeSquare
	{
		void Display(CDC * deviceContextP);
		CRect where;
		sType what;
	};
	*/
	void Divide (int U, int D, int L, int R);
	char ** grid;
	int numRows, numCols;
	int currentCol, currentRow;
	int endRow, endCol;
	bool finished;
};