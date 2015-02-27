/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSMALICIOUSDOWNLOADCHECKER_H__4A03DA08_7975_488C_A08E_022F1B19DCB1__INCLUDED_)
#define AFX_VMSMALICIOUSDOWNLOADCHECKER_H__4A03DA08_7975_488C_A08E_022F1B19DCB1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class vmsMaliciousDownloadChecker  
{
public:
	
	fsInternetResult Check (LPCSTR pszUrl);
	
	void Stop();
	
	
	LPCSTR get_VirusCheckResult();
	
	float get_AverageRating();
	
	int get_MaliciousOpinionCount();
	
	int get_OpinionTotalCount();
	
	vmsMaliciousDownloadChecker();
	virtual ~vmsMaliciousDownloadChecker();

	
	static CString EncodeUrl (LPCSTR pszUrl);

protected:
	bool m_bNeedStop;
	class vmsSimpleFileDownloader* m_dldr;

	int m_cOpinions, m_cMalOpinions;
	float m_fRating;
	fsString m_strVirusCheckResult;
};

#endif 
