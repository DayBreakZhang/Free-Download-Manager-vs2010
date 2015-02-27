/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_FSIECONTEXTMENUMGR_H__AFA1D7C8_15DB_4504_8070_5518A59CF257__INCLUDED_)
#define AFX_FSIECONTEXTMENUMGR_H__AFA1D7C8_15DB_4504_8070_5518A59CF257__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#define IEMENU_CONTEXT_DEFAULT		0x1
#define IEMENU_CONTEXT_IMAGE		0x2
#define IEMENU_CONTEXT_CONTROL		0x4
#define IEMENU_CONTEXT_TABLE		0x8
#define IEMENU_CONTEXT_SELECTEDTEXT	0x10
#define IEMENU_CONTEXT_LINK			0x20

class fsIEContextMenuMgr  
{
public:
	BOOL IsDLFlashVideoMenuPresent();
	static void DeleteAllFDMsIEMenus();
	BOOL IsDLSelectedMenuPresent();
	BOOL IsDLAllMenuPresent();
	
	BOOL AddIEMenus();
	
	BOOL DeleteIEMenus();
	
	BOOL IsIEMenusPresent();
	
	BOOL IsDLThisMenuPresent();
	
	BOOL IsDLPageMenuPresent();
	

	
	void ReadState();

	fsIEContextMenuMgr();
	virtual ~fsIEContextMenuMgr();

protected:
	
	
	
	
	BOOL AddContextMenu (LPCSTR pszMenuName, LPCSTR pszMenuUrl, DWORD dwContext = 0);
	
	BOOL DeleteContextMenu (LPCSTR pszMenuName);

	BOOL m_bDLPageMenu;	
	BOOL m_bDLThisMenu;	
	BOOL m_bDLAllMenu;	
	BOOL m_bDLSelectedMenu;	
	BOOL m_bDLFlashVideoMenu;

	
	BOOL IsContextMenuPresent (LPCSTR pszMenuName);
};

#endif 
