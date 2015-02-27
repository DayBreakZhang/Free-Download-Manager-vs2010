/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DLGPI2_WBCUSTOMIZATION_H__E190759D_67D1_4705_AD64_7B99EE1EA39D__INCLUDED_)
#define AFX_DLGPI2_WBCUSTOMIZATION_H__E190759D_67D1_4705_AD64_7B99EE1EA39D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "WebBrowser2Customization.h"

class CDlgPI2_WbCustomization : public CWebBrowser2Customization  
{
public:
	CWnd* m_pwndParent;
	CDlgPI2_WbCustomization();
	virtual ~CDlgPI2_WbCustomization();

protected:
	BOOL OnNavigateURL(LPCTSTR ptszUrl);
};

#endif 
