#include <afxwin.h>

class CLab13Win : public CFrameWnd
{
public:
	CLab13Win();
	afx_msg void OnPaint();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown( UINT nChar, UINT nRepCnt, UINT nFlags );
private:
	int m_nMessageX;
	int m_nMessageY;
	int m_nNumRects;
	int m_nNumAreas;
	int m_nRedMin;
	int m_nRedMax;
	int m_nGreenMin;
	int m_nGreenMax;
	int m_nBlueMin;
	int m_nBlueMax;	
	DECLARE_MESSAGE_MAP()
};
