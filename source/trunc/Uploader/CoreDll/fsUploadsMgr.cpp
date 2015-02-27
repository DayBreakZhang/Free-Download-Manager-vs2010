/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "fsUploadsMgr.h"
#include "vmsSharedData.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

fsUploadsMgr::fsUploadsMgr()
{
	BOOL bNeedInit = FALSE;

	if (FALSE == m_shdata.Aquire ("mf - fumcore - shdata", TRUE))
	{
		m_shdata.Aquire ("mf - fumcore - shdata", FALSE, sizeof (LONG) + 9 + sizeof (LONG));
		bNeedInit = TRUE;
	}

	
	m_pnUplNextId = (LPLONG)m_shdata.get_Data ();
	m_pbFileCellBusy = ((LPBYTE)m_shdata.get_Data ()) + sizeof (LONG);
	m_pnNextSharedMemId = (LPLONG)(m_pbFileCellBusy + 9);

	if (bNeedInit)
	{
		*m_pnUplNextId = 0;
		ZeroMemory (m_pbFileCellBusy, 9);
		*m_pnNextSharedMemId = 0;
	}
	

	m_pfnEvents = NULL;
	m_mxAccFiles = CreateMutex (NULL, FALSE, "mx - fumcore - uploadsfiles");
	m_nFile = -1;
	m_cDontSaveUploads = 0;
}

fsUploadsMgr::~fsUploadsMgr()
{
	m_pbFileCellBusy [m_nFile] = FALSE;
}

void fsUploadsMgr::Add(vmsUploadSmartPtr upl, BOOL bKeepIdAsIs)
{
	if (bKeepIdAsIs == FALSE)
		upl->nID = InterlockedIncrement (m_pnUplNextId);
	else
		*m_pnUplNextId = max (*m_pnUplNextId, (LONG)upl->nID+1);

	upl->pMgr->SetEventFunc (_UploadMgrEvents, this);

	SYSTEMTIME time;
	GetLocalTime (&time);
	SystemTimeToFileTime (&time, &upl->dateAdded);

	m_vUploads.push_back (upl);

	ProcessUploads ();
}

int fsUploadsMgr::GetCount()
{
	return m_vUploads.size ();
}

void fsUploadsMgr::ProcessUploads()
{
	for (size_t i = 0; i < m_vUploads.size (); i++)
	{
		vmsUploadSmartPtr upl = m_vUploads [i];
		if (upl->bAutostart && upl->pMgr->IsDone () == FALSE)
		{
			if (upl->pMgr->IsRunning () == FALSE)
				upl->pMgr->StartUploading ();
			return;
		}
	}
}

DWORD fsUploadsMgr::_UploadMgrEvents(fsUploadMgr* pMgr, fsUploadMgrEvent umgrEv, 
			DWORD dwData, LPVOID pData, LPVOID lpThis)
{
	fsUploadsMgr *pthis = (fsUploadsMgr*) lpThis;

	vmsUploadSmartPtr upl = pthis->FindUploadByManager (pMgr);

	switch (umgrEv)
	{
	case UMGRE_BEFORE_UPLOAD:
		char szStopReason [10000]; *szStopReason = 0;
		if (FALSE == _pDllCaller->OnBeforeUpload (szStopReason, (bool*)pData))
		{
			if (*szStopReason)
				pthis->OnMessageRecieved (upl, szStopReason, EDT_RESPONSE_E);
			return FALSE;
		}
		return TRUE;

	case UMGRE_ZIP_FILES_START:
		pthis->OnMessageRecieved (upl, LS (L_PREP_ZIP_ARCHIVE), EDT_INQUIRY);
		break;

	case UMGRE_ZIP_FILES_FAILED:
		pthis->OnMessageRecieved (upl, LS (L_PREP_ZIP_ARCHIVE_FAILED), EDT_RESPONSE_E);
		break;

	case UMGRE_ZIP_FILES_DONE:
		pthis->OnMessageRecieved (upl, LS (L_PREP_ZIP_ARCHIVE_OK), EDT_RESPONSE_S);
		break;

	case UMGRE_CRC_UPLOAD_FILE:
		pthis->OnMessageRecieved (upl, LS (L_CACL_CHECKSUM), EDT_INQUIRY);
		break;

	case UMGRE_CRC_UPLOAD_FILE_DONE:
		pthis->OnMessageRecieved (upl, LS (L_SUCCESS), EDT_RESPONSE_S);
		break;

	case UMGRE_CRC_UPLOAD_FILE_FAILED:
		pthis->OnMessageRecieved (upl, LS (L_FAILED), EDT_RESPONSE_E);
		break;

	case UMGRE_REQ_UPLOAD_INIT:
		pthis->OnMessageRecieved (upl, LS (L_SENDING_REQ_TO_SERV), EDT_INQUIRY);
		break;

	case UMGRE_REQ_UPLOAD_INIT_DONE:
		pthis->OnMessageRecieved (upl, LS (L_SUCCESS), EDT_RESPONSE_S);
		break;

	case UMGRE_REQ_UPLOAD_INIT_FAILED:
		char sz [1000];
		_pDllCaller->IRToStr ((fsInternetResult)dwData, sz, sizeof (sz));
		pthis->OnMessageRecieved (upl, sz, EDT_RESPONSE_E);
		break;

	case UMGRE_SENDING_UPLOAD_DETAILS:
		pthis->OnMessageRecieved (upl, LS (L_SENDING_UPL_DETAILS), EDT_INQUIRY);
		break;

	case UMGRE_SENDING_UPLOAD_DETAILS_DONE:
		pthis->OnMessageRecieved (upl, LS (L_UPL_DETAILS_SENT), EDT_RESPONSE_S);
		break;

	case UMGRE_SENDING_UPLOAD_DETAILS_FAILED:
		pthis->OnMessageRecieved (upl, LS (L_FAILED_TO_SEND_UPL_DETAILS), EDT_RESPONSE_E);
		_pDllCaller->IRToStr ((fsInternetResult)dwData, sz, sizeof (sz));
		pthis->OnMessageRecieved (upl, sz, EDT_RESPONSE_E);
		break;

	case UMGRE_NEED_ASK_CAPTCHA_VALUE:
		lstrcpy (sz, (LPCSTR)dwData); 
		pthis->Event (upl, UME_ASK_CAPTCHA_VALUE, sz);
		lstrcpy ((LPSTR)pData, sz); 
		break;

	case UMGRE_VALIDATING_UPLOAD:
		pthis->OnMessageRecieved (upl, LS (L_ACTIVATING_UPL), EDT_INQUIRY);
		break;

	case UMGRE_VALIDATING_UPLOAD_DONE:
		pthis->OnMessageRecieved (upl, LS (L_ACTIVATING_UPL_OK), EDT_RESPONSE_S);
		break;

	case UMGRE_VALIDATING_UPLOAD_FAILED:
		pthis->OnMessageRecieved (upl, LS (L_ACTIVATING_UPL_FAILED), EDT_RESPONSE_E);
		if (dwData != IR_FILENOTFOUND) 
		{
			_pDllCaller->IRToStr ((fsInternetResult)dwData, sz, sizeof (sz));
			pthis->OnMessageRecieved (upl, sz, EDT_RESPONSE_E);
		}
		break;
		
	case UMGRE_UPLOADER_EVENT:
	{
		fsInternetUploaderEvent ev = (fsInternetUploaderEvent)dwData;

		switch (ev)
		{
		case IUE_OPENINGFILEONDISK:
			pthis->OnMessageRecieved (upl, LS (L_OPENINGFILE), EDT_INQUIRY);
			break;

		case IUE_FILE_WAS_OPENED:
			pthis->OnMessageRecieved (upl, LS (L_SUCCESS), EDT_RESPONSE_S);
			break;

		case IUE_E_FAILEDTOOPENSRCFILE:
			pthis->OnMessageRecieved (upl, LS (L_FAILED), EDT_RESPONSE_E);
			break;

		case IUE_E_SRCFILESIZEWASCHANGED:
			pthis->OnMessageRecieved (upl, LS (L_UPL_FILE_WAS_CHANED), EDT_RESPONSE_E);
			break;

		case IUE_CONNECTING:
			pthis->OnMessageRecieved (upl, LS (L_CONNECTING_TO_UPL_SRV), EDT_INQUIRY);
			break;

		case IUE_CONNECTED:
			pthis->OnMessageRecieved (upl, LS (L_CONNECTED_TO_UPL_SRV_OK), EDT_RESPONSE_S);
			break;

		case IUE_MESSAGE:
			fsInternetUploaderMessage *ium; ium = (fsInternetUploaderMessage*)pData;
			pthis->OnMessageRecieved (upl, ium->pszText, ium->enType);
			break;

		case IUE_E_UNEXPECTED:
			pthis->OnMessageRecieved (upl, LS (L_UNEXP_ERR), EDT_RESPONSE_E);
			break;
		}

		pthis->Event (upl, UME_UPLOADER_EVENT, (LPVOID)ev);
	}
	break;

	case UMGRE_STOPPED_OR_DONE:
		if (upl->pMgr->IsDone ())
			pthis->OnMessageRecieved (upl, LS (L_DONE), EDT_DONE);
		else
		{
			upl->bAutostart = FALSE;
			pthis->OnMessageRecieved (upl, LS (L_STOPPED), EDT_RESPONSE_S);
		}
		pthis->Event (upl, UME_UPLOAD_STOPPED_OR_DONE);
		pthis->ProcessUploads ();
		break;

	case UMGRE_UPLOADER_STOPPED_OR_DONE:
		if (upl->pMgr->GetUploader ()->IsDone ())
			pthis->OnMessageRecieved (upl, LS (L_UPLOADED_OK), EDT_DONE);
		else
			pthis->OnMessageRecieved (upl, LS (L_UPLOAD_STOPPED), EDT_RESPONSE_S);
		break;
	}

	pthis->Event (upl, UME_UPLOAD_STATE_CHANGED);

	return 0;
}

vmsUploadSmartPtr fsUploadsMgr::GetUpload(int nIndex)
{
	return m_vUploads [nIndex];
}

void fsUploadsMgr::SetEventFunc(fntUploadsMgrEventFunc pfn, LPVOID lpParam)
{
	m_pfnEvents = pfn;
	m_lpEventParam = lpParam;
}

DWORD fsUploadsMgr::Event(vmsUploadSmartPtr upl, fsUploadsMgrEvent ev, LPVOID pData)
{
	if (m_pfnEvents)
		return m_pfnEvents (this, upl, ev, pData, m_lpEventParam);
	return 0;
}

vmsUploadSmartPtr fsUploadsMgr::FindUploadByManager(fsUploadMgr *pMgr)
{
	try {

		for (size_t i = 0; i < m_vUploads.size (); i++)
		{
			if (m_vUploads [i]->pMgr == pMgr)
				return m_vUploads [i];
		}

	}catch (...) {}

	return NULL;
}

void fsUploadsMgr::OnMessageRecieved(vmsUploadSmartPtr upl, LPCSTR pszText, fsInternetUploaderMessageType enType)
{
	fsDescEvent descEv;
	GetEventColors (enType, descEv.clrText, descEv.clrBg, descEv.iImage);
	descEv.pszEvent = new char [lstrlen (pszText) + 1];
	lstrcpy (descEv.pszEvent, pszText);

	SYSTEMTIME time;
	GetLocalTime (&time);
	SystemTimeToFileTime (&time, &descEv.timeEvent);

	upl->log.add (&descEv);

	Event (upl, UME_UPLOAD_LOG_ADDED);
}

void fsUploadsMgr::StartUploads(UPLS_LIST_REF v)
{
	for (size_t i = 0; i < v.size (); i++)
	{
		v [i]->bAutostart = TRUE;
		v [i]->pMgr->StartUploading ();
	}
}

void fsUploadsMgr::StopUploads(UPLS_LIST_REF v, BOOL bByUser)
{
	for (size_t i = 0; i < v.size (); i++)
	{
		v [i]->pMgr->StopUploading ();
		if (bByUser)
			v [i]->bAutostart = FALSE;
	}
}

void fsUploadsMgr::DeleteUploads(UPLS_LIST_REF v)
{
	
	std::vector <size_t> vIndexes;
	size_t cUpls = v.size ();
	size_t nStart = 0;	

	size_t i = 0;
	for (i = 0; i < cUpls; i++)
		vIndexes.push_back ((size_t)-1);

	for (i = 0; i < m_vUploads.size (); i++)
	{
		vmsUploadSmartPtr upl = m_vUploads [i];

		for (size_t j = nStart; j < cUpls; j++)
		{
			if (upl == v.at (j))
			{				
				vIndexes [j] = i;

				size_t k = j;
				for (k = j; k > nStart && vIndexes [k - 1] != -1; k--)
					;
				if (k == nStart)
					nStart = j + 1;
				break;
			}
		}
	}
	

	UPLS_LIST *pv = new UPLS_LIST;

	vmsUploadSmartPtr uplFake;
	Upload_CreateInstance (uplFake);

	for (i = 0; i < (UINT)v.size (); i++)
	{
		vmsUploadSmartPtr upl = v.at (i);

		int iIndex = vIndexes [i];
		if (iIndex == -1) 
			continue;

		upl->pMgr->SetEventFunc (NULL, 0);

		Event (upl, UME_UPLOAD_WILL_BE_DELETED);

		m_vUploads [iIndex] = uplFake;
		
		pv->push_back (upl);
	}

	UPLS_LIST v2;
	for (i = 0; i < m_vUploads.size (); i++)
	{
		if (m_vUploads [i] != uplFake)
			v2.push_back (m_vUploads [i]);
	}
	m_vUploads = v2;	

	Event (NULL, UME_UPLOADS_WERE_DELETED);

	ProcessUploads ();

	DWORD dw;
	CloseHandle (
		CreateThread (NULL, 0, _threadDeleteUploads, pv, 0, &dw));
}

DWORD WINAPI fsUploadsMgr::_threadDeleteUploads(LPVOID lp)
{
	UPLS_LIST *pv = (UPLS_LIST*) lp;

	UINT msg = RegisterWindowMessage (_pszUploadsDeletedNotifyMsg);
	UINT nMemId = InterlockedIncrement (_UplsMgr.m_pnNextSharedMemId);
	CString str; str.Format (_pszSharedMemoryName, nMemId);
	vmsSharedDataT <UINT> gdata (str, FALSE, pv->size ());
	int cUplds = 0;

	for (size_t i = 0; i < pv->size (); i++)
	{
		vmsUploadSmartPtr upl = pv->at (i); 
		
		if ((upl->dwFlags & UF_READONLY) == 0)
		{
			upl->pMgr->StopUploading (TRUE);
			upl->pMgr->DeleteZipFile ();
		}

		if ((upl->dwFlags & UF_DONTNOTIFYABOUTDELETE) == 0)
			gdata [cUplds++] = upl->nID;
	}

	DWORD dw;
	if (cUplds)
		SendMessageTimeout (HWND_BROADCAST, msg, cUplds, nMemId, 0, 5000, &dw);

	delete pv;
	return 0;
}

#define CLR_INQUIRY			RGB (255, 255, 210)
#define CLR_INQUIRY2		RGB (255, 255, 220)
#define CLR_DONE			RGB (230, 255, 250)
#define CLR_RESPONSE_S		RGB (230, 255, 230)
#define CLR_RESPONSE_S2		RGB (250, 255, 240)
#define CLR_RESPONSE_E		RGB (250, 240, 240)
#define CLR_WARNING			RGB (250, 240, 200)

void fsUploadsMgr::GetEventColors(fsInternetUploaderMessageType enType, COLORREF &clrText, COLORREF &clrBg, int &iImage)
{
	clrText = RGB (0, 0, 0);

	
	
	switch (enType)
	{
		case EDT_INQUIRY:
			clrBg = CLR_INQUIRY;
			iImage = 0;
			break;

		case EDT_INQUIRY2:
			clrBg = CLR_INQUIRY2;
			iImage = 0;
			break;

		case EDT_DONE:
			clrBg = CLR_DONE;
			iImage = 1;
			break;

		case EDT_RESPONSE_S:
			clrBg = CLR_RESPONSE_S;
			iImage = 2;
			break;

		case EDT_RESPONSE_S2:
			clrBg = CLR_RESPONSE_S2;
			iImage = 2;
			break;

		case EDT_RESPONSE_E:
			clrBg = CLR_RESPONSE_E;
			iImage = 3;
			break;

		case EDT_WARNING:
			clrBg = CLR_WARNING;
			iImage = 5;
			break;

		default:
			ASSERT (4!=4);
			return;
	}
}

void fsUploadsMgr::StopAllUploads(BOOL bByUser)
{
	StopUploads (m_vUploads, bByUser);
}

vmsUploadSmartPtr fsUploadsMgr::FindUploadById(UINT nId)
{
	try {

		for (size_t i = 0; i < m_vUploads.size (); i++)
		{
			if (m_vUploads [i]->nID == nId)
				return m_vUploads [i];
		}

	}catch (...) {}

	return NULL;
}

BOOL fsUploadsMgr::SaveAll()
{
	CString strUploadsFile;
	strUploadsFile.Format ("uploads.%d.sav", m_nFile+1);
	char sz [MAX_PATH];
	_pDllCaller->GetDataFilePath (strUploadsFile, sz);
	strUploadsFile = sz;

	fsString str = strUploadsFile; str += ".bak";

	WaitForSingleObject (m_mxAccFiles, INFINITE);

	HANDLE hFile = CreateFile (str, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, 
		FILE_ATTRIBUTE_HIDDEN, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
	{
		ReleaseMutex (m_mxAccFiles);
		return FALSE;
	}

	fsULFileHdr hdr; DWORD dw;
	if (FALSE == WriteFile (hFile, &hdr, sizeof (hdr), &dw, NULL))
		goto _lErr;

	if (FALSE == SaveUploads (hFile))
		goto _lErr;

	CloseHandle (hFile);

	
	DeleteFile (strUploadsFile);
	BOOL b; b = MoveFile (str, strUploadsFile);
	ReleaseMutex (m_mxAccFiles);
	return b;

_lErr:
	CloseHandle (hFile);
	DeleteFile (str);
	ReleaseMutex (m_mxAccFiles);
	return FALSE;
}

BOOL fsUploadsMgr::SaveUploads(HANDLE hFile)
{
	DWORD dw;

	UPLS_LIST list = m_vUploads;

	size_t cUploads = list.size () - m_cDontSaveUploads;
	if (FALSE == WriteFile (hFile, &cUploads, sizeof (size_t), &dw, NULL))
		return FALSE;

	for (size_t i = 0; i < list.size (); i++)
	{
		vmsUploadSmartPtr upl = list [i];
		if (upl->dwFlags & UF_DONTSAVETOFILE)
			continue;

		if (FALSE == WriteFile (hFile, &upl->bAutostart, sizeof (BOOL), &dw, NULL))
			return FALSE;
		if (FALSE == WriteFile (hFile, &upl->nID, sizeof (UINT), &dw, NULL))
			return FALSE;
		if (FALSE == WriteFile (hFile, &upl->dwFlags, sizeof (DWORD), &dw, NULL))
			return FALSE;
		if (FALSE == WriteFile (hFile, &upl->dwState, sizeof (DWORD), &dw, NULL))
			return FALSE;
		if (FALSE == WriteFile (hFile, &upl->dateAdded, sizeof (FILETIME), &dw, NULL))
			return FALSE;
		if (FALSE == upl->log.Save (hFile))
			return FALSE;
		if (FALSE == upl->pMgr->Save (hFile))
			return FALSE;
	}

	return TRUE;
}

BOOL fsUploadsMgr::LoadAll()
{
	for (int j = 0; j < 9; j++) 
	{
		if (m_pbFileCellBusy [j])
		{
			HANDLE ev = CreateEvent (NULL, TRUE, FALSE, "ev - fumcore - saveall");
			SetEvent (ev);
			Sleep (100);
			ResetEvent (ev);
			CloseHandle (ev);
			break;
		}
	}
	
	char sz [MAX_PATH];
	_pDllCaller->GetDataFilePath ("", sz);

	WaitForSingleObject (m_mxAccFiles, INFINITE);

	CString str1stEmpty;
	int n1stEmpty = -1;
	int n1stFullyLoaded = -1;

	std::vector <CString> vFullyLoaded, vFailedLoad;

	int i = 0;
	for (i = 0; i < 9; i++)
	{
		CString str; 
		str.Format ("%suploads.%d.sav", sz, i+1);

		HANDLE hFile = CreateFile (str, GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
		if (hFile == INVALID_HANDLE_VALUE)
		{
			if (n1stEmpty == -1 && GetFileAttributes (str) == DWORD (-1))
			{
				str1stEmpty = str;
				n1stEmpty = i;
			}
			continue;
		}

		fsULFileHdr hdr; DWORD dw;
		if (FALSE == ReadFile (hFile, &hdr, sizeof (hdr), &dw, NULL))
			goto _lErr;

		if (lstrcmp (hdr.szSig, ULFILE_SIG) || hdr.wVer > ULFILE_CURRENT_VERSION)
			goto _lErr;
		
		if (FALSE == LoadUploads (hFile, m_pbFileCellBusy [i], hdr.wVer))
		{
			vFailedLoad.push_back (str);
			goto _lErr;
		}

		if (m_pbFileCellBusy [i] == FALSE)
		{
			vFullyLoaded.push_back (str);
			if (n1stFullyLoaded == -1)
				n1stFullyLoaded = i;
		}

	_lErr:
		CloseHandle (hFile);
	}

	if (vFullyLoaded.size () != 0)
		m_nFile = n1stFullyLoaded;
	else
		m_nFile = n1stEmpty;
	m_pbFileCellBusy [m_nFile] = TRUE;

	if (vFullyLoaded.size () > 1)
	{
		SaveAll ();
		for (int i = 1; i < (int)vFullyLoaded.size (); i++)
			DeleteFile (vFullyLoaded [i]);
	}

	for (i = 0; i < (int)vFailedLoad.size (); i++)
		DeleteFile (vFailedLoad [i]);

	ReleaseMutex (m_mxAccFiles);

	DWORD dw;
	CloseHandle (
		CreateThread (NULL, 0, _threadSaveAll, this, 0, &dw));

	ProcessUploads ();

	return TRUE;
}

BOOL fsUploadsMgr::LoadUploads(HANDLE hFile, BOOL bCompletedOnly, WORD wVer)
{
	DWORD dw;

	size_t cUploads;
	if (FALSE == ReadFile (hFile, &cUploads, sizeof (size_t), &dw, NULL))
		return FALSE;

	for (size_t i = 0; i < cUploads; i++)
	{
		vmsUploadSmartPtr upl;
		Upload_CreateInstance (upl);

		if (FALSE == ReadFile (hFile, &upl->bAutostart, sizeof (BOOL), &dw, NULL))
			return FALSE;
		if (FALSE == ReadFile (hFile, &upl->nID, sizeof (UINT), &dw, NULL))
			return FALSE;
		if (FALSE == ReadFile (hFile, &upl->dwFlags, sizeof (DWORD), &dw, NULL))
			return FALSE;
		if (FALSE == ReadFile (hFile, &upl->dwState, sizeof (DWORD), &dw, NULL))
			return FALSE;
		upl->dwState = 0; 
		if (FALSE == ReadFile (hFile, &upl->dateAdded, sizeof (FILETIME), &dw, NULL))
			return FALSE;
		if (FALSE == upl->log.Load (hFile))
			return FALSE;
		if (FALSE == upl->pMgr->Load (hFile))
			return FALSE;

		if (bCompletedOnly && upl->pMgr->IsDone () == FALSE)
			continue;

		upl->pMgr->SetEventFunc (_UploadMgrEvents, this);

		if (bCompletedOnly)
		{
			upl->dwFlags |= UF_DONTSAVETOFILE | UF_READONLY;
			m_cDontSaveUploads++;
		}
		
		if (wVer == 1)
		{
			upl->dwFlags = 0;
			upl->nID = InterlockedIncrement (m_pnUplNextId);
		}

		*m_pnUplNextId = max (*m_pnUplNextId, (LONG)upl->nID + 1);

		m_vUploads.push_back (upl);
	}

	return TRUE;
}

DWORD WINAPI fsUploadsMgr::_threadSaveAll(LPVOID lp)
{
	fsUploadsMgr *pthis = (fsUploadsMgr*)lp;

	HANDLE ev = CreateEvent (NULL, TRUE, FALSE, "ev - fumcore - saveall");

	for (;;)
	{
		WaitForSingleObject (ev, INFINITE);
		pthis->SaveAll ();
	}
}

BOOL fsUploadsMgr::IsRunning()
{
	UPLS_LIST v = m_vUploads;
	for (size_t i = 0; i < v.size (); i++)
	{
		if (v [i]->pMgr->IsRunning ())
			return TRUE;
	}

	return FALSE;
}
