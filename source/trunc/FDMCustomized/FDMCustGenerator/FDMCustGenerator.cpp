/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsFDMCustomized.h"

#define FDMCSAPI WINAPI
typedef long FDMCS_SESSION;

#define FDMCS_FREE			0
#define FDMCS_STANDARD		1
#define FDMCS_PROFESSIONAL	2

#define FDMCS_NO			0
#define FDMCS_OPT_IN		1
#define FDMCS_OPT_OUT		2
#define FDMCS_YES			3

#define USE_FDMCS_SESSION(dstname, srcname) vmsFDMCustomized* dstname = (vmsFDMCustomized*) srcname;
#define FDMCS_BUILDTYPE_DENIED(pSession, type) if (pSession->get_BuildType () == type) return;

HANDLE _hModule = NULL;

BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
	if (ul_reason_for_call == DLL_PROCESS_ATTACH)
		_hModule = hModule;

    return TRUE;
}

FDMCS_SESSION FDMCSAPI fdmcsCreateSession (int iEdition)
{
	vmsFDMCustomized* pSession = new vmsFDMCustomized;

	pSession->set_BuildType ((vmsFDMCSBuildType)iEdition);

	return (FDMCS_SESSION) pSession;
}

void FDMCSAPI fdmcsCloseSession (FDMCS_SESSION pS)
{
	USE_FDMCS_SESSION (pSession, pS);
	delete pSession;
}

void FDMCSAPI fdmcsSet_PrimaryID (FDMCS_SESSION pS, int iID)
{
	USE_FDMCS_SESSION (pSession, pS);
	pSession->set_AffiliateID (iID);
}

void FDMCSAPI fdmcsSet_SiteURL (FDMCS_SESSION pS, LPCSTR pszURL)
{
	USE_FDMCS_SESSION (pSession, pS);
	pSession->set_Customizer_SiteURL (pszURL);
}

void FDMCSAPI fdmcsSet_SiteTitle (FDMCS_SESSION pS, LPCSTR pszTitle)
{
	USE_FDMCS_SESSION (pSession, pS);
	pSession->set_Customizer (pszTitle);
}

void FDMCSAPI fdmcsSet_SiteIcon (FDMCS_SESSION pS, LPCSTR pszIcon)
{
	USE_FDMCS_SESSION (pSession, pS);
	pSession->set_Customizer_SiteIconFile (pszIcon);
}

void FDMCSAPI fdmcsSet_Button (FDMCS_SESSION pS, BOOL bShowButton,
			LPCSTR pszIcon, LPCSTR pszText, LPCSTR pszURL)
{
	USE_FDMCS_SESSION (pSession, pS);
	
	pSession->set_UseButton (bShowButton);
	
	if (bShowButton)
	{
		pSession->get_ButtonInfo ()->strText = pszText;
		pSession->get_ButtonInfo ()->strURL  = pszURL;
		pSession->get_ButtonInfo ()->strIcon = pszIcon;
	}
}

void FDMCSAPI fdmcsSet_SetHomePage (FDMCS_SESSION pS, int iSet)
{
	USE_FDMCS_SESSION (pSession, pS);

	DWORD dwSet;

	switch (iSet)
	{
	case FDMCS_NO:
		dwSet = 0;
		break;

	case FDMCS_OPT_IN:
		dwSet = FC_MODIFYHOMEPAGE;
		break;

	case FDMCS_YES:
	case FDMCS_OPT_OUT:
		dwSet = FC_MODIFYHOMEPAGE | FC_MHP_CHECKEDBYDEF;
		break;

	default:
		return;
	}

	pSession->modify_Flags (FC_MODIFYHOMEPAGE, dwSet);
}

void FDMCSAPI fdmcsSet_AddLinkToFavorites (FDMCS_SESSION pS, int iSet)
{
	USE_FDMCS_SESSION (pSession, pS);

	DWORD dwSet;

	switch (iSet)
	{
	case FDMCS_NO:
		dwSet = 0;
		break;

	case FDMCS_YES:
		dwSet = FC_ADDLINKTOFAVOR;
		break;

	case FDMCS_OPT_IN:
		dwSet = FC_ADDLINKTOFAVOR | FC_FAV_OPTIONAL;
		break;

	case FDMCS_OPT_OUT:
		dwSet = FC_ADDLINKTOFAVOR | FC_FAV_OPTIONAL | FC_FAV_CHECKEDBYDEF;
		break;

	default:
		return;
	}

	pSession->modify_Flags (FC_ADDLINKTOFAVOR, dwSet);
}

void FDMCSAPI fdmcsSet_AddLinkToStartMenu (FDMCS_SESSION pS, int iSet)
{
	USE_FDMCS_SESSION (pSession, pS);

	DWORD dwSet;

	switch (iSet)
	{
	case FDMCS_NO:
		dwSet = 0;
		break;

	case FDMCS_YES:
		dwSet = FC_ADDLINKTOSTARTMENU;
		break;

	case FDMCS_OPT_IN:
		dwSet = FC_ADDLINKTOSTARTMENU | FC_SM_OPTIONAL;
		break;

	case FDMCS_OPT_OUT:
		dwSet = FC_ADDLINKTOSTARTMENU | FC_SM_OPTIONAL | FC_SM_CHECKEDBYDEF;
		break;

	default:
		return;
	}

	pSession->modify_Flags (FC_ADDLINKTOSTARTMENU, dwSet);
}

void FDMCSAPI fdmcsSet_IEButton (FDMCS_SESSION pS, int iSet, LPCSTR pszIcon)
{
	USE_FDMCS_SESSION (pSession, pS);
	FDMCS_BUILDTYPE_DENIED (pSession, FDMCS_STANDARD);

	DWORD dwSet;

	switch (iSet)
	{
	case FDMCS_NO:
		dwSet = 0;
		break;

	case FDMCS_YES:
		dwSet = FC_ADDBUTTONTOIE;
		break;

	case FDMCS_OPT_IN:
		dwSet = FC_ADDBUTTONTOIE | FC_IEBTN_OPTIONAL;
		break;

	case FDMCS_OPT_OUT:
		dwSet = FC_ADDBUTTONTOIE | FC_IEBTN_OPTIONAL | FC_IEBTN_CHECKEDBYDEF;
		break;

	default:
		return;
	}

	pSession->modify_Flags (FC_ADDBUTTONTOIE, dwSet);

	if (dwSet != 0)
		pSession->set_IEButtonIcon (pszIcon);
}

void FDMCSAPI fdmcsSet_GetCustVerBtn (FDMCS_SESSION pS, BOOL bShow)
{
	USE_FDMCS_SESSION (pSession, pS);
	FDMCS_BUILDTYPE_DENIED (pSession, FDMCS_FREE);
	pSession->set_ShowFDMCustBtn (bShow);
}

void FDMCSAPI fdmcsSet_ShowBanners (FDMCS_SESSION pS, BOOL bShow)
{
	USE_FDMCS_SESSION (pSession, pS);
	FDMCS_BUILDTYPE_DENIED (pSession, FDMCS_STANDARD);
	
	if (bShow)
		pSession->modify_Flags (0, FC_ADDBANNERS);
	else
		pSession->modify_Flags (FC_ADDBANNERS, 0);
}

void FDMCSAPI fdmcsAdd_Banner (FDMCS_SESSION pS, LPCSTR pszURL, LPCSTR pszImage)
{
	USE_FDMCS_SESSION (pSession, pS);
	FDMCS_BUILDTYPE_DENIED (pSession, FDMCS_STANDARD);

	fdmcsSet_ShowBanners (pS, TRUE);

	vmsFDMBannerInfo banner;
	banner.strURL  = pszURL;
	banner.strFile = pszImage;
	pSession->add_Banner (banner);
}

void FDMCSAPI fdmcsClearBannerList (FDMCS_SESSION pS)
{
	USE_FDMCS_SESSION (pSession, pS);
	pSession->RemoveAllBanners ();
}

void FDMCSAPI fdmcsSet_UseListOfDownloads (FDMCS_SESSION pS, BOOL bUse)
{
	USE_FDMCS_SESSION (pSession, pS);
	FDMCS_BUILDTYPE_DENIED (pSession, FDMCS_STANDARD);
	
	if (bUse)
		pSession->modify_Flags (0, FC_ADDDOWNLOADS);
	else
		pSession->modify_Flags (FC_ADDDOWNLOADS, 0);
}

void FDMCSAPI fdmcsAdd_Download (FDMCS_SESSION pS, LPCSTR pszURL, LPCSTR pszComment, BOOL bAutoStart)
{
	USE_FDMCS_SESSION (pSession, pS);
	FDMCS_BUILDTYPE_DENIED (pSession, FDMCS_STANDARD);

	fdmcsSet_UseListOfDownloads (pS, TRUE);

	vmsFDMDownloadInfo dl;
	dl.strURL     = pszURL;
	dl.strComment = pszComment;
	dl.bStartAutomatically = bAutoStart;
	pSession->add_Download (dl);
}

void DumpToLog_Session (HANDLE h, vmsFDMCustomized* pSession)
{
	DWORD dw;
	char sz [1000];

	sprintf (sz, "Primary ID: %d\r\nSite url: %s\r\nSite title: %s\r\nSite icon file: %s\r\n",
		pSession->get_AffiliateID (), 
		pSession->get_Customizer_SiteURL (),
		pSession->get_Customizer (),
		pSession->get_Customizer_SiteIconFile ());

	WriteFile (h, sz, lstrlen (sz), &dw, NULL);

	sprintf (sz, "Show button: %s\r\n", pSession->get_UseButton () ? "yes" : "no");
	WriteFile (h, sz, lstrlen (sz), &dw, NULL);
	if (pSession->get_UseButton ())
	{
		vmsFDMButtonInfo* btn = pSession->get_ButtonInfo ();
		sprintf (sz, " Button's icon file: %s\r\n Button's text: %s\r\n Button's url: %s\r\n",
			btn->strIcon.c_str (), btn->strText.c_str (), btn->strURL.c_str ());
		WriteFile (h, sz, lstrlen (sz), &dw, NULL);
	}

	DWORD dwFlags = pSession->get_Flags ();

	LPCSTR psz;
	if (0 == (dwFlags & FC_MODIFYHOMEPAGE))
		psz = "no";
	else
		psz = dwFlags & FC_MHP_CHECKEDBYDEF ? "yes, opt-in" : "yes, opt-out";
	sprintf (sz, "Set home page: %s\r\n", psz);
	WriteFile (h, sz, lstrlen (sz), &dw, NULL);

	if (0 == (dwFlags & FC_ADDLINKTOFAVOR))
		psz = "no";
	else if (0 == (dwFlags & FC_FAV_OPTIONAL))
		psz = "yes";
	else
		psz = dwFlags & FC_FAV_CHECKEDBYDEF ? "yes, opt-in" : "yes, opt-out";
	sprintf (sz, "Add link to favorites: %s\r\n", psz);
	WriteFile (h, sz, lstrlen (sz), &dw, NULL);

	if (0 == (dwFlags & FC_ADDLINKTOSTARTMENU))
		psz = "no";
	else if (0 == (dwFlags & FC_SM_OPTIONAL))
		psz = "yes";
	else
		psz = dwFlags & FC_SM_CHECKEDBYDEF ? "yes, opt-in" : "yes, opt-out";
	sprintf (sz, "Add link to start menu: %s\r\n", psz);
	WriteFile (h, sz, lstrlen (sz), &dw, NULL);

	if (0 == (dwFlags & FC_ADDBUTTONTOIE))
		psz = "no";
	else if (0 == (dwFlags & FC_IEBTN_OPTIONAL))
		psz = "yes";
	else
		psz = dwFlags & FC_IEBTN_CHECKEDBYDEF ? "yes, opt-in" : "yes, opt-out";
	sprintf (sz, "Add button to IE: %s\r\n", psz);
	WriteFile (h, sz, lstrlen (sz), &dw, NULL);

	if (dwFlags & FC_ADDBUTTONTOIE)
	{
		sprintf (sz, " IE button's icon file: %s\r\n", pSession->get_IEButtonIcon ());
		WriteFile (h, sz, lstrlen (sz), &dw, NULL);
	}

	sprintf (sz, "Show custom version button: %s\r\n", pSession->get_ShowFDMCustBtn () ? "yes" : "no");
	WriteFile (h, sz, lstrlen (sz), &dw, NULL);

	sprintf (sz, "Number of banners: %d\r\n", pSession->get_BannerCount ());
	WriteFile (h, sz, lstrlen (sz), &dw, NULL);

	int i = 0;
	for (i = 0; i < pSession->get_BannerCount (); i++)
	{
		vmsFDMBannerInfo* bi = pSession->get_Banner (i);
		sprintf (sz, " Banner %d\r\n  file: %s\r\n  url: %s\r\n", 
			i, bi->strFile.c_str (), bi->strURL.c_str ());
		WriteFile (h, sz, lstrlen (sz), &dw, NULL);
	}

	sprintf (sz, "Number of downloads: %d\r\n", pSession->get_DownloadCount ());
	WriteFile (h, sz, lstrlen (sz), &dw, NULL);

	for (i = 0; i < pSession->get_DownloadCount (); i++)
	{
		vmsFDMDownloadInfo* di = pSession->get_Download (i);
		sprintf (sz, " Download %d\r\n  url: %s\r\n  referer: %s\r\n  comment: %s\r\n  auto start: %s\r\n",
			i, di->strURL.c_str (), di->strReferer.c_str (), di->strComment.c_str (), 
			di->bStartAutomatically ? "yes" : "no");
		WriteFile (h, sz, lstrlen (sz), &dw, NULL);
	}
}

void DumpToLog (vmsFDMCustomized* pSession, LPCSTR pszOutFile, LPCSTR pszErr)
{
	HANDLE hmx = CreateMutex (NULL, FALSE, "vmsMX::fdmcs_Dump");
	WaitForSingleObject (hmx, INFINITE);

	char szFile [MAX_PATH];
	GetModuleFileName ((HINSTANCE)_hModule, szFile, sizeof (szFile));
	lstrcat (szFile, ".log");

	HANDLE h = CreateFile (szFile, GENERIC_WRITE, 0, NULL, OPEN_ALWAYS, 
		FILE_ATTRIBUTE_NORMAL, NULL);

	if (h == INVALID_HANDLE_VALUE)
		goto _lExit;

	SetFilePointer (h, 0, NULL, FILE_END);

	char szDate [100];

	SYSTEMTIME time;
	GetSystemTime (&time);
	GetDateFormat (LOCALE_SYSTEM_DEFAULT, DATE_SHORTDATE, &time, NULL, szDate, 
		sizeof (szDate));

	lstrcat (szDate, ", ");

	GetTimeFormat (LOCALE_USER_DEFAULT, 0, &time, NULL, szDate + lstrlen (szDate), 
		sizeof (szDate) - lstrlen (szDate));

	char sz [1000];
	DWORD dw;
	
	sprintf (sz, "[%s]\r\nGenerate distrib error occured!\r\nError is: %s\r\nOutput file name is: %s\r\n--- Session dump ---\r\n",
		szDate, pszErr, pszOutFile);
	WriteFile (h, sz, lstrlen (sz), &dw, NULL);

	DumpToLog_Session (h, pSession);
	WriteFile (h, "\r\n", 2, &dw, NULL);

	CloseHandle (h);

_lExit:
	ReleaseMutex (hmx);
	CloseHandle (hmx);
}

BOOL FDMCSAPI fdmcsGenerateDistrib (FDMCS_SESSION pS, LPCSTR pszFile, LPSTR pszErrDesc)
{
	USE_FDMCS_SESSION (pSession, pS);

	try {
		pSession->Generate (pszFile);
	}
	catch (LPCSTR pszErr)
	{
		DumpToLog (pSession, pszFile, pszErr);

		if (pszErrDesc)
			lstrcpy (pszErrDesc, pszErr);
		return FALSE;
	}

	return TRUE;
}