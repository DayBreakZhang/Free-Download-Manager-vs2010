/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSEXTERNALHTTPTRAFFICCOLLECTOR_H__64FB6255_14A4_4763_B10A_F055A329DE1D__INCLUDED_)
#define AFX_VMSEXTERNALHTTPTRAFFICCOLLECTOR_H__64FB6255_14A4_4763_B10A_F055A329DE1D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "vmsHttpTrafficCollector.h"

class vmsExternalHttpTrafficCollector  
{
public:
	void OnHttpDialogClosed (UINT nUID);
	void OnHttpDialogDataReceived (UINT nUID, LPBYTE pbData, UINT nSize);
	UINT OnNewHttpDialog (LPCSTR pszUrl, LPCSTR pszRequestHdrs, LPCSTR pszRespHdrs);
	vmsExternalHttpTrafficCollector(vmsHttpTrafficCollector *pHttpTraffic);
	virtual ~vmsExternalHttpTrafficCollector();

protected:
	vmsHttpTrafficCollector *m_pHttpTraffic;
};

#endif 
