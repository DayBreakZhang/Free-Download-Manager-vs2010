/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#pragma once

#include "ImportManager.h"

class CIwManagersPropertyPage : public CPropertyPage
{
	DECLARE_DYNAMIC(CIwManagersPropertyPage)

public:
	CIwManagersPropertyPage();
	CIwManagersPropertyPage(LPCTSTR pszCaption);
	virtual ~CIwManagersPropertyPage();
	void InitManager(int nId, bool bIsEnabled, const CString& sManagerName);
	void Init(CImportManager* pImportManager);

	enum { IDD = IDD_IWMANAGERSPROPERTYPAGE };

protected:
	CString m_strTitle;
	virtual void DoDataExchange(CDataExchange* pDX);    

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnSetActive();
	virtual LRESULT OnWizardNext();
	virtual BOOL OnInitDialog();

private:
	void UpdateButtons();

	CImportManager* m_pImportManager;
public:
	afx_msg void OnBnClickedOrbitManager();
	afx_msg void OnBnClickedMtorrenetManager();
};
