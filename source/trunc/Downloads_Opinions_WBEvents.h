/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DOWNLOADS_OPINIONS_WBEVENTS_H__9718B5AC_7F63_4DA9_AE47_31C511C9752B__INCLUDED_)
#define AFX_DOWNLOADS_OPINIONS_WBEVENTS_H__9718B5AC_7F63_4DA9_AE47_31C511C9752B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "vmsDocHostUIHandler.h"	

class CDownloads_Opinions_WBEvents : public CCmdTarget
{
	DECLARE_DISPATCH_MAP();

public:
	CDownloads_Opinions_WBEvents();
	virtual ~CDownloads_Opinions_WBEvents();

public:
	void Detach();
	HRESULT Attach();
	class CDownloads_Opinions* m_pwndOpinions;

	
	//{{AFX_VIRTUAL(CDownloads_Opinions_WBEvents)
	//}}AFX_VIRTUAL

protected:
	void OnNavigateError (LPDISPATCH pDisp, VARIANT* URL, VARIANT *TargetFrameName, VARIANT *StatusCode, BOOL *pbCancel);
	CString GetFormInputElementText (IHTMLFormElement* pForm, LPCSTR pszElementName, bool& bFound);
	void RetrieveLinkToUsText (IDispatch* pdDoc);
	vmsDocHostUIHandler m_wbUIHandler;
	IConnectionPointPtr m_spCP;
	DWORD m_dwCookie;
	void OnDocumentComplete(LPDISPATCH pDisp, VARIANT *URL);

	
	//{{AFX_MSG(CDownloads_Opinions_WBEvents)
		
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
