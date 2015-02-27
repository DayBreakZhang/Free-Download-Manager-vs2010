/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "fdmapp.h"
#include "WebBrowser2Customization.h"
#include <mshtml.h>
#include <exdispid.h>
#include "mshtmhst.h"
#include "webbrowser2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

BEGIN_DISPATCH_MAP(CWebBrowser2Customization, CCmdTarget)
	DISP_FUNCTION_ID(CWebBrowser2Customization, "BeforeNavigate2", DISPID_BEFORENAVIGATE2, OnBeforeNavigate2, VT_EMPTY, VTS_DISPATCH VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PBOOL)
	DISP_FUNCTION_ID(CWebBrowser2Customization, "DocumentComplete", DISPID_DOCUMENTCOMPLETE, OnDocumentComplete, VT_EMPTY, VTS_DISPATCH VTS_PVARIANT)
END_DISPATCH_MAP()

CWebBrowser2Customization::CWebBrowser2Customization()
{
	m_cRef = 0;

	m_dwHostUiInfoFlags = DOCHOSTUIFLAG_ENABLE_INPLACE_NAVIGATION | 
		DOCHOSTUIFLAG_THEME;

	m_pWB = NULL;

	EnableAutomation ();
}

CWebBrowser2Customization::~CWebBrowser2Customization()
{
}

BEGIN_MESSAGE_MAP(CWebBrowser2Customization, CCmdTarget)
	//{{AFX_MSG_MAP(CWebBrowser2Customization)
		
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CWebBrowser2Customization::OnBeforeNavigate2(LPDISPATCH, VARIANT *vtUrl, VARIANT *, VARIANT *vtTarget, VARIANT *, VARIANT *, BOOL *pbCancel)
{
	USES_CONVERSION;
	*pbCancel = OnNavigateURL (W2CT (vtUrl->bstrVal));
}

void CWebBrowser2Customization::OnDocumentComplete(LPDISPATCH pdWB, VARIANT *URL)
{
	
	IWebBrowser2Ptr spWB (pdWB);
	if (spWB == NULL)
		return;
	
	IDispatchPtr spdDoc;
	spWB->get_Document (&spdDoc);
	IHTMLDocumentPtr spDoc (spdDoc);
	if (spDoc == NULL)
		return;
	
	ICustomDocPtr spCD (spDoc); 
	if (spCD != NULL)
		spCD->SetUIHandler (this);
	
}

STDMETHODIMP CWebBrowser2Customization::GetHostInfo(DOCHOSTUIINFO *pInfo)
{
	
	
	pInfo->dwFlags = m_dwHostUiInfoFlags;
	
	return S_OK;
}

void CWebBrowser2Customization::setHostUiInfoFlags(DWORD dw)
{
	m_dwHostUiInfoFlags = dw;
}

DWORD CWebBrowser2Customization::getHostUiInfoFlags() const
{
	return m_dwHostUiInfoFlags;
}

HRESULT CWebBrowser2Customization::Attach(CWebBrowser2 *pWB)
{
	m_pWB = pWB;

	IConnectionPointContainerPtr spCPC;
	
	LPUNKNOWN pUnk = m_pWB->GetControlUnknown ();
	if (pUnk == NULL)
		return E_FAIL;
	
	spCPC = pUnk;
	if (spCPC == NULL)
		return E_FAIL;
	
	spCPC->FindConnectionPoint (DIID_DWebBrowserEvents2, &m_spCP);
	if (m_spCP == NULL)
		return E_FAIL;
	
	return m_spCP->Advise (GetIDispatch (FALSE), &m_dwCookie);
}

void CWebBrowser2Customization::Detach()
{
	if (m_spCP)
	{
		m_spCP->Unadvise (m_dwCookie);
		m_spCP = NULL;
	}
}

BOOL CWebBrowser2Customization::OnNavigateURL(LPCTSTR ptszUrl)
{
	CString strUrl = ptszUrl;
	
	if (strUrl.Left (5).CompareNoCase (_T ("http:")) == 0 || 
		strUrl.Left (6).CompareNoCase (_T ("https:")) == 0 || 
		strUrl.Left (4).CompareNoCase (_T ("ftp:")) == 0) 
	{
		extern void fsOpenUrlInBrowser (LPCTSTR);
		fsOpenUrlInBrowser (strUrl);
		return TRUE;
	}

	return FALSE;
}
