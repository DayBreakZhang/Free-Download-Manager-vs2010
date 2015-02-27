/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DOWNLOADPROPERTIES_CONNECTIONPAGE_H__EBBFF39D_6EDE_400B_B24D_03DDEF028FC7__INCLUDED_)
#define AFX_DOWNLOADPROPERTIES_CONNECTIONPAGE_H__EBBFF39D_6EDE_400B_B24D_03DDEF028FC7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "list.h"

class CDownloadProperties_ConnectionPage : public CPropertyPage
{
	friend class CDownloadPropertiesSheet;

	DECLARE_DYNCREATE(CDownloadProperties_ConnectionPage)

public:
	CDownloadProperties_ConnectionPage();
	~CDownloadProperties_ConnectionPage();

	//{{AFX_DATA(CDownloadProperties_ConnectionPage)
	enum { IDD = IDD_DOWNLOAD_CONNECTION };
		
		
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDownloadProperties_ConnectionPage)
	public:
	virtual BOOL OnApply();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void PrepareCHMgr(CPoint point);
	void ApplyLanguage();
	
	
	
	
	
	
	void ErrMustBeGreaterThan (UINT nID, UINT uMin);
	void UpdateEnabled();
	
	DLDS_LIST *m_pvDlds;
	
	//{{AFX_MSG(CDownloadProperties_ConnectionPage)
	virtual BOOL OnInitDialog();
	afx_msg void OnLimittraffic();
	afx_msg void OnIgnoreallrestrictions();
	afx_msg void OnChangePausebetween();
	afx_msg void OnChangeMaxattempts();
	afx_msg void OnChangeTimeout();
	afx_msg void OnChangeSectminsize();
	afx_msg void OnChangeSectmaxcount();
	afx_msg void OnChangeTrafficlimitval();
	afx_msg void OnEditchangeTrafficlimitdim();
	afx_msg void OnSelchangeTrafficlimitdim();
	afx_msg void OnSelchangeSectminsizedim();
	afx_msg void OnUsemaxattempts();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnWhatisthis();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnRestartifspeedlow();
	afx_msg void OnChangeLowspeedDuration();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}

#endif 
