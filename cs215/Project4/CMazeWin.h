#include <afxwin.h>
#include "CMaze.h"

class CMazeWin : public CFrameWnd
{
public:
	CMazeWin();
	afx_msg void OnPaint();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
private:
	CMaze myMaze;
	DECLARE_MESSAGE_MAP()
};