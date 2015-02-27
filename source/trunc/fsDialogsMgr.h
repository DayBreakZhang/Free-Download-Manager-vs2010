/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_FSDIALOGSMGR_H__76F4B252_242A_4A2C_9C15_5BC6EB220845__INCLUDED_)
#define AFX_FSDIALOGSMGR_H__76F4B252_242A_4A2C_9C15_5BC6EB220845__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class fsDialogsMgr  
{
public:
	
	int DoModal (CPropertySheet* sheet);
	int DoModal (CDialog* dlg);

	
	void OnDoModal (CDialog* pDlg);
	void OnDoModal (CPropertySheet *pSheet);

	
	void OnEndDialog (CDialog* pDlg);
	void OnEndDialog (CPropertySheet *pSheet);
	
	
	void EndAllDialogs ();
	
	fsDialogsMgr();
	virtual ~fsDialogsMgr();

protected:
	
	int FindDialog (CWnd *pWnd);
	fs::list <CWnd*> m_vDlgs;	
};

#endif 
