/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSUIWINDOW_H__B6790DE4_B056_4377_BC52_9F09D146673C__INCLUDED_)
#define AFX_VMSUIWINDOW_H__B6790DE4_B056_4377_BC52_9F09D146673C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class vmsUiWindow  
{
public:
	void setId (UINT nId);
	void RemoveAllChildWindows();
	CWnd* getHosterWindow () const;
	bool isWindowVisible () const;
	virtual bool OnRButtonDown (POINT pt);
	virtual bool isEnabled() const;
	virtual void setEnable (bool bEnable);
	virtual void OnHosterWindowEnterIdle();
	virtual void OnIdle();
	virtual void OnKillHosterWindowFocus();
	virtual void OnMouseLeave();
	virtual void OnMouseEnter();
	virtual void OnMouseMove (CPoint pt);
	virtual void OnLButtonUp (CPoint pt);
	virtual void setHosterWindow(CWnd *pwndHoster);
	virtual void Redraw(bool bInvalidateBg = false);
	virtual bool isVisible () const;
	virtual void setVisible (bool bVisible, bool bRedraw = true);
	virtual vmsUiWindow* FindChildWindow (CPoint pt, bool bIgnoreInvisibleAndDisabledWindows = true);
	virtual void OnLButtonDown (CPoint pt);
	virtual void releaseDC (CDC *pdc) const;
	virtual CDC* getDC() const;
	virtual void setParentWindow (vmsUiWindow* pWindow);
	void getAbsolutePos (CRect *prc) const;
	const CRect* getPos () const;
	virtual void addChildWindow (vmsUiWindow* pwnd);
	virtual void setPos (int x, int y, int cx, int cy);
	virtual void Draw (CDC *pdc);
	vmsUiWindow();
	virtual ~vmsUiWindow();

protected:
	UINT m_nId;
	bool m_bEnabled;
	CWnd* m_pwndHoster;
	bool m_bVisible;
	
	CRect m_rcPos;
	vmsUiWindow *m_pParentWindow;
	
	std::vector <vmsUiWindow*> m_vChildWindows;
	
	vmsUiWindow *m_pChildWindowUnderMouse;
};

#endif 
