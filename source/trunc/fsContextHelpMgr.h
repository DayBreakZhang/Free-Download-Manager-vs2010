/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_FSCONTEXTHELPMGR_H__2385DB0D_FC49_463B_8734_9BEA2D1AE6BC__INCLUDED_)
#define AFX_FSCONTEXTHELPMGR_H__2385DB0D_FC49_463B_8734_9BEA2D1AE6BC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

struct fsCtrlContextHelp
{
	UINT nIDCtrl;	
	LPCSTR pszDesc;	

	fsCtrlContextHelp (UINT nID, LPCSTR pszContextHelp) : nIDCtrl (nID), pszDesc (pszContextHelp) {}
	fsCtrlContextHelp () {};
};

class fsContextHelpMgr  
{
public:
	
	void ShowMenu ();
	
	
	
	
	
	void PrepareContextMenu (CDialog* pDlg, CPoint point, fsCtrlContextHelp* pCtrls, int cCtrls);
	
	void OnWT();

	fsContextHelpMgr();
	virtual ~fsContextHelpMgr();

protected:
	
	
	int FindControl (CPoint pt);

	BOOL m_bInWT;	
	CPoint m_ptLast;	
	CDialog* m_pLastDlg;	
	fsCtrlContextHelp*  m_pLastCtrls;	
	int m_cLastCtrls;	
	int m_iLastCtrl;	
};

#endif 
