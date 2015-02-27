/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_FLOATINGWNDDROPTARGET_H__A40C2620_2C75_41B4_AD8B_174FE4F1F32F__INCLUDED_)
#define AFX_FLOATINGWNDDROPTARGET_H__A40C2620_2C75_41B4_AD8B_174FE4F1F32F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include <afxole.h>

class CFloatingWndDropTarget : public COleDropTarget  
{
public:
	CFloatingWndDropTarget();
	virtual ~CFloatingWndDropTarget();

protected:
	virtual BOOL OnDrop (CWnd*, COleDataObject*, DROPEFFECT, CPoint);
	virtual DROPEFFECT OnDragOver (CWnd* pWnd, COleDataObject* pDataObject, DWORD dwKeyState, CPoint point);
	virtual DROPEFFECT OnDragEnter (CWnd* pWnd, COleDataObject *pData, DWORD dwKeyState, CPoint pt);
};

#endif 
