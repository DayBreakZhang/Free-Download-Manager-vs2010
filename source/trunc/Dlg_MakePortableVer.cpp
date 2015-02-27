/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "Dlg_MakePortableVer.h"
#include "FolderBrowser.h"
#include "mfchelp.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDlg_MakePortableVer::CDlg_MakePortableVer(CWnd* pParent )
	: CDialog(CDlg_MakePortableVer::IDD, pParent)
{
	m_bThreadRunning = false;
	m_bNeedStop = false;
}

void CDlg_MakePortableVer::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_MakePortableVer)
	DDX_Control(pDX, IDC_PROGRESS, m_wndProgress);
	DDX_Control(pDX, IDC_CHOOSEFOLDER, m_btnChooseFolder);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlg_MakePortableVer, CDialog)
	//{{AFX_MSG_MAP(CDlg_MakePortableVer)
	ON_BN_CLICKED(IDC_CHOOSEFOLDER, OnChoosefolder)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CDlg_MakePortableVer::OnChoosefolder() 
{
	CString str;
	GetDlgItemText (IDC_OUTFOLDER, str);

	if (str.GetLength () > 3 && (str [str.GetLength () - 1] == '\\' || str [str.GetLength () - 1] == '/'))
		str.GetBuffer (0) [str.GetLength () - 1] = 0;

	CFolderBrowser *fb = CFolderBrowser::Create (LS (L_CHOOSEOUTFOLDER), str, NULL, this);
	if (fb == NULL)
		return;

	SetDlgItemText (IDC_OUTFOLDER, fb->GetPath ());
	GetDlgItem (IDC_OUTFOLDER)->SetFocus ();	
}

void CDlg_MakePortableVer::OnOK() 
{
	CString str;
	GetDlgItemText (IDC_OUTFOLDER, str);

	if (str.IsEmpty ())
	{
		MessageBox (LS (L_ENTERFLRNAME), LS (L_INPERR), MB_ICONEXCLAMATION);
		GetDlgItem (IDC_OUTFOLDER)->SetFocus ();
		return;
	}

	DWORD dw;
	m_bThreadRunning = true;
	CloseHandle (
		CreateThread (NULL, 0, _threadCreatePortableVer, this, 0, &dw));

	
}

BOOL CDlg_MakePortableVer::OnInitDialog() 
{
	CDialog::OnInitDialog();
		
	m_btnChooseFolder.SetIcon (SICO (IDI_CHOOSEFOLDER));

	m_wndProgress.ShowWindow (SW_HIDE);

	ApplyLanguage ();
	
	return TRUE;  
	              
}

void CDlg_MakePortableVer::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC__PVDESC, L_PORTABLE_VER_DESC),
		fsDlgLngInfo (IDCANCEL, L_CANCEL),
	};

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), L_MAKE_PORTABLE_VER);
}

DWORD WINAPI CDlg_MakePortableVer::_threadCreatePortableVer(LPVOID lp)
{
	CDlg_MakePortableVer *pthis = (CDlg_MakePortableVer*) lp;

	pthis->GetDlgItem (IDC_OUTFOLDER)->ShowWindow (SW_HIDE);
	pthis->GetDlgItem (IDC_CHOOSEFOLDER)->ShowWindow (SW_HIDE);
	pthis->GetDlgItem (IDOK)->EnableWindow (FALSE);

	pthis->m_wndProgress.ShowWindow (SW_SHOW);
	
	CString str;
	pthis->GetDlgItemText (IDC_OUTFOLDER, str);

	if (str [str.GetLength () - 1] != '\\' && str [str.GetLength () - 1] != '/')
		str += '\\';
	str += "Free Download Manager";

	CString str2 = str + "\\1";
	fsBuildPathToFile (str2);

	int nTotal = 0;
	
	pthis->CopyDirTree (((CFdmApp*)AfxGetApp ())->m_strAppPath, str, nTotal, 0);
	pthis->m_wndProgress.SetRange32 (0, nTotal);
	
	int i = 0;
	pthis->CopyDirTree (((CFdmApp*)AfxGetApp ())->m_strAppPath, str, i, nTotal);

	pthis->m_bThreadRunning = false;
	pthis->PostMessage (WM_COMMAND, IDCANCEL);

	return 0;
}

void CDlg_MakePortableVer::CopyDirTree(CString SrcPath, CString DstPath, int& nCurIndex, int nTotalCount)
{
	CString CrntSrcPath = SrcPath;
    CString CrntDstPath;

    CFileFind Finder;

    
    CrntSrcPath += _T("\\*");    

    BOOL bResult = Finder.FindFile(CrntSrcPath);
    
    while (bResult)
    {
        bResult = Finder.FindNextFile();
        
        if (Finder.IsDots()) continue; 
                             
    
        CrntSrcPath = Finder.GetFilePath();
        CrntDstPath = DstPath + _T("\\") + Finder.GetFileName();
        
        
        if (Finder.IsDirectory())
        {
			if (nTotalCount != 0)
				CreateDirectory(CrntDstPath, NULL);
            CopyDirTree(CrntSrcPath, CrntDstPath, nCurIndex, nTotalCount);
        }
        else
        {
			if (m_bNeedStop) 
			{
				nTotalCount = 0;
				return;
			}

			if (nTotalCount != 0)
				CopyFile(CrntSrcPath, CrntDstPath, FALSE);
			nCurIndex++;
			if (nTotalCount != 0)
				m_wndProgress.SetPos (nCurIndex);
        }
    }
    
    Finder.Close();
}

void CDlg_MakePortableVer::OnCancel() 
{
	if (m_bThreadRunning)
	{
		m_bNeedStop = true;
		GetDlgItem (IDCANCEL)->EnableWindow (FALSE);
	}
	else	
	{
		CDialog::OnCancel();
	}
}
