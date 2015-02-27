/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "DownloaderProperties_MirrorsPage.h"
#include "DownloadsWnd.h"
#include "vmsDialogHelper.h"

extern CDownloadsWnd* _pwndDownloads;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNCREATE(CDownloaderProperties_MirrorsPage, CPropertyPage)

CDownloaderProperties_MirrorsPage::CDownloaderProperties_MirrorsPage() : CPropertyPage(CDownloaderProperties_MirrorsPage::IDD)
{
	m_psp.dwFlags |= PSP_USETITLE;
	m_psp.pszTitle = LS (L_MIRRORS);
}

CDownloaderProperties_MirrorsPage::~CDownloaderProperties_MirrorsPage()
{
}

void CDownloaderProperties_MirrorsPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDownloaderProperties_MirrorsPage)
	DDX_Control(pDX, IDC_MIRRSERVERS, m_wndMirrServers);
	DDX_Control(pDX, IDC_FILEMINSIZEDIM, m_wndMinSizeDim);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDownloaderProperties_MirrorsPage, CPropertyPage)
	//{{AFX_MSG_MAP(CDownloaderProperties_MirrorsPage)
	ON_WM_CONTEXTMENU()
	ON_WM_HELPINFO()
	ON_COMMAND(ID_WHATISTHIS, OnWhatisthis)
	ON_BN_CLICKED(IDC_AUTO, OnAuto)
	ON_BN_CLICKED(IDC_MAXMIRRORS, OnMaxmirrors)
	ON_EN_CHANGE(IDC_MAXMIRRORSVAL, OnChangeMaxmirrorsval)
	ON_BN_CLICKED(IDC_CALCSPEED, OnCalcspeed)
	ON_BN_CLICKED(IDC_RECALCSPEED, OnRecalcspeed)
	ON_EN_CHANGE(IDC_RECALCVAL, OnChangeRecalcval)
	ON_EN_CHANGE(IDC_FILEMINSIZE, OnChangeFileminsize)
	ON_CBN_SELCHANGE(IDC_FILEMINSIZEDIM, OnSelchangeFileminsizedim)
	ON_CBN_SELCHANGE(IDC_MIRRSERVERS, OnSelchangeMirrservers)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDownloaderProperties_MirrorsPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();

	UINT anIDs [] = {
		IDC_MAXMIRRORSSPIN, IDC_RECALCSPIN
	};

	for (int i = 0; i < sizeof (anIDs) / sizeof (UINT); i++)
	{
		CSpinButtonCtrl *p = (CSpinButtonCtrl*) GetDlgItem (anIDs [i]);
		p->SetRange (1, UD_MAXVAL);
	}

	m_wndMinSizeDim.AddString (LS (L_B)); 
	m_wndMinSizeDim.AddString (LS (L_KB)); 
	m_wndMinSizeDim.AddString (LS (L_MB));

	CheckDlgButton (IDC_AUTO, _App.Mirr_AutoSearch () ? BST_CHECKED : BST_UNCHECKED);
	if (_App.Mirr_MaxCount () != UINT_MAX)
	{
		CheckDlgButton (IDC_MAXMIRRORS, BST_CHECKED);
		SetDlgItemInt (IDC_MAXMIRRORSVAL, _App.Mirr_MaxCount (), FALSE);
	}
	else
		SetDlgItemInt (IDC_MAXMIRRORSVAL, 10, FALSE);

	CheckDlgButton (IDC_CALCSPEED, _App.Mirr_CalcSpeed () ? BST_CHECKED : BST_UNCHECKED);

	if (_App.Mirr_RecalcSpeedTime ())
	{
		CheckDlgButton (IDC_RECALCSPEED, BST_CHECKED);
		SetDlgItemInt (IDC_RECALCVAL, _App.Mirr_RecalcSpeedTime (), FALSE);
	}
	else
		SetDlgItemInt (IDC_RECALCVAL, 60, FALSE);

	vmsDialogHelper::SetDlgBytesGroup (this, _App.Mirr_FileMinSize (), IDC_FILEMINSIZE, IDC_FILEMINSIZEDIM);

	CheckDlgButton (IDC_DONTIFSIZEUNK, _App.Mirr_DontSearchIfSizeUnk () ? BST_CHECKED : BST_UNCHECKED);

	m_wndMirrServers.AddString ("FileSearching.com");
	m_wndMirrServers.AddString ("FindFiles.com");
	m_wndMirrServers.SetCurSel (_App.Mirr_Server ());
	
	ApplyLanguage ();
	UpdateEnabled ();
	
	return TRUE;  
	              
}

void CDownloaderProperties_MirrorsPage::OnContextMenu(CWnd* , CPoint point) 
{
	PrepareCHMgr (point);
	_CHMgr.ShowMenu ();	
}

BOOL CDownloaderProperties_MirrorsPage::OnHelpInfo(HELPINFO* pHelpInfo) 
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

void CDownloaderProperties_MirrorsPage::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC_AUTO, L_MIRR_AUTOSEARCH),
		fsDlgLngInfo (IDC_MAXMIRRORS, L_MIRR_MAXNUMBER),
		fsDlgLngInfo (IDC_CALCSPEED, L_MIRR_CALCSPEED),
		fsDlgLngInfo (IDC_RECALCSPEED, L_MIRR_RECALCSPEEDEACH),
		fsDlgLngInfo (IDC__MIN, L_MIN),
		fsDlgLngInfo (IDC__DONTSEARCH, L_MIRR_DONTSEARCH),
		fsDlgLngInfo (IDC_DONTIFSIZEUNK, L_MIRR_DONTIFSIZEUNK),
		fsDlgLngInfo (IDC__MIRRSERVER, L_MIRRSERVER),
	};

	_LngMgr.ApplyLanguage (	this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), 0);
}

void CDownloaderProperties_MirrorsPage::PrepareCHMgr(CPoint point)
{
	fsCtrlContextHelp aCH1 [] = {
		fsCtrlContextHelp (IDC_AUTO, LS (L_MIRR_AUTOHERE)),
		fsCtrlContextHelp (IDC_MAXMIRRORS, LS (L_MIRR_MAXMIRRORSHERE)),
		fsCtrlContextHelp (IDC_MAXMIRRORSVAL, LS (L_MIRR_MAXMIRRORSHERE)),
		fsCtrlContextHelp (IDC_CALCSPEED, LS (L_MIRR_CALCSPEEDHERE)),
		fsCtrlContextHelp (IDC_RECALCSPEED, LS (L_MIRR_RECALCSPEEDHERE)),
		fsCtrlContextHelp (IDC_RECALCVAL, LS (L_MIRR_RECALCSPEEDHERE)),
		fsCtrlContextHelp (IDC__DONTSEARCH, LS (L_MIRR_DONTSEARCHHERE)),
		fsCtrlContextHelp (IDC_FILEMINSIZE, LS (L_MIRR_DONTSEARCHHERE)),
		fsCtrlContextHelp (IDC_FILEMINSIZEDIM, LS (L_DIMHERE)),
	};

	static fsCtrlContextHelp aCH [sizeof (aCH1) / sizeof (fsCtrlContextHelp)];
	CopyMemory (aCH, aCH1, sizeof (aCH));

	_CHMgr.PrepareContextMenu (this, point, aCH, sizeof (aCH) / sizeof (fsCtrlContextHelp));	
}

void CDownloaderProperties_MirrorsPage::OnWhatisthis() 
{
	_CHMgr.OnWT ();	
}

void CDownloaderProperties_MirrorsPage::UpdateEnabled()
{
	BOOL b = IsDlgButtonChecked (IDC_AUTO);
	GetDlgItem (IDC__DONTSEARCH)->EnableWindow (b);
	GetDlgItem (IDC_FILEMINSIZE)->EnableWindow (b);
	GetDlgItem (IDC_FILEMINSIZEDIM)->EnableWindow (b);
	GetDlgItem (IDC_DONTIFSIZEUNK)->EnableWindow (b);

	b = IsDlgButtonChecked (IDC_CALCSPEED) == BST_CHECKED;
	GetDlgItem (IDC_RECALCSPEED)->EnableWindow (b);
	b = b && IsDlgButtonChecked (IDC_RECALCSPEED) == BST_CHECKED;
	GetDlgItem (IDC_RECALCVAL)->EnableWindow (b);
	GetDlgItem (IDC_RECALCSPIN)->EnableWindow (b);
	GetDlgItem (IDC__MIN)->EnableWindow (b);

	b = IsDlgButtonChecked (IDC_MAXMIRRORS) == BST_CHECKED;
	GetDlgItem (IDC_MAXMIRRORSVAL)->EnableWindow (b);
	GetDlgItem (IDC_MAXMIRRORSSPIN)->EnableWindow (b);
}

void CDownloaderProperties_MirrorsPage::OnAuto() 
{
	UpdateEnabled ();
	SetModified ();
}

void CDownloaderProperties_MirrorsPage::OnMaxmirrors() 
{
	UpdateEnabled ();
	SetModified ();	
}

void CDownloaderProperties_MirrorsPage::OnChangeMaxmirrorsval() 
{
	SetModified ();
}

void CDownloaderProperties_MirrorsPage::OnCalcspeed() 
{
	UpdateEnabled ();
	SetModified ();
}

void CDownloaderProperties_MirrorsPage::OnRecalcspeed() 
{
	UpdateEnabled ();
	SetModified ();	
}

void CDownloaderProperties_MirrorsPage::OnChangeRecalcval() 
{
	SetModified ();
}

BOOL CDownloaderProperties_MirrorsPage::OnApply() 
{
	UINT nID; 
	BOOL b;

	UINT u;
	UINT64 u64;
	if (vmsDialogHelper::GetDlgBytesGroup (this, IDC_FILEMINSIZE, IDC_FILEMINSIZEDIM, &u64) == FALSE)
		return FALSE;
	u = (UINT)u64;

	if (u < 100*1024)
		u = 100*1024;

	_App.Mirr_FileMinSize (u);

	_App.Mirr_AutoSearch (IsDlgButtonChecked (IDC_AUTO) == BST_CHECKED);

	if (IsDlgButtonChecked (IDC_MAXMIRRORS) == BST_CHECKED)
	{
		UINT u;
		u = GetDlgItemInt (IDC_MAXMIRRORSVAL);
		if (u == 0)
		{
			nID = IDC_MAXMIRRORSVAL;
			goto _lInpErr;
		}
		_App.Mirr_MaxCount (u);
	}
	else
		_App.Mirr_MaxCount (UINT_MAX);

	b = IsDlgButtonChecked (IDC_CALCSPEED) == BST_CHECKED;
	_App.Mirr_CalcSpeed (b);
	if (b)
	{
		if (IsDlgButtonChecked (IDC_RECALCSPEED) == BST_CHECKED)
		{
			UINT u;
			u = GetDlgItemInt (IDC_RECALCVAL);
			if (u == 0)
			{
				nID = IDC_RECALCVAL;
				goto _lInpErr;
			}
			_App.Mirr_RecalcSpeedTime (u);
		}
		else
			_App.Mirr_RecalcSpeedTime (0);
	}

	_App.Mirr_DontSearchIfSizeUnk (IsDlgButtonChecked (IDC_DONTIFSIZEUNK) == BST_CHECKED);
	_App.Mirr_Server (m_wndMirrServers.GetCurSel ());

	_DldsMgr.ReadMirrParameters ();
	_DldsMgr.Apply_MirrParameters ();
	
	return CPropertyPage::OnApply();

_lInpErr:
	CString str;
	str.Format (LS (L_ENTERGREATER), 0);
	MessageBox (str, LS (L_INPERR), MB_ICONEXCLAMATION);
	CEdit *pE = (CEdit*) GetDlgItem (nID);
	pE->SetSel (0, -1);
	pE->SetFocus ();
	return FALSE;
}

void CDownloaderProperties_MirrorsPage::OnChangeFileminsize() 
{
	SetModified ();
}

void CDownloaderProperties_MirrorsPage::OnSelchangeFileminsizedim() 
{
	SetModified ();	
}

void CDownloaderProperties_MirrorsPage::OnSelchangeMirrservers() 
{
	SetModified ();	
}
