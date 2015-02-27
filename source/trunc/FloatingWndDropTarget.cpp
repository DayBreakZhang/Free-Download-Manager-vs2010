/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "FloatingWndDropTarget.h"
#include "DownloadsWnd.h"
#include "SpiderWnd.h"
#include "SpiderAddPageDlg.h"
#include "MainFrm.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

extern CDownloadsWnd* _pwndDownloads;
extern CSpiderWnd* _pwndSpider;

CFloatingWndDropTarget::CFloatingWndDropTarget()
{

}

CFloatingWndDropTarget::~CFloatingWndDropTarget()
{

}

DROPEFFECT CFloatingWndDropTarget::OnDragEnter(CWnd* pWnd, COleDataObject* pData, DWORD dwKeyState, CPoint pt)
{
	return OnDragOver (pWnd, pData, dwKeyState, pt);
}

DROPEFFECT CFloatingWndDropTarget::OnDragOver(CWnd*, COleDataObject* pData, DWORD , CPoint )
{
	if (pData->IsDataAvailable (CF_TEXT))
	{
		HGLOBAL hMem = pData->GetGlobalData (CF_TEXT);
		if (hMem)
		{
			LPCSTR psz = (LPCSTR) GlobalLock (hMem);
			fsURL url;
			BOOL bOk = url.Crack (psz) == IR_SUCCESS;
			GlobalUnlock (hMem);
			GlobalFree (hMem);
			if (bOk)
				return DROPEFFECT_COPY | DROPEFFECT_MOVE | DROPEFFECT_LINK;
		}
	}
	else if (pData->IsDataAvailable (CF_HDROP))
	{
		return DROPEFFECT_COPY;
	}

	return DROPEFFECT_NONE;
}

BOOL CFloatingWndDropTarget::OnDrop(CWnd*, COleDataObject *pData, DROPEFFECT, CPoint)
{
	CLIPFORMAT cf;
	if (pData->IsDataAvailable (CF_TEXT))
		cf = CF_TEXT;
	else if (pData->IsDataAvailable (CF_HDROP))
		cf = CF_HDROP;
	else
		return FALSE;

	HGLOBAL hMem = pData->GetGlobalData (cf);
	if (hMem)
	{
		std::vector <fsString> vUrls;
		LPVOID pvLock = GlobalLock (hMem);

		if (cf == CF_TEXT)
		{
			LPCSTR pszUrl = (LPCSTR) pvLock;
			fsURL url;
			if (url.Crack (pszUrl) == IR_SUCCESS)
				vUrls.push_back (pszUrl);
		}
		else
		{
			HDROP hDrop = (HDROP) pvLock;
			int cFiles = DragQueryFile (hDrop, 0xFFFFFFFF, NULL, 0);
			for (int i = 0; i < cFiles; i++)
			{
				char szFile [MY_MAX_PATH];
				DragQueryFile (hDrop, i, szFile, sizeof (szFile));
				fsString strUrl = "file://";
				strUrl += szFile;
				vUrls.push_back (strUrl);
			}
		}
		
		if (vUrls.size ())
		{
			BOOL bSilent = _App.Monitor_Silent ();

			for (size_t i = 0; i < vUrls.size (); i++)
			{
				LPCSTR pszUrl = vUrls [i];
				BOOL bAdded = UINT_MAX != _pwndDownloads->CreateDownload (pszUrl, TRUE, NULL, NULL, bSilent);
				if (bAdded && bSilent)
					CMainFrame::ShowTimeoutBalloon (pszUrl, "Download added", NIIF_INFO, TRUE);
			}
		}

		GlobalUnlock (hMem);
		GlobalFree (hMem);

		if (vUrls.size ())
			return TRUE;
	}

	return FALSE;
}
