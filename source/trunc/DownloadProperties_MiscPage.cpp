/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "DownloadProperties_MiscPage.h"
#include "DownloadProperties.h"
#include "misc.h"
#include "DownloadsWnd.h"
#include "fsDownloadMgr.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNCREATE(CDownloadProperties_MiscPage, CPropertyPage)

CDownloadProperties_MiscPage::CDownloadProperties_MiscPage() : CPropertyPage(CDownloadProperties_MiscPage::IDD)
{
	m_psp.dwFlags |= PSP_USETITLE;
	m_psp.pszTitle = LS (L_MISC);
}

CDownloadProperties_MiscPage::~CDownloadProperties_MiscPage()
{
}

void CDownloadProperties_MiscPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDownloadProperties_MiscPage)
	DDX_Control(pDX, IDC_SCR, m_wndSCR);
	DDX_Control(pDX, IDC_AER, m_wndAER);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDownloadProperties_MiscPage, CPropertyPage)
	//{{AFX_MSG_MAP(CDownloadProperties_MiscPage)
	ON_CBN_SELCHANGE(IDC_AER, OnSelchangeAer)
	ON_CBN_SELCHANGE(IDC_SCR, OnSelchangeScr)
	ON_BN_CLICKED(IDC_RESERVESPACE, OnReservespace)
	ON_BN_CLICKED(IDC_USEEXT, OnUseext)
	ON_EN_CHANGE(IDC_EXT, OnChangeExt)
	ON_BN_CLICKED(IDC_DONTRESTARTIFNORESUME, OnDontrestartifnoresume)
	ON_BN_CLICKED(IDC_FILENOTFOUND, OnFilenotfound)
	ON_BN_CLICKED(IDC_ACCDENIED, OnAccdenied)
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_WHATISTHIS, OnWhatisthis)
	ON_WM_HELPINFO()
	ON_BN_CLICKED(IDC_USECREATEEXT, OnUsecreateext)
	ON_EN_CHANGE(IDC_CREATEEXT, OnChangeCreateext)
	ON_BN_CLICKED(IDC_USEHIDDENFLAG, OnUsehiddenflag)
	ON_BN_CLICKED(IDC_APPENDCOMMENT, OnAppendcomment)
	ON_BN_CLICKED(IDC_LAUNCHWHENDONE, OnLaunchwhendone)
	ON_BN_CLICKED(IDC_RETRFILEDATE, OnRetrfiledate)
	ON_BN_CLICKED(IDC_GENERATEINFOFILE, OnGenerateinfofile)
	ON_BN_CLICKED(IDC_RENAMEATRESTART, OnRenameatrestart)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

#define DP_OFFSET(member) ( LPBYTE (&dp.member) - LPBYTE (&dp) )
#define DP_SIZEOF(member) ( sizeof (dp.member) )
#define DP_EQ_EX(memOffset, memSize, bString) DPEntry_IsAllEqual (m_pvDlds, memOffset, memSize, bString)
#define DP_EQ_MASK(member, mask) DPEntry_IsAllEqual_BitMask (m_pvDlds, DP_OFFSET (member), mask)
#define DP_EQ(member, bString) DP_EQ_EX (DP_OFFSET (member), DP_SIZEOF (member), bString)
#define DP_SET_EX(memOffset, memSize, bString, NewVal) DPEntry_SetValue (m_pvDlds, memOffset, memSize, bString, NewVal)
#define DP_SET(member, bString, NewVal) DP_SET_EX (DP_OFFSET (member), DP_SIZEOF (member), bString, NewVal)
#define DP_SET_MASK(member, mask) DPEntry_SetValue_BitMask (m_pvDlds, DP_OFFSET (member), mask)
#define DP_UNSET_MASK(member, mask) DPEntry_UnsetValue_BitMask (m_pvDlds, DP_OFFSET (member), mask)

BOOL CDownloadProperties_MiscPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	fsDownload_Properties dp;
	fsDownload_Properties *dp0 = m_pvDlds->at (0)->pMgr->GetDownloadMgr ()->GetDP ();

	m_wndAER.AddString (LS (L_ASK));
	m_wndAER.AddString (LS (L_REWRITE));
	m_wndAER.AddString (LS (L_RENAME));
	m_wndAER.AddString (LS (L_RESUME));
	m_wndAER.AddString (LS (L_STOP));
	if (DP_EQ (enAER, FALSE))
	{
		int i = dp0->enAER;
		if (i == AER_RENAME_2)
		{
			i = AER_RENAME;
			CheckDlgButton (IDC_RENAMEATRESTART, BST_CHECKED);
		}
		m_wndAER.SetCurSel (i);
	}

	if (DP_EQ (bReserveDiskSpace, FALSE))
		CheckDlgButton (IDC_RESERVESPACE, dp0->bReserveDiskSpace ? BST_CHECKED : BST_UNCHECKED);
	else
		CheckDlgButton (IDC_RESERVESPACE, BST_INDETERMINATE);

	if (DP_EQ (pszAdditionalExt, TRUE))
	{
		CheckDlgButton (IDC_USEEXT, *dp0->pszAdditionalExt ? BST_CHECKED : BST_UNCHECKED);
		SetDlgItemText (IDC_EXT, dp0->pszAdditionalExt);
	}
	else
	{
		BOOL bUse = *dp0->pszAdditionalExt != 0;
		int i;
		for (i = m_pvDlds->size () - 1; i; i--)
		{
			BOOL bU = *m_pvDlds->at (i)->pMgr->GetDownloadMgr ()->GetDP ()->pszAdditionalExt != 0;
			if (bUse != bU)
				break;
		}

		if (i)
			CheckDlgButton (IDC_USEEXT, BST_INDETERMINATE);
		else
			CheckDlgButton (IDC_USEEXT, bUse ? BST_CHECKED : BST_UNCHECKED);			
	}

	if (DP_EQ (pszCreateExt, TRUE))
	{
		CheckDlgButton (IDC_USECREATEEXT, *dp0->pszCreateExt ? BST_CHECKED : BST_UNCHECKED);
		SetDlgItemText (IDC_CREATEEXT, dp0->pszCreateExt);
	}
	else
	{
		BOOL bUse = *dp0->pszCreateExt != 0;
		int i;
		for (i = m_pvDlds->size () - 1; i; i--)
		{
			BOOL bU = *m_pvDlds->at (i)->pMgr->GetDownloadMgr ()->GetDP ()->pszCreateExt != 0;
			if (bUse != bU)
				break;
		}

		if (i)
			CheckDlgButton (IDC_USECREATEEXT, BST_INDETERMINATE);
		else
			CheckDlgButton (IDC_USECREATEEXT, bUse ? BST_CHECKED : BST_UNCHECKED);			
	}

	if (DP_EQ_MASK (dwFlags, DPF_USEHIDDENATTRIB))
		CheckDlgButton (IDC_USEHIDDENFLAG, dp0->dwFlags & DPF_USEHIDDENATTRIB ? BST_CHECKED : BST_UNCHECKED);
	else
		CheckDlgButton (IDC_USEHIDDENFLAG, BST_INDETERMINATE);

	if (DP_EQ_MASK (dwFlags, DPF_DONTRESTARTIFNORESUME))
		CheckDlgButton (IDC_DONTRESTARTIFNORESUME, dp0->dwFlags & DPF_DONTRESTARTIFNORESUME ? BST_CHECKED : BST_UNCHECKED);
	else
		CheckDlgButton (IDC_DONTRESTARTIFNORESUME, BST_INDETERMINATE);

	if (DP_EQ_MASK (dwFlags, DPF_APPENDCOMMENTTOFILENAME))
		CheckDlgButton (IDC_APPENDCOMMENT, dp0->dwFlags & DPF_APPENDCOMMENTTOFILENAME ? BST_CHECKED : BST_UNCHECKED);
	else
		CheckDlgButton (IDC_APPENDCOMMENT, BST_INDETERMINATE);

	if (DP_EQ_MASK (dwFlags, DPF_STARTWHENDONE))
		CheckDlgButton (IDC_LAUNCHWHENDONE, dp0->dwFlags & DPF_STARTWHENDONE ? BST_CHECKED : BST_UNCHECKED);
	else
		CheckDlgButton (IDC_LAUNCHWHENDONE, BST_INDETERMINATE);

	if (DP_EQ_MASK (dwFlags, DPF_RETRDATEFROMSERVER))
		CheckDlgButton (IDC_RETRFILEDATE, dp0->dwFlags & DPF_RETRDATEFROMSERVER ? BST_CHECKED : BST_UNCHECKED);
	else
		CheckDlgButton (IDC_RETRFILEDATE, BST_INDETERMINATE);

	if (DP_EQ_MASK (dwFlags, DPF_GENERATEDESCFILE))
		CheckDlgButton (IDC_GENERATEINFOFILE, dp0->dwFlags & DPF_GENERATEDESCFILE ? BST_CHECKED : BST_UNCHECKED);
	else
		CheckDlgButton (IDC_GENERATEINFOFILE, BST_INDETERMINATE);

	m_wndSCR.AddString (LS (L_ASK));
	m_wndSCR.AddString (LS (L_RESTART));
	m_wndSCR.AddString (LS (L_ADJUST));
	m_wndSCR.AddString (LS (L_STOP));

	if (DP_EQ (enSCR, FALSE))
		m_wndSCR.SetCurSel (dp0->enSCR);

	
	

	
	UINT nID [] = { IDC_FILENOTFOUND, IDC_ACCDENIED };
	int i = 0;
	for (i = 0; i < sizeof (nID) / sizeof (UINT); i++)
	{
		if (DP_EQ_EX (DP_OFFSET (aEP)+i*sizeof (fsDownloadFileErrorProcessing), sizeof (fsDownloadFileErrorProcessing), FALSE))
			CheckDlgButton (nID [i], dp0->aEP [i] == DFEP_STOP ? BST_CHECKED : BST_UNCHECKED);
		else
			CheckDlgButton (nID [i], BST_INDETERMINATE);
	}
	
	
	m_bMayRename = TRUE;
	for (i = m_pvDlds->size () - 1; i >= 0; i--)
	{
		
		if (m_pvDlds->at (i)->pMgr->GetDownloadMgr ()->IsRunning () || m_pvDlds->at (i)->pMgr->GetDownloadMgr ()->GetDownloader ()->GetNumberOfSections ())
			m_bMayRename = FALSE;	
	}

	UpdateEnabled ();

	m_bExtModified = m_bCreateExtModified = FALSE;

	ApplyLanguage ();

	return TRUE;
}

void CDownloadProperties_MiscPage::OnSelchangeAer() 
{
	SetModified ();	
	UpdateEnabled ();
}

void CDownloadProperties_MiscPage::OnSelchangeScr() 
{
	SetModified ();	
}

void CDownloadProperties_MiscPage::OnReservespace() 
{
	if (IsDlgButtonChecked (IDC_RESERVESPACE) == BST_INDETERMINATE)
		CheckDlgButton (IDC_RESERVESPACE, BST_UNCHECKED);

	SetModified ();	
}

void CDownloadProperties_MiscPage::OnUseext() 
{
	if (IsDlgButtonChecked (IDC_USEEXT) == BST_INDETERMINATE)
		CheckDlgButton (IDC_USEEXT, BST_UNCHECKED);

	UpdateEnabled ();
	SetModified ();
	m_bExtModified = TRUE;
}

void CDownloadProperties_MiscPage::OnChangeExt() 
{
	m_bExtModified = TRUE;
	SetModified ();
}

void CDownloadProperties_MiscPage::OnDontrestartifnoresume() 
{
	if (IsDlgButtonChecked (IDC_DONTRESTARTIFNORESUME) == BST_INDETERMINATE)
		CheckDlgButton (IDC_DONTRESTARTIFNORESUME, BST_UNCHECKED);

	SetModified ();
}

void CDownloadProperties_MiscPage::OnFilenotfound() 
{
	if (IsDlgButtonChecked (IDC_FILENOTFOUND) == BST_INDETERMINATE)
		CheckDlgButton (IDC_FILENOTFOUND, BST_UNCHECKED);

	SetModified ();
}

void CDownloadProperties_MiscPage::OnAccdenied() 
{
	if (IsDlgButtonChecked (IDC_ACCDENIED) == BST_INDETERMINATE)
		CheckDlgButton (IDC_ACCDENIED, BST_UNCHECKED);

	SetModified ();
}

void CDownloadProperties_MiscPage::UpdateEnabled()
{
	GetDlgItem (IDC_EXT)->EnableWindow (m_bMayRename && IsDlgButtonChecked (IDC_USEEXT) == BST_CHECKED);
	GetDlgItem (IDC_USEEXT)->EnableWindow (m_bMayRename);
	GetDlgItem (IDC_CREATEEXT)->EnableWindow (m_bMayRename && IsDlgButtonChecked (IDC_USECREATEEXT) == BST_CHECKED);
	GetDlgItem (IDC_USECREATEEXT)->EnableWindow (m_bMayRename);
	GetDlgItem (IDC_RENAMEATRESTART)->EnableWindow (
		m_wndAER.GetCurSel () == AER_RENAME);
}

BOOL CDownloadProperties_MiscPage::OnApply() 
{
	int iCur;
	fsDownload_Properties dp;

	iCur = m_wndAER.GetCurSel ();
	if (iCur != CB_ERR)
	{
		if (iCur == AER_RENAME && 
				IsDlgButtonChecked (IDC_RENAMEATRESTART) == BST_CHECKED)
			iCur = AER_RENAME_2;
		DP_SET (enAER, FALSE, &iCur);
	}

	UINT uChecked = IsDlgButtonChecked (IDC_RESERVESPACE);
	if (uChecked != BST_INDETERMINATE)
	{
		BOOL b = uChecked == BST_CHECKED;
		DP_SET (bReserveDiskSpace, FALSE, &b);
	}

	uChecked = IsDlgButtonChecked (IDC_USEEXT);
	if (uChecked == BST_CHECKED)
	{
		if (m_bExtModified)
		{
			CString str;
			GetDlgItemText (IDC_EXT, str);
			if (str.GetLength () == 0)
			{
				MessageBox (LS (L_ENTEREXT), LS (L_INPERR), MB_ICONEXCLAMATION);
				GetDlgItem (IDC_EXT)->SetFocus ();
				return FALSE;
			}

			DP_SET (pszAdditionalExt, TRUE, str);
		}
	}
	else if (uChecked == BST_UNCHECKED)
		DP_SET (pszAdditionalExt, TRUE, "");

	uChecked = IsDlgButtonChecked (IDC_USECREATEEXT);
	if (uChecked == BST_CHECKED)
	{
		if (m_bCreateExtModified)
		{
			CString str;
			GetDlgItemText (IDC_CREATEEXT, str);
			if (str.GetLength () == 0)
			{
				MessageBox (LS (L_ENTEREXT), LS (L_INPERR), MB_ICONEXCLAMATION);
				GetDlgItem (IDC_CREATEEXT)->SetFocus ();
				return FALSE;
			}

			DP_SET (pszCreateExt, TRUE, str);
		}
	}
	else if (uChecked == BST_UNCHECKED)
		DP_SET (pszCreateExt, TRUE, "");

	uChecked = IsDlgButtonChecked (IDC_USEHIDDENFLAG);
	if (uChecked != BST_INDETERMINATE)
	{
		for (size_t i = 0; i < m_pvDlds->size (); i++)
		{
			vmsDownloadSmartPtr dld = m_pvDlds->at (i);
			LPCSTR pszFile = dld->pMgr->GetDownloadMgr ()->GetDP ()->pszFileName;
			DWORD dw = DWORD (-1);
			if (pszFile)
				dw = GetFileAttributes (pszFile);
	
			BOOL bOK = TRUE;

			if (dw != DWORD (-1) && (dw & FILE_ATTRIBUTE_DIRECTORY) == 0 && dld->pMgr->GetDownloadMgr ()->IsDone () == FALSE)
			{
				if (uChecked == BST_UNCHECKED)
					dw &= ~ FILE_ATTRIBUTE_HIDDEN;
				else
					dw |= FILE_ATTRIBUTE_HIDDEN;
				
				bOK = SetFileAttributes (pszFile, dw);
			}
			
			if (bOK)
			{
				if (uChecked == BST_UNCHECKED)
					dld->pMgr->GetDownloadMgr ()->GetDP ()->dwFlags &= ~ DPF_USEHIDDENATTRIB;
				else
					dld->pMgr->GetDownloadMgr ()->GetDP ()->dwFlags |= DPF_USEHIDDENATTRIB;
				dld->pMgr->GetDownloadMgr ()->setDirty();
			}
		}
	}
	
	uChecked = IsDlgButtonChecked (IDC_DONTRESTARTIFNORESUME);
	if (uChecked != BST_INDETERMINATE)
	{
		if (uChecked == BST_CHECKED)
			DP_SET_MASK (dwFlags, DPF_DONTRESTARTIFNORESUME);
		else
			DP_UNSET_MASK (dwFlags, DPF_DONTRESTARTIFNORESUME);
	}

	uChecked = IsDlgButtonChecked (IDC_APPENDCOMMENT);
	if (uChecked != BST_INDETERMINATE)
	{
		if (uChecked == BST_CHECKED)
			DP_SET_MASK (dwFlags, DPF_APPENDCOMMENTTOFILENAME);
		else
			DP_UNSET_MASK (dwFlags, DPF_APPENDCOMMENTTOFILENAME);
	}

	uChecked = IsDlgButtonChecked (IDC_RETRFILEDATE);
	if (uChecked != BST_INDETERMINATE)
	{
		if (uChecked == BST_CHECKED)
			DP_SET_MASK (dwFlags, DPF_RETRDATEFROMSERVER);
		else
			DP_UNSET_MASK (dwFlags, DPF_RETRDATEFROMSERVER);
	}

	uChecked = IsDlgButtonChecked (IDC_GENERATEINFOFILE);
	if (uChecked != BST_INDETERMINATE)
	{
		if (uChecked == BST_CHECKED)
			DP_SET_MASK (dwFlags, DPF_GENERATEDESCFILE);
		else
			DP_UNSET_MASK (dwFlags, DPF_GENERATEDESCFILE);
	}

	uChecked = IsDlgButtonChecked (IDC_LAUNCHWHENDONE);
	if (uChecked != BST_INDETERMINATE)
	{
		if (uChecked == BST_CHECKED)
			DP_SET_MASK (dwFlags, DPF_STARTWHENDONE);
		else
			DP_UNSET_MASK (dwFlags, DPF_STARTWHENDONE);
	}

	iCur = m_wndSCR.GetCurSel ();
	if (iCur != CB_ERR)
	{
		DP_SET (enSCR, FALSE, &iCur);
	}

	uChecked = IsDlgButtonChecked (IDC_FILENOTFOUND);
	if (uChecked != BST_INDETERMINATE)
	{
		fsDownloadFileErrorProcessing dfep = uChecked == BST_CHECKED ? DFEP_STOP : DFEP_IGNORE;
		DP_SET_EX (DP_OFFSET (aEP) + DFE_NOTFOUND * sizeof (dfep), sizeof (dfep), FALSE, &dfep);
	}

	uChecked = IsDlgButtonChecked (IDC_ACCDENIED);
	if (uChecked != BST_INDETERMINATE)
	{
		fsDownloadFileErrorProcessing dfep = uChecked == BST_CHECKED ? DFEP_STOP : DFEP_IGNORE;
		DP_SET_EX (DP_OFFSET (aEP) + DFE_ACCDENIED * sizeof (dfep), sizeof (dfep), FALSE, &dfep);
	}

	return CPropertyPage::OnApply();
}

void CDownloadProperties_MiscPage::OnContextMenu(CWnd* , CPoint point) 
{
	PrepareCHMgr (point);
	_CHMgr.ShowMenu ();
}

void CDownloadProperties_MiscPage::OnWhatisthis() 
{
	_CHMgr.OnWT ();	
}

void CDownloadProperties_MiscPage::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC__LOCALFILE, L_LOCALFILE),
		fsDlgLngInfo (IDC__IFEXISTS, L_IFEXISTS),
		fsDlgLngInfo (IDC_RESERVESPACE, L_RESERVESPACE),
		fsDlgLngInfo (IDC_USEEXT, L_ADDEXT),
		fsDlgLngInfo (IDC_APPENDCOMMENT, L_APPENDCOMMENT),
		fsDlgLngInfo (IDC_LAUNCHWHENDONE, L_LAUNCHWHENDONE),
		fsDlgLngInfo (IDC_USEHIDDENFLAG, L_USEHIDDENATTRIB),
		fsDlgLngInfo (IDC_USECREATEEXT, L_CREATEEXT),
		fsDlgLngInfo (IDC__INETSERV, L_INETSERV),
		fsDlgLngInfo (IDC_DONTRESTARTIFNORESUME, L_DONTRESTARTIFNORESUME),
		fsDlgLngInfo (IDC__IFSIZECHANGED, L_IFSIZECHANGED),
		fsDlgLngInfo (IDC__STOPONERRS, L_STOPONERRS),
		fsDlgLngInfo (IDC_RENAMEATRESTART, L_RENAMEATRESTARTALSO),
		fsDlgLngInfo (IDC_RETRFILEDATE, L_RETRDATEFROMSERVER),
		fsDlgLngInfo (IDC_GENERATEINFOFILE, L_GENERATEDESCFILE),
	};

	CString str = '"'; str += LS (L_FILENOTFOUND); str += '"';
	SetDlgItemText (IDC_FILENOTFOUND, str);
	str = '"'; str += LS (L_ACCDENIED); str += '"';
	SetDlgItemText (IDC_ACCDENIED, str);

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), 0);
}

BOOL CDownloadProperties_MiscPage::OnHelpInfo(HELPINFO* pHelpInfo) 
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

void CDownloadProperties_MiscPage::PrepareCHMgr(CPoint point)
{
	fsCtrlContextHelp aCH1 [] = {
		fsCtrlContextHelp (IDC__IFEXISTS, LS (L_IFEXISTSHERE)),
		fsCtrlContextHelp (IDC_AER, LS (L_IFEXISTSHERE)),
		fsCtrlContextHelp (IDC_RESERVESPACE, LS (L_RESERVESPACEHERE)),
		fsCtrlContextHelp (IDC_USEEXT, LS (L_ADDEXTHERE)),
		fsCtrlContextHelp (IDC_EXT, LS (L_ADDEXTHERE)),
		fsCtrlContextHelp (IDC_USECREATEEXT, LS (L_CREATEEXTHERE)),
		fsCtrlContextHelp (IDC_CREATEEXT, LS (L_CREATEEXTHERE)),
		fsCtrlContextHelp (IDC_DONTRESTARTIFNORESUME, LS (L_DONTRESTARTHERE)),
		fsCtrlContextHelp (IDC__IFSIZECHANGED, LS (L_IFSIZECHANGEDHERE)),
		fsCtrlContextHelp (IDC_SCR, LS (L_IFSIZECHANGEDHERE)),
		fsCtrlContextHelp (IDC_FILENOTFOUND, LS (L_FILENOTFOUNDHERE)),
		fsCtrlContextHelp (IDC_ACCDENIED, LS (L_ACCDENIEDHERE)),
		fsCtrlContextHelp (IDC_RETRFILEDATE, LS (L_RETRDATEFROMSERVER_HERE)),
		fsCtrlContextHelp (IDC_GENERATEINFOFILE, LS (L_GENERATEDESCFILE_HERE)),
	};

    static fsCtrlContextHelp aCH [sizeof (aCH1) / sizeof (fsCtrlContextHelp)];
	CopyMemory (aCH, aCH1, sizeof (aCH));

	_CHMgr.PrepareContextMenu (this, point, aCH, sizeof (aCH) / sizeof (fsCtrlContextHelp));	
}

void CDownloadProperties_MiscPage::OnUsecreateext() 
{
	if (IsDlgButtonChecked (IDC_USECREATEEXT) == BST_INDETERMINATE)
		CheckDlgButton (IDC_USECREATEEXT, BST_UNCHECKED);

	UpdateEnabled ();
	SetModified ();
	m_bCreateExtModified = TRUE;	
}

void CDownloadProperties_MiscPage::OnChangeCreateext() 
{
	SetModified ();
	m_bCreateExtModified = TRUE;
}

void CDownloadProperties_MiscPage::OnUsehiddenflag() 
{
	if (IsDlgButtonChecked (IDC_USEHIDDENFLAG) == BST_INDETERMINATE)
		CheckDlgButton (IDC_USEHIDDENFLAG, BST_UNCHECKED);
	
	SetModified ();	
}

void CDownloadProperties_MiscPage::OnAppendcomment() 
{
	if (IsDlgButtonChecked (IDC_APPENDCOMMENT) == BST_INDETERMINATE)
		CheckDlgButton (IDC_APPENDCOMMENT, BST_UNCHECKED);
	
	SetModified ();		
}

void CDownloadProperties_MiscPage::OnLaunchwhendone() 
{
	if (IsDlgButtonChecked (IDC_LAUNCHWHENDONE) == BST_INDETERMINATE)
		CheckDlgButton (IDC_LAUNCHWHENDONE, BST_UNCHECKED);
	
	SetModified ();		
}

void CDownloadProperties_MiscPage::OnRetrfiledate() 
{
	if (IsDlgButtonChecked (IDC_RETRFILEDATE) == BST_INDETERMINATE)
		CheckDlgButton (IDC_RETRFILEDATE, BST_UNCHECKED);
	
	SetModified ();	
}

void CDownloadProperties_MiscPage::OnGenerateinfofile() 
{
	if (IsDlgButtonChecked (IDC_GENERATEINFOFILE) == BST_INDETERMINATE)
		CheckDlgButton (IDC_GENERATEINFOFILE, BST_UNCHECKED);
	
	SetModified ();
}

void CDownloadProperties_MiscPage::OnRenameatrestart() 
{
	SetModified ();	
}
