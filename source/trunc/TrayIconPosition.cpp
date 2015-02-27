/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "resource.h"
#include "TrayIconPosition.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

CTrayIconPosition::CTrayIconPosition()
{
	m_hWndOfIconOwner = NULL;
	m_iTrayIconID = -1;
	m_prDefaultPrecision = High;
	m_iPrecisions[0] = 60; 
	m_iPrecisions[1] = 30; 
	m_iPrecisions[2] = 10; 

	m_osVer.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
	GetVersionEx( &m_osVer );
}

CTrayIconPosition::~CTrayIconPosition()
{

}

void CTrayIconPosition::InitializePositionTracking(HWND hwndOfIconOwner, int iIconID)
{
	m_hWndOfIconOwner = hwndOfIconOwner;
	m_iTrayIconID = iIconID;
}

BOOL CTrayIconPosition::GetTrayIconPosition(CPoint& a_ptPoint, Precision a_ePrec)
{
	if(m_hWndOfIconOwner == NULL || m_iTrayIconID == -1)
	{
		return -1;
	}
	
	
	const int iOffsetX = 4;
	const int iOffsetY = 6;

	CRect rcDirectRect;

	BOOL bOK = FindOutPositionOfIconDirectly(m_hWndOfIconOwner, m_iTrayIconID, rcDirectRect);

	a_ptPoint.x = rcDirectRect.left + iOffsetX;
	a_ptPoint.y = rcDirectRect.top  + iOffsetY;
	return bOK;
}

void CTrayIconPosition::SetPrecisionTimeOuts(int iLowSec, int iMedSec, int iHighSec)
{
	m_iPrecisions[0] = iLowSec;
	m_iPrecisions[1] = iMedSec;
	m_iPrecisions[2] = iHighSec;
}

BOOL CALLBACK CTrayIconPosition::FindTrayWnd(HWND hwnd, LPARAM lParam)
{    
	TCHAR szClassName[256];
    GetClassName(hwnd, szClassName, 255);    
	if (_tcscmp(szClassName, _T("TrayNotifyWnd")) == 0)    
	{        
		HWND* pWnd = (HWND*)lParam;
		*pWnd = hwnd;
        return FALSE;    
	}    
	
	
	
	
	
	return TRUE;
}

BOOL CALLBACK CTrayIconPosition::FindToolBarInTrayWnd(HWND hwnd, LPARAM lParam)
{    
	TCHAR szClassName[256];
    GetClassName(hwnd, szClassName, 255);    
	if (_tcscmp(szClassName, _T("ToolbarWindow32")) == 0)    
	{        
		HWND* pWnd = (HWND*)lParam;
		*pWnd = hwnd;
        return FALSE;    
	}    
	return TRUE;
}

HWND CTrayIconPosition::GetTrayNotifyWnd(BOOL a_bSeekForEmbedToolbar)
{
	HWND hWndTrayNotifyWnd = NULL;
	
    HWND hWndShellTrayWnd = FindWindow(_T("Shell_TrayWnd"), NULL);
    if (hWndShellTrayWnd)    
	{        
		EnumChildWindows(hWndShellTrayWnd, CTrayIconPosition::FindTrayWnd, (LPARAM)&hWndTrayNotifyWnd);   
		
		if(hWndTrayNotifyWnd && IsWindow(hWndTrayNotifyWnd))
		{
			HWND hWndToolBarWnd = NULL;
			EnumChildWindows(hWndTrayNotifyWnd, CTrayIconPosition::FindToolBarInTrayWnd, (LPARAM)&hWndToolBarWnd);   
			if(hWndToolBarWnd)
			{
				return hWndToolBarWnd;
			}
		}

		return hWndTrayNotifyWnd;
	}  

	return hWndShellTrayWnd;
}

CRect CTrayIconPosition::GetTrayWndRect()
{    
	CRect rect(0,0,0,0);
	
	HWND hWndTrayWnd = GetTrayNotifyWnd(FALSE);
	if(hWndTrayWnd)
	{
		GetWindowRect(hWndTrayWnd, &rect);
		return rect;
	}

	int nWidth  = GetSystemMetrics(SM_CXSCREEN);
    int nHeight = GetSystemMetrics(SM_CYSCREEN);
    rect.SetRect(nWidth-40, nHeight-20, nWidth, nHeight);

	return rect;
}

BOOL CTrayIconPosition::FindOutPositionOfIconDirectly(const HWND a_hWndOwner, const int a_iButtonID, CRect& a_rcIcon)
{
	
	HWND hWndTray = GetTrayNotifyWnd(TRUE);
    if (hWndTray == NULL)    
	{
		return FALSE;
	}

	
	DWORD dwTrayProcessID = (DWORD)-1;
	GetWindowThreadProcessId(hWndTray, &dwTrayProcessID);
	if(dwTrayProcessID == DWORD(-1))
	{
		return FALSE;
	}

	HANDLE hTrayProc = OpenProcess(PROCESS_ALL_ACCESS, 0, dwTrayProcessID);
	if(hTrayProc == NULL)
	{
		return FALSE;
	}
 
	
	int iButtonsCount = SendMessage(hWndTray, TB_BUTTONCOUNT, 0, 0);

	
	
	
	
	
	LPVOID lpData = VirtualAllocEx(hTrayProc, NULL, sizeof(TBBUTTON), MEM_COMMIT, PAGE_READWRITE);
	if( lpData == NULL || iButtonsCount < 1 )
	{
		CloseHandle(hTrayProc);
		return FALSE;
	}

	BOOL bIconFound = FALSE;

	for(int iButton=0; iButton<iButtonsCount; iButton++)
	{
		

		DWORD dwBytesRead = 0;
		TBBUTTON buttonData;
		SendMessage(hWndTray, TB_GETBUTTON, iButton, (LPARAM)lpData);
		ReadProcessMemory(hTrayProc, lpData, &buttonData, sizeof(TBBUTTON), &dwBytesRead);
		if(dwBytesRead < sizeof(TBBUTTON))
		{
			continue;
		}

		
		DWORD dwExtraData[2] = { 0,0 };
		dwBytesRead = 0;
		ReadProcessMemory(hTrayProc, (LPVOID)buttonData.dwData, dwExtraData, sizeof(dwExtraData), &dwBytesRead);
		if(dwBytesRead < sizeof(dwExtraData))
		{
			continue;
		}

		HWND hWndOfIconOwner = (HWND) dwExtraData[0];
		int  iIconId		 = (int)  dwExtraData[1];
		
		if(hWndOfIconOwner != a_hWndOwner || iIconId != a_iButtonID)
		{
			continue;
		}
		
		
		if( buttonData.fsState & TBSTATE_HIDDEN )
		{
			break;
		}

		
		RECT rcPosition = {0,0};
		SendMessage(hWndTray, TB_GETITEMRECT, iButton, (LPARAM)lpData);
		dwBytesRead = 0;
		ReadProcessMemory(hTrayProc, lpData, &rcPosition, sizeof(RECT), &dwBytesRead);

		if(dwBytesRead < sizeof(RECT))
		{
			continue;
		}

		MapWindowPoints(hWndTray, NULL, (LPPOINT)&rcPosition, 2);
		a_rcIcon = rcPosition;
		
		bIconFound = TRUE;
		break;
	}

	if(bIconFound == FALSE)
	{
		a_rcIcon = GetTrayWndRect(); 
		a_rcIcon.left -= 16 + 2;
		if (a_rcIcon.Height () > 16)
		{
			a_rcIcon.top += (a_rcIcon.Height () - 16) / 2;
			a_rcIcon.bottom = a_rcIcon.top + 16;
		}
	}

	VirtualFreeEx(hTrayProc, lpData, NULL, MEM_RELEASE);
	CloseHandle(hTrayProc);

	return bIconFound;	
}

void CTrayIconPosition::Invalidate()
{
	m_tLastUpdate = CTime(2000,1,1,1,1,1);
}
