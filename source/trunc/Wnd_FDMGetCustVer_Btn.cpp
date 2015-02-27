/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "Wnd_FDMGetCustVer_Btn.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CWnd_FDMGetCustVer_Btn::CWnd_FDMGetCustVer_Btn()
{
	LPCSTR ppszTexts [] = {
		
		"Promote your site with Free Download Manager!",
		"Customize Free Download Manager for your site",
		"Promote your site for free",

		
		"Downloading solutions for enterprise",
		"Professional services",
		"Custom solutions based on our engine",
	};

	
	LPCSTR ppszURLs [] = {
		"http://www.freedownloadmanager.org/custom.php?id=%d",
		"http://www.freedownloadmanager.org/custom.php?id=%d",
		"http://www.freedownloadmanager.org/custom.php?id=%d",

		"http://www.freedownloadmanager.org/solutions.htm",
		"http://www.freedownloadmanager.org/solutions.htm",
		"http://www.freedownloadmanager.org/solutions.htm",
	};

	int cTexts = sizeof (ppszTexts) / sizeof (LPCSTR);
	int iText = GetTickCount () % (int)(cTexts * 1.333);
	iText %= cTexts;
	
	m_strBtnText = ppszTexts [iText];
	m_strBtnURL  = ppszURLs [iText];

	m_AffiliateID = 0;
}

CWnd_FDMGetCustVer_Btn::~CWnd_FDMGetCustVer_Btn()
{
}

BEGIN_MESSAGE_MAP(CWnd_FDMGetCustVer_Btn, CWnd)
	//{{AFX_MSG_MAP(CWnd_FDMGetCustVer_Btn)
	ON_WM_PAINT()
	ON_WM_LBUTTONUP()
	ON_WM_RBUTTONUP()
	ON_WM_DRAWITEM()
	ON_WM_MEASUREITEM()
	ON_COMMAND(ID_HIDE, OnHide)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

#define GCVB_MIN_HEIGHT			16

#define GCVB_MLINE_MIN_HEIGHT	32

BOOL CWnd_FDMGetCustVer_Btn::Create(CWnd *pwndParent)
{
	CWnd::Create (
		AfxRegisterWndClass (0, LoadCursor (AfxGetInstanceHandle (), 
					MAKEINTRESOURCE (IDC_HAND_)),
				(HBRUSH)(COLOR_3DFACE+1), NULL), 
			"", WS_CHILD|WS_VISIBLE,
			CRect (0, 0, 130, _TB_SIZE_Y > GCVB_MIN_HEIGHT ? _TB_SIZE_Y : GCVB_MIN_HEIGHT), pwndParent, 0);

	m_bmBtn.LoadBitmap (IDB_FDM_GETCVER_BTN);

	m_fntText.CreateFont (12, 0, 0, 0, FW_BOLD, 0, 0, 0, 0, 0, 0, 0, 0, "Tahoma");

	if (is_BtnCanBeMultiline () == FALSE)
		m_strBtnText.Remove ('\n');

	CalculateTextRect ();

	SetWindowPos (NULL, 0, 0, m_rcText.Width (), _TB_SIZE_Y > GCVB_MIN_HEIGHT ? _TB_SIZE_Y : GCVB_MIN_HEIGHT, SWP_NOMOVE|SWP_NOZORDER);

	return TRUE;
}

void CWnd_FDMGetCustVer_Btn::OnPaint() 
{
	CPaintDC dc(this); 

	CDC MemDC;
	MemDC.CreateCompatibleDC (&dc);

	CBitmap* bmOld = MemDC.SelectObject (&m_bmBtn);

	CRect rc = m_rcText;
	rc.right += 4;

	int btnW = rc.Width () - 4;	
	if (btnW < 126)
		btnW = 126;

	int x = 0;
	if (rc.Width () > btnW)
		x = (rc.Width () - btnW) / 2;

	dc.BitBlt (x, 0, 126, _TB_SIZE_Y > GCVB_MIN_HEIGHT ? _TB_SIZE_Y : GCVB_MIN_HEIGHT, &MemDC, 0, 0, SRCCOPY);
	btnW -= 126;

	while (btnW)
	{
		x += 100;
		int w = min (btnW, 100);
		dc.BitBlt (x, 0, w+26, _TB_SIZE_Y > GCVB_MIN_HEIGHT ? _TB_SIZE_Y : GCVB_MIN_HEIGHT, &MemDC, 105-w, 0, SRCCOPY);
		btnW -= w;
	}	

	CFont* pfntOld = dc.SelectObject (&m_fntText);

	dc.SetBkMode (TRANSPARENT);
	dc.SetTextColor (RGB (255,255,255));
	
	dc.DrawText (m_strBtnText, &m_rcText, DT_CENTER);

	dc.SelectObject (pfntOld);
	
	MemDC.SelectObject (bmOld);
}

void CWnd_FDMGetCustVer_Btn::CalculateTextRect()
{
	CDC* dc = GetDC ();
	CFont* pfntOld = dc->SelectObject (&m_fntText);

	if (is_TextMultiline () == FALSE)
	{
		if (dc->GetTextExtent (m_strBtnText).cx > 120 &&
				is_BtnCanBeMultiline ())
		{
			
			int mp = m_strBtnText.GetLength () / 2;

			
			for (int i = 0; i < mp; i++)
			{
				if (m_strBtnText [mp+i] == ' ')
					mp += i;
				else if (m_strBtnText [mp-i] == ' ')
					mp -= i;

				if (m_strBtnText [mp] == ' ')
					break;
			}

			if (m_strBtnText [mp] == ' ')
			{
				
				

				CString str;
				str = m_strBtnText.Left (mp+1);
				str += "\n";
				str += m_strBtnText.Right (m_strBtnText.GetLength ()-mp-1);
				m_strBtnText = str;
			}
		}
	}

	GetClientRect (&m_rcText);

	if (is_TextMultiline () == FALSE)
	{
		
		CSize s = dc->GetTextExtent (m_strBtnText);
		m_rcText.top = (m_rcText.Height ()-s.cy) / 2;
		m_rcText.bottom = m_rcText.top + s.cy;
		m_rcText.right = s.cx + 2*10;	
	}
	else
	{
		int cxMax = 0;
		cxMax = dc->GetTextExtent (m_strBtnText.Left (m_strBtnText.Find ('\n'))).cx;
		cxMax = max (cxMax,
			dc->GetTextExtent (m_strBtnText.Right (
					m_strBtnText.GetLength () - m_strBtnText.Find ('\n') - 1)).cx
				);

		cxMax += 10;

		if (cxMax > 200)
			cxMax = 200;

		if (cxMax > 120)
			m_rcText.right = cxMax + 8;

		int cy = dc->GetTextExtent (m_strBtnText.Left (m_strBtnText.Find ('\n'))).cy;
		cy *= 2;
		if (m_rcText.Height () > cy)
		{
			m_rcText.top = (m_rcText.Height () - cy) / 2;
			m_rcText.bottom = m_rcText.top + cy;
		}
	}

	dc->SelectObject (pfntOld);
	ReleaseDC (dc);
}

BOOL CWnd_FDMGetCustVer_Btn::is_TextMultiline()
{
	return m_strBtnText.Find ('\n') != -1;
}

void CWnd_FDMGetCustVer_Btn::set_AffiliateID(DWORD dwID)
{
	m_AffiliateID = dwID;
}

BOOL CWnd_FDMGetCustVer_Btn::is_BtnCanBeMultiline()
{
	return _TB_SIZE_Y >= GCVB_MLINE_MIN_HEIGHT;
}

void CWnd_FDMGetCustVer_Btn::OnLButtonUp(UINT nFlags, CPoint point) 
{
	CString str;
	str.Format (m_strBtnURL, m_AffiliateID);
	fsOpenUrlInBrowser (str);
	
	CWnd::OnLButtonUp(nFlags, point);
}

void CWnd_FDMGetCustVer_Btn::OnRButtonUp(UINT nFlags, CPoint point) 
{
	CMenu menu;
	menu.LoadMenu (IDM_GCV_BUTTON);
	CMenu *pPopup = menu.GetSubMenu (0);

	CPoint pt; GetCursorPos (&pt);

	m_odmenu.Attach (&menu, FALSE);

	pPopup->ModifyMenu (ID_HIDE, MF_BYCOMMAND|MF_STRING, ID_HIDE, LS (L_HIDE));

	
	pPopup->TrackPopupMenu (TPM_RIGHTBUTTON | TPM_TOPALIGN | TPM_LEFTALIGN,	pt.x, pt.y, this);

	m_odmenu.Detach ();
	menu.DestroyMenu ();
	
	CWnd::OnRButtonUp(nFlags, point);
}

void CWnd_FDMGetCustVer_Btn::OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	m_odmenu.OnDrawItem (lpDrawItemStruct);
}

void CWnd_FDMGetCustVer_Btn::OnMeasureItem(int nIDCtl, LPMEASUREITEMSTRUCT lpMeasureItemStruct) 
{
	m_odmenu.OnMeasureItem (lpMeasureItemStruct);
}

void CWnd_FDMGetCustVer_Btn::OnHide() 
{
	_App.View_GCVButton (FALSE);
	ShowWindow (SW_HIDE);
	GetParentFrame ()->RecalcLayout ();
}
