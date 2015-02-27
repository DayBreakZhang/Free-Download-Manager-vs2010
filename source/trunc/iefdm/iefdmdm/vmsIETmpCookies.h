/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSIETMPCOOKIES_H__5CE05C63_3540_4132_9D7A_D08FA5CBC974__INCLUDED_)
#define AFX_VMSIETMPCOOKIES_H__5CE05C63_3540_4132_9D7A_D08FA5CBC974__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class vmsIETmpCookies  
{
public:
	
	LPCSTR get_PostData (int nIndex);
	LPCSTR get_Referer (int nIndex);
	LPCSTR get_Cookies (int nIndex);
	
	int Find (LPCSTR pszUrl);

	vmsIETmpCookies();
	virtual ~vmsIETmpCookies();

protected:
	
	
	static tstring GetLevel2DomainName (LPCSTR pszHostName);
	
	void ProcessFile (LPCSTR pszFile);
	
	
	void GetListOfKnownCookies();
	
	HANDLE m_mxFile;
	
	vector <string> m_vUrls;
	vector <string> m_vCookies;
	vector <string> m_vPostDatas;
	vector <string> m_vBeforeNavUrls;
};

#endif 
