/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#pragma once
class vmsWinSecurity
{
public:
	static bool IsVistaOrHigher () 
	{
		OSVERSIONINFO osver;
		osver.dwOSVersionInfoSize = sizeof (OSVERSIONINFO);
		return GetVersionEx (&osver) && osver.dwPlatformId == VER_PLATFORM_WIN32_NT && 
			osver.dwMajorVersion > 5;
	}
	static bool RunAsDesktopUser (LPCWSTR pwszApp, LPWSTR pwszCmdLine, LPCWSTR pwszCurrDir, STARTUPINFOW& si, PROCESS_INFORMATION& pi)
	{
		typedef BOOL (WINAPI *FNCreateProcessWithTokenW)(HANDLE hToken, DWORD dwLogonFlags, LPCWSTR lpApplicationName, LPWSTR lpCommandLine, DWORD dwCreationFlags, LPVOID lpEnvironment, LPCWSTR lpCurrentDirectory, LPSTARTUPINFOW lpStartupInfo, LPPROCESS_INFORMATION lpProcessInfo);
		FNCreateProcessWithTokenW pfnCreateProcessWithTokenW = (FNCreateProcessWithTokenW) GetProcAddress (GetModuleHandle (_T ("advapi32.dll")), "CreateProcessWithTokenW");
		if (!pfnCreateProcessWithTokenW)
			return false;

		ATL::CAccessToken processToken;
		if (!processToken.GetProcessToken (TOKEN_ADJUST_PRIVILEGES))
			return false;

		
		TOKEN_PRIVILEGES tkp;
		tkp.PrivilegeCount = 1;
		LookupPrivilegeValue (NULL, SE_INCREASE_QUOTA_NAME, &tkp.Privileges[0].Luid);
		tkp.Privileges [0].Attributes = SE_PRIVILEGE_ENABLED;
		if (!AdjustTokenPrivileges (processToken.GetHandle (), FALSE, &tkp, 0, NULL, NULL))
			return false;

		
		
		
		
		HWND hwndDesktop = GetShellWindow ();
		if (!hwndDesktop)
			return false;

		DWORD dwDesktopPID = 0;
		GetWindowThreadProcessId (hwndDesktop, &dwDesktopPID);
		if (!dwDesktopPID)
			return false;

		HANDLE hDesktopProcess = OpenProcess (PROCESS_QUERY_INFORMATION, FALSE, dwDesktopPID);
		if (!hDesktopProcess)
			return false;

		ATL::CAccessToken desktopProcessToken;
		if (!desktopProcessToken.GetProcessToken (TOKEN_DUPLICATE, hDesktopProcess))
			return false;

		HANDLE hTmp = NULL;
		DuplicateTokenEx (desktopProcessToken.GetHandle (), TOKEN_QUERY | TOKEN_ASSIGN_PRIMARY | TOKEN_DUPLICATE | TOKEN_ADJUST_DEFAULT | TOKEN_ADJUST_SESSIONID,
				NULL, SecurityImpersonation, TokenPrimary, &hTmp);
		if (!hTmp)
			return false;

		CloseHandle (hDesktopProcess);

		ATL::CAccessToken primaryToken;
		primaryToken.Attach (hTmp);

		return FALSE != pfnCreateProcessWithTokenW (primaryToken.GetHandle (), 0, pwszApp, pwszCmdLine, NULL, NULL, pwszCurrDir, &si, &pi);
	}

	static bool IsProcessElevated ()
	{
		ATL::CAccessToken processToken;
		if (!processToken.GetProcessToken (TOKEN_QUERY))
			return false;

		TOKEN_ELEVATION te = {0};
		DWORD dwReturnLength = 0;

		GetTokenInformation (processToken.GetHandle (), TokenElevation, &te, sizeof (te), &dwReturnLength);

		return te.TokenIsElevated != 0;
	}
};