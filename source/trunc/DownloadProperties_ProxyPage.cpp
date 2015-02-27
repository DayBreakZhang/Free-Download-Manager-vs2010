/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "DownloadProperties_ProxyPage.h"
#include "DownloadProperties.h"
#include "misc.h"
#include "DownloadsWnd.h"
#include "fsDownloadMgr.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNCREATE(CDownloadProperties_ProxyPage, CPropertyPage)

CDownloadProperties_ProxyPage::CDownloadProperties_ProxyPage() : CPropertyPage(CDownloadProperties_ProxyPage::IDD)
{
	m_psp.dwFlags |= PSP_USETITLE;
	m_psp.pszTitle = LS (L_PROXY);
}

CDownloadProperties_ProxyPage::~CDownloadProperties_ProxyPage()
{
}

void CDownloadProperties_ProxyPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDownloadProperties_ProxyPage)
	DDX_Control(pDX, IDC_PROTOCOLS, m_wndProtocols);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDownloadProperties_ProxyPage, CPropertyPage)
	//{{AFX_MSG_MAP(CDownloadProperties_ProxyPage)
	ON_BN_CLICKED(IDC_GETFROMIE, OnGetfromie)
	ON_BN_CLICKED(IDC_MANUALLY, OnManually)
	ON_BN_CLICKED(IDC_USESOCKS, OnUsesocks)
	ON_BN_CLICKED(IDC_DONTUSEPROXY, OnDontuseproxy)
	ON_EN_CHANGE(IDC_PROXYNAME, OnChangeProxyname)
	ON_EN_CHANGE(IDC_PORT, OnChangePort)
	ON_BN_CLICKED(IDC_AUTHORIZATION, OnAuthorization)
	ON_EN_CHANGE(IDC_USER, OnChangeUser)
	ON_EN_CHANGE(IDC_PASSWORD, OnChangePassword)
	ON_CBN_SELCHANGE(IDC_PROTOCOLS, OnSelchangeProtocols)
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_WHATISTHIS, OnWhatisthis)
	ON_WM_HELPINFO()
	ON_BN_CLICKED(IDC_USEROLLBACK, OnUserollback)
	ON_EN_CHANGE(IDC_ROLLBACKSIZE, OnChangeRollbacksize)
	ON_BN_CLICKED(IDC_FROMFIREFOX, OnFromfirefox)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

#define DNP_OFFSET(member) ( LPBYTE (&dnp.member) - LPBYTE (&dnp) )
#define DNP_SIZEOF(member) ( sizeof (dnp.member) )
#define DNP_EQ(member, bString) DNPEntry_IsAllEqual (m_pvDlds, DNP_OFFSET (member), DNP_SIZEOF (member), bString)
#define DNP_SET(member, bString, NewVal) DNPEntry_SetValue (m_pvDlds, DNP_OFFSET (member), DNP_SIZEOF (member), bString, NewVal)

BOOL CDownloadProperties_ProxyPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();

	fsDownload_NetworkProperties dnp;
	fsDownload_NetworkProperties *dnp0 = m_pvDlds->at (0)->pMgr->GetDownloadMgr ()->GetDNP ();

	UINT nChecked = 0;

	m_bIChange = TRUE;

	
	if (DNP_EQ (enAccType, FALSE))
	{
		switch (dnp0->enAccType)
		{
			case IAT_PRECONFIGPROXY:
				nChecked = IDC_GETFROMIE;
				break;

			case IAT_MANUALPROXY:
				nChecked = IDC_MANUALLY;
				break;

			case IAT_NOPROXY:
				nChecked = IDC_DONTUSEPROXY;
				break;

			case IATE_FIREFOXPROXY:
				nChecked = IDC_FROMFIREFOX;
				break;

			default:
				ASSERT (FALSE);
		}

		CheckRadioButton (IDC_GETFROMIE, IDC_DONTUSEPROXY, nChecked);
	}

	
	for (int i = m_pvDlds->size () - 1; i >= 0; i--)
	{
		vmsDownloadSmartPtr dld = m_pvDlds->at (i);

		switch (dld->pMgr->GetDownloadMgr ()->GetDNP ()->enProtocol)
		{
			case NP_HTTP:
				m_vHttp.push_back (dld);
				break;

			case NP_HTTPS:
				m_vHttps.push_back (dld);
				break;

			case NP_FTP:
				m_vFtp.push_back (dld);
				break;

			
		}
	}

	if (m_vHttp.size ())	
	{
		ProxyInfo pi;
		DLDS_LIST *pvDlds = m_pvDlds;
		m_pvDlds = &m_vHttp;	
		dnp0 = m_pvDlds->at (0)->pMgr->GetDownloadMgr ()->GetDNP ();

		if (DNP_EQ (pszProxyName, TRUE))
		{
			pi.strName = dnp0->pszProxyName;
			pi.bNameModified = TRUE;
		}

		if (DNP_EQ (pszProxyUserName, TRUE))
		{
			pi.strUser = dnp0->pszProxyUserName;
			if (pi.strUser.GetLength () == 0)
				pi.uAuthorization = BST_UNCHECKED;
			else
				pi.uAuthorization = BST_CHECKED;
		}
		else
		{
			pi.uAuthorization = *dnp0->pszProxyUserName ? BST_CHECKED : BST_UNCHECKED;
			for (int i = m_pvDlds->size () - 1; i; i--)
			{
				UINT u = *(m_pvDlds->at (i)->pMgr->GetDownloadMgr ()->GetDNP ()->pszProxyUserName) ? BST_CHECKED : BST_UNCHECKED;
				if (u != pi.uAuthorization)
				{
					pi.uAuthorization = BST_INDETERMINATE;
					break;
				}
			}
		}

		if (pi.uAuthorization == BST_CHECKED || pi.uAuthorization == BST_UNCHECKED)
			pi.bUserModified = pi.bPasswordModified = TRUE;

		if (DNP_EQ (pszProxyPassword, TRUE))
			pi.strPassword = dnp0->pszProxyPassword;
		
		m_pvDlds = pvDlds;
		m_vProxies.add (pi);	
		m_wndProtocols.AddString ("HTTP"); 
	}

	if (m_vHttps.size ())
	{
		ProxyInfo pi;
		DLDS_LIST *pvDlds = m_pvDlds;
		m_pvDlds = &m_vHttps;
		dnp0 = m_pvDlds->at (0)->pMgr->GetDownloadMgr ()->GetDNP ();

		if (DNP_EQ (pszProxyName, TRUE))
		{
			pi.strName = dnp0->pszProxyName;
			pi.bNameModified = TRUE;
		}

		if (DNP_EQ (pszProxyUserName, TRUE))
		{
			pi.strUser = dnp0->pszProxyUserName;
			if (pi.strUser.GetLength () == 0)
				pi.uAuthorization = BST_UNCHECKED;
			else
				pi.uAuthorization = BST_CHECKED;
		}
		else
		{
			pi.uAuthorization = *dnp0->pszProxyUserName ? BST_CHECKED : BST_UNCHECKED;
			for (int i = m_pvDlds->size () - 1; i; i--)
			{
				UINT u = *(m_pvDlds->at (i)->pMgr->GetDownloadMgr ()->GetDNP ()->pszProxyUserName) ? BST_CHECKED : BST_UNCHECKED;
				if (u != pi.uAuthorization)
				{
					pi.uAuthorization = BST_INDETERMINATE;
					break;
				}
			}
		}

		if (DNP_EQ (pszProxyPassword, TRUE))
			pi.strPassword = dnp0->pszProxyPassword;

		if (pi.uAuthorization == BST_CHECKED || pi.uAuthorization == BST_UNCHECKED)
			pi.bUserModified = pi.bPasswordModified = TRUE;
		
		m_pvDlds = pvDlds;
		m_vProxies.add (pi);
		m_wndProtocols.AddString ("HTTPS");
	}

	if (m_vFtp.size ())
	{
		ProxyInfo pi;
		DLDS_LIST *pvDlds = m_pvDlds;
		m_pvDlds = &m_vFtp;
		dnp0 = m_pvDlds->at (0)->pMgr->GetDownloadMgr ()->GetDNP ();

		if (DNP_EQ (pszProxyName, TRUE))
		{
			pi.strName = dnp0->pszProxyName;
			pi.bNameModified = TRUE;
		}

		if (DNP_EQ (pszProxyUserName, TRUE))
		{
			pi.strUser = dnp0->pszProxyUserName;
			if (pi.strUser.GetLength () == 0)
				pi.uAuthorization = BST_UNCHECKED;
			else
				pi.uAuthorization = BST_CHECKED;
		}
		else
		{
			pi.uAuthorization = *dnp0->pszProxyUserName ? BST_CHECKED : BST_UNCHECKED;
			for (int i = m_pvDlds->size () - 1; i; i--)
			{
				UINT u = *(m_pvDlds->at (i)->pMgr->GetDownloadMgr ()->GetDNP ()->pszProxyUserName) ? BST_CHECKED : BST_UNCHECKED;
				if (u != pi.uAuthorization)
				{
					pi.uAuthorization = BST_INDETERMINATE;
					break;
				}
			}
		}

		if (DNP_EQ (pszProxyPassword, TRUE))
			pi.strPassword = dnp0->pszProxyPassword;

		if (pi.uAuthorization == BST_CHECKED || pi.uAuthorization == BST_UNCHECKED)
			pi.bUserModified = pi.bPasswordModified = TRUE;
		
		m_pvDlds = pvDlds;
		m_vProxies.add (pi);
		m_wndProtocols.AddString ("FTP");
	}

	if (m_vHttp.size () == 0 && m_vHttps.size () == 0 && m_vFtp.size () == 0)
	{
		CheckRadioButton (IDC_GETFROMIE, IDC_DONTUSEPROXY, IDC_DONTUSEPROXY);
		GetDlgItem (IDC_GETFROMIE)->EnableWindow (FALSE);
		GetDlgItem (IDC_MANUALLY)->EnableWindow (FALSE);
		GetDlgItem (IDC_DONTUSEPROXY)->EnableWindow (FALSE);
	}

	if (DNP_EQ (wRollBackSize, FALSE))
	{
		CheckDlgButton (IDC_USEROLLBACK, dnp0->wRollBackSize ? BST_CHECKED : BST_UNCHECKED);
		if (dnp0->wRollBackSize)
			SetDlgItemInt (IDC_ROLLBACKSIZE, dnp0->wRollBackSize);
		else
			SetDlgItemInt (IDC_ROLLBACKSIZE, 3000);
	}
	else
	{
		CheckDlgButton (IDC_USEROLLBACK, BST_INDETERMINATE);
		SetDlgItemText (IDC_ROLLBACKSIZE, "");
	}

	m_wndProtocols.SetCurSel (0);
	m_iCurProtocol = 0;
	UpdatePS ();

	UpdateEnabled ();

	SetModified (FALSE);

	m_bIChange = FALSE;

	ApplyLanguage ();
	
	return TRUE;  
}

void CDownloadProperties_ProxyPage::UpdateEnabled()
{
	BOOL bSetE = IsDlgButtonChecked (IDC_MANUALLY) == BST_CHECKED;

	GetDlgItem (IDC__PROTOCOL)->EnableWindow (bSetE);
	GetDlgItem (IDC_PROTOCOLS)->EnableWindow (bSetE);
	GetDlgItem (IDC__ADDRESS)->EnableWindow (bSetE);
	GetDlgItem (IDC__PORT)->EnableWindow (bSetE);
	GetDlgItem (IDC__PROTOCOL)->EnableWindow (bSetE);
	GetDlgItem (IDC_PROXYNAME)->EnableWindow (bSetE);
	GetDlgItem (IDC_PORT)->EnableWindow (bSetE);
	GetDlgItem (IDC_AUTHORIZATION)->EnableWindow (bSetE);
	
	bSetE &= IsDlgButtonChecked (IDC_AUTHORIZATION) == BST_CHECKED;

	GetDlgItem (IDC__USER)->EnableWindow (bSetE);
	GetDlgItem (IDC__PASSWORD)->EnableWindow (bSetE);
	GetDlgItem (IDC_USER)->EnableWindow (bSetE);
	GetDlgItem (IDC_PASSWORD)->EnableWindow (bSetE);

	BOOL b = IsDlgButtonChecked (IDC_USEROLLBACK) == BST_CHECKED;
	GetDlgItem (IDC__ROLSIZE)->EnableWindow (b);
	GetDlgItem (IDC_ROLLBACKSIZE)->EnableWindow (b);
	GetDlgItem (IDC__BYTES)->EnableWindow (b);
}

void CDownloadProperties_ProxyPage::OnGetfromie() 
{
	SetModified ();
	UpdateEnabled ();
}

void CDownloadProperties_ProxyPage::OnManually() 
{
	SetModified ();
	UpdateEnabled ();	
}

void CDownloadProperties_ProxyPage::OnUsesocks() 
{
	SetModified ();
	UpdateEnabled ();	
}

void CDownloadProperties_ProxyPage::OnDontuseproxy() 
{
	SetModified ();
	UpdateEnabled ();	
}

void CDownloadProperties_ProxyPage::OnChangeProxyname() 
{
	if (m_bIChange == FALSE)
	{
		m_vProxies [m_iCurProtocol].bNameModified = TRUE;
		SetModified ();
	}
	
	CString str, strName;
	USHORT uPort;

	GetDlgItemText (IDC_PROXYNAME, str);

	
	
	
	if (str == "http:" || str == "ftp:" || str == "https:")
		return;

	if (CrackProxyName (str, strName, uPort))
		SetDlgItemInt (IDC_PORT, uPort, FALSE);

	if (strName != str)
	{
		SetDlgItemText (IDC_PROXYNAME, strName);
		GetDlgItem (IDC_PORT)->SetFocus ();
	}

}

void CDownloadProperties_ProxyPage::OnChangePort() 
{
	if (m_bIChange == FALSE)
		SetModified ();
}

void CDownloadProperties_ProxyPage::OnAuthorization() 
{
	if (IsDlgButtonChecked (IDC_AUTHORIZATION) == BST_INDETERMINATE)
		CheckDlgButton (IDC_AUTHORIZATION, BST_UNCHECKED);

	m_vProxies [m_iCurProtocol].uAuthorization = IsDlgButtonChecked (IDC_AUTHORIZATION);

	SetModified ();
	UpdateEnabled ();
}

void CDownloadProperties_ProxyPage::OnChangeUser() 
{
	if (m_bIChange == FALSE)
	{
		m_vProxies [m_iCurProtocol].bUserModified = TRUE;
		SetModified ();
	}
}

void CDownloadProperties_ProxyPage::OnChangePassword() 
{
	if (m_bIChange == FALSE)
	{
		m_vProxies [m_iCurProtocol].bPasswordModified = TRUE;
		SetModified ();
	}
}

BOOL CDownloadProperties_ProxyPage::CrackProxyName(LPCSTR pszName, CString &strName, USHORT &uPort)
{
	CHAR szName [1000];

	
	LPCSTR pszPort = strrchr (pszName, ':');

	
	if (strstr (pszName, ":/") == pszPort ||
		strstr (pszName, ":\\") == pszPort )
		pszPort = NULL;

	if (pszPort == NULL)
	{
		strName = pszName;
		return FALSE;
	}

	strcpy (szName, pszName);
	szName [pszPort - pszName] = 0;

	strName = szName;

	if (pszPort - pszName + 1 == (int) strlen (pszName))
		return FALSE;

	uPort = (USHORT) atoi (pszPort+1);

	return TRUE;
}

BOOL CDownloadProperties_ProxyPage::OnApply() 
{
	fsDownload_NetworkProperties dnp;

	if (IsDlgButtonChecked (IDC_GETFROMIE) == BST_CHECKED)
	{
		fsInternetAccessTypeEx type = IATE_PRECONFIGPROXY;
		DNP_SET (enAccType, FALSE, &type);
		DNP_SET (pszProxyName, TRUE, "");
		DNP_SET (pszProxyUserName, TRUE, "");
		DNP_SET (pszProxyPassword, TRUE, "");
	}
	else if (IsDlgButtonChecked (IDC_FROMFIREFOX) == BST_CHECKED)
	{
		fsInternetAccessTypeEx type = IATE_FIREFOXPROXY;
		DNP_SET (enAccType, FALSE, &type);
		DNP_SET (pszProxyName, TRUE, "");
		DNP_SET (pszProxyUserName, TRUE, "");
		DNP_SET (pszProxyPassword, TRUE, "");
	}
	else if (IsDlgButtonChecked (IDC_MANUALLY) == BST_CHECKED)
	{
		if (ReadPS () == FALSE)
			return FALSE;

		fsInternetAccessTypeEx type = IATE_MANUALPROXY;
		DNP_SET (enAccType, FALSE, &type);

		int i = 0;

		if (m_vHttp.size ())
			ApplyPS (&m_vHttp, &m_vProxies [i++]); 

		if (m_vHttps.size ())
			ApplyPS (&m_vHttps, &m_vProxies [i++]); 

		if (m_vFtp.size ())
			ApplyPS (&m_vFtp, &m_vProxies [i++]); 
	}
	else if (IsDlgButtonChecked (IDC_DONTUSEPROXY) == BST_CHECKED)
	{
		fsInternetAccessTypeEx type = IATE_NOPROXY;
		DNP_SET (enAccType, FALSE, &type);
		DNP_SET (pszProxyName, TRUE, "");
		DNP_SET (pszProxyUserName, TRUE, "");
		DNP_SET (pszProxyPassword, TRUE, "");
	}

	UINT u = IsDlgButtonChecked (IDC_USEROLLBACK);
	if (u == BST_CHECKED)
	{
		WORD w = (WORD)GetDlgItemInt (IDC_ROLLBACKSIZE);
		if (w == 0)
			w = 3000;
		if (w > 65000)
			w = 65000;
		DNP_SET (wRollBackSize, FALSE, &w);
	}
	else if (u == BST_UNCHECKED)
	{
		WORD w = 0;
		DNP_SET (wRollBackSize, FALSE, &w);
	}
	
	return CPropertyPage::OnApply();
}

BOOL CDownloadProperties_ProxyPage::ReadPS()
{
	UINT nErrID = 0;

	m_bIChange = TRUE;

	CString str;
	BOOL bOk;

	ProxyInfo *pi = &m_vProxies [m_iCurProtocol];

	if (pi->bNameModified)
	{
		GetDlgItemText (IDC_PROXYNAME, str);
		if (str.GetLength () == 0)
		{
			MessageBox (LS (L_ENTERPROXY), LS (L_INPERR), MB_ICONEXCLAMATION);
			nErrID = IDC_PROXYNAME;
			goto _lErr;
		}

		pi->strName = str;
		USHORT u = (USHORT) GetDlgItemInt (IDC_PORT, &bOk, FALSE);
		if (bOk == FALSE)
		{
			if (str.GetLength ())
			{
				MessageBox (LS (L_ENTERPROXYPORT), LS (L_INPERR), MB_ICONEXCLAMATION);
				nErrID = IDC_PORT;
				goto _lErr;
			}
		}
		else
		{
			if (str.GetLength () == 0)
			{
				MessageBox (LS (L_ENTERPROXY), LS (L_INPERR), MB_ICONEXCLAMATION);
				nErrID = IDC_PROXYNAME;
				goto _lErr;
			}

			str.Format (":%d", u);
			m_vProxies [m_iCurProtocol].strName += str;
		}
	}

	if (pi->uAuthorization == BST_CHECKED)
	{
		if (pi->bUserModified)
		{
			GetDlgItemText (IDC_USER, str);
			if (str.GetLength () == 0)
			{
				MessageBox (LS (L_ENTERUSER), LS (L_INPERR), MB_ICONEXCLAMATION);
				nErrID = IDC_USER;
				goto _lErr;
			}
			pi->strUser = str;
		}

		if (pi->bPasswordModified)
			GetDlgItemText (IDC_PASSWORD, pi->strPassword);
	}

	m_iCurProtocol = m_wndProtocols.GetCurSel ();
	UpdatePS ();
	m_bIChange = FALSE;
	return TRUE;

_lErr:
	m_wndProtocols.SetCurSel (m_iCurProtocol);
	CEdit *pE = (CEdit*) GetDlgItem (nErrID);
	pE->SetFocus ();
	pE->SetSel (0, -1);
	m_bIChange = FALSE;
	return FALSE;
}

void CDownloadProperties_ProxyPage::UpdatePS()
{
	CString strProxy;
	USHORT uPort;

	if (m_vProxies.size () == 0)
		return;

	if (CrackProxyName (m_vProxies [m_iCurProtocol].strName, strProxy, uPort))
		SetDlgItemInt (IDC_PORT, uPort, FALSE);
	else
		SetDlgItemText (IDC_PORT, "");

	SetDlgItemText (IDC_PROXYNAME, strProxy);

	CheckDlgButton (IDC_AUTHORIZATION, m_vProxies [m_iCurProtocol].uAuthorization);

	SetDlgItemText (IDC_USER, m_vProxies [m_iCurProtocol].strUser);
	SetDlgItemText (IDC_PASSWORD, m_vProxies [m_iCurProtocol].strPassword);

	UpdateEnabled ();
}

void CDownloadProperties_ProxyPage::ApplyPS(DLDS_LIST *pvDlds, ProxyInfo* pi)
{
	if (m_vProxies.size () == 0)
		return;

	DLDS_LIST *pvOld = m_pvDlds;
	fsDownload_NetworkProperties dnp;

	m_pvDlds = pvDlds;

	if (pi->bNameModified)
		DNP_SET (pszProxyName, TRUE, pi->strName);

	if (pi->uAuthorization == BST_UNCHECKED)
	{
		DNP_SET (pszProxyUserName, TRUE, "");
		DNP_SET (pszProxyPassword, TRUE, "");
	}
	else
	{
		if (pi->bUserModified)
			DNP_SET (pszProxyUserName, TRUE, pi->strUser);

		if (pi->bPasswordModified)
			DNP_SET (pszProxyPassword, TRUE, pi->strPassword);
	}

	m_pvDlds = pvOld;
}

void CDownloadProperties_ProxyPage::OnSelchangeProtocols() 
{
	if (m_wndProtocols.GetCurSel () != m_iCurProtocol)
		ReadPS ();
}

void CDownloadProperties_ProxyPage::OnContextMenu(CWnd* , CPoint point) 
{
	PrepareCHMgr (point);
	_CHMgr.ShowMenu ();
}

void CDownloadProperties_ProxyPage::OnWhatisthis() 
{
	_CHMgr.OnWT ();	
}

void CDownloadProperties_ProxyPage::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC__GETFROM, L_GETFROM),
		fsDlgLngInfo (IDC_GETFROMIE, L_FROMIE),
		fsDlgLngInfo (IDC_FROMFIREFOX, L_FROMFIREFOX),
		fsDlgLngInfo (IDC_MANUALLY, L_FROMMANUALLY),
		fsDlgLngInfo (IDC_DONTUSEPROXY, L_FROMDONTUSE),
		fsDlgLngInfo (IDC__SETTINGS, L_SETTINGS),
		fsDlgLngInfo (IDC__PROTOCOL, L_PROTOCOL),
		fsDlgLngInfo (IDC__ADDRESS, L_ADDR),
		fsDlgLngInfo (IDC__PORT, L_PORT),
		fsDlgLngInfo (IDC_AUTHORIZATION, L_LOGINREQ),
		fsDlgLngInfo (IDC__USER, L_USER),
		fsDlgLngInfo (IDC__PASSWORD, L_PASSWORD),
		fsDlgLngInfo (IDC_USEROLLBACK, L_USEROLLBACK),
		fsDlgLngInfo (IDC__ROLSIZE, L_ROLLBACKSIZE),
		fsDlgLngInfo (IDC__BYTES, L_BYTES),
	};

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), 0);
}

BOOL CDownloadProperties_ProxyPage::OnHelpInfo(HELPINFO* pHelpInfo) 
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

void CDownloadProperties_ProxyPage::PrepareCHMgr(CPoint point)
{
	fsCtrlContextHelp aCH1 [] = {
		fsCtrlContextHelp (IDC_GETFROMIE, LS (L_FROMIEHERE)),
		fsCtrlContextHelp (IDC_FROMFIREFOX, LS (L_FROMFIREFOX_HERE)),
		fsCtrlContextHelp (IDC_MANUALLY, LS (L_FROMMANUALHERE)),
		fsCtrlContextHelp (IDC_DONTUSEPROXY, LS (L_FROMDONTUSEHERE)),
		fsCtrlContextHelp (IDC__PROTOCOL, LS (L_PROTOCOLHERE)),
		fsCtrlContextHelp (IDC_PROTOCOLS, LS (L_PROTOCOLHERE)),
		fsCtrlContextHelp (IDC__ADDRESS, LS (L_PROXYADDRHERE)),
		fsCtrlContextHelp (IDC_PROXYNAME, LS (L_PROXYADDRHERE)),
		fsCtrlContextHelp (IDC__PORT, LS (L_PROXYPORTHERE)),
		fsCtrlContextHelp (IDC_PORT, LS (L_PROXYPORTHERE)),
		fsCtrlContextHelp (IDC_AUTHORIZATION, LS (L_PROXYLOGINHERE)),
		fsCtrlContextHelp (IDC__USER, LS (L_USERHERE)),
		fsCtrlContextHelp (IDC_USER, LS (L_USERHERE)),
		fsCtrlContextHelp (IDC__PASSWORD, LS (L_PWDHERE)),
		fsCtrlContextHelp (IDC_PASSWORD, LS (L_PWDHERE)),
		fsCtrlContextHelp (IDC_USEROLLBACK, LS (L_USEROLLBACKHERE)),
		fsCtrlContextHelp (IDC__ROLSIZE, LS (L_ROLLBACKSIZEHERE)),
		fsCtrlContextHelp (IDC_ROLLBACKSIZE, LS (L_ROLLBACKSIZEHERE)),
	};

    static fsCtrlContextHelp aCH [sizeof (aCH1) / sizeof (fsCtrlContextHelp)];
	CopyMemory (aCH, aCH1, sizeof (aCH));

	_CHMgr.PrepareContextMenu (this, point, aCH, sizeof (aCH) / sizeof (fsCtrlContextHelp));	
}

void CDownloadProperties_ProxyPage::OnUserollback() 
{
	if (IsDlgButtonChecked (IDC_USEROLLBACK) == BST_INDETERMINATE)
		CheckDlgButton (IDC_USEROLLBACK, BST_UNCHECKED);

	SetModified ();
	UpdateEnabled ();
}

void CDownloadProperties_ProxyPage::OnChangeRollbacksize() 
{
	SetModified ();
}

void CDownloadProperties_ProxyPage::OnFromfirefox() 
{
	SetModified ();
	UpdateEnabled ();
}
