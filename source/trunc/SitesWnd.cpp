/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "plugins.h"
#include "FdmApp.h"
#include "SitesWnd.h"
#include "fsSitesMgr.h"
#include "MainFrm.h"
#include "SitesSheet.h"
#include "DownloadsWnd.h"
#include "mfchelp.h"
#include "plugincmds.h"
#include "vmsLogger.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define WM_SW_SITESMGR_EVENT			(WM_APP+1000)

extern CDownloadsWnd *_pwndDownloads;

CSitesWnd *_pwndSites = NULL;

CSitesWnd::CSitesWnd()
{
	_SitesMgr.SetEventsFunc (_SitesMgrEvents, this);
}

CSitesWnd::~CSitesWnd()
{
}

BEGIN_MESSAGE_MAP(CSitesWnd, CListCtrlEx)
	//{{AFX_MSG_MAP(CSitesWnd)
	ON_WM_RBUTTONDOWN()
	ON_WM_DRAWITEM()
	ON_WM_MEASUREITEM()
	ON_COMMAND(ID_SITES_DELETE, OnSitesDelete)
	ON_COMMAND(ID_SITES_PROPERTIES, OnSitesProperties)
	ON_COMMAND(ID_SITES_TEMPRORARY, OnSitesTemprorary)
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_SITES_ADD, OnSitesAdd)
	//}}AFX_MSG_MAP

	
	ON_MESSAGE (WM_WGP_SHUTDOWN, OnAppExit)
	ON_MESSAGE (WM_WGP_READYTOSHUTDOWN, OnAppQueryExit)
	ON_MESSAGE (WM_WGP_UPDATE_MENUMAIN, OnUpdateMenu)
	ON_MESSAGE (WM_WGP_UPDATE_MENUVIEW, OnUpdateMenuView)
	ON_MESSAGE (WM_WGP_UPDATE_CMDITEM, OnUpdateToolBar)
	ON_MESSAGE (WM_WGP_INSERT, OnInsert)

	ON_COMMAND_RANGE(ID_SITES_1, ID_SITES_4, OnSitesListShowCol)
	
	ON_WM_DESTROY()
	ON_MESSAGE (WM_SW_SITESMGR_EVENT, OnSwSitesMgrEvent)
END_MESSAGE_MAP()

BOOL CSitesWnd::Create(CWnd *pWndParent)
{
	CRect rc (0, 0, 50, 50);

	if (FALSE == CListCtrlEx::Create (LVS_REPORT|LVS_OWNERDRAWFIXED|LVS_NOSORTHEADER|LVS_SHOWSELALWAYS,
									  rc, pWndParent, 0x53459))
		return FALSE;

	SetExtendedStyle (LVS_EX_FULLROWSELECT|LVS_EX_HEADERDRAGDROP|LVS_EX_INFOTIP);

	

	m_images.Create (16, 17, ILC_COLOR24 | ILC_MASK, 4, 1);
	CBitmap bmp;
	bmp.Attach (SBMP (IDB_SITELIST));
	m_images.Add (&bmp, RGB (255, 0, 255));
	SetImageList (&m_images, LVSIL_SMALL);

	m_selImages.Create (16, 17, ILC_COLOR24 | ILC_MASK, 4, 1);
	CBitmap bmp1;
	bmp1.Attach (SBMP (IDB_SITELIST_SEL));
	m_selImages.Add (&bmp1, RGB (255, 0, 255));
	SetSelectedImages (&m_selImages);

	InsertColumn (0, LS (L_SITENAME), LVCFMT_LEFT, 200, 0);
	InsertColumn (1, LS (L_CONNS), LVCFMT_LEFT, 80, 0);
	InsertColumn (2, LS (L_LOGIN), LVCFMT_LEFT, 100, 0);
	InsertColumn (3, LS (L_GROUP2), LVCFMT_LEFT, 100, 0);

	ReadState ("SitesList");

	ShowWindow (SW_SHOW);

	LoadSites ();

	return TRUE;
}

HWND CSitesWnd::Plugin_CreateMainWindow(HWND hWndParent)
{
	fsnew1 (_pwndSites, CSitesWnd);

	_pwndSites->Create (CWnd::FromHandle (hWndParent));

	return _pwndSites->m_hWnd;
}

void CSitesWnd::Plugin_GetToolBarInfo(wgTButtonInfo **ppButtons, int *pcButtons)
{
	static wgTButtonInfo btns [] = 
	{
		wgTButtonInfo (ID_SITES_ADD, TBSTYLE_BUTTON, ""),
		wgTButtonInfo (ID_SITES_PROPERTIES, TBSTYLE_BUTTON, ""),
	};

	btns [0].pszToolTip = LS (L_ADDSITE);
	btns [1].pszToolTip = LS (L_SITEPROP);

	*ppButtons = btns;
	*pcButtons = sizeof (btns) / sizeof (wgTButtonInfo);
}

void CSitesWnd::Plugin_GetMenuImages(fsSetImage **ppImages, int *pcImages)
{
	static fsSetImage images [] = 
	{
		fsSetImage (ID_SITES_ADD, 0),
		fsSetImage (ID_SITES_PROPERTIES, 1),
		fsSetImage (ID_SITES_DELETE, 2),
	};

	*ppImages = images;
	*pcImages = sizeof (images) / sizeof (fsSetImage);
}

LRESULT CSitesWnd::OnAppExit(WPARAM, LPARAM)
{
	SaveAll (0xffffffff);
	return 0;
}

LRESULT CSitesWnd::OnAppQueryExit(WPARAM, LPARAM)
{
	return 0;
}

LRESULT CSitesWnd::OnUpdateMenu(WPARAM, LPARAM lp)
{
	UpdateMenu (CMenu::FromHandle (*((HMENU*)lp)));
	return 0;
}

LRESULT CSitesWnd::OnUpdateToolBar(WPARAM wp, LPARAM)
{
	return UpdateToolBar (wp);
}

void CSitesWnd::UpdateMenu(CMenu *pMenu)
{
	int cSelected = GetSelectedCount ();

	if (cSelected == 0)
	{
		pMenu->EnableMenuItem (ID_SITES_DELETE, MF_BYCOMMAND | MF_GRAYED);
		pMenu->EnableMenuItem (ID_SITES_TEMPRORARY, MF_BYCOMMAND | MF_GRAYED);
	}
	else
	{
		POSITION pos = GetFirstSelectedItemPosition ();
		m_bSelectedIsTemp = TRUE;
		while (pos)
		{
			int iItem = GetNextSelectedItem (pos);
			fsSiteInfo *pSite = (fsSiteInfo*) GetItemData (iItem);
			if (pSite->bTemp == FALSE)
			{
				m_bSelectedIsTemp = FALSE;
				break;
			}
		}

		if (m_bSelectedIsTemp)
			pMenu->CheckMenuItem (ID_SITES_TEMPRORARY, MF_BYCOMMAND | MF_CHECKED);
	}

	if (cSelected != 1)
		pMenu->EnableMenuItem (ID_SITES_PROPERTIES, MF_BYCOMMAND | MF_GRAYED);

	pMenu->SetDefaultItem (ID_SITES_PROPERTIES);
}

int CSitesWnd::UpdateToolBar(UINT nID)
{
	BOOL bEnabled = TRUE;
	int cSelected = GetSelectedCount ();

	switch (nID)
	{
		case ID_SITES_ADD:
			break;

		case ID_SITES_DELETE:
		case ID_SITES_TEMPRORARY:
			bEnabled = cSelected > 0;
			break;

		case ID_SITES_PROPERTIES:
			bEnabled = cSelected == 1;
			break;
	}

	return bEnabled ? WGP_CMDITEMSTATE_ENABLED : WGP_CMDITEMSTATE_DISABLED;
}

void CSitesWnd::OnRClick()
{
	CMenu menu;
	menu.LoadMenu (IDM_SITES);
	ApplyLanguageToMenu (&menu);
	CMenu *pPopup = menu.GetSubMenu (0);

	UpdateMenu (pPopup);

	ClientToScreen (&m_rbPt);

	m_odmenu.Attach (&menu, FALSE);

	m_odmenu.SetImageList (&((CMainFrame*)AfxGetApp ()->m_pMainWnd)->m_imgsMenu, &((CMainFrame*)AfxGetApp ()->m_pMainWnd)->m_dimgsMenu);
	fsSetImage *pImages;
	int cImages;
	CSitesWnd::Plugin_GetMenuImages (&pImages, &cImages);
	m_odmenu.SetImages (pImages, cImages);

	pPopup->TrackPopupMenu (TPM_RIGHTBUTTON | TPM_TOPALIGN | TPM_LEFTALIGN,	m_rbPt.x, m_rbPt.y, this);
	m_odmenu.Detach ();

	menu.DestroyMenu ();
}

void CSitesWnd::OnRButtonDown(UINT nFlags, CPoint point) 
{
	m_rbPt = point;
	CListCtrlEx::OnRButtonDown(nFlags, point);
}

void CSitesWnd::OnDrawItem(int , LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	m_odmenu.OnDrawItem (lpDrawItemStruct);
}

void CSitesWnd::OnMeasureItem(int , LPMEASUREITEMSTRUCT lpMeasureItemStruct) 
{
	m_odmenu.OnMeasureItem (lpMeasureItemStruct);
}

void CSitesWnd::OnSitesAdd() 
{
	fsSiteInfoPtr site; site.CreateInstance ();

	site->dwFtpFlags = 0;
	site->bTemp = FALSE;
	site->cMaxConns = UINT_MAX;
	site->strName = NULL;
	site->strPassword = NULL;
	site->strUser = NULL;
	site->cConnsNow = 0;
	site->dwValidFor = SITE_VALIDFOR_HTTP | SITE_VALIDFOR_HTTPS | SITE_VALIDFOR_FTP | SITE_VALIDFOR_SUBDOMAINS;

	CSitesSheet sheet (LS (L_ADDSITE), this);
	sheet.SetMode(true);
	_DlgMgr.OnDoModal (&sheet);
	sheet.Init (site);
	UINT nRet = sheet.DoModal ();
	_DlgMgr.OnEndDialog (&sheet);

	if (nRet == IDOK)
	{
		_SitesMgr.AddSite (site);
	}

	SetFocus ();
}

void CSitesWnd::OnSitesDelete() 
{
	fs::list <int> vItems;
	POSITION pos = GetFirstSelectedItemPosition ();

	if (pos == NULL)
		return;

	if (IDNO == MessageBox (LS (L_AREYOUSURE), LS (L_CONFIRMATION), MB_YESNO))
	{
		SetFocus ();
		return;
	}

	SetFocus ();

	pos = GetFirstSelectedItemPosition ();

	while (pos)
	{
		int iItem = GetNextSelectedItem (pos);
		vItems.add (iItem);
	}

	if (vItems.size () == 0)
		return;

	for (int i = vItems.size () - 1; i >= 0; i--)
	{
		fsSiteInfo *pSite = (fsSiteInfo*) GetItemData (vItems [i]);
		_SitesMgr.DeleteSite (pSite);
	}
}

void CSitesWnd::OnSitesProperties() 
{
	POSITION pos = GetFirstSelectedItemPosition ();
	if (pos == NULL) return;
	int iItem = GetNextSelectedItem (pos);
	fsSiteInfo *pSite = (fsSiteInfo*) GetItemData (iItem);

	CSitesSheet sheet (LS (L_SITEPROP), this);
	sheet.SetMode(false);
	_DlgMgr.OnDoModal (&sheet);
	sheet.Init (pSite);
	UINT nRet = sheet.DoModal ();
	_DlgMgr.OnEndDialog (&sheet);

	SetFocus ();

	if (nRet == IDOK)
		UpdateSite (pSite);
}

void CSitesWnd::OnSitesTemprorary() 
{
	POSITION pos = GetFirstSelectedItemPosition ();
	while (pos)
	{
		int iItem = GetNextSelectedItem (pos);
		fsSiteInfo *pSite = (fsSiteInfo*) GetItemData (iItem);
		pSite->bTemp = !m_bSelectedIsTemp;
		_SitesMgr.setDirty();
		UpdateSite (pSite);
	}
}

void CSitesWnd::AddSiteToList(fsSiteInfo *pSite)
{
	int iItem = AddItem ("", GetSysColor (COLOR_WINDOW), GetSysColor (COLOR_WINDOWTEXT));
	SetItemData (iItem, (DWORD)pSite);
	UpdateSite (pSite);
}

void CSitesWnd::UpdateSite(fsSiteInfo *pSite)
{
	LVFINDINFO fi;
	fi.flags = LVFI_PARAM;
	fi.lParam = (LPARAM)pSite;
	int iItem = FindItem (&fi);
	if (iItem == -1)
		return;

	SetItemText (iItem, 0, pSite->strName);

	CString str, strConn;
	if (pSite->cMaxConns != UINT_MAX)
		str.Format ("%d", pSite->cMaxConns);
	else
		str = "+";
	strConn.Format ("%d/%s", pSite->cConnsNow, str);
	SetItemText (iItem, 1, strConn);

	SetItemText (iItem, 2, pSite->strUser == NULL ? "" : pSite->strUser);

	if (pSite->pGroup)
	{
		if (pSite->pGroup->nId == GRP_OTHER_ID)
			SetItemText (iItem, 3, LS (L_OTHER));
		else
			SetItemText (iItem, 3, pSite->pGroup->strName);
	}
	else
		SetItemText (iItem, 3, "");

	SetItemImage (iItem, pSite->bTemp ? 1 : 0);
}

void CSitesWnd::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	CListCtrlEx::OnLButtonDblClk(nFlags, point);
	OnSitesProperties ();
}

void CSitesWnd::_SitesMgrEvents(fsSitesMgrEvent ev, fsSiteInfo *site, LPVOID lp)
{
	CSitesWnd *pThis = (CSitesWnd*) lp;

	SwSitesMgrEventParam *p = new SwSitesMgrEventParam;
	p->ev = ev;
	p->site = site;

	pThis->PostMessage (WM_SW_SITESMGR_EVENT, 0, (LPARAM)p);
}

void CSitesWnd::LoadSites()
{
	CString strFile = fsGetDataFilePath ("sites.sav");

	if (GetFileAttributes (strFile) == DWORD (-1))
	{
		_DldsMgr.RebuildServerList ();
		return;
	}

	HANDLE hFile = CreateFile (strFile, GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);

	if (hFile == INVALID_HANDLE_VALUE) {
		_DldsMgr.RebuildServerList ();
		return;
	}

	try 
	{
		fsSitesFileHdr hdr;
		DWORD dw = 0;
		DWORD dwRequiredSize = ::GetFileSize(hFile, 0);
		BOOL bOldVer = FALSE;

		if (!ReadFile (hFile, &hdr, sizeof (hdr), &dw, NULL)) {
			bOldVer = TRUE;
		} 
		
		if (!bOldVer) {
			if (strcmp (hdr.szSig, SITESFILE_SIG)) {
				bOldVer = TRUE;
			} else if (hdr.wVer > SITESFILE_CURRENT_VERSION) {
				CloseHandle (hFile);
				_DldsMgr.RebuildServerList ();
				return;
			} else if (hdr.wVer < 3) {
				bOldVer = TRUE;
			}
		}

		if (bOldVer) {

			if (!SetFilePointer (hFile, 0, NULL, FILE_BEGIN)) {
				CloseHandle (hFile);
				_DldsMgr.RebuildServerList ();
				return;
			}

			_SitesMgr.LoadFromFile(hFile);
		} 
		else 
		{
			dwRequiredSize -= sizeof(hdr);

			std::auto_ptr<BYTE> pbtBufferGuard( new BYTE[dwRequiredSize] );
			LPBYTE pbtBuffer = pbtBufferGuard.get();
			if (pbtBuffer == 0) {
				CloseHandle (hFile);
				_DldsMgr.RebuildServerList ();
				return;
			}
			memset(pbtBuffer, 0, dwRequiredSize);

			if (!ReadFile (hFile, pbtBuffer, dwRequiredSize, &dw, NULL) || dw != dwRequiredSize) {
				CloseHandle (hFile);
				_DldsMgr.RebuildServerList ();
				return;
			}

			if (!_SitesMgr.loadFromStateBuffer(pbtBuffer, &dwRequiredSize, hdr.wVer)) {
				CloseHandle (hFile);
				_DldsMgr.RebuildServerList ();
				return;
			}
		}

		CloseHandle (hFile);
		_SitesMgr.resetDirty();

	} 
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("CSitesWnd::LoadSites " + tstring(ex.what()));
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("CSitesWnd::LoadSites unknown exception");
	}

	_DldsMgr.RebuildServerList ();
}

void CSitesWnd::SaveSites()
{
	if (!_SitesMgr.isDirty())
		return;

	CString strFile = fsGetDataFilePath ("sites.sav");

	HANDLE hFile = CreateFile (strFile, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS,
		FILE_ATTRIBUTE_HIDDEN, NULL);

	if (hFile == INVALID_HANDLE_VALUE)
		return;

	DWORD dw;
	fsSitesFileHdr hdr;
	DWORD dwRequiredSize = 0;

	if (!WriteFile (hFile, &hdr, sizeof (hdr), &dw, NULL)) {
		CloseHandle (hFile);
		return;
	}

	_SitesMgr.getStateBuffer(0, &dwRequiredSize, false);

	if (dwRequiredSize == 0)
		return;

	std::auto_ptr<BYTE> apbtBufferGuard( new BYTE[dwRequiredSize] );
	LPBYTE pbtBuffer = apbtBufferGuard.get();
	if (pbtBuffer == 0)
		return;
	memset(pbtBuffer, 0, dwRequiredSize);

	_SitesMgr.getStateBuffer(pbtBuffer, &dwRequiredSize, true);

	if (FALSE == WriteFile (hFile, pbtBuffer, dwRequiredSize, &dw, NULL) || dw != dwRequiredSize) {
		CloseHandle (hFile);
		return;
	}
	CloseHandle (hFile);
	_SitesMgr.onStateSavedSuccessfully();
}

void CSitesWnd::Plugin_GetMenuViewItems(wgMenuViewItem **ppItems, int* )
{
	*ppItems = NULL;
}

void CSitesWnd::SaveAll(DWORD dwWhat)
{
	if (dwWhat & 1)
		SaveSites ();
	if (dwWhat & 2)
		SaveState ("SitesList");
}

void CSitesWnd::Plugin_GetPluginNames(LPCSTR *ppszLong, LPCSTR *ppszShort)
{
	static CString strName;
	strName = LSNP (L_SITESMGR);
	*ppszLong = *ppszShort = strName;
}

void CSitesWnd::ApplyLanguageToMenu(CMenu* menu)
{
	menu->ModifyMenu (0, MF_BYPOSITION|MF_STRING, 0, LS (L_SITESMGR));
	
	CString str = LS (L_ADDSITE); str += "\tCtrl+I";
	menu->ModifyMenu (ID_SITES_ADD, MF_BYCOMMAND|MF_STRING, ID_SITES_ADD, str);
	
	str = LS (L_DELETESITE); str += "\tDel";
	menu->ModifyMenu (ID_SITES_DELETE, MF_BYCOMMAND|MF_STRING, ID_SITES_DELETE, str);

	menu->ModifyMenu (ID_SITES_TEMPRORARY, MF_BYCOMMAND|MF_STRING, ID_SITES_TEMPRORARY, LS (L_TEMPENTRY));

	str = LS (L_SITEPROP); str += "\tEnter";
	menu->ModifyMenu (ID_SITES_PROPERTIES, MF_BYCOMMAND|MF_STRING, ID_SITES_PROPERTIES, str);
}

void CSitesWnd::OnKeyDown(WORD wVK)
{
	switch (wVK)
	{
		case VK_DELETE:
			OnSitesDelete ();
		break;

		case VK_RETURN:
			OnSitesProperties ();
		break;

		case VK_APPS:
			CalcCoordsForCurSel ();
			OnRClick ();
		break;
	}
}

void CSitesWnd::ApplyLanguage()
{
	SetColumnText (0, LS (L_SITENAME));
	SetColumnText (1, LS (L_CONNS));
	SetColumnText (2, LS (L_LOGIN));
	SetColumnText (3, LS (L_GROUP2));
}

void CSitesWnd::CalcCoordsForCurSel()
{
	int iCurSel = GetSelectionMark ();
	if (iCurSel == -1)
	{
		POSITION pos = GetFirstSelectedItemPosition ();
		if (pos)
			iCurSel = GetNextSelectedItem (pos);
	}

	if (iCurSel != -1)
	{
		RECT rc;
		GetItemRect (iCurSel, &rc, LVIR_BOUNDS);
		m_rbPt.x = rc.left + 30;
		m_rbPt.y = rc.top;
	}
	else
		m_rbPt.x = m_rbPt.y = 30;
}

void CSitesWnd::Plugin_SetLanguage(wgLanguage, HMENU hMenuMain, HMENU hMenuView)
{
	CMenu *menu = CMenu::FromHandle (hMenuMain);
	_pwndSites->ApplyLanguageToMenu (menu);
	_pwndSites->ApplyLanguage ();
	_pwndSites->ApplyLanguageToMenuView (CMenu::FromHandle (hMenuView));
}

void CSitesWnd::OnForceUpdate()
{
	DeleteAllItems ();
	vmsCriticalSectionAutoLock csal;
	_SitesMgr.LockList (csal);
	int cSites = _SitesMgr.GetSiteCount ();
	for (int i = 0; i < cSites; i++)
		AddSiteToList (_SitesMgr.GetSite (i));
}

void CSitesWnd::ApplyLanguageToMenuView(CMenu *menu)
{
	menu->ModifyMenu (0, MF_BYPOSITION | MF_STRING, 0, LS (L_LISTOFSITES));

	UINT aCmds [] = {ID_SITES_1, ID_SITES_2, ID_SITES_3, ID_SITES_4};
	LPCSTR apszCmds [] = {LS (L_SITENAME), LS (L_CONNS), LS (L_LOGIN), LS (L_GROUP2)};
	
	for (int i = 0; i < sizeof (aCmds) / sizeof (UINT); i++)
		menu->ModifyMenu (aCmds [i], MF_BYCOMMAND|MF_STRING, aCmds [i], apszCmds [i]);
}

LRESULT CSitesWnd::OnUpdateMenuView(WPARAM, LPARAM lp)
{
	HMENU* pMenus = (HMENU*) lp;
	UpdateSitesListColMenu (CMenu::FromHandle (pMenus [0]));
	return 0;
}

void CSitesWnd::UpdateSitesListColMenu(CMenu *menu)
{
	BOOL bEn = GetHeaderCtrl ()->GetItemCount () > 1;
	for (int i = 0; i < 4; i++)
	{
		if (IsColumnShown (i))
		{
			menu->CheckMenuItem (ID_SITES_1+i, MF_CHECKED);
			if (bEn == FALSE)
				menu->EnableMenuItem (ID_SITES_1+i, MF_GRAYED);
		}
	}
}

void CSitesWnd::OnSitesListShowCol(UINT uCmd)
{
	int iCol = uCmd - ID_SITES_1;
	ChangeColumnVisibility (iCol);
}

LRESULT CSitesWnd::OnInsert(WPARAM, LPARAM)
{
	OnSitesAdd ();
	return 0;
}

HMENU CSitesWnd::Plugin_GetMainMenu()
{
	return LoadMenu (AfxGetInstanceHandle (), MAKEINTRESOURCE (IDM_SITES));
}

HMENU CSitesWnd::Plugin_GetViewMenu()
{
	return LoadMenu (AfxGetInstanceHandle (), MAKEINTRESOURCE (IDM_SITES_VIEW));
}

void CSitesWnd::OnDestroy()
{
	CListCtrlEx::OnDestroy();

	SAFE_DELETE (_pwndSites);
}

LRESULT CSitesWnd::OnSwSitesMgrEvent(WPARAM wp, LPARAM lp)
{
	SwSitesMgrEventParam *param = (SwSitesMgrEventParam*)lp;
	assert (param != NULL);
	if (!param)
		return 0;
	onEvents (param->ev, param->site);
	delete param;
	return 0;
}

void CSitesWnd::onEvents (fsSitesMgrEvent ev, fsSiteInfo *site)
{
	switch (ev)
	{
	case SM_SITEADDED:
		AddSiteToList (site);
		break;

	case SM_SITEDELETED:
		{
			LVFINDINFO fi;
			fi.flags = LVFI_PARAM;
			fi.lParam = (LPARAM)site;
			int iItem = FindItem (&fi);
			if (iItem != -1)
				DeleteItem (iItem);
		}
		break;

	case SM_SITEUPDATED:
		UpdateSite (site);
		break;
	}
}