/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsOleAccHelper.h"
#include <oleacc.h>

vmsOleAccHelper::vmsOleAccHelper()
{

}

vmsOleAccHelper::~vmsOleAccHelper()
{

}

IHTMLDocument2Ptr vmsOleAccHelper::GetDocumentFromHWND(HWND hwnd)
{
	UINT nMsg = RegisterWindowMessage ("WM_HTML_GETOBJECT");
	LRESULT lRes;
	SendMessageTimeout (hwnd, nMsg, 0, 0, SMTO_ABORTIFHUNG, 1000, (LPDWORD)&lRes);

	HMODULE hDll = LoadLibrary ("oleacc.dll");
	if (hDll == NULL)
		return NULL;
	LPFNOBJECTFROMLRESULT pfnObjectFromLresult = (LPFNOBJECTFROMLRESULT) GetProcAddress (hDll, "ObjectFromLresult");
	if (pfnObjectFromLresult == NULL)
		return NULL;
	IHTMLDocument2Ptr spDoc;
	HRESULT hr = pfnObjectFromLresult (lRes, IID_IHTMLDocument, 0, (void**)&spDoc);
	FreeLibrary (hDll);

	return spDoc;
}
