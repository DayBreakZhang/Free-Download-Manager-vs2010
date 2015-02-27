/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "ColumnTreeCtrl.h"

#include <shlwapi.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#ifndef TVS_NOHSCROLL
	#error CColumnTreeCtrl requires IE 5.0 or higher; _WIN32_IE should be greater than 0x500.
#endif

static void _DotHLine(HDC hdc, LONG x, LONG y, LONG w, COLORREF cr)
{
	for (; w>0; w-=2, x+=2)
		SetPixel(hdc, x, y, cr);
}

static void _DotVLine(HDC hdc, LONG x, LONG y, LONG w, COLORREF cr)
{
	for (; w>0; w-=2, y+=2)
		SetPixel(hdc, x, y, cr);
}

IMPLEMENT_DYNAMIC(CCustomTreeChildCtrl, CTreeCtrl)

CCustomTreeChildCtrl::CCustomTreeChildCtrl()
{

#ifdef _OWNER_DRAWN_TREE 
	
	m_bkImage.hbm=NULL;
	m_bkImage.xOffsetPercent = 0;
	m_bkImage.yOffsetPercent = 0;

	
	m_imgBtns.Create (9, 9, ILC_COLOR32|ILC_MASK,2,1);
	CBitmap* pBmpBtns = CBitmap::FromHandle(LoadBitmap(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_TREEBTNS)));
	ASSERT(pBmpBtns);
	m_imgBtns.Add(pBmpBtns,RGB(255,0,255));
#endif 
}

CCustomTreeChildCtrl::~CCustomTreeChildCtrl()
{
}

BEGIN_MESSAGE_MAP(CCustomTreeChildCtrl, CTreeCtrl)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	ON_WM_VSCROLL()
	ON_WM_MOUSEWHEEL()
	ON_WM_TIMER()
	ON_WM_CREATE()
	ON_WM_KEYDOWN()
	
END_MESSAGE_MAP()

BOOL CCustomTreeChildCtrl::GetBkImage(LVBKIMAGE* plvbkImage) const
{
	memcpy(plvbkImage, &m_bkImage, sizeof(LVBKIMAGE));
	return TRUE;
}

BOOL CCustomTreeChildCtrl::SetBkImage(LVBKIMAGE* plvbkImage)
{
	memcpy(&m_bkImage, plvbkImage, sizeof(LVBKIMAGE));
	Invalidate();
	return TRUE;
}

void CCustomTreeChildCtrl::OnTimer(UINT_PTR nIDEvent)
{
	
	
	
	
}

void CCustomTreeChildCtrl::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	
	
	Invalidate();

	
	CTreeCtrl::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CCustomTreeChildCtrl::OnLButtonDown(UINT nFlags, CPoint point)
{
	
	if (CheckHit(point))
	{
		UINT nHitFlags;
		HTREEITEM hItem = HitTest(point, &nHitFlags);
		if(hItem)
		{
			if (nHitFlags & TVHT_ONITEMSTATEICON)
				GetParent ()->GetParent ()->PostMessage (WM_CUSTTREE_CHECKBOX_CLICKED, 0, (LPARAM)hItem);

#ifdef _OWNER_DRAWN_TREE
			
			
			
			CRect rcItem, rcClient;
			GetClientRect(&rcClient);
			GetItemRect(hItem,&rcItem,FALSE);
			if(rcItem.bottom>rcClient.bottom)
			{
				Invalidate();
				EnsureVisible(hItem);
				SelectItem(hItem);
				
				return;
			}
#endif 

			
			SelectItem(hItem);
		}
		
		
		CTreeCtrl::OnLButtonDown(nFlags, point);
	}
	else  
	{
		
		
		SetFocus(); 
	}
	
}

void CCustomTreeChildCtrl::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	
	
	if (CheckHit(point))
	{
		HTREEITEM hItem = HitTest(point);
		if(hItem)
		{
#ifdef _OWNER_DRAWN_TREE
			
			
			CRect rcItem, rcClient;
			GetClientRect(&rcClient);
			GetItemRect(hItem,&rcItem,FALSE);
			if(rcItem.bottom>rcClient.bottom)
			{
				Invalidate();
				CTreeCtrl::OnLButtonDown(nFlags, point);
				return;
			}
#endif 

			SelectItem(hItem);
		}

		
		CTreeCtrl::OnLButtonDblClk(nFlags, point);
	}	
	else 
	{
		
		
		SetFocus();
	}
}

void CCustomTreeChildCtrl::OnMouseMove(UINT nFlags, CPoint point)
{
	if (::IsWindow (m_ttip.m_hWnd))
    {
        TOOLINFO ti;
		WPARAM wp = MAKEWPARAM (point.x, point.y);
		ti.lpszText = (char*)malloc (1000);
		strcpy (ti.lpszText, "");
		GetParent ()->SendMessage (ID_CTCC_GETTOOLTIPTEXT, wp, (LPARAM)&ti);

		static CString _strOld;
		
		if (_strOld != ti.lpszText)
        {
			_strOld = ti.lpszText;
			m_ttip.UpdateTipText (_strOld, this);
        }

		free (ti.lpszText);
    }

	
	if (CheckHit(point))
	{
		
		CTreeCtrl::OnMouseMove(nFlags, point);
	}
	
}

#ifdef _OWNER_DRAWN_TREE 

LRESULT CCustomTreeChildCtrl::CustomDrawNotify(LPNMTVCUSTOMDRAW lpnm)
{
	lpnm->nmcd.hdr.hwndFrom = GetSafeHwnd();
	lpnm->nmcd.hdr.code = NM_CUSTOMDRAW;
	lpnm->nmcd.hdr.idFrom = GetWindowLong(m_hWnd, GWL_ID);
	return GetParent()->SendMessage(WM_NOTIFY,(WPARAM)0,(LPARAM)lpnm);
}

LRESULT CCustomTreeChildCtrl::OwnerDraw(CDC* pDC)
{
	NMTVCUSTOMDRAW nm;	
	DWORD dwFlags;		

	DWORD dwRet;		
	CRect rcClient;		

	
	GetClientRect(&rcClient);

	
	memset(&nm,0,sizeof(NMTVCUSTOMDRAW));

	
	nm.nmcd.dwDrawStage = CDDS_PREPAINT; 
	nm.nmcd.hdc = pDC->m_hDC;
	nm.nmcd.rc = rcClient;
	
	
    dwFlags = (DWORD)CustomDrawNotify(&nm); 
	
	
	
	

	
	COLORREF crBkgnd = IsWindowEnabled()?pDC->GetBkColor():GetSysColor(COLOR_BTNFACE);
	
	pDC->FillSolidRect( rcClient, crBkgnd ); 

	if(m_bkImage.hbm && IsWindowEnabled())
	{
		

		int xOffset = m_nOffsetX;
		int yOffset = rcClient.left;
		int yHeight = rcClient.Height();

		SCROLLINFO scroll_info;
		
		
		if ( GetScrollInfo( SB_VERT, &scroll_info, SIF_POS | SIF_RANGE ) )
		{
			yOffset = -scroll_info.nPos;
			yHeight = max( scroll_info.nMax+1, rcClient.Height());
		}
	
		
		CDC dcTemp;
		dcTemp.CreateCompatibleDC(pDC);
		BITMAP bm;
		::GetObject(m_bkImage.hbm,sizeof(BITMAP),&bm);
		CBitmap* pOldBitmap = 
			dcTemp.SelectObject( CBitmap::FromHandle(m_bkImage.hbm) ); 
		
		
		float x = (float)m_bkImage.xOffsetPercent/100*(float)rcClient.Width();
		float y = (float)m_bkImage.yOffsetPercent/100*(float)rcClient.Height();
		pDC->BitBlt(+(int)x, 
			(int)y, 
			bm.bmWidth, bm.bmHeight, &dcTemp, 0, 0, SRCCOPY);
		
		
		dcTemp.SelectObject(pOldBitmap);
			
	}

	
	if(dwFlags&CDRF_NOTIFYPOSTERASE)
	{
		nm.nmcd.dwDrawStage = CDDS_POSTERASE;
		dwRet = (DWORD)CustomDrawNotify(&nm); 
	}
	
	
	CFont* pOldFont = pDC->SelectObject(GetFont());
	
	
	CImageList* pstateList = GetImageList(TVSIL_STATE);
	CImageList* pimgList = GetImageList(TVSIL_NORMAL);
	
	
	CSize iconSize, stateImgSize;

	
	if(pimgList)
	{
		
		IMAGEINFO ii;
		if(pimgList->GetImageInfo(0, &ii))
			iconSize = CSize(ii.rcImage.right-ii.rcImage.left,
			ii.rcImage.bottom-ii.rcImage.top);
	}		
	
	
	if(pstateList)
	{
		
		IMAGEINFO ii;
		if(pstateList->GetImageInfo(0, &ii))
			stateImgSize = CSize(ii.rcImage.right-ii.rcImage.left,
			ii.rcImage.bottom-ii.rcImage.top);
	}

	
	
	

	HTREEITEM hItem = GetFirstVisibleItem();

	while(hItem)
	{
		
		int nOldBkMode = pDC->SetBkMode(TRANSPARENT);

		
		DWORD dwStyle = GetStyle();

		
		DWORD dwState = GetItemState(hItem,0xFFFF);

		BOOL bEnabled = IsWindowEnabled();
		BOOL bSelected = dwState&TVIS_SELECTED;
		BOOL bHasFocus = (GetFocus() && GetFocus()->m_hWnd==m_hWnd)?TRUE:FALSE;
			

		
		
		
		

		nm.nmcd.dwItemSpec = (DWORD_PTR)hItem;

		
		if(bEnabled)
		{	
			if(bHasFocus)
			{
				nm.clrTextBk = bSelected?GetSysColor(COLOR_HIGHLIGHT):crBkgnd;
				nm.clrText = ::GetSysColor(bSelected?COLOR_HIGHLIGHTTEXT:COLOR_MENUTEXT);
				nm.nmcd.uItemState = dwState | (bSelected?CDIS_FOCUS:0);
			}
			else
			{
				if(GetStyle()&TVS_SHOWSELALWAYS)
				{
					nm.clrTextBk = bSelected?GetSysColor(COLOR_INACTIVEBORDER):crBkgnd;
					nm.clrText = ::GetSysColor(COLOR_MENUTEXT);
				}
				else
				{
					nm.clrTextBk = crBkgnd;
					nm.clrText = ::GetSysColor(COLOR_MENUTEXT);
				}
			}
		}
		else
		{
			nm.clrTextBk = bSelected?GetSysColor(COLOR_BTNSHADOW):crBkgnd;
			nm.clrText = ::GetSysColor(COLOR_GRAYTEXT);
		}
		
		
		
		GetItemRect(hItem,&nm.nmcd.rc,0);

		
		CRgn rgn;
		rgn.CreateRectRgn(nm.nmcd.rc.left, nm.nmcd.rc.top, 
			nm.nmcd.rc.left+m_nFirstColumnWidth, nm.nmcd.rc.bottom);
		pDC->SelectClipRgn(&rgn);

		dwRet = CDRF_DODEFAULT;

		
		if(dwFlags&CDRF_NOTIFYITEMDRAW)
		{
			nm.nmcd.dwDrawStage = CDDS_ITEMPREPAINT;
			dwRet = (DWORD)CustomDrawNotify(&nm); 

		}

		if(!(dwFlags&CDRF_SKIPDEFAULT))
		{
			
			
			

			CRect rcItem;
			int nImage,nSelImage;
			
			GetItemRect(hItem,&rcItem,TRUE);
			GetItemImage(hItem,nImage,nSelImage);
				
			int x = rcItem.left-3;
			int yCenterItem = rcItem.top + (rcItem.bottom - rcItem.top)/2; 

			
			if(pimgList)
			{
				int nImageIndex = dwState&TVIS_SELECTED?nImage:nSelImage;
				x-=iconSize.cx+1;
				pimgList->Draw(pDC,nImageIndex,
					CPoint(x, yCenterItem-iconSize.cy/2),ILD_TRANSPARENT);
			}
			
			
			if(GetStyle()&TVS_CHECKBOXES && pstateList!=NULL)
			{
				
				DWORD dwStateImg = GetItemState(hItem,TVIS_STATEIMAGEMASK)>>12;
				
				x-=stateImgSize.cx;

				pstateList->Draw(pDC,dwStateImg,
					CPoint(x, yCenterItem-stateImgSize.cy/2),ILD_TRANSPARENT);
			}

			
			if(dwStyle&TVS_HASLINES)
			{
				
				
				

				
				CPen pen;
				pen.CreatePen(PS_DOT,1,GetLineColor());
				CPen* pOldPen = pDC->SelectObject(&pen);
				
				HTREEITEM hItemParent = GetParentItem(hItem);

				if(hItemParent!=NULL ||dwStyle&TVS_LINESATROOT)
				{
					_DotHLine(pDC->m_hDC,x-iconSize.cx/2-2,yCenterItem,
						iconSize.cx/2+2,RGB(128,128,128));
				}
				
				if(hItemParent!=NULL ||	dwStyle&TVS_LINESATROOT && GetPrevSiblingItem(hItem)!=NULL)
				{
					_DotVLine(pDC->m_hDC,x-iconSize.cx/2-2,rcItem.top,
						yCenterItem-rcItem.top, RGB(128,128,128));
				}
				
				if(GetNextSiblingItem(hItem)!=NULL)
				{
					_DotVLine(pDC->m_hDC,x-iconSize.cx/2-2,yCenterItem,
						rcItem.bottom-yCenterItem,RGB(128,128,128));
				}

				int x1 = x-iconSize.cx/2-2;
				
				while(hItemParent!=NULL )
				{
					x1-=iconSize.cx+3;
					if(GetNextSiblingItem(hItemParent)!=NULL)
					{
						_DotVLine(pDC->m_hDC,x1,rcItem.top,rcItem.Height(),RGB(128,128,128));
					}
					hItemParent = GetParentItem(hItemParent);
				}
			
				
				pDC->SelectObject(pOldPen);
				
			}

			if(dwStyle&TVS_HASBUTTONS && ItemHasChildren(hItem))
			{
				
				int nImg = GetItemState(hItem,TVIF_STATE)&TVIS_EXPANDED?1:0;
				m_imgBtns.Draw(pDC, nImg, CPoint(x-iconSize.cx/2-6,yCenterItem-4), 
					ILD_TRANSPARENT);
			}

		}

		pDC->SelectClipRgn(NULL);

		
		if(dwRet&CDRF_NOTIFYPOSTPAINT)
		{
			nm.nmcd.dwDrawStage = CDDS_ITEMPOSTPAINT;
			dwRet = (DWORD)CustomDrawNotify(&nm); 
		}

		
		pDC->SetBkMode(nOldBkMode);

		
		hItem = GetNextVisibleItem(hItem);
	};

	

	pDC->SelectObject(pOldFont);
	
	return 0;
}

int CCustomTreeChildCtrl::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
	
	Invalidate();

	
	return CTreeCtrl::OnMouseWheel(nFlags, zDelta, pt);
}

void CCustomTreeChildCtrl::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar *pScrollBar)
{
	
	Invalidate();
	
	
	CTreeCtrl::OnVScroll(nSBCode, nPos, pScrollBar);
}

#endif 

void CCustomTreeChildCtrl::OnPaint()
{
	CRect rcClient;
	GetClientRect(&rcClient);

	CPaintDC dc(this);
	
	CDC dcMem;
	CBitmap bmpMem;

	
	dcMem.CreateCompatibleDC(&dc);
	if (bmpMem.CreateCompatibleBitmap(&dc, rcClient.Width(), rcClient.Height()))
	{
		CBitmap* pOldBmp = dcMem.SelectObject(&bmpMem);

		

#ifdef _OWNER_DRAWN_TREE	
		OwnerDraw(&dcMem);	
#else						
		CWnd::DefWindowProc(WM_PAINT, (WPARAM)dcMem.m_hDC, 0);
#endif 

		
		dc.BitBlt(0, 0, rcClient.right, rcClient.bottom, &dcMem, 0, 0, SRCCOPY);

		dcMem.SelectObject(pOldBmp);

		bmpMem.DeleteObject();
	}
	dcMem.DeleteDC();

}

BOOL CCustomTreeChildCtrl::OnEraseBkgnd(CDC* pDC)
{
	return TRUE;	
}

BOOL CCustomTreeChildCtrl::CheckHit(CPoint point)
{
	

	UINT fFlags;
	HTREEITEM hItem = HitTest(point, &fFlags);

	CRect rcItem,rcClient;
	GetClientRect(rcClient);
	GetItemRect(hItem, &rcItem, TRUE);

	if (fFlags & TVHT_ONITEMICON ||
		fFlags & TVHT_ONITEMBUTTON ||
		fFlags & TVHT_ONITEMSTATEICON)
		return TRUE;

	if(GetStyle()&TVS_FULLROWSELECT)
	{
		rcItem.right = rcClient.right;
		if(rcItem.PtInRect(point)) 
			return TRUE;
		
		return FALSE;
	}

	
	if (fFlags & TVHT_ONITEMLABEL)
	{
		rcItem.right = m_nFirstColumnWidth;
		
		if (!rcItem.PtInRect(point))
			return FALSE;
		
		CString strSub;
		AfxExtractSubString(strSub, GetItemText(hItem), 0, '\t');

		CDC* pDC = GetDC();
		pDC->SelectObject(GetFont());
		rcItem.right = rcItem.left + pDC->GetTextExtent(strSub).cx + 6;
		ReleaseDC(pDC);

		
		if (!rcItem.PtInRect(point))
			return FALSE;
		
		return TRUE;
	}

	return FALSE;
}

#define COLUMN_MARGIN		1		

#ifdef _OWNER_DRAWN_TREE
	#define DEFMINFIRSTCOLWIDTH 0 
#else
	#define DEFMINFIRSTCOLWIDTH 100	
#endif

IMPLEMENT_DYNCREATE(CColumnTreeCtrl, CStatic)

BEGIN_MESSAGE_MAP(CColumnTreeCtrl, CStatic)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	ON_WM_SIZE()
	ON_WM_HSCROLL()
	ON_WM_SETTINGCHANGE()
	ON_WM_ENABLE()
	
	ON_MESSAGE (ID_CTCC_GETTOOLTIPTEXT, OnCtccGetToolTipText)
END_MESSAGE_MAP()

CColumnTreeCtrl::CColumnTreeCtrl()
{
	
	m_uMinFirstColWidth = DEFMINFIRSTCOLWIDTH;
	m_bHeaderChangesBlocked = FALSE;
	m_xOffset = 0;
	m_bCreatingWindowByOurself = false;
}

CColumnTreeCtrl::~CColumnTreeCtrl()
{
}

BOOL CColumnTreeCtrl::Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID)
{
	m_bCreatingWindowByOurself = true;
	CStatic::Create(_T(""), dwStyle, rect, pParentWnd, nID);
	m_bCreatingWindowByOurself = false;
	Initialize();
	return TRUE;
}

void CColumnTreeCtrl::PreSubclassWindow()
{
	if (!m_bCreatingWindowByOurself)
		Initialize();
}

#ifdef DEBUG
void CColumnTreeCtrl::AssertValid( ) const
{
	

	CStatic::AssertValid();

	ASSERT( m_Tree.m_hWnd ); 
	ASSERT( m_Header.m_hWnd );
	ASSERT( m_Header2.m_hWnd );
}
#endif

void CColumnTreeCtrl::Initialize()
{
	if (m_Tree.m_hWnd) 
		return; 

	CRect rcClient;
	GetClientRect(&rcClient);
	
	
	m_Tree.Create(WS_CHILD | WS_VISIBLE  | TVS_NOHSCROLL, CRect(), this, TreeID);
	m_Header.Create(WS_CHILD |  WS_VISIBLE | HDS_FULLDRAG  , rcClient, this, HeaderID);
	m_Header2.Create(WS_CHILD , rcClient, this, Header2ID);

	
	m_horScroll.Create(SBS_HORZ|WS_CHILD|SBS_BOTTOMALIGN,rcClient,this,HScrollID);
	
	
	CFont* pFont = m_Tree.GetFont();
	m_Header.SetFont(pFont);
	m_Header2.SetFont(pFont);

	
	BOOL bIsComCtl6 = FALSE;

	HMODULE hComCtlDll = LoadLibrary(_T("comctl32.dll"));

	if (hComCtlDll)
	{
		typedef HRESULT (CALLBACK *PFNDLLGETVERSION)(DLLVERSIONINFO*);

		PFNDLLGETVERSION pfnDllGetVersion = (PFNDLLGETVERSION)GetProcAddress(hComCtlDll, "DllGetVersion");

		if (pfnDllGetVersion)
		{
			DLLVERSIONINFO dvi;
			ZeroMemory(&dvi, sizeof(dvi));
			dvi.cbSize = sizeof(dvi);

			HRESULT hRes = (*pfnDllGetVersion)(&dvi);

			if (SUCCEEDED(hRes) && dvi.dwMajorVersion >= 6)
				bIsComCtl6 = TRUE;
		}

		FreeLibrary(hComCtlDll);
	}

	
	WINDOWPOS wp;
	HDLAYOUT hdlayout;
	hdlayout.prc = &rcClient;
	hdlayout.pwpos = &wp;
	m_Header.Layout(&hdlayout);
	m_cyHeader = hdlayout.pwpos->cy;
	
	
	m_xOffset = bIsComCtl6 ? 9 : 6;

	m_xPos = 0;

	UpdateColumns();
}

void CColumnTreeCtrl::OnSettingChange(UINT uFlags, LPCTSTR lpszSection)
{
	m_Tree.SendMessage(WM_SETTINGCHANGE);
	m_horScroll.SendMessage(WM_SETTINGCHANGE);

	
	CRect rcClient;
	GetClientRect(&rcClient);
	
	
	
	
	
	m_Header.SendMessage(WM_SETTINGCHANGE);
	m_Header2.SendMessage(WM_SETTINGCHANGE);
	
	m_Header.SetFont(CFont::FromHandle((HFONT)GetStockObject(DEFAULT_GUI_FONT)));
	m_Header2.SetFont(CFont::FromHandle((HFONT)GetStockObject(DEFAULT_GUI_FONT)));

	
	WINDOWPOS wp;
	HDLAYOUT hdlayout;
	hdlayout.prc = &rcClient;
	hdlayout.pwpos = &wp;
	m_Header.Layout(&hdlayout);
	m_cyHeader = hdlayout.pwpos->cy;

	RepositionControls();
}

void CColumnTreeCtrl::OnPaint()
{
	
	
	
	CPaintDC dc(this);
	
	CRect rcClient;
	GetClientRect(&rcClient);
	
	int cyHScroll = GetSystemMetrics(SM_CYHSCROLL);
	int cxVScroll = GetSystemMetrics(SM_CXVSCROLL);
	CBrush brush;
	brush.CreateSolidBrush(::GetSysColor(COLOR_BTNFACE));
	
	CRect rc;

	
	SCROLLINFO scrinfo;
	scrinfo.cbSize = sizeof(scrinfo);
	m_Tree.GetScrollInfo(SB_VERT,&scrinfo,SIF_ALL);
	BOOL bVScrollVisible = scrinfo.nMin!=scrinfo.nMax?TRUE:FALSE;
	
	if(bVScrollVisible)
	{
		
		rc.SetRect(rcClient.right-cxVScroll, rcClient.bottom-cyHScroll,
				rcClient.right, rcClient.bottom);
		dc.FillRect(rc,&brush);
	}

	
}

BOOL CColumnTreeCtrl::OnEraseBkgnd(CDC* pDC)
{
	
	return FALSE;
	
}

void CColumnTreeCtrl::OnSize(UINT nType, int cx, int cy)
{
	RepositionControls();
}

void CColumnTreeCtrl::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	SCROLLINFO scrinfo;
	scrinfo.cbSize = sizeof(scrinfo);
	
	m_Tree.GetScrollInfo(SB_VERT,&scrinfo,SIF_ALL);
	
	BOOL bVScrollVisible = scrinfo.nMin!=scrinfo.nMax?TRUE:FALSE;
	
	
	int cxTotal = m_cxTotal+(bVScrollVisible?GetSystemMetrics(SM_CXVSCROLL):0);
	
	CRect rcClient;
	GetClientRect(&rcClient);
	int cx = rcClient.Width();

	int xLast = m_xPos;

	switch (nSBCode)
	{
	case SB_LINELEFT:
		m_xPos -= 15;
		break;
	case SB_LINERIGHT:
		m_xPos += 15;
		break;
	case SB_PAGELEFT:
		m_xPos -= cx;
		break;
	case SB_PAGERIGHT:
		m_xPos += cx;
		break;
	case SB_LEFT:
		m_xPos = 0;
		break;
	case SB_RIGHT:
		m_xPos = cxTotal - cx;
		break;
	case SB_THUMBTRACK:
		m_xPos = nPos;
		break;
	}

	if (m_xPos < 0)
		m_xPos = 0;
	else if (m_xPos > cxTotal - cx)
		m_xPos = cxTotal - cx;

	if (xLast == m_xPos)
		return;

	m_Tree.m_nOffsetX = m_xPos;

	SetScrollPos(SB_HORZ, m_xPos);
	CWnd::OnHScroll(nSBCode,nPos,pScrollBar);
	RepositionControls();
	
}

void CColumnTreeCtrl::OnHeaderItemChanging(NMHDR* pNMHDR, LRESULT* pResult)
{
	
	

	if(m_bHeaderChangesBlocked)
	{
		
		
		m_bHeaderChangesBlocked = FALSE;
		*pResult = TRUE; 
		return;
	}

	*pResult = FALSE;

	LPNMHEADER pnm = (LPNMHEADER)pNMHDR;
	if(pnm->iItem==0)
	{
		CRect rc;
		m_Header.GetItemRect(0,&rc);
		if(pnm->pitem->cxy<m_uMinFirstColWidth)
		{
			
			pnm->pitem->cxy=m_uMinFirstColWidth+1;
			*pResult = TRUE; 
		}
		return;
	}
	
}

void CColumnTreeCtrl::OnHeaderItemChanged(NMHDR* pNMHDR, LRESULT* pResult)
{
	UpdateColumns();

	m_Tree.Invalidate();
}

void CColumnTreeCtrl::OnTreeCustomDraw(NMHDR* pNMHDR, LRESULT* pResult)
{
	
	
	

	NMCUSTOMDRAW* pNMCustomDraw = (NMCUSTOMDRAW*)pNMHDR;
	NMTVCUSTOMDRAW* pNMTVCustomDraw = (NMTVCUSTOMDRAW*)pNMHDR;

	switch (pNMCustomDraw->dwDrawStage)
	{
	case CDDS_PREPAINT:
		*pResult = CDRF_NOTIFYITEMDRAW;
		break;

	case CDDS_ITEMPREPAINT:
		*pResult = CDRF_DODEFAULT | CDRF_NOTIFYPOSTPAINT;
		break;

	case CDDS_ITEMPOSTPAINT:
		{
			HTREEITEM hItem = (HTREEITEM)pNMCustomDraw->dwItemSpec;
			CRect rcItem = pNMCustomDraw->rc;

			if (rcItem.IsRectEmpty())
			{
				
				*pResult = CDRF_DODEFAULT;
				break;
			}

			CDC dc;
			dc.Attach(pNMCustomDraw->hdc);

			CRect rcLabel;
			m_Tree.GetItemRect(hItem, &rcLabel, TRUE);

			COLORREF crTextBk = pNMTVCustomDraw->clrTextBk;
			COLORREF crWnd = GetSysColor((IsWindowEnabled()?COLOR_WINDOW:COLOR_BTNFACE));
			

#ifndef _OWNER_DRAWN_TREE
			
			dc.FillSolidRect(&rcLabel, crWnd);
#endif 

			int nColsCnt = m_Header.GetItemCount();

			
			int xOffset = 0;
			int i=0;
			for (i=0; i<nColsCnt; i++)
			{
				xOffset += m_arrColWidths[i];
				rcItem.right = xOffset-1;
				dc.DrawEdge(&rcItem, BDR_SUNKENINNER, BF_RIGHT);
			}
			
			dc.DrawEdge(&rcItem, BDR_SUNKENINNER, BF_BOTTOM);

			CString strText = m_Tree.GetItemText(hItem);
			CString strSub;
			AfxExtractSubString(strSub, strText, 0, '\t');

			
			CRect rcText(0,0,0,0);
			dc.DrawText(strSub, &rcText, DT_NOPREFIX | DT_CALCRECT);
			rcLabel.right = min(rcLabel.left + rcText.right + 4, m_arrColWidths[0] - 4);

			BOOL bFullRowSelect = m_Tree.GetStyle()&TVS_FULLROWSELECT;

			if (rcLabel.Width() < 0)
				crTextBk = crWnd;
			if (crTextBk != crWnd)	
			{
				CRect rcSelect =  rcLabel;
				if(bFullRowSelect) rcSelect.right = rcItem.right;
				
				dc.FillSolidRect(&rcSelect, crTextBk);

				
				if (pNMCustomDraw->uItemState & CDIS_FOCUS)
					dc.DrawFocusRect(&rcSelect);

			}
			
			

			CFont* pOldFont = NULL;
			if(m_Tree.GetStyle()&TVS_TRACKSELECT && pNMCustomDraw->uItemState && CDIS_HOT)
			{
				LOGFONT lf;
				pOldFont = m_Tree.GetFont();
				pOldFont->GetLogFont(&lf);
				lf.lfUnderline = 1;
				CFont newFont;
				newFont.CreateFontIndirect(&lf);
				dc.SelectObject(newFont);
			}

			rcText = rcLabel;
			rcText.DeflateRect(2, 1);
			dc.SetTextColor(pNMTVCustomDraw->clrText);
			dc.DrawText(strSub, &rcText, DT_VCENTER | DT_SINGLELINE | 
				DT_NOPREFIX | DT_END_ELLIPSIS);

			xOffset = m_arrColWidths[0];
			dc.SetBkMode(TRANSPARENT);

			if(IsWindowEnabled() && !bFullRowSelect)	
				dc.SetTextColor(::GetSysColor(COLOR_MENUTEXT));
			
			
			if( pOldFont &&  !(m_Tree.GetStyle()& TVS_FULLROWSELECT)) 
				dc.SelectObject(pOldFont);

			
			for (i=1; i<nColsCnt; i++)
			{
				if (AfxExtractSubString(strSub, strText, i, '\t'))
				{
					rcText = rcLabel;
					rcText.left = xOffset+ COLUMN_MARGIN;
					rcText.right = xOffset + m_arrColWidths[i]-COLUMN_MARGIN;
					rcText.DeflateRect(m_xOffset, 1, 2, 1);
					if(rcText.left<0 || rcText.right<0 || rcText.left>=rcText.right)
					{
						xOffset += m_arrColWidths[i];
						continue;
					}
					DWORD dwFormat = m_arrColFormats[i]&HDF_RIGHT?
						DT_RIGHT:(m_arrColFormats[i]&HDF_CENTER?DT_CENTER:DT_LEFT);
					

					dc.DrawText(strSub, &rcText, DT_SINGLELINE |DT_VCENTER 
						| DT_NOPREFIX | DT_END_ELLIPSIS | dwFormat);
				}
				xOffset += m_arrColWidths[i];
			}

			if(pOldFont) dc.SelectObject(pOldFont);
			dc.Detach();
		}
		*pResult = CDRF_DODEFAULT;
		break;

	default:
		*pResult = CDRF_DODEFAULT;
	}
}

void CColumnTreeCtrl::UpdateColumns()
{
	m_cxTotal = 0;

	HDITEM hditem;
	hditem.mask = HDI_WIDTH;
	int nCnt = m_Header.GetItemCount();
	
	ASSERT(nCnt<=MAX_COLUMN_COUNT);
	
	
	for (int i=0; i<nCnt; i++)
	{
		if (m_Header.GetItem(i, &hditem))
		{
			m_cxTotal += m_arrColWidths[i] = hditem.cxy;
			if (i==0)
				m_Tree.m_nFirstColumnWidth = hditem.cxy;
		}
	}
	m_bHeaderChangesBlocked = TRUE;
	RepositionControls();
}

void CColumnTreeCtrl::RepositionControls()
{
	
	if (m_Tree.m_hWnd)
	{
	
		CRect rcClient;
		GetClientRect(&rcClient);
		int cx = rcClient.Width();
		int cy = rcClient.Height();

		
		int cyHScroll = GetSystemMetrics(SM_CYHSCROLL);
		int cxVScroll = GetSystemMetrics(SM_CXVSCROLL);
	
		
		SCROLLINFO scrinfo;
		scrinfo.cbSize = sizeof(scrinfo);
		m_Tree.GetScrollInfo(SB_VERT,&scrinfo,SIF_ALL);
		BOOL bVScrollVisible = scrinfo.nMin!=scrinfo.nMax?TRUE:FALSE;
	
		
		int cxTotal = m_cxTotal+(bVScrollVisible?cxVScroll:0);
	
		if (m_xPos > cxTotal - cx) m_xPos = cxTotal - cx;
		if (m_xPos < 0)	m_xPos = 0;
	
		scrinfo.fMask = SIF_PAGE | SIF_POS | SIF_RANGE;
		scrinfo.nPage = cx;
		scrinfo.nMin = 0;
		scrinfo.nMax = cxTotal;
		scrinfo.nPos = m_xPos;
		m_horScroll.SetScrollInfo(&scrinfo);

		CRect rcTree;
		m_Tree.GetClientRect(&rcTree);
		
		
		int x = 0;
		if (cx < cxTotal)
		{
			x = m_horScroll.GetScrollPos();
			cx += x;
		}
	
		
		
		BOOL bHScrollVisible = rcClient.Width()<cxTotal 
			&& rcClient.Height()>=cyHScroll+m_cyHeader;
			
		m_horScroll.ShowWindow(bHScrollVisible?SW_SHOW:SW_HIDE);
	
		m_Header.MoveWindow(-x, 0, cx  - (bVScrollVisible?cxVScroll:0), m_cyHeader);
		
		m_Header2.MoveWindow(rcClient.Width()-cxVScroll, 0, cxVScroll, m_cyHeader);

		m_Tree.MoveWindow(-x, m_cyHeader, cx, cy-m_cyHeader-(bHScrollVisible?cyHScroll:0));
		
		m_horScroll.MoveWindow(0, rcClient.Height()-cyHScroll,
			rcClient.Width() - (bVScrollVisible?cxVScroll:0), cyHScroll);

		
		
		
		m_Header2.ShowWindow(bVScrollVisible?SW_SHOW:SW_HIDE);

		RedrawWindow();
	}
}

int CColumnTreeCtrl::InsertColumn(int nCol, LPCTSTR lpszColumnHeading, int nFormat, int nWidth, int nSubItem)
{
	
	

	CHeaderCtrl& header = GetHeaderCtrl();

	HDITEM hditem;
	hditem.mask = HDI_TEXT | HDI_WIDTH | HDI_FORMAT;
	hditem.fmt = nFormat;
	hditem.cxy = nWidth;
	hditem.pszText = (LPTSTR)lpszColumnHeading;
	m_arrColFormats[nCol] = nFormat;
	int indx =  header.InsertItem(nCol, &hditem);

	if(m_Header.GetItemCount()>0) 
	{
		
		
		hditem.pszText = _T("");
		hditem.cxy = GetSystemMetrics(SM_CXVSCROLL)+5;
		m_Header2.InsertItem(0,&hditem);
	};
	UpdateColumns();
	
	return indx;
}

BOOL  CColumnTreeCtrl::DeleteColumn(int nCol)
{
	
	

	BOOL bResult = m_Header.DeleteItem(nCol);
	if(m_Header.GetItemCount()==0) 
	{
		m_Header2.DeleteItem(0);
	}

	UpdateColumns();
	return bResult;
}

CString CColumnTreeCtrl::GetItemText(HTREEITEM hItem, int nColumn)
{
	
	CString szText = m_Tree.GetItemText(hItem);
	CString szSubItem;
	AfxExtractSubString(szSubItem,szText,nColumn,'\t');
	return szSubItem;
}

void CColumnTreeCtrl::SetItemText(HTREEITEM hItem,int nColumn,LPCTSTR lpszItem)
{
	CString szText = m_Tree.GetItemText(hItem);
	CString szNewText, szSubItem;
	int i;
	for(i=0;i<m_Header.GetItemCount();i++)
	{
		AfxExtractSubString(szSubItem,szText,i,'\t');
		if(i!=nColumn) szNewText+=szSubItem+_T("\t");
		else szNewText+=CString(lpszItem)+_T("\t");
	}
	m_Tree.SetItemText(hItem,szNewText);
}

void CColumnTreeCtrl::SetFirstColumnMinWidth(UINT uMinWidth)
{
	
	m_uMinFirstColWidth = uMinWidth;
}

HTREEITEM CColumnTreeCtrl::HitTest(CPoint pt, UINT* pFlags) const
{
	CTVHITTESTINFO htinfo = {0, 0, NULL, 0};
	htinfo.pt = pt;
	HTREEITEM hItem = HitTest(&htinfo);
	if(pFlags)
	{
		*pFlags = htinfo.flags;
	}
	return hItem;
}

HTREEITEM CColumnTreeCtrl::HitTest(CTVHITTESTINFO* pHitTestInfo) const
{
	
	

	UINT uFlags = 0;
	HTREEITEM hItem = NULL;
	CRect rcItem, rcClient;
	
	CPoint point = pHitTestInfo->pt;
	point.x += m_xPos;
	point.y -= m_cyHeader;

	hItem = m_Tree.HitTest(point, &uFlags);

	
	pHitTestInfo->hItem = hItem;
	pHitTestInfo->flags = uFlags;
	pHitTestInfo->iSubItem = 0;
		
	if (! (uFlags&TVHT_ONITEMLABEL || uFlags&TVHT_ONITEMRIGHT) )
		return hItem;

	
	

	int i;
	int x = 0;
	for(i=0; i<m_Header.GetItemCount(); i++)
	{
		if(point.x>=x && point.x<=x+m_arrColWidths[i])
		{
			pHitTestInfo->iSubItem = i;
			pHitTestInfo->flags = TVHT_ONITEMLABEL;
			return hItem;
		}
		x += m_arrColWidths[i];
	}	
	
	pHitTestInfo->hItem = NULL;
	pHitTestInfo->flags = TVHT_NOWHERE;
	return NULL;
}

BOOL CColumnTreeCtrl::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT *pResult)
{
	
    
	
	LPNMHDR pHdr = (LPNMHDR)lParam;
	
	
		
	if(pHdr->code==NM_CUSTOMDRAW && pHdr->idFrom == TreeID)
	{
		OnTreeCustomDraw(pHdr,pResult);
		return TRUE; 
	}
	
	if(pHdr->code==HDN_ITEMCHANGING && pHdr->idFrom == HeaderID)
	{
		OnHeaderItemChanging(pHdr,pResult);
		return TRUE; 
	}
	
	if(pHdr->code==HDN_ITEMCHANGED && pHdr->idFrom == HeaderID)
	{
		OnHeaderItemChanged(pHdr,pResult);
		return TRUE; 
	}

#ifdef _OWNER_DRAWN_TREE
	
	if(pHdr->code==TVN_ITEMEXPANDING && pHdr->idFrom == TreeID)
	{
		
		Invalidate(); 
	}

#endif 

	if(pHdr->code==TVN_ITEMEXPANDED && pHdr->idFrom == TreeID)
	{
		RepositionControls(); 
	}

	
	pHdr->hwndFrom = GetSafeHwnd();
	pHdr->idFrom = GetWindowLong(GetSafeHwnd(),GWL_ID);
	return (BOOL)GetParent()->SendMessage(WM_NOTIFY,wParam,lParam);
		
}

void CColumnTreeCtrl::OnCancelMode()
{
	m_Header.SendMessage(WM_CANCELMODE);
	m_Header2.SendMessage(WM_CANCELMODE);
	m_Tree.SendMessage(WM_CANCELMODE);
	m_horScroll.SendMessage(WM_CANCELMODE);
	
}
void CColumnTreeCtrl::OnEnable(BOOL bEnable)
{
	m_Header.EnableWindow(bEnable);
	m_Header2.EnableWindow(bEnable);
	m_Tree.EnableWindow(bEnable);
	m_horScroll.EnableWindow(bEnable);
}

int CCustomTreeChildCtrl::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	

    if (m_ttip.Create (this, TTS_ALWAYSTIP) && m_ttip.AddTool(this, ""))
    {
        m_ttip.SendMessage (TTM_SETMAXTIPWIDTH, 0, SHRT_MAX);
        m_ttip.SendMessage (TTM_SETDELAYTIME, TTDT_AUTOPOP, SHRT_MAX);
        m_ttip.SendMessage (TTM_SETDELAYTIME, TTDT_INITIAL, 200);
        m_ttip.SendMessage (TTM_SETDELAYTIME, TTDT_RESHOW, 200);
    }

	return CTreeCtrl::OnCreate (lpCreateStruct);
}

int CCustomTreeChildCtrl::OnToolHitTest(CPoint point, TOOLINFO *pTI) const
{
	

	return CTreeCtrl::OnToolHitTest (point, pTI);
}

LRESULT CColumnTreeCtrl::OnCtccGetToolTipText(WPARAM wp, LPARAM lp)
{
	CPoint pt (LOWORD (wp), HIWORD (wp));

	if (pt.x > m_arrColWidths [0])
		return 0;
	
	m_Tree.ClientToScreen (&pt);
	ScreenToClient (&pt);

	HTREEITEM hItem = HitTest (pt);
	if (hItem == NULL)
		return 0;

	CString strText = GetItemText (hItem, 0);

	CDC *pdc = GetDC ();
	pdc->SelectObject (m_Tree.GetFont ());
	int cxText = pdc->GetTextExtent (strText).cx;
	ReleaseDC (pdc);
	CRect rc;
	m_Tree.GetItemRect (hItem, &rc, TRUE);
	if (cxText + rc.left + 7 < m_arrColWidths [0])
		return 0;
	
	TOOLINFO *pTI = (TOOLINFO*)lp;
	strncpy (pTI->lpszText, strText, 500-1);
	pTI->lpszText [500-1] = 0;
	m_Tree.GetItemRect (hItem, &pTI->rect, FALSE);
	return 0;
}

BOOL CCustomTreeChildCtrl::PreTranslateMessage(MSG *pMsg)
{
	if (::IsWindow(m_ttip.m_hWnd) && pMsg->hwnd == m_hWnd)
    {
        switch(pMsg->message)
        {
        case WM_LBUTTONDOWN:    
        case WM_MOUSEMOVE:
        case WM_LBUTTONUP:    
        case WM_RBUTTONDOWN:
        case WM_MBUTTONDOWN:    
        case WM_RBUTTONUP:
        case WM_MBUTTONUP:
            m_ttip.RelayEvent(pMsg);
            break;
        }
    }

	return CTreeCtrl::PreTranslateMessage (pMsg);
}

