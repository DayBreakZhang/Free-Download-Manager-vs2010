/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#pragma once

#include "ImportManager.h"

struct TIwManagerControls
{
	int nMgrsPageMgrId;
	int nResPageMgrId;
	int nResPageSucessfulId;
	int nResPageFailedId;
	int nResPageUnprocessedId;
	int nResPageTotalId;
};

const TIwManagerControls g_arrIwManagerControls[] = 
{
	{IDC_MTORRENET_MANAGER, IDC_STATIC_MTORRENT, IDC_MTORRENT_SUCCESSFUL, IDC_MTORRENT_FAILED, IDC_MTORRENT_UNPROCESSED, IDC_MTORRENT_TOTAL},
	{IDC_ORBIT_MANAGER, IDC_STATIC_ORBIT, IDC_ORBIT_SUCCESSFUL, IDC_ORBIT_FAILED, IDC_ORBIT_UNPROCESSED, IDC_ORBIT_TOTAL}
};

class CIwProgressPropertyPage : public CPropertyPage
{
	DECLARE_DYNAMIC(CIwProgressPropertyPage)

public:
	CIwProgressPropertyPage();
	CIwProgressPropertyPage(LPCTSTR pszCaption);
	virtual ~CIwProgressPropertyPage();
	void UpdateProgress(int nTotal, int nProcessed, const CString& sSupplierName);
	void Init(CImportManager* pImportManager);
	

	enum { IDD = IDD_IWPROGRESSPROPERTYPAGE };

protected:
	CString m_strTitle;
	virtual void DoDataExchange(CDataExchange* pDX);    

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnSetActive();
	virtual BOOL OnInitDialog();
	virtual LRESULT OnWizardNext();
	virtual BOOL OnKillActive();

private:
	CImportManager* m_pImportManager;
};
