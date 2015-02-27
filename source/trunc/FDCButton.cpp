/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "FDCButton.h"
#include "mfchelp.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CFDCButton::CFDCButton()
{
}

CFDCButton::~CFDCButton()
{
}

BEGIN_MESSAGE_MAP(CFDCButton, CWnd)
	//{{AFX_MSG_MAP(CFDCButton)
	ON_WM_SIZE()
	ON_WM_CREATE()
	ON_COMMAND(ID_FDC, OnFDC)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

#define FDCB_MIN_SIZE		16

void CFDCButton::Create(CWnd *pWndParent)
{
	CWnd::CreateEx (WS_EX_TRANSPARENT,
			AfxRegisterWndClass (0, NULL,
				NULL, NULL), 
			"", WS_CHILD|WS_VISIBLE,
			CRect (0, 0, 120, _TB_SIZE_Y > FDCB_MIN_SIZE ? _TB_SIZE_Y : FDCB_MIN_SIZE+9), pWndParent, 0);

	CRect rc;
	m_tbFDC.GetItemRect (0, &rc);

	SetWindowPos (NULL, 0, 0, rc.Width (), rc.Height (), SWP_NOZORDER | SWP_NOMOVE);
}

void CFDCButton::SetupButton()
{
	m_tbFDC.CreateEx (this, TBSTYLE_FLAT | TBSTYLE_TRANSPARENT | 
		TBSTYLE_LIST | TBSTYLE_AUTOSIZE,
		WS_CHILD | WS_VISIBLE | CBRS_ALIGN_TOP | CCS_NORESIZE);

	int iCX = _TB_SIZE_X > FDCB_MIN_SIZE ? _TB_SIZE_X : FDCB_MIN_SIZE;
	int iCY = _TB_SIZE_Y > FDCB_MIN_SIZE ? _TB_SIZE_Y : FDCB_MIN_SIZE;

	m_tbFDC.GetToolBarCtrl ().SetBitmapSize (CSize (_TB_SIZE_X, _TB_SIZE_Y));
	m_tbFDC.SetSizes (CSize (_TB_SIZE_X+7, iCY +7), 
		CSize (_TB_SIZE_X, iCY));

	m_FDCImage.Create (iCX, iCY, ILC_COLOR32 | ILC_MASK, 1, 1);
	m_tbFDC.GetToolBarCtrl ().SetImageList (&m_FDCImage);

	
	CString strFile = fsGetDataFilePath ("fdmcsbn.ico");
	HANDLE hFile = CreateFile (strFile, GENERIC_WRITE, 0, NULL,
		CREATE_ALWAYS, FILE_ATTRIBUTE_HIDDEN, NULL);
	if (hFile != INVALID_HANDLE_VALUE)
	{
		DWORD dw;
		WriteFile (hFile, m_pCusts->get_ButtonInfo ()->pbIcon, 
			m_pCusts->get_ButtonInfo ()->dwSize, &dw, NULL);
		CloseHandle (hFile);
		
		HICON hIco = (HICON)LoadImage (NULL, strFile, IMAGE_ICON, 0, 0, LR_LOADFROMFILE);
		m_FDCImage.Add (hIco);
	}

	UINT id = ID_FDC;
	m_tbFDC.SetButtons (&id, 1);
	m_tbFDC.SetButtonText (0, m_pCusts->get_ButtonInfo ()->pszText);
}

void CFDCButton::OnSize(UINT nType, int cx, int cy) 
{
	CWnd::OnSize(nType, cx, cy);
	m_tbFDC.SetWindowPos (NULL, 0, 0, cx, (_TB_SIZE_Y > FDCB_MIN_SIZE ? _TB_SIZE_Y : FDCB_MIN_SIZE)+7, SWP_NOZORDER);
}

int CFDCButton::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	SetupButton ();
	
	return 0;
}

void CFDCButton::OnFDC() 
{
	fsOpenUrlInBrowser (m_pCusts->get_ButtonInfo ()->pszLinksTo);
}

