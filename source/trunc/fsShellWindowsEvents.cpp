/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "fsShellWindowsEvents.h"
#include "vmsLogger.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNCREATE(fsShellWindowsEvents, CCmdTarget)

fsShellWindowsEvents::fsShellWindowsEvents()
{
	m_pConnPt = NULL;
	m_pfnEvents = NULL;
	EnableAutomation ();
}

fsShellWindowsEvents::~fsShellWindowsEvents()
{
	Detach ();
}

BEGIN_MESSAGE_MAP(fsShellWindowsEvents, CCmdTarget)
	//{{AFX_MSG_MAP(fsShellWindowsEvents)
		
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(fsShellWindowsEvents, CCmdTarget)
	DISP_FUNCTION_ID(fsShellWindowsEvents, "WindowRegistered",DISPID_WINDOWREGISTERED,OnWindowRegistered,VT_EMPTY,VTS_I4)
	DISP_FUNCTION_ID(fsShellWindowsEvents, "WindowRevoked",DISPID_WINDOWREVOKED,OnWindowRevoked,VT_EMPTY,VTS_I4)
END_DISPATCH_MAP()

HRESULT fsShellWindowsEvents::Attach(SHDocVw::IShellWindowsPtr& spSHWnds)
{
	LPCONNECTIONPOINTCONTAINER pConnPtContr;
	HRESULT hr;

	hr = spSHWnds->QueryInterface (IID_IConnectionPointContainer, (LPVOID*) &pConnPtContr);
	if (FAILED (hr))
		return hr;

	hr = pConnPtContr->FindConnectionPoint (__uuidof (SHDocVw::DShellWindowsEvents), &m_pConnPt);
	if (FAILED (hr))
	{
		pConnPtContr->Release ();
		return hr;
	}

	hr = m_pConnPt->Advise (GetIDispatch (FALSE), &m_dwCookie);

	pConnPtContr->Release ();

	return S_OK;
}

void fsShellWindowsEvents::Detach()
{
	try 
	{
		if (m_pConnPt)
		{
			m_pConnPt->Unadvise (m_dwCookie);
			m_pConnPt->Release ();
			m_pConnPt = NULL;
		}
	}
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsShellWindowsEvents::Detach " + tstring(ex.what()));
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsShellWindowsEvents::Detach unknown exception");
	}
}

void fsShellWindowsEvents::OnWindowRegistered(long lCookie)
{
	if (m_pfnEvents)
		m_pfnEvents (SWE_WINDOWOPENED, m_lpEventsParam);
}

void fsShellWindowsEvents::OnWindowRevoked(long lCookie)
{
	if (m_pfnEvents)
		m_pfnEvents (SWE_WINDOWCLOSED, m_lpEventsParam);
}

void fsShellWindowsEvents::SetEventFunc(fntSHWindowsEvents pfn, LPVOID lpParam)
{
	m_pfnEvents = pfn;
	m_lpEventsParam = lpParam;
}
