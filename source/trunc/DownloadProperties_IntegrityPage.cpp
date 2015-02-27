/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "DownloadProperties_IntegrityPage.h"
#include "Hash\vmsHash.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define DP_OFFSET(member) ( LPBYTE (&dp.member) - LPBYTE (&dp) )
#define DP_SIZEOF(member) ( sizeof (dp.member) )
#define DP_EQ_EX(memOffset, memSize, bString) DPEntry_IsAllEqual (m_pvDlds, memOffset, memSize, bString)
#define DP_EQ_MASK(member, mask) DPEntry_IsAllEqual_BitMask (m_pvDlds, DP_OFFSET (member), mask)
#define DP_EQ(member, bString) DP_EQ_EX (DP_OFFSET (member), DP_SIZEOF (member), bString)
#define DP_SET_EX(memOffset, memSize, bString, NewVal) DPEntry_SetValue (m_pvDlds, memOffset, memSize, bString, NewVal)
#define DP_SET(member, bString, NewVal) DP_SET_EX (DP_OFFSET (member), DP_SIZEOF (member), bString, NewVal)
#define DP_SET_MASK(member, mask) DPEntry_SetValue_BitMask (m_pvDlds, DP_OFFSET (member), mask)
#define DP_UNSET_MASK(member, mask) DPEntry_UnsetValue_BitMask (m_pvDlds, DP_OFFSET (member), mask)

IMPLEMENT_DYNCREATE(CDownloadProperties_IntegrityPage, CPropertyPage)

CDownloadProperties_IntegrityPage::CDownloadProperties_IntegrityPage() : CPropertyPage(CDownloadProperties_IntegrityPage::IDD)
{
	m_psp.dwFlags |= PSP_USETITLE;
	m_psp.pszTitle = LS (L_INTEGRITY);
}

CDownloadProperties_IntegrityPage::~CDownloadProperties_IntegrityPage()
{
}

void CDownloadProperties_IntegrityPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDownloadProperties_IntegrityPage)
	DDX_Control(pDX, IDC_ALGORITHM, m_wndAlgorithm);
	DDX_Control(pDX, IDC_ICFR, m_wndICFR);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDownloadProperties_IntegrityPage, CPropertyPage)
	//{{AFX_MSG_MAP(CDownloadProperties_IntegrityPage)
	ON_BN_CLICKED(IDC_PERFORMCHECKWHENDONE, OnPerformcheckwhendone)
	ON_CBN_SELCHANGE(IDC_ALGORITHM, OnSelchangeAlgorithm)
	ON_CBN_SELCHANGE(IDC_ICFR, OnSelchangeIcfr)
	ON_EN_CHANGE(IDC_CHECKSUM, OnChangeChecksum)
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_WHATISTHIS, OnWhatisthis)
	ON_WM_HELPINFO()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDownloadProperties_IntegrityPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();

	fsDownload_Properties dp;
	fsDownload_Properties *dp0 = m_pvDlds->at (0)->pMgr->GetDownloadMgr ()->GetDP ();

	if (DP_EQ (bCheckIntegrityWhenDone, FALSE))
		CheckDlgButton (IDC_PERFORMCHECKWHENDONE, dp0->bCheckIntegrityWhenDone ? BST_CHECKED : BST_UNCHECKED);
	else
		CheckDlgButton (IDC_PERFORMCHECKWHENDONE, BST_INDETERMINATE);

	m_wndICFR.AddString (LS (L_ASK));
	m_wndICFR.AddString (LS (L_RESTART));
	m_wndICFR.AddString (LS (L_DONOTHING));
	if (DP_EQ (enICFR, FALSE))
		m_wndICFR.SetCurSel (dp0->enICFR);

	LPCSTR ppszAlgs [] = {
		"MD5", "SHA-1", "SHA-2 256", "SHA-2 384", "SHA-2 512",
		"CRC 32"
	};

	DWORD adwAlgs [] = {
		HA_MD5, HA_SHA1, HA_SHA2, 
		MAKELONG (HA_SHA2, HSHA2S_384), MAKELONG (HA_SHA2, HSHA2S_512), 
		HA_CRC32,
	};

	DWORD dwAlg = (DWORD)-1;
	if (m_pvDlds->size () == 1)
		dwAlg = dp0->dwIntegrityCheckAlgorithm;

	for (int i = 0; i < sizeof (ppszAlgs) / sizeof (LPCSTR); i++)
	{
		m_wndAlgorithm.AddString (ppszAlgs [i]);
		m_wndAlgorithm.SetItemData (i, adwAlgs [i]);
		if (dwAlg == adwAlgs [i])
			m_wndAlgorithm.SetCurSel (i);
	}

	if (m_pvDlds->size () == 1)
	{
		SetDlgItemText (IDC_CHECKSUM, dp0->pszCheckSum);		
	}
	else
	{
		UINT anIds [] = {
			IDC__CHECKSUMOFTHISFILE, IDC_CHECKSUM, 
			IDC__ALGORITHM, IDC_ALGORITHM
		};

		for (int i = 0; i < sizeof (anIds) / sizeof (UINT); i++)
			GetDlgItem (anIds [i])->ShowWindow (SW_HIDE);
	}

	ApplyLanguage ();

	UpdateEnabled ();
	
	return TRUE;  
	              
}

void CDownloadProperties_IntegrityPage::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC_PERFORMCHECKWHENDONE, L_PERFORMINTEGRITYCHECK),
		fsDlgLngInfo (IDC__IFCHECKFAILED, L_IFCHECKFAILED, TRUE),
		fsDlgLngInfo (IDC__CHECKSUMOFTHISFILE, L_CHECKSUMOFTHISFILE, TRUE),
		fsDlgLngInfo (IDC__ALGORITHM, L_ALGORITHM, TRUE),
	};

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), 0);
}

void CDownloadProperties_IntegrityPage::OnPerformcheckwhendone() 
{
	if (IsDlgButtonChecked (IDC_PERFORMCHECKWHENDONE) == BST_INDETERMINATE)
		CheckDlgButton (IDC_PERFORMCHECKWHENDONE, BST_UNCHECKED);

	SetModified ();	
}

void CDownloadProperties_IntegrityPage::OnSelchangeAlgorithm() 
{
	SetModified ();	
}

void CDownloadProperties_IntegrityPage::OnSelchangeIcfr() 
{
	SetModified ();	
}

void CDownloadProperties_IntegrityPage::OnChangeChecksum() 
{
	SetModified ();	
}

void CDownloadProperties_IntegrityPage::UpdateEnabled()
{
	
}

void CDownloadProperties_IntegrityPage::OnContextMenu(CWnd* , CPoint point) 
{
	PrepareCHMgr (point);
	_CHMgr.ShowMenu ();	
}

void CDownloadProperties_IntegrityPage::OnWhatisthis() 
{
	_CHMgr.OnWT ();		
}

BOOL CDownloadProperties_IntegrityPage::OnHelpInfo(HELPINFO* pHelpInfo) 
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

void CDownloadProperties_IntegrityPage::PrepareCHMgr(CPoint point)
{
	fsCtrlContextHelp aCH1 [] = {
		fsCtrlContextHelp (IDC_PERFORMCHECKWHENDONE, LS (L_PERFORMINTEGRITYCHECKWHENDONE_HERE)),
		fsCtrlContextHelp (IDC_ICFR, LS (L_ICFR_HERE)),
		fsCtrlContextHelp (IDC__IFCHECKFAILED, LS (L_ICFR_HERE)),
	};

    static fsCtrlContextHelp aCH [sizeof (aCH1) / sizeof (fsCtrlContextHelp)];
	CopyMemory (aCH, aCH1, sizeof (aCH));

	_CHMgr.PrepareContextMenu (this, point, aCH, sizeof (aCH) / sizeof (fsCtrlContextHelp));
}

BOOL CDownloadProperties_IntegrityPage::OnApply() 
{
	fsDownload_Properties dp;

	if (m_pvDlds->size () == 1 && m_wndAlgorithm.GetCurSel () == CB_ERR)
	{
		MessageBox (LS (L_SPECIFYINTEGRITYALGORITHM), LS (L_INPERR), MB_ICONEXCLAMATION);
		m_wndAlgorithm.SetFocus ();
		return FALSE;		
	}

	UINT u = IsDlgButtonChecked (IDC_PERFORMCHECKWHENDONE);
	if (u != BST_INDETERMINATE)
	{
		u = u == BST_CHECKED;	
		DP_SET (bCheckIntegrityWhenDone, FALSE, &u);
	}

	if (m_wndICFR.GetCurSel () != CB_ERR)
	{
		vmsIntegrityCheckFailedReaction enICFR = (vmsIntegrityCheckFailedReaction)m_wndICFR.GetCurSel ();
		DP_SET (enICFR, FALSE, &enICFR);
	}

	if (m_pvDlds->size () == 1)
	{
		fsDownload_Properties *dp0 = m_pvDlds->at (0)->pMgr->GetDownloadMgr ()->GetDP ();

		SAFE_DELETE_ARRAY (dp0->pszCheckSum);
		CString str; GetDlgItemText (IDC_CHECKSUM, str);
		MakeChecksumValid (str);
		dp0->pszCheckSum = new char [str.GetLength () + 1];
		lstrcpy (dp0->pszCheckSum, str);

		dp0->dwIntegrityCheckAlgorithm = m_wndAlgorithm.GetItemData (m_wndAlgorithm.GetCurSel ());
		m_pvDlds->at (0)->pMgr->GetDownloadMgr ()->setDirty();
	}
	
	return CPropertyPage::OnApply();
}

void CDownloadProperties_IntegrityPage::MakeChecksumValid(CString &str)
{
	str.MakeLower ();

	CString str2;
	LPCSTR psz = str;
	while (*psz)
	{
		if ((*psz >= '0' && *psz <= '9') ||
				(*psz >= 'a' && *psz <= 'f') )
			str2 += *psz;

		psz++;
	}

	str = str2;
}
