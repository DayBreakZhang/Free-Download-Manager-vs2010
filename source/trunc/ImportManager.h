/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef IMPORT_MANAGER_INCLUDED_FILE
#define IMPORT_MANAGER_INCLUDED_FILE

#include "supplier_interface.h"

struct TSupplier
{
	TSupplier();
	TSupplier(IDownloadSupplier* _pSupplier, bool _bIsEnabled, bool _bIsChecked, int _nIndex);

	IDownloadSupplier* pSupplier;
	bool bIsEnabled; 
	bool bIsChecked; 
	int nIndex; 
	TImportResult tImportResult; 
};

typedef CArray<TSupplier, TSupplier&> SupplierArray;

class CImportManager
{
public:
	CImportManager();
	virtual~ CImportManager();
	void Init(informer fnWizardInformer, initializer fnWizardInitializer, InitManagerResult fnInitManagerResult, void* pData, HWND hWizardWnd); 
	void InitWizard(); 
	void Run(); 
	void InitResultPage(); 
	void CheckSupplier(int nIndex, bool bCheck); 
	bool HasSuppliersInstalled(bool bExcludeMtorrent); 

private:
	int procErr(std::runtime_error& exc, const CString& sSupplierName, bool bIsLast);
	int procErr(CException*& pExc, const CString& sSupplierName, bool bIsLast);
	void appendDiagnostics(CString&sMsg, const CString& sDiagnostics) const;

	SupplierArray m_arrSuppliers;
	informer m_fnWizardInformer;
	initializer m_fnWizardInitializer;
	InitManagerResult m_fnInitManagerResult;
	void* m_pData; 
	HWND m_hWizardWnd; 

};

#endif
