/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FUM.h"
#include "FUMApplication.h"
#include "mainfrm.h"

STDMETHODIMP CFUMApplication::Shutdown(BOOL bAskUser)
{
	if (bAskUser)
		return E_NOTIMPL;

	AfxGetApp ()->m_pMainWnd->PostMessage (WM_COMMAND, ID_NEED_EXIT);

	return S_OK;
}
