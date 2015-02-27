/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "fdm.h"
#include "Dlg_Options_Downloads_Mirrors.h"
#include "vmsDialogHelper.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDlg_Options_Downloads_Mirrors::CDlg_Options_Downloads_Mirrors(CWnd* pParent )
	: CDlg_Options_Page(CDlg_Options_Downloads_Mirrors::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_Options_Downloads_Mirrors)
		
	//}}AFX_DATA_INIT
}

void CDlg_Options_Downloads_Mirrors::DoDataExchange(CDataExchange* pDX)
{
	CDlg_Options_Page::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_Options_Downloads_Mirrors)
	DDX_Control(pDX, IDC_FILEMINSIZEDIM, m_wndMinSizeDim);
	DDX_Control(pDX, IDC_MIRRSERVERS, m_wndMirrServers);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlg_Options_Downloads_Mirrors, CDlg_Options_Page)
	//{{AFX_MSG_MAP(CDlg_Options_Downloads_Mirrors)
	ON_BN_CLICKED(IDC_AUTO, OnAuto)
	ON_BN_CLICKED(IDC_MAXMIRRORS, OnMaxmirrors)
	ON_BN_CLICKED(IDC_CALCSPEED, OnCalcspeed)
	ON_BN_CLICKED(IDC_RECALCSPEED, OnRecalcspeed)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDlg_Options_Downloads_Mirrors::OnInitDialog() 
{
	CDlg_Options_Page::OnInitDialog();
	
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

	CheckDlgButton (IDC_CHECKIFDLDISMIRR, _App.CheckIfDownloadIsMirror () ? BST_CHECKED : BST_UNCHECKED);
	
	m_wndMirrServers.AddString ("FileSearching.com");
	m_wndMirrServers.AddString ("FindFiles.com");
	m_wndMirrServers.SetCurSel (_App.Mirr_Server ());
	
	ApplyLanguage ();
	UpdateEnabled ();
	
	return TRUE;  
	              
}

CString CDlg_Options_Downloads_Mirrors::get_PageTitle()
{
	return LS (L_MIRRORS);
}

CString CDlg_Options_Downloads_Mirrors::get_PageShortTitle()
{
	return LS (L_MIRRORS);
}

BOOL CDlg_Options_Downloads_Mirrors::Apply()
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

	_App.CheckIfDownloadIsMirror (IsDlgButtonChecked (IDC_CHECKIFDLDISMIRR) == BST_CHECKED);
	
	_DldsMgr.ReadMirrParameters ();
	_DldsMgr.Apply_MirrParameters ();
	
	return TRUE;
	
_lInpErr:
	CString str;
	str.Format (LS (L_ENTERGREATER), 0);
	MessageBox (str, LS (L_INPERR), MB_ICONEXCLAMATION);
	CEdit *pE = (CEdit*) GetDlgItem (nID);
	pE->SetSel (0, -1);
	pE->SetFocus ();
	return FALSE;
}

void CDlg_Options_Downloads_Mirrors::ApplyLanguage()
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
		fsDlgLngInfo (IDC_CHECKIFDLDISMIRR, L_CHECKIFDLDISMIRROPTION),
	};
	
	_LngMgr.ApplyLanguage (	this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), 0);
}

void CDlg_Options_Downloads_Mirrors::UpdateEnabled()
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

void CDlg_Options_Downloads_Mirrors::OnAuto() 
{
	UpdateEnabled ();	
}

void CDlg_Options_Downloads_Mirrors::OnMaxmirrors() 
{
	UpdateEnabled ();	
}

void CDlg_Options_Downloads_Mirrors::OnCalcspeed() 
{
	UpdateEnabled ();	
}

void CDlg_Options_Downloads_Mirrors::OnRecalcspeed() 
{
	UpdateEnabled ();
}
