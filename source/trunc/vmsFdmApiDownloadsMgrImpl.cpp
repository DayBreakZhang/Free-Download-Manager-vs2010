/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "fdm.h"
#include "vmsFdmApiDownloadsMgrImpl.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

vmsFdmApiDownloadsMgrImpl::vmsFdmApiDownloadsMgrImpl()
{

}

vmsFdmApiDownloadsMgrImpl::~vmsFdmApiDownloadsMgrImpl()
{
	for (size_t i = 0; i < m_vTmpDldsStore.size (); i++)
		delete m_vTmpDldsStore [i];
}

vmsFdmApiDownloadsMgrImpl& vmsFdmApiDownloadsMgrImpl::o()
{
	static vmsFdmApiDownloadsMgrImpl o;
	return o;
}

int vmsFdmApiDownloadsMgrImpl::getDownloadCount()
{
	return _DldsMgr.GetCount ();
}

vmsFdmApiDownload* vmsFdmApiDownloadsMgrImpl::getDownload(int nIndex)
{
	vmsFdmApiDownloadImpl *dld = new vmsFdmApiDownloadImpl;
	dld->m_dld = _DldsMgr.GetDownload (nIndex);
	if (dld->m_dld == NULL)
	{
		delete dld;
		return NULL;
	}
	m_vTmpDldsStore.push_back (dld);
	return dld;
}

vmsFdmApiDownload* vmsFdmApiDownloadsMgrImpl::getDownloadById(UINT nId)
{
	vmsFdmApiDownloadImpl *dld = new vmsFdmApiDownloadImpl;
	dld->m_dld = _DldsMgr.GetDownloadByID (nId);
	m_vTmpDldsStore.push_back (dld);
	return dld;
}

UINT vmsFdmApiDownloadsMgrImpl::CreateDownload(vmsFdmApiCreateDownloadParameters *pNewDownload)
{
	return _pwndDownloads->CreateDownload (pNewDownload->pszUrl, FALSE, NULL, NULL, TRUE);
}
