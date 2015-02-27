/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "fsDialogsMgr.h"
#include "MainFrm.h"
#include "vmsLogger.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

fsDialogsMgr::fsDialogsMgr()
{

}

fsDialogsMgr::~fsDialogsMgr()
{

}

void fsDialogsMgr::OnDoModal(CDialog* pDlg)
{
	m_vDlgs.add (pDlg);
}

void fsDialogsMgr::OnEndDialog(CDialog* pDlg)
{
	int iIndex = FindDialog (pDlg);
	if (iIndex == -1)
		return;

	m_vDlgs.del (iIndex);
}

int fsDialogsMgr::FindDialog(CWnd* pWnd)
{
	for (int i = m_vDlgs.size () - 1; i >= 0; i--)
		if (m_vDlgs [i] == pWnd)
			return i;

	return -1;
}

void fsDialogsMgr::EndAllDialogs()
{
	try 
	{
		
		for (int i = m_vDlgs.size () - 1; i >= 0; i--)
			m_vDlgs [i]->SendMessage (WM_COMMAND, IDCANCEL);
	}
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsDialogsMgr::EndAllDialogs " + tstring(ex.what()));
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsDialogsMgr::EndAllDialogs unknown exception");
	}
}

void fsDialogsMgr::OnDoModal(CPropertySheet *pSheet)
{
	m_vDlgs.add (pSheet);
}

void fsDialogsMgr::OnEndDialog(CPropertySheet *pSheet)
{
	int iIndex = FindDialog (pSheet);

	if (iIndex == -1)
		return;

	m_vDlgs.del (iIndex);
}

int fsDialogsMgr::DoModal(CDialog *dlg)
{
	int res;
	OnDoModal (dlg);
	res = dlg->DoModal ();
	OnEndDialog (dlg);
	return res;
}

int fsDialogsMgr::DoModal(CPropertySheet *sheet)
{
	int res;
	OnDoModal (sheet);
	res = sheet->DoModal ();
	OnEndDialog (sheet);
	return res;
}
