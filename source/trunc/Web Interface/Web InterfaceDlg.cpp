/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "Web Interface.h"
#include "Web InterfaceDlg.h"
#include "fsAutorunMgr.h"

#include <afxpriv.h>
#define DELETE_EXCEPTION(e) do { e->Delete(); } while (0)

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define WM_TRAYMSG	(WM_APP + 100)

CWebInterfaceDlg::CWebInterfaceDlg(CWnd* pParent )
	: CDialog(CWebInterfaceDlg::IDD, pParent),
	m_http (&m_fdmServer)
{
	//{{AFX_DATA_INIT(CWebInterfaceDlg)
		
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	m_nShutdownMsg = RegisterWindowMessage ("FDM - remote control server - shutdown");
}

void CWebInterfaceDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWebInterfaceDlg)
		
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CWebInterfaceDlg, CDialog)
	//{{AFX_MSG_MAP(CWebInterfaceDlg)
	ON_WM_QUERYDRAGICON()
	ON_WM_DESTROY()
	ON_COMMAND(ID_CONFIGURE, OnConfigure)
	ON_COMMAND(ID_SHUTDOWN, OnShutdown)
	ON_BN_CLICKED(IDC_OPEN_IN_BROWSER, OnOpenInBrowser)
	ON_MESSAGE (WM_TRAYMSG, OnTrayMsg)
	ON_BN_CLICKED(IDC_USEPWD, OnUsepwd)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CWebInterfaceDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	SetIcon(m_hIcon, TRUE);			
	SetIcon(m_hIcon, FALSE);		

	UINT nIdIcon = IDR_MAINFRAME;
	_TrayMgr.Create (m_hWnd, &nIdIcon, 1, "FDM remote control server", WM_TRAYMSG);

	m_http.set_Port (AfxGetApp ()->GetProfileInt ("Network", "Port", 80));
	SetDlgItemInt (IDC_PORT, m_http.get_Port ());
	
	m_http.Start ();

	UpdateAddress ();

	fsAutorunMgr am;
	CheckDlgButton (IDC_AUTORUN, am.IsAutoStart () ? BST_CHECKED : BST_UNCHECKED);

	CString strU = AfxGetApp ()->GetProfileString ("Network", "Login", "");
	CString strP = AfxGetApp ()->GetProfileString ("Network", "Password", "");

	if (strU.IsEmpty () == FALSE)
	{
		CheckDlgButton (IDC_USEPWD, BST_CHECKED);
		SetDlgItemText (IDC_USER, strU);
		SetDlgItemText (IDC_PWD, strP);
	}

	UpdateEnabled ();
	
	return TRUE;  
}

HCURSOR CWebInterfaceDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CWebInterfaceDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	
	_TrayMgr.Remove ();
}

LRESULT CWebInterfaceDlg::OnTrayMsg(WPARAM, LPARAM lp)
{
	switch (lp)
	{
		case WM_MOUSEMOVE:
			break;
		
		case WM_LBUTTONDOWN:
			OnConfigure ();
			break;

		case WM_RBUTTONUP:
			ShowTrayMenu ();
			break;
	}

	return 0;
}

void CWebInterfaceDlg::ShowTrayMenu()
{
	CMenu menu;
	menu.LoadMenu (IDM_TRAY);
	CMenu *pPopup = menu.GetSubMenu (0);

	SetForegroundWindow ();

	pPopup->SetDefaultItem (ID_CONFIGURE);

	CPoint pt;
	GetCursorPos (&pt);

	pPopup->TrackPopupMenu (TPM_RIGHTBUTTON | TPM_BOTTOMALIGN | TPM_RIGHTALIGN,	pt.x, pt.y, this);

	menu.DestroyMenu ();
}

void CWebInterfaceDlg::OnConfigure() 
{
	if (IsWindowVisible ())
	{
		ShowWindow (SW_HIDE);
	}
	else
	{
		ShowWindow (SW_SHOW);
		ShowWindow (SW_RESTORE);
		SetForegroundWindow ();
	}
}

void CWebInterfaceDlg::OnShutdown() 
{
	EndDialog (IDOK);
}

void CWebInterfaceDlg::OnOK() 
{
	UINT nPort = GetDlgItemInt (IDC_PORT);
	if (nPort > 0xffff)
	{
		SetDlgItemInt (IDC_PORT, m_http.get_Port (), FALSE);
		return;
	}

	if (nPort != m_http.get_Port ())
	{
		AfxGetApp ()->WriteProfileInt ("Network", "Port", nPort);

		m_http.Shutdown ();
		m_http.set_Port (nPort);
		m_http.Start ();

		UpdateAddress ();
	}

	fsAutorunMgr am;
	am.SetAutoStart (IsDlgButtonChecked (IDC_AUTORUN) == BST_CHECKED);

	CString strU, strP;
	if (IsDlgButtonChecked (IDC_USEPWD) == BST_CHECKED)
	{
		GetDlgItemText (IDC_USER, strU);
		GetDlgItemText (IDC_PWD, strP);
		AfxGetApp ()->WriteProfileString ("Network", "Login", strU);
		AfxGetApp ()->WriteProfileString ("Network", "Password", strP);
	}
	else
	{
		AfxGetApp ()->WriteProfileString ("Network", "Login", "");
		AfxGetApp ()->WriteProfileString ("Network", "Password", "");
	}

	ShowWindow (SW_HIDE);
}

void CWebInterfaceDlg::OnCancel() 
{
	ShowWindow (SW_HIDE);
}

int CWebInterfaceDlg::DoModal() 
{
		
	ASSERT(m_lpszTemplateName != NULL || m_hDialogTemplate != NULL ||
		m_lpDialogTemplate != NULL);

	
	LPCDLGTEMPLATE lpDialogTemplate = m_lpDialogTemplate;
	HGLOBAL hDialogTemplate = m_hDialogTemplate;
	HINSTANCE hInst = AfxGetResourceHandle();
	if (m_lpszTemplateName != NULL)
	{
		hInst = AfxFindResourceHandle(m_lpszTemplateName, RT_DIALOG);
		HRSRC hResource = ::FindResource(hInst, m_lpszTemplateName, RT_DIALOG);
		hDialogTemplate = LoadResource(hInst, hResource);
	}
	if (hDialogTemplate != NULL)
		lpDialogTemplate = (LPCDLGTEMPLATE)LockResource(hDialogTemplate);

	
	if (lpDialogTemplate == NULL)
		return -1;

	
	HWND hWndParent = PreModal();
	AfxUnhookWindowCreate();
	BOOL bEnableParent = FALSE;
	if (hWndParent != NULL && ::IsWindowEnabled(hWndParent))
	{
		::EnableWindow(hWndParent, FALSE);
		bEnableParent = TRUE;
	}

	TRY
	{
		
		AfxHookWindowCreate(this);
		if (CreateDlgIndirect(lpDialogTemplate,
						CWnd::FromHandle(hWndParent), hInst))
		{
			if (m_nFlags & WF_CONTINUEMODAL)
			{
				
				DWORD dwFlags = 0; 
				if (GetStyle() & DS_NOIDLEMSG)
					dwFlags |= MLF_NOIDLEMSG;
				VERIFY(RunModalLoop(dwFlags) == m_nModalResult);
			}

			
			if (m_hWnd != NULL)
				SetWindowPos(NULL, 0, 0, 0, 0, SWP_HIDEWINDOW|
					SWP_NOSIZE|SWP_NOMOVE|SWP_NOACTIVATE|SWP_NOZORDER);
		}
	}
	CATCH_ALL(e)
	{
		DELETE_EXCEPTION(e);
		m_nModalResult = -1;
	}
	END_CATCH_ALL

	if (bEnableParent)
		::EnableWindow(hWndParent, TRUE);
	if (hWndParent != NULL && ::GetActiveWindow() == m_hWnd)
		::SetActiveWindow(hWndParent);

	
	DestroyWindow();
	PostModal();

	
	if (m_lpszTemplateName != NULL || m_hDialogTemplate != NULL)
		UnlockResource(hDialogTemplate);
	if (m_lpszTemplateName != NULL)
		FreeResource(hDialogTemplate);

	return m_nModalResult;
}

void CWebInterfaceDlg::UpdateAddress()
{
	char szName [10000];
	gethostname (szName, 10000);
	
	hostent *he = gethostbyname (szName);

	int nPort = GetDlgItemInt (IDC_PORT);

	CString str;
	if (nPort == 80)
	{
		str.Format ("http://%d.%d.%d.%d/", (int)(BYTE)he->h_addr_list [0][0],
			(int)(BYTE)he->h_addr_list [0][1], (int)(BYTE)he->h_addr_list [0][2], 
			(int)(BYTE)he->h_addr_list [0][3]);
	}
	else
	{
		str.Format ("http://%d.%d.%d.%d:%d/", (int)(BYTE)he->h_addr_list [0][0],
			(int)(BYTE)he->h_addr_list [0][1], (int)(BYTE)he->h_addr_list [0][2], 
			(int)(BYTE)he->h_addr_list [0][3], nPort);
	}

	SetDlgItemText (IDC_SERV_ADDR, str);
}

void fsOpenUrlInBrowser (LPCSTR pszUrl)
{
	char szReg [100];
	char szBrowser [1000];
	DWORD dwBrowserLen = 1000;

	

	if (strnicmp (pszUrl, "http", 4) == 0)
		strcpy (szReg, "http");
	else if (strnicmp (pszUrl, "https", 5) == 0)
		strcpy (szReg, "https");
	else
		strcpy (szReg, "ftp");

	strcat (szReg, "\\shell\\open\\command");

	HKEY hReg;

	if (ERROR_SUCCESS != RegOpenKeyEx (HKEY_CLASSES_ROOT, szReg, 0, KEY_QUERY_VALUE, &hReg))
		goto _lErr;

	if (ERROR_SUCCESS != RegQueryValueEx (hReg, NULL, NULL, NULL, (LPBYTE) szBrowser, &dwBrowserLen))
	{
		RegCloseKey (hReg);
		goto _lErr;
	}

	RegCloseKey (hReg);

	strlwr (szBrowser);
	LPSTR pszExe;
	pszExe = strstr (szBrowser, ".exe");

	if (pszExe == NULL)
		goto _lErr;

	pszExe [4] = 0;

	if (32 >= (int)ShellExecute (HWND_DESKTOP, "open", szBrowser [0] == '"' ? szBrowser+1 : szBrowser, pszUrl, NULL, SW_SHOW))
		goto _lErr;

	return;

_lErr:
	if (32 >= (int) ShellExecute (HWND_DESKTOP, "open", pszUrl, NULL, NULL, SW_SHOW))
		MessageBox (NULL, pszUrl, "failed to open", MB_ICONERROR);
}

void CWebInterfaceDlg::OnOpenInBrowser() 
{
	OnOK ();
	CString str;
	GetDlgItemText (IDC_SERV_ADDR, str);
	fsOpenUrlInBrowser (str);
}

LRESULT CWebInterfaceDlg::WindowProc(UINT message, WPARAM wParam, LPARAM lParam) 
{
	if (message == m_nShutdownMsg)
	{
		fsAutorunMgr am;
		am.SetAutoStart (FALSE);
		EndDialog (IDOK);
		return 0;
	}
	
	return CDialog::WindowProc(message, wParam, lParam);
}

void CWebInterfaceDlg::OnUsepwd() 
{
	UpdateEnabled ();	
}

void CWebInterfaceDlg::UpdateEnabled()
{
	BOOL b = IsDlgButtonChecked (IDC_USEPWD) == BST_CHECKED;
	GetDlgItem (IDC__S0)->EnableWindow (b);
	GetDlgItem (IDC__S1)->EnableWindow (b);
	GetDlgItem (IDC_USER)->EnableWindow (b);
	GetDlgItem (IDC_PWD)->EnableWindow (b);
}
