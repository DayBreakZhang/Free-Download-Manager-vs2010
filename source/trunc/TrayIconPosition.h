/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_TRAYICONPOSITION_H__9FD8A5A1_419F_11D7_B751_00304F20BD3B__INCLUDED_)
#define AFX_TRAYICONPOSITION_H__9FD8A5A1_419F_11D7_B751_00304F20BD3B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CTrayIconPosition  
{
public:
	typedef enum Precision { Default=0,Low,Medium,High };	

	
	void InitializePositionTracking(HWND a_hwndOfIconOwner, int a_iIconID);
	BOOL GetTrayIconPosition(CPoint& a_ptPoint, Precision a_ePrec = Default);

	
	void Invalidate();
	void SetPrecisionTimeOuts(int iLowSec, int iMedSec, int iHighSec);
	void SetDefaultPrecision(Precision newPrecision) { m_prDefaultPrecision = newPrecision; };
	Precision GetDefaultPrecision(void) { return m_prDefaultPrecision; };

	CTrayIconPosition();
	virtual ~CTrayIconPosition();

protected:
	HICON		m_hIconTemp;
	CRect		m_rtRectangleOfTheTray;
	Precision	m_prDefaultPrecision;
	CTime		m_tLastUpdate;
	CPoint		m_ptPosition;
	int			m_iTrayIconID;
	HWND		m_hWndOfIconOwner;
	int			m_iPrecisions[3];  
	OSVERSIONINFO m_osVer;

	
	static BOOL FindOutPositionOfIconDirectly(const HWND a_hWndOwner, const int a_iButtonID, CRect& a_rcIcon);

	
	static CRect GetTrayWndRect();
	static HWND  GetTrayNotifyWnd(BOOL a_bSeekForEmbedToolbar);
	static BOOL CALLBACK FindTrayWnd(HWND hwnd, LPARAM lParam);
	static BOOL CALLBACK FindToolBarInTrayWnd(HWND hwnd, LPARAM lParam);
};

#endif 
