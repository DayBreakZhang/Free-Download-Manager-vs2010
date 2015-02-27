/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "DlgVidMan.h"
#include "Downloads_VideoPreview.h"
#include "plugincmds.h"
#include "vmsLogger.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDlgVidMan::CDlgVidMan(CWnd* pParent )
	: CDialog(CDlgVidMan::IDD, pParent)
{
	m_bMute = FALSE;
	m_bInFVDownloads = FALSE;
}

void CDlgVidMan::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgVidMan)
	DDX_Control(pDX, IDC_VOLUME, m_wndVol);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlgVidMan, CDialog)
	//{{AFX_MSG_MAP(CDlgVidMan)
	ON_WM_CTLCOLOR()
	ON_COMMAND(ID_DLD_VID_PLAY, OnPlay)
	ON_COMMAND(ID_DLD_VID_PAUSE, OnPause)
	ON_COMMAND(ID_DLD_VID_STOP, OnStop)
	ON_COMMAND(ID_DLD_VID_MUTE, OnMute)
	ON_WM_HSCROLL()
	ON_WM_SIZE()
	ON_BN_CLICKED(IDC_CONVERT, OnConvert)
	ON_BN_CLICKED(IDC_SWITCH_AUTO, OnSwitchAuto)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

HBRUSH CDlgVidMan::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = m_brClrWindow;
	pDC->SetBkMode (TRANSPARENT);
	if (GetDlgItem (IDC__FILENAME)->m_hWnd == pWnd->m_hWnd)
		SelectObject (pDC->m_hDC, m_fntBold);	
	return hbr;
	
}

BOOL CDlgVidMan::OnInitDialog() 
{
	CDialog::OnInitDialog();

	m_wndVol.SetRange (0, 100);
	m_wndVol.SetPos (_App.MP_Volume ());
	UpdateVolumePerc ();
	
	CreateBars ();
	Update ();

	LOGFONT lf;
	GetFont ()->GetLogFont (&lf);
	lf.lfWeight = FW_BOLD;
	m_fntBold.CreateFontIndirect (&lf);

	m_brClrWindow.CreateSolidBrush (GetSysColor (COLOR_WINDOW));

	m_bMute = _App.MP_Mute ();
	UpdateMuteImage ();

	if (m_bInFVDownloads)
	{
		GetDlgItem (IDC_SWITCH_AUTO)->ShowWindow (SW_HIDE);
	}
	else
	{
		if (_App.View_AutoSwitchToMediaPreview ())
			CheckDlgButton (IDC_SWITCH_AUTO, BST_CHECKED);
	}

	ApplyLanguage ();
	
	return TRUE;  
	              
}

void CDlgVidMan::CreateBars()
{
	RECT rc = {0, 0, 0, 0};

	

	m_barMan.SetSizes (CSize (23, 23), CSize (16, 16));
	m_barMan.CreateEx (this, TBSTYLE_FLAT|TBSTYLE_TRANSPARENT, 
		WS_CHILD | WS_VISIBLE | CCS_NORESIZE | CCS_TOP | CCS_NODIVIDER | CBRS_TOOLTIPS,
		CRect (0,0,0,0), 0x10ff);

	m_imgMan.Create (16, 16, ILC_COLOR24 | ILC_MASK, 3, 1);
	CBitmap bmp;
	bmp.Attach (SBMP (IDB_VIDMAN));
	m_imgMan.Add (&bmp, RGB (255, 0, 255));
	m_barMan.GetToolBarCtrl ().SetImageList (&m_imgMan);

	m_dimgMan.Create (16, 16, ILC_COLOR24 | ILC_MASK, 3, 1);
	CBitmap bmp1;
	bmp1.Attach (SBMP (IDB_VIDMAN_D));
	m_dimgMan.Add (&bmp1, RGB (255, 0, 255));
	m_barMan.GetToolBarCtrl ().SetDisabledImageList (&m_dimgMan);

	UINT uIDs [] = {
		ID_DLD_VID_PLAY, ID_DLD_VID_STOP
	};
	m_barMan.SetButtons (uIDs, sizeof (uIDs) / sizeof (UINT));

	GetDlgItem (IDC__TOOL)->GetWindowRect (&rc);
	GetDlgItem (IDC__TOOL)->ShowWindow (SW_HIDE);
	ScreenToClient (&rc);
	m_barMan.MoveWindow (rc.left, rc.top, rc.right-rc.left, 25);

	
	m_barMute.SetSizes (CSize (23, 23), CSize (16, 16));
	m_barMute.CreateEx (this, TBSTYLE_FLAT|TBSTYLE_TRANSPARENT, 
		WS_CHILD | WS_VISIBLE | CCS_NORESIZE | CCS_TOP | CCS_NODIVIDER | CBRS_TOOLTIPS);

	m_imgMute.Create (16, 16, ILC_COLOR24 | ILC_MASK, 2, 1);
	CBitmap bmp2;
	bmp2.Attach (SBMP(IDB_MUTE));
	m_imgMute.Add (&bmp2, RGB (255, 0, 255));
	m_barMute.GetToolBarCtrl ().SetImageList (&m_imgMute);

	UINT uID = ID_DLD_VID_MUTE;
	m_barMute.SetButtons (&uID, 1);

	GetDlgItem (IDC__MUTE)->GetWindowRect (&rc);
	GetDlgItem (IDC__MUTE)->ShowWindow (SW_HIDE);
	ScreenToClient (&rc);
	m_barMute.MoveWindow (rc.left, rc.top, rc.right-rc.left, 25);
}

void CDlgVidMan::UpdateEnabled()
{
	vmsDownloadSmartPtr dld = m_parent->Get_ActiveDownload ();
	GetDlgItem (IDC_CONVERT)->EnableWindow (dld != NULL && dld->pMgr->IsDone ());

	m_wndVol.EnableWindow (m_parent->IsMuteAvail ());
}

void CDlgVidMan::Update()
{
	try
	{
		if (IsWindowVisible () == FALSE)
			return;

		BOOL bPlaying = m_parent->IsPlaying ();

		UINT nIdNow, nStyle; int iImage;
		m_barMan.GetButtonInfo (0, nIdNow, nStyle, iImage);
		UINT nIdReq = bPlaying ? ID_DLD_VID_PAUSE : ID_DLD_VID_PLAY;
		if (nIdNow != nIdReq)
			m_barMan.SetButtonInfo (0, nIdReq, nStyle, bPlaying ? 2 : 0);

		SetDlgItemText (IDC__FILENAME, m_parent->Get_FileName ());

		char szDim [100];
		CString str;
		UINT64 u;
		float val;

		u = m_parent->Get_FileSize ();
		if (u)
		{
			if (u == _UI64_MAX)
				str = "?";
			else
			{
				BytesToXBytes (u, &val, szDim);
				str.Format ("%.*g %s", val > 999 ? 4 : 3, val, szDim);
			}
		}
		else
			str = "";
		SetDlgItemText (IDC__SIZEVAL, str);

		u = m_parent->Get_AvailFileSize ();
		if (u || m_parent->Get_FileSize ())
		{
			BytesToXBytes (u, &val, szDim);
			str.Format ("%.*g %s", val > 999 ? 4 : 3, val, szDim);
		}
		else
			str = "";
		SetDlgItemText (IDC__SIZEAVAILVAL, str);

		SetDlgItemText (IDC__DURATIONVAL, m_parent->GetDuration ());

		UpdateEnabled ();
	}
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("CDlgVidMan::Update " + tstring(ex.what()));
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("CDlgVidMan::Update unknown exception");
	}
}

void CDlgVidMan::OnPlay() 
{
	if (m_parent->IsPlaying ())
		m_parent->Pause ();
	else
		m_parent->Play ();

	Update ();
}

void CDlgVidMan::OnPause() 
{
	m_parent->Pause ();	
	Update ();
}

void CDlgVidMan::OnStop() 
{
	m_parent->Stop ();
	Update ();
}

void CDlgVidMan::OnMute() 
{
	if (m_bMute)
	{
		

		m_bMute = FALSE;
		UpdateMuteImage ();

		if (m_wndVol.GetPos () == 0)
			m_wndVol.SetPos (20);
		ApplyVolume ();
	}
	else
	{
		

		m_parent->Set_Volume (-10000);
		m_bMute = TRUE;
		UpdateMuteImage ();
	}
}

void CDlgVidMan::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	if (pScrollBar->m_hWnd == m_wndVol.m_hWnd)
	{
		if (m_bMute && m_wndVol.GetPos ())
		{
			m_bMute = FALSE;
			UpdateMuteImage ();
		}

		ApplyVolume ();
		UpdateVolumePerc ();

		if (nSBCode == SB_ENDSCROLL && m_wndVol.GetPos () == 0)
			OnMute ();
	}
	
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CDlgVidMan::ApplyVolume()
{
	m_parent->Set_Volume (m_wndVol.GetPos () * 50 - 5000);
}

void CDlgVidMan::ApplyVolumeSettings()
{
	if (m_bMute)
		m_parent->Set_Volume (-10000);
	else
		ApplyVolume ();
}

void CDlgVidMan::UpdateVolumePerc()
{
	CString str;
	str.Format ("%d%%", m_wndVol.GetPos ());
	SetDlgItemText (IDC__VOLPERC, str);
}

void CDlgVidMan::UpdateCommand(UINT nID, BOOL *pbEnabled, BOOL *pbChecked)
{
	BOOL bHasDld = m_parent->Get_ActiveDownload () != NULL;
	BOOL bPlaying = m_parent->IsPlaying () || m_parent->IsPaused ();

	*pbChecked = FALSE;

	switch (nID)
	{
		case ID_DLD_VID_PAUSE:
			*pbEnabled = bHasDld && bPlaying && m_parent->IsPauseAvail ();
			break;

		case ID_DLD_VID_PLAY:
			*pbEnabled = bHasDld;
			break;

		case ID_DLD_VID_STOP:
			*pbEnabled = bHasDld && bPlaying;
			break;

		case ID_DLD_VID_MUTE:
			*pbEnabled = m_parent->IsMuteAvail ();
			*pbChecked = m_bMute;
			break;
	}
}

void CDlgVidMan::UpdateMuteImage()
{
	m_barMute.SetButtonInfo (0, ID_DLD_VID_MUTE, TBBS_BUTTON,
		m_bMute ? 1 : 0);
}

void CDlgVidMan::SaveSettings()
{
	_App.MP_Mute (m_bMute);
	_App.MP_Volume (m_wndVol.GetPos ());
}

BOOL CDlgVidMan::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult) 
{
	LPNMHDR nm = (LPNMHDR) lParam;

	int nID = 0;

	if (nm->code == TBN_GETINFOTIPA)
	{
		if (nm->hwndFrom == m_barMute.m_hWnd)
			nID = ID_DLD_VID_MUTE;
		else if (nm->hwndFrom == m_barMan.m_hWnd)
			nID = ((LPNMTBGETINFOTIPA) nm)->iItem;
	}

	if (nID == 0)
		return CDialog::OnNotify(wParam, lParam, pResult);
 
	switch (nm->code)
	{
		case TBN_GETINFOTIPA:	
		{
			LPNMTBGETINFOTIPA inf = (LPNMTBGETINFOTIPA) nm;
			
			switch (nID)
			{
				case ID_DLD_VID_MUTE:
					strcpy (inf->pszText, LS (L_MUTE));
					break;

				case ID_DLD_VID_PLAY:
					strcpy (inf->pszText, LS (L_PLAY));
					break;

				case ID_DLD_VID_PAUSE:
					strcpy (inf->pszText, LS (L_PAUSE));
					break;

				case ID_DLD_VID_STOP:
					strcpy (inf->pszText, LS (L_STOP));
					break;

			}
		}
		break;
	}

	*pResult = TRUE;

	return TRUE;
}

void CDlgVidMan::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
	
	
}

void CDlgVidMan::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC__MEDIAINFO, L_MEDIAINFO),
		fsDlgLngInfo (IDC__SIZE, L_DLGSIZE),
		fsDlgLngInfo (IDC__SIZEAVAIL, L_DLGAVAILABLE),
		fsDlgLngInfo (IDC__VOLUME, L_DLGVOLUME),
		fsDlgLngInfo (IDC__DURATION, L_DLGDURATION),
		fsDlgLngInfo (IDC_CONVERT, L_CONVERT),
		fsDlgLngInfo (IDC_SWITCH_AUTO, L_SWITCH_TO_TAB_AUTO),
	};

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), 0);
}

void CDlgVidMan::OnConvert() 
{
	if (_AppMgr.IsMediaFeaturesInstalled () == FALSE)
	{
		_AppMgr.ShowInstallMediaFeaturesMessage ();
		return;
	}

	vmsDownloadSmartPtr dld = m_parent->Get_ActiveDownload ();
	if (dld != NULL)
		_MediaConvertMgr.ConvertMediaFile (dld, MCM_OS_SHOW_OPTIONS_UI);
}

void CDlgVidMan::Convert()
{
	PostMessage (WM_COMMAND, IDC_CONVERT); 
}

void CDlgVidMan::OnSwitchAuto() 
{
	_App.View_AutoSwitchToMediaPreview (
		IsDlgButtonChecked (IDC_SWITCH_AUTO) == BST_CHECKED);
}

