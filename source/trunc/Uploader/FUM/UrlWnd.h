/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_URLWND_H__806DBD14_EAA0_4C57_8FDE_74936CE90961__INCLUDED_)
#define AFX_URLWND_H__806DBD14_EAA0_4C57_8FDE_74936CE90961__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CUrlWnd : public CStatic
{

public:
	CUrlWnd();

public:

public:

	
	//{{AFX_VIRTUAL(CUrlWnd)
	//}}AFX_VIRTUAL

public:
	
	void SetUrl (LPCSTR pszUrl);
	
	void Init();
	
	virtual ~CUrlWnd();

	
protected:
	CString m_strUrl;
	//{{AFX_MSG(CUrlWnd)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
