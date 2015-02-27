/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsFdmAppMgr.h"
#include "FdmApp.h"
#include "MyMessageBox.h"

vmsFdmAppMgr::vmsFdmAppMgr()
{

}

vmsFdmAppMgr::~vmsFdmAppMgr()
{

}

BOOL vmsFdmAppMgr::IsBtInstalled()
{
	static int _r = -1;

	if (_r == -1)
	{
		if (GetFileAttributes (vmsBtSupport::getBtDllFileName ().c_str ()) == DWORD (-1))
			_r = FALSE;
		else if (vmsBtSupport::getBtDllVersion () < BTSUPP_DLL_MINVERREQ)
			_r = FALSE;
		else if (vmsBtSupport::getBtDllMinimumFdmBuildRequired () > getBuildNumber ())
			_r = FALSE;
		else
			_r = TRUE;
	}
	
	return _r;
}

BOOL vmsFdmAppMgr::IsMediaFeaturesInstalled()
{
	return GetFileAttributes (((CFdmApp*)AfxGetApp ())->m_strAppPath + "mediaconverter.dll") != DWORD (-1);
}

void vmsFdmAppMgr::ShowInstallMediaFeaturesMessage()
{
	MessageBox (NULL, LS (L_INST_MEDIA_FEATURES), "Free Download Manager", 0);
}

void vmsFdmAppMgr::ShowInstallBtMessage()
{
	MessageBox (NULL, LS (L_INST_BT_SUPPORT), "Free Download Manager", 0);
}

LPCSTR vmsFdmAppMgr::getBuildNumberAsString()
{
	static std::string str;
	if (!str.empty ())
		return str.c_str ();
	str = getVersion ()->m_appVersion.size () > 2 ? getVersion ()->m_appVersion [2].toString () : "???";
	return str.c_str ();
}

int vmsFdmAppMgr::getBuildNumber()
{
	return getVersion ()->m_appVersion.size () > 2 ? getVersion ()->m_appVersion [2].dwVal : -1;
}

const vmsBinaryFileVersionInfo* vmsFdmAppMgr::getVersion()
{
	static vmsBinaryFileVersionInfo bfvi;
	if (bfvi.m_appVersion.size () == 0)
	{
		TCHAR tsz [MAX_PATH];
		GetModuleFileName (NULL, tsz, MAX_PATH);
		bfvi.Retrieve (tsz);
	}
	return &bfvi;
}

LPCSTR vmsFdmAppMgr::getAppVersionedName()
{
	static std::string str;
	if (str.empty ())
	{
		str = getAppName ();
		str += ' ';
		str += getVersion ()->m_tstrProductVersion;
	}
	return str.c_str ();
}

LPCSTR vmsFdmAppMgr::getAppAgentName()
{
	static std::string str;
	if (str.empty ())
	{
		str = "FDM ";
		char sz [100];
		str += itoa (getVersion ()->m_appVersion [0].dwVal, sz, 10);
		str += ".x"; 
	}
	return str.c_str ();
}

LPCSTR vmsFdmAppMgr::getAppName()
{
	return getVersion ()->m_tstrProductName.c_str ();
}

BOOL vmsFdmAppMgr::MakeSureBtInstalled()
{
	if (Is9xME)
		return FALSE;

	if (_App.Bittorrent_Enable () == FALSE)
	{
		if (_App.View_DontAskEnableBittorrent () == FALSE)
		{
			CMyMessageBox dlg (_pwndDownloads);
			dlg.m_hIcon = LoadIcon (NULL, IDI_QUESTION);
			dlg.m_strBtn1Text = LS (L_YES);
			dlg.m_strBtn2Text = LS (L_NO);
			dlg.m_strCheckBoxText = LS (L_DONTASKAGAIN);
			dlg.m_strText = LS (L_ENABLEBTISREQ);
			dlg.m_strTitle = LS (L_CONFIRMATION);
			dlg.m_bChecked = FALSE;
			if (IDC_BTN1 != _DlgMgr.DoModal (&dlg))
			{
				if (dlg.m_bChecked)
					_App.View_DontAskEnableBittorrent (TRUE);
				return FALSE;
			}
			_App.Bittorrent_Enable (TRUE);
		}
		else 
		{
			return FALSE;
		}
	}
	
	if (IsBtInstalled () == FALSE)
	{
		ShowInstallBtMessage ();
		_App.Bittorrent_Enable (FALSE);
		return FALSE;
	}

	return TRUE;
}

LPCSTR vmsFdmAppMgr::getAppAgentNameUf()
{
	static std::string str;
	if (str.empty ())
	{
		str = "Free Download Manager ";
		char sz [100];
		str += itoa (getVersion ()->m_appVersion [0].dwVal, sz, 10);
		str += ".x"; 
	}
	return str.c_str ();
}

LPCSTR vmsFdmAppMgr::getAppBtAgentName()
{
	static std::string str;
	if (str.empty ())
	{
		str = "FDM/";
		char sz [100];
		str += itoa (getVersion ()->m_appVersion [0].dwVal, sz, 10);
		str += '.';
		str += itoa (getVersion ()->m_appVersion [1].dwVal, sz, 10);
		str += '(';
		str += itoa (getVersion ()->m_appVersion [2].dwVal, sz, 10);
		str += ')';
	}
	return str.c_str ();
}
