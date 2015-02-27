/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "ToolBarEx.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CToolBarEx::CToolBarEx()
{
	m_cNames = 0;
}

CToolBarEx::~CToolBarEx()
{
}

BEGIN_MESSAGE_MAP(CToolBarEx, CToolBar)
	//{{AFX_MSG_MAP(CToolBarEx)
	ON_WM_RBUTTONUP()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CToolBarEx::Create(CWnd* pParent)
{
	if (!CreateEx (pParent, TBSTYLE_FLAT | TBSTYLE_TRANSPARENT 
			, 
			WS_CHILD | WS_VISIBLE | CBRS_TOOLTIPS | CBRS_ALIGN_TOP)
			)
		return FALSE;

	m_bar = &GetToolBarCtrl ();

	m_bar->SetBitmapSize (CSize (_TB_SIZE_X, _TB_SIZE_Y));

	SetSizes (CSize (_TB_SIZE_X+7, _TB_SIZE_Y+7), 
		CSize (_TB_SIZE_X, _TB_SIZE_Y));

 	if (!m_images.Create (_TB_SIZE_X, _TB_SIZE_Y, ILC_COLOR32 | ILC_MASK, 30, 5))
		return FALSE;

	m_dimages.Create (_TB_SIZE_X, _TB_SIZE_Y, ILC_COLOR32 | ILC_MASK, 30, 5);

	m_bar->SetImageList (&m_images);
	m_bar->SetDisabledImageList (&m_dimages);

	return TRUE;
}

BOOL CToolBarEx::InsertGroup(wgTButtonInfo *pButtons, CBitmap *pBitmap, CBitmap *pBmpDisabled, int cButtons)
{
	int cBitmaps = m_images.GetImageCount ();
	COLORREF clrBg;

	if (_TB_USE_ALPHA)
		clrBg = GetSysColor (COLOR_3DFACE);
	else
		clrBg = RGB (255, 0, 255); 

	m_images.Add (pBitmap, clrBg);
	m_dimages.Add (pBmpDisabled, clrBg);

	fs::list <fsTBInfo> vB;

	for (int i = 0; i < cButtons; i++)
	{
		fsTBInfo tb;

		tb.bStyle = pButtons [i].bStyle;
		tb.idCommand = pButtons [i].iIdCommand;
		tb.strToolTip = pButtons [i].pszToolTip;

		if (tb.bStyle == 0 && tb.idCommand == 0)
		{
			
			
			
			cBitmaps++;
			continue;
		}

		if (pButtons [i].pszName)
		{
			CString str;
			str.Format("%s\0", pButtons [i].pszName);
			GetToolBarCtrl().AddStrings(str);
			tb.iName = m_cNames++;
		}
		else
			tb.iName = -1;
		
		if (tb.bStyle & TBSTYLE_SEP)
			tb.iImage = 0;
		else
			tb.iImage = cBitmaps++;

		vB.add (tb);
	}

	m_vGroups.add (vB);

	return TRUE;
}

BOOL CToolBarEx::ShowGroup(int iGrp, int iWhere)
{
	if (iGrp >= m_vGroups.size ())
		return FALSE;

	fs::list <fsTBInfo> *pGroup = &m_vGroups [iGrp];

	for (int i = 0; i < pGroup->size (); i++)
	{
		fsTBInfo *tb = &pGroup->at (i);
		TBBUTTON btn;

		
		btn.dwData = iGrp;
		btn.fsState = TBSTATE_ENABLED;
		btn.fsStyle = tb->bStyle;
		
		btn.iBitmap = tb->iImage;
		btn.idCommand = tb->idCommand;
		btn.iString = tb->iName;

		GetToolBarCtrl ().InsertButton (iWhere++, &btn);
	}

	GetToolBarCtrl().AutoSize();

	UpdateSize ();

	return TRUE;
}

void CToolBarEx::HideGroup(int iGrp)
{
	int cButtons = m_bar->GetButtonCount ();
	while (cButtons--)
	{
		TBBUTTON tb;
		m_bar->GetButton (cButtons, &tb);

		if (tb.dwData == (DWORD) iGrp)
			m_bar->DeleteButton (cButtons);
	}

	UpdateSize ();
}

void CToolBarEx::UpdateSize()
{
	GetParentFrame ()->RecalcLayout ();
}

BOOL CToolBarEx::OnNotify(LPNMHDR nm)
{
	if (nm->hwndFrom != m_hWnd)
		return FALSE;

	int nID = ((LPNMTBGETINFOTIPA) nm)->iItem;
 
	fsTBInfo *tb = FindButton (nID);

	if (tb == NULL)
		return FALSE;

	switch (nm->code)
	{
		case TBN_GETINFOTIPA:
		{
			LPNMTBGETINFOTIPA inf = (LPNMTBGETINFOTIPA) nm;
			strcpy (inf->pszText, tb->strToolTip);
		}
		break;

		case TBN_GETINFOTIPW:
		{
			return FALSE;
			
		}
		break;

		default:
			return FALSE;
	}

	return TRUE;
}

CToolBarEx::fsTBInfo* CToolBarEx::FindButton(UINT nID)
{
	int cButtons = m_bar->GetButtonCount ();

	for (int i = 0; i < cButtons; i++)
 	{
		TBBUTTON bt;
 		m_bar->GetButton (i, &bt);

		if (bt.idCommand != (int)nID)
			continue;

		

 		
		fs::list <fsTBInfo> *pvGroup = &m_vGroups [bt.dwData];
 
		
		int j = 0;
 		for (j = 0; j < pvGroup->size (); j++)
 			if (pvGroup->at (j).idCommand == bt.idCommand)
 				break;	
 
 		return &pvGroup->at (j);
	}

	return NULL;
}

void CToolBarEx::UpdateGroupToolTips(int iGrp, LPCSTR *ppszTips, UINT uSize)
{
	int cTips = min ((int)uSize, m_vGroups [iGrp].size ());
	for (int i = 0; i < cTips; i++)
		m_vGroups [iGrp][i].strToolTip = ppszTips [i];
}

void CToolBarEx::OnRButtonUp(UINT nFlags, CPoint point) 
{
	
	CToolBar::OnRButtonUp(nFlags, point);
}

BOOL CToolBarEx::OnTBGetButtonInfo(NMHDR *nm)
{
	LPNMTOOLBAR nmt = (LPNMTOOLBAR) nm;
	
	
	int  i = nmt->iItem;
	
	if (i < 5)
	{
		
		
	}
	else
		return FALSE;

	

	return TRUE;
}

void CToolBarEx::AutoSize() const
{
	RECT rcTB;
	GetParent ()->GetWindowRect (&rcTB);

	int cButtons = GetToolBarCtrl ().GetButtonCount ();
	int dx = 0, dy = rcTB.bottom-rcTB.top; 
	
	for (int i = 0; i < cButtons; i++)
	{
		RECT rc;
		GetToolBarCtrl ().GetItemRect (i, &rc);
		dx += rc.right - rc.left;
		dy = max (dy, rc.bottom);
	}

	dx += 10;
	dy += 5;

	GetToolBarCtrl().SetWindowPos(0, 0, 0, dx, dy, SWP_NOZORDER|SWP_NOMOVE);
}

CImageList* CToolBarEx::get_Images()
{
	return &m_images;
}
