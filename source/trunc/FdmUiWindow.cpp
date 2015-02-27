/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmUiWindow.h"

CFdmUiWindow::CFdmUiWindow(void)
{
	m_hWnd = NULL;
	m_hevWindowCreatedOrFailed = CreateEvent (NULL, TRUE, FALSE, NULL);
}

CFdmUiWindow::~CFdmUiWindow(void)
{
}

STDMETHODIMP CFdmUiWindow::get_Handle(ULONG* pVal)
{
	if (!pVal)
		return E_POINTER;

	*pVal = (ULONG)m_hWnd;

	return m_bWindowCreatedOrFailed ? S_OK : S_FALSE;
}

STDMETHODIMP CFdmUiWindow::WaitForWindowCreation(LONG uTimeoutMilliseconds)
{
	WaitForSingleObject (m_hevWindowCreatedOrFailed, (DWORD)uTimeoutMilliseconds);
	return m_hWnd ? S_OK : S_FALSE;
}

void CFdmUiWindow::setWindow(HWND hwnd)
{
	m_bWindowCreatedOrFailed = true;
	m_hWnd = hwnd;
	SetEvent (m_hevWindowCreatedOrFailed);
}
