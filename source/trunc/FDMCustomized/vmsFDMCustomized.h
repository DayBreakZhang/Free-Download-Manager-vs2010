/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSFDMCUSTOMIZED_H__A728AF4F_3588_41C1_AAC8_5250D1826DCC__INCLUDED_)
#define AFX_VMSFDMCUSTOMIZED_H__A728AF4F_3588_41C1_AAC8_5250D1826DCC__INCLUDED_

#include "vmsFDMISSGenerator.h"
#include <vector>
#include <string>

#if _MSC_VER > 1000
#pragma once
#endif 

#define FC_MODIFYHOMEPAGE		1L
#define FC_ADDLINKTOFAVOR		(1L << 1)
#define FC_ADDLINKTOSTARTMENU	(1L << 2)
#define FC_ADDBUTTONTOIE		(1L << 3)
#define FC_ADDDOWNLOADS			(1L << 4)
#define FC_ADDBANNERS			(1L << 5)

#define FC_MHP_CHECKEDBYDEF		(1L << 6)

#define FC_FAV_OPTIONAL			(1L << 7)
#define FC_FAV_CHECKEDBYDEF		(1L << 8)

#define FC_SM_OPTIONAL			(1L << 9)
#define FC_SM_CHECKEDBYDEF		(1L << 10)

#define FC_IEBTN_OPTIONAL		(1L << 11)
#define FC_IEBTN_CHECKEDBYDEF	(1L << 12)

struct vmsFDMBannerInfo
{
	std::string strFile;
	std::string strURL;
};

struct vmsFDMButtonInfo
{
	std::string strText;
	std::string strIcon;
	std::string strURL;
};

struct vmsFDMDownloadInfo
{
	std::string strURL;
	std::string strReferer;
	std::string strComment;
};

class vmsFDMCustomized
{
public:
	int m_id;
	void set_UseFDMCVerBtn (BOOL bUse);
	void RemoveAllDownloads();
	vmsFDMDownloadInfo* get_Download (int iIndex);
	int get_DownloadCount();
	void add_Download (vmsFDMDownloadInfo& dl);
	void set_IEButtonIcon (LPCSTR psz);
	void set_Flags (DWORD dw);
	void set_Customizer (LPCSTR psz);
	void set_Customizer_SiteIconFile (LPCSTR psz);
	void set_Customizer_SiteURL (LPCSTR psz);
	LPCSTR get_Customizer_SiteIconFile();
	LPCSTR get_Customizer_SiteURL();
	void set_UseButton (BOOL bUse);
	vmsFDMButtonInfo* get_ButtonInfo();
	void remove_Banner (int iIndex);
	void add_Banner(const vmsFDMBannerInfo &banner);
	vmsFDMBannerInfo* get_Banner (int iIndex);
	void RemoveAllBanners();
	int get_BannerCount();
	void Generate (LPCSTR pszOutFile);
	vmsFDMCustomized();
	virtual ~vmsFDMCustomized();
protected:
	BOOL m_bShowGetCVerBtn;
	CString m_strIEButtonIcon;
	BOOL m_bUseBtn;
	CString m_strFDMPreExe;
	CString m_strFDMInst;
	
	CString m_strCustomizer;
	CString m_strCustWebsite;
	CString m_strCustSiteIcon;
	CString m_strPostVersion;
	DWORD m_dwFlags;
	CString m_strIEButtonDLL;
	CString m_strDownloads;
	std::vector <vmsFDMBannerInfo> m_vBanners;
	std::vector <vmsFDMDownloadInfo> m_vDownloads;
	vmsFDMButtonInfo m_Btn;
};

#endif 
