/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "CFDM.h"
#include "MainFrm.h"

STDMETHODIMP CFDM::Shutdown(BOOL bAskUser)
{
	if (bAskUser)
		return E_NOTIMPL;

	AfxGetApp ()->m_pMainWnd->PostMessage (WM_COMMAND, ID_APP_EXIT_2);

	return S_OK;
}

