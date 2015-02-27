/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#pragma once

class CDlgSpecifyNetworkSpeedValue : public CDialog
{
	DECLARE_DYNAMIC(CDlgSpecifyNetworkSpeedValue)

public:
	UINT64 m_uValue;
	CDlgSpecifyNetworkSpeedValue(CWnd* pParent = NULL);   
	virtual ~CDlgSpecifyNetworkSpeedValue();

	enum { IDD = IDD_SPECIFYNETSPEEDVALUE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CComboBox m_wndDim;
	virtual void OnOK();
protected:
	void ApplyLanguage(void);
public:
	afx_msg void OnBnClickedInbits();
protected:
	void ApplyInBitsToDim(void);
};
