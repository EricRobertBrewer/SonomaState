#include<afxwin.h>
#include"CMazeWin.h"

CMazeWin :: CMazeWin()
{
	Create(NULL, "proj4");
}

afx_msg void CMazeWin :: OnPaint()
{
	CRect rect;
	GetClientRect(&rect);
	myMaze.Display(rect, this);
}

afx_msg void CMazeWin :: OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	switch (nChar)
	{
	case 37 :
		myMaze.CMove('a');
		Invalidate(TRUE);
		break;
	case 38 :
		myMaze.CMove('w');
Invalidate(TRUE);
		break;
	case 39:
		myMaze.CMove('d');
Invalidate(TRUE);
		break;
	case 40:
		myMaze.CMove('s');
Invalidate(TRUE);
		break;
	default:
		MessageBox ("Invalid Key.");
	}
	myMaze.Message(this);
}

BEGIN_MESSAGE_MAP (CMazeWin, CFrameWnd)
	ON_WM_PAINT()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()   




































































































































































































































































































