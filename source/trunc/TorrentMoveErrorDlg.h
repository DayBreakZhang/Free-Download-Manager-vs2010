/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#pragma once

class CTorrentMoveErrorDlg : public CDialog
{
	DECLARE_DYNAMIC(CTorrentMoveErrorDlg)

public:
	CTorrentMoveErrorDlg(CWnd* pParent = NULL);   
	virtual ~CTorrentMoveErrorDlg();

	enum { IDD = IDD_TORRENTMOVE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	virtual BOOL OnInitDialog();
	void ApplyLanguage();

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedRetry();
	afx_msg void OnBnClickedAbort();
	afx_msg void OnBnClickedAbortAll();
	virtual void OnCancel();
	CString	m_strMsg;
};
