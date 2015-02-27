/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "FDMCustomizations.h"
#include "vmsMemFile.h"

#define SAFE_DELETE_ARRAY(a) if (a) {delete [] a; a = NULL;}

vmsFDMCustomizations::vmsFDMCustomizations()
{
	m_bUseBtn = FALSE;
	m_bShowFDMCustBtn = TRUE;
	m_dwAffiliateID = 0;
	m_xor.set_Key ("vmsFDMCustomizations-2nd");
}

vmsFDMCustomizations::~vmsFDMCustomizations()
{

}

void vmsFDMCustomizations::Load(HANDLE hFile)
{
	Free ();

	vmsMemFile file;
	DWORD dw;
	file.Use (hFile, TRUE);
	DecryptFile (file);

	
	file.ReadFile (&dw, sizeof (dw));
	if (dw)
		throw _pszFDMCustomizationsErr;

	LPSTR psz;
	ReadString (file, &psz);
	set_Customizer (psz);
	delete [] psz;

	file.ReadFile (&m_dwAffiliateID, sizeof (DWORD));

	

	
	file.ReadFile (&dw, sizeof (dw));

	while (dw--)
	{
		

		vmsFDMBanner banner;

		file.ReadFile (&banner.dwSize, sizeof (DWORD));

		banner.pbImage = new BYTE [banner.dwSize];

		file.ReadFile (banner.pbImage, banner.dwSize);
	
		ReadString (file, &banner.pszLinksTo);
		file.ReadFile (banner.szType, 4);

		AddBanner (banner);
	}

	

	file.ReadFile (&m_bUseBtn, sizeof (m_bUseBtn));

	if (m_bUseBtn)
	{
		ReadString (file, &m_Btn.pszText);
		ReadString (file, &m_Btn.pszLinksTo);
		
		file.ReadFile (&m_Btn.dwSize, sizeof (DWORD));

		m_Btn.pbIcon = new BYTE [m_Btn.dwSize];

		file.ReadFile (m_Btn.pbIcon, m_Btn.dwSize);
	}

	file.ReadFile (&m_bShowFDMCustBtn, sizeof (BOOL));
}

void vmsFDMCustomizations::Save(HANDLE hFile)
{
	DWORD dw;
	
	vmsMemFile file;
	file.Use (hFile, FALSE);

	dw = m_iKey;	
	file.WriteFile (&dw, sizeof (dw));

	dw = 0;	
	file.WriteFile (&dw, sizeof (dw));

	WriteString (file, get_Customizer ());

	file.WriteFile (&m_dwAffiliateID, sizeof (DWORD));

	

	
	dw = m_vBanners.size ();
	file.WriteFile (&dw, sizeof (dw));

	for (int i = 0; i < m_vBanners.size (); i++)
	{
		

		vmsFDMBanner* banner = &m_vBanners [i];

		file.WriteFile (&banner->dwSize, sizeof (dw));
	
		file.WriteFile (banner->pbImage, banner->dwSize);

		WriteString (file, banner->pszLinksTo);
		file.WriteFile (banner->szType, 4);
	}

	

	file.WriteFile (&m_bUseBtn, sizeof (m_bUseBtn));

	if (m_bUseBtn)
	{
		WriteString (file, m_Btn.pszText);
		WriteString (file, m_Btn.pszLinksTo);
		
		file.WriteFile (&m_Btn.dwSize, sizeof (DWORD));

		file.WriteFile (m_Btn.pbIcon, m_Btn.dwSize);
	}

	
	file.WriteFile (&m_bShowFDMCustBtn, sizeof (BOOL));

	EncryptFile (file);
	file.Done ();
}

void vmsFDMCustomizations::Free()
{
	RemoveAllBanners ();

	SAFE_DELETE_ARRAY (m_Btn.pszText);
	SAFE_DELETE_ARRAY (m_Btn.pszLinksTo);
	SAFE_DELETE_ARRAY (m_Btn.pbIcon);
}

void vmsFDMCustomizations::WriteString(vmsMemFile &file, LPCSTR psz)
{
	DWORD dw = lstrlen (psz);

	file.WriteFile (&dw, sizeof (dw));
	file.WriteFile (psz, dw);
}

void vmsFDMCustomizations::ReadString(vmsMemFile &file, LPSTR *ppsz)
{
	DWORD dw;

	*ppsz = NULL;

	file.ReadFile (&dw, sizeof (dw));

	*ppsz = new char [dw+1];

	file.ReadFile (*ppsz, dw);
	(*ppsz)[dw] = 0;
}

void vmsFDMCustomizations::AddBanner(vmsFDMBanner &banner)
{
	m_vBanners.push_back (banner);
}

int vmsFDMCustomizations::get_BannerCount()
{
	return m_vBanners.size ();
}

vmsFDMBanner* vmsFDMCustomizations::get_Banner(int iIndex)
{
	return &m_vBanners [iIndex];
}

BOOL vmsFDMCustomizations::get_UseButton()
{
	return m_bUseBtn;
}

vmsFDMButton* vmsFDMCustomizations::get_ButtonInfo()
{
	return &m_Btn;
}

void vmsFDMCustomizations::RemoveAllBanners()
{
	for (int i = 0; i < m_vBanners.size (); i++)
	{
		delete [] m_vBanners [i].pbImage;
		delete [] m_vBanners [i].pszLinksTo;
	}
	m_vBanners.clear ();
}

void vmsFDMCustomizations::set_UseButton(BOOL bUse)
{
	m_bUseBtn = bUse;
}

void vmsFDMCustomizations::set_ButtonInfo(vmsFDMButton &btn)
{
	SAFE_DELETE_ARRAY (m_Btn.pszText);
	SAFE_DELETE_ARRAY (m_Btn.pszLinksTo);
	SAFE_DELETE_ARRAY (m_Btn.pbIcon);
	m_Btn = btn;
}

void vmsFDMCustomizations::set_Customizer(LPCSTR psz)
{
	m_strCustomizer = psz;
}

LPCSTR vmsFDMCustomizations::get_Customizer()
{
	return m_strCustomizer.c_str ();
}

void vmsFDMCustomizations::set_DESKey(DES_KEY key)
{
	m_des.set_Key (key);
}

void vmsFDMCustomizations::EncryptFile(vmsMemFile &file)
{
	DWORD dwSize = file.get_FileBufferSize () - 4;

	
	
	DWORD dw = 8 - (dwSize % 8);
	if (dw != 8)
		file.WriteFile ("\0\0\0\0\0\0\0", dw);

	LPBYTE pb = file.get_FileBuffer () + 4;
	dwSize = file.get_FileBufferSize () - 4;
	
	LPBYTE pbRes = new BYTE [dwSize];
	m_des.Encrypt (pb, pbRes, dwSize);
	m_xor.Encrypt (pbRes, pbRes, dwSize);
	CopyMemory (pb, pbRes, dwSize);
	delete [] pbRes;
}

void vmsFDMCustomizations::DecryptFile(vmsMemFile &file)
{
	DWORD dwPWDInfo;
	file.ReadFile (&dwPWDInfo, sizeof (DWORD));
	set_Key (dwPWDInfo);

	LPBYTE pb = file.get_FileBuffer () + 4;
	DWORD dwSize = file.get_FileBufferSize () - 4;
	LPBYTE pbRes = new BYTE [dwSize];
	m_xor.Decrypt (pb, pb, dwSize);
	m_des.Decrypt (pb, pbRes, dwSize);
	CopyMemory (pb, pbRes, dwSize);
	delete [] pbRes;
}

DWORD vmsFDMCustomizations::get_AffiliateID()
{
	return m_dwAffiliateID;
}

void vmsFDMCustomizations::set_AffiliateID(DWORD dw)
{
	m_dwAffiliateID = dw;
}

BOOL vmsFDMCustomizations::get_ShowFDMCustBtn()
{
	return m_bShowFDMCustBtn;
}

void vmsFDMCustomizations::set_ShowFDMCustBtn(BOOL b)
{
	m_bShowFDMCustBtn = b;
}

void vmsFDMCustomizations::set_Key(int iKey)
{
	char szKey [100];

	szKey [0] = 'F'; szKey [1] = 'D'; szKey [2] = 'M';
	szKey [3] = 'C'; szKey [4] = '_'; szKey [5] = 'F';
	szKey [6] = 'K'; szKey [7] = '0';

	switch (iKey)
	{
	case 0:		
		break;

	case 1:
		szKey [5] = 'S'; szKey [7] = '1';
		break;

	case 2:
		szKey [5] = 'P'; szKey [7] = '2';
		break;

	default:
		throw _pszFDMCustomizationsErr;
	}

	set_DESKey ((DES_KEY)szKey);
	m_iKey = iKey;
}
