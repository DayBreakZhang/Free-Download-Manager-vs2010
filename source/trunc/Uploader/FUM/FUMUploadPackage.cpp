/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FUM.h"
#include "FUMUploadPackage.h"

STDMETHODIMP CFUMUploadPackage::Add(BSTR bstrPathName)
{
	USES_CONVERSION;
	m_vFiles.push_back (W2A (bstrPathName));
	return S_OK;
}

STDMETHODIMP CFUMUploadPackage::get_Name(BSTR *pVal)
{
	USES_CONVERSION;
	*pVal = SysAllocString (A2W (m_strName)); 	
	return S_OK;
}

STDMETHODIMP CFUMUploadPackage::put_Name(BSTR newVal)
{
	USES_CONVERSION;
	m_strName = W2A (newVal);
	return S_OK;
}

STDMETHODIMP CFUMUploadPackage::GetFileCount(long *pCount)
{
	*pCount = m_vFiles.size ();
	return S_OK;
}

STDMETHODIMP CFUMUploadPackage::GetFilePath(long nIndex, BSTR *pbstrPathName)
{
	USES_CONVERSION;
	*pbstrPathName = SysAllocString (A2W (m_vFiles [nIndex]));
	return S_OK;
}
