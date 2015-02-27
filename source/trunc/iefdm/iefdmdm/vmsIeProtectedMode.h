/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSIEPROTECTEDMODE_H__CF8CCE85_F859_4564_B825_37F97272B4DC__INCLUDED_)
#define AFX_VMSIEPROTECTEDMODE_H__CF8CCE85_F859_4564_B825_37F97272B4DC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class vmsIeProtectedMode  
{
public:
	static HRESULT IECancelSaveFile (HANDLE hState);
	static HRESULT IESaveFile (HANDLE hState, LPWSTR lpwstrSourceFile);
	static HRESULT IEShowSaveFileDialog (HWND hwnd, LPCWSTR lpwstrInitialFileName, LPCWSTR lpwstrInitialDir, LPCWSTR lpwstrFilter, LPCWSTR lpwstrDefExt, DWORD dwFilterIndex, DWORD dwFlags, LPWSTR* lppwstrDestinationFilePath, HANDLE* phState);
	static HRESULT IEIsProtectedModeProcess (BOOL *pbResult);
	vmsIeProtectedMode();
	virtual ~vmsIeProtectedMode();

};

#endif 
