/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "fsShellBrowsersEvents.h"
#include "vmsLogger.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNCREATE(fsShellBrowsersEvents, CCmdTarget)

fsShellBrowsersEvents::fsShellBrowsersEvents()
{
	m_pfnEvents = NULL;
	EnableAutomation ();
	m_pWBRoot = NULL;
	m_bDetaching = false;
}

fsShellBrowsersEvents::~fsShellBrowsersEvents()
{
	Detach ();
}

BEGIN_MESSAGE_MAP(fsShellBrowsersEvents, CCmdTarget)
	//{{AFX_MSG_MAP(fsShellBrowsersEvents)
		
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(fsShellBrowsersEvents, CCmdTarget)
	DISP_FUNCTION_ID(fsShellBrowsersEvents, "BeforeNavigate2",DISPID_BEFORENAVIGATE2,OnBeforeNavigate, VT_EMPTY, VTS_DISPATCH VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PBOOL)
	DISP_FUNCTION_ID(fsShellBrowsersEvents, "DownloadBegin",DISPID_DOWNLOADBEGIN,OnDownloadBegin, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION_ID(fsShellBrowsersEvents, "DownloadComplete",DISPID_DOWNLOADCOMPLETE,OnDownloadComplete, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION_ID(fsShellBrowsersEvents, "DocumentComplete", DISPID_DOCUMENTCOMPLETE, OnDocumentComplete, VT_EMPTY, VTS_DISPATCH VTS_PVARIANT)
	DISP_FUNCTION_ID(fsShellBrowsersEvents, "NavigateComplete2", DISPID_NAVIGATECOMPLETE2, OnNavigateComplete2, VT_EMPTY, VTS_DISPATCH VTS_PVARIANT)
END_DISPATCH_MAP()

HRESULT fsShellBrowsersEvents::Attach(SHDocVw::IShellWindowsPtr& spSHWnds)
{
	if (m_bDetaching)
		return S_FALSE;

	if (is_Attached ())
		Detach ();

	LONG cItems = spSHWnds->GetCount ();
	HRESULT hr;

	
	for (LONG i = 0; i < cItems; i++)
	{
		try 
		{
			IDispatchPtr spDisp;
			_variant_t va (i, VT_I4);
		
			spDisp = spSHWnds->Item (va);

			SHDocVw::IWebBrowser2Ptr spBrowser (spDisp);

			if (spBrowser == NULL)
				continue;

			
			fsShellBrowsersEvents* pBrowser = new fsShellBrowsersEvents;
		
			hr = pBrowser->Attach (spBrowser); 

			if (FAILED (hr))
			{
				delete pBrowser;
				return hr;
			}

			pBrowser->SetEventFunc (m_pfnEvents, m_lpEventsParam);

			m_vBrowsers.add (pBrowser);
		}
		catch (const std::exception& ex)
		{
			ASSERT (FALSE);
			vmsLogger::WriteLog("fsShellBrowsersEvents::Attach " + tstring(ex.what()));
		}
		catch (...)
		{
			ASSERT (FALSE);
			vmsLogger::WriteLog("fsShellBrowsersEvents::Attach unknown exception");
		}
	}
	
	return S_OK;
}

HRESULT fsShellBrowsersEvents::Attach(SHDocVw::IWebBrowser2Ptr& spBrowser)
{
	if (m_bDetaching)
		return S_FALSE;

	IConnectionPointContainerPtr spConnPtContr;
	HRESULT hr;

	

	hr = spBrowser->QueryInterface (IID_IConnectionPointContainer, (LPVOID*) &spConnPtContr);
	if (FAILED (hr))
		return hr;

	hr = spConnPtContr->FindConnectionPoint (__uuidof (SHDocVw::DWebBrowserEvents2), &m_spConnPt);
	if (FAILED (hr))
		return hr;

	hr = m_spConnPt->Advise (GetIDispatch (FALSE), &m_dwCookie);

	if (SUCCEEDED (hr))
		m_spWB = spBrowser;

	return hr;
}

void fsShellBrowsersEvents::Detach()
{
	m_bDetaching = true;

	try 
	{
		if (m_vBrowsers.size () != 0)
		{
			int i = 0;
			for (i = 0; i < m_vBrowsers.size (); i++)
				m_vBrowsers [i]->SetEventFunc (NULL, 0);

			for (i = 0; i < m_vBrowsers.size (); i++)
			{
				m_vBrowsers [i]->Detach ();
				delete m_vBrowsers [i];
			}

			m_vBrowsers.clear ();
		}
		else
		{
			if (m_spConnPt != NULL)
			{
				m_spConnPt->Unadvise (m_dwCookie);
				m_spConnPt = NULL;	
			}
		}
	}
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsShellBrowsersEvents::Detach " + tstring(ex.what()));
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsShellBrowsersEvents::Detach unknown exception");
	}

	m_bDetaching = false;
}

void fsShellBrowsersEvents::OnBeforeNavigate(LPDISPATCH, VARIANT *vtUrl, VARIANT *, VARIANT *, VARIANT *, VARIANT *, BOOL* pbCancel)
{
	_bstr_t bstrUrl = vtUrl->bstrVal;
	*pbCancel = Event (SBE_BEFORENAVIGATE, (DWORD)(LPCSTR) bstrUrl) == FALSE;
}

void fsShellBrowsersEvents::OnDownloadBegin()
{
	Event (SBE_DLBEGIN);
}

void fsShellBrowsersEvents::OnDownloadComplete()
{
	Event (SBE_DLCOMPLETE);
}

void fsShellBrowsersEvents::SetEventFunc(fntSHBrowserEvent pfn, LPVOID lpParam)
{
	m_pfnEvents = pfn;
	m_lpEventsParam = lpParam;

	for (int i = 0; i < m_vBrowsers.size (); i++)
		m_vBrowsers [i]->SetEventFunc (pfn, lpParam);
}

BOOL fsShellBrowsersEvents::Event(fsSHBrowserEvent ev, DWORD dwInfo)
{
	if (m_bDetaching || is_Attached () == FALSE)
		return FALSE;

	if (m_pfnEvents)
		return m_pfnEvents (this, ev, dwInfo, m_lpEventsParam);

	return TRUE;
}

BOOL fsShellBrowsersEvents::is_Attached()
{
	return m_spConnPt != NULL || m_vBrowsers.size () != 0;
}

IWebBrowser2* fsShellBrowsersEvents::get_WB()
{
	return m_spWB;
}

void fsShellBrowsersEvents::OnDocumentComplete(LPDISPATCH pDisp, VARIANT *URL)
{
	if (m_pWBRoot == pDisp)
	{
		Event (SBE_DOCUMENTCOMPLETE);
		m_pWBRoot = NULL;
	}
}

void fsShellBrowsersEvents::OnNavigateComplete2(LPDISPATCH pDisp, VARIANT *URL)
{
	if (m_pWBRoot == NULL)
		m_pWBRoot = pDisp;
}
