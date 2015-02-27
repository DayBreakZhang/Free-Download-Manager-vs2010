/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSSINGLELINETOOLTIP_H__C7AC2541_51BC_4702_BD50_A32C88AFBD88__INCLUDED_)
#define AFX_VMSSINGLELINETOOLTIP_H__C7AC2541_51BC_4702_BD50_A32C88AFBD88__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "vmsUiWindow.h"

class vmsSingleLineTooltip : public vmsUiWindow
{
public:
	CSize getRequiredSize () const;
	void setText (LPCTSTR pszHtml);
	vmsSingleLineTooltip();
	virtual ~vmsSingleLineTooltip();

protected:
	CSize m_sRequired;
};

#endif 
