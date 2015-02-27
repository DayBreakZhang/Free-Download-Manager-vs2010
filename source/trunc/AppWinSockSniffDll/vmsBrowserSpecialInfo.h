/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSBROWSERSPECIALINFO_H__57451844_E30D_49B4_9F13_A2F79DFC9429__INCLUDED_)
#define AFX_VMSBROWSERSPECIALINFO_H__57451844_E30D_49B4_9F13_A2F79DFC9429__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class vmsBrowserSpecialInfo  
{
public:
	struct UrlInfo
	{
		string strUrl;
		string strSrcTabUrl;
	};
public:
	void RemoveUrlInfo (int nIndex);
	UrlInfo* getUrlInfo (int nIndex);
	int findUrlIndex (LPCSTR pszUrl) const;
	void Unlock();
	void Lock();
	void AddUrl (const UrlInfo &url);
	static vmsBrowserSpecialInfo& o();
	vmsBrowserSpecialInfo();
	virtual ~vmsBrowserSpecialInfo();

protected:
	vmsCriticalSection m_csUrls;
	vector <UrlInfo> m_vUrls;
};

#endif 
