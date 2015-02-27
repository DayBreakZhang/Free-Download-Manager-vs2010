/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsFDMCustomized.h"
#include "vmsFile.h"

vmsFDMCustomized::vmsFDMCustomized()
{
	m_strFDMPreExe = "fdmcs_PreExe.exe";
	m_dwFlags = 0;
}

vmsFDMCustomized::~vmsFDMCustomized()
{

}

void vmsFDMCustomized::Generate(LPCSTR pszOutFile)
{
	vmsFile out;
	out.Create (pszOutFile);

	vmsFile file;
	DWORD dw;

	
	file.Open (m_strFDMPreExe.c_str (), TRUE);

	LPBYTE pbBuffer = new BYTE [file.get_Size ()];
	file.Read (pbBuffer, file.get_Size ());
	out.Write (pbBuffer, file.get_Size ());
	file.Close ();
	delete [] pbBuffer;

	
	out.Write ("###FDMDATA###", lstrlen ("###FDMDATA###"));

	
	file.Open (m_strFDMInst.c_str (), TRUE);
	dw = file.get_Size ();
	out.Write (&dw, sizeof (DWORD));
	pbBuffer = new BYTE [dw];
	file.Read (pbBuffer, dw);
	out.Write (pbBuffer, dw);
	file.Close ();
	delete [] pbBuffer;

	
	dw = m_strPostVersion.length ();
	out.Write (&dw, sizeof (DWORD));
	out.Write (m_strPostVersion.c_str (), dw);

	
	dw = m_strCustomizer.length ();
	out.Write (&dw, sizeof (DWORD));
	out.Write (m_strCustomizer.c_str (), dw);

	dw = m_strCustWebsite.length ();
	out.Write (&dw, sizeof (DWORD));
	out.Write (m_strCustWebsite.c_str (), dw);

	
	out.Write (&m_dwFlags, sizeof (DWORD));

	
	if (m_strCustSiteIcon.length ())
	{
		file.Open (m_strCustSiteIcon.c_str (), TRUE);
		dw = file.get_Size ();
		out.Write (&dw, sizeof (DWORD));
		pbBuffer = new BYTE [dw];
		file.Read (pbBuffer, dw);
		out.Write (pbBuffer, dw);
		file.Close ();
		delete [] pbBuffer;
	}
	else
	{
		dw = 0;
		out.Write (&dw, sizeof (DWORD));
	}

	
	if (m_dwFlags & FC_ADDBUTTONTOIE)
	{
		file.Open (m_strIEButtonIcon.c_str (), TRUE);
		dw = file.get_Size ();
		out.Write (&dw, sizeof (DWORD));
		pbBuffer = new BYTE [dw];
		file.Read (pbBuffer, dw);
		out.Write (pbBuffer, dw);
		file.Close ();
		delete [] pbBuffer;
	}

	
	if ((m_dwFlags & FC_ADDDOWNLOADS) && m_vDownloads.size ())
	{
		dw = m_vDownloads.size ();
		out.Write (&dw, sizeof (DWORD));

		for (int i = 0; i < m_vDownloads.size (); i++)
		{
			vmsFDMDownloadInfo* dl = &m_vDownloads [i];

			dw = dl->strURL.length ();
			out.Write (&dw, sizeof (DWORD));
			out.Write (dl->strURL.c_str (), dw);

			dw = dl->strReferer.length ();
			out.Write (&dw, sizeof (DWORD));
			out.Write (dl->strReferer.c_str (), dw);

			dw = dl->strComment.length ();
			out.Write (&dw, sizeof (DWORD));
			out.Write (dl->strComment.c_str (), dw);

			out.Write (&dl->bStartAutomatically, sizeof (BOOL));
		}
	}

	
	ApplyBannersInfo ();
	ApplyButtonInfo ();
	m_Customizations.set_Customizer (m_strCustomizer.c_str ());

	
	

	DWORD dwPos = out.get_Pos ();	

	out.Write (&dw, sizeof (DWORD));	
	m_Customizations.Save (out);	

	DWORD dwPos2 = out.get_Pos ();	
	
	out.set_Pos (dwPos, FILE_BEGIN);	
	dw = dwPos2 - dwPos - sizeof (DWORD);	
	out.Write (&dw, sizeof (DWORD));	

	out.set_Pos (dwPos2, FILE_BEGIN);	
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

void vmsFDMCustomized::ApplyBannersInfo()
{
	m_Customizations.RemoveAllBanners ();

	if (m_dwFlags & FC_ADDBANNERS)
	for (int i = 0; i < get_BannerCount (); i++)
	{
		vmsFDMBannerInfo *bi = get_Banner (i);
		vmsFDMBanner banner;
		LPCSTR pszFile = bi->strFile.c_str ();
		
		banner.pszLinksTo = new char [bi->strURL.length ()+1];
		lstrcpy (banner.pszLinksTo, bi->strURL.c_str ());

		vmsFile file;
		file.Open (pszFile, TRUE);
		banner.dwSize = file.get_Size ();
		banner.pbImage = new BYTE [file.get_Size ()];
		file.Read (banner.pbImage, banner.dwSize);
		file.Close ();

		banner.szType [0] = 0;
		LPCSTR pszExt = strrchr (pszFile, '.');
		if (pszExt)
		{
			strncpy (banner.szType, pszExt+1, 3);
			banner.szType [3] = 0;
		}

		m_Customizations.AddBanner (banner);
	}
}

vmsFDMButtonInfo* vmsFDMCustomized::get_ButtonInfo()
{
	return &m_Btn;
}

void vmsFDMCustomized::set_UseButton(BOOL bUse)
{
	m_bUseBtn = bUse;
}

void vmsFDMCustomized::ApplyButtonInfo()
{
	m_Customizations.set_UseButton (m_bUseBtn);

	if (m_bUseBtn)
	{
		vmsFDMButton btn;

		btn.pszText = new char [m_Btn.strText.length ()+1];
		lstrcpy (btn.pszText, m_Btn.strText.c_str ());

		btn.pszLinksTo = new char [m_Btn.strURL.length ()+1];
		lstrcpy (btn.pszLinksTo, m_Btn.strURL.c_str ());

		vmsFile file;
		file.Open (m_Btn.strIcon.c_str (), TRUE);
		btn.dwSize = file.get_Size ();
		btn.pbIcon = new BYTE [file.get_Size ()];
		file.Read (btn.pbIcon, btn.dwSize);
		file.Close ();

		m_Customizations.set_ButtonInfo (btn);
	}
}

LPCSTR vmsFDMCustomized::get_Customizer_SiteURL()
{
	return m_strCustWebsite.c_str ();
}

LPCSTR vmsFDMCustomized::get_Customizer_SiteIconFile()
{
	return m_strCustSiteIcon.c_str ();
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

void vmsFDMCustomized::set_BuildType(vmsFDMCSBuildType enType)
{
	switch (enType)
	{
	case FDMCSBT_FREE:
		m_strFDMInst = "fdmcs_Inst_wa.exe";	
		m_Customizations.set_Key (0);
		break;

	case FDMCSBT_STANDARD:
		m_strFDMInst = "fdmcs_Inst_woa.exe";	
		m_Customizations.set_Key (1);
		break;

	case FDMCSBT_PROFESSIONAL:
		m_strFDMInst = "fdmcs_Inst_woa.exe";
		m_Customizations.set_Key (2);
		break;

	default:
		return;
	}

	m_enBuildType = enType;
}

vmsFDMCSBuildType vmsFDMCustomized::get_BuildType()
{
	return m_enBuildType;
}

void vmsFDMCustomized::set_AffiliateID(DWORD dwID)
{
	m_Customizations.set_AffiliateID (dwID);
}

void vmsFDMCustomized::modify_Flags(DWORD dwRemove, DWORD dwSet)
{
	m_dwFlags &= ~dwRemove;
	m_dwFlags |= dwSet;
}

void vmsFDMCustomized::set_ShowFDMCustBtn(BOOL bShow)
{
	m_Customizations.set_ShowFDMCustBtn (bShow);
}

DWORD vmsFDMCustomized::get_AffiliateID()
{
	return m_Customizations.get_AffiliateID ();
}

LPCSTR vmsFDMCustomized::get_Customizer()
{
	return m_strCustomizer.c_str ();
}

BOOL vmsFDMCustomized::get_UseButton()
{
	return m_bUseBtn;
}

DWORD vmsFDMCustomized::get_Flags()
{
	return m_dwFlags;
}

LPCSTR vmsFDMCustomized::get_IEButtonIcon()
{
	return m_strIEButtonIcon.c_str ();
}

BOOL vmsFDMCustomized::get_ShowFDMCustBtn()
{
	return m_Customizations.get_ShowFDMCustBtn ();
}
