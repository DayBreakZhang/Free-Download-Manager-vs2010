/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_FSCOMMANDLINEPARSER_H__83B66E37_1776_4D30_A255_1BC65A140AFD__INCLUDED_)
#define AFX_FSCOMMANDLINEPARSER_H__83B66E37_1776_4D30_A255_1BC65A140AFD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include <fsString.h>
#include "list.h"

class fsCommandLineParser  
{
public:
	
	BOOL Parse();
	
	int Get_ParameterCount();
	
	LPCSTR Get_Parameter(int iIndex);
	
	LPCSTR Get_ParameterValue (int iIndex);
	size_t FindParameterIndex (const tstring& tstrParam) const 
	{
		for (size_t i = 0; i < m_vPars.size (); i++)
		{
			if (!_tcsicmp (m_vPars [i].strParam, tstrParam.c_str ()))
				return i;
		}
		return SIZE_T_MAX;
	}
	
	fsCommandLineParser();
	virtual ~fsCommandLineParser();

protected:
	struct fsCmdLineParameter
	{
		fsString strParam;	
		fsString strValue;	
	};
	
	std::vector <fsCmdLineParameter> m_vPars;
};

#endif 
