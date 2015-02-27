/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FUM.h"

#include "MainFrm.h"
#include <initguid.h>
#include "FUM_i.c"
#include "FUMUploader.h"
#include "FUMUploadPackage.h"
#include "urlwnd.h"
#include "DlgUpdate.h"
#include "mfchelp.h"
#include "fumapplication.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

BEGIN_MESSAGE_MAP(CFUMApp, CWinApp)
	//{{AFX_MSG_MAP(CFUMApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
		
		
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

CFUMApp::CFUMApp()
{
	
	
}

CFUMApp theApp;

BOOL CFUMApp::InitInstance()
{
	
	
	
	

#ifdef _AFXDLL
	Enable3dControls();			
#else
	Enable3dControlsStatic();	
#endif

	
	
	
	SetRegistryKey (_T("FreeDownloadManager.ORG"));

	CoInitialize (NULL);

	BOOL bNeedRegisterServer = FALSE;

	m_strAppPath = GetProfileString ("", "Path", "");

	if (m_strAppPath.IsEmpty () == FALSE)
	{
		if (m_strAppPath.Right (1) != "\\")
			m_strAppPath += "\\";
		if (GetFileAttributes (m_strAppPath + "fum.exe") == DWORD (-1))
		{
			bNeedRegisterServer = TRUE;
			m_strAppPath = "";
		}
	}

	if (m_strAppPath.IsEmpty ())
	{
		char sz [MAX_PATH];
		GetModuleFileName (NULL, sz, MAX_PATH);
		strrchr (sz, '\\') [1] = 0;
		WriteProfileString ("", "Path", sz);
		m_strAppPath = sz;
	}
	
	SetCurrentDirectory (m_strAppPath);

	if (strcmp (m_lpCmdLine, "-duis") == 0 && FALSE == IsRecentlyInstalledFumLaunched ())
		return FALSE;

	#ifndef _DEBUG
	if (MakeSureRecentlyInstalledFumLaunched () == FALSE)
		return FALSE;
	#endif

	InitLanguage ();

	if (strcmp (m_lpCmdLine, "-suis") == 0 ||
			strcmp (m_lpCmdLine, "-euis") == 0 ||
			strcmp (m_lpCmdLine, "-duis") == 0)
	{
		IntegrationSettings ();
		return FALSE;
	}

	if (lstrcmpi (m_lpCmdLine, "-shui") == 0)
	{
		HANDLE h = CreateEvent (NULL, TRUE, FALSE, "fum - oe - injapp");
		SetEvent (h);
		CloseHandle (h);
		return FALSE;
	}

	if (lstrcmpi (m_lpCmdLine, "-stui") == 0)
	{
		ShellExecute (0, "open", vmsGetAppFolder () + "fumoei.exe", 0, 0, SW_SHOW);
		return FALSE;
	}

	CString strUpdateFile = AfxGetApp ()->GetProfileString ("Update", "UpdateFile", "");
	if (strUpdateFile.IsEmpty () == FALSE)
	{
		AfxGetApp ()->WriteProfileString ("Update", "UpdateFile", "");
		m_hAppMutex = CreateMutex (NULL, TRUE, _pszAppMutex);
		if (FALSE == CDlgUpdate::StartUpdater (strUpdateFile))
		{
			DeleteFile (strUpdateFile);
			CloseHandle (m_hAppMutex);
		}
		else
		{
			return FALSE;
		}
	}

	
	char sz [MAX_PATH];
	fsGetSystemAppDataFolder (sz);
	CString str = sz; str += "Free Upload Manager\\uploads.sav";
	MoveFile (str, fsGetDataFilePath ("uploads.2.sav"));
	

	
	
	str = sz; str += "Free Upload Manager\\";
	if (str != fsGetAppDataFolder ())
	{
		CFileFind f; 
		BOOL b = f.FindFile (str + "uploads.?.sav");
		std::vector <CString> v;
		while (b)
		{
			b = f.FindNextFile ();
			v.push_back (f.GetFilePath ());
		}
		CString str2 = fsGetAppDataFolder ();
		for (size_t i = 0; i < v.size (); i++)
		{
			for (int j = 1, i = 0; j < 10 && i < (int)v.size (); j++)
			{
				CString str2; 
				str2.Format ("%suploads.%d.sav", fsGetAppDataFolder (), j);
				if (GetFileAttributes (str2) == DWORD (-1))
					MoveFile (v [i++], str2);
			}
		}
	}

	if (!InitATL())
		return FALSE;

	if (bNeedRegisterServer)
		RegisterServer ();

	AfxEnableControlContainer();

	

	
	

	CMainFrame* pFrame = new CMainFrame;
	m_pMainWnd = pFrame;

	

	pFrame->LoadFrame(IDR_MAINFRAME,
		WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, NULL,
		NULL);

	_App.View_ReadWndPlacement (pFrame, "MainFrm");

	
	if (_tcscmp (m_lpCmdLine, _T ("-autorun")) == 0)
		pFrame->ShowWindow (SW_HIDE);	
	else if (_App.Prg_StartMinimized ())
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

	return TRUE;
}

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	CFont m_fntUnderline;
	CUrlWnd	m_wndDLURL;
	CUrlWnd	m_wndFirm;
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

void CFUMApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

BOOL CFUMApp::InitLanguage()
{
	
	if (FALSE == _LngMgr.Initialize ())
		return FALSE;

	
	int iLang = _LngMgr.FindLngByName (_App.View_Language ());
	if (iLang == -1) 
		iLang = 0;

	

	if (FALSE == _LngMgr.LoadLng (iLang))
	{
		
		if (iLang == 0 || FALSE == _LngMgr.LoadLng (0))
			return FALSE;
	}

	return TRUE;
}

int CFUMApp::ExitInstance() 
{
	CoUninitialize ();
	
	if (m_bATLInited)
	{
		_Module.RevokeClassObjects();
		_Module.Term();
	
		CoUninitialize();
	}

	return CWinApp::ExitInstance();
}

	
CFUMModule _Module;

BEGIN_OBJECT_MAP(ObjectMap)
OBJECT_ENTRY(CLSID_FUMUploader, CFUMUploader)
OBJECT_ENTRY(CLSID_FUMUploadPackage, CFUMUploadPackage)
OBJECT_ENTRY(CLSID_FUMApplication, CFUMApplication)
END_OBJECT_MAP()

LONG CFUMModule::Unlock()
{
	AfxOleUnlockApp();
	return 0;
}

LONG CFUMModule::Lock()
{
	AfxOleLockApp();
	return 1;
}
LPCTSTR CFUMModule::FindOneOf(LPCTSTR p1, LPCTSTR p2)
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

BOOL CFUMApp::InitATL()
{
	m_bATLInited = TRUE;

#if _WIN32_WINNT >= 0x0400
	HRESULT hRes = CoInitializeEx(NULL, COINIT_MULTITHREADED);
#else
	HRESULT hRes = CoInitialize(NULL);
#endif

	if (FAILED(hRes))
	{
		m_bATLInited = FALSE;
		return FALSE;
	}

	_Module.Init(ObjectMap, AfxGetInstanceHandle());
	_Module.dwThreadID = GetCurrentThreadId();

	LPTSTR lpCmdLine = GetCommandLine(); 
	TCHAR szTokens[] = _T("-/");

	BOOL bRun = TRUE;
	LPCTSTR lpszToken = _Module.FindOneOf(lpCmdLine, szTokens);
	while (lpszToken != NULL)
	{
		if (lstrcmpi(lpszToken, _T("UnregServer"))==0)
		{
			if (IsRecentlyInstalledFumLaunched ())
			{
				_Module.UpdateRegistryFromResource(IDR_FUM, FALSE);
				_Module.UpdateRegistryFromResource(IDR_FUMAPPLICATION, FALSE);
				_Module.UpdateRegistryFromResource(IDR_FUMUPLOADER, FALSE);
				_Module.UpdateRegistryFromResource(IDR_FUMUPLOADPACKAGE, FALSE);
				_Module.UnregisterServer(TRUE); 
			}
			bRun = FALSE;
			break;
		}
		if (lstrcmpi(lpszToken, _T("RegServer"))==0)
		{
			RegisterServer ();
			bRun = FALSE;
			break;
		}
		lpszToken = _Module.FindOneOf(lpszToken, szTokens);
	}

	if (bRun && CheckFUMStartedAlready (TRUE))
		bRun = FALSE;

	if (!bRun)
	{
		m_bATLInited = FALSE;
		_Module.Term();
		CoUninitialize();
		return FALSE;
	}

	hRes = _Module.RegisterClassObjects(CLSCTX_LOCAL_SERVER, 
		REGCLS_MULTIPLEUSE);
	if (FAILED(hRes))
	{
		m_bATLInited = FALSE;
		CoUninitialize();
		return FALSE;
	}	

	return TRUE;

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
	if (stricmp (_LngMgr.GetLngName (_LngMgr.GetCurLng ()), "Russian") == 0)
		m_wndDLURL.SetUrl ("http://www.freedownloadmanager.org/download.htm");
	else
		m_wndDLURL.SetUrl ("http://www.freedownloadmanager.org/download.htm");
	
	CString strVer;
	char szVer [] = "%s %s build %d";
	strVer.Format (szVer, LS (L_VERSION), PRG_VERSION, PRG_BUILD_NUMBER);
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
	
	return TRUE;
}

HBRUSH CAboutDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	if (pWnd->m_hWnd == m_wndFirm.m_hWnd ||
		 pWnd->m_hWnd == m_wndDLURL.m_hWnd || 
		 pWnd->m_hWnd == m_wndSupport.m_hWnd)
	{
		pDC->SetTextColor (GetSysColor (COLOR_HOTLIGHT));
        pDC->SelectObject (&m_fntUnderline);
	}

	if (pWnd->m_hWnd == GetDlgItem (IDC__WARN)->m_hWnd)
		pDC->SelectObject (&m_fontWarn);

	return hbr;
}

BOOL CFUMApp::CheckFUMStartedAlready(BOOL bSetForIfEx)
{
	LPCSTR pszMainWnd = "Free Upload Manager Main Window";

	m_hAppMutex = CreateMutex (NULL, TRUE, _pszAppMutex);
	
	
	if (GetLastError () == ERROR_ALREADY_EXISTS)
	{
		CloseHandle (m_hAppMutex);
		m_hAppMutex = NULL;

		if (bSetForIfEx)
		{
			

			HWND hWnd = FindWindow (pszMainWnd, NULL);

			if (IsIconic (hWnd))
			{
				ShowWindow (hWnd, SW_RESTORE);
			}
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

AFX_MODULE_STATE* CFUMApp::GetModuleState()
{
	return m_pModuleState;
}

void CFUMApp::IntegrationSettings()
{
	vmsUploadsDllCaller udc;
	HMODULE hUploadsDll;

	#ifndef _DEBUG
	hUploadsDll = LoadLibrary (vmsGetAppFolder () + "fumcore.dll");
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

BOOL CFUMApp::MakeSureRecentlyInstalledFumLaunched()
{
	if (FALSE == IsRecentlyInstalledFumLaunched ())
	{
		ShellExecute (NULL, "open", m_strAppPath + "fum.exe", m_lpCmdLine, m_strAppPath, SW_SHOW);
		return FALSE;
	}

	return TRUE;
}

void CFUMApp::RegisterServer()
{
	_Module.UpdateRegistryFromResource(IDR_FUM, TRUE);
	_Module.UpdateRegistryFromResource(IDR_FUMAPPLICATION, TRUE);
	_Module.UpdateRegistryFromResource(IDR_FUMUPLOADER, TRUE);
	_Module.UpdateRegistryFromResource(IDR_FUMUPLOADPACKAGE, TRUE);
	_Module.RegisterServer(TRUE);
	
	ITypeLib *pLib = NULL;
	if (SUCCEEDED (LoadTypeLibEx (L"fuminterfaces.tlb", REGKIND_REGISTER, &pLib)))
		pLib->Release ();
	if (SUCCEEDED (LoadTypeLibEx (L"fum.tlb", REGKIND_REGISTER, &pLib)))
		pLib->Release ();
}

BOOL CFUMApp::IsRecentlyInstalledFumLaunched()
{
	char sz [MAX_PATH];
	GetModuleFileName (NULL, sz, MAX_PATH);
	strrchr (sz, '\\') [1] = 0;

	if (m_strAppPath.CompareNoCase (sz))
	{
		if (GetFileAttributes (m_strAppPath + "fum.exe") != DWORD (-1))
			return FALSE;
	}
	
	return TRUE;
}
