/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef QUERY_STORING_SERVICE_INFO_GUARD
#define QUERY_STORING_SERVICE_INFO_GUARD

template<class T>
class CQueryStoringDownloadListGuard
{
public:
	CQueryStoringDownloadListGuard(T* pQueryManager)
		: m_pQueryManager(pQueryManager),
		  m_IsChanged(false)
	{}
	virtual ~CQueryStoringDownloadListGuard()
	{
		if (m_IsChanged && m_pQueryManager) {
			m_pQueryManager->QueryStoringDownloadList();
		}
	}

	void QueryStoringDownloadList()
	{
		m_IsChanged = true;
	}

private:
	T* m_pQueryManager;
	bool m_IsChanged;
};

#endif
