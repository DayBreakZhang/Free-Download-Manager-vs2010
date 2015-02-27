/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DOWNLOADS_INFOFRAME_H__78885121_9E0C_4380_B8AD_FE98B0FB5907__INCLUDED_)
#define AFX_DOWNLOADS_INFOFRAME_H__78885121_9E0C_4380_B8AD_FE98B0FB5907__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CDownloads_InfoFrame : public CWnd
{

public:
	CDownloads_InfoFrame();

public:

public:

	
	//{{AFX_VIRTUAL(CDownloads_InfoFrame)
	//}}AFX_VIRTUAL

public:
	
	void SetChildWnd (CWnd *pWnd);
	BOOL Create (CWnd *pParent);
	virtual ~CDownloads_InfoFrame();

	
protected:
	
	void ResizeChild (int cx, int cy);
	CWnd* m_pChild; 
	//{{AFX_MSG(CDownloads_InfoFrame)
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
