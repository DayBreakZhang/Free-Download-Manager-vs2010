/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSAPPSETTINGS_H__052B18B6_1A70_4801_8B12_E440F61737A4__INCLUDED_)
#define AFX_VMSAPPSETTINGS_H__052B18B6_1A70_4801_8B12_E440F61737A4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class vmsAppSettings  
{
public:
	void View_UploadDoneDlg (BOOL b);
	BOOL View_UploadDoneDlg();
	BOOL GetProfileBinary (LPCSTR pszSecion, LPCSTR pszName, LPBYTE* ppData, UINT* pnDataSize);
	void WriteProfileBinary (LPCSTR pszSection, LPCSTR pszName, LPVOID pvData, UINT nDataSize);
	void View_SplitterRatio (LPCSTR pszName, float f);
	float View_SplitterRatio (LPCSTR pszName);
	vmsAppSettings();
	virtual ~vmsAppSettings();

};

#endif 
