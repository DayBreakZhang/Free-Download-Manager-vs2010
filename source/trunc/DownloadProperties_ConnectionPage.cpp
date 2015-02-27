/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "DownloadProperties_ConnectionPage.h"
#include "DownloadProperties.h"
#include "misc.h"
#include "DownloadsWnd.h"
#include "fsDownloadMgr.h"
#include "vmsDialogHelper.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNCREATE(CDownloadProperties_ConnectionPage, CPropertyPage)

CDownloadProperties_ConnectionPage::CDownloadProperties_ConnectionPage() : CPropertyPage(CDownloadProperties_ConnectionPage::IDD)
{
	m_psp.dwFlags |= PSP_USETITLE;
	m_psp.pszTitle = LS (L_CONNECTION);
}

CDownloadProperties_ConnectionPage::~CDownloadProperties_ConnectionPage()
{
}

void CDownloadProperties_ConnectionPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDownloadProperties_ConnectionPage)
		
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDownloadProperties_ConnectionPage, CPropertyPage)
	//{{AFX_MSG_MAP(CDownloadProperties_ConnectionPage)
	ON_BN_CLICKED(IDC_LIMITTRAFFIC, OnLimittraffic)
	ON_BN_CLICKED(IDC_IGNOREALLRESTRICTIONS, OnIgnoreallrestrictions)
	ON_EN_CHANGE(IDC_PAUSEBETWEEN, OnChangePausebetween)
	ON_EN_CHANGE(IDC_MAXATTEMPTS, OnChangeMaxattempts)
	ON_EN_CHANGE(IDC_TIMEOUT, OnChangeTimeout)
	ON_EN_CHANGE(IDC_SECTMINSIZE, OnChangeSectminsize)
	ON_EN_CHANGE(IDC_SECTMAXCOUNT, OnChangeSectmaxcount)
	ON_EN_CHANGE(IDC_TRAFFICLIMITVAL, OnChangeTrafficlimitval)
	ON_CBN_EDITCHANGE(IDC_TRAFFICLIMITDIM, OnEditchangeTrafficlimitdim)
	ON_CBN_SELCHANGE(IDC_TRAFFICLIMITDIM, OnSelchangeTrafficlimitdim)
	ON_CBN_SELCHANGE(IDC_SECTMINSIZEDIM, OnSelchangeSectminsizedim)
	ON_BN_CLICKED(IDC_USEMAXATTEMPTS, OnUsemaxattempts)
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_WHATISTHIS, OnWhatisthis)
	ON_WM_HELPINFO()
	ON_BN_CLICKED(IDC_RESTARTIFSPEEDLOW, OnRestartifspeedlow)
	ON_EN_CHANGE(IDC_LOWSPEED_DURATION, OnChangeLowspeedDuration)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

#define DP_OFFSET(member) ( LPBYTE (&dp.member) - LPBYTE (&dp) )

#define DP_SIZEOF(member) ( sizeof (dp.member) )

#define DP_EQ(member, bString) DPEntry_IsAllEqual (m_pvDlds, DP_OFFSET (member), DP_SIZEOF (member), bString)

#define DP_SET(member, bString, NewVal) DPEntry_SetValue (m_pvDlds, DP_OFFSET (member), DP_SIZEOF (member), bString, NewVal)

#define DNP_OFFSET(member) ( LPBYTE (&dnp.member) - LPBYTE (&dnp) )
#define DNP_SIZEOF(member) ( sizeof (dnp.member) )
#define DNP_EQ(member, bString) DNPEntry_IsAllEqual (m_pvDlds, DNP_OFFSET (member), DNP_SIZEOF (member), bString)
#define DNP_EQ_MASK(member, mask) DNPEntry_IsAllEqual_BitMask (m_pvDlds, DNP_OFFSET (member), mask)
#define DNP_SET(member, bString, NewVal) DNPEntry_SetValue (m_pvDlds, DNP_OFFSET (member), DNP_SIZEOF (member), bString, NewVal)
#define DNP_SET_MASK(member, mask) DNPEntry_SetValue_BitMask (m_pvDlds, DNP_OFFSET (member), mask)
#define DNP_UNSET_MASK(member, mask) DNPEntry_UnsetValue_BitMask (m_pvDlds, DNP_OFFSET (member), mask)

BOOL CDownloadProperties_ConnectionPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();

	fsDownload_Properties dp;
	fsDownload_Properties* dp0 = m_pvDlds->at (0)->pMgr->GetDownloadMgr ()->GetDP ();

	
	UINT pID [] = {
		IDC_PAUSEBETWEENSPIN, IDC_MAXATTEMPTSSPIN, IDC_SECTMAXCOUNTSPIN,
		IDC_LOWSPEED_DURATIONSPIN,
	};

	CSpinButtonCtrl *pSpin;

	for (int i = 0; i < sizeof (pID) / sizeof (UINT); i++)
	{
		pSpin = (CSpinButtonCtrl*) GetDlgItem (pID [i]);
		pSpin->SetRange (1, UD_MAXVAL);
	}

	pSpin = (CSpinButtonCtrl*) GetDlgItem (IDC_TIMEOUTSPIN);
	pSpin->SetRange (10, UD_MAXVAL);

	CComboBox *pBox = (CComboBox*) GetDlgItem (IDC_SECTMINSIZEDIM);
	pBox->AddString (LS (L_B)); pBox->AddString (LS (L_KB)); pBox->AddString (LS (L_MB));

	pBox = (CComboBox*) GetDlgItem (IDC_TRAFFICLIMITDIM);
	CString str; 
	
	str.Format ("%s/%s", LS (L_B), LS (L_S));	pBox->AddString (str); 
	str.Format ("%s/%s", LS (L_KB), LS (L_S)); pBox->AddString (str); 
	str.Format ("%s/%s", LS (L_MB), LS (L_S)); pBox->AddString (str);

	if (DP_EQ (uRetriesTime, FALSE))	
		
		SetDlgItemInt (IDC_PAUSEBETWEEN, dp0->uRetriesTime / 1000, FALSE);
	else
		SetDlgItemText (IDC_PAUSEBETWEEN, "");	

	

	if (DP_EQ (uMaxAttempts, FALSE))
	{
		if (dp0->uMaxAttempts != UINT_MAX)
			SetDlgItemInt (IDC_MAXATTEMPTS, dp0->uMaxAttempts, FALSE);
		else
			SetDlgItemInt (IDC_MAXATTEMPTS, 1, FALSE);

		CheckDlgButton (IDC_USEMAXATTEMPTS, dp0->uMaxAttempts != UINT_MAX ? BST_CHECKED : BST_UNCHECKED);		
	}
	else
	{
		BOOL bUse = dp0->uMaxAttempts != UINT_MAX;
		int i;
		for (i = m_pvDlds->size () - 1; i; i--)
		{
			BOOL bU = m_pvDlds->at (i)->pMgr->GetDownloadMgr ()->GetDP ()->uMaxAttempts != UINT_MAX;
			if (bU != bUse)
				break;
		}

		if (i)
			CheckDlgButton (IDC_USEMAXATTEMPTS, BST_INDETERMINATE);
		else
			CheckDlgButton (IDC_USEMAXATTEMPTS, bUse ? BST_CHECKED : BST_UNCHECKED);

		SetDlgItemText (IDC_MAXATTEMPTS, "");
	}

	if (DP_EQ (uTimeout, FALSE))
		SetDlgItemInt (IDC_TIMEOUT, dp0->uTimeout / 1000, FALSE);
	else
		SetDlgItemText (IDC_TIMEOUT, "");

	if (DP_EQ (uSectionMinSize, FALSE))
		vmsDialogHelper::SetDlgBytesGroup (this, dp0->uSectionMinSize, IDC_SECTMINSIZE, IDC_SECTMINSIZEDIM);
	else
		((CComboBox*) GetDlgItem (IDC_SECTMINSIZEDIM))->SetCurSel (0);

	if (DP_EQ (uMaxSections, FALSE))
		SetDlgItemInt (IDC_SECTMAXCOUNT, dp0->uMaxSections, FALSE);
	else
		SetDlgItemText (IDC_SECTMAXCOUNT, "");

	BOOL bLimit = dp0->uTrafficRestriction != UINT_MAX;
	CheckDlgButton (IDC_LIMITTRAFFIC, bLimit ? BST_CHECKED : BST_UNCHECKED);
	int i;
	for (i = m_pvDlds->size () - 1; i; i--)
	{
		BOOL bLim = m_pvDlds->at (i)->pMgr->GetDownloadMgr ()->GetDP ()->uTrafficRestriction != UINT_MAX;
		if (bLim != bLimit)
		{
			CheckDlgButton (IDC_LIMITTRAFFIC, BST_INDETERMINATE);
			break;
		}
	}
	
	((CComboBox*) GetDlgItem (IDC_TRAFFICLIMITDIM))->SetCurSel (0);
	if (DP_EQ (uTrafficRestriction, FALSE))
	{
		if (dp0->uTrafficRestriction != UINT_MAX)
			vmsDialogHelper::SetDlgBytesGroup (this, dp0->uTrafficRestriction, IDC_TRAFFICLIMITVAL, IDC_TRAFFICLIMITDIM);
	}

	if (DP_EQ (bIgnoreRestrictions, FALSE))
		CheckDlgButton (IDC_IGNOREALLRESTRICTIONS, dp0->bIgnoreRestrictions ? BST_CHECKED : BST_UNCHECKED);
	else
		CheckDlgButton (IDC_IGNOREALLRESTRICTIONS, BST_INDETERMINATE);

	fsDownload_NetworkProperties dnp;
	fsDownload_NetworkProperties* dnp0 = m_pvDlds->at (0)->pMgr->GetDownloadMgr ()->GetDNP ();

	if (DNP_EQ_MASK (dwFlags, DNPF_RESTARTSECTIONWHENSPEEDTOOLOW))
		CheckDlgButton (IDC_RESTARTIFSPEEDLOW, dnp0->dwFlags & DNPF_RESTARTSECTIONWHENSPEEDTOOLOW ? BST_CHECKED : BST_UNCHECKED);
	else
		CheckDlgButton (IDC_RESTARTIFSPEEDLOW, BST_INDETERMINATE);

	if (DNP_EQ (wLowSpeed_Duration, FALSE))
		SetDlgItemInt (IDC_LOWSPEED_DURATION, dnp0->wLowSpeed_Duration, FALSE);
	else
		SetDlgItemText (IDC_LOWSPEED_DURATION, "");

	UpdateEnabled ();

	ApplyLanguage ();
	
	return TRUE;  
	              
}

void CDownloadProperties_ConnectionPage::UpdateEnabled()
{
	BOOL bLimitTraffic = IsDlgButtonChecked (IDC_LIMITTRAFFIC) == BST_CHECKED;
	BOOL bIgnoreAll = IsDlgButtonChecked (IDC_IGNOREALLRESTRICTIONS) == BST_CHECKED;

	GetDlgItem (IDC_TRAFFICLIMITVAL)->EnableWindow (bLimitTraffic && bIgnoreAll == FALSE);
	GetDlgItem (IDC_TRAFFICLIMITDIM)->EnableWindow (bLimitTraffic && bIgnoreAll == FALSE);
	GetDlgItem (IDC_LIMITTRAFFIC)->EnableWindow (bIgnoreAll == FALSE);

	BOOL b = IsDlgButtonChecked (IDC_USEMAXATTEMPTS) == BST_CHECKED;
	GetDlgItem (IDC_MAXATTEMPTS)->EnableWindow (b);
	GetDlgItem (IDC_MAXATTEMPTSSPIN)->EnableWindow (b);

	b = IsDlgButtonChecked (IDC_RESTARTIFSPEEDLOW) == BST_CHECKED;
	GetDlgItem (IDC_LOWSPEED_DURATION)->EnableWindow (b);
	GetDlgItem (IDC_LOWSPEED_DURATIONSPIN)->EnableWindow (b);
}

void CDownloadProperties_ConnectionPage::OnLimittraffic() 
{
	if (IsDlgButtonChecked (IDC_LIMITTRAFFIC) == BST_INDETERMINATE)
		CheckDlgButton (IDC_LIMITTRAFFIC, BST_UNCHECKED);

	UpdateEnabled ();
	SetModified ();	
}

void CDownloadProperties_ConnectionPage::OnIgnoreallrestrictions() 
{
	
	if (IsDlgButtonChecked (IDC_IGNOREALLRESTRICTIONS) == BST_INDETERMINATE)
		CheckDlgButton (IDC_IGNOREALLRESTRICTIONS, BST_UNCHECKED);

	UpdateEnabled ();
	SetModified ();
}

void CDownloadProperties_ConnectionPage::OnChangePausebetween() 
{
	SetModified ();
}

void CDownloadProperties_ConnectionPage::OnChangeMaxattempts() 
{
	SetModified ();
}

void CDownloadProperties_ConnectionPage::OnChangeTimeout() 
{
	SetModified ();
}

void CDownloadProperties_ConnectionPage::OnChangeSectminsize() 
{
	SetModified ();
}

void CDownloadProperties_ConnectionPage::OnChangeSectmaxcount() 
{
	SetModified ();
}

void CDownloadProperties_ConnectionPage::OnChangeTrafficlimitval() 
{
	SetModified ();
}

void CDownloadProperties_ConnectionPage::OnEditchangeTrafficlimitdim() 
{
	SetModified ();	
}

void CDownloadProperties_ConnectionPage::OnSelchangeTrafficlimitdim() 
{
	SetModified ();	
}

void CDownloadProperties_ConnectionPage::OnSelchangeSectminsizedim() 
{
	SetModified ();	
}

BOOL CDownloadProperties_ConnectionPage::OnApply() 
{

#define CHECK_RANGE(id, min) if (val < min) { ErrMustBeGreaterThan (id, min); return FALSE; }

#define SET_VAL_EX(id, min, Value, Mul) GetDlgItemText (id, str); if (str.GetLength ()) { int  val = atoi (str); CHECK_RANGE (id, min); val*= Mul; DP_SET (Value, FALSE, &val); }
#define SET_VAL(id, min, Value) SET_VAL_EX (id, min, Value, 1)

	CString str;
	UINT uVal;
	fsDownload_Properties dp;

	SET_VAL_EX (IDC_PAUSEBETWEEN, 1, uRetriesTime, 1000);
	SET_VAL_EX (IDC_TIMEOUT, 10, uTimeout, 1000);

	UINT nCheck = IsDlgButtonChecked (IDC_USEMAXATTEMPTS);
	if (nCheck == BST_CHECKED)
	{
		SET_VAL (IDC_MAXATTEMPTS, 1, uMaxAttempts);
	}
	else if (nCheck == BST_UNCHECKED)
	{
		UINT val = UINT_MAX;
		DP_SET (uMaxAttempts, FALSE, &val);
	}

	UINT64 u;
	if (vmsDialogHelper::GetDlgBytesGroup (this, IDC_SECTMINSIZE, IDC_SECTMINSIZEDIM, &u))
	{
		uVal = (UINT)u;
		DP_SET (uSectionMinSize, FALSE, &uVal);
	}
	else if (GetLastError () == ERROR_INVALID_DATA)
		return FALSE;

	SET_VAL (IDC_SECTMAXCOUNT, 1, uMaxSections);

	nCheck = IsDlgButtonChecked (IDC_LIMITTRAFFIC);
	if (nCheck == BST_UNCHECKED)
	{
		uVal = UINT_MAX;
		DP_SET (uTrafficRestriction, FALSE, &uVal);
	}
	else
	{
		UINT64 u;
		if (vmsDialogHelper::GetDlgBytesGroup (this, IDC_TRAFFICLIMITVAL, IDC_TRAFFICLIMITDIM, &u))
		{
			uVal = (UINT)u;
			DP_SET (uTrafficRestriction, FALSE, &uVal);
		}
		else if (GetLastError () == ERROR_INVALID_DATA)
			return FALSE;
	}

	nCheck = IsDlgButtonChecked (IDC_IGNOREALLRESTRICTIONS);
	if (nCheck != BST_INDETERMINATE)
	{
		BOOL bIgnore = nCheck == BST_CHECKED;
		DP_SET (bIgnoreRestrictions, FALSE, &bIgnore);
	}

	fsDownload_NetworkProperties dnp;
	

	nCheck = IsDlgButtonChecked (IDC_RESTARTIFSPEEDLOW);
	if (nCheck == BST_CHECKED)
	{
		DNP_SET_MASK (dwFlags, DNPF_RESTARTSECTIONWHENSPEEDTOOLOW);
		WORD w = (WORD)GetDlgItemInt (IDC_LOWSPEED_DURATION, NULL, FALSE);
		if (w)
			DNP_SET (wLowSpeed_Duration, FALSE, &w);
	}
	else if (nCheck == BST_UNCHECKED)
	{
		DNP_UNSET_MASK (dwFlags, DNPF_RESTARTSECTIONWHENSPEEDTOOLOW);
	}

	for (int i = m_pvDlds->size () - 1; i >= 0; i--)
	{
		if (m_pvDlds->at (i)->pMgr->IsRunning ())
			m_pvDlds->at (i)->pMgr->GetDownloadMgr ()->ApplyProperties ();	
	}

	

	return CPropertyPage::OnApply();
}

void CDownloadProperties_ConnectionPage::ErrMustBeGreaterThan(UINT nID, UINT uMin)
{
	CString str;

	str.Format (LS (L_ENTERGREATER), uMin);
	MessageBox (str, LS (L_INPERR), MB_ICONEXCLAMATION);
	
	CEdit *pEdit = (CEdit*) GetDlgItem (nID);
	pEdit->SetSel (0, -1);
	pEdit->SetFocus ();
}

void CDownloadProperties_ConnectionPage::OnUsemaxattempts() 
{
	if (IsDlgButtonChecked (IDC_USEMAXATTEMPTS) == BST_INDETERMINATE)
		CheckDlgButton (IDC_USEMAXATTEMPTS, BST_UNCHECKED);

	UpdateEnabled ();
	SetModified ();
}

void CDownloadProperties_ConnectionPage::OnContextMenu(CWnd* , CPoint point) 
{
	PrepareCHMgr (point);
	_CHMgr.ShowMenu ();
}

void CDownloadProperties_ConnectionPage::OnWhatisthis() 
{
	_CHMgr.OnWT ();	
}

void CDownloadProperties_ConnectionPage::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC__NETWORK, L_NETWORK),
		fsDlgLngInfo (IDC__ERRORS, L_ERRS),
		fsDlgLngInfo (IDC__PAUSEBETWEEN, L_PAUSEBETWEEN),
		fsDlgLngInfo (IDC_USEMAXATTEMPTS, L_MAXATTEMPTS),
		fsDlgLngInfo (IDC__TIMEOUT, L_TIMEOUTINSEC),
		fsDlgLngInfo (IDC__SECTIONS, L_SECTIONS),
		fsDlgLngInfo (IDC__SECTMINSIZE, L_MINSIZE),
		fsDlgLngInfo (IDC__SECTMAXCOUNT, L_MAXCOUNT),
		fsDlgLngInfo (IDC__NETUSAGERESTR, L_NETUSAGERESTR),
		fsDlgLngInfo (IDC_LIMITTRAFFIC, L_LIMITTRAFF),
		fsDlgLngInfo (IDC_IGNOREALLRESTRICTIONS, L_IGNOREALLRESTR),
		fsDlgLngInfo (IDC_RESTARTIFSPEEDLOW, L_RESTARTATLOWSPEED),
	};

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), 0);
}

BOOL CDownloadProperties_ConnectionPage::OnHelpInfo(HELPINFO* pHelpInfo) 
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

void CDownloadProperties_ConnectionPage::PrepareCHMgr(CPoint point)
{
	fsCtrlContextHelp aCH1 [] = {
		fsCtrlContextHelp (IDC__PAUSEBETWEEN, LS (L_PAUSEBETWEENHERE)),
		fsCtrlContextHelp (IDC_PAUSEBETWEEN, LS (L_PAUSEBETWEENHERE)),
		fsCtrlContextHelp (IDC_USEMAXATTEMPTS, LS (L_MAXATTEMPTSHERE)),
		fsCtrlContextHelp (IDC__TIMEOUT, LS (L_TIMEOUTHERE)),
		fsCtrlContextHelp (IDC_TIMEOUT, LS (L_TIMEOUTHERE)),
		fsCtrlContextHelp (IDC__SECTMINSIZE, LS (L_MINSECTSIZEHERE)),
		fsCtrlContextHelp (IDC_SECTMINSIZE, LS (L_MINSECTSIZEHERE)),
		fsCtrlContextHelp (IDC__SECTMAXCOUNT, LS (L_MAXSECTHERE)),
		fsCtrlContextHelp (IDC_SECTMAXCOUNT, LS (L_MAXSECTHERE)),
		fsCtrlContextHelp (IDC_LIMITTRAFFIC, LS (L_TRAFFLIMITHERE)),
		fsCtrlContextHelp (IDC_IGNOREALLRESTRICTIONS, LS (L_IGNOREALLHERE)),
		fsCtrlContextHelp (IDC_SECTMINSIZEDIM, LS (L_DIMHERE)),
		fsCtrlContextHelp (IDC_TRAFFICLIMITDIM, LS (L_DIMHERE)),
		fsCtrlContextHelp (IDC_RESTARTIFSPEEDLOW, LS (L_RESTARTATLOWSPEED_HERE)),
		fsCtrlContextHelp (IDC_LOWSPEED_DURATION, LS (L_RESTARTATLOWSPEED_HERE)),
	};

    static fsCtrlContextHelp aCH [sizeof (aCH1) / sizeof (fsCtrlContextHelp)];
	CopyMemory (aCH, aCH1, sizeof (aCH));

	_CHMgr.PrepareContextMenu (this, point, aCH, sizeof (aCH) / sizeof (fsCtrlContextHelp));
}

void CDownloadProperties_ConnectionPage::OnRestartifspeedlow() 
{
	if (IsDlgButtonChecked (IDC_RESTARTIFSPEEDLOW) == BST_INDETERMINATE)
		CheckDlgButton (IDC_RESTARTIFSPEEDLOW, BST_UNCHECKED);

	SetModified ();
	UpdateEnabled ();
}

void CDownloadProperties_ConnectionPage::OnChangeLowspeedDuration() 
{
	SetModified ();
}
