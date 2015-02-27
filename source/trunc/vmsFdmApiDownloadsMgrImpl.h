/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSFDMAPIDOWNLOADSMGRIMPL_H__3F2EE66F_9B6F_497F_9B6E_4EB229CFF813__INCLUDED_)
#define AFX_VMSFDMAPIDOWNLOADSMGRIMPL_H__3F2EE66F_9B6F_497F_9B6E_4EB229CFF813__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "Plugins API/fdm.h"
#include "vmsFdmApiDownloadImpl.h"

class vmsFdmApiDownloadsMgrImpl : public vmsFdmApiDownloadsMgr  
{
public:
	UINT CreateDownload (vmsFdmApiCreateDownloadParameters* pNewDownload);
	vmsFdmApiDownload* getDownloadById (UINT nId);
	vmsFdmApiDownload* getDownload (int nIndex);
	int getDownloadCount();
	static vmsFdmApiDownloadsMgrImpl& o();
	vmsFdmApiDownloadsMgrImpl();
	virtual ~vmsFdmApiDownloadsMgrImpl();

	std::vector <vmsFdmApiDownloadImpl*> m_vTmpDldsStore;

};

#endif 
