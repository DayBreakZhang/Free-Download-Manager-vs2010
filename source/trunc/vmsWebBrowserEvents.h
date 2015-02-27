/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSWEBBROWSEREVENTS_H__A46677A7_6E00_400D_BA13_E92040F27ABD__INCLUDED_)
#define AFX_VMSWEBBROWSEREVENTS_H__A46677A7_6E00_400D_BA13_E92040F27ABD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "WebBrowser2.h"

class vmsWebBrowserEvents : public CCmdTarget
{
public:
	vmsWebBrowserEvents(CWebBrowser2 *pWB = NULL, IDocHostUIHandler *pUIHandler = NULL);
	virtual ~vmsWebBrowserEvents();

	DECLARE_DISPATCH_MAP();

public:
	void set_UIHandler (IDocHostUIHandler* pUIHandler);
	void set_WebBrowser (CWebBrowser2* pWB);
	void Detach();
	HRESULT Attach();

	
	//{{AFX_VIRTUAL(vmsWebBrowserEvents)
	//}}AFX_VIRTUAL

protected:
	void OnDocumentComplete(LPDISPATCH pdWB, VARIANT *URL);
	IConnectionPointPtr m_spCP;
	DWORD m_dwCookie;
	CWebBrowser2* m_pWB;
	IDocHostUIHandlerPtr m_spUIHandler;
	
	//{{AFX_MSG(vmsWebBrowserEvents)
		
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
