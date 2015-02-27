/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_FSIEUSERAGENT_H__6C5C6FE2_1F1F_4061_9F72_E74E38639298__INCLUDED_)
#define AFX_FSIEUSERAGENT_H__6C5C6FE2_1F1F_4061_9F72_E74E38639298__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class fsIEUserAgent  
{
public:
	void RemovePP (LPCSTR pszPP);
	void SetPP (LPCSTR pszPP);
	
	
	
	
	

	fsIEUserAgent();
	virtual ~fsIEUserAgent();

protected:
	
	void OpenUAKey();
	CRegKey m_keyUA;
	
	
	
	
};

#endif 
