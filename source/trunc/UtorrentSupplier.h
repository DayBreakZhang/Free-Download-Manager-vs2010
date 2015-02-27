/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef UTORRENT_SUPPLIER_INCLUDED_FILE
#define UTORRENT_SUPPLIER_INCLUDED_FILE

#include "Bittorrent\fdmbtsupp\vmsUTorrentDownloadsDb.h"
#include "supplier_interface.h"
#include "orbit_download.h"

class CUtorrentSupplier : public IDownloadSupplier
{
public:
	CUtorrentSupplier();
	virtual ~CUtorrentSupplier();

	virtual bool CheckSupplier() const; 
	virtual void Import(informer, void* pData, TImportResult& tImportResult) const; 
	virtual CString GetSupplierName() const; 
	static bool UtorrentInstalled(LPSTR szPath);
	static void ImportUtorrentDownloads(informer fnInformer, void* pData, TImportResult& tImportResult, const CUtorrentSupplier* pUtorrentSupplier, LPSTR szPath);

	

private:
	void appendDiagnostics(CString&sMsg, const CString& sDiagnostics) const;
	void appendErrorCode(CString& sMsg, HRESULT hr) const;
};

#endif
