#include<afxwin.h>
#include"application.h"

BOOL CMazeApp :: InitInstance()
{
	m_pMainWnd = new CMazeWin();
	m_pMainWnd->ShowWindow(m_nCmdShow);
	m_pMainWnd->UpdateWindow();

	return TRUE;
}

CMazeApp MazeApp;

