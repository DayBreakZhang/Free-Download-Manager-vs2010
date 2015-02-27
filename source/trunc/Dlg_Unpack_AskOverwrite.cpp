/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "Dlg_Unpack_AskOverwrite.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDlg_Unpack_AskOverwrite::CDlg_Unpack_AskOverwrite(CWnd* pParent )
	: CDialog(CDlg_Unpack_AskOverwrite::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_Unpack_AskOverwrite)
		
	//}}AFX_DATA_INIT
	m_puNewSize = NULL;
	m_ptimeNewLastModified = NULL;
}

void CDlg_Unpack_AskOverwrite::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_Unpack_AskOverwrite)
		
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlg_Unpack_AskOverwrite, CDialog)
	//{{AFX_MSG_MAP(CDlg_Unpack_AskOverwrite)
	ON_BN_CLICKED(IDC_YES, OnYes)
	ON_BN_CLICKED(IDC_YESFORALL, OnYesforall)
	ON_BN_CLICKED(IDC_NO2, OnNo)
	ON_BN_CLICKED(IDC_NOFORALL, OnNoforall)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CDlg_Unpack_AskOverwrite::OnYes() 
{
	m_enOM = AC_OM_OVERWRITE;
	EndDialog (IDOK);	
}

void CDlg_Unpack_AskOverwrite::OnYesforall() 
{
	m_bForAll = true;
	OnYes ();
}

void CDlg_Unpack_AskOverwrite::OnNo() 
{
	m_enOM = AC_OM_SKIP;	
	EndDialog (IDOK);
}

void CDlg_Unpack_AskOverwrite::OnNoforall() 
{
	m_bForAll = true;	
	OnNo ();
}

void CDlg_Unpack_AskOverwrite::OnCancel() 
{
	m_enOM = AC_OM_CANCEL;
	CDialog::OnCancel();
}

BOOL CDlg_Unpack_AskOverwrite::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_bForAll = false;

	CString str;
	char szFileName [MY_MAX_PATH];
	fsGetFileName (m_strFile, szFileName);

	CString str1; 
	CString str2;

	HANDLE hFile = CreateFile (m_strFile, GENERIC_READ, 
		FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL);
	if (hFile != INVALID_HANDLE_VALUE) 
	{
		DWORD dwSizeHigh = 0, dwSizeLow = GetFileSize (hFile, &dwSizeHigh);
		FILETIME timeLastWrite;
		GetFileTime (hFile, NULL, NULL, &timeLastWrite);
		CloseHandle (hFile);
		ULARGE_INTEGER uli; 
		uli.LowPart = dwSizeLow; uli.HighPart = dwSizeHigh;
		str1 = GetFileInfoString (&timeLastWrite, &uli.QuadPart);
	}
	else
		str1.Format ("%s, %s", LS (L_UNKNOWN), LS (L_UNKNOWN));

	str2 = GetFileInfoString (m_ptimeNewLastModified, m_puNewSize);

	str.Format (LS (L_UNPACK_EXISTSALREADYMSG), szFileName, str1, str2);
	SetDlgItemText (IDC__MSG, str);

	ApplyLanguage ();
	
	return TRUE;
}

CString CDlg_Unpack_AskOverwrite::GetFileInfoString(FILETIME *time, UINT64 *size)
{
	CString str, str2;

	if (time)
	{
		SYSTEMTIME systime;
		FileTimeToSystemTime (time, &systime);
		char szDate [1000], szTime [1000];
		SystemTimeToStr (&systime, szDate, szTime, TRUE);
		str2 = szDate; str2 += ", "; str2 += szTime;
	}
	else
		str2 = LS (L_UNKNOWN);

	str.Format ("%s, %s", size ? BytesToString (*size) : LS (L_UNKNOWN), 
		str2);

	return str;
}

void CDlg_Unpack_AskOverwrite::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC_YES, L_YES),
		fsDlgLngInfo (IDC_YESFORALL, L_YESFORALL),
		fsDlgLngInfo (IDC_NO2, L_SKIP),
		fsDlgLngInfo (IDC_NOFORALL, L_SKIPALL),
		fsDlgLngInfo (IDCANCEL, L_CANCEL),
	};

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), L_CONFIRMATION);
}
