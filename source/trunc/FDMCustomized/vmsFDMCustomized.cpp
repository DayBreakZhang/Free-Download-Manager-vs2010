/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FDMCustomized.h"
#include "vmsFDMCustomized.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

vmsFDMCustomized::vmsFDMCustomized()
{
	m_strCustomizer = "Free Downloads Center";
	m_strCustWebsite = "http://www.freedownloadscenter.com/indexF.html";
	
	m_strPostVersion = "FDC Edition";
	m_dwFlags = 0;
	m_bShowGetCVerBtn = TRUE;
}

vmsFDMCustomized::~vmsFDMCustomized()
{

}

#define FDMCSAPI WINAPI
typedef long FDMCS_SESSION;

#define FDMCS_FREE			0
#define FDMCS_STANDARD		1
#define FDMCS_PROFESSIONAL	2

#define FDMCS_NO			0
#define FDMCS_OPT_IN		1
#define FDMCS_OPT_OUT		2
#define FDMCS_YES			3

typedef FDMCS_SESSION (FDMCSAPI *fdmcsCreateSession) (int iEdition);
typedef void (FDMCSAPI *fdmcsCloseSession) (FDMCS_SESSION pS);
typedef void (FDMCSAPI *fdmcsSet_PrimaryID) (FDMCS_SESSION pS, int iID);
typedef void (FDMCSAPI *fdmcsSet_SiteURL) (FDMCS_SESSION pS, LPCSTR pszURL);
typedef void (FDMCSAPI *fdmcsSet_SiteTitle) (FDMCS_SESSION pS, LPCSTR pszTitle);
typedef void (FDMCSAPI *fdmcsSet_SiteIcon) (FDMCS_SESSION pS, LPCSTR pszIcon);
typedef void (FDMCSAPI *fdmcsSet_Button) (FDMCS_SESSION pS, BOOL bShowButton, LPCSTR pszIcon, LPCSTR pszText, LPCSTR pszURL);
typedef void (FDMCSAPI *fdmcsSet_SetHomePage) (FDMCS_SESSION pS, int iSet);
typedef void (FDMCSAPI *fdmcsSet_AddLinkToFavorites) (FDMCS_SESSION pS, int iSet);
typedef void (FDMCSAPI *fdmcsSet_AddLinkToStartMenu) (FDMCS_SESSION pS, int iSet);
typedef void (FDMCSAPI *fdmcsSet_IEButton) (FDMCS_SESSION pS, int iSet, LPCSTR pszIcon);
typedef void (FDMCSAPI *fdmcsSet_GetCustVerBtn) (FDMCS_SESSION pS, BOOL bShow);
typedef void (FDMCSAPI *fdmcsSet_ShowBanners) (FDMCS_SESSION pS, BOOL bShow);
typedef void (FDMCSAPI *fdmcsAdd_Banner) (FDMCS_SESSION pS, LPCSTR pszURL, LPCSTR pszImage);
typedef void (FDMCSAPI *fdmcsClearBannerList) (FDMCS_SESSION pS);
typedef void (FDMCSAPI *fdmcsSet_UseListOfDownloads) (FDMCS_SESSION pS, BOOL bUse);
typedef void (FDMCSAPI *fdmcsAdd_Download) (FDMCS_SESSION pS, LPCSTR pszURL, LPCSTR pszComment, BOOL bAutoStart);
typedef BOOL (FDMCSAPI *fdmcsGenerateDistrib) (FDMCS_SESSION pS, LPCSTR pszFile, LPSTR pszErrDesc);

void vmsFDMCustomized::Generate(LPCSTR pszOutFile)
{
	HMODULE hLib = LoadLibrary ("fdmdll.dll");
	if (hLib == NULL)
		throw "failed to load fdmdll.dll";

	fdmcsCreateSession CreateSession = (fdmcsCreateSession) GetProcAddress (hLib, "fdmcsCreateSession");
	fdmcsCloseSession CloseSession = (fdmcsCloseSession) GetProcAddress (hLib, "fdmcsCloseSession");
	fdmcsSet_PrimaryID Set_PrimaryID = (fdmcsSet_PrimaryID) GetProcAddress (hLib, "fdmcsSet_PrimaryID");
	fdmcsSet_SiteURL Set_SiteURL = (fdmcsSet_SiteURL) GetProcAddress (hLib, "fdmcsSet_SiteURL");
	fdmcsSet_SiteTitle Set_SiteTitle = (fdmcsSet_SiteTitle) GetProcAddress (hLib, "fdmcsSet_SiteTitle");
	fdmcsSet_SiteIcon Set_SiteIcon = (fdmcsSet_SiteIcon) GetProcAddress (hLib, "fdmcsSet_SiteIcon");
	fdmcsSet_Button Set_Button = (fdmcsSet_Button) GetProcAddress (hLib, "fdmcsSet_Button");
	fdmcsSet_SetHomePage Set_SetHomePage = (fdmcsSet_SetHomePage) GetProcAddress (hLib, "fdmcsSet_SetHomePage");
	fdmcsSet_AddLinkToFavorites Set_AddLinkToFavorites = (fdmcsSet_AddLinkToFavorites) GetProcAddress (hLib, "fdmcsSet_AddLinkToFavorites");
	fdmcsSet_AddLinkToStartMenu Set_AddLinkToStartMenu = (fdmcsSet_AddLinkToStartMenu) GetProcAddress (hLib, "fdmcsSet_AddLinkToStartMenu");
	fdmcsSet_IEButton Set_IEButton = (fdmcsSet_IEButton) GetProcAddress (hLib, "fdmcsSet_IEButton");
	fdmcsSet_GetCustVerBtn Set_GetCustVerBtn = (fdmcsSet_GetCustVerBtn) GetProcAddress (hLib, "fdmcsSet_GetCustVerBtn");
	fdmcsSet_ShowBanners Set_ShowBanners = (fdmcsSet_ShowBanners) GetProcAddress (hLib, "fdmcsSet_ShowBanners");
	fdmcsAdd_Banner Add_Banner = (fdmcsAdd_Banner) GetProcAddress (hLib, "fdmcsAdd_Banner");
	fdmcsClearBannerList ClearBannerList = (fdmcsClearBannerList) GetProcAddress (hLib, "fdmcsClearBannerList");
	fdmcsSet_UseListOfDownloads Set_UseListOfDownloads = (fdmcsSet_UseListOfDownloads) GetProcAddress (hLib, "fdmcsSet_UseListOfDownloads");
	fdmcsAdd_Download Add_Download = (fdmcsAdd_Download) GetProcAddress (hLib, "fdmcsAdd_Download");
	fdmcsGenerateDistrib GenerateDistrib = (fdmcsGenerateDistrib) GetProcAddress (hLib, "fdmcsGenerateDistrib");

	FDMCS_SESSION pS = CreateSession (FDMCS_PROFESSIONAL);

	Set_PrimaryID (pS, m_id);
	Set_SiteURL (pS, get_Customizer_SiteURL ());
	Set_SiteTitle (pS, m_strCustomizer);
	Set_SiteIcon (pS, m_strCustSiteIcon);
	Set_Button (pS, m_bUseBtn, m_Btn.strIcon.c_str (), m_Btn.strText.c_str (), m_Btn.strURL.c_str ());

	int iSet = FDMCS_NO;
	if (m_dwFlags & FC_MODIFYHOMEPAGE)
	{
		iSet = FDMCS_OPT_IN;
		if (m_dwFlags & FC_MHP_CHECKEDBYDEF)
			iSet = FDMCS_OPT_OUT;
	}
	Set_SetHomePage (pS, iSet);

	iSet = FDMCS_NO;
	if (m_dwFlags & FC_ADDLINKTOFAVOR)
	{
		iSet = FDMCS_YES;
		if (m_dwFlags & FC_FAV_OPTIONAL)
		{
			iSet = FDMCS_OPT_IN;
			if (m_dwFlags & FC_FAV_CHECKEDBYDEF)
				iSet = FDMCS_OPT_OUT;
		}
	}
	Set_AddLinkToFavorites (pS, iSet);

	iSet = FDMCS_NO;
	if (m_dwFlags & FC_ADDLINKTOSTARTMENU)
	{
		iSet = FDMCS_YES;
		if (m_dwFlags & FC_SM_OPTIONAL)
		{
			iSet = FDMCS_OPT_IN;
			if (m_dwFlags & FC_SM_CHECKEDBYDEF)
				iSet = FDMCS_OPT_OUT;
		}
	}
	Set_AddLinkToStartMenu (pS, iSet);

	iSet = FDMCS_NO;
	if (m_dwFlags & FC_ADDBUTTONTOIE)
	{
		iSet = FDMCS_YES;
		if (m_dwFlags & FC_IEBTN_OPTIONAL)
		{
			iSet = FDMCS_OPT_IN;
			if (m_dwFlags & FC_IEBTN_CHECKEDBYDEF)
				iSet = FDMCS_OPT_OUT;
		}
	}
	Set_IEButton (pS, iSet, m_strIEButtonIcon);

	Set_GetCustVerBtn (pS, m_bShowGetCVerBtn);

	if (m_dwFlags & FC_ADDBANNERS)
	{
		for (int i = 0; i < get_BannerCount (); i++)
		{
			vmsFDMBannerInfo* banner = get_Banner (i);
			Add_Banner (pS, banner->strURL.c_str (), banner->strFile.c_str ());
		}
	}

	if (m_dwFlags & FC_ADDDOWNLOADS)
	{
		for (int i = 0; i < get_DownloadCount (); i++)
		{
			vmsFDMDownloadInfo* dl = get_Download (i);
			Add_Download (pS, dl->strURL.c_str (), dl->strComment.c_str (), FALSE);
		}
	}

	if (FALSE == GenerateDistrib (pS, "#fdminst-cust.exe", NULL))
		MessageBox (NULL, "Failed to generate distrib", "Error", MB_ICONERROR);

	CloseSession (pS);
	FreeLibrary (hLib);
}

int vmsFDMCustomized::get_BannerCount()
{
	return m_vBanners.size ();
}

void vmsFDMCustomized::RemoveAllBanners()
{
	m_vBanners.clear ();
}

vmsFDMBannerInfo* vmsFDMCustomized::get_Banner(int iIndex)
{
	return &m_vBanners [iIndex];
}

void vmsFDMCustomized::add_Banner(const vmsFDMBannerInfo &banner)
{
	m_vBanners.push_back (banner);
}

void vmsFDMCustomized::remove_Banner(int iIndex)
{
	m_vBanners.erase (m_vBanners.begin () + iIndex);
}

#include "vmsImage.h"

vmsFDMButtonInfo* vmsFDMCustomized::get_ButtonInfo()
{
	return &m_Btn;
}

void vmsFDMCustomized::set_UseButton(BOOL bUse)
{
	m_bUseBtn = bUse;
}

LPCSTR vmsFDMCustomized::get_Customizer_SiteURL()
{
	return m_strCustWebsite;
}

LPCSTR vmsFDMCustomized::get_Customizer_SiteIconFile()
{
	return m_strCustSiteIcon;
}

void vmsFDMCustomized::set_Customizer_SiteURL(LPCSTR psz)
{
	m_strCustWebsite = psz;
}

void vmsFDMCustomized::set_Customizer_SiteIconFile(LPCSTR psz)
{
	m_strCustSiteIcon = psz;
}

void vmsFDMCustomized::set_Customizer(LPCSTR psz)
{
	m_strCustomizer = psz;
	m_strPostVersion = psz;
	m_strPostVersion += " Edition";
}

void vmsFDMCustomized::set_Flags(DWORD dw)
{
	m_dwFlags = dw;
}

void vmsFDMCustomized::set_IEButtonIcon(LPCSTR psz)
{
	m_strIEButtonIcon = psz;
}

void vmsFDMCustomized::add_Download(vmsFDMDownloadInfo &dl)
{
	m_vDownloads.push_back (dl);
}

int vmsFDMCustomized::get_DownloadCount()
{
	return m_vDownloads.size ();
}

vmsFDMDownloadInfo* vmsFDMCustomized::get_Download(int iIndex)
{
	return &m_vDownloads [iIndex];
}

void vmsFDMCustomized::RemoveAllDownloads()
{
	m_vDownloads.clear ();
}

void vmsFDMCustomized::set_UseFDMCVerBtn(BOOL bUse)
{
	m_bShowGetCVerBtn = bUse;
}

