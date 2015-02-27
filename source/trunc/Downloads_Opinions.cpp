/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "Downloads_Opinions.h"
#include "vmsMaliciousDownloadChecker.h"
#include <mshtml.h>
#include "vmsLogger.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define WM_OPINIONS_UPDATECONTENT		(WM_APP+1)

CDownloads_Opinions::CDownloads_Opinions()
{
	m_wbEventRcvr.m_pwndOpinions = this;
	m_enCS = DOCS_UNKNOWN;
	m_cSetAsCurrentTabAfterLoadComplete = 0;
}

CDownloads_Opinions::~CDownloads_Opinions()
{
}

BEGIN_MESSAGE_MAP(CDownloads_Opinions, CWnd)
	//{{AFX_MSG_MAP(CDownloads_Opinions)
	ON_WM_CREATE()
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
	ON_MESSAGE (WM_OPINIONS_UPDATECONTENT, OnUpdateContent)
END_MESSAGE_MAP()

void CDownloads_Opinions::Set_ActiveDownload(vmsDownloadSmartPtr dld)
{
	if (dld != m_dld)
	{
		m_dld = dld;
		m_enCS = DOCS_UNKNOWN;
		if (IsWindowVisible ())
			UpdateContent ();
	}
}

bool CDownloads_Opinions::Create(CWnd *pwndParent)
{
	CRect rc (0, 0, 50, 50);

	if (FALSE == CWnd::Create (AfxRegisterWndClass (0, LoadCursor (NULL, IDC_ARROW), (HBRUSH) (COLOR_WINDOW+1), NULL) ,
			NULL, WS_CHILD | WS_VISIBLE, rc, pwndParent, 0x19821))
		return false;

	return true;
}

int CDownloads_Opinions::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	CRect rc (0, 0, 50, 50);
	m_wb.Create (NULL, WS_CHILD|WS_VISIBLE, rc, this, 0);

	m_wbEventRcvr.Attach ();

	UpdateContent ();
	
	return 0;
}

void CDownloads_Opinions::OnSize(UINT nType, int cx, int cy) 
{
	CWnd::OnSize(nType, cx, cy);
	m_wb.MoveWindow (0, 0, cx, cy);
}

void CDownloads_Opinions::UpdateContent(bool bSetAsCurrentTabAfterLoadComplete)
{
	if (bSetAsCurrentTabAfterLoadComplete)
		InterlockedIncrement (&m_cSetAsCurrentTabAfterLoadComplete);
	PostMessage (WM_OPINIONS_UPDATECONTENT);
}

BOOL CDownloads_Opinions::PreTranslateMessage(MSG* pMsg) 
{
	HACCEL hAccel = ((CFrameWnd*)AfxGetApp ()->m_pMainWnd)->GetDefaultAccelerator();
	if (hAccel != NULL && ::TranslateAccelerator(AfxGetApp ()->m_pMainWnd->m_hWnd, hAccel, pMsg))
		return TRUE;

	if (IsDialogMessage (pMsg))
		return TRUE;
	
	return CWnd::PreTranslateMessage(pMsg);
}

LRESULT CDownloads_Opinions::OnUpdateContent(WPARAM, LPARAM)
{
	try
	{
		if (m_dld == NULL)
		{
			if (m_enCS != DOCS_BLANK)
			{
				
				m_enCS = DOCS_BLANK;
				m_wb.Navigate ("about:blank", NULL, NULL, NULL, NULL);
			}
		}
		else
		{
			bool bShowOpinions = false;
			if (m_dld->pMgr->IsDownloading () &&
					_App.Community_DisplayOpinionsAtDlding ())
			{
				
				
				if (m_dld->dwFlags & (DLD_HASOPINIONS_YES | DLD_HASOPINIONS_NO))
					bShowOpinions = (m_dld->dwFlags & DLD_HASOPINIONS_YES) != 0;
				else
					_pwndDownloads->CheckDldHasOpinions (m_dld); 
			}

			if (bShowOpinions == false)
			{
				
				
				m_enCS = DOCS_OPINION;
				m_wb.Navigate ("http://fdm.freedownloadmanager.org/fromfdm/opinion.html", NULL, NULL, NULL, NULL);
			}
			else
			{
				
				if (m_enCS != DOCS_OPINIONS)
				{
					

					m_enCS = DOCS_OPINIONS;
					CString str;
					CString strUrl;
					if (m_dld->pMgr->IsBittorrent ())
						strUrl = m_dld->pMgr->GetBtDownloadMgr ()->get_InfoHash ();
					else
						strUrl = vmsMaliciousDownloadChecker::EncodeUrl (m_dld->pMgr->get_URL ());
					str.Format ("http://fdm.freedownloadmanager.org/fromfdm/showopinions.html?url=%s", strUrl);
					m_wb.Navigate (str, NULL, NULL, NULL, NULL);
				}
			}
		}
	}
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("CDownloads_Opinions::OnUpdateContent " + tstring(ex.what()));
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("CDownloads_Opinions::OnUpdateContent unknown exception");
	}

	return 0;
}
