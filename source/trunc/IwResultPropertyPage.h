/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#pragma once

#include "supplier_interface.h"
#include "ImportManager.h"

class CIwResultPropertyPage : public CPropertyPage
{
	DECLARE_DYNAMIC(CIwResultPropertyPage)

public:
	CIwResultPropertyPage();
	CIwResultPropertyPage(LPCTSTR pszCaption);
	virtual ~CIwResultPropertyPage();
	void InitManagerResult(int nManagerIndex, bool bChecked, const CString & sSupplierName, const TImportResult& tImportResult);
	void Init(CImportManager* pImportManager);

	enum { IDD = IDD_IWRESULTPROPERTYPAGE };

protected:
	CString m_strTitle;
	virtual void DoDataExchange(CDataExchange* pDX);    

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnSetActive();

private:
	CImportManager* m_pImportManager;
public:
	virtual BOOL OnInitDialog();
};
