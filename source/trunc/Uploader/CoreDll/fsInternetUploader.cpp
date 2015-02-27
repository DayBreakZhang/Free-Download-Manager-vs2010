/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "fsInternetUploader.h"
#include "vmsInternetSession.h"
#include "common.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

void vmsMakeWinInetProxy (LPCSTR pszProxy, fsNetworkProtocol npConnection, fsNetworkProtocol npProxy, LPSTR pszWProxy)
{
	switch (npConnection)
	{
		case NP_FTP:
			lstrcpy (pszWProxy, "ftp=");
			break;

		case NP_HTTP:
		case NP_FILE:
			lstrcpy (pszWProxy, "http=");
			break;

		case NP_HTTPS:
			lstrcpy (pszWProxy, "https=");
			break;

		default:
			ASSERT (FALSE);
			return;
	}

	switch (npProxy)
	{
		case NP_FTP:
			lstrcat (pszWProxy, "ftp://");
			break;

		case NP_HTTP:
		case NP_FILE:
			lstrcat (pszWProxy, "http://");
			break;

		case NP_HTTPS:
			lstrcat (pszWProxy, "https://");
			break;

		default:
			ASSERT (FALSE);
			return;
	}

	lstrcat (pszWProxy, pszProxy);
}

LPCSTR strcmp_m (LPCSTR pszWhere, LPCSTR pszWhat)
{
	if (*pszWhere == 0)
		return *pszWhat == 0 ? pszWhere : NULL;

	if (*pszWhat == 0)
		return NULL;

	if (*pszWhat == '*')
	{
		if (pszWhat [1] == 0)
			return pszWhere;
		
		
		
		LPCSTR psz = strcmp_m (pszWhere, pszWhat+1);
		if (psz)
			return psz;

		
		return strcmp_m (pszWhere+1, pszWhat);
	}

	if (*pszWhat != '?')
	{
		if (*pszWhere != *pszWhat)
			return NULL;
	}

	return strcmp_m (pszWhere+1, pszWhat+1) ? pszWhere : NULL;
}

LPCSTR strcmpi_m (LPCSTR pszWhere, LPCSTR pszWhat)
{
	char *psz1 = new char [lstrlen (pszWhere) + 1];
	char *psz2 = new char [lstrlen (pszWhat) + 1];

	lstrcpy (psz1, pszWhere);
	lstrcpy (psz2, pszWhat);

	CharLower (psz1);
	CharLower (psz2);

	LPCSTR psz = strcmp_m (psz1, psz2);
	LPCSTR pszRet = NULL;
	if (psz)
		pszRet = pszWhere + (psz - psz1);

	delete [] psz1;
	delete [] psz2;

	return pszRet;
}

BOOL IsExtStrEq (LPCSTR pszMasked, LPCSTR psz2)
{
	return strcmpi_m (psz2, pszMasked) != NULL;

	
}

BOOL IsExtInExtsStr (LPCSTR pszExts, LPCSTR pszExt)
{
	if (pszExt == NULL)
		return FALSE;

	int len = lstrlen (pszExts);
	int i = 0;
	CHAR szExt [1000];

	do
	{
		int j = 0;

		while (i < len && pszExts [i] != ' ')
			szExt [j++] = pszExts [i++];

		szExt [j] = 0;
		i++;

		if (IsExtStrEq (szExt, pszExt))
			return TRUE;

	} while (i < len);

	return FALSE;
}

INTERNET_SCHEME fsNPToScheme (fsNetworkProtocol np)
{
	switch (np)
	{
		case NP_HTTP:
			return INTERNET_SCHEME_HTTP;

		case NP_HTTPS:
			return INTERNET_SCHEME_HTTPS;

		case NP_FTP:
			return INTERNET_SCHEME_FTP;

		case NP_FILE:
			return INTERNET_SCHEME_FILE;	

		default:
			ASSERT (0);
			return INTERNET_SCHEME_UNKNOWN;
	}
}

UINT64 fsGetFileSize (HANDLE hFile)
{
	DWORD dw1, dw2;
	dw1 = GetFileSize (hFile, &dw2);

	return dw1 | UINT64 (dw2) << 32;
}

BOOL fsSetFilePointer (HANDLE hFile, UINT64 uPosition, DWORD dwMethod)
{
	LONG lOffsetHi = 0;
	UINT64 uOffset = uPosition;
	
	while (uOffset > DWORD (-1))
	{
		SetFilePointer (hFile, -1, &lOffsetHi, dwMethod);
		if (GetLastError ())
			return FALSE;
		uOffset -= DWORD (-1);
		dwMethod = FILE_CURRENT;
		lOffsetHi = 0;
	}
	SetFilePointer (hFile, DWORD (uOffset), &lOffsetHi, dwMethod);
	return TRUE;
}

fsInternetUploader::fsInternetUploader()
{
	ZeroMemory (&m_unp, sizeof (m_unp));
	m_pInetFile = NULL;
	m_unp.uTimeout = 120000;
	m_unp.uMaxErrRetries = 20;
	m_unp.uPauseBetweenAttempts = 5000;
	m_bNeedStop = FALSE;
	m_bRunning = FALSE;
	m_uPosition = 0;
	m_uFileSize = _UI64_MAX;
	m_pfnEvents = NULL;
	m_dwUploadPartSize = 100 * 1024;
}

fsInternetUploader::~fsInternetUploader()
{
	StopUploading (TRUE);
	SAFE_DELETE (m_pInetFile);
}

fsInternetResult fsInternetUploader::OpenUrl()
{
	fsInternetResult ir;
	fsUpload_NetworkProperties* dnp = &m_unp;

	BOOL bOpenAnotherReq = m_pInetFile != NULL;

	if (bOpenAnotherReq == FALSE)
	{
		m_pInetFile = new fsInternetURLFile;
		m_pInetFile->SetDialogFunc (_InetFileDialogFunc, this, 0);
	
		vmsInternetSession* pSession = new vmsInternetSession;
		char szProxy [10000];
		vmsMakeWinInetProxy (dnp->pszProxyName, dnp->enProtocol, dnp->enProtocol, szProxy);
		ir  = pSession->Create (dnp->pszAgent, dnp->enAccType, szProxy, dnp->enProtocol);
		if (ir != IR_SUCCESS)
		{
			delete pSession;
			SAFE_DELETE (m_pInetFile);
			return ir;
		}
	
		ApplyProxySettings (pSession, dnp);
	
		m_pInetFile->Initialize (pSession, TRUE);

		ApplyProperties (m_pInetFile, dnp);

		
		if (dnp->enProtocol == NP_FTP && dnp->enFtpTransferType == FTT_UNKNOWN)
		{
			int posPath = strlen (dnp->pszPathName) - 1;
			int posExt = 0;
			LPSTR pszExt = new char [MAX_PATH];

			while (posPath && dnp->pszPathName [posPath] != '.')
				pszExt [posExt++] = dnp->pszPathName [posPath--];

			if (posPath)
			{
				LPSTR pszExtension = new char [MAX_PATH];

				pszExt [posExt] = 0;

				int i = 0;
				for (i = 0; i < posExt; i++)
					pszExtension [i] = pszExt [posExt - i - 1];

				pszExtension [i] = 0;
			
				if (IsExtInExtsStr (_pDllCaller->GetSettings ()->FtpAsciiExts (), pszExtension))
					m_pInetFile->FtpSetTransferType (FTT_ASCII);
				else
					m_pInetFile->FtpSetTransferType (FTT_BINARY);

				delete [] pszExtension;
			}
			else 
			{
				m_pInetFile->FtpSetTransferType (FTT_BINARY);
			}

			delete [] pszExt;
		}
	}

	
	
	m_uPosition -= m_uPosition % m_dwUploadPartSize;

	if (bOpenAnotherReq)
	{
		ir = m_pInetFile->OpenAnotherRequestOnServer (dnp->pszPathName, m_uPosition,
			min (m_dwUploadPartSize, m_uFileSize - m_uPosition), m_uFileSize);
	}
	else
	{
		ir = m_pInetFile->OpenEx (fsNPToScheme (dnp->enProtocol), dnp->pszServerName,
					dnp->pszUserName, dnp->pszPassword, dnp->uServerPort, 
					dnp->pszPathName, m_uPosition, FALSE, 
					min (m_dwUploadPartSize, m_uFileSize - m_uPosition), m_uFileSize);
	}

	if (m_bNeedStop)
	{
		SAFE_DELETE (m_pInetFile);
		return IR_S_FALSE;
	}

	if (ir != IR_SUCCESS)
	{
		
		SAFE_DELETE (m_pInetFile);
		return ir;
	}
	
	return IR_SUCCESS;
}

void fsInternetUploader::ApplyProperties(fsInternetURLFile *pFile, fsUpload_NetworkProperties *dnp)
{
	pFile->UseHttp11 (dnp->bUseHttp11);
	pFile->UseCookie (dnp->bUseCookie);
	
	
	pFile->UseFtpPassiveMode (dnp->dwFtpFlags & FTP_USEPASSIVEMODE);
	pFile->FtpSetDontUseLIST (dnp->dwFtpFlags & FTP_DONTSENDLIST);

	if (dnp->enFtpTransferType != FTT_UNKNOWN && dnp->enProtocol == NP_FTP)
		pFile->FtpSetTransferType (dnp->enFtpTransferType);
}

void fsInternetUploader::ApplyProxySettings(fsInternetSession *pSession, fsUpload_NetworkProperties *dnp)
{
	pSession->SetProxyAuth (dnp->pszProxyUserName, dnp->pszProxyPassword);
	pSession->SetTimeout (m_unp.uTimeout);
}

void fsInternetUploader::_InetFileDialogFunc(fsInetFileDialogDirection dir, LPCSTR pszMsg, LPVOID lp1, LPVOID lp2)
{
	fsInternetUploader* pthis = (fsInternetUploader*) lp1;

	fsInternetUploaderMessage ium;
	ium.pszText = pszMsg;
	ium.enType = dir == IFDD_TOSERVER ? EDT_INQUIRY2 : EDT_RESPONSE_S2;
	pthis->Event (IUE_MESSAGE, &ium);
}

void fsInternetUploader::StartUploading()
{
	if (m_bRunning)
		return;

	m_bRunning = TRUE;
	m_bNeedStop = FALSE;

	DWORD dw;
	CloseHandle (
		CreateThread (NULL, 0, _threadUploading, this, 0, &dw));
}

DWORD WINAPI fsInternetUploader::_threadUploading(LPVOID lp)
{
	fsInternetUploader* pthis = (fsInternetUploader*) lp;

	LPBYTE pbBuffer = NULL;
	DWORD dwBuffCapacity = 1000;
	DWORD dwMaxWrite = dwBuffCapacity;
	const int BufDivider = 8; 
	fsTicksMgr ticksTrack;

	pthis->m_speed.Reset ();

	pthis->Event (IUE_OPENINGFILEONDISK);

	HANDLE hFile = CreateFile (pthis->m_unp.strFileName, GENERIC_READ, FILE_SHARE_READ,
		NULL, OPEN_EXISTING, 0, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
	{
		pthis->Event (IUE_E_FAILEDTOOPENSRCFILE);
		goto _lExit;
	}

	UINT64 u; u = fsGetFileSize (hFile);

	if (pthis->m_uFileSize == _UI64_MAX)
	{
		pthis->m_uFileSize = u;
		pthis->m_dwUploadPartSize = (DWORD) (u / 100);
		pthis->m_dwUploadPartSize = max (pthis->m_dwUploadPartSize, 100 * 1024);
		pthis->m_dwUploadPartSize = min (pthis->m_dwUploadPartSize, 700 * 1024);
		pthis->m_uPosition = 0;
	}
	else if (pthis->m_uFileSize != u)
	{
		pthis->Event (IUE_E_SRCFILESIZEWASCHANGED);
		goto _lExit;
	}

	fsSetFilePointer (hFile, pthis->m_uPosition, FILE_BEGIN);

	pthis->Event (IUE_FILE_WAS_OPENED);

	pbBuffer = new BYTE [dwBuffCapacity];
	ticksTrack.Now ();

	DWORD nUploaded; nUploaded = 0;

	while (pthis->m_bNeedStop == FALSE && pthis->m_uPosition < pthis->m_uFileSize)
	{
		if (pthis->m_pInetFile == NULL || nUploaded == pthis->m_dwUploadPartSize)
		{
			BOOL bMsgs;

			if (pthis->m_pInetFile == NULL)
				pthis->m_speed.Reset ();

			nUploaded = 0;
	
			if (pthis->m_bNeedStop)
				goto _lExit;

			fsInternetResult ir = IR_ERROR;

			for (UINT i = 0; ir != IR_SUCCESS && i < pthis->m_unp.uMaxErrRetries; i++)
			{
				bMsgs = pthis->m_pInetFile == NULL;

				if (bMsgs)
					pthis->Event (IUE_CONNECTING);

				ir = pthis->OpenUrl ();
				if (ir != IR_SUCCESS)
				{
					char sz [1000];
					_pDllCaller->IRToStr (ir, sz, sizeof (sz));
					fsInternetUploaderMessage ium;
					ium.pszText = sz;
					ium.enType = EDT_RESPONSE_E;
					pthis->Event (IUE_MESSAGE, &ium);
					if (FALSE == pthis->DoSleep ())
						goto _lExit;
				}
				else
				{
					fsSetFilePointer (hFile, pthis->m_uPosition, FILE_BEGIN);

					if (bMsgs)
						pthis->Event (IUE_CONNECTED);
				}
			}
			
			if (ir != IR_SUCCESS)
				goto _lExit;
		}

		DWORD dwToWrite = (DWORD) min (pthis->m_uFileSize - pthis->m_uPosition, dwMaxWrite);
		dwToWrite = min (dwToWrite, (pthis->m_dwUploadPartSize - nUploaded));
		DWORD dw;
		ReadFile (hFile, pbBuffer, dwToWrite, &dw, NULL);
		fsInternetResult ir = pthis->m_pInetFile->Write (pbBuffer, dwToWrite, &dw);
		nUploaded += dw;
		
		if (ir != IR_SUCCESS)
		{
			char sz [1000];
			_pDllCaller->IRToStr (ir, sz, sizeof (sz));
			fsInternetUploaderMessage ium;
			ium.pszText = sz;
			ium.enType = EDT_RESPONSE_E;
			pthis->Event (IUE_MESSAGE, &ium);
			SAFE_DELETE (pthis->m_pInetFile);
			pthis->m_speed.Reset ();
			continue;
		}

		ASSERT (dwToWrite == dw);

		pthis->m_uPosition += dw;
		pthis->m_speed.Done (dw);

		fsTicksMgr ticksNow; ticksNow.Now ();
		if (ticksNow - ticksTrack >= 1000)
		{
			DWORD dwMaxWrite = pthis->m_speed.GetSpeed () / BufDivider;
			if (dwMaxWrite < 10)
				dwMaxWrite = 10;
			if (dwMaxWrite > 200000)
				dwMaxWrite = 200000;
			if (dwBuffCapacity < dwMaxWrite)
			{
				delete [] pbBuffer;
				pbBuffer = new BYTE [dwBuffCapacity = dwMaxWrite];
			}
		}
	}

_lExit:
	if (pbBuffer)
		delete [] pbBuffer;
	pthis->m_speed.Reset ();
	SAFE_DELETE (pthis->m_pInetFile);

	if (hFile != INVALID_HANDLE_VALUE)
		CloseHandle (hFile);
	pthis->m_bRunning = FALSE;

	pthis->Event (IUE_UPLOADSTOPPEDORDONE);

	return 0;
}

void fsInternetUploader::StopUploading(BOOL bWaitStop)
{
	m_bNeedStop = TRUE;

	if (m_pInetFile)
		m_pInetFile->CloseHandle ();

	if (bWaitStop)
	{
		while (m_bRunning)
			Sleep (10);
	}
}

BOOL fsInternetUploader::DoSleep()
{
	Event (IUE_PAUSEMODE);

	int i = m_unp.uPauseBetweenAttempts;
	while (i > 0 && m_bNeedStop == FALSE)
	{
		Sleep (100);
		i -= 100;
	}

	return m_bNeedStop == FALSE;
}

void fsInternetUploader::SetEventFunc(fntInternetUploaderEventFunc pfn, LPVOID lpParam)
{
	m_pfnEvents = pfn;
	m_lpEventParam = lpParam;
}

DWORD fsInternetUploader::Event(fsInternetUploaderEvent ev, LPVOID pData)
{
	if (m_pfnEvents)
		return m_pfnEvents (this, ev, pData, m_lpEventParam);
	return 0;
}

BOOL fsInternetUploader::IsRunning()
{
	return m_bRunning;
}

BOOL fsInternetUploader::IsDone()
{
	return m_uFileSize == m_uPosition;
}

fsInternetResult fsInternetUploader::CreateForFile(LPCSTR pszFileName, LPCSTR pszUploadUrl)
{
	fsUP_GetByUrl_Free (&m_unp);
	fsUP_GetByUrl (&m_unp, pszUploadUrl);

	m_unp.strFileName = pszFileName;
	m_uFileSize = _UI64_MAX;
	m_uPosition = 0;

	return IR_SUCCESS;
}

fsUpload_Properties* fsInternetUploader::GetUP()
{
	return &m_unp;
}

UINT64 fsInternetUploader::GetCurrentPosition()
{
	return m_uPosition;
}

UINT64 fsInternetUploader::GetFileSize()
{
	return m_uFileSize;
}

UINT fsInternetUploader::GetSpeed()
{
	return m_speed.GetSpeed ();
}

float fsInternetUploader::GetProgress()
{
	if (GetCurrentPosition () == _UI64_MAX || GetFileSize () == _UI64_MAX)
		return 0;
	return (float)((double)(__int64)GetCurrentPosition () / (__int64)GetFileSize () * 100.0);
}

LPCSTR fsInternetUploader::get_UploadFileName()
{
	return m_unp.strFileName;
}

BOOL fsInternetUploader::Save(HANDLE hFile)
{
	DWORD dw;

	if (FALSE == WriteFile (hFile, &m_dwUploadPartSize, sizeof (DWORD), &dw, NULL))
		return FALSE;

	if (FALSE == WriteFile (hFile, &m_uFileSize, sizeof (UINT64), &dw, NULL))
		return FALSE;

	if (FALSE == WriteFile (hFile, &m_uPosition, sizeof (UINT64), &dw, NULL))
		return FALSE;
	
	return TRUE;
}

BOOL fsInternetUploader::Load(HANDLE hFile)
{
	DWORD dw;

	if (FALSE == ReadFile (hFile, &m_dwUploadPartSize, sizeof (DWORD), &dw, NULL))
		return FALSE;

	if (FALSE == ReadFile (hFile, &m_uFileSize, sizeof (UINT64), &dw, NULL))
		return FALSE;

	if (FALSE == ReadFile (hFile, &m_uPosition, sizeof (UINT64), &dw, NULL))
		return FALSE;
	
	return TRUE;
}
