/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "ListCtrlEx.h"
#include "vmsLogger.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CListCtrlEx::CListCtrlEx()
{
	UseGrid ();
	m_clrGrid = GetSysColor (COLOR_3DFACE);
	m_pSelImages = NULL;
	ZeroMemory (m_appszCols, sizeof (m_appszCols));
	m_sortMode = LCSM_NONE;
	m_iSortCol = -1;
	m_sortModeSupport = LCSM_ALL_SUPPORTED;
	m_cTotalCols = 0;
}

CListCtrlEx::~CListCtrlEx()
{
}

BEGIN_MESSAGE_MAP(CListCtrlEx, CListCtrl)
	//{{AFX_MSG_MAP(CListCtrlEx)
	ON_NOTIFY_REFLECT(NM_CLICK, OnClick)
	ON_NOTIFY_REFLECT(NM_RCLICK, OnRclick)
	ON_NOTIFY_REFLECT(LVN_DELETEITEM, OnDeleteitem)
	ON_NOTIFY_REFLECT(LVN_DELETEALLITEMS, OnDeleteallitems)
	ON_NOTIFY_REFLECT(LVN_KEYDOWN, OnKeydown)
	ON_WM_PARENTNOTIFY()
	ON_NOTIFY_REFLECT(LVN_COLUMNCLICK, OnColumnclick)
	ON_NOTIFY_REFLECT(LVN_ITEMCHANGED, OnItemchanged)
	//}}AFX_MSG_MAP
	ON_COMMAND_RANGE (1, LISTEX_MAXCOLUMNS, OnShowCol)
END_MESSAGE_MAP()

BOOL RGBIsEqual (COLORREF clr1, COLORREF clr2)
{
	return abs (GetRValue (clr1) - GetRValue (clr2)) < 10 &&
		abs (GetGValue (clr1) - GetGValue (clr2)) < 10 &&
		abs (GetBValue (clr1) - GetBValue (clr2)) < 10;
}

void CListCtrlEx::DrawItem(LPDRAWITEMSTRUCT lpDraw)
{
	try
	{
		int cCols = GetHeaderCtrl ()->GetItemCount ();
		CDC *dc = CDC::FromHandle (lpDraw->hDC);
		int xStart = lpDraw->rcItem.left;	
		CImageList *pImages = GetImageList (LVSIL_SMALL);
		BOOL bNeedBorder = FALSE;	

		

		CHeaderCtrl* pHdr = GetHeaderCtrl ();

		
		for (int i = 0; i < cCols; i++)
		{
			LVITEM item;
			TCHAR szItem [10000];
			int colWidth = GetColumnWidth (pHdr->OrderToIndex (i));

			xStart += 5;
			colWidth -= 5;

			item.iItem = lpDraw->itemID;
			item.iSubItem = i;
			item.pszText = szItem;
			item.cchTextMax = sizeof (szItem);
			item.mask = LVIF_IMAGE | LVIF_TEXT;

			GetItem (&item);

			
			if (i == 0)
			{
				item.state = GetItemState (lpDraw->itemID, LVIS_SELECTED|LVIS_FOCUSED);

				COLORREF clrBg = m_vInfo [lpDraw->itemID].clrBg;
				COLORREF clrText = m_vInfo [lpDraw->itemID].clrText;
	
				
			
				if (item.state & LVIS_FOCUSED)
					bNeedBorder = TRUE;

				if (item.state & LVIS_SELECTED)
				{
					clrBg = GetSysColor (COLOR_HIGHLIGHT);
					clrText = GetSysColor (COLOR_HIGHLIGHTTEXT);
					if (bNeedBorder == FALSE)
					{
						if (GetSelectionMark () == (int)lpDraw->itemID)
							bNeedBorder = TRUE;
					}
				}
		
				CBrush br;
				CPen pen;
				CBrush *oldBr;
				CPen *oldPen;

				if (RGBIsEqual (clrBg, clrText))
					clrText = (~clrText) & 0x00FFFFFF;

				dc->SetTextColor (clrText);

				br.CreateSolidBrush (clrBg);
				pen.CreatePen (PS_SOLID, 1, clrBg);

				oldBr = dc->SelectObject (&br);
				oldPen = dc->SelectObject (&pen);
			
				dc->Rectangle (&lpDraw->rcItem);

				
				if (m_bGrid)
				{
					CPen pen1 (PS_SOLID, 1, m_clrGrid);
					dc->SelectObject (&pen1);
					dc->MoveTo (lpDraw->rcItem.left, lpDraw->rcItem.bottom-1);
					dc->LineTo (lpDraw->rcItem.right, lpDraw->rcItem.bottom-1);
					dc->SelectObject (oldPen);
				}

				dc->SelectObject (oldBr);
				dc->SelectObject (oldPen);

				if (pImages)
				{
					

					CPoint pt;
					pt.x = xStart;
					pt.y = lpDraw->rcItem.top;
					if (m_pSelImages && (item.state & LVIS_SELECTED))
						m_pSelImages->Draw (dc, item.iImage, pt, ILD_TRANSPARENT);
					else
						pImages->Draw (dc, item.iImage, pt, ILD_TRANSPARENT);

					IMAGEINFO inf;
					pImages->GetImageInfo (item.iImage, &inf);

					xStart += inf.rcImage.right - inf.rcImage.left + 5;
					colWidth -= inf.rcImage.right - inf.rcImage.left + 5;
				}
			}

			if (*item.pszText)
			{
				

				int needX = GetStringWidth (item.pszText);
				BOOL bDrawText = TRUE;

				RECT rcText = lpDraw->rcItem;
				rcText.left = xStart;
				rcText.right = xStart + colWidth - 5;

				
				if (needX > colWidth-5)
				{
					RECT rc = rcText;
					int dx = GetStringWidth ("...");
					if (dx <= colWidth-5)
					{
						rc.left = rc.right - dx;
						dc->DrawText ("...", &rc, DT_SINGLELINE | DT_LEFT | DT_VCENTER);
						rcText.right = rc.left - 5;
					}
					else
						bDrawText = FALSE;
				}

				if (bDrawText)
					dc->DrawText (szItem, &rcText, DT_SINGLELINE | DT_LEFT | DT_VCENTER | DT_NOPREFIX);
			}

			xStart += colWidth;

			
			if (m_bGrid)
			{
				
				CPen pen (PS_SOLID, 1, m_clrGrid);
				CPen *oldPen = dc->SelectObject (&pen);
				dc->MoveTo (xStart-1, lpDraw->rcItem.top);
				dc->LineTo (xStart-1, lpDraw->rcItem.bottom);
				dc->SelectObject (oldPen);
			}
		}

		if (bNeedBorder)
		{
			

			dc->SetTextColor (m_vInfo [lpDraw->itemID].clrText);
			RECT rc = lpDraw->rcItem;
			rc.bottom--; rc.right--;
			dc->DrawFocusRect (&rc);
		}

	}
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("CListCtrlEx::DrawItem " + tstring(ex.what()));
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("CListCtrlEx::DrawItem unknown exception");
	}
}

void CListCtrlEx::OnClick(NMHDR* , LRESULT* pResult) 
{
	OnClick ();
	*pResult = 0;
}

void CListCtrlEx::OnClick()
{

}

void CListCtrlEx::OnRclick(NMHDR* nm, LRESULT* pResult) 
{
	if (nm->hwndFrom == m_hWnd)
		OnRClick ();
	
	*pResult = 0;
}

void CListCtrlEx::OnRClick()
{
	
}

void CListCtrlEx::OnDeleteitem(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;

	
	m_vInfo.erase (m_vInfo.begin () + pNMListView->iItem);

	OnDeleteItem (pNMListView);
	
	*pResult = 0;
}

void CListCtrlEx::OnDeleteallitems(NMHDR* , LRESULT* pResult) 
{
	
	
	OnDeleteAllItems ();
		
	*pResult = 0;
}

void CListCtrlEx::OnDeleteItem(NM_LISTVIEW* )
{

}

void CListCtrlEx::OnDeleteAllItems()
{

}

int CListCtrlEx::AddItem(LPCSTR pszItem, COLORREF clrBg, COLORREF clrText, int iImage, BOOL bAddToBeginning)
{
	assert (pszItem != NULL);

	int c = bAddToBeginning ? 0 : GetItemCount ();

	ListEx_ItemInfo info;
	info.clrBg = clrBg;
	info.clrText = clrText;
	if (bAddToBeginning)
		m_vInfo.insert (m_vInfo.begin (), info);
	else
		m_vInfo.push_back (info);

	c = InsertItem (c, "", iImage);
	if (*pszItem)
		SetItemText (c, 0, pszItem);

	return c;
}

void CListCtrlEx::OnKeydown(NMHDR* pNMHDR, LRESULT* pResult) 
{
	LV_KEYDOWN* pLVKeyDow = (LV_KEYDOWN*)pNMHDR;
	

	OnKeyDown (pLVKeyDow->wVKey);

	
	*pResult = 0;
}

void CListCtrlEx::OnKeyDown(WORD )
{

}

int CListCtrlEx::GetItemImage(int iItem)
{
	LVITEM item;

	item.iItem = iItem;
	item.iSubItem = 0;
	item.mask = LVIF_IMAGE;
	GetItem (&item);

	return item.iImage;
}

void CListCtrlEx::SetItemImage(int iItem, int iImage)
{
	LVITEM item;

	item.iItem = iItem;
	item.iSubItem = 0;
	item.mask = LVIF_IMAGE;
	item.iImage = iImage;
	SetItem (&item);

	CRect rc;
	GetItemRect (iItem, &rc, LVIR_BOUNDS);
	InvalidateRect (&rc);
}

void CListCtrlEx::OnForceUpdate()
{

}

BOOL CListCtrlEx::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult) 
{
	LPNMHDR nm = (LPNMHDR) lParam;

	
	if (nm->code == NM_RELEASEDCAPTURE)
	{
		
		RebuildAIndex ();
		
		OnForceUpdate ();
		return TRUE;
	}

	return CListCtrl::OnNotify(wParam, lParam, pResult);
}

void CListCtrlEx::UseGrid(BOOL bUse)
{
	m_bGrid = bUse;
}

void CListCtrlEx::SaveState(LPCSTR pszName)
{
	int *piWidthes;	
	fsnew (piWidthes, int, m_cTotalCols);

	int aOrder [LISTEX_MAXCOLUMNS];
	GetColumnOrderArray ((int*) aOrder, GetHeaderCtrl ()->GetItemCount ());

	for (int i = 0; i < m_cTotalCols; i++)
		if (m_aIndex [i] != -1)
			piWidthes [i] = GetColumnWidth (aOrder [m_aIndex [i]]);
		else
			piWidthes [i] = -1;	

	CString strIndexes = pszName, strWidthes = pszName;
	strIndexes += 'I';
	strWidthes += 'W';

	
	_App.get_SettingsStore ()->WriteProfileBinary (_T ("Settings\\View\\ListViews"), strIndexes, (LPBYTE)m_aIndex, m_cTotalCols * sizeof (int));
	_App.get_SettingsStore ()->WriteProfileBinary (_T ("Settings\\View\\ListViews"), strWidthes, (LPBYTE)piWidthes, m_cTotalCols * sizeof (int));

	delete [] piWidthes;
}

void CListCtrlEx::ReadState(LPCSTR pszName)
{
	CHeaderCtrl* pHdr = GetHeaderCtrl ();
	int *piWidthes;

	Initialize ();

	LPBYTE pbW, pbI;
	UINT uSizeI, uSizeW;

	CString strIndexes = pszName, strWidthes = pszName;
	strIndexes += 'I';
	strWidthes += 'W';

	
	if (_App.get_SettingsStore ()->GetProfileBinary (_T ("Settings\\View\\ListViews"), strIndexes, &pbI, &uSizeI) &&
		 _App.get_SettingsStore ()->GetProfileBinary (_T ("Settings\\View\\ListViews"), strWidthes, &pbW, &uSizeW) && 
		 uSizeI == m_cTotalCols * sizeof (int) && uSizeW == m_cTotalCols * sizeof (int))
	{
		CopyMemory (m_aIndex, pbI, m_cTotalCols * sizeof (int));
		piWidthes = (int*) pbW;

		

		int i;
		for (i = m_cTotalCols - 1; i >= 0; i--)
			if (m_aIndex [i] == -1)	
				DeleteColumn (i);	

		int aOrder [LISTEX_MAXCOLUMNS];
		int iCorr = 0;
		
		
		for (i = 0; i < m_cTotalCols; i++)
		{
			if (m_aIndex [i] != -1)
				aOrder [m_aIndex [i]] = i - iCorr;
			else
				iCorr ++;
		}
		
		pHdr->SetOrderArray (GetHeaderCtrl ()->GetItemCount (), (int*) aOrder);

		RebuildAIndex ();

		for (i = 0; i < m_cTotalCols; i++)
		{
			if (piWidthes [i] > 0)
				SetColumnWidth (aOrder [m_aIndex [i]], piWidthes [i]);
		}

		delete [] pbW;
		delete [] pbI;
	}
}

void CListCtrlEx::SetItemColor(int iItem, COLORREF clr, BOOL bUpdate)
{
	m_vInfo [iItem].clrText = clr;
	if (bUpdate)
		Update (iItem);
}

void CListCtrlEx::SetSelectedImages(CImageList *pImages)
{
	m_pSelImages = pImages;
}

void CListCtrlEx::DeleteHdrItem(int iItem)
{
	int aOrder [LISTEX_MAXCOLUMNS];
	GetColumnOrderArray ((int*) aOrder, GetHeaderCtrl ()->GetItemCount ());
	int iCol = aOrder [m_aIndex [iItem]];
	DeleteColumn (iCol);
	RebuildAIndex ();
	OnForceUpdate ();
}

void CListCtrlEx::OnParentNotify(UINT message, LPARAM lParam) 
{
	
	if (LOWORD (message) == WM_RBUTTONDOWN)
	{
		
		CMenu menu, m;
		menu.CreateMenu ();
		m.CreateMenu ();
		m.AppendMenu (MF_POPUP, (UINT) menu.m_hMenu, "-");

		int cCols = GetHeaderCtrl ()->GetItemCount ();
		
		
		for (int i = 0; i < m_cTotalCols; i++)
		{
			UINT state = 0;
			if (m_aIndex [i] != -1)
			{
				state = MF_CHECKED;
				if (cCols == 1)
					
					state |= MF_GRAYED;
			}
			
			menu.AppendMenu (MF_STRING | state, i+1, m_appszCols [i]);
		}

		CPoint pt (LOWORD (lParam), HIWORD (lParam));
		ClientToScreen (&pt);
		menu.TrackPopupMenu (TPM_RIGHTBUTTON | TPM_TOPALIGN | TPM_LEFTALIGN, pt.x, pt.y, this);
		menu.DestroyMenu ();
	}
	else
		CListCtrl::OnParentNotify(message, lParam);
}

void CListCtrlEx::RebuildAIndex()
{
	int cCols = GetHeaderCtrl ()->GetItemCount ();
	
	
	int i = 0;
	for (i = 0; i < m_cTotalCols; i++)
		m_aIndex [i] = -1;

	int aOrder [LISTEX_MAXCOLUMNS];
	GetColumnOrderArray ((int*) aOrder, cCols);

	HDITEM item;
	item.mask = HDI_LPARAM;
	for (i = 0; i < cCols; i++)
	{
		GetHeaderCtrl ()->GetItem (aOrder [i], &item);
		
		m_aIndex [item.lParam] = i;	
	}
}

void CListCtrlEx::Initialize()
{
	m_cTotalCols = GetHeaderCtrl ()->GetItemCount ();
	if (m_cTotalCols == -1)
	{
		m_cTotalCols = 0;
		return;
	}

	HDITEM item;
	item.mask = HDI_LPARAM;
	for (int i = 0; i < m_cTotalCols; i++)
	{
		item.lParam = i;
		
		GetHeaderCtrl ()->SetItem (i, &item);
	}

	RebuildAIndex ();
}

void CListCtrlEx::SetColumnText(int iCol, LPCSTR pszText)
{
	m_appszCols [iCol] = pszText;

	if (m_aIndex [iCol] == -1)
		return;

	int aOrder [LISTEX_MAXCOLUMNS];
	GetColumnOrderArray ((int*) aOrder, GetHeaderCtrl ()->GetItemCount ());

	iCol = aOrder [m_aIndex [iCol]];

	HDITEM item;
	item.mask = HDI_TEXT;
	item.pszText = (LPSTR) pszText;
	GetHeaderCtrl ()->SetItem (iCol, &item);
}

void CListCtrlEx::OnShowCol(UINT uCmd)
{
	int iCol = uCmd - 1;
	ChangeColumnVisibility (iCol);
}

void CListCtrlEx::InsertHdrItem(int iCol)
{
	int cCols = GetHeaderCtrl ()->GetItemCount ();
	InsertColumn (cCols, m_appszCols [iCol], LVCFMT_LEFT, 80);
	HDITEM item;
	item.mask = HDI_LPARAM;
	item.lParam = iCol;
	GetHeaderCtrl ()->SetItem (cCols, &item);
	RebuildAIndex ();
	OnForceUpdate ();
}

void CListCtrlEx::SetItemText(int iItem, int iSubItem, LPCSTR pszText)
{
	if (m_aIndex [iSubItem] != -1)
		CListCtrl::SetItemText (iItem, m_aIndex [iSubItem], pszText);
}

BOOL CListCtrlEx::IsColumnShown(int iCol)
{
	return m_aIndex [iCol] != -1;
}

void CListCtrlEx::ChangeColumnVisibility(int iColumn)
{
	if (m_aIndex [iColumn] == -1)
		InsertHdrItem (iColumn);
	else
		DeleteHdrItem (iColumn);
}

void CListCtrlEx::OnColumnclick(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;

	HDITEM hditem;
	hditem.mask = HDI_ORDER;
	GetHeaderCtrl ()->GetItem (pNMListView->iSubItem, &hditem);
	int iSortCol = SubItemToSubItem (hditem.iOrder);

	if (m_sortMode != LCSM_NONE && m_iSortCol == iSortCol)
	{
		

		if (m_sortMode == LCSM_ASCENDING)
			m_sortMode = LCSM_DESCENDING;
		else if (m_sortMode == LCSM_DESCENDING)
			m_sortMode = LCSM_ASCENDING;
		else
			m_sortMode = LCSM_NONE;

		if (m_sortMode == LCSM_DESCENDING && 
				(m_sortModeSupport & LCSM_DESCENDING_NOTSUPPORTED))
			m_sortMode = LCSM_NONE;
	}
	else
	{
		m_iSortCol = iSortCol;
		if (m_sortMode == LCSM_NONE)
			m_sortMode = m_sortModeSupport & LCSM_ASCENDING_NOTSUPPORTED ? LCSM_DESCENDING : LCSM_ASCENDING;
	}

	OnSortModeChanged ();

	*pResult = 0;
}

void CListCtrlEx::OnSortModeChanged()
{
	
}

void CListCtrlEx::InitSortImages()
{
	m_imgsSort.Create (10, 10, ILC_COLOR24 | ILC_MASK, 3, 1);
	CBitmap bmp;
	bmp.Attach (SBMP (IDB_SORTIMAGES));
	m_imgsSort.Add (&bmp, RGB (255, 0, 255));
	GetHeaderCtrl ()->SetImageList (&m_imgsSort);
}

void CListCtrlEx::VirtualView_ItemWillBeAdded(COLORREF clrBg, COLORREF clrText, BOOL bAddToBeginning)
{
	ListEx_ItemInfo info;
	info.clrBg = clrBg;
	info.clrText = clrText;
	if (bAddToBeginning)
		m_vInfo.insert (m_vInfo.begin (), info);
	else
		m_vInfo.push_back (info);
}

void CListCtrlEx::VirtualView_ItemWillBeDeleted(int nItem)
{
	m_vInfo.erase (m_vInfo.begin () + nItem);
}

void CListCtrlEx::VirtualView_AllItemsWillBeDeleted()
{
	m_vInfo.clear ();
}

void CListCtrlEx::OnItemchanged(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	OnItemChanged (pNMListView);	
	*pResult = 0;
}

void CListCtrlEx::OnItemChanged(NM_LISTVIEW*)
{

}

int CListCtrlEx::SubItemToSubItem(int nSubItem)
{
	for (int i = 0; i < m_cTotalCols; i++)
	{
		if (m_aIndex [i] == nSubItem)
			return i;
	}

	return -1;
}
