/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "HFE_Address.h"
#include "HFEWnd.h"
#include "plugincmds.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern CHFEWnd* _pwndHFE;

CHFE_Address::CHFE_Address()
{
}

CHFE_Address::~CHFE_Address()
{
}

BEGIN_MESSAGE_MAP(CHFE_Address, CWnd)
	//{{AFX_MSG_MAP(CHFE_Address)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_PAINT()
	ON_COMMAND (ID_HFE_GO, OnHfeGo)
	ON_COMMAND (ID_HFE_BACK, OnHfeBack)
	//}}AFX_MSG_MAP

END_MESSAGE_MAP()

BOOL CHFE_Address::Create(CWnd *pParent)
{
	CRect rc (0, 0, 50, 50);

	if (FALSE == CWnd::Create (AfxRegisterWndClass (0, LoadCursor (NULL, IDC_ARROW),
		CreateSolidBrush (GetSysColor (COLOR_3DFACE)), NULL), NULL, WS_CHILD | WS_VISIBLE, rc, pParent, 0x13121))
		return FALSE;

	return TRUE;
}

int CHFE_Address::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndUrl.Create (this))
		return -1;

	
	for (int i = 0; i < _LastUrlPaths.GetRecordCount (); i++)
		m_wndUrl.AddString (_LastUrlPaths.GetRecord (i));

	m_wndUrl.SetWindowText (_LastUrlPaths.GetRecordCount () ? _LastUrlPaths.GetRecord (0) : "ftp://");
	m_wndUrl.SetReturnID (ID_HFE_GO);

	m_font.CreateFont (15, 0, 0, 0, FW_NORMAL, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, "MS Sans Serif");

	CreateBars ();
	
	return 0;
}

void CHFE_Address::OnSize(UINT , int cx, int ) 
{
	m_wndUrl.MoveWindow (60, 6, cx - 60 - 50 - 40, 20);
	m_barGo.MoveWindow (cx - 49, 5, 50, 26);
	m_barBack.MoveWindow (cx - 49 - 35, 5, 35, 23);
	m_rcUrl = CRect (60, 6, cx - 50, 8+16+2);
}

void CHFE_Address::OnPaint() 
{
	CPaintDC dc(this); 

	CRect rc;
	GetClientRect (&rc);
	rc.right = m_rcUrl.left - 1;
	rc.left = 5; rc.top = m_rcUrl.top + 4;

	dc.SetBkMode (TRANSPARENT);
	CFont *oldfont = dc.SelectObject (&m_font);
	dc.SetTextColor (GetSysColor (COLOR_WINDOWTEXT));
	dc.DrawText (LS (L_ADDRESS), -1, &rc, DT_LEFT | DT_TOP | DT_SINGLELINE);
	dc.SelectObject (oldfont);

	DrawUrlFrame (&dc);
}

void CHFE_Address::DrawUrlFrame(CDC *dc)
{
	CPen light (PS_SOLID, 1, GetSysColor (COLOR_3DHILIGHT));
	CPen dark (PS_SOLID, 1, GetSysColor (COLOR_3DSHADOW));
	CPen* oldpen = dc->SelectObject (&dark);

	CRect rc;

	GetClientRect (&rc);
	dc->SelectObject (&dark);
	dc->MoveTo (0, rc.bottom - 2);
	dc->LineTo (rc.right, rc.bottom - 2);

	dc->SelectObject (&light);
	dc->MoveTo (0, rc.bottom - 1);
	dc->LineTo (rc.right, rc.bottom - 1);

	dc->SelectObject (oldpen);
}

void CHFE_Address::OnHfeGo() 
{
	HfeGo ();
}

LPCSTR CHFE_Address::GetUrl()
{
	m_wndUrl.GetWindowText (m_strUrl);

	
	if (strnicmp (m_strUrl, "ftp.", 4) == 0)
	{
		
		CString str = "ftp://";
		str += m_strUrl;
		m_strUrl = str;
	}
	else if (strnicmp (m_strUrl, "www.", 3) == 0)	
	{
		
		CString str = "http://";
		str += m_strUrl;
		m_strUrl = str;
	}

	if (strnicmp (m_strUrl, "ftp://", 6) == 0)
	{
		if (m_strUrl.Right (1) != '/' && m_strUrl.Right (1) != '\\')
			m_strUrl += '/';
	}

	

	m_wndUrl.SetWindowText (m_strUrl);

	return m_strUrl;
}

void CHFE_Address::ApplyLanguage()
{
	Invalidate ();
}

void CHFE_Address::UpdateUrl()
{
	m_wndUrl.GetWindowText (m_strUrl);
	fsURL url;
	BOOL bIncUser = FALSE, bIncPass = FALSE;	

	if (IR_SUCCESS == url.Crack (m_strUrl))
	{
		
		bIncUser = *url.GetUserName () != 0;
		bIncPass = *url.GetPassword () != 0;
	}

	fsString strUrl;
	_pwndHFE->GetMgr ()->GetCurrentUrl (strUrl, bIncUser, bIncPass);
	if (!strUrl.IsEmpty ())
	{
		m_strUrl = strUrl;
		m_wndUrl.SetWindowText (strUrl);
	}
}

void CHFE_Address::CreateBars()
{
	CRect rcBar (0, 0, 0, 0);

	
	m_barGo.SetSizes (CSize (50, 23), CSize (16, 16));
	m_barGo.CreateEx (this, TBSTYLE_FLAT|TBSTYLE_TRANSPARENT|TBSTYLE_LIST, 
		WS_CHILD | WS_VISIBLE | CCS_NORESIZE |  CCS_TOP | CCS_NODIVIDER | CBRS_TOOLTIPS, 
		rcBar, 0x111a);
	
	
	m_imgsBarGo.Create (16, 16, ILC_COLOR24 | ILC_MASK, 1, 1);
	CBitmap bmp;
	bmp.Attach (SBMP (IDB_GO));
	m_imgsBarGo.Add (&bmp, RGB (255, 0, 255));
	m_barGo.GetToolBarCtrl ().SetImageList (&m_imgsBarGo);

	UINT uID = ID_HFE_GO;
	m_barGo.SetButtons (&uID, 1);
	
	m_barGo.SetButtonText (0, "Go");

	
	m_barBack.SetSizes (CSize (35, 23), CSize (28, 16));
	m_barBack.CreateEx (this, TBSTYLE_FLAT|TBSTYLE_TRANSPARENT,
		WS_CHILD | WS_VISIBLE | CCS_NORESIZE |  CCS_TOP | CCS_NODIVIDER | CBRS_TOOLTIPS, 
		rcBar, 0x112a);
	
	m_imgsBarBack.Create (28, 16, ILC_COLOR24 | ILC_MASK, 1, 1);
	CBitmap bmp1;
	bmp1.Attach (SBMP (IDB_BACK));
	m_imgsBarBack.Add (&bmp1, RGB (255, 0, 255));
	m_barBack.GetToolBarCtrl ().SetImageList (&m_imgsBarBack);

	m_imgsBarBack_D.Create (28, 16, ILC_COLOR24 | ILC_MASK, 1, 1);
	CBitmap bmp2;
	bmp2.Attach (SBMP (IDB_BACK_D));
	m_imgsBarBack_D.Add (&bmp2, RGB (255, 0, 255));
	m_barBack.GetToolBarCtrl ().SetDisabledImageList (&m_imgsBarBack_D);

	uID = ID_HFE_BACK;
	m_barBack.SetButtons (&uID, 1);
	m_barBack.GetToolBarCtrl ().EnableButton (ID_HFE_BACK, FALSE);
}

void CHFE_Address::PushUrl(LPCSTR pszUrl)
{
	if (m_vAddrs.size ())
		if (m_vAddrs [m_vAddrs.size () - 1] == pszUrl)
			return;

	fsURL url;
	url.Crack (m_strUrl);

	
	BOOL bUser = *url.GetUserName ();
	BOOL bPassword = bUser && *url.GetPassword ();

	url.Crack (pszUrl);

	char szUrl [10000];
	DWORD dw = sizeof (szUrl);
	fsURL url1;

	
	
	url1.Create (url.GetInternetScheme (), url.GetHostName (), url.GetPort (), 
		bUser ? url.GetUserName () : NULL, bPassword ? url.GetPassword () : NULL,
		url.GetPath (), szUrl, &dw);

	m_vAddrs.add (szUrl);
}

void CHFE_Address::OnHfeBack()
{
	CString strUrl = PopUrl ();
	if (strUrl != "")
	{
		m_wndUrl.SetWindowText (strUrl);
		HfeGo (FALSE);
	}
}

CString CHFE_Address::PopUrl()
{
	
	if (m_vAddrs.size () < 2)
		return "";

	CString strUrl = m_vAddrs [m_vAddrs.size () - 2];	
	m_vAddrs.del (m_vAddrs.size () - 1);
	return strUrl;
}

void CHFE_Address::HfeGo(BOOL bPushUrl)
{
	
	_LastUrlPaths.AddRecord (GetUrl ());

	
	m_wndUrl.ResetContent ();
	for (int i = 0; i < _LastUrlPaths.GetRecordCount (); i++)
		m_wndUrl.AddString (_LastUrlPaths.GetRecord (i));
	m_wndUrl.SetWindowText (m_strUrl);

	if (bPushUrl)
		PushUrl (m_strUrl);

	_pwndHFE->OnGo ();
}

BOOL CHFE_Address::OnNotify(WPARAM , LPARAM lParam, LRESULT *pResult)
{
	LPNMHDR nm = (LPNMHDR) lParam;

	int nID = nm->hwndFrom == m_barGo.m_hWnd ? ID_HFE_GO : ID_HFE_BACK;
 
	switch (nm->code)
	{
		case TBN_GETINFOTIPA:	
		{
			LPNMTBGETINFOTIPA inf = (LPNMTBGETINFOTIPA) nm;
			if (nID == ID_HFE_BACK)
				strcpy (inf->pszText, LS (L_BACK));
			else
				strcpy (inf->pszText, LS (L_GO));
		}
		break;
	}

	*pResult = TRUE;

	return TRUE;
}

void CHFE_Address::ClearHistory()
{
	m_wndUrl.ResetContent ();
}
