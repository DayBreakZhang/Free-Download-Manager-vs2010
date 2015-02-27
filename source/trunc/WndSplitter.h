/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_WNDSPLITTER_H__8B4B2B4B_98FF_4C3E_A094_FB4162F63469__INCLUDED_)
#define AFX_WNDSPLITTER_H__8B4B2B4B_98FF_4C3E_A094_FB4162F63469__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "misc.h"

enum WndSplitterType
{
	WST_HORIZONTAL,				
	WST_VERTICAL				
};

class CWndSplitter  
{
public:
	
	BOOL Create (HINSTANCE hInst, HWND hWndParent, WndSplitterType enType = WST_VERTICAL);
	
	void SetWnd2 (HWND hWnd);
	void SetWnd1 (HWND hWnd);
	
	
	void SetRatio (float fRatio);
	float GetRatio();
	
	
	
	void RecalRatio (BOOL bWnd1MustNotResize = TRUE);
	
	void SetMinDimensions (int wnd1, int wnd2);
	
	void ApplyRatio();
	
	CWndSplitter();
	virtual ~CWndSplitter();

	HWND m_wndSplitter;		

protected:
	BOOL m_bDragging;	
	
	void OnLButtonUp (POINTS pt);
	void OnMouseDrag (POINTS pt);
	void OnCaptureChanged();
	void OnLButtonDown();
	void OnPaint();
	static LRESULT CALLBACK _wndProc (HWND hWnd, UINT uMsg, WPARAM wp, LPARAM lp);
	
	void DrawSizingFrame();
	
	int m_dim;		
	float m_ratio;	
	WndSplitterType m_type;	
	HWND m_wndParent;	
	HWND m_wnd1, m_wnd2;	
	
	
	int  m_startDrag, m_drag;
	int  m_dim1min, m_dim2min;	
};

#endif 
