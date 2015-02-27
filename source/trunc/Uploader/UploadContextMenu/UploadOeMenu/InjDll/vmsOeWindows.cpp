/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsOeWindows.h"

vmsOeWindows::vmsOeWindows()
{

}

vmsOeWindows::~vmsOeWindows()
{

}

BOOL vmsOeWindows::Initialize()
{
	
	m_hwndMain = FindWindow ("Outlook Express Browser Class", NULL);	
	if (m_hwndMain == NULL)
		return FALSE;
	

	
	m_hwndRebar = FindWindowEx (m_hwndMain, NULL, "SizableRebar", NULL);
	if (m_hwndRebar)
		m_hwndRebar = FindWindowEx (m_hwndRebar, NULL, "ReBarWindow32", NULL);
	

	
	m_hwndMessageList = FindWindowEx (m_hwndMain, NULL, "Outlook Express Message View", NULL);

	if (m_hwndMessageList)
		m_hwndMessageList = FindWindowEx (m_hwndMessageList, NULL, "Outlook Express Message List", NULL);

	if (m_hwndMessageList)
		m_hwndMessageList = FindWindowEx (m_hwndMessageList, NULL, "ATL:SysListView32", NULL);
	

	
	HWND m_hwndFoldersList = FindWindowEx (m_hwndMain, NULL, "Outlook Express Navigation Pane", NULL);

	if (m_hwndFoldersList)
		m_hwndFoldersList = FindWindowEx (m_hwndFoldersList, NULL, "Outlook Express Pane Frame", NULL);

	if (m_hwndFoldersList)
		m_hwndFoldersList = FindWindowEx (m_hwndFoldersList, NULL, "ThorTreeViewWndClass", NULL);

	if (m_hwndFoldersList)
		m_hwndFoldersList = FindWindowEx (m_hwndFoldersList, NULL, "SysTreeView32", NULL);
	

	return TRUE;
}
