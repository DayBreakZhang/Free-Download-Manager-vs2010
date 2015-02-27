/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "iefdmdm.h"
#include "vmsIeHelper.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

vmsIeHelper::vmsIeHelper()
{

}

vmsIeHelper::~vmsIeHelper()
{

}

void vmsIeHelper::GetIeWindows(vector <HWND> &vWnds)
{
	HWND hwnd = NULL;
	DWORD dwCPID = GetCurrentProcessId ();
	
	do
	{
		hwnd = FindWindowEx (NULL, hwnd, _T ("IEFrame"), NULL);
		if (hwnd)
		{
			DWORD dwPID = 0;
			GetWindowThreadProcessId (hwnd, &dwPID);
			if (dwPID == dwCPID)
				vWnds.push_back (hwnd);
		}
	}
	while (hwnd != NULL);
}

int vmsIeHelper::GetTabCount(HWND hwndIeWindow)
{
	HWND hwnd = NULL;
	int cTabs = 0;

	do 
	{
		hwnd = FindWindowEx (hwndIeWindow, hwnd, _T ("Frame Tab"), NULL);
		if (hwnd)
			cTabs++;
	} 
	while (hwnd != NULL);

	if (!cTabs)
		cTabs = 1;

	return cTabs;
}
