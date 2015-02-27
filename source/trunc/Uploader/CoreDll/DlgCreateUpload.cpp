/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "coredll.h"
#include "DlgCreateUpload.h"
#include <AlsFolderBrowser.h>
#include "misc.h"

#define IDC_ADDFILES	40000
#define IDC_ADDFOLDER	40001

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDlgCreateUpload::CDlgCreateUpload(CWnd* pParent )
	: CDialog(CDlgCreateUpload::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgCreateUpload)
		
	//}}AFX_DATA_INIT
}

void CDlgCreateUpload::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgCreateUpload)
	DDX_Control(pDX, IDC_COMPRESS, m_wndCompress);
	DDX_Control(pDX, IDC_NUMBEROFDLDS, m_wndNumberOfDlds);
	DDX_Control(pDX, IDC_DAYSTOKEEP, m_wndDaysToKeep);
	DDX_Control(pDX, IDC_FILES, m_wndFiles);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlgCreateUpload, CDialog)
	//{{AFX_MSG_MAP(CDlgCreateUpload)
	ON_BN_CLICKED(IDC_SETPWD, OnSetpwd)
	ON_BN_CLICKED(IDC_ADVANCEDINFO, OnAdvancedinfo)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_ADDFILES, OnAddfiles)
	ON_BN_CLICKED(IDC_ADDFOLDER, OnAddfolder)
END_MESSAGE_MAP()

void CDlgCreateUpload::OnAddfiles() 
{
	CString str;
	str.Format ("%s (*.*)|*.*||", LS (L_ALLFILES));
	CFileDialog dlg (TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_ALLOWMULTISELECT | 
		OFN_NOCHANGEDIR, str);
	char sz [10000] = "";
	dlg.m_ofn.lpstrFile = sz;
	dlg.m_ofn.nMaxFile = sizeof (sz) - 1;
	dlg.m_ofn.lpstrTitle = LS (L_UPLOADFILES);
	if (IDOK != _DlgMgr.DoModal (&dlg))
		return;
	
	POSITION pos = dlg.GetStartPosition ();
	while (pos)
		m_wndFiles.InsertItem (m_wndFiles.GetItemCount (), dlg.GetNextPathName (pos));

	m_wndFiles.SetColumnWidth (0, LVSCW_AUTOSIZE);

	if (m_wndFiles.GetItemCount () > 1)
		GetDlgItem (IDC_PKGNAME)->EnableWindow (TRUE);
}

BOOL CDlgCreateUpload::OnInitDialog() 
{
	AFX_MANAGE_STATE (AfxGetStaticModuleState ());

	CDialog::OnInitDialog();
	
	m_wndFiles.InsertColumn (0, "");

	SetDlgItemText (IDC_PKGNAME, m_pkg.m_strName);

	if (m_pkg.m_vPathes.size ())
	{
		for (size_t i = 0; i < m_pkg.m_vPathes.size (); i++)
			m_wndFiles.InsertItem (i, m_pkg.m_vPathes [i]);

		m_wndFiles.SetColumnWidth (0, LVSCW_AUTOSIZE);
	}

	SetForegroundWindow ();
	BringWindowToTop ();

	SetWindowText (LS (L_UPLOADFILES));

	m_tbFiles.CreateEx (this, TBSTYLE_FLAT | TBSTYLE_TRANSPARENT | TBSTYLE_LIST, 
		WS_CHILD | WS_VISIBLE | CBRS_ALIGN_TOP | CBRS_SIZE_FIXED | CBRS_TOOLTIPS);
	
	CBitmap bmp; bmp.LoadBitmap (IDB_FILES);
	m_imgsFiles.Create (16, 16, ILC_COLOR24 | ILC_MASK, 2, 1);
	m_imgsFiles.Add (&bmp, RGB (255, 0, 255));
	m_tbFiles.GetToolBarCtrl ().SetImageList (&m_imgsFiles);
	UINT aIDs [] = {IDC_ADDFILES, IDC_ADDFOLDER};
	m_tbFiles.SetButtons (aIDs, sizeof (aIDs) / sizeof (UINT));
	
	TBBUTTONINFO tbbi;
	tbbi.cbSize = sizeof (tbbi);
	tbbi.dwMask = TBIF_TEXT;
	tbbi.pszText = (LPSTR) LS (L_ADDFILES);
	m_tbFiles.GetToolBarCtrl ().SetButtonInfo (IDC_ADDFILES, &tbbi);
	tbbi.pszText = (LPSTR) LS (L_ADDFOLDER);
	m_tbFiles.GetToolBarCtrl ().SetButtonInfo (IDC_ADDFOLDER, &tbbi);

	m_tbFiles.GetToolBarCtrl ().SetButtonWidth (70, 200);

	CRect rc;
	GetDlgItem (IDC__TB_FILES)->GetWindowRect (&rc);
	CRect rc2;
	m_tbFiles.GetItemRect (1, &rc2);
	ScreenToClient (&rc);
	rc.left = rc.right - rc2.right;
	rc.bottom = rc.top + rc2.bottom;
	m_tbFiles.MoveWindow (&rc);

	m_wndNumberOfDlds.AddString (LS (L_LESSTHAN10));
	m_wndNumberOfDlds.AddString (LS (L_FROM_10_TO_100));
	m_wndNumberOfDlds.AddString (LS (L_MORE_THAN_100));
	m_wndNumberOfDlds.SetCurSel (0);

	m_wndDaysToKeep.AddString (LS (L_2DAYS));
	m_wndDaysToKeep.AddString (LS (L_7DAYS));
	m_wndDaysToKeep.AddString (LS (L_1MONTH));
	m_wndDaysToKeep.SetCurSel (0);

	m_wndCompress.AddString (LS (L_NONE));
	m_wndCompress.AddString (LS (L_FAST));
	m_wndCompress.AddString (LS (L_AVERAGE2));
	m_wndCompress.AddString (LS (L_BEST));
	m_wndCompress.SetItemData (0, 0);
	m_wndCompress.SetItemData (1, 2);
	m_wndCompress.SetItemData (2, 6);
	m_wndCompress.SetItemData (3, 9);
	m_wndCompress.SetCurSel (0);

	InitializeTerms ();

	UpdateEnabled ();

	ApplyLanguage ();

	
	
	return TRUE;
}

void CDlgCreateUpload::OnAddfolder() 
{
	AlsFolderBrowser fb;
	if (!fb.Create ("", "", NULL, m_hWnd))
		return;

	m_wndFiles.InsertItem (m_wndFiles.GetItemCount (), fb.GetPath ());

	m_wndFiles.SetColumnWidth (0, LVSCW_AUTOSIZE);

	GetDlgItem (IDC_PKGNAME)->EnableWindow (TRUE);
}

void CDlgCreateUpload::OnOK() 
{
	if (m_wndFiles.GetItemCount () == 0)
	{
		MessageBox (LS (L_SPECIFYFILESTOUPLOAD), LS (L_INPERR), MB_ICONEXCLAMATION);
		return;
	}

	if (IsDlgButtonChecked (IDC_AGREE) == BST_UNCHECKED)
	{
		_pDllCaller->GetPersist ()->WriteProfileInt ("Settings\\View", "UplCreate_Agree", FALSE);
		MessageBox (LS (L_YOUSHOULDAGREETOTERMS), LS (L_INPERR), MB_ICONEXCLAMATION);
		return;
	}

	_pDllCaller->GetPersist ()->WriteProfileInt ("Settings\\View", "UplCreate_Agree", TRUE);

	m_pkg.m_vPathes.clear ();
	int i = 0;
	for (i = 0; i < m_wndFiles.GetItemCount (); i++)
		m_pkg.add (m_wndFiles.GetItemText (i, 0));

	CString str;
	GetDlgItemText (IDC_PKGNAME, str);
	if (str.GetLength () > 300)
	{
		GetDlgItem (IDC_PKGNAME)->SetFocus ();
		MessageBox (LS (L_TOOLONGINPUT), LS (L_INPERR), MB_ICONEXCLAMATION);
		return;
	}

	if (str.IsEmpty ())
	{
		str = m_wndFiles.GetItemText (0, 0);
		if (str [str.GetLength () - 1] == '\\')
			str.Delete (str.GetLength () - 1);
		char sz [MAX_PATH] = "";
		fsGetFileName (str, sz);
		if (*sz != 0)
			str = sz;
	}

	m_pkg.set_name (str);

	i = m_wndNumberOfDlds.GetCurSel ();
	if (i == 0)
		m_pkg.set_supposedNumberOfDownloads (9);
	else if (i == 1)
		m_pkg.set_supposedNumberOfDownloads (100);
	else
		m_pkg.set_supposedNumberOfDownloads (0);

	i = m_wndDaysToKeep.GetCurSel ();
	if (i == 0)
		m_pkg.set_numberOfDaysToKeepThisUpload (2);
	else if (i == 1)
		m_pkg.set_numberOfDaysToKeepThisUpload (7);
	else
		m_pkg.set_numberOfDaysToKeepThisUpload (31);

	if (IsDlgButtonChecked (IDC_SETPWD) == BST_CHECKED)
	{
		CString strP1, strP2;
		GetDlgItemText (IDC_PWD, strP1);
		GetDlgItemText (IDC_PWD_R, strP2);
		if (strP1 != strP2)
		{
			GetDlgItem (IDC_PWD)->SetFocus ();
			MessageBox (LS (L_MISTAKEINPWD_NEEDRETYPE), LS (L_INPERR), MB_ICONEXCLAMATION);
			return;
		}
		if (strP1.GetLength () > 32)
		{
			GetDlgItem (IDC_PWD)->SetFocus ();
			MessageBox (LS (L_TOOLONGINPUT), LS (L_INPERR), MB_ICONEXCLAMATION);
			return;
		}		
		m_pkg.set_passwordForDownload (strP1);
	}
	else
		m_pkg.set_passwordForDownload ("");

	m_pkg.set_addLinkToUploadInCatalogue (IsDlgButtonChecked (IDC_PLACETOCAT) == BST_CHECKED);

	m_pkg.m_iZipCompressMethod = m_wndCompress.GetItemData (m_wndCompress.GetCurSel ());

	if (IsDlgButtonChecked (IDC_ADVANCEDINFO) == BST_CHECKED)
	{
		CString str;
		
		GetDlgItemText (IDC_DESC, str);
		if (str.GetLength () > 1024)
		{
			GetDlgItem (IDC_DESC)->SetFocus ();
			MessageBox (LS (L_TOOLONGINPUT), LS (L_INPERR), MB_ICONEXCLAMATION);
			return;
		}
		m_pkg.set_Description (str);

		GetDlgItemText (IDC_TAGS, str);
		if (str.GetLength () > 512)
		{
			GetDlgItem (IDC_TAGS)->SetFocus ();
			MessageBox (LS (L_TOOLONGINPUT), LS (L_INPERR), MB_ICONEXCLAMATION);
			return;
		}
		m_pkg.set_Tags (str);

		GetDlgItemText (IDC_SNDRNAME, str);
		if (str.GetLength () > 512)
		{
			GetDlgItem (IDC_SNDRNAME)->SetFocus ();
			MessageBox (LS (L_TOOLONGINPUT), LS (L_INPERR), MB_ICONEXCLAMATION);
			return;
		}
		m_pkg.set_OwnerName (str);

		GetDlgItemText (IDC_SNDREMAIL, str);
		if (str.GetLength () > 64)
		{
			GetDlgItem (IDC_SNDREMAIL)->SetFocus ();
			MessageBox (LS (L_TOOLONGINPUT), LS (L_INPERR), MB_ICONEXCLAMATION);
			return;
		}
		m_pkg.set_OwnerEmail (str);

		GetDlgItemText (IDC_RCVREMAIL, str);
		if (str.GetLength () > 64)
		{
			GetDlgItem (IDC_RCVREMAIL)->SetFocus ();
			MessageBox (LS (L_TOOLONGINPUT), LS (L_INPERR), MB_ICONEXCLAMATION);
			return;
		}
		m_pkg.set_RecipientEmail (str);
	}
	
	CDialog::OnOK();
}

BOOL CDlgCreateUpload::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult) 
{
	NMHDR* pNMHDR = (NMHDR*)lParam;
	HWND hWndCtrl = pNMHDR->hwndFrom;

	if (hWndCtrl == m_tbFiles.m_hWnd)
	{
		switch (pNMHDR->code)
		{
		case TBN_GETINFOTIPA:
			int nID = ((LPNMTBGETINFOTIPA) pNMHDR)->iItem;
			LPNMTBGETINFOTIPA inf = (LPNMTBGETINFOTIPA) pNMHDR;
			strcpy (inf->pszText, nID == IDC_ADDFILES ? LS (L_ADDFILES) : LS (L_ADDFOLDER));
			return TRUE;
		}
	}
	
	return CDialog::OnNotify(wParam, lParam, pResult);
}

void CDlgCreateUpload::OnSetpwd() 
{
	UpdateEnabled ();	
}

void CDlgCreateUpload::UpdateEnabled()
{
	BOOL b = IsDlgButtonChecked (IDC_SETPWD) == BST_CHECKED;
	GetDlgItem (IDC_PWD)->EnableWindow (b);
	GetDlgItem (IDC_PWD_R)->EnableWindow (b);
	GetDlgItem (IDC__PWD)->EnableWindow (b);
	GetDlgItem (IDC__PWD_R)->EnableWindow (b);

	b = IsDlgButtonChecked (IDC_ADVANCEDINFO) == BST_CHECKED;
	GetDlgItem (IDC__SNDRNAME)->EnableWindow (b);
	GetDlgItem (IDC_SNDRNAME)->EnableWindow (b);
	GetDlgItem (IDC__SNDREMAIL)->EnableWindow (b);
	GetDlgItem (IDC_SNDREMAIL)->EnableWindow (b);
	GetDlgItem (IDC__RCVREMAIL)->EnableWindow (b);
	GetDlgItem (IDC_RCVREMAIL)->EnableWindow (b);
	GetDlgItem (IDC__DESC)->EnableWindow (b);
	GetDlgItem (IDC_DESC)->EnableWindow (b);
	GetDlgItem (IDC__TAGS)->EnableWindow (b);
	GetDlgItem (IDC_TAGS)->EnableWindow (b);
}

void CDlgCreateUpload::OnAdvancedinfo() 
{
	UpdateEnabled ();	
}

void CDlgCreateUpload::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC__FILESTOUPLOAD, L_FILESTOUPLOAD, TRUE),
		fsDlgLngInfo (IDC__PKGNAME, L_PKGNAME, TRUE),
		fsDlgLngInfo (IDC__COMPRESS, L_COMPRESS, TRUE),
		fsDlgLngInfo (IDC_SETPWD, L_SETPWDFORTHISDLD),
		fsDlgLngInfo (IDC__PWD, L_PASSWORD),
		fsDlgLngInfo (IDC__PWD_R, L_RETYPE, TRUE),
		fsDlgLngInfo (IDC__KEEPTHESEFILES, L_KEEPTHESEFILES, TRUE),
		fsDlgLngInfo (IDC__SUPPOSEDNUMBEROFDLDS, L_SUPPOSEDNUMBEROFDLDS, TRUE),
		fsDlgLngInfo (IDC_PLACETOCAT, L_ADDLINKINOURCAT),
		fsDlgLngInfo (IDC_ADVANCEDINFO, L_INCADVINFO),
		fsDlgLngInfo (IDC__DESC, L_DESCRIPTION, TRUE),
		fsDlgLngInfo (IDC__TAGS, L_TAGS, TRUE),
		fsDlgLngInfo (IDC__SNDRNAME, L_YOURNAME, TRUE),
		fsDlgLngInfo (IDC__SNDREMAIL, L_YOUREMAIL, TRUE),
		fsDlgLngInfo (IDC__RCVREMAIL, L_RCVREMAIL, TRUE),
		fsDlgLngInfo (IDC_AGREE, L_I_AGREE_TO),
		fsDlgLngInfo (IDC__TERMS, L_TERMS),
		fsDlgLngInfo (IDCANCEL, L_CANCEL),
	};

	vmsMfcLngHelper::ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), L_UPLOADFILES);
}

void CDlgCreateUpload::InitializeTerms()
{
	CDC* dc = GetDC ();
	CFont* fnt = GetFont ();
	dc->SelectObject (fnt);

	LOGFONT lf;
	fnt->GetLogFont (&lf);
	lf.lfUnderline = TRUE;
	m_fntUnderline.CreateFontIndirect (&lf);

	CRect rc;
	CString str = "XXX"; str += LS (L_I_AGREE_TO);
	dc->DrawText (str, &rc, DT_CALCRECT);

	int w = rc.Width ();

	GetDlgItem (IDC_AGREE)->GetWindowRect (&rc);
	GetDlgItem (IDC_AGREE)->SetWindowPos (NULL, 0, 0, w, rc.Height (), SWP_NOZORDER |
		SWP_NOMOVE);

	GetDlgItem (IDC_AGREE)->GetWindowRect (&rc);

	CRect rc2;
	GetDlgItem (IDOK)->GetWindowRect (&rc2);

	int wTerms = rc2.left - rc.right - 2*3;

	ScreenToClient (&rc);
	int xTerms = rc.right + 3;

	GetDlgItem (IDC__TERMS)->GetWindowRect (&rc);
	ScreenToClient (&rc);
	int yTerms = rc.top;

	dc->DrawText (LS (L_TERMS), &rc2, DT_CALCRECT);

	wTerms = min (wTerms, rc2.Width () + 3);

	GetDlgItem (IDC__TERMS)->SetWindowPos (NULL, xTerms, yTerms, wTerms, rc.Height (),
		SWP_NOZORDER);

	m_wndTerms.SubclassDlgItem (IDC__TERMS, this);
	m_wndTerms.Init ();
	m_wndTerms.SetUrl ("http://wikifortio.com/terms.jsp");

	if (_pDllCaller->GetPersist ()->GetProfileInt ("Settings\\View", "UplCreate_Agree", FALSE))
		CheckDlgButton (IDC_AGREE, BST_CHECKED);
}

HBRUSH CDlgCreateUpload::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	if (pWnd->m_hWnd == m_wndTerms.m_hWnd)
	{
		pDC->SetTextColor (GetSysColor (COLOR_HOTLIGHT));
		pDC->SelectObject (&m_fntUnderline);
	}

	return hbr;
}
