/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "vmsSkinMgr.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

vmsSkinMgr::vmsSkinMgr()
{
}

vmsSkinMgr::~vmsSkinMgr()
{

}

void vmsSkinMgr::Scan()
{
	m_vList.clear ();

	CString strSkinDir = "Skins";

	WIN32_FIND_DATA wfd;
	HANDLE hFind = FindFirstFile (strSkinDir + "\\*.*", &wfd);
	if (hFind == INVALID_HANDLE_VALUE)
		return;

	

	do 
	{
		if (wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
		{
			if (lstrcmp (wfd.cFileName, ".") && lstrcmp (wfd.cFileName, ".."))
			{
				
				Scan_TryFolder (strSkinDir + "\\" + wfd.cFileName);
			}
		}
	} 
	while (FindNextFile (hFind, &wfd));

	FindClose (hFind);
}

void vmsSkinMgr::Scan_TryFolder(LPCSTR pszFolder)
{
	CFile file;
	CString strIni = pszFolder;
	strIni += "\\skin.ini";

	if (GetFileAttributes (strIni) == DWORD (-1))
		return; 

	char szValues [30000] = "";
	GetPrivateProfileSection ("Skin", szValues, sizeof (szValues), strIni);
	if (*szValues == 0)
		return;

	vmsSkinInfo skin;
	skin.strSkinFolder = pszFolder;

	LPCSTR pszValue = szValues;

	while (*pszValue)
	{
		
		
		
		LPSTR pszVVal = const_cast<LPSTR>(strchr (pszValue, '='));
		*pszVVal = 0;
		pszVVal++;

		if (lstrcmpi (pszValue, "Name") == 0)
			skin.strName = pszVVal;

		else if (lstrcmpi (pszValue, "tbSizeX") == 0)
			skin.tbSizeX = atoi (pszVVal);

		else if (lstrcmpi (pszValue, "tbSizeY") == 0)
			skin.tbSizeY = atoi (pszVVal);

		else if (lstrcmpi (pszValue, "tbUseAlpha") == 0)
			skin.tbUseAlpha = lstrcmpi (pszVVal, "yes") == 0;

		else if (lstrcmpi (pszValue, "fdmBuild") == 0)
			skin.nFDMBuild = atoi (pszVVal);

		pszValue = pszVVal;
		while (*pszValue++);	
	}

	
	
	if (skin.nFDMBuild < 829 || skin.nFDMBuild > (int)vmsFdmAppMgr::getVersion ()->m_appVersion [2].dwVal)
		return;

	m_vList.add (skin);
}

void vmsSkinMgr::set_CurrentSkin(int iSkin)
{
	m_nCurrSkin = iSkin;
}

HBITMAP vmsSkinMgr::bmp_x(UINT nID, LPCSTR pszName)
{
	if ((m_dwFlags & SM_ALLOWBITMAPS) == 0)
		pszName = NULL;

	if (m_nCurrSkin == -1 || pszName == NULL)
		return (HBITMAP)
			LoadImage (m_hInst, MAKEINTRESOURCE (nID), IMAGE_BITMAP, 
				0, 0, LR_CREATEDIBSECTION);

	HBITMAP hbm = (HBITMAP) 
		LoadImage (NULL, m_vList [m_nCurrSkin].strSkinFolder + "\\" + pszName + ".bmp",
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

	return hbm ? hbm : bmp_x (nID, NULL);
}

HBITMAP vmsSkinMgr::bmp(UINT nID)
{
	

	static UINT aIDs [] = {
		IDB_BACK, IDB_BACK_D, IDB_CHECKS, IDB_DOWNLOADSTASKS_SEL,
		IDB_DOWNLOADSTASKS, IDB_DOWNLOADSINFO, IDB_FILELIST,
		IDB_FILELIST_SEL, IDB_GO, IDB_GROUPS, IDB_GROUPSMENU_D,
		IDB_GROUPSMENU, IDB_LOGSTATES, IDB_MUTE, IDB_SCHEDULER_SEL,
		IDB_SHEDULER, IDB_SITELIST, IDB_SITELIST_SEL,
		IDB_TOOL0, IDB_TOOL0_16, IDB_TOOL0_16_D, IDB_TOOL0_D,
		IDB_TOOL_DLDS, IDB_TOOL_DLDS_D, IDB_TOOL_DLD_16, IDB_TOOL_DLD_16_D,
		IDB_TOOL_BT, IDB_TOOL_BT_D, IDB_TOOL_BT_16, IDB_TOOL_BT_16_D,
		IDB_TOOL_HFE, IDB_TOOL_HFE_D, IDB_TOOL_HFE_16, IDB_TOOL_HFE_16_D,
		IDB_TOOL_SCHEDULE, IDB_TOOL_SCHEDULE_D, IDB_TOOL_SCH_16, IDB_TOOL_SCH_16_D,
		IDB_TOOL_SITES, IDB_TOOL_SITES_D, IDB_TOOL_SITES_16, IDB_TOOL_SITES_16_D,
		IDB_TOOL_SPIDER, IDB_TOOL_SPIDER_D, IDB_TOOL_SPIDER_16, IDB_TOOL_SPIDER_16_D,
		IDB_VIDMAN, IDB_VIDMAN_D
	};

	static LPCSTR ppszNames [] = {
		"back", "back_d", "checks", "dldtasks_sel", "dldtasks",
		"dlinfo", "filelist", "filelist_sel", "go", "groups",
		"groupsmenu_d", "groupsmenu", "logstat", "mute", 
		"scheduler_sel", "scheduler", "sitelist", "sitelist_sel",
		"tool0", "tool0_small", "tool0_small_d", "tool0_d",
		"tool_dld", "tool_dld_d", "tool_dld_small", "tool_dld_small_d",
        "tool_bt", "tool_bt_d", "tool_bt_small", "tool_bt_small_d",
		"tool_hfe",	"tool_hfe_d", "tool_hfe_small", "tool_hfe_small_d",
		"tool_sch", "tool_sch_d", "tool_sch_small", "tool_sch_small_d",
		"tool_sites", "tool_sites_d", "tool_sites_small", "tool_sites_small_d",
		"tool_spider", "tool_spider_d", "tool_spider_small", "tool_spider_small_d",
		"vidman", "vidman_d"		
	};

	ASSERT (sizeof (aIDs)/sizeof (UINT) == sizeof (ppszNames)/sizeof (LPCSTR));

	for (int i = 0; i < sizeof (aIDs) / sizeof (UINT); i++)
	{
		if (aIDs [i] == nID)
			return bmp_x (nID, ppszNames [i]);
	}

	
	return bmp_x (nID, NULL);
}

void vmsSkinMgr::Initialize()
{
	m_nCurrSkin = -1;
	m_hInst = AfxGetInstanceHandle ();
	m_dwFlags = _App.Skin_Flags ();
	Scan ();
	CString strSkin = _App.Skin_Current ();
	if (strSkin != "")
	{
		for (int i = 0; i < m_vList.size (); i++)
		{
			if (m_vList [i].strName.CompareNoCase (strSkin) == 0)
			{
				m_nCurrSkin = i;
				break;
			}
		}
	}
}

int vmsSkinMgr::tbSizeX()
{
	return m_nCurrSkin == -1 || (m_dwFlags & SM_ALLOWBITMAPS) == 0 ? 32 : m_vList [m_nCurrSkin].tbSizeX;
}

int vmsSkinMgr::tbSizeY()
{
	return m_nCurrSkin == -1 || (m_dwFlags & SM_ALLOWBITMAPS) == 0 ? 32 : m_vList [m_nCurrSkin].tbSizeY;
}

BOOL vmsSkinMgr::tbUseAlpha()
{
	return m_nCurrSkin == -1 || (m_dwFlags & SM_ALLOWBITMAPS) == 0 ? TRUE : m_vList [m_nCurrSkin].tbUseAlpha;
}

HICON vmsSkinMgr::icon(UINT nID, int cx, int cy)
{
	static UINT aIDs [] = {
		IDI_CHOOSEFOLDER, IDI_CREATEGROUP, IDI_LOGO2, IDI_LOGIN,
		IDI_SETTIME, IDI_TOSEL, IDI_TOUNSEL,
		IDI_TRAY, IDI_TRAY_DOWNLOADING, IDI_TRAY_ERRORS,IDI_TRAY_UNKNOWN,
		IDI_TEST_OK,
	};

	static LPCSTR ppszNames [] = {
		"choosefolder", "creategroup", "dropbox", "login", "settime",
		"tosel", "tounsel", 
		"tray",	"tray_down", "tray_err", "tray_starting",
		"check_ok",
	};

	ASSERT (sizeof (aIDs)/sizeof (UINT) == sizeof (ppszNames)/sizeof (LPCSTR));

	for (int i = 0; i < sizeof (aIDs) / sizeof (UINT); i++)
	{
		if (aIDs [i] == nID)
			return icon_x (nID, ppszNames [i], cx, cy);
	}

	return icon_x (nID, NULL, cx, cy);
}

HICON vmsSkinMgr::icon_x(UINT nID, LPCSTR pszName, int cx, int cy)
{
	if ((m_dwFlags & SM_ALLOWICONS) == 0)
		pszName = NULL;

	if (m_nCurrSkin == -1 || pszName == NULL)
		return (HICON)
			LoadIcon (m_hInst, MAKEINTRESOURCE (nID));
			

	HICON hico = (HICON) 
		LoadImage (NULL, m_vList [m_nCurrSkin].strSkinFolder + "\\" + pszName + ".ico",
			IMAGE_ICON, cx, cy, LR_LOADFROMFILE);

	return hico ? hico : icon_x (nID, NULL, cx, cy);
}

int vmsSkinMgr::get_Count()
{
	return m_vList.size ();
}

int vmsSkinMgr::get_Current()
{
	return m_nCurrSkin;
}

vmsSkinInfo* vmsSkinMgr::get_Skin(int iIndex)
{
	return &m_vList [iIndex];
}

BOOL vmsSkinMgr::tbUseAlpha_ForAllPluginMenuImages()
{
	return m_nCurrSkin != -1 && tbUseAlpha ();
}

COLORREF vmsSkinMgr::getLinkTextColor() const
{
	return GetSysColor (26);
}
