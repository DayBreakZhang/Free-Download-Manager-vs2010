/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include <windows.h>
#include "npapi.h"
#include "npupp.h"
#include <objbase.h>
#include "..\Fdm.h"
#include <comdef.h>
#include "resource.h"

HICON _Icon = NULL;
NPPluginFuncs* g_plugFuncs;
HINSTANCE _hModule;
const LPCSTR _pszWndClass = "FDM OpNetCatcher wnd class";

LRESULT WINAPI WndProc (HWND hWnd, UINT uMsg, WPARAM wp, LPARAM lp);

BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  reason, 
                       LPVOID lpReserved
					 )
{
	switch (reason)
	{
		case DLL_PROCESS_ATTACH:
			CoInitialize (NULL);
			_hModule = (HINSTANCE) hModule;
			_Icon = LoadIcon ((HINSTANCE)hModule, MAKEINTRESOURCE (IDI_FDM));
			break;

		case DLL_PROCESS_DETACH:
			CoUninitialize ();
			break;
	}
	
	return TRUE;
}

void NPP_URLNotify (NPP instance, const char* url, NPReason reason, void* notifyData)
{

}

NPNetscapeFuncs *_pNFuncs;
short _stdcall NP_Initialize (NPNetscapeFuncs *p)
{	

	_pNFuncs = p;

	int navMinorVers = p->version & 0xFF;

	if (navMinorVers >= NPVERS_HAS_NOTIFICATION)
		g_plugFuncs->urlnotify = NPP_URLNotify;
	
	if (navMinorVers >= NPVERS_HAS_LIVECONNECT) 
		g_plugFuncs->javaClass = NULL;

	WNDCLASSEX wc;
	wc.cbSize = sizeof (wc);
	wc.style = 0;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = _hModule;
	wc.hbrBackground = (HBRUSH) (COLOR_WINDOW+1);
	wc.hCursor = LoadCursor (_hModule, IDC_ARROW);
	wc.hIcon = NULL;
	wc.hIconSm = NULL;
	wc.lpszClassName = _pszWndClass;
	wc.lpszMenuName = NULL;
	wc.style = 0;
	RegisterClassEx (&wc);

	return 0;
}

NPError WINAPI NP_Shutdown()
{
	
	UnregisterClass (_pszWndClass, _hModule);
    return NPERR_NO_ERROR;
}

void UrlToFdm (LPCSTR pszUrl)
{
	IWGUrlReceiver* wg;
	HRESULT hr;
	if (FAILED (hr=CoCreateInstance (CLSID_WGUrlReceiver, NULL, CLSCTX_ALL, IID_IWGUrlReceiver, (void**) &wg)))
	{
		char szMsg [1000];
		lstrcpy (szMsg, "Free Download Manager is not properly installed! Please reinstall Free Download Manager\n\nIf you want to download with your browser please remove \"npfdm.dll\" file in the Plugin directory of your browser.\n\nError code: ");
		char sz [100];
		_itoa_s (hr, sz, 100, 16);
		lstrcat (szMsg, sz);
		MessageBox (NULL, szMsg, "Error", MB_ICONERROR);
		return;
	}

	_bstr_t url = pszUrl;
	wg->put_Url (url);
	wg->AddDownload ();
	wg->Release ();
}

DWORD WINAPI _threadUrlToFdm (LPVOID lp)
{
	CoInitialize (NULL);
	UrlToFdm ((LPCSTR) lp);
	delete [] (LPSTR) lp;
	CoUninitialize ();
	return 0;
}

NPError NPP_NewStream (NPP npp, NPMIMEType, NPStream* stream, NPBool, uint16* stype)
{
	DWORD dw;
	int nLen = strlen (stream->url) + 1;
	char *url = new char [nLen];
	strcpy_s (url, nLen, stream->url);
	CloseHandle (CreateThread (NULL, 0, _threadUrlToFdm, (void*)url, 0, &dw));
	*stype = NP_NORMAL;
	return NPERR_GENERIC_ERROR;
	
}

NPError NPP_New (NPMIMEType, NPP npp, uint16, int16, char* arg [], char *argv [], NPSavedData*)
{
	
	if (npp == NULL)
		return NPERR_GENERIC_ERROR;

	npp->pdata = NULL;

	return 0;
}

NPError NPP_Destroy (NPP, NPSavedData** pp)
{
	
	return NPERR_NO_ERROR;
}

LRESULT WINAPI WndProc (HWND hWnd, UINT uMsg, WPARAM wp, LPARAM lp)
{
	
	switch (uMsg)
	{
		case WM_PAINT:
			PAINTSTRUCT ps;
			HDC dc = BeginPaint (hWnd, &ps);
			
			SelectObject (dc, GetStockObject (WHITE_BRUSH));
			SelectObject (dc, GetStockObject (WHITE_PEN));
			RECT rc;
			GetClientRect (hWnd, &rc);
			Rectangle (dc, rc.left, rc.top, rc.right, rc.bottom);
			DrawIcon (dc, 5, 5, _Icon);
			LPCSTR pszMsg = "Download was transferred to Free Download Manager...\nPlease use \"Back\" button to go back";
			RECT rcT = rc;
			rcT.left = 40; rcT.top = 5;
			DrawText (dc, pszMsg, lstrlen (pszMsg), &rcT, DT_LEFT | DT_TOP);
			EndPaint (hWnd, &ps);
			return 0;
		
	}

	return DefWindowProc (hWnd, uMsg, wp, lp);
}

NPError NPP_SetWindow (NPP npp, NPWindow* wnd)
{
	

	if (wnd == NULL)
		return NPERR_GENERIC_ERROR;
	if (npp == NULL)
		return NPERR_INVALID_INSTANCE_ERROR;
	if (wnd->window == NULL)
		return NPERR_NO_ERROR;

	HWND hWndParent = (HWND) wnd->window;

	if (npp->pdata == NULL)
	{
		npp->pdata = CreateWindowEx (0, _pszWndClass, "", WS_CHILD | WS_VISIBLE, 
			0, 0, wnd->width, wnd->height, hWndParent, NULL, _hModule, NULL);
	}
	else
	{
		MoveWindow ((HWND) npp->pdata, 0, 0, wnd->width, wnd->height, TRUE);
	}

	return NPERR_NO_ERROR;
}

NPError NPP_DestroyStream (NPP, NPStream*, NPReason)
{
	
	return NPERR_GENERIC_ERROR;
}

void NPP_StreamAsFile (NPP, NPStream*, const char* file)
{

}

int32 NPP_WriteReady (NPP npp, NPStream* stream)
{
	

	return 1;
}

int32 NPP_Write (NPP npp, NPStream* stream, int32 off, int32 len, void*)
{
	

	return -1;
}

void NPP_Print (NPP, NPPrint*)
{

}

int16 NPP_HandleEvent (NPP, void* ev)
{
	return NPERR_GENERIC_ERROR;
}

short _stdcall NP_GetEntryPoints (NPPluginFuncs* p)
{
	
	if (p == NULL)
		return NPERR_INVALID_FUNCTABLE_ERROR;

	ZeroMemory (p, p->size);

	p->version = (NP_VERSION_MAJOR << 8) | NP_VERSION_MINOR;
	p->newp = NPP_New;
	p->destroy = NPP_Destroy;
	p->setwindow = NPP_SetWindow;
	p->newstream = NPP_NewStream;
	p->destroystream = NPP_DestroyStream;
	p->asfile = NPP_StreamAsFile;
	p->writeready = NPP_WriteReady;
	p->write =  NPP_Write;
	p->print = NPP_Print;
	p->event = 0; 

	g_plugFuncs = p;
	
	return 0;
}

