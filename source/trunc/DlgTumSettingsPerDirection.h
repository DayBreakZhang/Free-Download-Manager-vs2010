/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#pragma once

class CDlgTumSettingsPerDirection : public CDialog
{
	DECLARE_DYNAMIC(CDlgTumSettingsPerDirection)

public:
	CDlgTumSettingsPerDirection(CWnd* pParent = NULL);   
	virtual ~CDlgTumSettingsPerDirection();

	enum { IDD = IDD_TUM_SETTINGS_PERDIRECTION };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    

	DECLARE_MESSAGE_MAP()

public:
	void ReadSettingsFromTumMgr (bool bForDownload);
	void SaveSettingsToTumMgr (bool bForDownload);
	vmsTrafficUsageModeRawSettings::PerDirection m_settings [3];
	virtual BOOL OnInitDialog();
	CTabCtrl m_tabTrafficModes;
protected:
	void UpdateEnabled(void);
	void ApplyLanguage(void);
public:
	afx_msg void OnSelchangeModestab(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnSelchangingModestab(NMHDR *pNMHDR, LRESULT *pResult);
public:
	bool SerializeSettings(bool bSave);
public:
	afx_msg void OnMncManageauto();
	afx_msg void OnMncSetto();
	afx_msg void OnClickedMncpsManageauto();
	afx_msg void OnMncpsSetto();
	afx_msg void OnClickedMntManageauto();
	afx_msg void OnMntSetto();
};
