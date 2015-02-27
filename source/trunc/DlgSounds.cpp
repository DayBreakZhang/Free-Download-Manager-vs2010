/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "DlgSounds.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDlgSounds::CDlgSounds(CWnd* pParent )
	: CDialog(CDlgSounds::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgSounds)
		
	//}}AFX_DATA_INIT
}

void CDlgSounds::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgSounds)
	DDX_Control(pDX, IDC_SOUNDS, m_wndSnds);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlgSounds, CDialog)
	//{{AFX_MSG_MAP(CDlgSounds)
	ON_WM_CONTEXTMENU()
	ON_WM_HELPINFO()
	ON_COMMAND(ID_WHATISTHIS, OnWhatisthis)
	ON_NOTIFY(NM_CLICK, IDC_SOUNDS, OnClickSounds)
	ON_NOTIFY(NM_DBLCLK, IDC_SOUNDS, OnDblclkSounds)
	ON_BN_CLICKED(IDC_SETSOUND, OnSetsound)
	ON_BN_CLICKED(IDC_REMOVE, OnRemove)
	ON_BN_CLICKED(IDC_TEST, OnTest)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDlgSounds::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	CRect rc;
	m_wndSnds.GetClientRect (&rc);

	m_wndSnds.InsertColumn (0, LS (L_EVENT), LVCFMT_LEFT, rc.right / 2);
	m_wndSnds.InsertColumn (1, LS (L_SOUND), LVCFMT_LEFT, rc.right / 2 - 1);

	m_wndSnds.InsertItem (0, LS (L_DOWNLOADADDED));	
	m_wndSnds.SetItemText (0, 1, SndFile (_App.Snd_DownloadAdded ()));

	m_wndSnds.InsertItem (1, LS (L_DOWNLOADCOMPLETE));	
	m_wndSnds.SetItemText (1, 1, SndFile (_App.Snd_DownloadComplete ()));

	m_wndSnds.InsertItem (2, LS (L_DOWNLOADFAILED));	
	m_wndSnds.SetItemText (2, 1, SndFile (_App.Snd_DownloadFailed ()));

	m_wndSnds.InsertItem (3, LS (L_DIALINGSUCCEDED));	
	m_wndSnds.SetItemText (3, 1, SndFile (_App.Snd_DialingOK ()));

	m_wndSnds.InsertItem (4, LS (L_DIALINGFAILED));	
	m_wndSnds.SetItemText (4, 1, SndFile (_App.Snd_DialingFailed ()));

	m_wndSnds.InsertItem (5, LS (L_NOACTIVEDOWNLOADS));
	m_wndSnds.SetItemText (5, 1, SndFile (_App.Snd_NoActiveDownloads ()));

	ApplyLanguage ();
	UpdateEnabled ();

	return TRUE;
}

void CDlgSounds::OnContextMenu(CWnd* , CPoint point) 
{
	PrepareCHMgr (point);
	_CHMgr.ShowMenu ();	
}

BOOL CDlgSounds::OnHelpInfo(HELPINFO* pHelpInfo) 
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

void CDlgSounds::OnWhatisthis() 
{
	_CHMgr.OnWT ();	
}

void CDlgSounds::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC_SETSOUND, L_SETSOUND),
		fsDlgLngInfo (IDC_REMOVE, L_REMOVE),
		fsDlgLngInfo (IDC_TEST, L_TEST),
		fsDlgLngInfo (IDCANCEL, L_CANCEL),
	};

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), L_CUSTOMIZESOUNDS);
}

void CDlgSounds::PrepareCHMgr(CPoint point)
{
	LPCSTR pszSoundsHere = LS (L_SNDEVENTSHERE);

	CPoint pt = point;
	m_wndSnds.ScreenToClient (&pt);
	switch (m_wndSnds.HitTest (pt))
	{
		case 0:
			pszSoundsHere = LS (L_DLADDEDHERE);
			break;

		case 1:
			pszSoundsHere = LS (L_DLCOMPLETEDHERE);
			break;

		case 2:
			pszSoundsHere = LS (L_DLFAILEDHERE);
			break;

		case 3:
			pszSoundsHere = LS (L_DIALOKHERE);
			break;

		case 4:
			pszSoundsHere = LS (L_DIALFAILEDHERE);
			break;

		case 5:
			pszSoundsHere = LS (L_NOACTIVEDOWNLOADSSNDHERE);
			break;
	}

	fsCtrlContextHelp aCH1 [] = {
		fsCtrlContextHelp (IDC_SOUNDS, pszSoundsHere),
		fsCtrlContextHelp (IDC_SETSOUND, LS (L_SETSOUNDHERE)),
		fsCtrlContextHelp (IDC_REMOVE, LS (L_REMOVESOUNDHERE)),
		fsCtrlContextHelp (IDC_TEST, LS (L_TESTSOUNDHERE)),
		fsCtrlContextHelp (IDCANCEL, LS (L_DONTACCEPTCHANGES)),
		fsCtrlContextHelp (IDOK, LS (L_ACCEPTCHANGES)),
	};

    static fsCtrlContextHelp aCH [sizeof (aCH1) / sizeof (fsCtrlContextHelp)];
	CopyMemory (aCH, aCH1, sizeof (aCH));

	_CHMgr.PrepareContextMenu (this, point, aCH, sizeof (aCH) / sizeof (fsCtrlContextHelp));
}

CString CDlgSounds::SndFile(CString strSndFile)
{
	if (strSndFile == "")
		strSndFile = LS (L_NOSOUND);
	return strSndFile;
}

void CDlgSounds::UpdateEnabled()
{
	int cSel = 0;
	BOOL bNoSound = TRUE;

	cSel = m_wndSnds.GetSelectedCount ();

	if (cSel)
	{
		POSITION pos = m_wndSnds.GetFirstSelectedItemPosition ();
		while (pos)
		{
			int i = m_wndSnds.GetNextSelectedItem (pos);
			CString str = m_wndSnds.GetItemText (i, 1);
			if (str != LS (L_NOSOUND))
				bNoSound = FALSE;
		}
	}

	GetDlgItem (IDC_SETSOUND)->EnableWindow (cSel == 1);
	GetDlgItem (IDC_REMOVE)->EnableWindow (cSel && bNoSound == FALSE);
	GetDlgItem (IDC_TEST)->EnableWindow (cSel == 1 && bNoSound == FALSE);
}

void CDlgSounds::OnClickSounds(NMHDR* , LRESULT* pResult) 
{
	UpdateEnabled ();
	*pResult = 0;
}

void CDlgSounds::OnDblclkSounds(NMHDR* , LRESULT* pResult) 
{
	if (m_wndSnds.GetSelectedCount () == 0)
		return;

	OnSetsound ();
	
	*pResult = 0;
}

void CDlgSounds::OnSetsound() 
{
	CString strFilter;
	strFilter.Format ("%s (*.wav)|*.wav||", LS (L_SOUNDFILES));

	CString strFile = GetSndFile (GetCurSelSnd ());

	CFileDialog dlg (TRUE, "wav", strFile, OFN_HIDEREADONLY|OFN_NOCHANGEDIR, strFilter, this);

	if (_DlgMgr.DoModal (&dlg) == IDCANCEL)
		return;

	m_wndSnds.SetItemText (GetCurSelSnd (), 1, dlg.GetPathName ());

	UpdateEnabled ();
}

void CDlgSounds::OnRemove() 
{
	POSITION pos = m_wndSnds.GetFirstSelectedItemPosition (); 
	while (pos)
	{
		int i = m_wndSnds.GetNextSelectedItem (pos);
		m_wndSnds.SetItemText (i, 1, LS (L_NOSOUND));	
	}

	UpdateEnabled ();
}

void CDlgSounds::OnTest() 
{
	_Snds.PlaySnd (GetSndFile (GetCurSelSnd ()));
}

void CDlgSounds::OnOK() 
{
	_App.Snd_DownloadAdded (GetSndFile (0));
	_App.Snd_DownloadComplete (GetSndFile (1));
	_App.Snd_DownloadFailed (GetSndFile (2));
	_App.Snd_DialingOK (GetSndFile (3));
	_App.Snd_DialingFailed (GetSndFile (4));
	_App.Snd_NoActiveDownloads (GetSndFile (5));

	_Snds.ReadSettings ();
	
	CDialog::OnOK();
}

CString CDlgSounds::GetSndFile(int iItem)
{
	if (iItem == -1)
		return "";

	CString str = m_wndSnds.GetItemText (iItem, 1);
	if (str == LS (L_NOSOUND))
		str = "";

	return str;
}

int CDlgSounds::GetCurSelSnd()
{
	POSITION pos = m_wndSnds.GetFirstSelectedItemPosition ();
	if (pos == NULL)
		return -1;

	return m_wndSnds.GetNextSelectedItem (pos);
}
