/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "Dlg_SpreadHelp_LinkCode.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define IMGT_DRAW		2 

#define IMGT_EXIT		4

CDlg_SpreadHelp_LinkCode::CDlg_SpreadHelp_LinkCode(CWnd* pParent )
	: CDialog(CDlg_SpreadHelp_LinkCode::IDD, pParent)
{
	m_iCurrentFrame = 0;
	m_bRunning = FALSE;
	m_dwThrJob = 0;
}

void CDlg_SpreadHelp_LinkCode::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_SpreadHelp_LinkCode)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlg_SpreadHelp_LinkCode, CDialog)
	//{{AFX_MSG_MAP(CDlg_SpreadHelp_LinkCode)
	ON_WM_TIMER()
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_COPYTOCLIPBOARD, OnCopytoclipboard)
	ON_BN_CLICKED(IDC_MOREEXAMPLES, OnMoreexamples)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDlg_SpreadHelp_LinkCode::OnInitDialog() 
{
	CDialog::OnInitDialog();

	m_bRunning = TRUE;

	m_fntFDM.CreateFont (15, 0, 0, 0, FW_NORMAL, 0, TRUE, 0, DEFAULT_CHARSET,
		0, 0, 0, 0, "MS Sans Serif");

	m_bRunning = TRUE;
	m_dwThrJob = IMGT_DRAW;
	m_bImgLoaded = FALSE;

	DWORD dw;
	CloseHandle (
		CreateThread (NULL, 0, _threadImage, this, 0, &dw));

	while (m_bImgLoaded == FALSE)
		Sleep (10);

	SetDlgItemText (IDC_HTMLCODE, get_HTMLCode ());

	ApplyLanguage ();
	
	return TRUE;  
	              
}

void CDlg_SpreadHelp_LinkCode::OnTimer(UINT nIDEvent) 
{
	if (m_iCurrentFrame == m_img.get_FrameCount ())
		m_iCurrentFrame = 0;

	KillTimer (1);
	SetTimer (1, m_img.get_FrameDelay (m_iCurrentFrame) * 10, NULL);

	m_img.set_CurrentFrame (m_iCurrentFrame++);

	m_dwThrJob |= IMGT_DRAW;

	CDialog::OnTimer(nIDEvent);
}

void CDlg_SpreadHelp_LinkCode::OnPaint() 
{
	CDialog::OnPaint ();
	m_dwThrJob |= IMGT_DRAW;	
}

DWORD WINAPI CDlg_SpreadHelp_LinkCode::_threadImage(LPVOID lp)
{
	CoInitialize (NULL);
	CDlg_SpreadHelp_LinkCode* pThis = (CDlg_SpreadHelp_LinkCode*) lp;

	pThis->m_bRunning = TRUE;

	pThis->m_img.Load ("fdm_01.gif");
	pThis->m_bImgLoaded = TRUE;

	if (pThis->m_img.get_FrameCount ())
	{
		pThis->m_iCurrentFrame = 0;
		pThis->SetTimer (1, pThis->m_img.get_FrameDelay (0) * 10, NULL);
	}

	while ((pThis->m_dwThrJob & IMGT_EXIT) == 0)
	{
		if (pThis->m_dwThrJob & IMGT_DRAW)
		{
			if (pThis->m_img.is_Loaded ())
			{
				CRect rc;
				pThis->GetClientRect (&rc);
				CSize size = pThis->m_img.get_Size ();

				rc.top = 5;
				rc.bottom = rc.top + size.cy;

				if (rc.Width () <= size.cx)
				{
					rc.right = size.cx;	
				}
				else
				{
					int w = (rc.Width () - size.cx) / 2;
					rc.left = w;
					rc.right = w + size.cx;
				}

				CDC* dc = pThis->GetDC ();
				pThis->m_img.Draw (*dc, rc);
				pThis->ReleaseDC (dc);
			}

			pThis->m_dwThrJob &= ~IMGT_DRAW;
		}

		Sleep (50);
	}

	pThis->m_img.Free ();
	pThis->m_dwThrJob &= ~IMGT_EXIT;
	pThis->m_bRunning = FALSE;

	CoUninitialize ();

	return 0;
}

void CDlg_SpreadHelp_LinkCode::OnOK() 
{
	ShutdownThread ();
	CDialog::OnOK();
}

void CDlg_SpreadHelp_LinkCode::ShutdownThread()
{
	m_dwThrJob |= IMGT_EXIT;
	while (m_bRunning)
		Sleep (5);
}

HBRUSH CDlg_SpreadHelp_LinkCode::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	if (pWnd->m_hWnd == GetDlgItem (IDC__FDM)->m_hWnd)
	{
		pDC->SelectObject (m_fntFDM);
		pDC->SetTextColor (RGB (0, 0, 200));
	}
	
	
	return hbr;
}

void CDlg_SpreadHelp_LinkCode::OnCancel() 
{
	ShutdownThread ();	
	CDialog::OnCancel();
}

void CDlg_SpreadHelp_LinkCode::OnCopytoclipboard() 
{
	_ClipbrdMgr.Text (get_HTMLCode ());	
}

void CDlg_SpreadHelp_LinkCode::OnMoreexamples() 
{
	fsOpenUrlInBrowser ("http://www.freedownloadmanager.org/linktous.htm");
}

CString CDlg_SpreadHelp_LinkCode::get_HTMLCode()
{
	return "<!--Free Download Manager code//--> <A href=\"http://www.freedownloadmanager.org/\" title=\"Free Download Manager\">\
<img src=\"http://www.freedownloadmanager.org/images/fdm_01.gif\" width=\"88\" height=\"31\" border=\"0\" alt = \"Free Download Manager\" > <br>Free Download Manager </A> <!--End of Free Download Manager code//-->";
}

void CDlg_SpreadHelp_LinkCode::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC_COPYTOCLIPBOARD, L_COPYTOCLIPBOARD),
		fsDlgLngInfo (IDC_MOREEXAMPLES, L_MOREEXAMPLES),
	};

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), L_LINKHTMLCODE);
}
