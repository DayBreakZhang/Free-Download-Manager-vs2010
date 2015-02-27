/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"

#include "FdmApp.h"
#include "dbghelp.h"

#include "MainFrm.h"
#include "UrlWnd.h"
#include <initguid.h>
#include "WGUrlReceiver.h"
#include "Fdm_i.c"
#include "UEDlg.h"
#include "fsIEUserAgent.h"
#include "WgUrlListReceiver.h"
#include "CFDM.h"
#include "fsFDMCmdLineParser.h"
#include "mfchelp.h"
#include "vmsFilesToDelete.h"
#include "vmsDLL.h"
#include "vmsFirefoxMonitoring.h"
#include "vmsChromeExtensionInstaller.h"
#include "FDMDownloadsStat.h"
#include "FDMDownload.h"
#include "FDMUploader.h"
#include "FDMUploadPackage.h"
#include "vmsTorrentExtension.h"
#include "vmsMagnetExtension.h"
#include "FdmTorrentFilesRcvr.h"
#include "FDMFlashVideoDownloads.h"
#include "vmsUploadsDllCaller.h"
#include "vistafx/vistafx.h"
#include "inetutil.h"
#include "vmsNotEverywhereSupportedFunctions.h"
#include "SpiderWnd.h"
extern CSpiderWnd *_pwndSpider;
#include "vmsFlvSniffInjector.h"
#include "FdmFlvDownload.h"
#include "vmsIeHelper.h"
#include "FdmUiWindow.h"
#include "CmdHistorySaver.h"
#include "vmsAppMutex.h"
#include "vmsElevatedFdm.h"
#include "vmsFdmCrashReporter.h"
#include "vmsAppGlobalObjects.h"
#include "vmsFirefoxExtensionInfo.h"
#include "vmsFirefoxUtil.h"
#include "vmsTmpFileName.h"
#include "vmsRegisteredAppPath.h"
#include "vmsFdmFilesDeleter.h"
#include "vmsFdmUiDetails.h"
#include "vmsWinSecurity.h"
#include "vmsFdmUtils.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

BEGIN_MESSAGE_MAP(CFdmApp, CWinApp)
	//{{AFX_MSG_MAP(CFdmApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

CFdmApp::CFdmApp()
{
	m_bCOMInited = m_bATLInited = m_bATLInited2 = FALSE;
	m_bEmbedding = FALSE;
	m_bStarting = TRUE;

	SYSTEMTIME time;
	GetLocalTime (&time);
	SystemTimeToFileTime (&time, &_timeAppHasStarted);

	m_pModuleState;
}

CFdmApp theApp;
vmsAppMutex _appMutex (_T ("Free Download Manager"));

vmsFdmCrashReporter _CrashReporter;

BOOL CFdmApp::InitInstance()
{
	

	AfxEnableControlContainer ();

	
	SetRegistryKey (IDS_COMPANY);

	bool bContinue = true;
	if (_CrashReporter.CheckIfSubmitDumpIsRequestedByCommandLine (bContinue))
	{
		if (!bContinue)
			return FALSE;
	}

	CheckRegistry ();

	fsIECatchMgr::CleanIEPluginKey ();

	
	CString strPath = GetProfileString ("", "Path", "");
	BOOL bNeedLocalRegister = FALSE;
	if (strPath == "")
	{
		CRegKey key;
		if (ERROR_SUCCESS == key.Open (HKEY_CURRENT_USER, "Software\\FreeDownloadManager.ORG\\Free Download Manager", KEY_WRITE))
			vmsSHCopyKey (HKEY_LOCAL_MACHINE, "Software\\FreeDownloadManager.ORG\\Free Download Manager", key);
		strPath = GetProfileString ("", "Path", "");
		bNeedLocalRegister = strPath != "";
	}

	if (GetFileAttributes (strPath + "\\fdm.exe") == DWORD (-1))
	{
		strPath = "";
		bNeedLocalRegister = false;
	}

	
	
	if (strPath == "" || FALSE == SetCurrentDirectory (strPath))
		_dwAppState |= APPSTATE_PORTABLE_MODE;

	char szExeDir [MY_MAX_PATH], szExeFile [MY_MAX_PATH];
	GetModuleFileName (NULL, szExeFile, sizeof (szExeFile));
	fsGetPath (szExeFile, szExeDir);

	if (IS_PORTABLE_MODE)
	{
		strPath = szExeDir;
		SetCurrentDirectory (strPath);
	}

	m_strAppPath = strPath;
	if (m_strAppPath.IsEmpty () == FALSE)
	{
		if (m_strAppPath [m_strAppPath.GetLength ()-1] != '\\' &&
				m_strAppPath [m_strAppPath.GetLength ()-1] != '/')
			m_strAppPath += '\\';
	}

	if (IS_PORTABLE_MODE == false)
	{
		CString strDataFldr = szExeDir; strDataFldr += "Data";
		
		
		
		if (m_strAppPath.CompareNoCase (szExeDir) &&
			 DWORD (-1) != GetFileAttributes (strDataFldr))
		{
			
			_dwAppState |= APPSTATE_PORTABLE_MODE;
			_dwAppState |= APPSTATE_PORTABLE_MODE_NOREG;
			m_strAppPath = szExeDir;
		}
	}

	if (IS_PORTABLE_MODE)
	{
		
		vmsAppSettingsStore* pStgs = _App.get_SettingsStore ();
		CString strStgsFile = m_strAppPath + "Data\\settings.dat";
		fsBuildPathToFile (strStgsFile);
		pStgs->LoadSettingsFromFile (strStgsFile);
		_App.ApplySettingsToMutexes ();
	}

	BOOL bNoLng = FALSE;

	if (FALSE == InitLanguage ())
		bNoLng = TRUE;

	if (strcmp (m_lpCmdLine, "-suis") == 0 || 
			strcmp (m_lpCmdLine, "-euis") == 0 ||
			strcmp (m_lpCmdLine, "-duis") == 0)
	{
		IntegrationSettings ();
		return FALSE;
	}

	if (IS_PORTABLE_MODE)
	{
		
		
		
		char szTmpFile [MY_MAX_PATH];
		CString str = m_strAppPath; str += "Data";
		CreateDirectory (str, NULL);
		if (0 == GetTempFileName (str, "fdm", 0, szTmpFile))
			MessageBox (NULL, LS (L_NOWRITEACCESSTODATAFOLDER), vmsFdmAppMgr::getAppName (), MB_ICONWARNING);
		else
			DeleteFile (szTmpFile);
	}

	_SkinMgr.Initialize ();

	_IECatchMgr.ReadSettings ();
	_NOMgr.Initialize ();
	_IECMM.ReadState ();

	
	HRESULT hRes = OleInitialize (NULL);
	
	if (FAILED(hRes))
		return FALSE;
	
	m_bCOMInited = TRUE;

	const tstring currentVersion = vmsFdmAppMgr::getVersion ()->m_fileVersion.ToString ();
	bool currentVersionFirstRun = currentVersion != _App.RecentVersionRun ();
	if (currentVersionFirstRun)
		_App.RecentVersionRun (currentVersion);

	vmsAppGlobalObjects::Create2 (currentVersionFirstRun);

	fsFDMCmdLineParser cmdline;

	cmdline.Parse (fsFDMCmdLineParser::Elevated);

	if (cmdline.isRunAsElevatedTasksProcessor ())
	{
		RunAsElevatedTasksProcessor (cmdline);
		return FALSE;
	}

	if (cmdline.isNeedExit ())
		return FALSE;

	m_bForceSilentSpecified = cmdline.is_ForceSilentSpecified ();

	if (cmdline.isNeedRegisterServer ())
	{
		onNeedRegisterServer ();
		return FALSE;
	}
	else if (cmdline.isNeedUnregisterServer ())
	{
		onNeedUnregisterServer ();
		return FALSE;
	}

	if (vmsWinSecurity::IsVistaOrHigher () && strncmp (m_lpCmdLine, "-nelvcheck", 10) && stricmp (m_lpCmdLine, "-autorun"))
	{
		if (vmsWinSecurity::IsProcessElevated ())
		{
			WCHAR wsz [MAX_PATH] = L"";
			GetModuleFileNameW (NULL, wsz, MAX_PATH);
			std::wstring wstr = L"\"";
			wstr += wsz;
			wstr += L"\" -nelvcheck ";
			wstr += CT2WEX<> (m_lpCmdLine);
			_appMutex.CloseMutex ();
			STARTUPINFOW si = {0}; PROCESS_INFORMATION pi = {0};
			si.cb = sizeof (si);
			if (vmsWinSecurity::RunAsDesktopUser (wsz, (LPWSTR)wstr.c_str (), NULL, si, pi))
				return FALSE;
			_appMutex.Create ();
		}
	}

	cmdline.Parse (fsFDMCmdLineParser::Normal);

	if (CheckFdmStartedAlready (m_bForceSilentSpecified == FALSE))
		return FALSE;

	if (!InitATL())
		return FALSE;

	_App.StartCount (_App.StartCount () + 1);

	
	
	if (IS_PORTABLE_MODE && (_dwAppState & APPSTATE_PORTABLE_MODE_NOREG) == 0)
		Install_RegisterServer ();

	
	
	
	
	vmsFilesToDelete::Process ();

	if (bNeedLocalRegister)
		RegisterServer (FALSE);

	

#ifdef _AFXDLL
	Enable3dControls();			
#else
	Enable3dControlsStatic();	
#endif

	CheckLocked ();

	_UpdateMgr.ReadSettings ();
	
	if (_UpdateMgr.IsStartUpdaterNeeded ())
	{
		if (_UpdateMgr.StartUpdater ())	
			return FALSE;	
		else
			::MessageBox (NULL, LS (L_CANTFINDUPDATER), LS (L_ERR), MB_ICONERROR);
	}

	vmsFlvSniffInjector::o ().Enable (_App.FlvMonitoring_Enable () != FALSE);

	LoadHistory ();

	_Snds.ReadSettings ();

	if (!vmsBtSupport::isBtDllValid ())
	{
		MessageBox (NULL, LS (L_INVALID_BT_MODULE), _T ("Free Download Manager"), MB_ICONERROR);
		return FALSE;
	}

	if (!_App.get_SettingsStore ()->GetProfileInt (_T ("State"), _T ("FfExtChecked"), FALSE))
	{
		DWORD dwResult;
		CheckFirefoxExtension (&dwResult);
		if (!(dwResult & (1 << 1)))
			_App.get_SettingsStore ()->WriteProfileInt (_T ("State"), _T ("FfExtChecked"), TRUE); 
	}

	CMainFrame* pFrame = NULL;
	fsnew1 (pFrame, CMainFrame);
	m_pMainWnd = pFrame;

	
	if (FALSE == pFrame->LoadFrame(IDR_MAINFRAME, WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, 
		NULL, NULL))
	{
		return FALSE;
	}

	
	BOOL bHidden = _tcscmp (m_lpCmdLine, _T ("-autorun")) == 0;

	_App.View_ReadWndPlacement (pFrame, "MainFrm", 
		bHidden ? fsAppSettings::RWPA_FORCE_SWHIDE_AND_KEEP_MINIMIZED_MAXIMIZED_STATE : fsAppSettings::RWPA_NONE);

	if (!bHidden)
	{
		if (_App.Prg_StartMinimized ())
		{
			if (IsWindowVisible (pFrame->m_hWnd))
				pFrame->ShowWindow (SW_MINIMIZE);
		}
		else
		{
			pFrame->UpdateWindow();
			if (pFrame->IsWindowVisible ())
				pFrame->SetForegroundWindow ();
		}
	}

	m_bStarting = FALSE;

	
	hRes = _Module.RegisterClassObjects (CLSCTX_LOCAL_SERVER, 
				REGCLS_MULTIPLEUSE);
	if (FAILED (hRes))
	{
		LPVOID lpMsgBuf;
		FormatMessage( 
				FORMAT_MESSAGE_ALLOCATE_BUFFER | 
				FORMAT_MESSAGE_FROM_SYSTEM | 
				FORMAT_MESSAGE_IGNORE_INSERTS,
				NULL,
				hRes,
				MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), 
				(LPTSTR) &lpMsgBuf,
				0,
				NULL 
				);
			
			
			
			MessageBox( NULL, (LPCTSTR)lpMsgBuf, "Error", MB_OK | MB_ICONINFORMATION );
			
			LocalFree( lpMsgBuf );
	}
	m_bATLInited2 = SUCCEEDED (hRes);

	return TRUE;
}

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	CUrlWnd	m_wndDLURL;
	CUrlWnd	m_wndFirm;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	CFont m_fntUnderline;
	CFont m_fontRegInfo;
	CFont m_fontWarn;
	CUrlWnd m_wndSupport;
	//{{AFX_MSG(CAboutDlg)
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
	m_fontRegInfo.CreateFont (10, 0, 0, 0, FW_BOLD, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, "MS Sans Serif");
	m_fontWarn.CreateFont (12, 0, 0, 0, FW_LIGHT, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, "Arial");
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CFdmApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
   	_DlgMgr.OnDoModal (&aboutDlg);
	aboutDlg.DoModal();
    _DlgMgr.OnEndDialog (&aboutDlg);
}

int CFdmApp::ExitInstance() 
{
	if (m_bATLInited2)
		_Module.RevokeClassObjects();

	if (IS_PORTABLE_MODE && (_dwAppState & APPSTATE_PORTABLE_MODE_NOREG) == 0)
		Install_UnregisterServer ();
	
	if (m_bATLInited)
		_Module.Term();

	

	
	
	return CWinApp::ExitInstance();
}

BOOL CAboutDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

    CFont* fnt = GetFont ();
	LOGFONT lf;
	fnt->GetLogFont (&lf);
	lf.lfUnderline = TRUE;
	m_fntUnderline.CreateFontIndirect (&lf);
	
	m_wndDLURL.SubclassDlgItem (IDC__DOWNLOAD, this);
	m_wndDLURL.Init ();
	m_wndDLURL.SetUrl ("http://www.freedownloadmanager.org/download.htm");
	
	CString strVer;
	char szVer [] = "%s %s build %s";
	strVer.Format (szVer, LS (L_VERSION), vmsFdmAppMgr::getVersion ()->m_tstrProductVersion.c_str (), 
		vmsFdmAppMgr::getBuildNumberAsString ());
	SetDlgItemText (IDC__VER, strVer);

	

	
	

	m_wndFirm.SubclassDlgItem (IDC__FIRM, this);
	m_wndFirm.Init ();
	m_wndFirm.SetUrl ("http://www.freedownloadmanager.org");

	SetDlgItemText (IDC__SUPPORT, LS (L_SUPPORTANDOTHER));
	m_wndSupport.SubclassDlgItem (IDC__SUPPORT, this);
	m_wndSupport.Init ();
	m_wndSupport.SetUrl ("http://www.freedownloadmanager.org/support.htm");

	SetDlgItemText (IDC__DOWNLOAD, LS (L_DLLATESTVERSION));

	SetDlgItemText (IDC__WARN, LS (L_LICWARN));

	SetWindowText (LS (L_ABOUT2));

	if (_AppMgr.IsBtInstalled () == FALSE || _AppMgr.IsMediaFeaturesInstalled () == FALSE)
	{
		CString str;
		GetDlgItemText (IDC__NAME, str);
		str += " (Light)";
		SetDlgItemText (IDC__NAME, str);
	}

	return TRUE;
}

HBRUSH CAboutDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	if (pWnd->m_hWnd == m_wndFirm.m_hWnd ||
		 pWnd->m_hWnd == m_wndDLURL.m_hWnd || 
		 pWnd->m_hWnd == m_wndSupport.m_hWnd)
	{
		pDC->SetTextColor (GetSysColor (26));
        pDC->SelectObject (&m_fntUnderline);
	}

	if (pWnd->m_hWnd == GetDlgItem (IDC__WARN)->m_hWnd)
		pDC->SelectObject (&m_fontWarn);
		
	return hbr;
}

void CFdmApp::LoadHistory()
{
	CCmdHistorySaver& chsSaver = CCmdHistorySaver::Instance();
	chsSaver.Load();

	
	

	
	
	
}

void CFdmApp::SaveHistory()
{
	CCmdHistorySaver& chsSaver = CCmdHistorySaver::Instance();
	chsSaver.Save();

	
	
	
	
	
}

	
CFdmModule _Module;

BEGIN_OBJECT_MAP(ObjectMap)
OBJECT_ENTRY(CLSID_WGUrlReceiver, CWGUrlReceiver)
OBJECT_ENTRY(CLSID_WGUrlListReceiver, CWgUrlListReceiver)
OBJECT_ENTRY(CLSID_FdmFlvDownload, CFdmFlvDownload)
OBJECT_ENTRY(CLSID_FDM, CFDM)
OBJECT_ENTRY(CLSID_FDMDownloadsStat, CFDMDownloadsStat)
OBJECT_ENTRY(CLSID_FDMDownload, CFDMDownload)
OBJECT_ENTRY(CLSID_FDMUploader, CFDMUploader)
OBJECT_ENTRY(CLSID_FDMUploadPackage, CFDMUploadPackage)
OBJECT_ENTRY(CLSID_FdmTorrentFilesRcvr, CFdmTorrentFilesRcvr)
OBJECT_ENTRY(CLSID_FDMFlashVideoDownloads, CFDMFlashVideoDownloads)
OBJECT_ENTRY(CLSID_FdmUiWindow, CFdmUiWindow)
END_OBJECT_MAP()

LONG CFdmModule::Unlock()
{
	AfxOleUnlockApp();
	return 0;
}

LONG CFdmModule::Lock()
{
	AfxOleLockApp();
	return 1;
}
LPCTSTR CFdmModule::FindOneOf(LPCTSTR p1, LPCTSTR p2)
{
	while (*p1 != NULL)
	{
		LPCTSTR p = p2;
		while (*p != NULL)
		{
			if (*p1 == *p)
				return CharNext(p1);
			p = CharNext(p);
		}
		p1++;
	}
	return NULL;
}

BOOL CFdmApp::InitATL()
{
	m_bEmbedding = FALSE;

	if (m_bATLInited == FALSE)
	{
		m_bATLInited = TRUE;
		_Module.Init (ObjectMap, AfxGetInstanceHandle());
		_Module.dwThreadID = GetCurrentThreadId ();
	}

	return TRUE;
}

BOOL CFdmApp::InitLanguage()
{
	m_nNoLngsErrReason = 0;
	
	
	if (FALSE == _LngMgr.Initialize ())
	{
		m_nNoLngsErrReason = 1;
		return FALSE;
	}

	
	int iLang = _LngMgr.FindLngByName (_App.View_Language ());
	if (iLang == -1) 
		iLang = 0;

	

	if (FALSE == _LngMgr.LoadLng (iLang))
	{
		
		if (iLang == 0 || FALSE == _LngMgr.LoadLng (0))
		{
			m_nNoLngsErrReason = 2;
			return FALSE;
		}
	}

	return TRUE;
}

BOOL CFdmApp::CheckFdmStartedAlready(BOOL bSetForIfEx)
{
	LPCSTR pszMainWnd = "Free Download Manager Main Window";
	
	
	if (_appMutex.isAnotherInstanceStartedAlready ())
	{
		_appMutex.CloseMutex ();

		if (bSetForIfEx)
		{
			

			HWND hWnd = FindWindow (pszMainWnd, NULL);

			if (IsIconic (hWnd))
				ShowWindow (hWnd, SW_RESTORE);
			else
			{
				WINDOWPLACEMENT wc;
				GetWindowPlacement (hWnd, &wc);
				if (wc.showCmd == SW_HIDE)
					ShowWindow (hWnd, SW_RESTORE);
			}

			SetForegroundWindow (hWnd);
			SetFocus (hWnd);
		}
		
		return TRUE;
	}

	return FALSE;
}

CFdmApp::~CFdmApp()
{
	if (m_bCOMInited)
		CoUninitialize();
}

LONG CFdmApp::_UEF(_EXCEPTION_POINTERS *info)
{
	static BOOL _b = FALSE;

	if (_b)
		return EXCEPTION_EXECUTE_HANDLER;

	_b = TRUE;

	typedef BOOL (WINAPI *FNMDWD)(HANDLE, DWORD, HANDLE, MINIDUMP_TYPE, 
		PMINIDUMP_EXCEPTION_INFORMATION, PMINIDUMP_USER_STREAM_INFORMATION, PMINIDUMP_CALLBACK_INFORMATION);
	vmsDLL dll ("dbghelp.dll");
	FNMDWD pfnMiniDumpWriteDump;
	pfnMiniDumpWriteDump = (FNMDWD) dll.GetProcAddress ("MiniDumpWriteDump");
	if (pfnMiniDumpWriteDump == NULL)
		return EXCEPTION_EXECUTE_HANDLER;
	
	
	
	MINIDUMP_EXCEPTION_INFORMATION eInfo;
    eInfo.ThreadId = GetCurrentThreadId();
    eInfo.ExceptionPointers = info;
    eInfo.ClientPointers = FALSE;

	char szFile [MAX_PATH]; char szName [100];
	wsprintf (szName, "fdm%s.dmp", vmsFdmAppMgr::getBuildNumberAsString ());
	GetTempPath (MAX_PATH, szFile);
	lstrcat (szFile, szName);
	HANDLE hFile = CreateFile (szFile, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS,
		0, NULL);

    
    pfnMiniDumpWriteDump(
        GetCurrentProcess(),
        GetCurrentProcessId(),
        hFile,
        MiniDumpNormal,
        &eInfo,
        NULL,
        NULL);

	CloseHandle (hFile);

	CUEDlg dlg;
	dlg.DoModal ();

	
	TerminateProcess (GetCurrentProcess (), 0);
	return 0; 
}

#include "FDM.h"
#include "FDMDownloadsStat.h"
#include "FDMDownload.h"
#include "FDMUploader.h"
#include "FDMUploadPackage.h"
#include "FdmFlvDownload.h"

BOOL CFdmApp::Is_Starting()
{
	return m_bStarting;
}

void CFdmApp::CheckLocked()
{
	DWORD dwRes;

	do 
	{
		HANDLE hMx = CreateMutex (NULL, TRUE, "_mx_FDM_Lock_Start_");
		dwRes = GetLastError ();
		CloseHandle (hMx);

		if (dwRes == ERROR_ALREADY_EXISTS)
			Sleep (100);
	}
	while (dwRes == ERROR_ALREADY_EXISTS);
}

void CFdmApp::UninstallCustomizations()
{
	CRegKey key;
	key.Open (HKEY_CURRENT_USER, "Software\\FreeDownloadManager.ORG\\Free Download Manager");

	char sz [MY_MAX_PATH];
	DWORD dw = MY_MAX_PATH;
	
	
	key.QueryValue (sz, "CLSM_File", &dw);
	DeleteFile (sz);

	
	dw = MY_MAX_PATH;
	key.QueryValue (sz, "CLFM_File", &dw);
	DeleteFile (sz);

	

	

	

	char szIEOP [10000] = "about:blank";
	char szIECP [10000] = "about:blank";

	CRegKey fdmkey;
	fdmkey.Open (HKEY_CURRENT_USER, "Software\\FreeDownloadManager.ORG\\Free Download Manager");

	dw = sizeof (szIECP);
	fdmkey.QueryValue (szIECP, "CustSite", &dw);
	dw = sizeof (szIEOP);
	if (ERROR_SUCCESS == fdmkey.QueryValue (szIEOP, "CIEOP", &dw))
	{
		key.Open (HKEY_CURRENT_USER, "Software\\Microsoft\\Internet Explorer\\Main");

		char sz2 [10000] = "about:blank";
		dw = sizeof (sz2);
		key.QueryValue (sz2, "Start Page", &dw);

		if (lstrcmp (sz2, szIECP) == 0)
			key.SetValue (szIEOP, "Start Page");
	}
}

BOOL CFdmApp::RegisterServer(BOOL bGlobal)
{
	LOG ("Registering server (%s)...", bGlobal ? "global" : "local");

	bool bRegisterForUserOnly = IS_PORTABLE_MODE && !Is9xME;

	if (bRegisterForUserOnly)
	{
		LOGsnl ("Portable mode: overriding HKCR...");
		HKEY hKey;
		LONG lRes;
		lRes = RegOpenKeyEx (HKEY_CURRENT_USER, "Software\\Classes", 0, KEY_ALL_ACCESS, &hKey);
		LOGRESULT (" open cu key", lRes);
		lRes = vmsNotEverywhereSupportedFunctions::RegOverridePredefKey (HKEY_CLASSES_ROOT, hKey);
		LOGRESULT (" override HKCR key", lRes);
		RegCloseKey (hKey);
	}

	if (bGlobal)
	{
		fsIEUserAgent ua;
		ua.RemovePP (IE_USERAGENT_ADDITION);
	}

	

	if (bGlobal)
	{
		vmsIeHelper::RegisterExeAsSafeToRun (_T ("{1C306DF7-2171-45c8-9324-D36448104BD5}"));
		vmsIeHelper::RegisterExeAsSafeToDragDrop (_T ("{1C306DF7-2171-45c8-9324-D36448104BD5}"));

		CRegKey key;
		
		
		
		if (ERROR_SUCCESS == key.Open (HKEY_LOCAL_MACHINE, "Software\\FreeDownloadManager.ORG\\Free Download Manager", KEY_WRITE))
			vmsSHCopyKey (HKEY_CURRENT_USER, "Software\\FreeDownloadManager.ORG\\Free Download Manager", key);

		
		HRESULT hr = _Module.UpdateRegistryFromResource (IDR_FDM, TRUE);
		LOGRESULT ("UpdateRegistryFromResource", hr);
	
		hr = _Module.RegisterServer (!bRegisterForUserOnly);
		LOGRESULT ("_Module.RegisterServer", hr);

		if (bRegisterForUserOnly)
		{
			CComBSTR bstrPath;
			CComPtr<ITypeLib> pTypeLib;
			hr = AtlModuleLoadTypeLib (&_Module, NULL, &bstrPath, &pTypeLib);
			if (SUCCEEDED(hr))
			{
				OLECHAR szDir[_MAX_PATH];
				ocscpy(szDir, bstrPath);
				szDir[AtlGetDirLen(szDir)] = 0;
			
				typedef HRESULT (WINAPI *FNRTLFU)(ITypeLib*,OLECHAR*,OLECHAR*);
				FNRTLFU pfn = (FNRTLFU) GetProcAddress (GetModuleHandle ("oleaut32.dll"), "RegisterTypeLibForUser");
				if (pfn)
					hr = pfn (pTypeLib, bstrPath, szDir);
				else
					hr = ::RegisterTypeLib(pTypeLib, bstrPath, szDir);
			}
			LOGRESULT ("register typelib", hr);
		}
		
		
		ITypeLib *pLib = NULL;
		
		if (SUCCEEDED (hr = LoadTypeLibEx (L"fdm.tlb", REGKIND_REGISTER, &pLib)))
			pLib->Release ();
		else
			MessageBox (0, "Failed to load Free Download Manager type lib","Error",0);
		LOGRESULT ("register fdm.tlb", hr);

		if (_AppMgr.IsBtInstalled ())
		{
			
			if (vmsTorrentExtension::IsAssociatedWithUs () == FALSE)
			{
				if (_App.Bittorrent_Enable () || vmsTorrentExtension::IsAssociationExist () == FALSE)
				{
					_App.Bittorrent_OldTorrentAssociation (vmsTorrentExtension::GetCurrentAssociation ());
					vmsTorrentExtension::Associate ();
				}
			}

			if (vmsMagnetExtension::IsAssociatedWithUs () == FALSE)
			{
				if (_App.Bittorrent_Enable () || vmsMagnetExtension::IsAssociationExist () == FALSE)
					vmsFdmUtils::AssociateFdmWithMagnetLinks (true);
			}
		}
	}

	WriteProfileInt ("", "cverID", 0);

	if (GetProfileInt ("Settings\\Monitor", "IECMInited", 0) == 0)
		WriteProfileInt ("Settings\\Monitor", "IECMInited", TRUE);
	_IECMM.DeleteIEMenus (); 
	fsIEContextMenuMgr::DeleteAllFDMsIEMenus ();
	_IECMM.AddIEMenus ();

	
	const DWORD dwMUSO = _App.Monitor_UserSwitchedOn ();
				
	BOOL bIeOK = _IECatchMgr.InstallIeIntegration ((dwMUSO & MONITOR_USERSWITCHEDON_IE) != 0, bRegisterForUserOnly, FALSE);

	vmsFirefoxMonitoring::Install (true);
	if (vmsFirefoxMonitoring::IsInstalled () == false)
		_App.Monitor_Firefox (FALSE);
	else
		_App.Monitor_Firefox ((dwMUSO & MONITOR_USERSWITCHEDON_FIREFOX) != 0);
	
	

	if (!vmsChromeExtensionInstaller::IsInstalled())
		vmsChromeExtensionInstaller::Install ();
	if (!vmsChromeExtensionInstaller::IsInstalled())
		_App.Monitor_Chrome (FALSE);
	else
		_App.Monitor_Chrome (TRUE);
	
	_NOMgr.getPluginInstaller(vmsKnownBrowsers::Chrome).DeinstallPlugin ();

	size_t cBrowsers = 0;
	const vmsFdmUiDetails::KnownBrowserData *pBrowsers = vmsFdmUiDetails::getKnownBrowsersData (cBrowsers);

	for (size_t nBrowser = 0; nBrowser < cBrowsers; nBrowser++)
	{
		const vmsFdmUiDetails::KnownBrowserData& bd = pBrowsers [nBrowser];
		vmsNpPluginInstaller& pluginInstaller = _NOMgr.getPluginInstaller (bd.enBrowser);

		if (bd.enBrowser == vmsKnownBrowsers::Chrome) 
		{
			if ((dwMUSO & bd.dwUserSwitchedOnFlag) || _App.Monitor_ForceEnableChromeOnce ())
			{
				
				pluginInstaller.DeinstallPlugin ();
				pluginInstaller.Initialize (); 
				pluginInstaller.InstallPlugin ();
				_App.Monitor_ForceEnableChromeOnce (FALSE);
			}
			continue;
		}

		if (dwMUSO & bd.dwUserSwitchedOnFlag)
			pluginInstaller.InstallPlugin ();
	}

	CRegKey key;
	if (ERROR_SUCCESS != key.Create (HKEY_CURRENT_USER, "Software\\FreeDownloadManager.ORG\\Free Upload Manager"))
		key.Open (HKEY_CURRENT_USER, "Software\\FreeDownloadManager.ORG\\Free Upload Manager");
	key.SetValue (fsGetAppDataFolder (), "force_data_folder");

	if (bRegisterForUserOnly)
		vmsNotEverywhereSupportedFunctions::RegOverridePredefKey (HKEY_CLASSES_ROOT, NULL);

	if (!bIeOK && (dwMUSO & MONITOR_USERSWITCHEDON_IE) != 0 && _App.Monitor_IE2 () && IS_PORTABLE_MODE)
		vmsElevatedFdm::o ().InstallIeIntegration (true);

	return TRUE;
}

void CFdmApp::Install_RegisterServer()
{
	if (m_bATLInited == FALSE)
	{
		m_bATLInited = TRUE;
		_Module.Init(ObjectMap, AfxGetInstanceHandle());
		_Module.dwThreadID = GetCurrentThreadId();
	}
	RegisterServer (TRUE);
}

void CFdmApp::Install_UnregisterServer()
{
	LOGsnl ("Unregister server...");

	bool bUnregisterForUserOnly = IS_PORTABLE_MODE;
	
	if (bUnregisterForUserOnly)
	{
		HKEY hKeyCurrentUser;
		LONG l = RegOpenKeyEx (HKEY_CURRENT_USER, _T("Software\\Classes"), 0, KEY_ALL_ACCESS, &hKeyCurrentUser);
		LOGRESULT ("open cu", l);
		l = vmsNotEverywhereSupportedFunctions::RegOverridePredefKey (HKEY_CLASSES_ROOT, hKeyCurrentUser);
		LOGRESULT ("override key", l);
		RegCloseKey (hKeyCurrentUser);
	}

	if (m_bATLInited == FALSE)
	{
		m_bATLInited = TRUE;
		_Module.Init(ObjectMap, AfxGetInstanceHandle());
		_Module.dwThreadID = GetCurrentThreadId();
	}
			
	
	HRESULT hr = _Module.UpdateRegistryFromResource(IDR_FDM, FALSE);
	LOGRESULT ("_Module.UpdateRegistryFromResource", hr);
	hr = _Module.UnregisterServer(!bUnregisterForUserOnly); 
	LOGRESULT ("_Module.UnregisterServer", hr);
	UnRegisterTypeLib (LIBID_FdmLib, 0, 0, LOCALE_SYSTEM_DEFAULT, SYS_WIN32);

	if (bUnregisterForUserOnly)
	{
		typedef HRESULT (WINAPI *PFNRTL)(REFGUID, WORD, WORD, LCID, SYSKIND);
		CComBSTR bstrPath;
		CComPtr<ITypeLib> pTypeLib;
		hr = AtlModuleLoadTypeLib(&_Module, NULL, &bstrPath, &pTypeLib);
		if (SUCCEEDED(hr))
		{
			TLIBATTR* ptla;
			HRESULT hr = pTypeLib->GetLibAttr(&ptla);
			if (SUCCEEDED(hr))
			{
				HINSTANCE h = LoadLibrary(_T("oleaut32.dll"));
				if (h != NULL)
				{
					PFNRTL pfn = (PFNRTL) GetProcAddress(h, "UnRegisterTypeLibForUser");
					if (pfn == NULL)
						pfn = (PFNRTL) GetProcAddress(h, "UnRegisterTypeLib");
					if (pfn != NULL)
						hr = pfn(ptla->guid, ptla->wMajorVerNum, ptla->wMinorVerNum, ptla->lcid, ptla->syskind);
					FreeLibrary (h);
				}
				pTypeLib->ReleaseTLibAttr(ptla);
			}
		}
		LOGRESULT ("unregister typelib", hr);
	}
	
	
	
	if (_IECMM.IsIEMenusPresent ())
		WriteProfileInt ("Settings\\Monitor", "IECMInited", 0);

	fsIEContextMenuMgr::DeleteAllFDMsIEMenus ();
	
	std::vector <std::auto_ptr <vmsBrowserPluginFileDeleter> > vBrowserPluginFiles;
	_NOMgr.DeinstallAllPlugins (vBrowserPluginFiles);
	if (!vBrowserPluginFiles.empty ())
		vmsFdmFilesDeleter::DeleteBrowserPluginFiles (vBrowserPluginFiles);
	_IECatchMgr.InstallIeIntegration (FALSE, bUnregisterForUserOnly, FALSE);
	fsIEUserAgent ua;
	ua.RemovePP (IE_USERAGENT_ADDITION);
	UninstallCustomizations ();
	vmsFirefoxMonitoring::Install (false);
	vmsChromeExtensionInstaller::Uninstall();

	
	if (vmsTorrentExtension::IsAssociatedWithUs ())
		vmsTorrentExtension::AssociateWith (_App.Bittorrent_OldTorrentAssociation ());
	vmsFdmUtils::AssociateFdmWithMagnetLinks (false);

	if (bUnregisterForUserOnly)
		vmsNotEverywhereSupportedFunctions::RegOverridePredefKey (HKEY_CLASSES_ROOT, NULL);
}

void CFdmApp::SaveSettings()
{
	if (IS_PORTABLE_MODE)
	{
		
		vmsAppSettingsStore* pStgs = _App.get_SettingsStore ();
		CString strStgsFile = fsGetDataFilePath ("settings.dat");
		pStgs->SaveSettingsToFile (strStgsFile);
	}
}

void CFdmApp::IntegrationSettings()
{
	vmsUploadsDllCaller udc;
	HMODULE hUploadsDll;

	#ifndef _DEBUG
	CString strFP = fsGetFumProgramFilesFolder ();
	hUploadsDll = LoadLibrary (strFP + "fumcore.dll");
	#else
	hUploadsDll = LoadLibrary ("E:\\VCW\\FDM\\FDM\\Uploader\\CoreDll\\Debug\\fumcore.dll");
	ASSERT (hUploadsDll != NULL);
	#endif

	if (hUploadsDll == NULL)
		return;

	vmsUploadsDll::FNSDC pfnSetCaller = (vmsUploadsDll::FNSDC) GetProcAddress (hUploadsDll, 
		"_SetDllCaller");
	ASSERT (pfnSetCaller != NULL);
	pfnSetCaller (&udc);

	if (lstrcmpi (m_lpCmdLine, "-suis") == 0)
	{
		vmsUploadsDll::FNSIS pfnShowIntegrationSettings = (vmsUploadsDll::FNSIS) GetProcAddress (hUploadsDll, 
			"_ShowIntegrationSettings");
		ASSERT (pfnShowIntegrationSettings != NULL);
		pfnShowIntegrationSettings (NULL);
	}
	else
	{
		vmsUploadsDll::FNEI pfnEnableIntegration = (vmsUploadsDll::FNEI) GetProcAddress (hUploadsDll, 
			"_EnableIntegration");			 
		ASSERT (pfnEnableIntegration != NULL);
		pfnEnableIntegration  (lstrcmpi (m_lpCmdLine, "-euis") == 0, 0);
	}

	FreeLibrary (hUploadsDll);
}

DWORD WINAPI CFdmApp::_threadExitProcess(LPVOID lp)
{
	Sleep (((DWORD)lp) * 1000);
	ASSERT (LPCSTR ("_threadExitProcess is called") == NULL);
	HANDLE hProcess = OpenProcess (PROCESS_TERMINATE, FALSE, GetCurrentProcessId ());
	TerminateProcess (hProcess, (DWORD)-1);
	return 0;
}

void CFdmApp::ScheduleExitProcess(DWORD dwSeconds)
{
	DWORD dw;
	CloseHandle (
		::CreateThread (NULL, 0, _threadExitProcess, (LPVOID)dwSeconds, 0, &dw));
}

void CFdmApp::CheckRegistry()
{
	fsString str = "%56%69%63%4D%61%6E%20%53%6F%66%74%77%61%72%65";
	fsDecodeHtmlUrl (str);
	CString strOldKey = "Software\\"; strOldKey += str; 
	CString strOldRKey = strOldKey;
	strOldKey += "\\Free Download Manager";

	
	CRegKey key;
	if (ERROR_SUCCESS == key.Open (HKEY_CURRENT_USER, strOldKey))
	{
		CRegKey key2;
		if (ERROR_SUCCESS != key2.Open (HKEY_CURRENT_USER, "Software\\FreeDownloadManager.ORG\\Free Download Manager\\Settings\\History"))
		{
			LONG lRes = key2.Create (HKEY_CURRENT_USER, "Software\\FreeDownloadManager.ORG");
			if (lRes != ERROR_SUCCESS)
				lRes = key2.Open (HKEY_CURRENT_USER, "Software\\FreeDownloadManager.ORG");

			if (ERROR_SUCCESS == lRes)
			{
				key.Open (HKEY_CURRENT_USER, strOldRKey);

				CString strPath = GetProfileString ("", "Path", "");
				LONG nRes = fsCopyKey (key, key2, "Free Download Manager", "Free Download Manager");
				nRes; 
				WriteProfileString ("", "Path", strPath); 
				
				key.RecurseDeleteKey ("Free Download Manager");
			}
		}
	}
}

AFX_MODULE_STATE* CFdmApp::GetModuleState()
{
	return m_pModuleState;
}

bool CFdmApp::onNeedRegisterServer(void)
{
	Install_RegisterServer ();
	return false;
}

bool CFdmApp::onNeedUnregisterServer(void)
{
	BOOL bWaitShutdown = FALSE;
	if (CheckFdmStartedAlready (FALSE))
	{
		UINT nMsg = RegisterWindowMessage ("FDM - shutdown");
		if (nMsg)
		{
			PostMessage (HWND_BROADCAST, nMsg, 0, 0);
			bWaitShutdown = TRUE;
		}
		else
		{
			MessageBox (NULL, "Unable to shutdown Free Download Manager.\nPlease do that yourself.", "Error", MB_ICONEXCLAMATION);
		}
	}

	HANDLE hMxWi = CreateMutex (NULL, FALSE, "FDM - remote control server");
	if (GetLastError () == ERROR_ALREADY_EXISTS)
	{
		UINT nMsg = RegisterWindowMessage ("FDM - remote control server - shutdown");
		if (nMsg)
			PostMessage (HWND_BROADCAST, nMsg, 0, 0);
	}
	if (hMxWi)
		CloseHandle (hMxWi);

	if (bWaitShutdown)
	{
		while (CheckFdmStartedAlready (FALSE))
		{
			Sleep (400);
		}
	}

	Install_UnregisterServer ();

	return false;
}

void CFdmApp::RunAsElevatedTasksProcessor(fsFDMCmdLineParser& cmdline)
{
	_appMutex.CloseMutex ();

	if (!IsUserAnAdmin ())
		return;

	const std::vector <vmsKnownBrowsers::Browser>& vBrowsersToInstall = cmdline.getBrowsersToInstallIntegration (true);
	const std::vector <vmsKnownBrowsers::Browser>& vBrowsersToDeinstall = cmdline.getBrowsersToInstallIntegration (false);

	if (!vBrowsersToInstall.empty ())
		_NOMgr.InstallPluginsEx (vBrowsersToInstall);

	if (!vBrowsersToDeinstall.empty ())
		_NOMgr.DeinstallPluginsEx (vBrowsersToDeinstall);

	if (cmdline.isNeedInstallIeIntegration ())
	{
		_IECatchMgr.InstallIeIntegration (TRUE, TRUE);

		for (;;)
		{
			vmsAppMutex appmx (_appMutex.getName ());
			appmx.CloseMutex ();
			if (!appmx.isAnotherInstanceStartedAlready ())
				break;
			Sleep (1000);
		}

		_IECatchMgr.InstallIeIntegration (FALSE, TRUE);
	}
}

void CFdmApp::CheckFirefoxExtension(LPDWORD pdwResult)
{
	if (pdwResult)
		*pdwResult = 0;

	bool bEnabled;
	if (!vmsFirefoxMonitoring::IsEnabledInFirefox (bEnabled) || bEnabled)
		return;

	if (pdwResult)
		*pdwResult |= 1;

	if (IDYES != MessageBox (NULL, _T ("Free Download Manager extension for Firefox is disabled. You need to enable it in order to use the integration with Firefox. Would you like to enable it?"), 
			_T ("Free Download Manager"), MB_YESNO))
		return;

	if (pdwResult)
		*pdwResult |= (1 << 1);

	MessageBox (NULL, _T ("Firefox addons page will be opened. You need to enable the extension there."), _T ("Free Download Manager"), MB_OK);

	ShellExecute (NULL, _T ("open"), _T ("firefox.exe"), _T ("about:addons"), NULL, SW_SHOWNORMAL);
}
