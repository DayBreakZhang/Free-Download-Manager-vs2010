/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "Dlg_UnpackProgress.h"
#include "vmsArchiveMgr.h"
#include "Dlg_Unpack_AskOverwrite.h"
#include "Dlg_Unpack_InstAddPack.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDlg_UnpackProgress::CDlg_UnpackProgress(CWnd* pParent )
	: CDialog(CDlg_UnpackProgress::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_UnpackProgress)
		
	//}}AFX_DATA_INIT
	m_bNeedStop = false;
	m_bDone = false;
}

void CDlg_UnpackProgress::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_UnpackProgress)
	DDX_Control(pDX, IDC_PROGRESS, m_wndProgress);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlg_UnpackProgress, CDialog)
	//{{AFX_MSG_MAP(CDlg_UnpackProgress)
	ON_BN_CLICKED(IDC_OPENFOLDER, OnOpenfolder)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

bool CDlg_UnpackProgress::BeforeExtract(LPCSTR pszFile)
{
	CString str;
	str.Format ("Extracting: %s...", pszFile);
	SetDlgItemText (IDC__EXTRACTING, str);
	return m_bNeedStop == false;
}

bool CDlg_UnpackProgress::AfterExtract(LPCSTR pszFile, vmsAC_ExtractResult res)
{
	return true;
}

bool CDlg_UnpackProgress::SetProgress(int nProgress)
{
	m_wndProgress.SetPos (nProgress);
	return m_bNeedStop == false;
}

BOOL CDlg_UnpackProgress::OnInitDialog() 
{
	CDialog::OnInitDialog();

	ApplyLanguage ();

	GetDlgItem (IDC_OPENFOLDER)->EnableWindow (FALSE);
	
	DWORD dw;
	CloseHandle (
		CreateThread (NULL, 0, _threadExtract, this, 0, &dw));
	
	return TRUE;  
	              
}

DWORD WINAPI CDlg_UnpackProgress::_threadExtract(LPVOID lp)
{
	CDlg_UnpackProgress* pthis = (CDlg_UnpackProgress*)lp;

	vmsArchiveMgr ar;
	ar.set_ArchiveCallback (pthis);
	if (false == ar.Extract (pthis->m_strArchive, pthis->m_strDstFolder)) {
		if (ar.get_LastExtractError () != AEE_ABORTED_BY_USER) {
			if (_App.IsArchivePackInstalled () == FALSE &&
					_App.DontShowInstallAP () == FALSE) {
				CDlg_Unpack_InstAddPack dlg;
				_DlgMgr.DoModal (&dlg);
			}
			else {
				pthis->MessageBox (LS (L_UNSUPPARCFMT), LS (L_ERR), MB_ICONERROR);
			}
		}
		pthis->m_bNeedStop = true;
	}
	
	if (pthis->m_bNeedStop == false)
	{
		pthis->m_bDone = true;
		pthis->SetDlgItemText (IDCANCEL, "OK");
		pthis->GetDlgItem (IDC_OPENFOLDER)->EnableWindow (TRUE);
		pthis->m_wndProgress.SetPos (100);
		pthis->SetDlgItemText (IDC__EXTRACTING, LS (L_DONE));
	}
	else 
	{
		pthis->PostMessage (WM_COMMAND, IDCANCEL);
	}

	return 0;
}

void CDlg_UnpackProgress::OnCancel() 
{
	if (m_bNeedStop)
		EndDialog (IDCANCEL);
	else
	{
		if (m_bDone == false)
		{
			GetDlgItem (IDCANCEL)->EnableWindow (FALSE);
			m_bNeedStop = true;
		}
		else 
		{
			EndDialog (IDOK);
		}
	}
}

void CDlg_UnpackProgress::OnOpenfolder() 
{
	ShellExecute (NULL, "explore", m_strDstFolder, NULL, NULL, SW_SHOW);
	EndDialog (IDOK);
}

void CDlg_UnpackProgress::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC_OPENFOLDER, L_OPENFOLDER),
		fsDlgLngInfo (IDCANCEL, L_CANCEL),
	};

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), L_EXTRACTION);
}

void CDlg_UnpackProgress::AskOverwrite(vmsOverwriteFileInfo &ofi, vmsAC_OverwriteMode &enOM, bool &bForAll)
{
	CDlg_Unpack_AskOverwrite dlg;
	dlg.m_strFile = ofi.pszFile;
	dlg.m_ptimeNewLastModified = ofi.ptimeNewLastWrite;
	dlg.m_puNewSize = ofi.puNewSize;
	_DlgMgr.DoModal (&dlg);
	enOM = dlg.m_enOM;
	bForAll = dlg.m_bForAll;
}
