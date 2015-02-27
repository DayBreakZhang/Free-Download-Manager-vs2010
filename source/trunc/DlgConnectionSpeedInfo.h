/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#pragma once

class CDlgConnectionSpeedInfo : public CDialog
{
	DECLARE_DYNAMIC(CDlgConnectionSpeedInfo)

public:
	CDlgConnectionSpeedInfo(CWnd* pParent = NULL);   
	virtual ~CDlgConnectionSpeedInfo();

	enum { IDD = IDD_CONNECTIONSPEEDINFO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedMeasureagain();
protected:
	void UpdateStats(void);
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
protected:
	void ApplyLanguage(void);
	void UpdateEnabled(void);
};
