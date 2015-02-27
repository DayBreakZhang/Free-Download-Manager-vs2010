/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "DownloaderProperties_BtPage.h"
#include "vmsDialogHelper.h"
#include "vmsTorrentExtension.h"
#include "vmsMagnetExtension.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNCREATE(CDownloaderProperties_BtPage, CPropertyPage)

CDownloaderProperties_BtPage::CDownloaderProperties_BtPage() : CPropertyPage(CDownloaderProperties_BtPage::IDD)
{
	m_psp.dwFlags |= PSP_USETITLE;
	m_psp.pszTitle = LS (L_BITTORRENT);
	m_bDontSetModif = false;
}

CDownloaderProperties_BtPage::~CDownloaderProperties_BtPage()
{
}

void CDownloaderProperties_BtPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDownloaderProperties_BtPage)
	DDX_Control(pDX, IDC_LIMITDIM, m_wndLimitDim);
	DDX_Control(pDX, IDC_TRAFFICMODESTAB, m_tabTrafficModes);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDownloaderProperties_BtPage, CPropertyPage)
	//{{AFX_MSG_MAP(CDownloaderProperties_BtPage)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TRAFFICMODESTAB, OnSelchangeTrafficmodestab)
	ON_BN_CLICKED(IDC_LIMIT, OnLimit)
	ON_BN_CLICKED(IDC_LIMITUPLOADS, OnLimituploads)
	ON_BN_CLICKED(IDC_ENABLE, OnEnable)
	ON_EN_CHANGE(IDC_LIMITVAL, OnChangeLimitval)
	ON_CBN_SELCHANGE(IDC_LIMITDIM, OnSelchangeLimitdim)
	ON_EN_CHANGE(IDC_UPLLIMITVAL, OnChangeUpllimitval)
	ON_EN_CHANGE(IDC_PORT_FROM, OnChangePortFrom)
	ON_EN_CHANGE(IDC_PORT_TO, OnChangePortTo)
	ON_BN_CLICKED(IDC_USE_DHT, OnUseDht)
	ON_BN_CLICKED(IDC_LOCAL_PEER, OnUseLocalPeer)
	ON_BN_CLICKED(IDC_ENABLE_UPNP, OnUseUPnP)
	ON_BN_CLICKED(IDC_ENABLE_NATPMP, OnUseNATPMP)
	ON_WM_CONTEXTMENU()
	ON_WM_HELPINFO()
	ON_COMMAND(ID_WHATISTHIS, OnWhatisthis)
	ON_BN_CLICKED(IDC_ASSOCWITHTORRENT, OnAssocwithtorrent)
	ON_BN_CLICKED(IDC_ASSOCWITHMAGNET, OnAssocwithMagnet)
	ON_BN_CLICKED(IDC_DISABLE_SEEDING, OnDisableSeeding)
	ON_EN_CHANGE(IDC_MAXHALFSVAL, OnChangeMaxhalfsval)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDownloaderProperties_BtPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();

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
		IDC_MAXHALFSSPIN
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
				_App.Bittorrent_MaxHalfConnections (i)));
	}
	SetDlgItemInt (IDC_UPLLIMITVAL, 1);
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

	CheckDlgButton (IDC_DISABLE_SEEDING, 
		_App.Bittorrent_DisableSeedingByDef () ? BST_CHECKED : BST_UNCHECKED);

	ApplyLanguage ();

	UpdateEnabled ();

	if (vmsBtSupport::getBtDllVersion () < 751)
	{
		GetDlgItem (IDC_MAXHALFSVAL)->EnableWindow (FALSE);
		GetDlgItem (IDC__MAXHALFS)->EnableWindow (FALSE);
	}
	
	return TRUE;  
	              
}

BOOL CDownloaderProperties_BtPage::OnApply() 
{
	BOOL bEn = IsDlgButtonChecked (IDC_ENABLE) == BST_CHECKED;
	_App.Bittorrent_Enable (bEn);

	BOOL bTorrentAssoc = IsDlgButtonChecked (IDC_ASSOCWITHTORRENT) == BST_CHECKED;
	BOOL bMagnetAssoc = IsDlgButtonChecked (IDC_ASSOCWITHTORRENT) == BST_CHECKED;

	if (bTorrentAssoc == FALSE && vmsTorrentExtension::IsAssociatedWithUs ())
	{
		vmsTorrentExtension::AssociateWith (_App.Bittorrent_OldTorrentAssociation ());
	}
	else if (bTorrentAssoc && vmsTorrentExtension::IsAssociatedWithUs () == FALSE)
	{
		_App.Bittorrent_OldTorrentAssociation (vmsTorrentExtension::GetCurrentAssociation ());
		vmsTorrentExtension::Associate ();
	}

	if (bEn == FALSE)
		return CPropertyPage::OnApply ();

	DlgToMode (m_iOldMode);

	for (size_t i = 0; i < m_vModes.size (); i++)
	{
		_App.Bittorrent_UploadTrafficLimit (i, m_vModes [i].iUplTrafLim);
		_App.Bittorrent_UploadConnectionLimit (i, m_vModes [i].iUplConnLim);
		_App.Bittorrent_MaxHalfConnections (i, m_vModes [i].iMaxHalfConnections);
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

	_App.Bittorrent_DisableSeedingByDef (IsDlgButtonChecked (IDC_DISABLE_SEEDING) == BST_CHECKED);
	
	return CPropertyPage::OnApply();
}

void CDownloaderProperties_BtPage::OnSelchangeTrafficmodestab(NMHDR* pNMHDR, LRESULT* pResult) 
{
	DlgToMode (m_iOldMode);
	m_iOldMode = m_tabTrafficModes.GetCurSel ();
	ModeToDlg ();
	*pResult = 0;
}

void CDownloaderProperties_BtPage::ModeToDlg()
{
	m_bDontSetModif = true;

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

	SetDlgItemInt (IDC_MAXHALFSVAL, m_vModes [mode].iMaxHalfConnections);

	UpdateEnabled ();

	m_bDontSetModif = false;
}

void CDownloaderProperties_BtPage::DlgToMode(int mode)
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

	m_vModes [mode].iMaxHalfConnections = GetDlgItemInt (IDC_MAXHALFSVAL, NULL, FALSE);
}

void CDownloaderProperties_BtPage::UpdateEnabled()
{
	BOOL b = IsDlgButtonChecked (IDC_ENABLE) == BST_CHECKED;

	UINT aIDs [] = {
		IDC_TRAFFICMODESTAB, IDC_LIMIT, IDC_LIMITVAL, IDC_LIMITDIM,
		IDC_LIMITUPLOADS, IDC_UPLLIMITVAL, IDC_UPLLIMITVALSPIN,
		IDC__USEPORTS, IDC_PORT_FROM, IDC_PORT_FROM_SPIN, IDC__TO,
		IDC_PORT_TO, IDC_PORT_TO_SPIN, IDC_USE_DHT, IDC_LOCAL_PEER, 
		IDC_ENABLE_UPNP, IDC_ENABLE_NATPMP
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
}

void CDownloaderProperties_BtPage::OnLimit() 
{
	SetModified ();
	UpdateEnabled ();	
}

void CDownloaderProperties_BtPage::OnLimituploads() 
{
	SetModified ();
	UpdateEnabled ();	
}

void CDownloaderProperties_BtPage::OnEnable() 
{
	SetModified ();
	UpdateEnabled ();
}

void CDownloaderProperties_BtPage::OnChangeLimitval() 
{
	if (m_bDontSetModif == false)
		SetModified ();	
}

void CDownloaderProperties_BtPage::OnSelchangeLimitdim() 
{
	if (m_bDontSetModif == false)
		SetModified ();	
}

void CDownloaderProperties_BtPage::OnChangeUpllimitval() 
{
	if (m_bDontSetModif == false)
		SetModified ();	
}

void CDownloaderProperties_BtPage::OnChangePortFrom() 
{
	SetModified ();
}

void CDownloaderProperties_BtPage::OnChangePortTo() 
{
	SetModified ();
}

void CDownloaderProperties_BtPage::OnUseDht() 
{
	SetModified ();	
}

void CDownloaderProperties_BtPage::OnUseLocalPeer(){
	SetModified ();	
}

void CDownloaderProperties_BtPage::OnUseUPnP(){
	SetModified ();	
}

void CDownloaderProperties_BtPage::OnUseNATPMP(){
	SetModified ();	
}

void CDownloaderProperties_BtPage::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC_ENABLE, L_ENABLEBTSUPPORT),
		fsDlgLngInfo (IDC_LIMIT, L_LIMIT_UPLOAD_TRAFFIC),
		fsDlgLngInfo (IDC_LIMITUPLOADS, L_LIMIT_UPLOAD_CONNECTIONS),
		fsDlgLngInfo (IDC__USEPORTS, L_USE_PORTS_IN_RANGE_FROM, TRUE),
		fsDlgLngInfo (IDC__TO, L_TO, TRUE),
		fsDlgLngInfo (IDC_USE_DHT, L_ENABLE_DHT),
		fsDlgLngInfo (IDC_ASSOCWITHTORRENT, L_ASSOCWITHTORRENT),
		fsDlgLngInfo (IDC_ASSOCWITHMAGNET, L_ASSOCWITHMAGNET),
		fsDlgLngInfo (IDC_DISABLE_SEEDING, L_DISABLE_SEEDING_BYDEF),
		fsDlgLngInfo (IDC__MAXHALFS, L_MAXHALFCONNS, TRUE),
	};

	_LngMgr.ApplyLanguage (	this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), 0);
}

void CDownloaderProperties_BtPage::OnContextMenu(CWnd* , CPoint point) 
{
	PrepareCHMgr (point);
	_CHMgr.ShowMenu ();		
}

BOOL CDownloaderProperties_BtPage::OnHelpInfo(HELPINFO* pHelpInfo) 
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

void CDownloaderProperties_BtPage::OnWhatisthis() 
{
	_CHMgr.OnWT ();	
}

void CDownloaderProperties_BtPage::PrepareCHMgr(CPoint point)
{
	fsCtrlContextHelp aCH1 [] = {
		fsCtrlContextHelp (IDC_ENABLE, LS (L_ENABLEBT_HERE)),
		fsCtrlContextHelp (IDC_LIMIT, LS (L_LIMITUPLOADTRAF_HERE)),
		fsCtrlContextHelp (IDC_LIMITVAL, LS (L_LIMITUPLOADTRAF_HERE)),
		fsCtrlContextHelp (IDC_LIMITDIM, LS (L_DIMHERE)),
		fsCtrlContextHelp (IDC_LIMITUPLOADS, LS (L_LIMITUPLOADCONNS_HERE)),
		fsCtrlContextHelp (IDC_UPLLIMITVAL, LS (L_LIMITUPLOADCONNS_HERE)),
		fsCtrlContextHelp (IDC__USEPORTS, LS (L_BT_USEPORTSINRANGE_HERE)),
		fsCtrlContextHelp (IDC_PORT_FROM, LS (L_BT_USEPORTSINRANGE_HERE)),
		fsCtrlContextHelp (IDC__TO, LS (L_BT_USEPORTSINRANGE_HERE)),
		fsCtrlContextHelp (IDC_PORT_TO, LS (L_BT_USEPORTSINRANGE_HERE)),
		fsCtrlContextHelp (IDC_USE_DHT, LS (L_ENABLEDHT_HERE)),
	};

	static fsCtrlContextHelp aCH [sizeof (aCH1) / sizeof (fsCtrlContextHelp)];
	CopyMemory (aCH, aCH1, sizeof (aCH));

	_CHMgr.PrepareContextMenu (this, point, aCH, sizeof (aCH) / sizeof (fsCtrlContextHelp));	
}

void CDownloaderProperties_BtPage::OnAssocwithtorrent() 
{
	SetModified ();	
}

void CDownloaderProperties_BtPage::OnAssocwithMagnet() 
{
	SetModified ();	
}

void CDownloaderProperties_BtPage::OnDisableSeeding() 
{
	SetModified ();	
}

void CDownloaderProperties_BtPage::OnChangeMaxhalfsval() 
{
	SetModified ();	
}
