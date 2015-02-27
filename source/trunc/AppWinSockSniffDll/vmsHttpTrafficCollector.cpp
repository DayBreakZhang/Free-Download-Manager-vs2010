/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsHttpTrafficCollector.h"
#include "vmsHttpHelper.h"
#include "vmsZlibHelper.h"
#include "vmsUrlMonSpyDll.h"
#include <atlbase.h>
#include "vmsUrl.h"

extern LPCSTR strstrn (LPCSTR pszSrc, LPCSTR pszSrch, int lenSrc);

vmsHttpTrafficCollector::vmsHttpTrafficCollector()
{
	m_vDialogsInProgress.reserve (50);
	m_vCompletedDialogs.reserve (1000);
	InitializeCriticalSection (&m_csModifyDialogsVector);
	InitializeCriticalSection (&m_csRemoveOldDialogs);
	
	m_nNextDlgID = 1024*1024;
}

vmsHttpTrafficCollector::~vmsHttpTrafficCollector()
{
	DeleteCriticalSection (&m_csModifyDialogsVector);
	DeleteCriticalSection (&m_csRemoveOldDialogs);
}

bool vmsHttpTrafficCollector::isFlashVideoCT(LPCSTR pszContentType)
{
	LPCSTR apszCT [] = {
		"video/x-flv", "video/mp4", "video/x-m4v", "audio/mp4a-latm", 
		"video/3gpp", "video/quicktime", "audio/mp4", "video/mpeg",
		"flv-application/octet-stream", "video/webm",
	};

	for (int i = 0; i < sizeof (apszCT) / sizeof (LPCSTR); i++)
	{
		if (strnicmp (pszContentType, apszCT [i], strlen (apszCT [i])) == 0)
			return true;
	}

	return false;
}

int vmsHttpTrafficCollector::getHttpDialogCount() const
{
	return m_vCompletedDialogs.size ();
}

const vmsHttpTrafficCollector::HttpDialog* vmsHttpTrafficCollector::getHttpDialog(int nIndex) const
{
	assert (nIndex >= 0 && nIndex < m_vCompletedDialogs.size ());
	if (!(nIndex >= 0 && nIndex < m_vCompletedDialogs.size ()))
		return NULL;	
	return m_vCompletedDialogs [nIndex];
}

int vmsHttpTrafficCollector::getHttpDialogIndex(const HttpDialog *pDlg) const
{
	for (size_t i = 0; i < m_vCompletedDialogs.size (); i++)
	{
		if (m_vCompletedDialogs [i] == pDlg)
			return i;
	}

	return -1;
}

void vmsHttpTrafficCollector::CloseDialog(HttpDialog *pDlg)
{
	LOGFN ("vmsHttpTrafficCollector::CloseDialog");
	LOG (" URL: %s", pDlg->strRequestUrl.c_str ());

	if (pDlg->vbRequestBody.size () > RequestBodyMaxSize || 
			pDlg->vbResponseBody.size () > ResponseBodyMaxSize)
	{
		DeleteDialogFromListByID (pDlg->nID);
		return;
	}

	switch (pDlg->enState)
	{
	case HttpDialog::SENDING_REQUEST_HEADERS:
	case HttpDialog::REQUEST_HEADERS_SENT:
	case HttpDialog::SENDING_REQUEST_BODY:
	case HttpDialog::RECEIVING_RESPONSE_HEADERS:
		DeleteDialogFromListByID (pDlg->nID);
		ProcessAddToTreeDialogList ();
		break;
		
	case HttpDialog::RESPONSE_HEADERS_RCVD:
	case HttpDialog::RECEIVING_RESPONSE_BODY:
		MoveDialogToCompleted (pDlg);
		break;
		
	case HttpDialog::DONE:
		assert (false); 
		break;
		
	default:
		assert (false); 
		break;
	}
}

void vmsHttpTrafficCollector::DecompressBodyIfRequired(HttpDialog *pDlg)
{
	LOGFN ("vmsHttpTrafficCollector::DecompressBodyIfRequired");

	if (pDlg->dwFlags & HttpDialog::BODY_DECOMPRESSED)
		return;

	if (pDlg->vbResponseBody.empty ())
		return;

	const vmsHttpParser::HdrField *pTE = pDlg->pHttpResponse->FieldByName ("Transfer-Encoding");
	if (pTE != NULL && stricmp (pTE->strValue.c_str (), "chunked") == 0)
	{
		UINT64 uNewSize = vmsHttpHelper::DeChunk (&pDlg->vbResponseBody[0], pDlg->vbResponseBody.size ());
		pDlg->vbResponseBody.resize (uNewSize);
		if (pDlg->vbResponseBody.empty ())
			return;
	}

	const vmsHttpParser::HdrField *pCE = pDlg->pHttpResponse->FieldByName ("Content-Encoding");
	if (!pCE)
		return; 

	if (stricmp (pCE->strValue.c_str (), "gzip") && stricmp (pCE->strValue.c_str (), "compress") &&
			stricmp (pCE->strValue.c_str (), "deflate"))
		return; 

	LPBYTE pb = NULL; UINT uSize = 0;
	BOOL bOK;

	if (stricmp (pCE->strValue.c_str (), "gzip") == 0)
		bOK = vmsZlibHelper::DecompressGzip (&pDlg->vbResponseBody[0], pDlg->vbResponseBody.size (), &pb, &uSize);
	else
		bOK = vmsZlibHelper::DecompressDeflate (&pDlg->vbResponseBody[0], pDlg->vbResponseBody.size (), &pb, &uSize);

	if (bOK && pb != NULL)
	{
		if (uSize)
		{
			pDlg->vbResponseBody.resize (uSize);
			CopyMemory (&pDlg->vbResponseBody[0], pb, uSize);
		}
		else
		{
			pDlg->vbResponseBody.clear ();
		}
		delete [] pb;
		pDlg->dwFlags |= HttpDialog::BODY_DECOMPRESSED;
	}
	else
	{
		LOG ("Failed to decompress. URL: %s", pDlg->strRequestUrl.c_str ());

		pDlg->vbResponseBody.clear ();
	}
}

void vmsHttpTrafficCollector::RemoveAllDialogsOlderWhen(UINT nSeconds)
{
	LOGFN ("vmsHttpTrafficCollector::RemoveAllDialogsOlderWhen");

	LockRemoveOldDialogs (true);
	EnterCriticalSection (&m_csModifyDialogsVector);
	
	DWORD dwTicksNow = GetTickCount ();

	size_t cDlds;

	for (cDlds = 0; cDlds < m_vCompletedDialogs.size (); cDlds++)
	{
		if ((dwTicksNow - m_vCompletedDialogs [cDlds]->dwTicksWhenCompleted) <= (nSeconds * 1000))
			break;
	}

	if (cDlds)
		m_vCompletedDialogs.erase (m_vCompletedDialogs.begin (), m_vCompletedDialogs.begin () + cDlds);

	LeaveCriticalSection (&m_csModifyDialogsVector);
	LockRemoveOldDialogs (false);
}

void vmsHttpTrafficCollector::LockRemoveOldDialogs(bool bLock)
{
	if (bLock)
		EnterCriticalSection (&m_csRemoveOldDialogs);
	else
		LeaveCriticalSection (&m_csRemoveOldDialogs);
}

void vmsHttpTrafficCollector::LockDialogsLists(bool bLock)
{
	if (bLock)
		EnterCriticalSection (&m_csModifyDialogsVector);
	else
		LeaveCriticalSection (&m_csModifyDialogsVector);
}

const vmsHttpTrafficCollector::HttpDialog* vmsHttpTrafficCollector::FindDialogByRequestUrl(LPCSTR pszUrl, HttpDialog::ResourceContentType enRT, bool bSearchInCompleted) const
{
	vmsCriticalSectionAutoLock csaul ((LPCRITICAL_SECTION)&m_csModifyDialogsVector);
	return FindDialogByRequestUrl2 (pszUrl, enRT, bSearchInCompleted ? m_vCompletedDialogs : m_vDialogsInProgress);
}

void vmsHttpTrafficCollector::MoveDialogToTop(const HttpDialog *pDlg)
{
	LOGFN ("vmsHttpTrafficCollector::MoveDialogToTop");

	EnterCriticalSection (&m_csModifyDialogsVector);

	int nIndex = getHttpDialogIndex (pDlg);

	if (nIndex != -1)
	{
		HttpDialogPtr spDlg = m_vCompletedDialogs [nIndex];
		m_vCompletedDialogs.erase (m_vCompletedDialogs.begin () + nIndex);
		m_vCompletedDialogs.insert (m_vCompletedDialogs.begin (), spDlg);
		if (m_vCompletedDialogs.size () > 1)
		{
			if (m_vCompletedDialogs [1]->nID > 0)
			{
				spDlg->nID = m_vCompletedDialogs [1]->nID - 1;
				spDlg->dwTicksWhenCompleted = m_vCompletedDialogs [1]->dwTicksWhenCompleted;
			}
			else
			{
				spDlg->nID = 0;
			}
		}
	}

	LeaveCriticalSection (&m_csModifyDialogsVector);
}

const vmsHttpTrafficCollector::HttpDialog* vmsHttpTrafficCollector::FindDialogByRequestUrl2(LPCSTR pszUrl, HttpDialog::ResourceContentType enRT, const vector <HttpDialogPtr> &vDlg) const
{
	LOGFN ("vmsHttpTrafficCollector::FindDialogByRequestUrl2");

	for (int i = 0; i < vDlg.size (); i++)
	{
		const HttpDialog* pDlg = vDlg [i];
		if (!(pDlg->enCT & enRT))
			continue;
		if (pDlg->strRequestUrl == pszUrl)
			return pDlg;
	}

	return NULL;
}

void vmsHttpTrafficCollector::FinishDialog(const HttpDialog *pDlg)
{
	LOGFN ("vmsHttpTrafficCollector::FinishDialog");
	CloseDialog ((HttpDialog*)pDlg);
}

bool vmsHttpTrafficCollector::isResponseBodyContainsText(const HttpDialog* pDlg, LPCSTR pszText, bool bMatchCase)
{
	LOGFN ("vmsHttpTrafficCollector::isResponseBodyContainsText");
	if (pDlg->vbResponseBody.empty ())
		return false;
	LPCSTR psz = (LPCSTR)&pDlg->vbResponseBody [0];
	extern LPCSTR strstrn (LPCSTR pszSrc, LPCSTR pszSrch, int lenSrc);
	extern LPCSTR strstrni (LPCSTR pszSrc, LPCSTR pszSrch, int lenSrc);
	return bMatchCase ? strstrn (psz, pszText, pDlg->vbResponseBody.size ()) != NULL :
		strstrni (psz, pszText, pDlg->vbResponseBody.size ()) != NULL;
}

bool vmsHttpTrafficCollector::isFlashSwfCT(LPCSTR pszContentType)
{
	return stricmp (pszContentType, "application/x-shockwave-flash") == 0;
}

void vmsHttpTrafficCollector::GetHttpDialogs(int nStartIndex, int nEndIndex, DWORD dwContentTypes, vector <const HttpDialog*> &vDialogs) const
{
	LOGFN ("vmsHttpTrafficCollector::GetHttpDialogs");

	assert (nStartIndex >= 0 && nStartIndex < m_vCompletedDialogs.size ());
	assert (nEndIndex == -1 || (nEndIndex >= 0 && nEndIndex < m_vCompletedDialogs.size ()));
	assert (dwContentTypes != 0);

	vDialogs.clear ();

	if (!(nStartIndex >= 0 && nStartIndex < m_vCompletedDialogs.size ()))
		return;
	if (!(nEndIndex == -1 || (nEndIndex >= 0 && nEndIndex < m_vCompletedDialogs.size ())))
		return;
	if (!dwContentTypes)
		return;

	if (nEndIndex == -1)
		nEndIndex = m_vCompletedDialogs.size ()-1;

	for (size_t i = nStartIndex; i < m_vCompletedDialogs.size (); i++)
	{
		if (m_vCompletedDialogs [i]->enCT & dwContentTypes)
			vDialogs.push_back (m_vCompletedDialogs [i]);
	}
}

bool vmsHttpTrafficCollector::IsBodyFlashVideo(const HttpDialog *pDlg)
{
	LOGFN ("vmsHttpTrafficCollector::IsBodyFlashVideo");

	assert (pDlg != NULL);
	assert (!pDlg->vbResponseBody.empty ());

	if (!pDlg)
		return false;

	if (pDlg->vbResponseBody.empty ())
		return false;

	if (pDlg->vbResponseBody.size () < 8)
		return false;

	LPBYTE pbBody = (LPBYTE)&pDlg->vbResponseBody [0];

	if (!memcmp (pbBody, "FLV", 3))
		return true;

	if (!memcmp (pbBody + 4, "ftyp", 4))
		return true;	

	return false;
}

void vmsHttpTrafficCollector::MoveDialogToCompleted(HttpDialog *pDlg)
{
	LOGFN ("vmsHttpTrafficCollector::MoveDialogToCompleted");
	LOG (" URL: %s", pDlg->strRequestUrl.c_str ());

	assert (pDlg->pHttpResponse != NULL);
	if (!pDlg->pHttpResponse)
		return;

#ifndef DEBUG_SAVE_ALL_HTTP_BODIES
	
	bool bDontKeepDialog = false;
	if (pDlg->enCT == HttpDialog::UNKNOWN)
	{
		bDontKeepDialog = true;
	}
	if (!bDontKeepDialog)
	{
		if (pDlg->pHttpResponse->getStatusCode () / 100 == 4)
			bDontKeepDialog = true;
	}
	if (bDontKeepDialog)
	{
		if (pDlg->pHttpResponse->getStatusCode () / 100 == 3 )
			bDontKeepDialog = false;
	}
	if (bDontKeepDialog)
	{
		LOG ("Ignore URL: %s", pDlg->strRequestUrl.c_str ());
		DeleteDialogFromListByID (pDlg->nID);
		ProcessAddToTreeDialogList ();
		return;
	}
#endif
	
	EnterCriticalSection (&m_csModifyDialogsVector);

	pDlg->enState = HttpDialog::DONE;
	
	pDlg->dwTicksWhenCompleted = GetTickCount ();

	HttpDialogPtr spDlg = pDlg;

	int nIndex; 
	if (m_vCompletedDialogs.size () == 0 || m_vCompletedDialogs [m_vCompletedDialogs.size ()-1]->nID < spDlg->nID)
	{
		m_vCompletedDialogs.push_back (spDlg);
		nIndex = m_vCompletedDialogs.size () - 1;
	}
	else
	{
		int nIndexFirstLess = m_vCompletedDialogs.size () - 1;
		while (nIndexFirstLess >= 0 && m_vCompletedDialogs [nIndexFirstLess]->nID > spDlg->nID)
			nIndexFirstLess--;
		assert (nIndexFirstLess < 0 || m_vCompletedDialogs [nIndexFirstLess]->nID != spDlg->nID);	
		nIndex = nIndexFirstLess + 1;
		m_vCompletedDialogs.insert (m_vCompletedDialogs.begin () + nIndex, spDlg);
	}
	
	DeleteDialogFromListByID (spDlg->nID);
	
	
	if (nIndex > 0 && spDlg->s != INVALID_SOCKET)
	{
		for (int i = nIndex - 1; i >= 0; i--)
		{
			if (m_vCompletedDialogs [i]->s == spDlg->s && 
					m_vCompletedDialogs [i]->strRequestHost == spDlg->strRequestHost)
			{
				spDlg->spDlgPrevInSession = m_vCompletedDialogs [i];
				break;
			}
		}
	}

	
	
	if (nIndex > 0)
	{
		for (int i = nIndex - 1; i >= 0; i--)
		{
			HttpDialog *pPrevDlg = m_vCompletedDialogs [i];
			if (!pPrevDlg->pHttpResponse)
				continue;
			if (pPrevDlg->pHttpResponse->getStatusCode () / 100 == 3)
			{
				const vmsHttpParser::HdrField *pLocation = pPrevDlg->pHttpResponse->FieldByName ("Location");
				if (pLocation && pLocation->strValue == spDlg->strRequestUrl)
				{
					spDlg->spDlgRedirectChainPrev = pPrevDlg;
					if (pPrevDlg->spDlgRedirectChainNext == NULL)
						pPrevDlg->spDlgRedirectChainNext = spDlg;
					break;
				}
			}
		}
	}
	

	if (spDlg->enCT != HttpDialog::UNKNOWN)
		DecompressBodyIfRequired (spDlg);

#ifdef DEBUG_SAVE_ALL_HTTP_BODIES
	if (spDlg->enCT == HttpDialog::UNKNOWN)
		DecompressBodyIfRequired (spDlg);
#endif

	if (!spDlg->vbResponseBody.empty () && spDlg->isBodyText ())
		spDlg->vbResponseBody.push_back (0); 

	
	
	
	vmsWinSockHttpDlgTree::o ().InsertDialog_Async (spDlg);
	
	
	LeaveCriticalSection (&m_csModifyDialogsVector);
}

void vmsHttpTrafficCollector::DeleteDialogFromListByID(LONG nID)
{
	LOGFN ("vmsHttpTrafficCollector::DeleteDialogFromListByID");
	EnterCriticalSection (&m_csModifyDialogsVector);
	int nIndex = FindDialogIndexById (nID);
	if (nIndex != -1)
		m_vDialogsInProgress.erase (m_vDialogsInProgress.begin () + nIndex);
	LeaveCriticalSection (&m_csModifyDialogsVector);
}

int vmsHttpTrafficCollector::FindDialogIndexById(LONG nID, bool bSearchInCompleted) const
{
	const vector <HttpDialogPtr> &v = bSearchInCompleted ? m_vCompletedDialogs : m_vDialogsInProgress;
	
	for (size_t i = 0; i < v.size (); i++)
	{
		if (v [i]->nID == nID)
			return i;
	}
	
	return -1;
}

void vmsHttpTrafficCollector::ExtractContentType(HttpDialog *pDlg)
{
	assert (pDlg != NULL);
	if (!pDlg)
		return;

	pDlg->enCT = HttpDialog::UNKNOWN;
	
	const vmsHttpParser::HdrField *pCT = pDlg->pHttpResponse->FieldByName ("Content-Type");
	if (pCT)
	{
		if (strncmp (pCT->strValue.c_str (), "text/html", 9) == 0)
			pDlg->enCT = HttpDialog::HTML;
		
		else if (strncmp (pCT->strValue.c_str (), "application/x-www-form-urlencoded", 33) == 0)
			pDlg->enCT = HttpDialog::X_WWW_FORM_URL_ENCODED;
		
		else if (strncmp (pCT->strValue.c_str (), "text/xml", 8) == 0 || 
				strncmp (pCT->strValue.c_str (), "application/xml", 15) == 0)
			pDlg->enCT = HttpDialog::XML;
		
		else if (isFlashSwfCT (pCT->strValue.c_str ()))
			pDlg->enCT = HttpDialog::SWF;
		
		else if (strcmp (pCT->strValue.c_str (), "application/x-amf") == 0 || 
				strncmp (pCT->strValue.c_str (), "application/x-amf;", 18) == 0)
			pDlg->enCT = HttpDialog::AMF;
		
		else if (strncmp (pCT->strValue.c_str (), "application/x-javascript", 24) == 0 || 
				strncmp (pCT->strValue.c_str (), "application/javascript", 22) == 0 || 
				strncmp (pCT->strValue.c_str (), "text/javascript", 15) == 0)
			pDlg->enCT = HttpDialog::JSCRIPT;
		
		else if (isFlashVideoCT (pCT->strValue.c_str ()) &&
				(pDlg->pHttpResponse->getStatusCode () == 200 || pDlg->pHttpResponse->getStatusCode () == 206))
		{
			pDlg->enCT = HttpDialog::FLV;
			onFlvDetected (pDlg);
		}
	}
}

void vmsHttpTrafficCollector::onHttpResponseHdrsAvailable(HttpDialog *pDlg)
{
	LOGFN ("vmsHttpTrafficCollector::onHttpResponseHdrsAvailable");

	assert (pDlg != NULL);
	if (!pDlg)
		return;

	
	
	
	FindUrlMonRequest (pDlg);

	pDlg->pHttpResponse = new vmsHttpResponseParser;
	pDlg->pHttpResponse->ParseHeader (pDlg->strResponseHeaders.c_str ());
	
	const vmsHttpParser::HdrField *pCL = pDlg->pHttpResponse->FieldByName ("Content-Length");
	if (pCL != NULL)
		pDlg->nContentLength = (UINT64)_atoi64 (pCL->strValue.c_str ());
	
	ExtractContentType (pDlg);
	
	if (pDlg->enCT != HttpDialog::UNKNOWN && pDlg->enCT != HttpDialog::FLV)
	{
		pDlg->bSaveResponseBody = true;

		if (pDlg->nContentLength != _UI64_MAX)
		{	
			if ((pDlg->enCT == HttpDialog::XML && pDlg->nContentLength > 60*1024) || 
					(pDlg->enCT == HttpDialog::SWF && pDlg->nContentLength > 800*1024))
				pDlg->bSaveResponseBody = false;
		}
	}
	
	if (pDlg->enCT != HttpDialog::FLV && 
			pDlg->nContentLength != _UI64_MAX && pDlg->nContentLength >= 300*1024)
		pDlg->dwFlags |= HttpDialog::CHECK_REAL_CONTENT_TYPE;
	
	#ifdef DEBUG_SAVE_ALL_HTTP_BODIES
	if (pDlg->enCT != HttpDialog::FLV)
		pDlg->bSaveResponseBody = true;
	#endif

	pDlg->enPBRTDT = GetPointersByRefererToDialogType (pDlg);
}

void vmsHttpTrafficCollector::onDataReceived(HttpDialog *pDlg)
{
	LOGFN ("vmsHttpTrafficCollector::onDataReceived");

	if (pDlg->enState == HttpDialog::RECEIVING_RESPONSE_BODY || pDlg->enState == HttpDialog::RESPONSE_HEADERS_RCVD)
	{
		assert (pDlg->vbResponseBody.size () <= pDlg->nContentLength || isContentLengthValid (pDlg) == false);

		if (pDlg->vbResponseBody.size () > ResponseBodyMaxSize)
		{
			DeleteDialogFromListByID (pDlg->nID);
			return;
		}
		
		if (pDlg->dwFlags & HttpDialog::CHECK_REAL_CONTENT_TYPE)
		{
			if (pDlg->vbResponseBody.size () > 8)
			{
				pDlg->dwFlags &= ~HttpDialog::CHECK_REAL_CONTENT_TYPE;
				
				if (IsBodyFlashVideo (pDlg))
				{
					pDlg->enCT = HttpDialog::FLV;
					pDlg->bSaveResponseBody = false;
					onFlvDetected (pDlg);
				}
				
				if (!pDlg->bSaveResponseBody)
				{
					pDlg->vbResponseBody.clear ();
					MoveDialogToCompleted (pDlg);
					return;
				}
			}
		}

		if (isContentLengthValid (pDlg))
		{
			if (pDlg->vbResponseBody.size () > pDlg->nContentLength && pDlg->nContentLength != _UI64_MAX)
			{
				pDlg->vbResponseBody.erase (pDlg->vbResponseBody.begin () + pDlg->nContentLength, pDlg->vbResponseBody.end ());
				assert (pDlg->vbResponseBody.size () == pDlg->nContentLength);
			}
			if (pDlg->vbResponseBody.size () == pDlg->nContentLength)
			{
				MoveDialogToCompleted (pDlg);
			}
			else
			{
				if (!pDlg->vbResponseBody.empty () && (pDlg->dwFlags & HttpDialog::BODY_DECOMPRESSED) == 0)
				{
					const vmsHttpParser::HdrField *pTE = pDlg->pHttpResponse->FieldByName ("Transfer-Encoding");
					if (pTE != NULL && stricmp (pTE->strValue.c_str (), "chunked") == 0)
					{
						if (vmsHttpHelper::ChunkedTE_hasLastChunk (&pDlg->vbResponseBody [0], pDlg->vbResponseBody.size ()))
							MoveDialogToCompleted (pDlg);
					}
				}
			}
		}
	}
}

vmsHttpTrafficCollector::HttpDialogPtr vmsHttpTrafficCollector::CreateHttpDialogStore()
{
	
	
	vmsUrlMonSpyDll::CheckDllLoaded ();

	HttpDialogPtr spDlg;
	spDlg.CreateInstance ();
	spDlg->nID = InterlockedIncrement (&m_nNextDlgID);
	return spDlg;
}

int vmsHttpTrafficCollector::FindDialogIndexBySocket(SOCKET s, bool bFindInCompleted) const
{
	assert (s != INVALID_SOCKET);
	if (s == INVALID_SOCKET)
		return -1;
	
	const vector <HttpDialogPtr> &v = bFindInCompleted ? m_vCompletedDialogs : m_vDialogsInProgress;
	
	for (size_t i = 0; i < v.size (); i++)
	{
		if (v [i]->s == s)
			return i;
	}
	
	return -1;
}

int vmsHttpTrafficCollector::FindDialogIndexByWInetFile(HINTERNET hFile, bool bFindInCompleted) const
{
	assert (hFile != NULL);
	if (hFile == NULL)
		return -1;
	
	const vector <HttpDialogPtr> &v = bFindInCompleted ? m_vCompletedDialogs : m_vDialogsInProgress;
	
	for (size_t i = 0; i < v.size (); i++)
	{
		if (v [i]->hWInetFile == hFile)
			return i;
	}
	
	return -1;
}

void vmsHttpTrafficCollector::DeleteDialogFromListBySocket(SOCKET s)
{
	LOGFN ("vmsHttpTrafficCollector::DeleteDialogFromListBySocket");
	EnterCriticalSection (&m_csModifyDialogsVector);
	int nIndex = FindDialogIndexBySocket (s);
	if (nIndex != -1)
		m_vDialogsInProgress.erase (m_vDialogsInProgress.begin () + nIndex);
	LeaveCriticalSection (&m_csModifyDialogsVector);
}

void vmsHttpTrafficCollector::ExtractRequestUrlFromSocket(HttpDialog *pDlg)
{
	LOGFN ("vmsHttpTrafficCollector::ExtractRequestUrlFromSocket");
	assert (pDlg->strRequestUrl.empty ());
	if (!pDlg->strRequestUrl.empty ())
		return;
	assert (pDlg->strRequestHeaders.empty () == false && pDlg->pHttpRequest != NULL);
	if (pDlg->strRequestHeaders.empty () || pDlg->pHttpRequest == NULL)
		return;
	string strPath = pDlg->pHttpRequest->getPath ();
	if (vmsUrl::isAbsolute (strPath.c_str ()))
	{
		
		pDlg->strRequestUrl = strPath;
		LOG ("New URL: %s", pDlg->strRequestUrl.c_str ());
		return;
	}
	const vmsHttpParser::HdrField* pHost = pDlg->pHttpRequest->FieldByName ("Host");
	string strHost;
	if (pHost)
	{
		strHost = pHost->strValue;
		
		sockaddr_in saddr; int i = sizeof (saddr);
		if (!getpeername (pDlg->s, (SOCKADDR*)&saddr, &i))
		{
			int iPort = ntohs (saddr.sin_port);
			if (iPort != 80)
			{
				char sz [10];
				sprintf (sz, ":%d", iPort);
				strHost += sz;
			}
		}
	}
	else
	{
		sockaddr_in saddr; int i = sizeof (saddr);
		if (getpeername (pDlg->s, (SOCKADDR*)&saddr, &i))
			return; 
		LPCSTR psz = inet_ntoa (saddr.sin_addr);
		if (!psz)
			return;
		strHost = psz;
		if (ntohs (saddr.sin_port) != 80)
		{
			char sz [100] = "";
			sprintf (sz, "%s:%d", strHost.c_str (), (int)ntohs (saddr.sin_port));
			strHost = sz;
		}
	}
	assert (strHost.empty () == false);
	if (strHost.empty ())
		return; 
	pDlg->strRequestHost = strHost;
	
	
	pDlg->strRequestUrl = "http://"; 
	pDlg->strRequestUrl += strHost;
	pDlg->strRequestUrl += strPath;
	LOG ("New URL: %s", pDlg->strRequestUrl.c_str ());
}

void vmsHttpTrafficCollector::ExtractRequestUrlFromWInetFile(HttpDialog *pDlg)
{
	LOGFN ("vmsHttpTrafficCollector::ExtractRequestUrlFromWInetFile");

	assert (pDlg != NULL);
	if (!pDlg)
		return;
	assert (pDlg->hWInetFile != NULL);
	if (!pDlg->hWInetFile)
		return;

	char szUrl [10000] = ""; DWORD dw = sizeof (szUrl);
	InternetQueryOption (pDlg->hWInetFile, INTERNET_OPTION_URL, szUrl, &dw);

	pDlg->strRequestUrl = szUrl;
	LOG ("New URL: %s", pDlg->strRequestUrl.c_str ());

	char szHost [1000] = "";

	URL_COMPONENTS urlc; ZeroMemory (&urlc, sizeof (urlc));
	urlc.dwStructSize = sizeof (urlc);
	urlc.lpszHostName = szHost;
	urlc.dwHostNameLength = sizeof (szHost);
	InternetCrackUrl (szUrl, 0, 0, &urlc);

	pDlg->strRequestHost = szHost;
}

void vmsHttpTrafficCollector::ExtractHttpHeadersFromWInetFile(HttpDialog *pDlg)
{
	LOGFN ("vmsHttpTrafficCollector::ExtractHttpHeadersFromWInetFile");

	assert (pDlg != NULL);
	if (!pDlg)
		return;
	assert (pDlg->hWInetFile != NULL);
	if (!pDlg->hWInetFile)
		return;

	char szHdrs [40000] = ""; DWORD dw = sizeof (szHdrs);

	HttpQueryInfo (pDlg->hWInetFile, HTTP_QUERY_RAW_HEADERS_CRLF | HTTP_QUERY_FLAG_REQUEST_HEADERS,
		szHdrs, &dw, NULL);

	if (*szHdrs)
	{
		pDlg->strRequestHeaders = szHdrs;
		onHttpRequestHdrsAvailable (pDlg);
	}

	*szHdrs = 0; dw = sizeof (szHdrs);
	HttpQueryInfo (pDlg->hWInetFile, HTTP_QUERY_RAW_HEADERS_CRLF,
		szHdrs, &dw, NULL);

	if (*szHdrs)
	{
		pDlg->strResponseHeaders = szHdrs;
		onHttpResponseHdrsAvailable (pDlg);
	}
}

void vmsHttpTrafficCollector::onHttpRequestHdrsAvailable(HttpDialog *pDlg)
{
	LOGFN ("vmsHttpTrafficCollector::onHttpRequestHdrsAvailable");
	pDlg->pHttpRequest = new vmsHttpRequestParser;
	pDlg->pHttpRequest->ParseHeader (pDlg->strRequestHeaders.c_str ());
	FindRefererDialogs (pDlg);
}

bool vmsHttpTrafficCollector::isNeedBody(const HttpDialog *pDlg) const
{
	return (pDlg->dwFlags & vmsHttpTrafficCollector::HttpDialog::CHECK_REAL_CONTENT_TYPE) != 0 || 
		pDlg->bSaveResponseBody;
}

bool vmsHttpTrafficCollector::isContentLengthValid(HttpDialog *pDlg) const
{
	return pDlg->dwFlags & HttpDialog::BODY_DECOMPRESSED ? false : true;
}

void vmsHttpTrafficCollector::ScheduleAddDialogToTree(HttpDialogPtr spDlg)
{
	vmsCriticalSectionAutoLock al (&m_cs_vDialogsToAddToTree);

	if (m_vDialogsToAddToTree.empty () || 
		m_vDialogsToAddToTree [m_vDialogsToAddToTree.size ()-1]->nID < spDlg->nID)
	{
		m_vDialogsToAddToTree.push_back (spDlg);
	}
	else
	{
		size_t nIndex = 0; 
		while (nIndex < m_vDialogsToAddToTree.size () && m_vDialogsToAddToTree [nIndex]->nID < spDlg->nID)
			nIndex++;
		m_vDialogsToAddToTree.insert (m_vDialogsToAddToTree.begin () + nIndex, spDlg);
	}
}

void vmsHttpTrafficCollector::ProcessAddToTreeDialogList()
{
	LONG lMinID = LONG_MAX;
	EnterCriticalSection (&m_csModifyDialogsVector);
	for (size_t i = 0; i < m_vDialogsInProgress.size (); i++)
	{
		LONG lID = m_vDialogsInProgress [i]->nID;
		if (lID < lMinID)
			lMinID = lID;
	}
	LeaveCriticalSection (&m_csModifyDialogsVector);

	vmsCriticalSectionAutoLock al (&m_cs_vDialogsToAddToTree);

	while (!m_vDialogsToAddToTree.empty () && m_vDialogsToAddToTree [0]->nID < lMinID)
	{
		vmsWinSockHttpDlgTree::o ().InsertDialog_Async (m_vDialogsToAddToTree [0]);
		m_vDialogsToAddToTree.erase (m_vDialogsToAddToTree.begin ());
	}
}

void vmsHttpTrafficCollector::FindRefererDialogs(HttpDialog *pDlg)
{
	assert (pDlg != NULL);
	if (!pDlg)
		return;

	assert (pDlg->pHttpRequest != NULL);
	if (!pDlg->pHttpRequest)
		return;

	const vmsHttpParser::HdrField *pReferer = pDlg->pHttpRequest->FieldByName ("Referer");
	if (!pReferer)
		return;

	vmsCriticalSectionAutoLock csal (&m_csModifyDialogsVector);

	bool bRefererDamaged = true;
	bool bRefererNonSafe = false;
	bool bRefererAmbiguous = false;

	int nRefererLen = pReferer->strValue.length ();

	for (size_t iVector = 0; iVector < 2; iVector++)
	{
		vector <HttpDialogPtr> &vDialogs = iVector ? m_vCompletedDialogs : m_vDialogsInProgress;

		for (int i = vDialogs.size () - 1; i >= 0; i--)
		{
			HttpDialog* pDlg2 = vDialogs [i];
			if (pDlg2->nID >= pDlg->nID)
				continue; 
			if (pDlg2->enState < HttpDialog::REQUEST_HEADERS_SENT)
				continue;
			if (pDlg2->strRequestUrl.empty ())
				continue;
			bool bEq = !strncmp (pDlg2->strRequestUrl.c_str (), pReferer->strValue.c_str (), nRefererLen);
			if (bEq && pDlg2->strRequestUrl.length () == nRefererLen)
			{
				if (bRefererDamaged)
				{
					pDlg->vDlgsRefererLinksTo.clear ();
					bRefererDamaged = false;
					bRefererNonSafe = false;
					bRefererAmbiguous = false;
				}

				if (pDlg2->enPBRTDT == HttpDialog::PTRBYREFERER_TODIALOG_NONSAFE)
					bRefererNonSafe = true;
				else if (pDlg2->enPBRTDT == HttpDialog::PTRBYREFERER_TODIALOG_CANBEAMBIGUOUS)
					bRefererAmbiguous = true; 

				pDlg->vDlgsRefererLinksTo.push_back (pDlg2);
			}

			if (!bRefererDamaged)
				continue; 

			bool bHaveDamagedMatch = false;

			
			if (bEq && pDlg2->strRequestUrl [nRefererLen] == '#')
				bHaveDamagedMatch = true;
			
			
			else if (pReferer->strValue.length () > pDlg2->strRequestUrl.length () &&
					strncmp (pReferer->strValue.c_str (), pDlg2->strRequestUrl.c_str (), pDlg2->strRequestUrl.length ()) == 0 &&
					strncmp (pReferer->strValue.c_str () + pDlg2->strRequestUrl.length (), "/[[", 3) == 0)
				bHaveDamagedMatch = true;

			
			else if (pDlg2->strRequestUrl.length () > 140 &&
					strncmp (pReferer->strValue.c_str (), pDlg2->strRequestUrl.c_str (), 140) == 0)
				bHaveDamagedMatch = true;

			if (bHaveDamagedMatch)
			{
				if (pDlg2->enPBRTDT == HttpDialog::PTRBYREFERER_TODIALOG_NONSAFE)
					bRefererNonSafe = true;
				else if (pDlg2->enPBRTDT == HttpDialog::PTRBYREFERER_TODIALOG_CANBEAMBIGUOUS)
					bRefererAmbiguous = true;
				if (!bRefererAmbiguous && !pDlg->vDlgsRefererLinksTo.empty () && 
						pDlg->vDlgsRefererLinksTo [0]->strRequestUrl != pDlg2->strRequestUrl)
					bRefererAmbiguous = true;
				pDlg->vDlgsRefererLinksTo.push_back (pDlg2);
			}
		}
	}

	if (bRefererNonSafe)
	{
		for (size_t i = 0; i < pDlg->vDlgsRefererLinksTo.size (); i++)
		{
			if (pDlg->vDlgsRefererLinksTo [i]->vCanHaveChildrenWithHosts.findIndex (pDlg->strRequestHost) == -1)
				pDlg->vDlgsRefererLinksTo [i]->vCanHaveChildrenWithHosts.push_back (pDlg->strRequestHost);
		}
		pDlg->vDlgsRefererLinksTo.clear ();
	}

	if (bRefererDamaged)
		pDlg->dwFlags |= HttpDialog::REFERER_DAMAGED;
	if (bRefererAmbiguous)
		pDlg->dwFlags |= HttpDialog::REFERER_AMBIGOUS;
	if (bRefererNonSafe)
		pDlg->dwFlags |= HttpDialog::REFERER_NONSAFE;
}

vmsHttpTrafficCollector::HttpDialog::PointersByRefererToDialogType vmsHttpTrafficCollector::GetPointersByRefererToDialogType (HTTPDLG pDlg)
{
	assert (pDlg != NULL);
	if (!pDlg)
		return HttpDialog::PTRBYREFERER_TODIALOG_TYPE_UNKNOWN;
	if (pDlg->enCT == vmsHttpTrafficCollector::HttpDialog::SWF)
		return HttpDialog::PTRBYREFERER_TODIALOG_NONSAFE;
	assert (pDlg->pHttpRequest != NULL);
	if (!pDlg->pHttpRequest)
		return HttpDialog::PTRBYREFERER_TODIALOG_CANBEAMBIGUOUS;
	if (pDlg->pHttpRequest->getRequestType () != vmsHttpRequestParser::GET)
		return HttpDialog::PTRBYREFERER_TODIALOG_CANBEAMBIGUOUS;
	return HttpDialog::PTRBYREFERER_TODIALOG_SAFE;
}

void vmsHttpTrafficCollector::ExtractUrlValuesFromPostData(HTTPDLG pDlg, string &strValues)
{
	strValues = "";
	assert (pDlg != NULL);
	if (!pDlg)
		return;
	if (!pDlg->pHttpRequest)
		return;
	if (pDlg->vbRequestBody.empty ())
		return;
	if (pDlg->pHttpRequest->getRequestType () != vmsHttpRequestParser::POST)
		return;
	const vmsHttpParser::HdrField *pFld = pDlg->pHttpRequest->FieldByName ("Content-Type");
	if (!pFld)
		return;
	if (stricmp (pFld->strValue.c_str (), "application/x-www-form-urlencoded"))
		return;
	strValues.assign ((LPCSTR)&pDlg->vbRequestBody [0], pDlg->vbRequestBody.size ());
}

void vmsHttpTrafficCollector::FindUrlMonRequest(HttpDialog *pDlg)
{
	LOG ("Find URLMON request for URL: %s at TICKCOUNT = %d", pDlg->strRequestUrl.c_str (), GetTickCount ());
	USES_CONVERSION;
	pDlg->spUrlMonRequest = vmsUrlMonSpyDll::FindRequest (A2CW (pDlg->strRequestUrl.c_str ()), 
		pDlg->vbRequestBody.empty () ? NULL : &pDlg->vbRequestBody[0], pDlg->vbRequestBody.size (), true);
	LOG ("URLMON request %s found", pDlg->spUrlMonRequest != NULL ? "was" : "was NOT");
}

void vmsHttpTrafficCollector::onFlvDetected(HttpDialog* pDlg)
{	
	assert (!pDlg->strRequestUrl.empty () && !pDlg->strRequestHost.empty ());
	if (pDlg->strRequestUrl.empty () || pDlg->strRequestHost.empty ())
		return;

	if (pDlg->strRequestHost != "youtube.com")
	{
		if (pDlg->strRequestHost.length () < 13)
			return;
		if (strcmp (pDlg->strRequestHost.c_str () + pDlg->strRequestHost.length () - 12, ".youtube.com"))
			return;
	}

	LPSTR psz = (LPSTR)strstr (pDlg->strRequestUrl.c_str (), "&range=");
	if (!psz)
		psz = (LPSTR)strstr (pDlg->strRequestUrl.c_str (), "?range=");

	if (!psz)
		return;

	LPSTR psz2 = psz + 7;
	while (*psz2 && *psz2 != '&')
		psz2++;

	pDlg->strRequestUrlOfFullResource = pDlg->strRequestUrl;
	pDlg->strRequestUrlOfFullResource.erase (psz - pDlg->strRequestUrl.c_str (), psz2-psz);

	pDlg->dwFlags |= HttpDialog::SCRAP_FILE;
}
