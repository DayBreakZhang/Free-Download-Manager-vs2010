/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_PRGSHEET_H__C609A037_E045_4703_AC68_83AA6C8C46CB__INCLUDED_)
#define AFX_PRGSHEET_H__C609A037_E045_4703_AC68_83AA6C8C46CB__INCLUDED_

#include "Prg_GeneralPage.h"	
#include "Prg_UpdatePage.h"	
#include "Prg_HistoryPage.h"	
#include "Prg_SkinsPage.h"	
#include "Prg_MiscPage.h"	
#include "Prg_Data.h"	
#if _MSC_VER > 1000
#pragma once
#endif 

class CPrgSheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CPrgSheet)

public:
	CPrgSheet(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CPrgSheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);

public:

public:

	
	//{{AFX_VIRTUAL(CPrgSheet)
	//}}AFX_VIRTUAL

public:
	void Init();
	virtual ~CPrgSheet();

	
protected:
	CPrg_Data m_data;
	CPrg_MiscPage m_misc;
	CPrg_SkinsPage m_skins;
	CPrg_HistoryPage m_history;	
	CPrg_UpdatePage m_update;	
	CPrg_GeneralPage m_general;	
	//{{AFX_MSG(CPrgSheet)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
