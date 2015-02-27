/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "coredll.h"
#include "vmsUploadPackageImpl.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

vmsUploadPackageImpl::vmsUploadPackageImpl()
{
	m_bAddLinkToUploadInCatalogue = FALSE;
	m_nSupposedNumberOfDlds = 9;
	m_nNumberOfDaysToKeepThisUpload = 2;
	m_iZipCompressMethod = 0;
}

vmsUploadPackageImpl::~vmsUploadPackageImpl()
{

}

void vmsUploadPackageImpl::set_name(LPCSTR psz)
{
	m_strName = psz;
}

void vmsUploadPackageImpl::add(LPCSTR pszPathName)
{
	m_vPathes.push_back (pszPathName);
}

void vmsUploadPackageImpl::set_numberOfDaysToKeepThisUpload (int nDays)
{
	m_nNumberOfDaysToKeepThisUpload = nDays;
}

void vmsUploadPackageImpl::set_supposedNumberOfDownloads (int n)
{
	m_nSupposedNumberOfDlds = n;
}

void vmsUploadPackageImpl::set_passwordForDownload (LPCSTR pszPwd)
{
	m_strPassword = pszPwd ? pszPwd : "";
}

void vmsUploadPackageImpl::set_addLinkToUploadInCatalogue (BOOL bAdd)
{
	m_bAddLinkToUploadInCatalogue = bAdd;
}

void vmsUploadPackageImpl::set_Description (LPCSTR pszDesc)
{
	m_strDescription = pszDesc;
}

void vmsUploadPackageImpl::set_Tags (LPCSTR pszTags)
{
	m_strTags = pszTags;
}

void vmsUploadPackageImpl::set_OwnerName (LPCSTR pszName)
{
	m_strOwnerName = pszName;
}

void vmsUploadPackageImpl::set_OwnerEmail (LPCSTR pszEmail)
{
	m_strOwnerEmail = pszEmail;
}

void vmsUploadPackageImpl::set_RecipientEmail (LPCSTR pszEmail)
{
	m_strRecipientEmail = pszEmail;
}

bool vmsUploadPackageImpl::is_shouldBeCompressed()
{
	if (m_iZipCompressMethod != 0 || m_vPathes.size () > 1)
		return true;

	DWORD dw = GetFileAttributes (m_vPathes [0]);
	if (dw != (DWORD)-1)
		return (dw & FILE_ATTRIBUTE_DIRECTORY) != 0;

	return false;		
}
