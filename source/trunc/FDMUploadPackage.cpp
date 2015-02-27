/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "FDMUploadPackage.h"

STDMETHODIMP CFDMUploadPackage::Add(BSTR bstrPathName)
{
	USES_CONVERSION;
	m_vFiles.push_back (W2A (bstrPathName));
	return S_OK;
}

STDMETHODIMP CFDMUploadPackage::get_Name(BSTR *pVal)
{
	USES_CONVERSION;
	*pVal = SysAllocString (A2W (m_strName)); 	
	return S_OK;
}

STDMETHODIMP CFDMUploadPackage::put_Name(BSTR newVal)
{
	USES_CONVERSION;
	m_strName = W2A (newVal);
	return S_OK;
}

STDMETHODIMP CFDMUploadPackage::GetFileCount(long *pCount)
{
	*pCount = m_vFiles.size ();
	return S_OK;
}

STDMETHODIMP CFDMUploadPackage::GetFilePath(long nIndex, BSTR *pbstrPathName)
{
	USES_CONVERSION;
	*pbstrPathName = SysAllocString (A2W (m_vFiles [nIndex]));
	return S_OK;
}
