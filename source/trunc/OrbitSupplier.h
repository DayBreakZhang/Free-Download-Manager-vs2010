/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef ORBIT_SUPPLIER_INCLUDED_FILE
#define ORBIT_SUPPLIER_INCLUDED_FILE

#include "supplier_interface.h"
#include "orbit_download.h"

class COrbitSupplier : public IDownloadSupplier
{
public:
	COrbitSupplier();
	virtual ~COrbitSupplier();

	virtual bool CheckSupplier() const; 
	virtual void Import(informer, void* pData, TImportResult& tImportResult) const; 
	virtual CString GetSupplierName() const; 

private:
	void appendDiagnostics(CString&sMsg, const CString& sDiagnostics) const;
	void appendErrorCode(CString& sMsg, HRESULT hr) const;
	void retreivePathToOrbitAppData(CString& sPath) const;
	
	void OpenFile(HANDLE& hFile, const CString& sDldListFilePath, LangPhrase enMsg) const;
	
	void ReadOrbitDldList(const CString& sDldListFilePath, CString& sDldList) const;
	bool retrieveDownloadFilePath(const TOrbitDownload& tOrbitDownload, CString& sDownloadFilePath) const;
	void configureDownloadFileName(const CString& sDownloadFilePath, vmsDownloadSmartPtr dld) const;
	void processDldImportedFromOrbit(const TOrbitDownload& tOrbitDownload, TImportResult& tImportResult) const;
	void processDldsImportedFromOrbit(OrbitDownloadsArray& arrDownloads, informer fnInformer, void* pData, TImportResult& tImportResult) const;
	void retrieveOrbitDownloadList(CString& sDldList) const;
	void retrieveOrbitDownloads(OrbitDownloadsArray& arrDownloads) const;
	void ReadFile(HANDLE& hFile, BYTE* bBuffer, DWORD& dwBytesRead, LangPhrase enMsg) const;
	void ReadOrbitDldFile(const CString& sDownloadFilePath, vmsDownloadSmartPtr dld) const;
	void configureIncompleteFileExt(vmsDownloadSmartPtr dld) const;
};

#endif
