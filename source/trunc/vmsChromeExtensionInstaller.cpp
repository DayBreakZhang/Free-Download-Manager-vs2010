/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "StdAfx.h"

#include <fstream>
#include "picojson.h"

#include "vmsChromeExtensionInstaller.h"

using namespace std;
using namespace picojson;

#define EXT_ID "ahmpjcflkgiildlgicmcieglgoilbfdp" 

#define BUFFER_SIZE MAX_PATH*2
static TCHAR buffer[BUFFER_SIZE];

bool vmsChromeExtensionInstaller::IsInstalled()
{
	

	memset(buffer, 0, BUFFER_SIZE*sizeof(TCHAR));
	if(S_OK != SHGetFolderPath(NULL, CSIDL_LOCAL_APPDATA, NULL, SHGFP_TYPE_CURRENT, buffer))
		return false;

	_tcscat(buffer, _T("\\Google\\Chrome\\User Data\\Default\\Extensions\\"));
	_tcscat(buffer, _T(EXT_ID));

	DWORD dwAttrs = GetFileAttributes(buffer);
	if(dwAttrs == INVALID_FILE_ATTRIBUTES)
		return false;
	if(dwAttrs & FILE_ATTRIBUTE_DIRECTORY)
		return true;

	return false;
}

static bool DOT(value& json, const string& field)
{
	if(!json.is<object>())
		return false;
	object obj = json.get<object>();
	if(obj.count(field) == 0)
		return false;
	json = obj[field];
	return true;
}

bool vmsChromeExtensionInstaller::Enabled(bool& isEnabled)
{
	

	memset(buffer, 0, BUFFER_SIZE*sizeof(TCHAR));
	if(S_OK != SHGetFolderPath(NULL, CSIDL_LOCAL_APPDATA, NULL, SHGFP_TYPE_CURRENT, buffer))
		return false;

	_tcscat(buffer, _T("\\Google\\Chrome\\User Data\\Default\\Preferences"));

	ifstream prefs(buffer);
	if(!prefs)
		return false;

	istream_iterator<char> input(prefs);
	value json; string err;
	parse(json, input, istream_iterator<char>(), &err);
	if (!err.empty())
		return false;
	
	bool res = 
		DOT(json, "extensions") &&
		DOT(json, "settings") &&
		DOT(json, EXT_ID) &&
		DOT(json, "state");
	if(!res)
		return false;
	if(!json.is<int>())
		return false;
	isEnabled = json.get<double>() != 0;
	return true;
}

BOOL vmsChromeExtensionInstaller::Install()
{
	return RunChrome(_T("--install-from-webstore=") _T(EXT_ID));
}

void vmsChromeExtensionInstaller::Enable()
{
	
	Uninstall();
	Install();
}

BOOL vmsChromeExtensionInstaller::Uninstall()
{
	return RunChrome(_T("--uninstall-extension=") _T(EXT_ID));
}

BOOL vmsChromeExtensionInstaller::RunChrome(const TCHAR* parameters)
{
	SHELLEXECUTEINFO ShExecInfo;
	ShExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
	ShExecInfo.fMask = SEE_MASK_NOCLOSEPROCESS | SEE_MASK_FLAG_NO_UI;
	ShExecInfo.hwnd = NULL;
	ShExecInfo.lpVerb = NULL;
	ShExecInfo.lpFile = _T("chrome.exe");        
	ShExecInfo.lpParameters = parameters;
	ShExecInfo.lpDirectory = NULL;
	ShExecInfo.nShow = SW_NORMAL;
	ShExecInfo.hInstApp = NULL; 
	BOOL ret = ShellExecuteEx(&ShExecInfo);
	if(ret)
		WaitForSingleObject(ShExecInfo.hProcess,INFINITE);
	return ret;
}
