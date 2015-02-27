/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_FDMCUSTOMIZATIONS_H__56762F4E_A485_4A61_92FB_F2DEAD30D283__INCLUDED_)
#define AFX_FDMCUSTOMIZATIONS_H__56762F4E_A485_4A61_92FB_F2DEAD30D283__INCLUDED_

#include "vmsXOR.h"	
#if _MSC_VER > 1000
#pragma once
#endif 

#include <windows.h>
#include <vector>
#include "vmsDES.h"	

const char* const _pszFDMCustomizationsErr = "fdmcusterr";

struct vmsFDMBanner
{
	LPBYTE	pbImage;
	DWORD	dwSize;
	LPSTR	pszLinksTo;
	char	szType [4];	
};

struct vmsFDMButton
{
	LPSTR	pszText;
	LPSTR	pszLinksTo;
	LPBYTE	pbIcon;
	DWORD	dwSize;

	vmsFDMButton () : pszText (NULL), pszLinksTo (NULL), pbIcon (NULL) {};
};

class vmsFDMCustomizations  
{
public:
	void set_Key (int iKey);
	void set_ShowFDMCustBtn (BOOL b);
	BOOL get_ShowFDMCustBtn();
	void set_AffiliateID (DWORD dw);
	DWORD get_AffiliateID();
	LPCSTR get_Customizer();
	void set_Customizer (LPCSTR psz);
	void set_ButtonInfo (vmsFDMButton& btn);
	void set_UseButton (BOOL bUse);
	void RemoveAllBanners();
	vmsFDMButton* get_ButtonInfo();
	BOOL get_UseButton();
	vmsFDMBanner* get_Banner (int iIndex);
	int get_BannerCount();
	void AddBanner (vmsFDMBanner& banner);
	void Save (HANDLE hFile);
	void Load (HANDLE hFile);
	void Free();

	vmsFDMCustomizations();
	virtual ~vmsFDMCustomizations();

protected:
	int m_iKey;
	void set_DESKey (DES_KEY key);
	vmsXOR m_xor;
	vmsDES m_des;
	std::string m_strCustomizer;
	std::vector <vmsFDMBanner> m_vBanners;
	BOOL m_bUseBtn;
	vmsFDMButton m_Btn;
	DWORD m_dwAffiliateID;
	BOOL m_bShowFDMCustBtn;
private:
	void DecryptFile (class vmsMemFile& file);
	void EncryptFile (class vmsMemFile& file);
	void ReadString (class vmsMemFile &file, LPSTR* ppsz);
	void WriteString (class vmsMemFile &file, LPCSTR psz);
};

#endif 
