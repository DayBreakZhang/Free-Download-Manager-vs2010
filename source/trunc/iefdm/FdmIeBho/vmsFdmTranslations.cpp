/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "StdAfx.h"
#include "vmsFdmTranslations.h"

vmsFdmTranslations::vmsFdmTranslations()
{
	CRegKey keyFDM;
	if (ERROR_SUCCESS == keyFDM.Open (HKEY_CURRENT_USER, 
			"Software\\FreeDownloadManager.ORG\\Free Download Manager", KEY_READ))
	{
		char szPath [MAX_PATH] = ""; 
		DWORD dw = sizeof (szPath);
		keyFDM.QueryValue (szPath, "Path", &dw);
		if (*szPath)
		{
			if (szPath [lstrlen (szPath) - 1] != '\\')
				lstrcat (szPath, "\\");
		
			lstrcat (szPath, "Language");
		
			
			m_lm.Initialize (szPath);
		
			char szLang [100] = "English";	
			dw = sizeof (szLang);
			CRegKey key;
			key.Open (keyFDM, "Settings\\View", KEY_READ);
			
			key.QueryValue (szLang, "Language", &dw);
		
			int nIndex = m_lm.FindLngByName (szLang);
			if (nIndex != -1)
				m_lm.LoadLng (nIndex);
		}
	}
}

vmsFdmTranslations::~vmsFdmTranslations()
{

}

LPCSTR vmsFdmTranslations::GetString(int nIndex)
{
	return m_lm.GetString (nIndex);
}

vmsFdmTranslations& vmsFdmTranslations::o()
{
	static vmsFdmTranslations o;
	return o;
}
