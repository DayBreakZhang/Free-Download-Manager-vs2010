/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_WPDS_SHEET_H__07670506_2279_4595_9CBE_D0FB2268A4D0__INCLUDED_)
#define AFX_WPDS_SHEET_H__07670506_2279_4595_9CBE_D0FB2268A4D0__INCLUDED_

#include "WPDS_GeneralPage.h"	
#include "WPDS_WebPagesPage.h"	
#include "WPDS_FilesPage.h"	
#include "WPDS_ImagesPages.h"	
#if _MSC_VER > 1000
#pragma once
#endif 

class CWPDS_Sheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CWPDS_Sheet)

public:
	CWPDS_Sheet(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CWPDS_Sheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);

public:

public:

	
	//{{AFX_VIRTUAL(CWPDS_Sheet)
	//}}AFX_VIRTUAL

public:
	
	
	
	void Init (fsWPDSettings *wpds, BOOL bGeneralPage = FALSE, fsWebPageDownloader* wpd = NULL, bool bUsedAsSetDefaults = false);

	
	CWPDS_ImagesPages m_images;	
	CWPDS_FilesPage m_files;	
	CWPDS_WebPagesPage m_webpages;
	CWPDS_GeneralPage m_general;

	virtual ~CWPDS_Sheet();

	
protected:
	//{{AFX_MSG(CWPDS_Sheet)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
