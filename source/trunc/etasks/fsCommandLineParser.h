/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_FSCOMMANDLINEPARSER_H__83B66E37_1776_4D30_A255_1BC65A140AFD__INCLUDED_)
#define AFX_FSCOMMANDLINEPARSER_H__83B66E37_1776_4D30_A255_1BC65A140AFD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class fsCommandLineParser  
{
public:
	
	BOOL Parse();
	
	int Get_ParameterCount();
	
	LPCSTR Get_Parameter(int iIndex);
	
	LPCSTR Get_ParameterValue (int iIndex);
	
	fsCommandLineParser();
	virtual ~fsCommandLineParser();

protected:
	struct fsCmdLineParameter
	{
		string strParam;	
		string strValue;	
	};
	
	vector <fsCmdLineParameter> m_vPars;
};

#endif 
