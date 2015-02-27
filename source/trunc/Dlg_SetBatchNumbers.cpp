/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "Dlg_SetBatchNumbers.h"
#include "vmsBatchList.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDlg_SetBatchNumbers::CDlg_SetBatchNumbers(CWnd* pParent )
	: CDialog(CDlg_SetBatchNumbers::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_SetBatchNumbers)
		
	//}}AFX_DATA_INIT
}

void CDlg_SetBatchNumbers::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_SetBatchNumbers)
	DDX_Control(pDX, IDC_SET, m_wndSets);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlg_SetBatchNumbers, CDialog)
	//{{AFX_MSG_MAP(CDlg_SetBatchNumbers)
	ON_BN_CLICKED(IDC_SETOFNUMBERS, OnSetofnumbers)
	ON_BN_CLICKED(IDC_SINGLENUMBER, OnSinglenumber)
	ON_WM_CONTEXTMENU()
	ON_WM_HELPINFO()
	ON_COMMAND(ID_WHATISTHIS, OnWhatisthis)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CDlg_SetBatchNumbers::UpdateEnabled()
{
	bool b = IsDlgButtonChecked (IDC_SETOFNUMBERS) == BST_CHECKED;

	UINT aIDs [] = {
		IDC__FROM, IDC_FROM, IDC_FROMSPIN, IDC__TO, IDC_TO, IDC_TOSPIN,
		IDC__WB, IDC_WB, IDC_WBSPIN, IDC__STEP, IDC_STEP, IDC_STEPSPIN,
	};

	for (int i = 0; i < sizeof (aIDs) / sizeof (UINT); i++)
		GetDlgItem (aIDs [i])->EnableWindow (b);

	GetDlgItem (IDC__NUMBER)->EnableWindow (!b);
	GetDlgItem (IDC_NUMBER)->EnableWindow (!b);
}

BOOL CDlg_SetBatchNumbers::OnInitDialog() 
{
	CDialog::OnInitDialog();

	int aSpinID [] = { IDC_FROMSPIN, IDC_TOSPIN, IDC_STEPSPIN, IDC_WBSPIN };
	for (int i = 0; i < sizeof (aSpinID) / sizeof (int); i++)
		((CSpinButtonCtrl*) GetDlgItem (aSpinID [i]))->SetRange (i == 0 ? 0 : 1, UD_MAXVAL);

	SetDlgItemInt (IDC_TO, 100);
	SetDlgItemInt (IDC_WB, 1);
	SetDlgItemInt (IDC_STEP, 1);
	
	CheckDlgButton (IDC_SETOFNUMBERS, BST_CHECKED);
	UpdateEnabled ();

	ApplyLanguage ();
	
	return TRUE;  
	              
}

void CDlg_SetBatchNumbers::OnSetofnumbers() 
{
	UpdateEnabled ();	
}

void CDlg_SetBatchNumbers::OnSinglenumber() 
{
	UpdateEnabled ();	
}

void CDlg_SetBatchNumbers::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC__FROM, L_DLGFROM),
		fsDlgLngInfo (IDC__TO, L_DLGTO),
		fsDlgLngInfo (IDC__WB, L_DLGWILDBYTES),
		fsDlgLngInfo (IDC__STEP, L_DLGSTEP),
		fsDlgLngInfo (IDC_SETOFNUMBERS, L_SETOFNUMBERS),
		fsDlgLngInfo (IDC_SINGLENUMBER, L_SINGLENUMBER),
		fsDlgLngInfo (IDC__NUMBER, L_NUMBER, TRUE),
		fsDlgLngInfo (IDC_ADD, L_ADD),
		fsDlgLngInfo (IDCANCEL, L_CANCEL),
	};

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), L_ASSIGNSETOFNUMBERS);
}

void CDlg_SetBatchNumbers::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	PrepareCHMgr (point);
	_CHMgr.ShowMenu ();		
}

BOOL CDlg_SetBatchNumbers::OnHelpInfo(HELPINFO* pHelpInfo) 
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

void CDlg_SetBatchNumbers::OnWhatisthis() 
{
	_CHMgr.OnWT ();	
}

void CDlg_SetBatchNumbers::PrepareCHMgr(CPoint point)
{
	fsCtrlContextHelp aCH1 [] = {
		fsCtrlContextHelp (IDC__FROM, LS (L_FROMHERE)),
		fsCtrlContextHelp (IDC_FROM, LS (L_FROMHERE)),
		fsCtrlContextHelp (IDC__TO, LS (L_TOHERE)),
		fsCtrlContextHelp (IDC_TO, LS (L_TOHERE)),
		fsCtrlContextHelp (IDC__STEP, LS (L_STEPHERE)),
		fsCtrlContextHelp (IDC_STEP, LS (L_STEPHERE)),
		fsCtrlContextHelp (IDC__WB, LS (L_WILDBYTESHERE)),
		fsCtrlContextHelp (IDC_WB, LS (L_WILDBYTESHERE)),
	};

    static fsCtrlContextHelp aCH [sizeof (aCH1) / sizeof (fsCtrlContextHelp)];
	CopyMemory (aCH, aCH1, sizeof (aCH));

	_CHMgr.PrepareContextMenu (this, point, aCH, sizeof (aCH) / sizeof (fsCtrlContextHelp));
}

void CDlg_SetBatchNumbers::OnAdd() 
{
	CString str, strU;
	UINT nID;

	if (IsDlgButtonChecked (IDC_SETOFNUMBERS) == BST_CHECKED)
	{
		int from, to, step, wc;
		from = GetDlgItemInt (IDC_FROM);
		to = GetDlgItemInt (IDC_TO);
		step = GetDlgItemInt (IDC_STEP);
		wc = GetDlgItemInt (IDC_WB);

		if (to == 0)
		{
			nID = IDC_TO;
			goto _l0Err;
		}

		if (step == 0)
		{
			nID = IDC_STEP;
			goto _l0Err;
		}

		if (wc == 0)
		{
			nID = IDC_WB;
			goto _l0Err;
		}

		if (to <= from)
		{
			MessageBox (LS (L_TOMBGTFROM), LS (L_INPERR), MB_ICONEXCLAMATION);
			((CEdit*) GetDlgItem (IDC_TO))->SetSel (0, -1);
			GetDlgItem (IDC_TO)->SetFocus ();
			return;
		}

		if (false == CheckSetOfNumbersParameters (from, to, step, wc))
			return;

		str.Format ("%d-%d", from, to);
		strU.Format ("%s %d %s %d", LS (L_DLGFROM), from, LS (L_DLGTO), to);
		strU.Remove (':');

		if (step != 1) {
			CString str2; 
			str2.Format ("%c%d", BATCHLIST_STEP_SYMBOL, step);
			str += str2;
			str2.Format (" %s %d", LS (L_DLGSTEP), step);
			str2.Remove (':');
			strU += str2;
		}

		if (wc != 1) {
			CString str2;
			str2.Format ("%c%d", BATCHLIST_WILDCARD_SYMBOL, wc);
			str += str2;
			str2.Format (" %s %d", LS (L_DLGWILDBYTES), wc);
			str2.Remove (':');
			strU += str2;
		}
	}
	else
	{
		int n = GetDlgItemInt (IDC_NUMBER);
		str.Format ("%d", n);
		strU = str;
	}

	m_wndSets.AddString (strU);
	CString *pstr; pstr = new CString;
	*pstr = str;
	m_wndSets.SetItemData (m_wndSets.GetCount () - 1, (DWORD)pstr);
	return;

_l0Err:
	str.Format (LS (L_ENTERGREATER), 0);
	MessageBox (str, LS (L_INPERR), MB_ICONEXCLAMATION);
	CEdit *pE = (CEdit*) GetDlgItem (nID);
	pE->SetSel (0, -1);
	pE->SetFocus ();
}

void CDlg_SetBatchNumbers::OnOK() 
{
	m_strNumbers = "";

	for (int i = 0; i < m_wndSets.GetCount (); i++)
	{
		CString* str = (CString*) m_wndSets.GetItemData (i);
		if (i)
			m_strNumbers += ", ";

		m_strNumbers += *str;
		delete str;
	}
	
	CDialog::OnOK();
}

bool CDlg_SetBatchNumbers::CheckSetOfNumbersParameters(int from, int to, int step, int wc)
{
	int nID;

	if (to == 0)
	{
		nID = IDC_TO;
		goto _l0Err;
	}

	if (step == 0)
	{
		nID = IDC_STEP;
		goto _l0Err;
	}

	if (wc == 0)
	{
		nID = IDC_WB;
		goto _l0Err;
	}

	if (to <= from)
	{
		MessageBox (LS (L_TOMBGTFROM), LS (L_INPERR), MB_ICONEXCLAMATION);
		((CEdit*) GetDlgItem (IDC_TO))->SetSel (0, -1);
		GetDlgItem (IDC_TO)->SetFocus ();
		return FALSE;
	}

	return true;

_l0Err:
	CString str;
	str.Format (LS (L_ENTERGREATER), 0);
	MessageBox (str, LS (L_INPERR), MB_ICONEXCLAMATION);
	CEdit *pE = (CEdit*) GetDlgItem (nID);
	pE->SetSel (0, -1);
	pE->SetFocus ();
	return false;
}
