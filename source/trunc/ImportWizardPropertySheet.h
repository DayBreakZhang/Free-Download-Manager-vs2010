/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#pragma once

#include "IwManagersPropertyPage.h"
#include "IwProgressPropertyPage.h"
#include "IwResultPropertyPage.h"
#include "ImportManager.h"

class CImportWizardPropertySheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CImportWizardPropertySheet)

public:
	CImportWizardPropertySheet(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CImportWizardPropertySheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	virtual ~CImportWizardPropertySheet();

	
	void UpdateProgress(int nTotal, int nProcessed, const CString& sSupplierName);
	void InitManager(int nManagerIndex, bool bIsEnabled, const CString& sManagerName);
	void InitManagerResult(int nManagerIndex, bool bChecked, const CString & sSupplierName, const TImportResult& tImportResult); 

	
	static void UpdateProgress(int nTotal, int nProcessed, const CString& sSupplierName, void* pData);
	static void InitManager(int nManagerIndex, bool bIsEnabled, const CString& sManagerName, void* pData);
	static void InitManagerResult(int nManagerIndex, bool bChecked, const CString & sSupplierName, const TImportResult& tImportResult, void* pData);

protected:
	DECLARE_MESSAGE_MAP()

private:
	void Init();

	CIwManagersPropertyPage m_pageManagers;
	CIwProgressPropertyPage m_pageProgress;
	CIwResultPropertyPage m_pageResult;
	CButton m_ctlFakeDoneButton;
	CImportManager m_imImportManager;
public:
	virtual BOOL OnInitDialog();
};

