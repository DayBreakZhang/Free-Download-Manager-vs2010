#ifndef __FDMDLSMGR_H_
#define __FDMDLSMGR_H_

#include "fdmdl.h"

class vmsFdmApiDownloadsMgr
{
public:
	virtual int getDownloadCount () = NULL;
	virtual vmsFdmApiDownload* getDownload (int nIndex) = NULL;
	virtual vmsFdmApiDownload* getDownloadById (UINT nId) = NULL;
	// returns id of created download
	virtual UINT CreateDownload (struct vmsFdmApiCreateDownloadParameters* pNewDownload) = NULL;
};

struct vmsFdmApiCreateDownloadParameters
{
	LPCSTR pszUrl;
};


#endif //__FDMDLSMGR_H_