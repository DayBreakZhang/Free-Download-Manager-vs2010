/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "HFE_Log.h"
#include "HFEWnd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern CHFEWnd* _pwndHFE;

CHFE_Log::CHFE_Log()
{
}

CHFE_Log::~CHFE_Log()
{
}

BEGIN_MESSAGE_MAP(CHFE_Log, CWndLog)
	//{{AFX_MSG_MAP(CHFE_Log)
		ON_COMMAND (ID_CLEAR, OnClear)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CHFE_Log::OnClear()
{
	CWndLog::OnClear ();
	_pwndHFE->m_evMgr.clear ();
}

BOOL CHFE_Log::Create(CWnd *pParent)
{
	if (!CWndLog::Create (pParent))
		return FALSE;

	ReadState ("HFELog");

	return TRUE;
}
