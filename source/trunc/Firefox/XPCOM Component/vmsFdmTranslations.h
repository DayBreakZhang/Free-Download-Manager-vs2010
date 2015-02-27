/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSFDMTRANSLATIONS_H__82215CFF_025C_409B_A57C_323F1E9BBAF7__INCLUDED_)
#define AFX_VMSFDMTRANSLATIONS_H__82215CFF_025C_409B_A57C_323F1E9BBAF7__INCLUDED_

#include "fsLangMgr.h"	
#if _MSC_VER > 1000
#pragma once
#endif 

#include "../../lngphrases.h"

class vmsFdmTranslations  
{
public:
	static vmsFdmTranslations& o();
	LPCSTR GetString (int nIndex);
	vmsFdmTranslations();
	virtual ~vmsFdmTranslations();

protected:
	fsLangMgr m_lm;
};

#endif 
