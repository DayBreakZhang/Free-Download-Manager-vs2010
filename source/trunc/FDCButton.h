/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_FDCBUTTON_H__C2538FC4_5714_4E65_9C53_6C451678AB50__INCLUDED_)
#define AFX_FDCBUTTON_H__C2538FC4_5714_4E65_9C53_6C451678AB50__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#pragma warning (push, 3)
#include "FDMCustomized/FDMCustomized_lib/FDMCustomizations.h"
#include "Wnd_Banner.h"	
#include "FDCButton.h"	
#pragma warning (pop)

class CFDCButton : public CWnd
{

public:
	CFDCButton();

public:

public:

	
	//{{AFX_VIRTUAL(CFDCButton)
	//}}AFX_VIRTUAL

public:
	vmsFDMCustomizations* m_pCusts;
	void Create (CWnd* pWndParent);
	virtual ~CFDCButton();

	
protected:
	CImageList m_FDCImage;
	CToolBar m_tbFDC;
	void SetupButton();
	//{{AFX_MSG(CFDCButton)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnFDC();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
