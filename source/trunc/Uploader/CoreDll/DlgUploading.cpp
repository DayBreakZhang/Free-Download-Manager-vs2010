/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "CoreDll.h"
#include "DlgUploading.h"
#include "Uploads_Tasks.h"
#include "misc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDlgUploading::CDlgUploading(CWnd* pParent )
	: CDialog(CDlgUploading::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgUploading)
	//}}AFX_DATA_INIT
	m_bDontReleaseIfStopped = false;
}

void CDlgUploading::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgUploading)
	DDX_Control(pDX, IDC_PROGRESS, m_wndProgress);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlgUploading, CDialog)
	//{{AFX_MSG_MAP(CDlgUploading)
	ON_BN_CLICKED(IDC_ABORT, OnAbort)
	ON_BN_CLICKED(IDC_PAUSE, OnPause)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_COPY, OnCopy)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CDlgUploading::OnCancel() 
{
	Release ();
}

void CDlgUploading::OnAbort() 
{
	UPLS_LIST v;
	v.push_back (m_upl);
	_UplsMgr.DeleteUploads (v);
	Release ();
}

void CDlgUploading::OnPause() 
{
	if (m_upl->pMgr->IsRunning ())
	{
		m_bDontReleaseIfStopped = true;
		m_upl->pMgr->StopUploading ();	
		SetDlgItemText (IDC_PAUSE, LS (L_RESUME));
	}
	else
	{
		m_upl->pMgr->StartUploading ();
		m_bDontReleaseIfStopped = false;
		SetDlgItemText (IDC_PAUSE, LS (L_PAUSE));
	}
}

BOOL CDlgUploading::OnInitDialog() 
{
	CDialog::OnInitDialog();

	SetIcon (LoadIcon (AfxGetResourceHandle (), MAKEINTRESOURCE (IDI_MAIN)), FALSE);

	UpdateStat (TRUE);
	
	SetTimer (1, 1000, NULL);

	ApplyLanguage ();
	
	return TRUE;  
	              
}

CDlgUploading* CDlgUploading::CreateInstance(vmsUploadSmartPtr upl, CWnd *pwndParent)
{
	AFX_MANAGE_STATE (AfxGetStaticModuleState ());

	CDlgUploading *p = new CDlgUploading;
	p->m_upl = upl;
	p->Create (IDD_UPLOADING, pwndParent);
	return p;	
}

void CDlgUploading::OnTimer(UINT nIDEvent) 
{
	if (m_bDontReleaseIfStopped == false && m_upl->pMgr->IsRunning () == FALSE)
	{
		KillTimer (nIDEvent);

		if (m_upl->pMgr->IsDone ())
		{
			
		}

		Release ();
		return;
	}

	UpdateStat ();
			
	CDialog::OnTimer(nIDEvent);
}

void CDlgUploading::Release()
{
	m_upl->dwState &= ~US_UPLOADINGDLGISSHOWN;
	delete this;
}

void CDlgUploading::UpdateStat(BOOL bForceUpdate)
{
	CString str, str2;

	
	GetDlgItemText (IDC_URL, str);
	if (str.IsEmpty ())
	{
		LPCSTR pszUrl = m_upl->pMgr->get_PackageUrl ();
		if (pszUrl && *pszUrl)
			SetDlgItemText (IDC_URL, pszUrl);
	}

	
	str = CUploads_Tasks::GetUploadText (m_upl, UTT_SIZE);
	GetDlgItemText (IDC__TOTALSIZE, str2);
	if (str != str2)
		SetDlgItemText (IDC__TOTALSIZE, str);

	
	int iPos = m_wndProgress.GetPos ();
	int iProgress = (int)m_upl->pMgr->GetProgress ();
	if (bForceUpdate || iPos != iProgress)
	{
		m_wndProgress.SetPos (iProgress);
		CString str;
		str.Format ("[%d%%] - %s", iProgress, m_upl->pMgr->get_PackageName ());
		SetWindowText (str);
	}

	
	str = CUploads_Tasks::GetUploadText (m_upl, UTT_UPLOADED);
	GetDlgItemText (IDC__UPLOADED, str2);
	if (str2 != str)
		SetDlgItemText (IDC__UPLOADED, str);

	
	str = CUploads_Tasks::GetUploadText (m_upl, UTT_SPEED);
	GetDlgItemText (IDC__SPEED, str2);
	if (str2 != str)
		SetDlgItemText (IDC__SPEED, str);

	
	str = CUploads_Tasks::GetUploadText (m_upl, UTT_TIME_REMAINING);
	GetDlgItemText (IDC__TIMELEFT, str2);
	if (str2 != str)
		SetDlgItemText (IDC__TIMELEFT, str);
}

void CDlgUploading::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC__TOTALSIZE_, L_TOTAL_SIZE, TRUE),
		fsDlgLngInfo (IDC__UPLOADED_, L_UPLOADED, TRUE),
		fsDlgLngInfo (IDC__SPEED_, L_SPEED, TRUE),
		fsDlgLngInfo (IDC__TIMELEFT_, L_TIMELEFT, TRUE),
		fsDlgLngInfo (IDC_COPY, L_COPY),
		fsDlgLngInfo (IDC_PAUSE, L_PAUSE),
		fsDlgLngInfo (IDC_ABORT, L_ABORT),
		fsDlgLngInfo (IDCANCEL, L_HIDE),
	};

	vmsMfcLngHelper::ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), 0);
}

void CDlgUploading::OnCopy() 
{
	CString str;
	GetDlgItemText (IDC_URL, str);
	vmsSetClipboardText (str);
}

