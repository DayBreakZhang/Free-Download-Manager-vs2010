/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "fsFindDownloadMgr.h"
#include "WaitDlg.h"
#include "DownloadsWnd.h"

extern CDownloadsWnd* _pwndDownloads;
extern LPCSTR fsStrStrNoCase(LPCSTR pszIn, LPCSTR pszWhat);

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

fsFindDownloadMgr::fsFindDownloadMgr()
{
	m_iIndex = -1;
}

fsFindDownloadMgr::~fsFindDownloadMgr()
{

}

void fsFindDownloadMgr::ReadSettings()
{
	m_dwFlags = _App.Find_Flags ();
	m_strWhat = _App.Find_What ();
	m_pGroup = _DldsGrps.FindGroup (_App.Find_GroupId ());
	if (m_pGroup == NULL)
		m_pGroup = _DldsGrps.FindGroup (GRP_OTHER_ID);
	m_tFrom = _App.Find_TimeFrom ();
	m_tTo = _App.Find_TimeTo ();
	m_uFileSizeFrom = _App.Find_FileSizeFrom ();
	m_uFileSizeTo = _App.Find_FileSizeTo ();
}

void fsFindDownloadMgr::PrepareFind()
{
	ReadSettings ();

	if (m_dwFlags & SEARCHWH_LISTOFDLDS)
		m_enWI = WII_LISTOFDLDS;
	else if (m_dwFlags & SEARCHWH_HISTOFDLDS)
		m_enWI = WII_HISTOFDLDS;
	else if (m_dwFlags & SEARCHWH_DELETED)
		m_enWI = WII_DELETED;
	else
	{
		m_iIndex = -1;
		return;
	}

	m_iIndex = 0;
}

BOOL fsFindDownloadMgr::FindNext()
{
	if (m_iIndex == -1)
		return FALSE;

	int cElems = GetElementCount ();

	if (cElems == 0)
	{
		m_iIndex = -1;
		return FALSE;
	}

	if (cElems < 600)
		FindNext_imp ();
	else
	{
		CWaitDlg dlg;
		dlg.StartWaiting (LS (L_SEARCHISPERFORMED), _threadFindNext, TRUE, this);
	}

	if (m_iIndex == -1)
		return FALSE;

	m_iIndex++;

	switch (m_enWI)
	{
		case WII_LISTOFDLDS:
			_pwndDownloads->ShowAllDownloads ();
			_pwndDownloads->SelectDownload ((fsDownload*)m_pFoundElement);
			break;

		case WII_HISTOFDLDS:
			_pwndDownloads->ShowAllHistory ();
			_pwndDownloads->SelectHistRecord ((fsDLHistoryRecord*)m_pFoundElement);
			break;

		case WII_DELETED:
			_pwndDownloads->ShowDeletedDownloads ();
			_pwndDownloads->SelectDeletedDownload ((fsDownload*)m_pFoundElement);
			break;
	}

	return TRUE;
}

int fsFindDownloadMgr::GetElementCount()
{
	int cElements = 0;

	if (m_dwFlags & SEARCHWH_LISTOFDLDS)
		cElements += _DldsMgr.GetCount ();
	
	if (m_dwFlags & SEARCHWH_HISTOFDLDS)
		cElements += _DldsMgr.m_histmgr.GetRecordCount ();

	if (m_dwFlags & SEARCHWH_DELETED)
		cElements += _DldsMgr.Get_DeletedDownloadCount ();

	return cElements;
}

void fsFindDownloadMgr::FindNext_imp(BOOL* pbCancel, int* piProgress)
{
	do 
	{
		if (m_iIndex == -1)
			m_iIndex = 0;

		switch (m_enWI)
		{
			case WII_LISTOFDLDS:
				FindNext_InListOfDlds (pbCancel, piProgress);
				break;

			case WII_HISTOFDLDS:
				FindNext_InHistoryOfDlds (pbCancel, piProgress);
				break;

			case WII_DELETED:
				FindNext_InDeleted (pbCancel, piProgress);
				break;
		}

		
		if (m_iIndex == -1 && NextFindSource (m_enWI) == FALSE)
			break;
	}
	while (m_iIndex == -1);
}

DWORD WINAPI fsFindDownloadMgr::_threadFindNext(LPVOID lp)
{
	ProcWaitInfo *info = (ProcWaitInfo*) lp;
	fsFindDownloadMgr* pThis = (fsFindDownloadMgr*) info->lpParam1;
	pThis->FindNext_imp (&info->bNeedStop, &info->iProgress);
	info->bWaitDone = TRUE;
	return 0;
}

BOOL fsFindDownloadMgr::NextFindSource(fsFDM_WhereIsIndex &wi)
{
	switch (wi)
	{
		case WII_LISTOFDLDS:
			if (m_dwFlags & SEARCHWH_HISTOFDLDS)
				wi = WII_HISTOFDLDS;
			else if (m_dwFlags & SEARCHWH_DELETED)
				wi = WII_DELETED;
			else
				return FALSE;
			break;

		case WII_HISTOFDLDS:
			if (m_dwFlags & SEARCHWH_DELETED)
				wi = WII_DELETED;
			else
				return FALSE;

		default:
			return FALSE;
	}

	return TRUE;
}

void fsFindDownloadMgr::FindNext_InListOfDlds(BOOL *pbCancel, int *piProgress)
{
	int cElems = GetElementCount ();

	_DldsMgr.LockList (true);

	int cDlds = _DldsMgr.GetCount ();

	for (int i = m_iIndex; i < cDlds; i++)
	{
		if (pbCancel && *pbCancel)
			break;

		vmsDownloadSmartPtr dld = _DldsMgr.GetDownload (i);
		if (IsSatisfies (dld))
		{
			_DldsMgr.UnlockList (true);
			m_iIndex = i;
			m_pFoundElement = dld;
			return;
		}

		if (piProgress)
			*piProgress = int ((double) cDlds / cElems * 100.0);
	}

	_DldsMgr.UnlockList (true);

	m_iIndex = -1;	
}

void fsFindDownloadMgr::FindNext_InHistoryOfDlds(BOOL *pbCancel, int *piProgress)
{
	int cElems = GetElementCount ();
	fsDownloadsHistoryMgr* mgr = &_DldsMgr.m_histmgr;
	int cRecs = mgr->GetRecordCount ();
	int cDidElems = 0;
	
	if (m_dwFlags & SEARCHWH_LISTOFDLDS)
		cDidElems += _DldsMgr.GetCount ();

	mgr->Lock ();

	for (int i = m_iIndex; i < cRecs; i++)
	{
		if (pbCancel && *pbCancel)
			break;

		fsDLHistoryRecord* rec = mgr->GetRecord (i);
		if (IsSatisfies (rec))
		{
			m_iIndex = i;
			m_pFoundElement = rec;
			mgr->Unlock ();
			return;
		}

		if (piProgress)
			*piProgress = int ((double) (cRecs + cDidElems) / cElems * 100.0);
	}

	mgr->Unlock ();

	m_iIndex = -1;	
}

void fsFindDownloadMgr::FindNext_InDeleted(BOOL *pbCancel, int *piProgress)
{
	int cElems = GetElementCount ();
	int cDlds = _DldsMgr.Get_DeletedDownloadCount ();
	int cDidElems = 0;
	
	if (m_dwFlags & SEARCHWH_LISTOFDLDS)
		cDidElems += _DldsMgr.GetCount ();
	if (m_dwFlags & SEARCHWH_HISTOFDLDS)
		cDidElems += _DldsMgr.m_histmgr.GetRecordCount ();

	for (int i = m_iIndex; i < cDlds; i++)
	{
		if (pbCancel && *pbCancel)
			break;

		vmsDownloadSmartPtr dld = _DldsMgr.Get_DeletedDownload (i);
		if (IsSatisfies (dld))
		{
			m_iIndex = i;
			m_pFoundElement = dld;
			return;
		}

		if (piProgress)
			*piProgress = int ((double) (cDlds + cDidElems) / cElems * 100.0);
	}

	m_iIndex = -1;	
}

BOOL fsFindDownloadMgr::IsSatisfies(vmsDownloadSmartPtr dld)
{
	if (m_dwFlags & SEARCHU_DLDGROUP)
	{
		if (dld->pGroup != m_pGroup)
			return FALSE;
	}

	if (m_dwFlags & SEARCHU_FILESIZE)
	{
		UINT64 size = dld->pMgr->GetLDFileSize ();
		if (size < m_uFileSizeFrom || size > m_uFileSizeTo)
			return FALSE;
	}

	if (m_dwFlags & SEARCHIN_COMMENT)
		if (fsStrStrNoCase (dld->strComment, m_strWhat))
			return TRUE;

	if (m_dwFlags & SEARCHIN_LOCFILENAME)
	{
		if (fsStrStrNoCase (dld->pMgr->get_OutputFilePathName (), m_strWhat))
			return TRUE;

		if (dld->pMgr->GetBtDownloadMgr ())
		{
			for (int i = 1; i < dld->pMgr->GetBtDownloadMgr ()->get_FileCount (); i++)
			{
				if (fsStrStrNoCase (dld->pMgr->GetBtDownloadMgr ()->get_OutputFilePathName (i), m_strWhat))
					return TRUE;
			}
		}
	}

	if (m_dwFlags & SEARCHIN_URL)
	{
		if (fsStrStrNoCase (dld->pMgr->get_URL (), m_strWhat))
			return TRUE;
	}

	if (m_dwFlags & SEARCHIN_FILENAME)
	{
		char sz [10000];
		CDownloads_Tasks::GetFileName (dld, sz);
		if (fsStrStrNoCase (sz, m_strWhat))
			return TRUE;
	}

	return FALSE;
}

BOOL fsFindDownloadMgr::IsSatisfies(fsDLHistoryRecord *rec)
{
	if (m_dwFlags & SEARCHU_FILESIZE)
	{
		if (rec->uFileSize < m_uFileSizeFrom || rec->uFileSize > m_uFileSizeTo)
			return FALSE;
	}

	if (m_dwFlags & SEARCHU_TIME)
	{
		fsDldHistRecFilter_Custom filter;
		filter.SetTimeRange (m_tFrom, m_tTo);
		if (filter.IsSatisfies (rec) == FALSE)
			return FALSE;
	}

	if (m_dwFlags & SEARCHIN_COMMENT)
		if (fsStrStrNoCase (rec->strComment, m_strWhat))
			return TRUE;

	if (m_dwFlags & SEARCHIN_LOCFILENAME)
		if (fsStrStrNoCase (rec->strSavedTo, m_strWhat))
			return TRUE;

	if (m_dwFlags & SEARCHIN_URL)
	{
		if (fsStrStrNoCase (rec->strURL, m_strWhat))
			return TRUE;
	}

	if (m_dwFlags & SEARCHIN_FILENAME)
	{
		if (fsStrStrNoCase (rec->strFileName, m_strWhat))
			return TRUE;
	}

	return FALSE;
}

BOOL fsFindDownloadMgr::IsFindNextAvail()
{
	return m_iIndex != -1;
}
