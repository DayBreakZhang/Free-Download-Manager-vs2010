/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_TOOLBAREX_H__58B8C9AE_B53F_41DE_913E_E539488B949D__INCLUDED_)
#define AFX_TOOLBAREX_H__58B8C9AE_B53F_41DE_913E_E539488B949D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "list.h"
#include "plugins.h"

struct fsTButtonInfo
{
	int idCommand;			
	BYTE bStyle;			
	CString strToolTip;		
	int iName;			

	fsTButtonInfo (int cmd, BYTE style, LPCSTR pszTip, int iString) : idCommand (cmd), bStyle (style), 
		strToolTip (pszTip), iName (iString) {};
	fsTButtonInfo () {};
};

class CToolBarEx : public CToolBar
{

public:
	CToolBarEx();

public:

public:

	
	//{{AFX_VIRTUAL(CToolBarEx)
	//}}AFX_VIRTUAL

public:
	CImageList* get_Images();
	void AutoSize () const;
	
	
	
	
	BOOL InsertGroup (wgTButtonInfo* pButtons, CBitmap* pBitmap, CBitmap *pBmpDisabled, int cButtons);
	
	
	BOOL ShowGroup (int iGrp, int iWhere);
	
	void HideGroup (int iGrp);
	
	
	BOOL OnTBGetButtonInfo (NMHDR* nm);
	BOOL OnNotify(LPNMHDR nm);
	
	
	
	void UpdateGroupToolTips (int iGrp, LPCSTR* ppszTips, UINT uSize);
	
	BOOL Create(CWnd* pParent);
	virtual ~CToolBarEx();

	
protected:
	int m_cNames; 
	
	struct fsTBInfo : fsTButtonInfo
	{
		int iImage;	
	};

	
	fsTBInfo* FindButton (UINT nID);
	
	void UpdateSize();

	CToolBarCtrl* m_bar;

	fs::list <fs::list <fsTBInfo> > m_vGroups;	

	CImageList m_images, m_dimages;	

	//{{AFX_MSG(CToolBarEx)
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
