/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSIMAGE_H__23C3F1D7_011F_4A56_B3CF_025736AEE582__INCLUDED_)
#define AFX_VMSIMAGE_H__23C3F1D7_011F_4A56_B3CF_025736AEE582__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include <IImgCtx.h>

class vmsImage  
{
public:
	CSize get_Size();
	void Free();
	HRESULT Load (LPCSTR pszFile);
	vmsImage();
	virtual ~vmsImage();

protected:
	IImgCtx* m_pImage;
};

#endif 
