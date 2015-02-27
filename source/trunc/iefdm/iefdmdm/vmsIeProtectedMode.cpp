/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "iefdmdm.h"
#include "vmsIeProtectedMode.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

vmsIeProtectedMode::vmsIeProtectedMode()
{

}

vmsIeProtectedMode::~vmsIeProtectedMode()
{

}

HRESULT vmsIeProtectedMode::IEIsProtectedModeProcess(BOOL *pbResult)
{
	HMODULE hDll = GetModuleHandle (_T ("ieframe.dll"));
	if (!hDll)
		return E_NOTIMPL;

	typedef HRESULT (__stdcall *FNIPMP)(BOOL*);
	FNIPMP pfn = (FNIPMP)GetProcAddress (hDll, "IEIsProtectedModeProcess");
	if (!pfn)
		return E_NOTIMPL;

	return pfn (pbResult);
}

HRESULT vmsIeProtectedMode::IEShowSaveFileDialog(HWND hwnd, LPCWSTR lpwstrInitialFileName, LPCWSTR lpwstrInitialDir, LPCWSTR lpwstrFilter, LPCWSTR lpwstrDefExt, DWORD dwFilterIndex, DWORD dwFlags, LPWSTR *lppwstrDestinationFilePath, HANDLE *phState)
{
	HMODULE hDll = GetModuleHandle (_T ("ieframe.dll"));
	if (!hDll)
		return E_NOTIMPL;

	typedef HRESULT (__stdcall *FNSSFD)(HWND hwnd, LPCWSTR lpwstrInitialFileName, LPCWSTR lpwstrInitialDir, LPCWSTR lpwstrFilter, LPCWSTR lpwstrDefExt, DWORD dwFilterIndex, DWORD dwFlags, LPWSTR *lppwstrDestinationFilePath, HANDLE *phState);
	FNSSFD pfn = (FNSSFD)GetProcAddress (hDll, "IEShowSaveFileDialog");
	if (!pfn)
		return E_NOTIMPL;

	return pfn (hwnd, lpwstrInitialFileName, lpwstrInitialDir, lpwstrFilter, lpwstrDefExt, dwFilterIndex, dwFlags, lppwstrDestinationFilePath, phState);
}

HRESULT vmsIeProtectedMode::IESaveFile(HANDLE hState, LPWSTR lpwstrSourceFile)
{
	HMODULE hDll = GetModuleHandle (_T ("ieframe.dll"));
	if (!hDll)
		return E_NOTIMPL;

	typedef HRESULT (__stdcall *FNSF)(HANDLE, LPWSTR);
	FNSF pfn = (FNSF)GetProcAddress (hDll, "IESaveFile");
	if (!pfn)
		return E_NOTIMPL;

	return pfn (hState, lpwstrSourceFile);
}

HRESULT vmsIeProtectedMode::IECancelSaveFile(HANDLE hState)
{
	HMODULE hDll = GetModuleHandle (_T ("ieframe.dll"));
	if (!hDll)
		return E_NOTIMPL;
	
	typedef HRESULT (__stdcall *FNCSF)(HANDLE);
	FNCSF pfn = (FNCSF)GetProcAddress (hDll, "IECancelSaveFile");
	if (!pfn)
		return E_NOTIMPL;
	
	return pfn (hState);
}
