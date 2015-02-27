/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "fum.h"
#include "OptsProxyPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNCREATE(COptsProxyPage, CPropertyPage)

COptsProxyPage::COptsProxyPage() : CPropertyPage(COptsProxyPage::IDD)
{
	m_psp.dwFlags |= PSP_USETITLE;
	m_psp.pszTitle = LS (L_PROXY);
}

COptsProxyPage::~COptsProxyPage()
{
}

void COptsProxyPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COptsProxyPage)
		
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(COptsProxyPage, CPropertyPage)
	//{{AFX_MSG_MAP(COptsProxyPage)
	ON_BN_CLICKED(IDC_AUTHORIZATION, OnAuthorization)
	ON_BN_CLICKED(IDC_GETFROMIE, OnGetfromie)
	ON_BN_CLICKED(IDC_MANUALLY, OnManually)
	ON_BN_CLICKED(IDC_DONTUSEPROXY, OnDontuseproxy)
	ON_EN_CHANGE(IDC_PROXYNAME, OnChangeProxyname)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void COptsProxyPage::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC__GETFROM, L_GETFROM),
		fsDlgLngInfo (IDC_GETFROMIE, L_FROMIE),
		fsDlgLngInfo (IDC_MANUALLY, L_FROMMANUALLY),
		fsDlgLngInfo (IDC_DONTUSEPROXY, L_FROMDONTUSE),
		fsDlgLngInfo (IDC__SETTINGS, L_HTTPPROXYSETTINGS),
		fsDlgLngInfo (IDC__ADDRESS, L_ADDR),
		fsDlgLngInfo (IDC__PORT, L_PORT),
		fsDlgLngInfo (IDC_AUTHORIZATION, L_LOGINREQ),
		fsDlgLngInfo (IDC__USER, L_USER),
		fsDlgLngInfo (IDC__PASSWORD, L_PASSWORD),
	};

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), 0);
}

BOOL COptsProxyPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();

	fsInternetAccessTypeEx en = _App.InternetAccessType ();

	switch (en)
	{
	case IATE_NOPROXY:
		CheckDlgButton (IDC_DONTUSEPROXY, BST_CHECKED);
		break;

	case IATE_PRECONFIGPROXY:
		CheckDlgButton (IDC_GETFROMIE, BST_CHECKED);
		break;

	case IATE_MANUALPROXY:
		CheckDlgButton (IDC_MANUALLY, BST_CHECKED);
		break;
	}

	CString strAddr; USHORT uPort;
	if (CrackProxyName (_App.HttpProxy_Name (), strAddr, uPort))
	{
		SetDlgItemText (IDC_PROXYNAME, strAddr);
		SetDlgItemInt (IDC_PORT, uPort);
	}

	CString strU = _App.HttpProxy_UserName (), 
		strP = _App.HttpProxy_Password ();
	if (strU.IsEmpty () == FALSE)
	{
		SetDlgItemText (IDC_USER, strU);
		SetDlgItemText (IDC_PASSWORD, strP);
		CheckDlgButton (IDC_AUTHORIZATION, BST_CHECKED);
	}
	
	ApplyLanguage ();
	UpdateEnabled ();
	
	return TRUE;  
	              
}

void COptsProxyPage::OnAuthorization() 
{
	UpdateEnabled ();	
}

void COptsProxyPage::UpdateEnabled()
{
	BOOL b = IsDlgButtonChecked (IDC_MANUALLY) == BST_CHECKED;

	UINT anIds [] = {
		IDC__SETTINGS, IDC__ADDRESS, IDC_PROXYNAME, IDC__PORT,
		IDC_PORT, IDC_AUTHORIZATION,
	};
	for (int i = 0; i < sizeof (anIds) / sizeof (UINT); i++)
		GetDlgItem (anIds [i])->EnableWindow (b);

	b = b && IsDlgButtonChecked (IDC_AUTHORIZATION) == BST_CHECKED;
	GetDlgItem (IDC__USER)->EnableWindow (b);
	GetDlgItem (IDC__PASSWORD)->EnableWindow (b);
	GetDlgItem (IDC_USER)->EnableWindow (b);
	GetDlgItem (IDC_PASSWORD)->EnableWindow (b);
}

void COptsProxyPage::OnGetfromie() 
{
	UpdateEnabled ();	
}

void COptsProxyPage::OnManually() 
{
	UpdateEnabled ();	
}

void COptsProxyPage::OnDontuseproxy() 
{
	UpdateEnabled ();	
}

BOOL COptsProxyPage::CrackProxyName(LPCSTR pszName, CString &strName, USHORT &uPort)
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

void COptsProxyPage::OnChangeProxyname() 
{
	SetModified ();
}

BOOL COptsProxyPage::OnApply() 
{
	if (IsDlgButtonChecked (IDC_GETFROMIE) == BST_CHECKED)
	{
		_App.InternetAccessType (IATE_PRECONFIGPROXY);
	}
	else if (IsDlgButtonChecked (IDC_DONTUSEPROXY) == BST_CHECKED)
	{
		_App.InternetAccessType (IATE_NOPROXY);
	}
	else 
	{
		CString str;
		GetDlgItemText (IDC_PROXYNAME, str);
		if (str.GetLength () == 0)
		{
			MessageBox (LS (L_ENTERPROXY), LS (L_INPERR), MB_ICONEXCLAMATION);
			return FALSE;
		}

		USHORT n = (USHORT)GetDlgItemInt (IDC_PORT);
		if (n == 0)
			n = 3128;

		CString str2; 
		str2.Format ("%s:%d", str, n);

		_App.HttpProxy_Name (str2);

		CString strU, strP;
		if (IsDlgButtonChecked (IDC_AUTHORIZATION) == BST_CHECKED)
		{
			GetDlgItemText (IDC_USER, strU);
			if (strU.IsEmpty () == FALSE)
				GetDlgItemText (IDC_PASSWORD, strP);
		}

		_App.HttpProxy_UserName (strU);
		_App.HttpProxy_Password (strP);

		_App.InternetAccessType (IATE_MANUALPROXY);
	}
	
	
	return CPropertyPage::OnApply();
}
