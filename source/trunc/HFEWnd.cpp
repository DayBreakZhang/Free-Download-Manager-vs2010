/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "HFEWnd.h"
#include "plugins.h"
#include "inetutil.h"
#include "plugincmds.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CHFEWnd* _pwndHFE = NULL;

CHFEWnd::CHFEWnd()
{
	m_mgr.SetEventsFunc (_EventsFunc, this);
	m_wndListLog.m_wndLog.SetEvMgr (&m_evMgr);
}

CHFEWnd::~CHFEWnd()
{
}

BEGIN_MESSAGE_MAP(CHFEWnd, CWnd)
	//{{AFX_MSG_MAP(CHFEWnd)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_SIZE()
	ON_COMMAND(ID_HFE_REFRESH, OnHfeRefresh)
	ON_COMMAND(ID_HFE_SETTINGS, OnHfeSettings)
	ON_COMMAND(ID_HFE_STOP, OnHfeStop)
	ON_COMMAND(ID_HFE_DOWNLOAD, OnHfeDownload)
	ON_COMMAND(ID_HFE_OPENFOLDER, OnHfeOpenfolder)
	ON_COMMAND(ID_HFE_PARENTFOLDER, OnHfeParentfolder)
	ON_COMMAND(ID_HFE_DISCONNECT, OnHfeDisconnect)
	ON_WM_SETFOCUS()
	//}}AFX_MSG_MAP

	
	ON_MESSAGE (WM_WGP_SHUTDOWN, OnAppExit)
	ON_MESSAGE (WM_WGP_READYTOSHUTDOWN, OnAppQueryExit)
	ON_MESSAGE (WM_WGP_UPDATE_MENUMAIN, OnUpdateMenu)
	ON_MESSAGE (WM_WGP_UPDATE_MENUVIEW, OnUpdateMenuView)
	ON_MESSAGE (WM_WGP_UPDATE_CMDITEM, OnUpdateToolBar)
	
	ON_COMMAND(WGP_MENU_VIEWSMPLITEM_CMDSTART+0, OnShowLog)

	ON_COMMAND_RANGE(ID_LISTOFFILES_1, ID_LISTOFFILES_3, OnFilesListShowCol)
	ON_COMMAND_RANGE(ID_LOG_1, ID_LOG_3, OnLogShowCol)
	
	
END_MESSAGE_MAP()

HWND CHFEWnd::Plugin_CreateMainWindow(HWND hParent)
{
	fsnew1 (_pwndHFE, CHFEWnd);

	_pwndHFE->Create (CWnd::FromHandle (hParent));

	return _pwndHFE->m_hWnd;
}

BOOL CHFEWnd::Create(CWnd *pParent)
{
	CRect rc (0, 0, 50, 50);

	if (FALSE == CWnd::Create (AfxRegisterWndClass (0, NULL,
		NULL, NULL), NULL, WS_CHILD | WS_VISIBLE, rc, pParent, 0x23121))
		return FALSE;

	return TRUE;
}

int CHFEWnd::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndUrl.Create (this))
		return -1;

	if (!m_wndListLog.Create (this))
		return -1;
		
	return 0;
}

void CHFEWnd::OnDestroy() 
{
	CWnd::OnDestroy();
	
	SAFE_DELETE (_pwndHFE);
}

LRESULT CHFEWnd::OnAppExit(WPARAM, LPARAM)
{
	m_mgr.SetEventsFunc (NULL, 0);
	m_mgr.Stop (FALSE);
	
	MSG msg;
	while (m_mgr.IsRunning ())
	{
		while (PeekMessage (&msg, NULL, 0, 0,  PM_REMOVE))
			DispatchMessage (&msg);
		
		Sleep (10);
	}

	int cMax = 100;

	while (PeekMessage (&msg, NULL, 0, 0,  PM_REMOVE))
	{
		DispatchMessage (&msg);
		if (--cMax == 0)
			break;
	}

	SaveAll (0xffffffff);

	return 0;
}

LRESULT CHFEWnd::OnAppQueryExit(WPARAM, LPARAM)
{
	return 0;
}

void CHFEWnd::OnSize(UINT , int cx, int cy) 
{
	if (cx && cy)
	{
		m_wndUrl.MoveWindow (0, 0, cx, 35);
		m_wndListLog.MoveWindow (0, 35, cx, cy - 35);
	}
}

fsInternetFileListMgr* CHFEWnd::GetMgr()
{
	return &m_mgr;
}

void CHFEWnd::_EventsFunc(fsInternetFileListMgr* mgr, fsInternetFileListMgrEvent ev, LPVOID lp)
{
	CHFEWnd* pThis = (CHFEWnd*) lp;

	fsDescEvent event;
	LPCSTR psz = NULL;
	CString str;

	switch (ev)
	{
		case FLME_CONNECTING:
			event.clrBg = CLR_INQUIRY;
			event.clrText = RGB (0, 0, 0);
			event.iImage = 0;
			psz = LS (L_CONNECTINGTOSERV);
			break;

		case FLME_TRYINGTOUSESITEMGRLOGIN:
			event.clrBg = CLR_INQUIRY;
			event.clrText = RGB (0, 0, 0);
			event.iImage = 0;
			psz = LS (L_TRYINGSITEMGR);
			break;

		case FLME_CONNECTED:
			event.clrBg = CLR_RESPONSE_S;
			event.clrText = RGB (0, 0, 0);
			event.iImage = 2;
			psz = LS (L_CONNSUCC);
			break;

		case FLME_GETTINGLIST:
			event.clrBg = CLR_INQUIRY;
			event.clrText = RGB (0, 0, 0);
			event.iImage = 0;
			psz = LS (L_RETRLIST);
			break;

		case FLME_DONE:
			event.clrBg = CLR_DONE;
			event.clrText = RGB (0, 0, 0);
			event.iImage = 1;
			psz = LS (L_DONE);
			break;

		case FLME_ERROR:
			event.clrBg = CLR_RESPONSE_E;
			event.clrText = RGB (0, 0, 0);
			event.iImage = 3;
			break;

		case FLME_PAUSE:
			event.clrBg = CLR_RESPONSE_S;
			event.clrText = RGB (0, 0, 0);
			event.iImage = 2;
			str.Format (LS (L_PAUSESECS), _App.RetriesTime () / 1000);
			psz = str;
			break;

		case FLME_STOPPED:
			event.clrBg = CLR_RESPONSE_E;
			event.clrText = RGB (0, 0, 0);
			event.iImage = 3;
			psz = LS (L_DLDSTOPPED);
			break;

		case FLME_CONNECTIONWASLOST_RESTORE:
			event.clrBg = CLR_RESPONSE_E;
			event.clrText = RGB (0, 0, 0);
			event.iImage = 3;
			psz = LS (L_CONNLOSTTRYINGTORESTORE);
			break;

		case FLME_HTTP_LISTREAD:
			event.clrBg = CLR_RESPONSE_S;
			event.clrText = RGB (0, 0, 0);
			event.iImage = 2;
			psz = LS (L_SUCCESS);
			break;

		case FLME_HTTP_STARTBUILDLIST:
			event.clrBg = CLR_INQUIRY;
			event.clrText = RGB (0, 0, 0);
			event.iImage = 0;
			psz = LS (L_BUILDINGLIST2);
			break;
	}

	if (ev == FLME_ERROR)	
	{
		char str [1000];
		*str = 0;
		
		
		fsIRToStr (mgr->GetLastError (), str, 1000);

		
		fsnew (event.pszEvent, char, strlen (str) + 1);
		strcpy (event.pszEvent, str);
		pThis->m_evMgr.add (&event);
		pThis->m_wndListLog.m_wndLog.AddRecord (&event);

		
		if (mgr->GetLastError () == IR_EXTERROR)
		{
			
			LPCSTR pszExtError = pThis->m_mgr.GetLastErrorDesc ();
			LPCSTR pszErr1 = pszExtError;
			LPCSTR pszErr2 = pszErr1;

			
			while (pszErr1)
			{
				
				pszErr1 = strstr (pszErr1, "\r\n");
				if (pszErr1)	
				{
					
					strncpy (str, pszErr2, pszErr1 - pszErr2);
					str [pszErr1 - pszErr2] = 0;
				}
				else
					strcpy (str, pszErr2);	
					
				
				fsnew (event.pszEvent, char, strlen (str) + 1);
				strcpy (event.pszEvent, str);
				pThis->m_evMgr.add (&event);
				pThis->m_wndListLog.m_wndLog.AddRecord (&event);

				if (pszErr1)
				{
					pszErr1 += 2;
					pszErr2 = pszErr1;
				}
			}
		}
	}
	else if (psz)
	{
		fsnew (event.pszEvent, char, strlen (psz) + 1);
		strcpy (event.pszEvent, psz);
		pThis->m_evMgr.add (&event);
		pThis->m_wndListLog.m_wndLog.AddRecord (&event);
	}

	
	if (ev == FLME_DONE || ev == FLME_DONE_FROM_CACHE || ev == FLME_STOPPED || ev == FLME_ERROR)
	{
		
		pThis->m_wndListLog.m_wndFileList.UpdateList ();
		pThis->m_wndUrl.UpdateUrl ();
	}
	else
	{
		
	}
}

LRESULT CHFEWnd::OnUpdateMenu(WPARAM, LPARAM lp)
{
	m_wndListLog.m_wndFileList.UpdateMenu (CMenu::FromHandle (*((HMENU*)lp)));
	return 0;
}

void CHFEWnd::OnHfeRefresh() 
{
	vmsAUTOLOCKSECTION (m_csGo);
	m_wndListLog.m_wndFileList.OnHfeRefresh ();	
}

void CHFEWnd::OnHfeSettings() 
{
	m_wndListLog.m_wndFileList.OnHfeSettings ();	
}

void CHFEWnd::OnHfeStop() 
{
	m_wndListLog.m_wndFileList.OnHfeStop ();	
}

void CHFEWnd::OnGo()
{
	CString strUrl = m_wndUrl.GetUrl ();
	vmsAUTOLOCKSECTION (m_csLastGoUrl);
	if (strUrl == m_strLastGoUrl)
		return;
	m_strLastGoUrl = strUrl;
	vmsAUTOLOCKSECTION_UNLOCK (m_csLastGoUrl);

	DWORD dw;
	CloseHandle (
		CreateThread (NULL, 0, _threadGoUrl, this, 0, &dw));

	m_wndListLog.m_wndFileList.SetFocus ();
}

DWORD WINAPI CHFEWnd::_threadGoUrl(LPVOID lp)
{
	CHFEWnd* pThis = (CHFEWnd*) lp;

	EnterCriticalSection (&pThis->m_csGo);

	EnterCriticalSection (&pThis->m_csLastGoUrl);
	CString strUrl = pThis->m_strLastGoUrl;
	LeaveCriticalSection (&pThis->m_csLastGoUrl);

	if (pThis->m_mgr.IsRunning ())
		pThis->m_mgr.Stop ();
 	pThis->m_mgr.GetList (strUrl, NULL, NULL);

	LeaveCriticalSection (&pThis->m_csGo);

	return 0;
}

void CHFEWnd::Plugin_GetToolBarInfo(wgTButtonInfo **ppButtons, int *pcButtons)
{
	static wgTButtonInfo btns [] = 
	{
		wgTButtonInfo (ID_HFE_DOWNLOAD, TBSTYLE_BUTTON, ""),
		wgTButtonInfo (ID_HFE_STOP, TBSTYLE_BUTTON, ""),
		wgTButtonInfo (ID_HFE_REFRESH, TBSTYLE_BUTTON, ""),
	};

	btns [0].pszToolTip = LS (L_DOWNLOADSELECTED);
	btns [1].pszToolTip = LS (L_STOP);
	btns [2].pszToolTip = LS (L_REFRESH);

	*ppButtons = btns;
	*pcButtons = sizeof (btns) / sizeof (wgTButtonInfo);
}

LRESULT CHFEWnd::OnUpdateToolBar(WPARAM wp, LPARAM)
{
	return m_wndListLog.m_wndFileList.OnUpdateToolBar (wp);
}

void CHFEWnd::OnHfeDownload() 
{
	m_wndListLog.m_wndFileList.OnHfeDownload ();	
}

void CHFEWnd::OnHfeOpenfolder() 
{
	m_wndListLog.m_wndFileList.OnHfeOpenfolder ();	
}

void CHFEWnd::OnHfeParentfolder() 
{
	m_wndListLog.m_wndFileList.OnHfeParentfolder ();	
}

void CHFEWnd::Plugin_GetMenuImages(fsSetImage **ppImages, int *pcImages)
{
	static fsSetImage images [] = 
	{
		fsSetImage (ID_HFE_DOWNLOAD, 0),
		fsSetImage (ID_HFE_STOP, 1),
		fsSetImage (ID_HFE_REFRESH, 2),
		fsSetImage (ID_HFE_SETTINGS, 3),
		fsSetImage (ID_HFE_OPENFOLDER, 4),
	};

	*ppImages = images;
	*pcImages = sizeof (images) / sizeof (fsSetImage);
}
void CHFEWnd::OnHfeDisconnect() 
{
	m_wndListLog.m_wndFileList.OnHfeDisconnect ();
}

void CHFEWnd::Plugin_GetMenuViewItems(wgMenuViewItem **ppItems, int * cItems)
{
	static wgMenuViewItem aItems [] = {
		wgMenuViewItem ("", &_pwndHFE->m_wndListLog.m_bShowLog),
	};

	aItems [0].pszName = LS (L_EXPLORERLOG);

	*ppItems = aItems;
	*cItems = sizeof (aItems) / sizeof (wgMenuViewItem);
}

void CHFEWnd::OnShowLog()
{
	m_wndListLog.ShowLog (m_wndListLog.m_bShowLog == FALSE);
}

void CHFEWnd::SaveAll(DWORD dwWhat)
{
	if (dwWhat & 2)
		m_wndListLog.SaveState ();
}

void CHFEWnd::Plugin_GetPluginNames(LPCSTR *ppszLong, LPCSTR *ppszShort)
{
	static CString strNameLong, strNameShort;
	strNameLong = LSNP (L_HFE);
	strNameShort = LSNP (L_EXPLORER);
	*ppszLong = strNameLong;
	*ppszShort = strNameShort;
}

void CHFEWnd::OnSetFocus(CWnd* pOldWnd) 
{
	CWnd::OnSetFocus(pOldWnd);
	m_wndUrl.m_wndUrl.SetFocus ();	
}

void CHFEWnd::Plugin_SetLanguage(wgLanguage, HMENU hMenuMain, HMENU hMenuView)
{
	CMenu *menu = CMenu::FromHandle (hMenuMain);
	_pwndHFE->m_wndListLog.m_wndFileList.ApplyLanguageToMenu (menu);
	_pwndHFE->m_wndListLog.ApplyLanguage ();
	_pwndHFE->m_wndUrl.ApplyLanguage ();
	_pwndHFE->ApplyLanguageToMenuView (CMenu::FromHandle (hMenuView));
}

void CHFEWnd::ApplyLanguageToMenuView(CMenu *menu)
{
	menu->ModifyMenu (0, MF_BYPOSITION | MF_STRING, 0, LS (L_LISTOFFILES));
	menu->ModifyMenu (1, MF_BYPOSITION | MF_STRING, 0, LS (L_EXPLORERLOG));

	UINT aCmds [] = {ID_LISTOFFILES_1, ID_LISTOFFILES_2, ID_LISTOFFILES_3, ID_LOG_1, ID_LOG_2, ID_LOG_3};
	LPCSTR apszCmds [] = {LS (L_FILENAME), LS (L_SIZE), LS (L_DATE), LS (L_TIME),
		LS (L_DATE), LS (L_INFORMATION)};
	
	for (int i = 0; i < sizeof (aCmds) / sizeof (UINT); i++)
		menu->ModifyMenu (aCmds [i], MF_BYCOMMAND|MF_STRING, aCmds [i], apszCmds [i]);
}

LRESULT CHFEWnd::OnUpdateMenuView(WPARAM, LPARAM lp)
{
	HMENU* pMenus = (HMENU*) lp;
	UpdateFilesListColMenu (CMenu::FromHandle (pMenus [0]));
	UpdateLogColMenu (CMenu::FromHandle (pMenus [1]));
	return 0;
}

void CHFEWnd::UpdateFilesListColMenu(CMenu *menu)
{
	BOOL bEn = m_wndListLog.m_wndFileList.GetHeaderCtrl ()->GetItemCount () > 1;
	for (int i = 0; i < 3; i++)
	{
		if (m_wndListLog.m_wndFileList.IsColumnShown (i))
		{
			menu->CheckMenuItem (ID_LISTOFFILES_1+i, MF_CHECKED);
			if (bEn == FALSE)
				menu->EnableMenuItem (ID_LISTOFFILES_1+i, MF_GRAYED);
		}
	}
}

void CHFEWnd::UpdateLogColMenu(CMenu *menu)
{
	BOOL bEn = m_wndListLog.m_wndLog.GetHeaderCtrl ()->GetItemCount () > 1;
	for (int i = 0; i < 3; i++)
	{
		if (m_wndListLog.m_wndLog.IsColumnShown (i))
		{
			menu->CheckMenuItem (ID_LOG_1+i, MF_CHECKED);
			if (bEn == FALSE)
				menu->EnableMenuItem (ID_LOG_1+i, MF_GRAYED);
		}
	}
}

void CHFEWnd::OnFilesListShowCol(UINT uCmd)
{
	int iCol = uCmd - ID_LISTOFFILES_1;
	m_wndListLog.m_wndFileList.ChangeColumnVisibility (iCol);
}

void CHFEWnd::OnLogShowCol(UINT uCmd)
{
	int iCol = uCmd - ID_LOG_1;
	m_wndListLog.m_wndLog.ChangeColumnVisibility (iCol);
}

void CHFEWnd::ClearHistory()
{
	m_wndUrl.ClearHistory ();
}

void CHFEWnd::LogFailedMessage(LPCSTR pszMsg)
{
	fsDescEvent event;
	event.clrBg = CLR_RESPONSE_E;
	event.clrText = RGB (0, 0, 0);
	event.iImage = 3;
	fsnew (event.pszEvent, char, lstrlen (pszMsg) + 1);
	lstrcpy (event.pszEvent, pszMsg);
	m_evMgr.add (&event);
	m_wndListLog.m_wndLog.AddRecord (&event);
}

HMENU CHFEWnd::Plugin_GetMainMenu()
{
	return LoadMenu (AfxGetInstanceHandle (), MAKEINTRESOURCE (IDM_HFE));
}

HMENU CHFEWnd::Plugin_GetViewMenu()
{
	return LoadMenu (AfxGetInstanceHandle (), MAKEINTRESOURCE (IDM_HFE_VIEW));
}
