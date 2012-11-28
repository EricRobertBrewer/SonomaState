#include <afxwin.h>
#include "CLab13Win.h"
CLab13Win::CLab13Win ()
{
Create (NULL, "Lab13");
m_nMessageX = 100;
m_nMessageY = 100;
m_nNumRects = 5;
m_nNumAreas = 4;
m_nRedMin = 0;
m_nRedMax = 0;
m_nGreenMin = 0;
m_nGreenMax = 255;
m_nBlueMin = 255;
m_nBlueMax = 0;
}
afx_msg void CLab13Win::OnPaint ()
{
CPaintDC dc (this);
dc.SetBkMode(TRANSPARENT);
dc.SetTextColor(RGB (255,255,255));
CRect rect;
GetClientRect (&rect);
int height = rect.Height () / m_nNumAreas;
int width = rect.Width () / m_nNumAreas;
int deltaX = width / 2 / m_nNumRects;
int deltaY = height / 2 / m_nNumRects;
int deltaR = (m_nRedMax - m_nRedMin) / (m_nNumRects - 1);
int deltaG = (m_nGreenMax - m_nGreenMin) / (m_nNumRects - 1);
int deltaB = (m_nBlueMax - m_nBlueMin) / (m_nNumRects - 1);
for (int aX = 0; aX < m_nNumAreas; aX++)
for (int aY = 0; aY < m_nNumAreas; aY++)
{
int ulX = aX * width;
int ulY = aY * height;
int lrX = (aX+1) * width;
int lrY = (aY+1) * height;
for (int r = 0; r < m_nNumRects; r++)
{
int red = m_nRedMin + r * deltaR;
int green = m_nGreenMin + r * deltaG;
int blue = m_nBlueMin + r * deltaB;
CBrush paintBrush;
paintBrush.CreateSolidBrush (RGB(red, green,
blue));
CBrush * pBrushSv = dc.SelectObject
(&paintBrush);
dc.Rectangle (ulX + r*deltaX, ulY + r*deltaY,
lrX - r*deltaX, lrY - r*deltaY);
dc.SelectObject (pBrushSv);
}
}
dc.DrawText("Hello World", CRect (m_nMessageX, m_nMessageY,
m_nMessageX+80, m_nMessageY+16), DT_LEFT);
}
afx_msg void CLab13Win::OnMouseMove( UINT nFlags, CPoint point )
{
if (nFlags == MK_LBUTTON)
{
m_nMessageX = point.x;
m_nMessageY = point.y;
Invalidate (TRUE);
}
}
afx_msg void CLab13Win::OnKeyDown( UINT nChar, UINT nRepCnt, UINT nFlags )
{
switch (nChar)
{
case 37: // Left arrow key
if (m_nNumRects > 2)
{
m_nNumRects--;
Invalidate (TRUE);
}
break;
case 38: // Up arrow key
m_nNumAreas++;
Invalidate (TRUE);
break;
case 39: // Right arrow key
m_nNumRects++;
Invalidate (TRUE);
break;
case 40: // Down arrow key
if (m_nNumAreas > 1)
{
m_nNumAreas--;
Invalidate (TRUE);
}
break;
default:
MessageBox ("Key not recognized");
}
}

BEGIN_MESSAGE_MAP (CLab13Win, CFrameWnd)
ON_WM_PAINT ()
ON_WM_KEYDOWN ()
ON_WM_MOUSEMOVE ()
END_MESSAGE_MAP ()