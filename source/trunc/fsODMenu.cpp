/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "fsODMenu.h"
#include "grutil.h"
#include "misc.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

fsODMenu::fsODMenu()
{
	m_hMenu = NULL;
	m_cxIcon = 16;
	m_cyIcon = 16;
	
	LOGFONT lf;
	NONCLIENTMETRICS nm;

	ZeroMemory (&nm, sizeof (nm));
	nm.cbSize = sizeof (nm);
	SystemParametersInfo (SPI_GETNONCLIENTMETRICS, nm.cbSize, &nm, 0);
	lf = nm.lfMenuFont;
	lf.lfCharSet = DEFAULT_CHARSET;

	m_font.CreateFontIndirect (&lf);

	lf.lfWeight = FW_BOLD;
	m_fontBold.CreateFontIndirect (&lf);

	m_pImages = NULL;
}

fsODMenu::~fsODMenu()
{
	Detach ();
}

void fsODMenu::Attach(CMenu *pMenu, BOOL bMainMenu)
{
	Detach ();
	m_hMenu = pMenu->m_hMenu;
	AttachMenu (pMenu, bMainMenu);
}

void fsODMenu::AttachMenu(CMenu *pMenu, BOOL bMenuBar)
{
	for (UINT i = 0; i < (UINT)pMenu->GetMenuItemCount (); i++)
	{
		UINT uState = pMenu->GetMenuState (i, MF_BYPOSITION);

		fsODMenuItemData* pData = AttachMenuItem (pMenu, i);
		pData->bMenuBar = bMenuBar;
		pData->bBold = pMenu->GetDefaultItem (GMDI_USEDISABLED, TRUE) == i;

		
		if (uState & MF_POPUP)
		{
			CMenu *pSubMenu = pMenu->GetSubMenu (i);
			AttachMenu (pSubMenu);	
		}
	}
}

fsODMenuItemData* fsODMenu::AttachMenuItem(CMenu *pMenu, UINT iPos, BOOL bByPos)
{
	fsODMenuItemData *pData;
	
	fsnew1 (pData, fsODMenuItemData);

	UINT nByPosFl = bByPos ? MF_BYPOSITION : MF_BYCOMMAND;

	UINT uState = pMenu->GetMenuState (iPos, nByPosFl);

	UINT nID;
	
	if (uState & MF_POPUP)
		nID = (UINT) pMenu->GetSubMenu (iPos)->m_hMenu;
	else if (bByPos)
		nID = pMenu->GetMenuItemID (iPos);
	else
		nID = iPos;

	pMenu->GetMenuString (iPos, pData->strMenuText, nByPosFl);

	if (uState & MF_POPUP)  
		uState = MF_POPUP;

	
	pMenu->ModifyMenu (iPos, uState | MF_OWNERDRAW | nByPosFl, nID, (LPCSTR)pData);

	pData->iImage = pData->iCheckImage = -1;
	pData->bBold = pData->bMenuBar = FALSE;

	return pData;	
}

void fsODMenu::Detach()
{
	if (m_hMenu == NULL)
		return;

	DetachMenu (CMenu::FromHandle (m_hMenu));

	m_hMenu = NULL;
}

void fsODMenu::DetachMenu(CMenu *pMenu)
{
	if (pMenu == NULL)
		return;
	

	for (UINT i = 0; i < (UINT)pMenu->GetMenuItemCount (); i++)
	{
		UINT uState = pMenu->GetMenuState (i, MF_BYPOSITION);

		if (uState & MF_POPUP)
		{
			CMenu *pSubMenu = pMenu->GetSubMenu (i);
			DetachMenu (pSubMenu);
		}

		DetachMenuItem (pMenu, i);
	}
}

void fsODMenu::DetachMenuItem(CMenu *pMenu, UINT iPos, BOOL bByPos)
{
	MENUITEMINFO info;
	ZeroMemory (&info, sizeof (info));
	info.cbSize = sizeof (info);
	info.fMask  = MIIM_DATA | MIIM_STATE | MIIM_ID | MIIM_SUBMENU;
	pMenu->GetMenuItemInfo (iPos, &info, bByPos);

	UINT uID = info.fState & MF_POPUP ? (UINT) info.hSubMenu : info.wID;

	fsODMenuItemData* pData = (fsODMenuItemData*) info.dwItemData;

	UINT nPosFl = bByPos ? MF_BYPOSITION : MF_BYCOMMAND;
	info.fState &= ~MF_OWNERDRAW;

	
	pMenu->ModifyMenu (iPos, info.fState  | nPosFl, uID, pData->strMenuText);

	delete pData;
}

void fsODMenu::OnMeasureItem(LPMEASUREITEMSTRUCT pmis)
{
	SIZE sz = {0, 0};
	fsODMenuItemData *pData = (fsODMenuItemData*) pmis->itemData;

	
	if (pData->strMenuText.GetLength () == 0)
	{
		pmis->itemWidth  = 0;
		pmis->itemHeight = 5;
		return;
	}

	CDC* dc = AfxGetApp ()->m_pMainWnd->GetDC ();
	CFont *oldfont = dc->SelectObject (pData->bBold ? &m_fontBold : &m_font);

	sz = dc->GetTextExtent (pData->strMenuText);

	pmis->itemWidth  = sz.cx;
	pmis->itemHeight = sz.cy;

	if (pData->bMenuBar == FALSE)
	{
		pmis->itemWidth += m_cxIcon + 6 + 10;  

		UINT mincy = m_cyIcon + 6;
		if (pmis->itemHeight < mincy)
			pmis->itemHeight = mincy;

		if (strchr (pData->strMenuText, '\t') != NULL)
			pmis->itemWidth += 15;
	}
	else
	{
		pmis->itemWidth -= 3;
		UINT temp = GetSystemMetrics (SM_CYMENU);
		pmis->itemHeight = temp > m_cyIcon + 8 ? temp : m_cyIcon + 7;
    
		if(pmis->itemHeight < (UINT)sz.cy)
			pmis->itemHeight = sz.cy;
	}

	dc->SelectObject (oldfont);
	AfxGetApp ()->m_pMainWnd->ReleaseDC (dc);
}

void fsODMenu::OnDrawItem(LPDRAWITEMSTRUCT pdis)
{
	CDC *dc = CDC::FromHandle (pdis->hDC);
	fsODMenuItemData* pData = (fsODMenuItemData*) pdis->itemData;
	UINT uState = pdis->itemState;
	CFont *oldfont = dc->SelectObject (pData->bBold ? &m_fontBold : &m_font);

	RECT rcItem = pdis->rcItem;
	
	RECT rcIcon = rcItem;
	rcIcon.left += 3;
	rcIcon.right = rcIcon.left + m_cxIcon;
	rcIcon.top += (rcIcon.bottom - rcIcon.top - m_cyIcon) / 2;
	rcIcon.bottom = rcIcon.top + m_cyIcon;

	RECT rcIconFrame = rcIcon;
	InflateRect (&rcIconFrame, 2, 2);

	RECT rcSel;
	
	if (pData->bMenuBar)
	{
		rcSel = pdis->rcItem;
		InflateRect (&rcSel, -1, -1);
		fsFillSolidRect (dc, &rcItem, GetSysColor (COLOR_3DFACE));
	}
	else
	{
		rcSel = rcIconFrame;
		rcSel.right = rcItem.right;
		rcSel.bottom++;
		
		fsFillSolidRect (dc, &rcItem, GetSysColor (COLOR_MENU));
		rcItem.left += m_cxIcon;
	}
	
	if (pData->strMenuText.GetLength () == 0)
	{
		RECT rect = rcItem;
		rect.left -= m_cxIcon;
		rect.top += (rect.bottom - rect.top) / 2;
		rect.bottom = rect.top+1;
		rect.right = rcItem.right;
		fsFillSolidRect (dc, &rect, GetSysColor (COLOR_GRAYTEXT));
		return;
	}

	if (uState & 0x40 )
		if (pData->bMenuBar)
			fsDrawFrame (dc, &rcSel, 1);

	if (uState & ODS_SELECTED)	
	{
		if (pData->bMenuBar)
			fsDrawPressedFrame (dc, &rcSel, 1);	
		else
		{
			
			fsFillSolidRect (dc, &rcSel, GetSysColor (COLOR_HIGHLIGHT));
		}
	}

	dc->SetBkMode (TRANSPARENT);

	if (pData->bMenuBar)
	{
		
		if (uState & ODS_GRAYED || uState & ODS_DISABLED) 
			dc->SetTextColor (GetSysColor (COLOR_GRAYTEXT));
		dc->DrawText (pData->strMenuText, &rcItem, DT_VCENTER | DT_SINGLELINE | DT_CENTER);
	}
	else
	{
		CPen pen (PS_SOLID, 1, GetSystemMetrics (COLOR_HIGHLIGHTTEXT));

		CPen *oldpen = dc->SelectObject (&pen);

		if (uState & ODS_GRAYED || uState & ODS_DISABLED) 
			dc->SetTextColor (GetSysColor (COLOR_GRAYTEXT));
		else if (uState & ODS_SELECTED)
			dc->SetTextColor (GetSysColor (COLOR_HIGHLIGHTTEXT));
		else
			dc->SetTextColor (GetSysColor (COLOR_MENUTEXT));

		

		LPCSTR pszTab = strchr (pData->strMenuText, '\t');
		int left = pszTab ? pszTab - pData->strMenuText : pData->strMenuText.GetLength ();

		rcItem.left += 9; rcItem.right -= 15;
		dc->DrawText (pData->strMenuText, left, &rcItem, DT_VCENTER | DT_SINGLELINE);

		if (pszTab)
			dc->DrawText (pszTab+1, -1, &rcItem, DT_VCENTER | DT_SINGLELINE | DT_RIGHT);

		dc->SelectObject (oldpen);
	}

	

	POINT ptIcon;
	ptIcon.x = rcIcon.left + 1;
	ptIcon.y = rcIcon.top + 1;

	RECT rcClr = pdis->rcItem;
	rcClr.right = m_cxIcon + 5;

	if (uState & ODS_CHECKED)
	{
		if (pData->iCheckImage >= 0)
		{
			fsFillSolidRect (dc, &rcClr, GetSysColor (COLOR_MENU));
			m_pImages->Draw (dc, pData->iCheckImage, ptIcon, ILD_TRANSPARENT);
		}
		else if (pData->iImage >= 0)
		{
			fsFillSolidRect (dc, &rcClr, GetSysColor (COLOR_MENU));
			
			
			rcIconFrame.right--;
			fsDrawPressedFrame (dc, &rcIconFrame, 1);
			m_pImages->Draw (dc, pData->iImage, ptIcon, ILD_TRANSPARENT);
		}
		else
		{
			CFont font;
			char check;
			int fsize;

			switch (pData->iCheckImage)
			{
				case ODMENU_CHECKIMAGE_CHECK:
				{
					DrawCheckMark (dc, rcIcon, uState & ODS_SELECTED, uState & ODS_GRAYED);
					
				}
				break;

				case ODMENU_CHECKIMAGE_RADIO:
				{
					check = 105;
					fsize = m_cyIcon;
					font.CreateFont (fsize, 0, 0, 0, FW_NORMAL, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, "Marlett");
					CFont* oldfont = dc->SelectObject (&font);
					dc->DrawText (&check, 1, &rcIcon, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
					dc->SelectObject (oldfont);
				}
				break;

				default:
					return;
			}
		}
	}
	else if (pData->iImage != -1)
	{
		fsFillSolidRect (dc, &rcClr, GetSysColor (COLOR_MENU));

		if (uState & ODS_GRAYED || uState & ODS_DISABLED)
		{
			if (m_pDisImages == NULL)
			{
				HICON hI = m_pImages->ExtractIcon (pData->iImage);

				DrawState (dc->m_hDC, NULL, NULL, LPARAM (hI), 0, ptIcon.x, ptIcon.y, m_cxIcon, m_cyIcon, 
					DST_ICON | DSS_DISABLED);

				DestroyIcon (hI); 
			}
			else
				m_pDisImages->Draw (dc, pData->iImage, ptIcon, ILD_TRANSPARENT);

		}
		else
		{
			if (uState & ODS_SELECTED)
				fsDrawFrame (dc, &rcIconFrame, 1);

			m_pImages->Draw (dc, pData->iImage, ptIcon, ILD_TRANSPARENT);
		}
	}

	dc->SelectObject (oldfont);
}

void fsODMenu::SetImageList(CImageList *pList, CImageList *pDisList)
{
	m_pImages = pList;
	m_pDisImages = pDisList;
}

int fsODMenu::InsertMenu(CMenu *pMenu, int iWhere, CMenu *pMenuWhere)
{
	BOOL bMenuBar = FALSE;
	if (pMenuWhere == NULL)
	{
		pMenuWhere = CMenu::FromHandle (m_hMenu);
		bMenuBar = TRUE;
	}

	for (UINT i = 0; i < (UINT)pMenu->GetMenuItemCount (); i++)
	{
		CString strText;

		pMenu->GetMenuString (i, strText, MF_BYPOSITION);

		HMENU hMenu = CopyMenu (pMenu->GetSubMenu (i)->m_hMenu);
		CMenu *menu = CMenu::FromHandle (hMenu);

		pMenuWhere->InsertMenu (iWhere, MF_BYPOSITION | MF_POPUP,  (UINT_PTR) menu->m_hMenu, strText);

		AttachMenu (menu);
		AttachMenuItem (pMenuWhere, iWhere++)->bMenuBar = bMenuBar;
	}

	
	return pMenu->GetMenuItemCount ();
}

void fsODMenu::RemoveMenu(int iWhere, int iCount, CMenu *pMenuWhere)
{
	if (pMenuWhere == NULL)
		pMenuWhere = CMenu::FromHandle (m_hMenu);

	while (iCount--)
	{
		CMenu *pSubMenu = pMenuWhere->GetSubMenu (iWhere);
		DetachMenu (pSubMenu);
		DetachMenuItem (pMenuWhere, iWhere);
		pMenuWhere->RemoveMenu (iWhere, MF_BYPOSITION);
		pSubMenu->DestroyMenu ();
		iWhere--;
	}
}

HMENU fsODMenu::CopyMenu(HMENU hMenu)
{
	HMENU hCopy = CreateMenu ();

	for (int i = 0; i < GetMenuItemCount (hMenu); i++)
	{
		UINT uState = GetMenuState (hMenu, i, MF_BYPOSITION);
		UINT nID;
		char szMenuText [100];

		if (uState & MF_POPUP)
		{
			nID = (UINT) CopyMenu (GetSubMenu (hMenu, i));
			uState = MF_POPUP | MF_STRING;
		}
		else
			nID = GetMenuItemID (hMenu, i);

		GetMenuString (hMenu, i, szMenuText, sizeof (szMenuText), MF_BYPOSITION);

		
		AppendMenu (hCopy, uState, nID, szMenuText);
	}

	return hCopy;
}

void fsODMenu::SetImages(fsSetImage *pImages, int cImages, CMenu *pMenu, BOOL fByPos)
{
	if (pMenu == NULL)
		pMenu = CMenu::FromHandle (m_hMenu);

	MENUITEMINFO info;
	ZeroMemory (&info, sizeof (info));
	info.cbSize = sizeof (info);
	info.fMask = MIIM_DATA;

	for (int i = 0; i < cImages; i++)
	{
		if (pMenu->GetMenuItemInfo (pImages [i].iIdItem, &info, fByPos))
		{
			fsODMenuItemData *pData = (fsODMenuItemData*) info.dwItemData;
			ASSERT (pData);
			pData->iImage = pImages [i].iImage;
			pData->iCheckImage = pImages [i].iCheckImage;
		}
	}
}

fsODMenuItemData* fsODMenu::AddItem(CMenu *pMenu, UINT nID, LPCSTR pszItem)
{
	pMenu->AppendMenu (pszItem ? MF_STRING : MF_SEPARATOR, nID, pszItem);
	return AttachMenuItem (pMenu, nID, FALSE);
}

void fsODMenu::RemoveMenuItem(CMenu *pMenu, UINT nID, BOOL bByPos)
{
	DetachMenuItem (pMenu, nID, bByPos);
	pMenu->RemoveMenu (nID, bByPos ? MF_BYPOSITION : MF_BYCOMMAND);
}

void fsODMenu::InsertMenuItem(CMenu* pMenu, LPCSTR pszItem, UINT nID, UINT uWhere, BOOL bByPos)
{
	pMenu->InsertMenu (uWhere, bByPos ? MF_BYPOSITION : MF_BYCOMMAND, nID, pszItem);
	AttachMenuItem (pMenu, nID, FALSE);
}

void fsODMenu::SetMenuItemText(CMenu *pMenu, LPCSTR pszText, UINT nID, BOOL bByPos)
{
	MENUITEMINFO info;
	ZeroMemory (&info, sizeof (info));
	info.cbSize = sizeof (info);
	info.fMask  = MIIM_DATA | MIIM_ID;
	pMenu->GetMenuItemInfo (nID, &info, bByPos);
	
	fsODMenuItemData* pData = (fsODMenuItemData*) info.dwItemData;
	if (pData == NULL)
		return;
	
	UINT nFlags = bByPos ? MF_BYPOSITION : MF_BYCOMMAND;
	pMenu->ModifyMenu (nID, nFlags|MF_STRING, info.wID, pszText);
	pMenu->ModifyMenu (nID, nFlags|MF_OWNERDRAW, info.wID, (LPCSTR)pData);

	pData->strMenuText = pszText;
}

void fsODMenu::SetMenuItemsText(CMenu *pMenu, fsSetText *pTexts, UINT nSize, BOOL bByPos)
{
	for (UINT i = 0; i < nSize; i++)
		SetMenuItemText (pMenu, pTexts [i].pszText, pTexts [i].nIDItem, bByPos);
}

void fsODMenu::DrawCheckMark(CDC *dc, RECT &rc, BOOL bSelected, BOOL bGrayed)
{
	int cx = rc.right - rc.left - 4 - 1; 

	int xs = rc.left + 2 + 2 + 1;
	int ys = rc.top + 2 + 2 + 3;
	int d1 = (cx-4) / 2;
	int d2 = (cx-4) - d1;

	if (d1 == d2)
		d1--;

	COLORREF clr;

	if (bGrayed)
		clr = GetSysColor (COLOR_GRAYTEXT);
	else if (bSelected)
		clr = GetSysColor (COLOR_HIGHLIGHTTEXT);
	else
		clr = GetSysColor (COLOR_MENUTEXT);

	CPen pen (PS_SOLID, 1, clr);
	CPen *oldpen = dc->SelectObject (&pen);

	for (int i = 0; i < 2; i++)
	{
		dc->MoveTo (xs-i, ys+i);
		dc->LineTo (xs+d1-1, ys+d1+i*2-1);
		dc->LineTo (xs+d1+d2+i, ys-3+i);

		if (i < 1)
		{
			dc->MoveTo (xs-i, ys+i+1);
			dc->LineTo (xs+d1-1, ys+d1+i*2);
			dc->LineTo (xs+d1+d2+i, ys-2+i);
		}
	}

	dc->SelectObject (oldpen);
}
