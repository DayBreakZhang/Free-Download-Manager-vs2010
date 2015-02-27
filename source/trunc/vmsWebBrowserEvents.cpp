/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "vmsWebBrowserEvents.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

BEGIN_DISPATCH_MAP(vmsWebBrowserEvents, CCmdTarget)
	DISP_FUNCTION_ID(vmsWebBrowserEvents, "DocumentComplete", DISPID_DOCUMENTCOMPLETE, OnDocumentComplete, VT_EMPTY, VTS_DISPATCH VTS_PVARIANT)
END_DISPATCH_MAP()

vmsWebBrowserEvents::vmsWebBrowserEvents(CWebBrowser2 *pWB, IDocHostUIHandler *pUIHandler)
{
	EnableAutomation ();

	set_WebBrowser (pWB);
	set_UIHandler (pUIHandler);
}

vmsWebBrowserEvents::~vmsWebBrowserEvents()
{
}

BEGIN_MESSAGE_MAP(vmsWebBrowserEvents, CCmdTarget)
	//{{AFX_MSG_MAP(vmsWebBrowserEvents)
		
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

HRESULT vmsWebBrowserEvents::Attach()
{
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

void vmsWebBrowserEvents::Detach()
{
	if (m_spCP)
	{
		m_spCP->Unadvise (m_dwCookie);
		m_spCP = NULL;
	}
}

void vmsWebBrowserEvents::set_WebBrowser(CWebBrowser2 *pWB)
{
	m_pWB = pWB;
}

void vmsWebBrowserEvents::set_UIHandler(IDocHostUIHandler *pUIHandler)
{
	m_spUIHandler = pUIHandler;
}

void vmsWebBrowserEvents::OnDocumentComplete(LPDISPATCH pdWB, VARIANT *URL)
{
	if (m_spUIHandler != NULL)
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
			spCD->SetUIHandler (m_spUIHandler);
	}
}
