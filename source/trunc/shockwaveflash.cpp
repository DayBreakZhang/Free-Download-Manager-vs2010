/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "shockwaveflash.h"

IMPLEMENT_DYNCREATE(CShockwaveFlash, CWnd)

long CShockwaveFlash::GetReadyState()
{
	long result;
	InvokeHelper(DISPID_READYSTATE, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

long CShockwaveFlash::GetTotalFrames()
{
	long result;
	InvokeHelper(0x7c, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

BOOL CShockwaveFlash::GetPlaying()
{
	BOOL result;
	InvokeHelper(0x7d, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CShockwaveFlash::SetPlaying(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x7d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

long CShockwaveFlash::GetQuality()
{
	long result;
	InvokeHelper(0x69, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CShockwaveFlash::SetQuality(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x69, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long CShockwaveFlash::GetScaleMode()
{
	long result;
	InvokeHelper(0x78, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CShockwaveFlash::SetScaleMode(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x78, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long CShockwaveFlash::GetAlignMode()
{
	long result;
	InvokeHelper(0x79, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CShockwaveFlash::SetAlignMode(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x79, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long CShockwaveFlash::GetBackgroundColor()
{
	long result;
	InvokeHelper(0x7b, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CShockwaveFlash::SetBackgroundColor(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x7b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

BOOL CShockwaveFlash::GetLoop()
{
	BOOL result;
	InvokeHelper(0x6a, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CShockwaveFlash::SetLoop(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x6a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

CString CShockwaveFlash::GetMovie()
{
	CString result;
	InvokeHelper(0x66, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CShockwaveFlash::SetMovie(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x66, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

long CShockwaveFlash::GetFrameNum()
{
	long result;
	InvokeHelper(0x6b, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CShockwaveFlash::SetFrameNum(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x6b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

void CShockwaveFlash::SetZoomRect(long left, long top, long right, long bottom)
{
	static BYTE parms[] =
		VTS_I4 VTS_I4 VTS_I4 VTS_I4;
	InvokeHelper(0x6d, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 left, top, right, bottom);
}

void CShockwaveFlash::Zoom(long factor)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x76, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 factor);
}

void CShockwaveFlash::Pan(long x, long y, long mode)
{
	static BYTE parms[] =
		VTS_I4 VTS_I4 VTS_I4;
	InvokeHelper(0x77, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 x, y, mode);
}

void CShockwaveFlash::Play()
{
	InvokeHelper(0x70, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void CShockwaveFlash::Stop()
{
	InvokeHelper(0x71, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void CShockwaveFlash::Back()
{
	InvokeHelper(0x72, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void CShockwaveFlash::Forward()
{
	InvokeHelper(0x73, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void CShockwaveFlash::Rewind()
{
	InvokeHelper(0x74, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void CShockwaveFlash::StopPlay()
{
	InvokeHelper(0x7e, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void CShockwaveFlash::GotoFrame(long FrameNum)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x7f, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 FrameNum);
}

long CShockwaveFlash::CurrentFrame()
{
	long result;
	InvokeHelper(0x80, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
	return result;
}

BOOL CShockwaveFlash::IsPlaying()
{
	BOOL result;
	InvokeHelper(0x81, DISPATCH_METHOD, VT_BOOL, (void*)&result, NULL);
	return result;
}

long CShockwaveFlash::PercentLoaded()
{
	long result;
	InvokeHelper(0x82, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
	return result;
}

BOOL CShockwaveFlash::FrameLoaded(long FrameNum)
{
	BOOL result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x83, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
		FrameNum);
	return result;
}

long CShockwaveFlash::FlashVersion()
{
	long result;
	InvokeHelper(0x84, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
	return result;
}

CString CShockwaveFlash::GetWMode()
{
	CString result;
	InvokeHelper(0x85, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CShockwaveFlash::SetWMode(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x85, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CShockwaveFlash::GetSAlign()
{
	CString result;
	InvokeHelper(0x86, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CShockwaveFlash::SetSAlign(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x86, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

BOOL CShockwaveFlash::GetMenu()
{
	BOOL result;
	InvokeHelper(0x87, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CShockwaveFlash::SetMenu(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x87, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

CString CShockwaveFlash::GetBase()
{
	CString result;
	InvokeHelper(0x88, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CShockwaveFlash::SetBase(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x88, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CShockwaveFlash::GetScale()
{
	CString result;
	InvokeHelper(0x89, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CShockwaveFlash::SetScale(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x89, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

BOOL CShockwaveFlash::GetDeviceFont()
{
	BOOL result;
	InvokeHelper(0x8a, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CShockwaveFlash::SetDeviceFont(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x8a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL CShockwaveFlash::GetEmbedMovie()
{
	BOOL result;
	InvokeHelper(0x8b, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CShockwaveFlash::SetEmbedMovie(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x8b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

CString CShockwaveFlash::GetBGColor()
{
	CString result;
	InvokeHelper(0x8c, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CShockwaveFlash::SetBGColor(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x8c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CShockwaveFlash::GetQuality2()
{
	CString result;
	InvokeHelper(0x8d, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CShockwaveFlash::SetQuality2(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x8d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

void CShockwaveFlash::LoadMovie(long layer, LPCTSTR url)
{
	static BYTE parms[] =
		VTS_I4 VTS_BSTR;
	InvokeHelper(0x8e, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 layer, url);
}

void CShockwaveFlash::TGotoFrame(LPCTSTR target, long FrameNum)
{
	static BYTE parms[] =
		VTS_BSTR VTS_I4;
	InvokeHelper(0x8f, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 target, FrameNum);
}

void CShockwaveFlash::TGotoLabel(LPCTSTR target, LPCTSTR label)
{
	static BYTE parms[] =
		VTS_BSTR VTS_BSTR;
	InvokeHelper(0x90, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 target, label);
}

long CShockwaveFlash::TCurrentFrame(LPCTSTR target)
{
	long result;
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x91, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		target);
	return result;
}

CString CShockwaveFlash::TCurrentLabel(LPCTSTR target)
{
	CString result;
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x92, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms,
		target);
	return result;
}

void CShockwaveFlash::TPlay(LPCTSTR target)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x93, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 target);
}

void CShockwaveFlash::TStopPlay(LPCTSTR target)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x94, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 target);
}

void CShockwaveFlash::SetVariable(LPCTSTR name, LPCTSTR value)
{
	static BYTE parms[] =
		VTS_BSTR VTS_BSTR;
	InvokeHelper(0x97, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 name, value);
}

CString CShockwaveFlash::GetVariable(LPCTSTR name)
{
	CString result;
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x98, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms,
		name);
	return result;
}

void CShockwaveFlash::TSetProperty(LPCTSTR target, long property, LPCTSTR value)
{
	static BYTE parms[] =
		VTS_BSTR VTS_I4 VTS_BSTR;
	InvokeHelper(0x99, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 target, property, value);
}

CString CShockwaveFlash::TGetProperty(LPCTSTR target, long property)
{
	CString result;
	static BYTE parms[] =
		VTS_BSTR VTS_I4;
	InvokeHelper(0x9a, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms,
		target, property);
	return result;
}

void CShockwaveFlash::TCallFrame(LPCTSTR target, long FrameNum)
{
	static BYTE parms[] =
		VTS_BSTR VTS_I4;
	InvokeHelper(0x9b, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 target, FrameNum);
}

void CShockwaveFlash::TCallLabel(LPCTSTR target, LPCTSTR label)
{
	static BYTE parms[] =
		VTS_BSTR VTS_BSTR;
	InvokeHelper(0x9c, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 target, label);
}

void CShockwaveFlash::TSetPropertyNum(LPCTSTR target, long property, double value)
{
	static BYTE parms[] =
		VTS_BSTR VTS_I4 VTS_R8;
	InvokeHelper(0x9d, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 target, property, value);
}

double CShockwaveFlash::TGetPropertyNum(LPCTSTR target, long property)
{
	double result;
	static BYTE parms[] =
		VTS_BSTR VTS_I4;
	InvokeHelper(0x9e, DISPATCH_METHOD, VT_R8, (void*)&result, parms,
		target, property);
	return result;
}

double CShockwaveFlash::TGetPropertyAsNumber(LPCTSTR target, long property)
{
	double result;
	static BYTE parms[] =
		VTS_BSTR VTS_I4;
	InvokeHelper(0xac, DISPATCH_METHOD, VT_R8, (void*)&result, parms,
		target, property);
	return result;
}

CString CShockwaveFlash::GetSWRemote()
{
	CString result;
	InvokeHelper(0x9f, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CShockwaveFlash::SetSWRemote(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x9f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CShockwaveFlash::GetFlashVars()
{
	CString result;
	InvokeHelper(0xaa, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CShockwaveFlash::SetFlashVars(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0xaa, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CShockwaveFlash::GetAllowScriptAccess()
{
	CString result;
	InvokeHelper(0xab, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CShockwaveFlash::SetAllowScriptAccess(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0xab, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CShockwaveFlash::GetMovieData()
{
	CString result;
	InvokeHelper(0xbe, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CShockwaveFlash::SetMovieData(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0xbe, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

LPUNKNOWN CShockwaveFlash::GetInlineData()
{
	LPUNKNOWN result;
	InvokeHelper(0xbf, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
	return result;
}

void CShockwaveFlash::SetInlineData(LPUNKNOWN newValue)
{
	static BYTE parms[] =
		VTS_UNKNOWN;
	InvokeHelper(0xbf, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

BOOL CShockwaveFlash::GetSeamlessTabbing()
{
	BOOL result;
	InvokeHelper(0xc0, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CShockwaveFlash::SetSeamlessTabbing(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0xc0, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

void CShockwaveFlash::EnforceLocalSecurity()
{
	InvokeHelper(0xc1, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

BOOL CShockwaveFlash::GetProfile()
{
	BOOL result;
	InvokeHelper(0xc2, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CShockwaveFlash::SetProfile(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0xc2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

CString CShockwaveFlash::GetProfileAddress()
{
	CString result;
	InvokeHelper(0xc3, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CShockwaveFlash::SetProfileAddress(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0xc3, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

long CShockwaveFlash::GetProfilePort()
{
	long result;
	InvokeHelper(0xc4, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CShockwaveFlash::SetProfilePort(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0xc4, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

CString CShockwaveFlash::CallFunction(LPCTSTR request)
{
	CString result;
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0xc6, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms,
		request);
	return result;
}

void CShockwaveFlash::SetReturnValue(LPCTSTR returnValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0xc7, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 returnValue);
}

void CShockwaveFlash::DisableLocalSecurity()
{
	InvokeHelper(0xc8, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

CString CShockwaveFlash::GetAllowNetworking()
{
	CString result;
	InvokeHelper(0xc9, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CShockwaveFlash::SetAllowNetworking(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0xc9, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CShockwaveFlash::GetAllowFullScreen()
{
	CString result;
	InvokeHelper(0xca, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CShockwaveFlash::SetAllowFullScreen(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0xca, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}
