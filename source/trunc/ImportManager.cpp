/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "StdAfx.h"
#include "ImportManager.h"
#include "Utils.h"
#include "OrbitSupplier.h"
#include "UtorrentSupplier.h"
#include "vmsLogger.h"

TSupplier::TSupplier()
	: pSupplier(0),
	  bIsEnabled(false),
	  bIsChecked(false)
{
}

TSupplier::TSupplier(IDownloadSupplier* _pSupplier, bool _bIsEnabled, bool _bIsChecked, int _nIndex)
	: pSupplier(_pSupplier),
	  bIsEnabled(_bIsEnabled),
	  bIsChecked(_bIsChecked),
	  nIndex(_nIndex)
{
}

CImportManager::CImportManager()
	: m_fnWizardInformer(0),
	  m_pData(0),
	  m_hWizardWnd(0)
{
	InitArray(m_arrSuppliers);
}

CImportManager::~CImportManager()
{
	int i = 0;
	for (i = 0; i <= m_arrSuppliers.GetUpperBound(); i++) {
		TSupplier& tSupplier = m_arrSuppliers[i];
		if (tSupplier.pSupplier)
			delete tSupplier.pSupplier;
	}
}

void CImportManager::Init(informer fnWizardInformer, initializer fnWizardInitializer, InitManagerResult fnInitManagerResult, void* pData, HWND hWizardWnd)
{
	m_fnWizardInformer = fnWizardInformer;
	m_fnWizardInitializer = fnWizardInitializer;
	m_fnInitManagerResult = fnInitManagerResult;

	m_pData = pData;
	m_hWizardWnd = hWizardWnd;

	

	
	std::auto_ptr<CUtorrentSupplier> pUtorrentSupplierGuard (new CUtorrentSupplier());
	CUtorrentSupplier* pUtorrentSupplier = pUtorrentSupplierGuard.get();
	if (pUtorrentSupplier == 0) {
		CString sMsg = LS (L_OUTOFMEMORY);
		throw std::runtime_error((const char*)sMsg);
	}

	
	
	TSupplier tUtorrentSupplier(pUtorrentSupplierGuard.release(), false, false, 0);
	m_arrSuppliers.Add(tUtorrentSupplier);

	
	std::auto_ptr<COrbitSupplier> pOrbitSupplierGuard (new COrbitSupplier());
	COrbitSupplier* pOrbitSupplier = pOrbitSupplierGuard.get();
	if (pOrbitSupplier == 0) {
		CString sMsg = LS (L_OUTOFMEMORY);
		throw std::runtime_error((const char*)sMsg);
	}

	
	
	TSupplier tOrbitSupplier(pOrbitSupplierGuard.release(), false, false, 1);
	m_arrSuppliers.Add(tOrbitSupplier);
}

void CImportManager::InitWizard()
{
	ASSERT(m_fnWizardInitializer != 0 && m_pData != 0);

	int i = 0;
	for (i = 0; i <= m_arrSuppliers.GetUpperBound(); i++) {
		TSupplier& tSupplier = m_arrSuppliers[i];
		IDownloadSupplier* pSupplier = tSupplier.pSupplier;
		if (pSupplier) {
			tSupplier.bIsEnabled = pSupplier->CheckSupplier();
			CString sSupplierName = pSupplier->GetSupplierName();
			m_fnWizardInitializer(tSupplier.nIndex, tSupplier.bIsEnabled, sSupplierName, m_pData);
		}
	}
}

int CImportManager::procErr(std::runtime_error& exc, const CString& sSupplierName, bool bIsLast)
{
	CString sFmt = LS (L_DOWNLOADS_IMPORT_HAS_BEEN_STOPPED);
	CString sTmp;
	sTmp.Format(sFmt, (LPCTSTR)sSupplierName);

	CString sMsg = sTmp;
	sMsg += " ";
	sMsg += exc.what();

	UINT nType = MB_ICONERROR;

	if (!bIsLast) {
		sMsg += " ";
		sMsg += LS (L_REQUEST_TO_CONTINUE_IMPORT);
		nType |= MB_YESNO;
	} else {
		nType |= MB_OK;
	}

	return ::MessageBox(m_hWizardWnd, (LPCTSTR)sMsg, LS (L_ERR), nType);
}

void CImportManager::appendDiagnostics(CString&sMsg, const CString& sDiagnostics) const
{
	CString sTmp;
	CString sFmt = LS (L_SYS_DIAGNOSTICS_FMT);
	sTmp.Format((LPCTSTR)sFmt, (LPCTSTR)sDiagnostics);
	sMsg += " ";
	sMsg += sTmp;
}

int CImportManager::procErr(CException*& pExc, const CString& sSupplierName, bool bIsLast)
{
	CString sFmt = LS (L_DOWNLOADS_IMPORT_HAS_BEEN_STOPPED);
	CString sTmp;
	sTmp.Format(sFmt, (LPCTSTR)sSupplierName);

	CString sMsg = sTmp;
	sMsg += " ";

	TCHAR szMsg[1024] = {0,};
	if (!pExc->GetErrorMessage(szMsg, 1024)) {
		szMsg[1023] = 0;
		appendDiagnostics(sMsg, szMsg);
	} else {
		sMsg += " ";
		sMsg += "Unkown error";
	}
	pExc->Delete();

	UINT nType = MB_ICONERROR;

	if (!bIsLast) {
		sMsg += " ";
		sMsg += LS (L_REQUEST_TO_CONTINUE_IMPORT);
		nType |= MB_YESNO;
	} else {
		nType |= MB_OK;
	}

	return ::MessageBox(m_hWizardWnd, (LPCTSTR)sMsg, LS (L_ERR), nType);
}

void CImportManager::Run()
{
	ASSERT(m_fnWizardInformer != 0 && m_pData != 0);

	int i = 0;
	for (i = 0; i <= m_arrSuppliers.GetUpperBound(); i++) {
		TSupplier& tSupplier = m_arrSuppliers[i];
		IDownloadSupplier* pSupplier = tSupplier.pSupplier;
		if (pSupplier && tSupplier.bIsChecked) {
			CString sSupplierName = pSupplier->GetSupplierName();
			bool bIsLast = (i == m_arrSuppliers.GetUpperBound());
			try {
				
				m_fnWizardInformer(-1, -1, sSupplierName, m_pData);
				
				pSupplier->Import(m_fnWizardInformer, m_pData, tSupplier.tImportResult);
			} 
			catch (std::runtime_error& exc) 
			{
				vmsLogger::WriteLog("CImportManager::Run std::runtime_error " + tstring(exc.what()));

				if (procErr(exc, sSupplierName, bIsLast) != IDYES)
					break;
			}
			catch (CException* pExc)
			{
				tstring bufa;
				bufa.resize(1024);
				pExc->GetErrorMessage(&bufa.front(), 1024);
				vmsLogger::WriteLog("CImportManager::Run " + tstring(bufa));

				if (procErr(pExc, sSupplierName, bIsLast) != IDYES)
					break;
			}
		}
	}
}

void CImportManager::InitResultPage()
{
	int i = 0;
	for (i = 0; i <= m_arrSuppliers.GetUpperBound(); i++) {
		TSupplier& tSupplier = m_arrSuppliers[i];
		IDownloadSupplier* pSupplier = tSupplier.pSupplier;
		if (pSupplier) {
			tSupplier.bIsEnabled = pSupplier->CheckSupplier();
			CString sSupplierName = pSupplier->GetSupplierName();
			m_fnInitManagerResult(tSupplier.nIndex, tSupplier.bIsChecked, sSupplierName, tSupplier.tImportResult, m_pData);
		}
	}
}

void CImportManager::CheckSupplier(int nIndex, bool bCheck)
{
	ASSERT(nIndex >= 0 && nIndex <= m_arrSuppliers.GetUpperBound());

	int i = 0;
	for (i = 0; i <= m_arrSuppliers.GetUpperBound(); i++) {
		TSupplier& tSupplier = m_arrSuppliers[i];
		if (tSupplier.nIndex == nIndex) {
			tSupplier.bIsChecked = bCheck;
			break;
		}
	}
}

bool CImportManager::HasSuppliersInstalled(bool bExcludeMtorrent)
{
	CString sMtorrentSupplier = LS (L_UTORRENT_MANAGER);

	int i = 0;
	for (i = 0; i <= m_arrSuppliers.GetUpperBound(); i++) {
		TSupplier& tSupplier = m_arrSuppliers[i];
		IDownloadSupplier* pSupplier = tSupplier.pSupplier;
		if (pSupplier) {
			CString sSupplierName = pSupplier->GetSupplierName();
			if (bExcludeMtorrent && sMtorrentSupplier.Compare(sSupplierName) == 0)
				continue;
			if (pSupplier->CheckSupplier())
				return true;
		}
	}
	return false;
}
