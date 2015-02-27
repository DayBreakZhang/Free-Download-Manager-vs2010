/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef SUPPLIER_INTERFACE_INCLUDED_FILE
#define SUPPLIER_INTERFACE_INCLUDED_FILE

struct TImportResult
{
	TImportResult()
		: nTotal(-1), 
		  nSuccess(-1),
		  nFailure(-1),
		  nUnprocessed(-1)
	{
	}

	int nTotal;
	int nSuccess;
	int nFailure;
	int nUnprocessed;
};

class CImportResultGuard
{
public:
	CImportResultGuard(TImportResult& tImportResult) 
		: m_tImportResult(tImportResult),
		  m_bIsSuccess(false)
	{}
	virtual ~CImportResultGuard() 
	{
		if (m_bIsSuccess)
			++m_tImportResult.nSuccess;
		else
			++m_tImportResult.nFailure;

		--m_tImportResult.nUnprocessed;
	}
	void Success(bool bIsSuccess) {m_bIsSuccess = bIsSuccess;}

private:
	bool m_bIsSuccess;
	TImportResult& m_tImportResult;
};

typedef void (*informer)(int nTotal, int nImportedDownloads, const CString& sSupplierName, void* pData); 
typedef void (*initializer)(int nManagerIndex, bool bEnable, const CString & sSupplierName, void* pData); 
typedef void (*InitManagerResult)(int nManagerIndex, bool bChecked, const CString & sSupplierName, const TImportResult& tImportResult, void* pData); 

interface IDownloadSupplier
{
	virtual bool CheckSupplier() const = 0; 
	virtual void Import(informer, void* pData, TImportResult& tImportResult) const = 0; 
	virtual CString GetSupplierName() const = 0; 
};

#endif
