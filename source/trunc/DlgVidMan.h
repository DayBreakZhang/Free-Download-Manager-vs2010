/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DLGVIDMAN_H__04998526_B001_4CC7_8376_B687D36D0C24__INCLUDED_)
#define AFX_DLGVIDMAN_H__04998526_B001_4CC7_8376_B687D36D0C24__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "resource.h"

class CDlgVidMan : public CDialog
{

public:
	BOOL m_bInFVDownloads;
	void Convert();
	void ApplyLanguage();
	void SaveSettings();
	
	
	void UpdateCommand(UINT nID, BOOL *pbEnabled, BOOL *pbChecked);
	
	void ApplyVolumeSettings();
	
	void Update();
	class CDownloads_VideoPreview* m_parent;
	CDlgVidMan(CWnd* pParent = NULL);   

	//{{AFX_DATA(CDlgVidMan)
	enum { IDD = IDD_VIDMAN };
	CSliderCtrl	m_wndVol;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDlgVidMan)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);
	//}}AFX_VIRTUAL

protected:
	
	CFont m_fntBold;
	
	CBrush m_brClrWindow;
	
	void UpdateMuteImage();
	BOOL m_bMute;	
	
	void UpdateVolumePerc();
	
	void ApplyVolume();
	void UpdateEnabled();
	CImageList m_imgMute;
	
	CImageList m_imgMan, m_dimgMan;
	
	void CreateBars();
	CToolBar m_barMute;
	CToolBar m_barMan;

	
	//{{AFX_MSG(CDlgVidMan)
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL OnInitDialog();
	afx_msg void OnPlay();
	afx_msg void OnPause();
	afx_msg void OnStop();
	afx_msg void OnMute();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnConvert();
	afx_msg void OnSwitchAuto();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
