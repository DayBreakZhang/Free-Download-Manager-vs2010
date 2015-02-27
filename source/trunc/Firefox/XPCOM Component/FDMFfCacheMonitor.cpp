/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "FDMFfCacheMonitor.h"
#include "vmsFlvSniffDll.h"
#include "xrfix.h"

XRFIX_NS_IMPL_ISUPPORTS1(CFDMFfCacheMonitor, IFDMFfCacheMonitor, IFDMFFCACHEMONITOR_IID)

CFDMFfCacheMonitor::CFDMFfCacheMonitor()
{

}

CFDMFfCacheMonitor::~CFDMFfCacheMonitor()
{

}

NS_IMETHODIMP CFDMFfCacheMonitor::OnNewHttpDialog (const char *pszUrl, const char *pszReqHdrs, const char *pszRespHdrs, PRUint32 *_retval)
{
	*_retval = vmsFlvSniffDll::onNewHttpDialog (pszUrl, pszReqHdrs, pszRespHdrs);
	return NS_OK;
}

NS_IMETHODIMP CFDMFfCacheMonitor::OnDataReceived (PRUint32 nUID, PRUint32 count, PRUint8 *data)
{
	vmsFlvSniffDll::onHttpDialogDataReceived (nUID, data, count);
	return NS_OK;
}

NS_IMETHODIMP CFDMFfCacheMonitor::OnDialogClosed (PRUint32 nUID)
{
	vmsFlvSniffDll::onHttpDialogClosed (nUID);
	return NS_OK;
}
