/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "coredll.h"
#include "UploaderProps_Integration.h"
#include <comdef.h>
#include "../UploadContextMenu/UploadShellExt/UploadShellExt.h"
#include <atlbase.h>
#include "../FDMUploadBtnForIe/FDMUploadBtnForIe.h"

_COM_SMARTPTR_TYPEDEF(IFdmUplShellExts, __uuidof(IFdmUplShellExts));
_COM_SMARTPTR_TYPEDEF(IFDMUploadBtnForIe, __uuidof(IFDMUploadBtnForIe));

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNCREATE(CUploaderProps_Integration, CPropertyPage)

CUploaderProps_Integration::CUploaderProps_Integration() : CPropertyPage(CUploaderProps_Integration::IDD)
{
	m_psp.dwFlags |= PSP_USETITLE;
	m_psp.pszTitle = LS (L_INTEGRATION);
}

CUploaderProps_Integration::~CUploaderProps_Integration()
{
}

void CUploaderProps_Integration::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CUploaderProps_Integration)
		
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CUploaderProps_Integration, CPropertyPage)
	//{{AFX_MSG_MAP(CUploaderProps_Integration)
	ON_BN_CLICKED(IDC_CM, OnCm)
	ON_BN_CLICKED(IDC_STM, OnStm)
	ON_BN_CLICKED(IDC_OE, OnOe)
	ON_EN_CHANGE(IDC_OE_MINSIZE, OnChangeOeMinsize)
	ON_BN_CLICKED(IDC_OE_ASKUPLOAD, OnOeAskupload)
	ON_BN_CLICKED(IDC_IE, OnIe)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CUploaderProps_Integration::OnCm() 
{
	SetModified ();	
}

void CUploaderProps_Integration::OnStm() 
{
	SetModified ();	
}

void CUploaderProps_Integration::OnOe() 
{
	SetModified ();
	UpdateEnabled ();
}

void CUploaderProps_Integration::OnChangeOeMinsize() 
{
	SetModified ();
}

void CUploaderProps_Integration::UpdateEnabled()
{
	BOOL b = IsDlgButtonChecked (IDC_OE) == BST_CHECKED;
	GetDlgItem (IDC_OE_ASKUPLOAD)->EnableWindow (b);
	b = b && IsDlgButtonChecked (IDC_OE_ASKUPLOAD) == BST_CHECKED;
	GetDlgItem (IDC_OE__MINSIZE)->EnableWindow (b);
	GetDlgItem (IDC_OE_MINSIZE)->EnableWindow (b);
	GetDlgItem (IDC__KB)->EnableWindow (b);
}

BOOL CUploaderProps_Integration::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();

	IFdmUplShellExtsPtr spExts;
	spExts.CreateInstance (__uuidof (FdmUplShellExts));

	if (spExts != NULL)
	{
		BOOL b;

		spExts->get_ShowInExplorerContextMenu (&b);
		if (b)
			CheckDlgButton (IDC_CM, BST_CHECKED);

		spExts->get_ShowInSendToContextMenu (&b);
		if (b)
			CheckDlgButton (IDC_STM, BST_CHECKED);
	}

	IFDMUploadBtnForIePtr spBtn;
	spBtn.CreateInstance (__uuidof (FDMUploadBtnForIe));
	CheckDlgButton (IDC_IE, spBtn != NULL ? BST_CHECKED : BST_UNCHECKED);

	HANDLE h = CreateEvent (NULL, TRUE, FALSE, "fum - oe - injapp");
	m_bOeIntegrRunning = GetLastError () == ERROR_ALREADY_EXISTS;
	CloseHandle (h);
	if (m_bOeIntegrRunning)
		CheckDlgButton (IDC_OE, BST_CHECKED);

	CRegKey key;
	if (ERROR_SUCCESS == key.Open (HKEY_CURRENT_USER, 
			"Software\\FreeDownloadManager.ORG\\Free Upload Manager\\Settings\\Integration\\Oe", KEY_ALL_ACCESS))
	{
		DWORD dw = 1024;
		key.QueryValue (dw, "MinSizeOfFileToUpload");
		if (dw != UINT_MAX)
		{
			CheckDlgButton (IDC_OE_ASKUPLOAD, BST_CHECKED);
			SetDlgItemInt (IDC_OE_MINSIZE, dw);
		}
		else
		{
			SetDlgItemInt (IDC_OE_MINSIZE, 1024);
		}
	}
	else
	{
		CheckDlgButton (IDC_OE_ASKUPLOAD, BST_CHECKED);
		SetDlgItemInt (IDC_OE_MINSIZE, 1024);
	}
	
	UpdateEnabled ();
	ApplyLanguage ();
	
	return TRUE;  
	              
}

BOOL CUploaderProps_Integration::OnApply() 
{
	char sz [MAX_PATH];

	IFdmUplShellExtsPtr spExts;
	spExts.CreateInstance (__uuidof (FdmUplShellExts));

	if (spExts == NULL)
	{
		_pDllCaller->GetCommonFilesFolder (sz);
		lstrcat (sz, "fumshext.dll");
		HMODULE hDll = LoadLibrary (sz);
		if (hDll != NULL)
		{
			typedef HRESULT (_stdcall *FNDRUS)(void);
			FNDRUS pfn;
			pfn = (FNDRUS)GetProcAddress (hDll, "DllRegisterServer");
			if (pfn)
				pfn ();
			FreeLibrary (hDll);
		}
		spExts.CreateInstance (__uuidof (FdmUplShellExts));
	}

	if (spExts != NULL)
	{
		spExts->put_ShowInExplorerContextMenu (IsDlgButtonChecked (IDC_CM) == BST_CHECKED);
		spExts->put_ShowInSendToContextMenu (IsDlgButtonChecked (IDC_STM) == BST_CHECKED);
	}

	
	_pDllCaller->GetCommonFilesFolder (sz);
	lstrcat (sz, "fumiebtn.dll");
	HMODULE hDll = LoadLibrary (sz);
	if (hDll != NULL)
	{
		typedef HRESULT (_stdcall *FNDRUS)(void);
		FNDRUS pfn;
		pfn = (FNDRUS)GetProcAddress (hDll, IsDlgButtonChecked (IDC_IE) == BST_CHECKED ? 
			"DllRegisterServer" : "DllUnregisterServer");
		if (pfn)
			pfn ();
		FreeLibrary (hDll);
		CoFreeUnusedLibraries ();
	}
	

	BOOL bNewOe = IsDlgButtonChecked (IDC_OE) == BST_CHECKED;

	if (bNewOe)
	{
		CRegKey key;

		if (ERROR_SUCCESS != key.Open (HKEY_CURRENT_USER, 
				"Software\\FreeDownloadManager.ORG\\Free Upload Manager\\Settings\\Integration\\Oe"))
		{
			key.Create (HKEY_CURRENT_USER, 
				"Software\\FreeDownloadManager.ORG\\Free Upload Manager\\Settings\\Integration\\Oe");
		}

		if (key.m_hKey)
		{
			DWORD dw = IsDlgButtonChecked (IDC_OE_ASKUPLOAD) == BST_CHECKED ? 
				GetDlgItemInt (IDC_OE_MINSIZE) : UINT_MAX;
			key.SetValue (dw, "MinSizeOfFileToUpload");
		}
	}

	if (!bNewOe != !m_bOeIntegrRunning)
	{
		CRegKey key;
		key.Open (HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Run");

		if (bNewOe)
		{
			#ifdef _DEBUG
			lstrcpy (sz, "E:\\VCW\\FDM\\FDM\\Uploader\\UploadContextMenu\\UploadOeMenu\\InjApp\\Debug\\fumoei.exe");
			#else
			_pDllCaller->GetCommonFilesFolder (sz);
			lstrcat (sz, "fumoei.exe");
			#endif

			ASSERT (GetFileAttributes (sz) != DWORD (-1));
			if (key.m_hKey) 
				key.SetValue (sz, "Free Uploader Oe Integration");
			ShellExecute (0, "open", sz, 0, 0, SW_SHOW);
		}
		else
		{
			HANDLE h = CreateEvent (NULL, TRUE, FALSE, "fum - oe - injapp");
			SetEvent (h);
			CloseHandle (h);
			if (key.m_hKey)
				key.DeleteValue ("Free Uploader Oe Integration");
		}
	}
	
	return CPropertyPage::OnApply();
}

void CUploaderProps_Integration::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC__S0, L_INTEGRATE_UPLOADER_TO, TRUE),
		fsDlgLngInfo (IDC_CM, L_EXPLORERS_CONTEXT_MENU),
		fsDlgLngInfo (IDC_STM, L_EXPLORERS_SENDTO_MENU),
		fsDlgLngInfo (IDC_OE_ASKUPLOAD, L_OE_ASK_UPLOAD),
		fsDlgLngInfo (IDC_OE__MINSIZE, L_MINIMUM_SIZE_OF_FILE_TO_UPLOAD, TRUE),
		fsDlgLngInfo (IDC__KB, L_KB),
	};

	vmsMfcLngHelper::ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), L_UPLOADFILES);
}

void CUploaderProps_Integration::OnOeAskupload() 
{
	SetModified ();
	UpdateEnabled ();
}

void CUploaderProps_Integration::OnIe() 
{
	SetModified ();	
}
