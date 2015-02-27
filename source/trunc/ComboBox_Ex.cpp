/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "ComboBox_Ex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CComboBox_Ex::CComboBox_Ex()
{
}

CComboBox_Ex::~CComboBox_Ex()
{
}

BEGIN_MESSAGE_MAP(CComboBox_Ex, CComboBox)
	//{{AFX_MSG_MAP(CComboBox_Ex)
	ON_MESSAGE (CB_GETDROPPEDSTATE, OnGetDroppedState)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CComboBox_Ex::Create(CWnd *pParent)
{
	CRect rc (0, 0, 100, 100);
	
	CComboBox::Create (WS_CHILD|WS_VISIBLE|CBS_AUTOHSCROLL|CBS_DROPDOWN|WS_VSCROLL,
		rc, pParent, 0x67909);

	m_font.CreateFont (15, 0, 0, 0, FW_NORMAL, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, "MS Sans Serif");
	SetFont (&m_font);

	return TRUE;
}

void CComboBox_Ex::SetReturnID(UINT nID)
{
	m_uReturnID = nID;
}

LRESULT CComboBox_Ex::OnGetDroppedState(WPARAM, LPARAM)
{
	

	LRESULT lRes = DefWindowProc (CB_GETDROPPEDSTATE, 0, 0);
	
	if (lRes == FALSE)
		GetParent ()->PostMessage (WM_COMMAND, m_uReturnID, 0);	

	return lRes;
}
