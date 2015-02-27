/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "fdm.h"
#include "Dlg_Options_Downloads_Bittorrent.h"
#include "vmsTorrentExtension.h"
#include "vmsMagnetExtension.h"
#include "vmsDialogHelper.h"
#include "vistafx/vistafx.h"
#include "vmsFdmUtils.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDlg_Options_Downloads_Bittorrent::CDlg_Options_Downloads_Bittorrent(CWnd* pParent )
	: CDlg_Options_Page(CDlg_Options_Downloads_Bittorrent::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_Options_Downloads_Bittorrent)
		
	//}}AFX_DATA_INIT
}

void CDlg_Options_Downloads_Bittorrent::DoDataExchange(CDataExchange* pDX)
{
	CDlg_Options_Page::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_Options_Downloads_Bittorrent)
	DDX_Control(pDX, IDC_LIMITDIM, m_wndLimitDim);
	DDX_Control(pDX, IDC_TRAFFICMODESTAB, m_tabTrafficModes);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlg_Options_Downloads_Bittorrent, CDlg_Options_Page)
	//{{AFX_MSG_MAP(CDlg_Options_Downloads_Bittorrent)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TRAFFICMODESTAB, OnSelchangeTrafficmodestab)
	ON_BN_CLICKED(IDC_LIMIT, OnLimit)
	ON_BN_CLICKED(IDC_LIMITUPLOADS, OnLimituploads)
	ON_BN_CLICKED(IDC_ENABLE, OnEnable)
	ON_BN_CLICKED(IDC_LIMITCONNS, OnLimitconns)
	ON_BN_CLICKED(IDC_ASSOCWITHTORRENT, OnAssocwithtorrent)
	ON_BN_CLICKED(IDC_ASSOCWITHMAGNET, OnAssocwithMagnet)
	ON_EN_CHANGE(IDC_CONNSLIMITVAL, OnChangeConnslimitval)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDlg_Options_Downloads_Bittorrent::OnInitDialog() 
{
	CDlg_Options_Page::OnInitDialog();
	
	m_tabTrafficModes.InsertItem (0, LS (L_LIGHT));
	m_tabTrafficModes.InsertItem (1, LS (L_MEDIUM));
	m_tabTrafficModes.InsertItem (2, LS (L_HEAVY));
	m_iOldMode = 0;
	
	CString str;
	str.Format ("%s/%s", LS (L_B), LS (L_S)); m_wndLimitDim.AddString (str);
	str.Format ("%s/%s", LS (L_KB), LS (L_S)); m_wndLimitDim.AddString (str);
	str.Format ("%s/%s", LS (L_MB), LS (L_S)); m_wndLimitDim.AddString (str);
	m_wndLimitDim.SetCurSel (0);
	
	UINT aSpinIds [] = {
		IDC_UPLLIMITVALSPIN, IDC_PORT_FROM_SPIN, IDC_PORT_TO_SPIN,
		IDC_MAXHALFSSPIN, IDC_CONNSLIMITVALSPIN,
	};
	int i = 0;
	for (i = 0; i < sizeof (aSpinIds) / sizeof (UINT); i++)
	{
		CSpinButtonCtrl *pSpin = (CSpinButtonCtrl*) GetDlgItem (aSpinIds [i]);
		pSpin->SetRange (1, UD_MAXVAL);
	}
	
	for (i = 0; i < 3; i++)
	{
		m_vModes.push_back (
			_inc_ModeStgs (_App.Bittorrent_UploadTrafficLimit (i), 
			_App.Bittorrent_UploadConnectionLimit (i),
			_App.Bittorrent_MaxHalfConnections (i), 
			_App.Bittorrent_MaxConnections (i)));
	}
	SetDlgItemInt (IDC_UPLLIMITVAL, 1);
	SetDlgItemInt (IDC_CONNSLIMITVAL, 1);
	ModeToDlg ();
	
	CheckDlgButton (IDC_ENABLE,
		_App.Bittorrent_Enable () ? BST_CHECKED : BST_UNCHECKED);
	
	SetDlgItemInt (IDC_PORT_FROM, _App.Bittorrent_ListenPort_From ());
	SetDlgItemInt (IDC_PORT_TO, _App.Bittorrent_ListenPort_To ());
	
	CheckDlgButton (IDC_USE_DHT,
		_App.Bittorrent_EnableDHT () ? BST_CHECKED : BST_UNCHECKED);

	CheckDlgButton (IDC_LOCAL_PEER,
		_App.Bittorrent_EnableLocalPeerDiscovery () ? BST_CHECKED : BST_UNCHECKED);

	CheckDlgButton (IDC_ENABLE_UPNP,
		_App.Bittorrent_EnableUPnP () ? BST_CHECKED : BST_UNCHECKED);

	CheckDlgButton (IDC_ENABLE_NAT_PMP,
		_App.Bittorrent_EnableNATPMP () ? BST_CHECKED : BST_UNCHECKED);

	CheckDlgButton (IDC_ASSOCWITHTORRENT, 
		vmsTorrentExtension::IsAssociatedWithUs () ? BST_CHECKED : BST_UNCHECKED);

	CheckDlgButton (IDC_ASSOCWITHMAGNET, 
		vmsMagnetExtension::IsAssociatedWithUs () ? BST_CHECKED : BST_UNCHECKED);
		
	ApplyLanguage ();
	
	UpdateEnabled ();
	
	if (vmsBtSupport::getBtDllVersion () < 751)
	{
		GetDlgItem (IDC_MAXHALFSVAL)->EnableWindow (FALSE);
		GetDlgItem (IDC__MAXHALFS)->EnableWindow (FALSE);
	}
	
	return TRUE;  
	              
}

CString CDlg_Options_Downloads_Bittorrent::get_PageTitle()
{
	return LS (L_BITTORRENT);
}

CString CDlg_Options_Downloads_Bittorrent::get_PageShortTitle()
{
	return LS (L_BITTORRENT);
}

BOOL CDlg_Options_Downloads_Bittorrent::Apply()
{
	m_tstrFdmElevateArgs = _T ("");

	if(_App.Bittorrent_Enable()) _App.View_ImportMtorrentInfo (FALSE);
	BOOL bEn = IsDlgButtonChecked (IDC_ENABLE) == BST_CHECKED;
	if (bEn && _App.View_ImportMtorrentInfo ()) {
		_App.View_ImportMtorrentInfo (FALSE);
		MessageBox (LS (L_IMPORT_MTORRENT_INFO), LS (L_INFORMATION), MB_ICONINFORMATION);
	}
	_App.Bittorrent_Enable (bEn);
	
	BOOL bAssoc = IsDlgButtonChecked (IDC_ASSOCWITHTORRENT) == BST_CHECKED;
	
	if (bAssoc == FALSE && vmsTorrentExtension::IsAssociatedWithUs ())
	{
		if (FALSE == vmsTorrentExtension::AssociateWith (_App.Bittorrent_OldTorrentAssociation ()) && 
				GetLastError () == ERROR_ACCESS_DENIED && VistaFx::IsVistaOrHigher ())
		{
			m_tstrFdmElevateArgs += _T ("-assocwithtorrent=0 ");
			setElevateRequired (true);
		}
	}
	else if (bAssoc && vmsTorrentExtension::IsAssociatedWithUs () == FALSE)
	{
		_App.Bittorrent_OldTorrentAssociation (vmsTorrentExtension::GetCurrentAssociation ());
		if (FALSE == vmsTorrentExtension::Associate () && GetLastError () == ERROR_ACCESS_DENIED && VistaFx::IsVistaOrHigher ())
		{
			m_tstrFdmElevateArgs += _T ("-assocwithtorrent=1 ");
			setElevateRequired (true);
		}
	}

	bAssoc = IsDlgButtonChecked (IDC_ASSOCWITHMAGNET) == BST_CHECKED;
	if (!vmsFdmUtils::AssociateFdmWithMagnetLinks (bAssoc) && 
			GetLastError () == ERROR_ACCESS_DENIED && VistaFx::IsVistaOrHigher ())
	{
		m_tstrFdmElevateArgs += bAssoc ? _T ("-assocwithmagnet=1 ") : _T ("-assocwithmagnet=0 ");
		setElevateRequired (true);
	}
	
	if (bEn == FALSE)
		return TRUE;
	
	DlgToMode (m_iOldMode);
	
	for (size_t i = 0; i < m_vModes.size (); i++)
	{
		_App.Bittorrent_UploadTrafficLimit (i, m_vModes [i].iUplTrafLim);
		_App.Bittorrent_UploadConnectionLimit (i, m_vModes [i].iUplConnLim);
		_App.Bittorrent_MaxHalfConnections (i, m_vModes [i].iMaxHalfConnections);
		_App.Bittorrent_MaxConnections (i, m_vModes [i].iMaxConnections);
	}
	
	int portFrom = GetDlgItemInt (IDC_PORT_FROM);
	int portTo = GetDlgItemInt (IDC_PORT_TO);
	if (portFrom > portTo)
	{
		int t = portFrom;
		portFrom = portTo;
		portTo = t;
	}
	_App.Bittorrent_ListenPort_From (portFrom);
	_App.Bittorrent_ListenPort_To (portTo);
	_BT.ApplyListenPortSettings ();
	
	_App.Bittorrent_EnableDHT (IsDlgButtonChecked (IDC_USE_DHT) == BST_CHECKED);
	_App.Bittorrent_EnableLocalPeerDiscovery (IsDlgButtonChecked (IDC_LOCAL_PEER) == BST_CHECKED);
	_App.Bittorrent_EnableUPnP (IsDlgButtonChecked (IDC_ENABLE_UPNP) == BST_CHECKED);
	_App.Bittorrent_EnableNATPMP (IsDlgButtonChecked (IDC_ENABLE_NATPMP) == BST_CHECKED);

	_BT.ApplyDHTSettings ();
	
	return TRUE;
}

void CDlg_Options_Downloads_Bittorrent::OnSelchangeTrafficmodestab(NMHDR* pNMHDR, LRESULT* pResult) 
{
	DlgToMode (m_iOldMode);
	m_iOldMode = m_tabTrafficModes.GetCurSel ();
	ModeToDlg ();
	*pResult = 0;
}

void CDlg_Options_Downloads_Bittorrent::ModeToDlg()
{
	int mode = m_tabTrafficModes.GetCurSel ();
	
	if (m_vModes [mode].iUplTrafLim != -1)
	{
		vmsDialogHelper::SetDlgBytesGroup (this, m_vModes [mode].iUplTrafLim, 
			IDC_LIMITVAL, IDC_LIMITDIM);
		CheckDlgButton (IDC_LIMIT, BST_CHECKED);
	}
	else
	{
		CheckDlgButton (IDC_LIMIT, BST_UNCHECKED);
	}
	
	if (m_vModes [mode].iUplConnLim != -1)
	{
		SetDlgItemInt (IDC_UPLLIMITVAL, m_vModes [mode].iUplConnLim);
		CheckDlgButton (IDC_LIMITUPLOADS, BST_CHECKED);
	}
	else
	{
		CheckDlgButton (IDC_LIMITUPLOADS, BST_UNCHECKED);
	}

	if (m_vModes [mode].iMaxConnections != -1)
	{
		SetDlgItemInt (IDC_CONNSLIMITVAL, m_vModes [mode].iMaxConnections);
		CheckDlgButton (IDC_LIMITCONNS, BST_CHECKED);
	}
	else
	{
		CheckDlgButton (IDC_LIMITCONNS, BST_UNCHECKED);
	}
	
	SetDlgItemInt (IDC_MAXHALFSVAL, m_vModes [mode].iMaxHalfConnections);
	
	UpdateEnabled ();
}

void CDlg_Options_Downloads_Bittorrent::DlgToMode(int mode)
{
	if (IsDlgButtonChecked (IDC_LIMIT) == BST_CHECKED)
	{
		UINT64 u;
		vmsDialogHelper::GetDlgBytesGroup (this, IDC_LIMITVAL, IDC_LIMITDIM, &u);
		m_vModes [mode].iUplTrafLim = (int)u;
	}
	else
		m_vModes [mode].iUplTrafLim = -1;
	
	if (IsDlgButtonChecked (IDC_LIMITUPLOADS) == BST_CHECKED)
		m_vModes [mode].iUplConnLim = GetDlgItemInt (IDC_UPLLIMITVAL);
	else
		m_vModes [mode].iUplConnLim = -1;

	if (IsDlgButtonChecked (IDC_LIMITCONNS) == BST_CHECKED)
		m_vModes [mode].iMaxConnections = GetDlgItemInt (IDC_CONNSLIMITVAL);
	else
		m_vModes [mode].iMaxConnections = -1;
	
	m_vModes [mode].iMaxHalfConnections = GetDlgItemInt (IDC_MAXHALFSVAL, NULL, FALSE);
}

void CDlg_Options_Downloads_Bittorrent::UpdateEnabled()
{
	BOOL b = IsDlgButtonChecked (IDC_ENABLE) == BST_CHECKED;
	
	UINT aIDs [] = {
		IDC_TRAFFICMODESTAB, IDC_LIMIT, IDC_LIMITVAL, IDC_LIMITDIM,
			IDC_LIMITUPLOADS, IDC_UPLLIMITVAL, IDC_UPLLIMITVALSPIN,
			IDC_LIMITCONNS, IDC_CONNSLIMITVAL, IDC_CONNSLIMITVALSPIN,
			IDC__USEPORTS, IDC_PORT_FROM, IDC_PORT_FROM_SPIN, IDC__TO,
			IDC_PORT_TO, IDC_PORT_TO_SPIN, IDC_USE_DHT,IDC_LOCAL_PEER,
			IDC_ENABLE_UPNP, IDC_ENABLE_NATPMP,
			IDC__MAXHALFS, IDC_MAXHALFSVAL, IDC_MAXHALFSSPIN,
	};
	for (int i = 0; i < sizeof (aIDs) / sizeof (UINT); i++)
	{
		GetDlgItem (aIDs [i])->EnableWindow (b);
	}
	
	if (b == FALSE)
		return;
	
	
	b = IsDlgButtonChecked (IDC_LIMIT) == BST_CHECKED;
	GetDlgItem (IDC_LIMITVAL)->EnableWindow (b);
	GetDlgItem (IDC_LIMITDIM)->EnableWindow (b);
	
	b = IsDlgButtonChecked (IDC_LIMITUPLOADS) == BST_CHECKED;
	GetDlgItem (IDC_UPLLIMITVAL)->EnableWindow (b);
	GetDlgItem (IDC_UPLLIMITVALSPIN)->EnableWindow (b);

	b = IsDlgButtonChecked (IDC_LIMITCONNS) == BST_CHECKED;
	GetDlgItem (IDC_CONNSLIMITVAL)->EnableWindow (b);
	GetDlgItem (IDC_CONNSLIMITVALSPIN)->EnableWindow (b);
}

void CDlg_Options_Downloads_Bittorrent::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC_ENABLE, L_ENABLEBTSUPPORT),
		fsDlgLngInfo (IDC_LIMIT, L_LIMIT_UPLOAD_TRAFFIC),
		fsDlgLngInfo (IDC_LIMITUPLOADS, L_LIMIT_UPLOAD_CONNECTIONS),
		fsDlgLngInfo (IDC_LIMITCONNS, L_LIMIT_CONNECTIONS),
		fsDlgLngInfo (IDC__USEPORTS, L_USE_PORTS_IN_RANGE_FROM, TRUE),
		fsDlgLngInfo (IDC__TO, L_TO, TRUE),
		fsDlgLngInfo (IDC_USE_DHT, L_ENABLE_DHT),
		fsDlgLngInfo (IDC_LOCAL_PEER, L_ENABLE_LOCAL_PEERS),
		fsDlgLngInfo (IDC_ENABLE_UPNP, L_ENABLE_UPNP),
		fsDlgLngInfo (IDC_ENABLE_NATPMP, L_ENABLE_NATPMP),
		fsDlgLngInfo (IDC_ASSOCWITHTORRENT, L_ASSOCWITHTORRENT),
		fsDlgLngInfo (IDC_ASSOCWITHMAGNET, L_ASSOCWITHMAGNET),
		fsDlgLngInfo (IDC__MAXHALFS, L_MAXHALFCONNS, TRUE),
	};
	
	_LngMgr.ApplyLanguage (	this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), 0);
}

void CDlg_Options_Downloads_Bittorrent::OnLimit() 
{
	UpdateEnabled ();	
}

void CDlg_Options_Downloads_Bittorrent::OnLimituploads() 
{
	UpdateEnabled ();	
}

void CDlg_Options_Downloads_Bittorrent::OnEnable() 
{
	UpdateEnabled ();	
}

void CDlg_Options_Downloads_Bittorrent::OnLimitconns() 
{
	UpdateEnabled ();	
}

void CDlg_Options_Downloads_Bittorrent::OnAssocwithtorrent()
{
	if (VistaFx::IsVistaOrHigher () && !vmsTorrentExtension::CheckAccessRights ())
	{
		bool bAssoc = IsDlgButtonChecked (IDC_ASSOCWITHTORRENT) == BST_CHECKED;
		bool bNeedElevate = false;

		if (!bAssoc && vmsTorrentExtension::IsAssociatedWithUs ())
			bNeedElevate = true;
		else if (bAssoc && !vmsTorrentExtension::IsAssociatedWithUs ())
			bNeedElevate = true;

		setElevateRequired (bNeedElevate);
	}
}

void CDlg_Options_Downloads_Bittorrent::OnAssocwithMagnet()
{
	if (VistaFx::IsVistaOrHigher () && !vmsTorrentExtension::CheckAccessRights ())
	{
		bool bAssoc = IsDlgButtonChecked (IDC_ASSOCWITHMAGNET) == BST_CHECKED;
		bool bNeedElevate = false;

		if (!bAssoc && vmsMagnetExtension::IsAssociatedWithUs ())
			bNeedElevate = true;
		else if (bAssoc && !vmsMagnetExtension::IsAssociatedWithUs ())
			bNeedElevate = true;

		setElevateRequired (bNeedElevate);
	}
}

void CDlg_Options_Downloads_Bittorrent::OnChangeConnslimitval() 
{
		
}
