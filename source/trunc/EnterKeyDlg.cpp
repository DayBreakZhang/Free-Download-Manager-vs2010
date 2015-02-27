/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "EnterKeyDlg.h"
#include "misc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CEnterKeyDlg::CEnterKeyDlg(CWnd* pParent )
	: CDialog(CEnterKeyDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEnterKeyDlg)
		
	//}}AFX_DATA_INIT
}

void CEnterKeyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEnterKeyDlg)
		
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CEnterKeyDlg, CDialog)
	//{{AFX_MSG_MAP(CEnterKeyDlg)
	ON_BN_CLICKED(IDC_GETKEY, OnGetkey)
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_WHATISTHIS, OnWhatisthis)
	ON_WM_HELPINFO()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CEnterKeyDlg::OnGetkey() 
{
	fsOpenBuyPage ();
}

BOOL CEnterKeyDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	ApplyLanguage ();
	
	return TRUE;  
	              
}

void CEnterKeyDlg::OnContextMenu(CWnd* , CPoint point) 
{
	PrepareCHMgr (point);
	_CHMgr.ShowMenu ();
}

void CEnterKeyDlg::OnWhatisthis() 
{
	_CHMgr.OnWT ();	
}

void CEnterKeyDlg::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC__KEY, L_KEY),
		fsDlgLngInfo (IDC__KEYNOTE, L_KEYNOTE),
		fsDlgLngInfo (IDC_GETKEY, L_GETKEY),
		fsDlgLngInfo (IDCANCEL, L_CANCEL),
	};

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), L_REGISTRATION);
}

BOOL CEnterKeyDlg::RegisterKey(LPCSTR pszKey)
{
	HKEY hKey;
    DWORD dwDisposition;

	if (ERROR_SUCCESS != RegCreateKeyEx (HKEY_CURRENT_USER, "Software\\FreeDownloadManager.ORG\\Free Download Manager", 0, NULL,
				REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, &hKey, &dwDisposition)) 
    {
        return FALSE;
    }

	if (ERROR_SUCCESS != RegSetValueEx (hKey, "Key", 0, REG_SZ, (BYTE*)pszKey, strlen (pszKey) ))
    { 
        RegCloseKey(hKey);
        return FALSE;
    }

    RegCloseKey(hKey);
    return TRUE;
}

void CEnterKeyDlg::OnOK() 
{
	CString strKey;
	GetDlgItemText (IDC_KEY, strKey);
	if (strKey != "")
	{
		if (RegisterKey (strKey) == FALSE)
			MessageBox (LS (L_FAILEDTOREG), LS (L_ERR), MB_ICONERROR);
		else
			MessageBox (LS (L_THANKSFORREG), LS (L_SUCCESS), MB_OK);
	}
	CDialog::OnOK();
}

BOOL CEnterKeyDlg::OnHelpInfo(HELPINFO* pHelpInfo) 
{
	RECT rc;
	CWnd *pItem = GetDlgItem (pHelpInfo->iCtrlId);
	if (pItem == NULL)
		return TRUE;
	pItem->GetWindowRect (&rc);
	if (PtInRect (&rc, pHelpInfo->MousePos) == FALSE)
	{
		pHelpInfo->MousePos.x = rc.left + (rc.right - rc.left) / 2;
		pHelpInfo->MousePos.y = rc.top + (rc.bottom - rc.top) / 2;
	}
	PrepareCHMgr (pHelpInfo->MousePos);
	_CHMgr.OnWT ();
	return TRUE;
}

void CEnterKeyDlg::PrepareCHMgr(CPoint point)
{
	fsCtrlContextHelp aCH1 [] = {
		fsCtrlContextHelp (IDC__KEY, LS (L_SPECKEY)),
		fsCtrlContextHelp (IDC_KEY, LS (L_SPECKEY)),

		fsCtrlContextHelp (IDOK, LS (L_CLICKAFTER)),
		fsCtrlContextHelp (IDCANCEL, LS (L_DONTREGISTER)),
	};

    static fsCtrlContextHelp aCH [sizeof (aCH1) / sizeof (fsCtrlContextHelp)];
	CopyMemory (aCH, aCH1, sizeof (aCH));

	_CHMgr.PrepareContextMenu (this, point, aCH, sizeof (aCH) / sizeof (fsCtrlContextHelp));
}
