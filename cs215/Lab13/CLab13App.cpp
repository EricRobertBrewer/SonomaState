#include <afxwin.h>
#include "CLab13App.h"
BOOL CLab13App::InitInstance ()
{
m_pMainWnd = new CLab13Win();
m_pMainWnd->ShowWindow (m_nCmdShow);
m_pMainWnd->UpdateWindow ();
return TRUE;
}
CLab13App Lab13App;