/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "FdmTorrentFilesRcvr.h"
#include "DownloadsWnd.h"
#include "UIThread.h"

STDMETHODIMP CFdmTorrentFilesRcvr::CreateBtDownload(BSTR bstrFile)
{
	USES_CONVERSION;

	if (Is9xME)
		return E_NOTIMPL;

	if (FALSE == vmsFdmAppMgr::MakeSureBtInstalled ())
		return S_FALSE;

	_inc_CBRFF_ctx *p = new _inc_CBRFF_ctx;

	p->strFile = W2A (bstrFile);
	p->strFileUrl = "file://"; p->strFileUrl += p->strFile;
	p->bForceSilent = m_bForceSilent;

	UIThread *thr = (UIThread*) RUNTIME_CLASS (UIThread)->CreateObject ();
	thr->set_Thread (_threadCreateBtDownload, p);
	thr->CreateThread ();

	return S_OK;
}

STDMETHODIMP CFdmTorrentFilesRcvr::get_ForceSilent(BOOL *pVal)
{
	*pVal = m_bForceSilent;
	return S_OK;
}

STDMETHODIMP CFdmTorrentFilesRcvr::put_ForceSilent(BOOL newVal)
{
	m_bForceSilent = newVal;
	return S_OK;
}

DWORD WINAPI CFdmTorrentFilesRcvr::_threadCreateBtDownload(LPVOID lp)
{
	_inc_CBRFF_ctx *p = (_inc_CBRFF_ctx*) lp;

	_pwndDownloads->CreateBtDownload (p->strFile, p->strFileUrl,
		p->bForceSilent ? TRUE : _App.Monitor_Silent ());

	delete p;

	return 0;
}
