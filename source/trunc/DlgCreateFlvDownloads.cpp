/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "fdm.h"
#include "DlgCreateFlvDownloads.h"
#include "mfchelp.h"
#include "CreateDownloadDlg.h"
#include "FdmUiWindow.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDlgCreateFlvDownloads::CDlgCreateFlvDownloads(CWnd* pParent , CFdmUiWindow *pUiWindow)
	: CDialog(CDlgCreateFlvDownloads::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgCreateFlvDownloads)
		
	//}}AFX_DATA_INIT

	m_bUseAutoConvert = false;
	m_bReqTopMostDialog = false;
	m_pUiWindow = pUiWindow;
}

void CDlgCreateFlvDownloads::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgCreateFlvDownloads)
	DDX_Control(pDX, IDC_FLVLIST, m_wndFlvList);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlgCreateFlvDownloads, CDialog)
	//{{AFX_MSG_MAP(CDlgCreateFlvDownloads)
	ON_BN_CLICKED(IDC_USE_AUTO_CONVERT, OnUseAutoConvert)
	ON_BN_CLICKED(IDC_CNVRT_SETTINGS, OnCnvrtSettings)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDlgCreateFlvDownloads::OnInitDialog() 
{
	CDialog::OnInitDialog();

	if (m_pUiWindow)
		m_pUiWindow->setWindow (m_hWnd);
	
	SetDlgItemText (IDC_WPURL, m_strWebPageUrl);

	CRect rc; m_wndFlvList.GetClientRect (&rc);

	m_wndFlvList.InsertColumn (0, LS (L_TITLE), LVCFMT_LEFT);
	m_wndFlvList.InsertColumn (1, LS (L_SIZE), LVCFMT_LEFT);
	m_wndFlvList.InsertColumn (2, "URL", LVCFMT_LEFT);

	int nMaxW0 = 0;
	int nMaxW1 = 0;

	size_t i = 0;
	for (i = 0; i < m_vDlds.size (); i++)
	{
		m_wndFlvList.InsertItem (i, m_vDlds [i].strTitle);
		int nW0 = m_wndFlvList.GetStringWidth (m_vDlds [i].strTitle);
		CString strSize; 
		if (m_vDlds [i].uSize != _UI64_MAX)
			strSize = BytesToString (m_vDlds [i].uSize, true);
		int nW1 = m_wndFlvList.GetStringWidth (strSize);
		m_wndFlvList.SetItemText (i, 1, strSize);
		m_wndFlvList.SetItemText (i, 2, m_vDlds [i].strUrl);
		nMaxW0 = max (nMaxW0, nW0);
		nMaxW1 = max (nMaxW1, nW1);
	}
	
	int n = rc.Width () / 3;
	if (n > nMaxW0)
		n = nMaxW0;
	m_wndFlvList.SetColumnWidth (0, n+20);
	m_wndFlvList.SetColumnWidth (1, nMaxW1+20);
	m_wndFlvList.SetColumnWidth (2, rc.Width () - n-20 - nMaxW1-20 - GetSystemMetrics (SM_CXVSCROLL) - 3);
	m_wndFlvList.SetExtendedStyle (LVS_EX_FULLROWSELECT | LVS_EX_INFOTIP | LVS_EX_CHECKBOXES);

	if (m_vbDldSelected.size () != m_vDlds.size ())
	{
		m_vbDldSelected.clear ();
		for (i = 0; i < m_vDlds.size (); i++)
			m_vbDldSelected.push_back (true);
	}

	
	for (i = 0; i < m_vDlds.size (); i++)
		ListView_SetItemState (m_wndFlvList, i, UINT((int(m_vbDldSelected [i]) + 1) << 12), LVIS_STATEIMAGEMASK);

	CComboBox *pDirs = (CComboBox*) GetDlgItem (IDC_OUTFOLDER);
	for (i = 0; i < (size_t)_LastFlashVideoDstFolders.GetRecordCount (); i++)
		pDirs->AddString (_LastFlashVideoDstFolders.GetRecord (i));
	if (_LastFlashVideoDstFolders.GetRecordCount ())
	{
		pDirs->SetCurSel (0);
	}
	else
	{
		vmsDownloadsGroupSmartPtr pGrp = _DldsGrps.FindGroupByExt ("flv");
		if (pGrp == NULL)
			pGrp = _DldsGrps.FindGroupByExt ("mp4");
		if (pGrp == NULL)
			pGrp = _DldsGrps.FindGroupByExt ("avi");
		if (pGrp == NULL)
			pGrp = _DldsGrps.FindGroup (GRP_OTHER_ID);
		ASSERT (pGrp != NULL);
		if (pGrp != NULL)
			pDirs->SetWindowText (pGrp->strOutFolder);
	}

	if (_App.FVDownloads_AutoConvertVideo () && _AppMgr.IsMediaFeaturesInstalled ())
	{
		CheckDlgButton (IDC_USE_AUTO_CONVERT, BST_CHECKED);
		UpdateEnabled ();
	}
	
	vmsMediaConvertMgr::GetDefaultSettings (m_convertSettings);

	ApplyLanguage ();

	if (m_bReqTopMostDialog)
	{
		mfcSetForegroundWindow (this);
		mfcSetTopmostWindow (this);
	}
	
	return TRUE;  
	              
}

void CDlgCreateFlvDownloads::OnOK() 
{
	for (size_t i = 0; i < m_vDlds.size (); i++)
	{
		UINT uState = m_wndFlvList.GetItemState (i, LVIS_STATEIMAGEMASK);
		m_vbDldSelected [i] = ((uState >> 12) - 1) != 0;
	}

	if (FALSE == CCreateDownloadDlg::_CheckFolderName (this, IDC_OUTFOLDER))
		return;
	GetDlgItemText (IDC_OUTFOLDER, m_strDstFolder);

	fsPathToGoodPath ((LPSTR)(LPCSTR)m_strDstFolder);
	if (m_strDstFolder.GetLength () == 0)
	{
		MessageBox (LS (L_ENTERFLRNAME), LS (L_INPERR), MB_ICONEXCLAMATION);
		GetDlgItem (IDC_OUTFOLDER)->SetFocus ();
		return;
	}
	_LastFlashVideoDstFolders.AddRecord (m_strDstFolder);

	if (m_strDstFolder [m_strDstFolder.GetLength () - 1] != '\\' && 
			m_strDstFolder [m_strDstFolder.GetLength () - 1] != '/')
		m_strDstFolder += '\\';

	m_bUseAutoConvert = IsDlgButtonChecked (IDC_USE_AUTO_CONVERT) == BST_CHECKED;
	
	CDialog::OnOK();
}

void CDlgCreateFlvDownloads::UpdateEnabled()
{
	GetDlgItem (IDC_CNVRT_SETTINGS)->EnableWindow (
		IsDlgButtonChecked (IDC_USE_AUTO_CONVERT) == BST_CHECKED);
}

void CDlgCreateFlvDownloads::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC__WEBPAGE, L_WEBPAGE, TRUE),
		fsDlgLngInfo (IDC__FLVONTHISPAGE, L_FLVFOUNDONTHISPAGE, TRUE),
		fsDlgLngInfo (IDC__SAVETO, L_SAVETO),
		fsDlgLngInfo (IDC_USE_AUTO_CONVERT, L_USE_AUTO_CONVERT),
		fsDlgLngInfo (IDC_CNVRT_SETTINGS, L_CUSTOMIZE),
		fsDlgLngInfo (IDCANCEL, L_CANCEL),
	};
	
	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), L_CREATEFVDLD);
}

void CDlgCreateFlvDownloads::OnUseAutoConvert() 
{
	UpdateEnabled ();	
}

void CDlgCreateFlvDownloads::OnCnvrtSettings() 
{
	vmsMediaConvertMgr::ShowSettingsUI (m_convertSettings);	
}

