/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "ZipPreviewDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace fsArchive;

CZipPreviewDlg::CZipPreviewDlg(CWnd* pParent )
	: CDialog(CZipPreviewDlg::IDD, pParent)
{
	m_ar = NULL;
	m_tFiles.CreateInstance ();
}

void CZipPreviewDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CZipPreviewDlg)
	DDX_Control(pDX, IDC_FILES, m_wndFiles);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CZipPreviewDlg, CDialog)
	//{{AFX_MSG_MAP(CZipPreviewDlg)
	ON_BN_CLICKED(IDC_CHECKUNCHECKALL, OnCheckuncheckall)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CZipPreviewDlg::OnOK() 
{
	if (FALSE == ApplyTreeChecks ())
	{
		MessageBox (LS (L_SELECTATLEAST1FILE), LS (L_INPERR), MB_ICONEXCLAMATION);
		return;
	}
	
	CDialog::OnOK();
}

BOOL CZipPreviewDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	CBitmap bmp; bmp.Attach (SBMP (IDB_CHECKS));
	BITMAP bm; bmp.GetBitmap (&bm);
	m_checks.Create (15, bm.bmHeight, ILC_COLOR24|ILC_MASK, 3, 1);
	m_checks.Add (&bmp, RGB (255, 0, 255));
	m_wndFiles.SetImageList (&m_checks, TVSIL_STATE);

	BuildTreeOfFiles ();
	TreeToDlg (TVI_ROOT, m_tFiles);

	ApplyLanguage ();
	
	return TRUE;  
	              
}

void CZipPreviewDlg::BuildTreeOfFiles()
{
	for (int i = 0; i < m_ar->GetFileCount (); i++)
		AddToTree (m_ar->GetFileName (i), i, m_tFiles);
}

void CZipPreviewDlg::AddToTree(LPCSTR pszFile, int iIndex, fs::ListTree <fsFile>* root)
{
	LPCSTR pszNextDir = strpbrk (pszFile, "/\\");

	if (pszNextDir)
		pszNextDir++;

	fsString strFileToAdd;

	fsFile file;

	if (pszNextDir == NULL || *pszNextDir == 0)
	{
		strFileToAdd = pszFile; 
		if (pszNextDir)
			strFileToAdd [strFileToAdd.Length ()-1] = 0; 

		for (int i = 0; i < root->GetLeafCount (); i++)
		{
			if (root->GetLeaf (i)->GetData ().strName == strFileToAdd)
			{
				root->GetLeaf (i)->GetData ().iIndex = iIndex;
				return;
			}
		}

		file.strName = strFileToAdd;
		file.iIndex = iIndex;
		root->AddLeaf (file);

		return;
	}
	
	fsString str1stDir;	
	str1stDir.ncpy (pszFile, pszNextDir-pszFile-1);

	
	for (int i = 0; i < root->GetLeafCount (); i++)
	{
		if (root->GetLeaf (i)->GetData ().strName == str1stDir)
		{
			
			AddToTree (pszNextDir, iIndex, root->GetLeaf (i));
			return;
		}
	}

	file.iIndex = -1;
	file.strName = str1stDir;
	fs::ListTree <fsFile>* t = root->AddLeaf (file);

	AddToTree (pszNextDir, iIndex, t);
}

void CZipPreviewDlg::TreeToDlg(HTREEITEM hRoot, fs::ListTree <fsFile>* root)
{
	for (int i = 0; i < root->GetLeafCount (); i++)
	{
		fs::ListTree <fsFile>* t = root->GetLeaf (i);

		HTREEITEM ht = m_wndFiles.InsertItem (t->GetData ().strName, hRoot, TVI_LAST);
		m_wndFiles.SetItemData (ht, t->GetData ().iIndex);
		m_wndFiles.SetCheck (ht, TRUE);

		TreeToDlg (ht, t);
	}
}

BOOL CZipPreviewDlg::ApplyTreeChecks()
{
	fs::list <int> vFiles;
	ApplyTreeChecks (TVI_ROOT, vFiles);

	if (vFiles.size () == 0)
		return FALSE;

	fs::list <fsString> vstrFiles;

	for (int i = 0; i < vFiles.size (); i++)
		vstrFiles.add (m_ar->GetFileName (vFiles [i]));

	m_ar->RebuildArchive (vstrFiles);

	return TRUE;
}

void CZipPreviewDlg::ApplyTreeChecks(HTREEITEM hRoot, fs::list <int> &vFiles)
{
	if (hRoot != TVI_ROOT)
	{
		if (m_wndFiles.IsChecked (hRoot) == FALSE)
			return;

		int iIndex = m_wndFiles.GetItemData (hRoot);
		if (iIndex != -1)
			vFiles.add (iIndex);
	}

	HTREEITEM hChild = m_wndFiles.GetChildItem (hRoot);

	while (hChild)
	{
		ApplyTreeChecks (hChild, vFiles);
		hChild = m_wndFiles.GetNextItem (hChild, TVGN_NEXT);
	}
}

void CZipPreviewDlg::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC__MSG, L_CHECKFILESTODL),
		fsDlgLngInfo (IDC_CHECKUNCHECKALL, L_CHECKUNCHECKALL),
		fsDlgLngInfo (IDCANCEL, L_CANCEL),
	};

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), L_ZIPPREVIEW);
}

void CZipPreviewDlg::OnCheckuncheckall() 
{
	BOOL bChecked = m_wndFiles.IsChecked (m_wndFiles.GetChildItem (TVI_ROOT));	
	CheckAllItems (TVI_ROOT, !bChecked);
}

void CZipPreviewDlg::CheckAllItems(HTREEITEM hRoot, BOOL bCheck)
{
	if (hRoot != TVI_ROOT)
		m_wndFiles.SetCheck (hRoot, bCheck);

	HTREEITEM hChild = m_wndFiles.GetChildItem (hRoot);

	while (hChild)
	{
		CheckAllItems (hChild, bCheck);
		hChild = m_wndFiles.GetNextItem (hChild, TVGN_NEXT);
	}
}

