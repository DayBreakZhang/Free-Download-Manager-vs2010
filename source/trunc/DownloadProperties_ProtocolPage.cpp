/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "DownloadProperties_ProtocolPage.h"
#include "DownloadProperties.h"
#include "misc.h"
#include "DownloadsWnd.h"
#include "fsDownloadMgr.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNCREATE(CDownloadProperties_ProtocolPage, CPropertyPage)

CDownloadProperties_ProtocolPage::CDownloadProperties_ProtocolPage() : CPropertyPage(CDownloadProperties_ProtocolPage::IDD)
{
	m_psp.dwFlags |= PSP_USETITLE;
	m_psp.pszTitle = LS (L_PROTOCOL);
}

CDownloadProperties_ProtocolPage::~CDownloadProperties_ProtocolPage()
{
}

void CDownloadProperties_ProtocolPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDownloadProperties_ProtocolPage)
		DDX_Control (pDX, IDC_USERAGENT, m_wndUserAgent);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDownloadProperties_ProtocolPage, CPropertyPage)
	//{{AFX_MSG_MAP(CDownloadProperties_ProtocolPage)
	ON_BN_CLICKED(IDC_BINARY, OnBinary)
	ON_BN_CLICKED(IDC_ASCII, OnAscii)
	ON_BN_CLICKED(IDC_ASCIIFOREXTS, OnAsciiforexts)
	ON_CBN_EDITCHANGE(IDC_USERAGENT, OnEditchangeUseragent)
	ON_CBN_SELCHANGE(IDC_USERAGENT, OnSelchangeUseragent)
	ON_EN_CHANGE(IDC_REFERER, OnChangeReferer)
	ON_BN_CLICKED(IDC_USEHTTP11, OnUsehttp11)
	ON_BN_CLICKED(IDC_USECOOKIE, OnUsecookie)
	ON_BN_CLICKED(IDC_USEPASSIVEMODE, OnUsepassivemode)
	ON_EN_CHANGE(IDC_ASCIIEXTS, OnChangeAsciiexts)
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_WHATISTHIS, OnWhatisthis)
	ON_WM_HELPINFO()
	ON_BN_CLICKED(IDC_DONTSENDLIST, OnDontsendlist)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

LPCSTR _ppszAgentNames [] = {
	vmsFdmAppMgr::getAppAgentNameUf (),		
	"Microsoft Internet Explorer 5.0",
	"Netscape Communicator 4.0",
	"Opera 3.6"
};

LPCSTR _ppszAgentValues [] = {
	vmsFdmAppMgr::getAppAgentName (),
	"Mozilla/4.0 (compatible; MSIE 5.0; Windows 98)",
	"Mozilla/4.05 [en] (Win95; I)",
	"Mozilla/4.0 (Windows 95;US) Opera 3.60  [en]"
};

#define DNP_OFFSET(member) ( LPBYTE (&dnp.member) - LPBYTE (&dnp) )
#define DNP_SIZEOF(member) ( sizeof (dnp.member) )
#define DNP_EQ(member, bString) DNPEntry_IsAllEqual (m_pvDlds, DNP_OFFSET (member), DNP_SIZEOF (member), bString)
#define DNP_EQ_MASK(member, mask) DNPEntry_IsAllEqual_BitMask (m_pvDlds, DNP_OFFSET (member), mask)
#define DNP_SET(member, bString, NewVal) DNPEntry_SetValue (m_pvDlds, DNP_OFFSET (member), DNP_SIZEOF (member), bString, NewVal)
#define DNP_SET_MASK(member, mask) DNPEntry_SetValue_BitMask (m_pvDlds, DNP_OFFSET (member), mask)
#define DNP_UNSET_MASK(member, mask) DNPEntry_UnsetValue_BitMask (m_pvDlds, DNP_OFFSET (member), mask)

BOOL CDownloadProperties_ProtocolPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();

	fsDownload_NetworkProperties dnp;
	fsDownload_NetworkProperties* dnp0 = m_pvDlds->at (0)->pMgr->GetDownloadMgr ()->GetDNP ();

	for (int i = 0; i < sizeof (_ppszAgentNames) / sizeof (LPCSTR); i++)
		m_wndUserAgent.AddString (_ppszAgentNames [i]);

	if (DNPEntry_IsAllEqual (m_pvDlds, DNP_OFFSET (pszAgent), 0, TRUE))
	{
		LPCSTR pszAgent = dnp0->pszAgent;
		BOOL bSelected = FALSE;

		for (int i = 0; i < sizeof (_ppszAgentValues) / sizeof (LPCSTR); i++)
		{
			if (stricmp (pszAgent, _ppszAgentValues [i]) == 0)
			{
				m_wndUserAgent.SelectString (-1, _ppszAgentNames [i]);
				bSelected = TRUE;
			}
		}

		if (bSelected == FALSE)
			m_wndUserAgent.SetWindowText (pszAgent);
	}

	if (DNPEntry_IsAllEqual (m_pvDlds, DNP_OFFSET (pszReferer), 0, TRUE))
		SetDlgItemText (IDC_REFERER, dnp0->pszReferer);

	if (DNP_EQ (bUseHttp11, FALSE))
		CheckDlgButton (IDC_USEHTTP11, dnp0->bUseHttp11 ? BST_CHECKED : BST_UNCHECKED);
	else
		CheckDlgButton (IDC_USEHTTP11, BST_INDETERMINATE);

	if (DNP_EQ (bUseCookie, FALSE))
		CheckDlgButton (IDC_USECOOKIE, dnp0->bUseCookie ? BST_CHECKED : BST_UNCHECKED);
	else
		CheckDlgButton (IDC_USEHTTP11, BST_INDETERMINATE);

	if (DNP_EQ_MASK (dwFtpFlags, FTP_USEPASSIVEMODE))
		CheckDlgButton (IDC_USEPASSIVEMODE, dnp0->dwFtpFlags & FTP_USEPASSIVEMODE ? BST_CHECKED : BST_UNCHECKED);
	else
		CheckDlgButton (IDC_USEPASSIVEMODE, BST_INDETERMINATE);

	if (DNP_EQ_MASK (dwFtpFlags, FTP_DONTSENDLIST))
		CheckDlgButton (IDC_DONTSENDLIST, dnp0->dwFtpFlags & FTP_DONTSENDLIST ? BST_CHECKED : BST_UNCHECKED);
	else
		CheckDlgButton (IDC_DONTSENDLIST, BST_INDETERMINATE);

	if (DNP_EQ (enFtpTransferType, FALSE))
	{
		UINT nChecked;

		switch (dnp0->enFtpTransferType)
		{
			case FTT_ASCII:
				nChecked = IDC_ASCII;
				break;

			case FTT_BINARY:
				nChecked = IDC_BINARY;
				break;

			default: 
				nChecked = IDC_ASCIIFOREXTS;
				break;
		}

		CheckRadioButton (IDC_BINARY, IDC_ASCIIFOREXTS, nChecked);
	}

	if (DNP_EQ (pszASCIIExts, TRUE))
		SetDlgItemText (IDC_ASCIIEXTS, dnp0->pszASCIIExts);

	m_bRefererModified = FALSE;

	UpdateEnabled ();

	ApplyLanguage ();

	return TRUE;  
	              
}

void CDownloadProperties_ProtocolPage::UpdateEnabled()
{
	GetDlgItem (IDC_ASCIIEXTS)->EnableWindow (IsDlgButtonChecked (IDC_ASCIIFOREXTS) == BST_CHECKED);
}

void CDownloadProperties_ProtocolPage::OnBinary() 
{
	UpdateEnabled ();
	SetModified ();
}

void CDownloadProperties_ProtocolPage::OnAscii() 
{
	UpdateEnabled ();
	SetModified ();
}

void CDownloadProperties_ProtocolPage::OnAsciiforexts() 
{
	UpdateEnabled ();
	SetModified ();
}

void CDownloadProperties_ProtocolPage::OnEditchangeUseragent() 
{
	SetModified ();	
}

void CDownloadProperties_ProtocolPage::OnSelchangeUseragent() 
{
	SetModified ();	
}

void CDownloadProperties_ProtocolPage::OnChangeReferer() 
{
	m_bRefererModified = TRUE;
	SetModified ();	
}

void CDownloadProperties_ProtocolPage::OnUsehttp11() 
{
	if (IsDlgButtonChecked (IDC_USEHTTP11) == BST_INDETERMINATE)
		CheckDlgButton (IDC_USEHTTP11, BST_UNCHECKED);

	SetModified ();
}

void CDownloadProperties_ProtocolPage::OnUsecookie() 
{
	if (IsDlgButtonChecked (IDC_USECOOKIE) == BST_INDETERMINATE)
		CheckDlgButton (IDC_USECOOKIE, BST_UNCHECKED);

	SetModified ();
}

void CDownloadProperties_ProtocolPage::OnUsepassivemode() 
{
	if (IsDlgButtonChecked (IDC_USEPASSIVEMODE) == BST_INDETERMINATE)
		CheckDlgButton (IDC_USEPASSIVEMODE, BST_UNCHECKED);

	SetModified ();
}

void CDownloadProperties_ProtocolPage::OnChangeAsciiexts() 
{
	SetModified ();
}

BOOL CDownloadProperties_ProtocolPage::OnApply() 
{
	fsDownload_NetworkProperties dnp;

	CString str;

	m_wndUserAgent.GetWindowText (str);
	if (str.GetLength ())
	{
		BOOL bFind = FALSE;

		for (int i = 0; i < sizeof (_ppszAgentNames) / sizeof (LPCSTR); i++)
		{
			if (str == _ppszAgentNames [i])
			{
				DNP_SET (pszAgent, TRUE, _ppszAgentValues [i]);
				bFind = TRUE;
			}
		}

		if (bFind == FALSE)
			DNP_SET (pszAgent, TRUE, str);
	}

	GetDlgItemText (IDC_REFERER, str);
	if (str.GetLength () || m_bRefererModified)
		DNP_SET (pszReferer, TRUE, str);

	UINT uChecked = IsDlgButtonChecked (IDC_USEHTTP11);
	if (uChecked != BST_INDETERMINATE)
	{
		BOOL bUse = uChecked == BST_CHECKED;
		DNP_SET (bUseHttp11, FALSE, &bUse);
	}

	uChecked = IsDlgButtonChecked (IDC_USECOOKIE);
	if (uChecked != BST_INDETERMINATE)
	{
		BOOL bUse = uChecked == BST_CHECKED;
		DNP_SET (bUseCookie, FALSE, &bUse);
	}

	uChecked = IsDlgButtonChecked (IDC_USEPASSIVEMODE);
	if (uChecked != BST_INDETERMINATE)
	{
		if (uChecked == BST_CHECKED)
			DNP_SET_MASK (dwFtpFlags, FTP_USEPASSIVEMODE);
		else
			DNP_UNSET_MASK (dwFtpFlags, FTP_USEPASSIVEMODE);
	}

	uChecked = IsDlgButtonChecked (IDC_DONTSENDLIST);
	if (uChecked != BST_INDETERMINATE)
	{
		if (uChecked == BST_CHECKED)
			DNP_SET_MASK (dwFtpFlags, FTP_DONTSENDLIST);
		else
			DNP_UNSET_MASK (dwFtpFlags, FTP_DONTSENDLIST);
	}

	fsFtpTransferType ftt;

	if (BST_CHECKED == IsDlgButtonChecked (IDC_BINARY))
	{
		ftt = FTT_BINARY;
		DNP_SET (enFtpTransferType, FALSE, &ftt);
	}
	else if (BST_CHECKED == IsDlgButtonChecked (IDC_ASCII))
	{
		ftt = FTT_ASCII;
		DNP_SET (enFtpTransferType, FALSE, &ftt);
	}
	else if (BST_CHECKED == IsDlgButtonChecked (IDC_ASCIIFOREXTS))
	{
		ftt = FTT_UNKNOWN;
		DNP_SET (enFtpTransferType, FALSE, &ftt);
		
		GetDlgItemText (IDC_ASCIIEXTS, str);

		if (str.GetLength ())
			DNP_SET (pszASCIIExts, TRUE, str);
	}

	return CPropertyPage::OnApply();
}

void CDownloadProperties_ProtocolPage::OnContextMenu(CWnd* , CPoint point) 
{
	PrepareCHMgr (point);
	_CHMgr.ShowMenu ();
}

void CDownloadProperties_ProtocolPage::OnWhatisthis() 
{
	_CHMgr.OnWT ();	
}

void CDownloadProperties_ProtocolPage::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC__IDAS, L_IDAS),
		fsDlgLngInfo (IDC__REFERER, L_REFERER),
		fsDlgLngInfo (IDC_USEHTTP11, L_USEHTTP11),
		fsDlgLngInfo (IDC_USECOOKIE, L_USECOOKIE),
		fsDlgLngInfo (IDC_USEPASSIVEMODE, L_USEPASSIVEMODE),
		fsDlgLngInfo (IDC__TRANSFERMODE, L_TRANSFERMODE),
		fsDlgLngInfo (IDC_BINARY, L_BINARY),
		fsDlgLngInfo (IDC_ASCIIFOREXTS, L_ASCIIFOR),
		fsDlgLngInfo (IDC_DONTSENDLIST, L_DONTRETRFILEDATEFROMSERV),
	};

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), 0);
}

BOOL CDownloadProperties_ProtocolPage::OnHelpInfo(HELPINFO* pHelpInfo) 
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

void CDownloadProperties_ProtocolPage::PrepareCHMgr(CPoint point)
{
	fsCtrlContextHelp aCH1 [] = {
		fsCtrlContextHelp (IDC__IDAS, LS (L_IDASHERE)),
		fsCtrlContextHelp (IDC_USERAGENT, LS (L_IDASHERE)),
		fsCtrlContextHelp (IDC__REFERER, LS (L_REFERERHERE)),
		fsCtrlContextHelp (IDC_REFERER, LS (L_REFERERHERE)),
		fsCtrlContextHelp (IDC_USEHTTP11, LS (L_USEHTTP11HERE)),
		fsCtrlContextHelp (IDC_USECOOKIE, LS (L_USECOOKIEHERE)),
		fsCtrlContextHelp (IDC_USEPASSIVEMODE, LS (L_USEPASSIVEMODEHERE)),
		fsCtrlContextHelp (IDC_BINARY, LS (L_BINARYHERE)),
		fsCtrlContextHelp (IDC_ASCII, LS (L_ASCIIHERE)),
		fsCtrlContextHelp (IDC_ASCIIFOREXTS, LS (L_ASCIIFORHERE)),
		fsCtrlContextHelp (IDC_DONTSENDLIST, LS (L_DONTRETRFILEDATEFROMSERV_HERE)),
	};

    static fsCtrlContextHelp aCH [sizeof (aCH1) / sizeof (fsCtrlContextHelp)];
	CopyMemory (aCH, aCH1, sizeof (aCH));

	_CHMgr.PrepareContextMenu (this, point, aCH, sizeof (aCH) / sizeof (fsCtrlContextHelp));
}

void CDownloadProperties_ProtocolPage::OnDontsendlist() 
{
	if (IsDlgButtonChecked (IDC_DONTSENDLIST) == BST_INDETERMINATE)
		CheckDlgButton (IDC_DONTSENDLIST, BST_UNCHECKED);

	SetModified ();	
}
