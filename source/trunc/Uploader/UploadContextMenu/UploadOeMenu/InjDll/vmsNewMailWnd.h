/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSNEWMAILWND_H__7E0A477E_1323_4AA6_B734_1FF1B4805237__INCLUDED_)
#define AFX_VMSNEWMAILWND_H__7E0A477E_1323_4AA6_B734_1FF1B4805237__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include <string>
#include <atlbase.h>
#include <vector>

class vmsNewMailWnd  
{
public:
	static void OnSettings();
	static void DetachFromWindow (HWND hwndNewMailWnd);
	static void OnUploadFolder(HWND hwndNewMailWnd);
	static BOOL InsertUploadUrlToMailText (HWND hwndNewMailWnd, LPCWSTR pwszPkgName, LPCWSTR pwszUrl);
	static std::wstring GetSubject (HWND hwndNewMailWnd);
	static BOOL InsertLinkToMailText (HWND hwndNewMailWnd, LPCWSTR pwszText, LPCWSTR pwszHref);
	static BOOL OnBeforeSendMail (HWND hwndNewMailWnd);
	static void OnUploadFiles (HWND hwndNewMailWnd);
	static HWND FindToolbarWindow (HWND hwndNewMailWnd);
	static bool InitializeWindow (HWND hwndNewMailWnd);
	static bool AttachToWindow (HWND hwndNewMailWnd);
	static HWND FindMailTextWindow (HWND hwndNewMailWnd);
	static bool ClearAttachmentsList (HWND hwndNewMailWnd);
	static HWND FindAttachmentsListView (HWND hwndNewMailWnd);
	static LRESULT WINAPI _WindowProcedure (HWND hwnd, UINT msg, WPARAM wp, LPARAM lp);
	static WNDPROC	_m_pfnOrigWndProc;
	static CRegKey	_m_keySettings;
	static HMENU	_m_menuAttachFiles;

	vmsNewMailWnd();
	virtual ~vmsNewMailWnd();

protected:
	static void CreateContextMenu();
	
};

#endif 
