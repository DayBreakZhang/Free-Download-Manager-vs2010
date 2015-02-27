/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSUPLOADPACKAGEIMPL_H__EC04E19F_7AFA_48E5_B997_D62AAC0EB22D__INCLUDED_)
#define AFX_VMSUPLOADPACKAGEIMPL_H__EC04E19F_7AFA_48E5_B997_D62AAC0EB22D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "vmsUploadsWnd.h"

class vmsUploadPackageImpl : public vmsUploadPackage  
{
public:
	void add (LPCSTR pszPathName);
	void set_name (LPCSTR psz);
	void set_numberOfDaysToKeepThisUpload (int nDays);
	void set_supposedNumberOfDownloads (int);
	void set_passwordForDownload (LPCSTR pszPwd);
	void set_addLinkToUploadInCatalogue (BOOL bAdd);
	void set_Description (LPCSTR pszDesc);
	void set_Tags (LPCSTR pszTags);
	void set_OwnerName (LPCSTR pszName);
	void set_OwnerEmail (LPCSTR pszEmail);
	void set_RecipientEmail (LPCSTR pszEmail);

	vmsUploadPackageImpl();
	~vmsUploadPackageImpl();

public:
	bool is_shouldBeCompressed();
	int  m_nNumberOfDaysToKeepThisUpload;
	int  m_nSupposedNumberOfDlds;
	fsString m_strName;
	fsString m_strPassword;
	std::vector <fsString> m_vPathes;
	BOOL m_bAddLinkToUploadInCatalogue;
	fsString m_strDescription;
	fsString m_strTags;
	fsString m_strOwnerName;
	fsString m_strOwnerEmail;
	fsString m_strRecipientEmail;
	
	int m_iZipCompressMethod;
};

#endif 
