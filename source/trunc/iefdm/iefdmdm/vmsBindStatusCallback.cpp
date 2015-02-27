/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"

#include <initguid.h> 
#include "bscex.h"

#include "vmsBindStatusCallback.h"
#include "vmsHttpHelper.h"
#include "../InetFile/base64.h"
#include "vmsStringsHelper.h"

vmsBindStatusCallback::vmsBindStatusCallback()
{
	m_cRef = 0;
	m_grfBINDF = 0;
	m_pBindInfo = NULL;
	m_dwBindVerb = BINDVERB_GET;
	m_bAllowDownload = false;
	m_bAbort = false;
	m_hFile = INVALID_HANDLE_VALUE;
	m_bWriteError = false;
	m_bDone = false;
	m_uFileSize = _UI64_MAX;
	m_uDownloaded = 0;
	m_nDataBufferLen = 0;
	m_vbDataBuffer.resize (16*1024);
	m_bMemoryError = false;
	m_htDownload = NULL;
	m_bOnDataAvailableWasNotCalled = true;
	m_bHttp = false;
	m_bDoFailInStartBinding = false;

	InitializeCriticalSection (&m_csDataBuffer);
	InitializeCriticalSection (&m_csDownload);
}

vmsBindStatusCallback::~vmsBindStatusCallback()
{
	WaitForSingleObject (m_htDownload, 5000);
	DeleteCriticalSection (&m_csDataBuffer);
	DeleteCriticalSection (&m_csDownload);
}

STDMETHODIMP vmsBindStatusCallback::GetBindInfoEx (DWORD *grfBINDF, BINDINFO *pbindinfo, DWORD *grfBINDF2, DWORD *pdwReserved)
{
	HRESULT hr = GetBindInfo (grfBINDF, pbindinfo);
	if (FAILED (hr))
		return hr;

	*grfBINDF2 = BINDF2_READ_DATA_GREATER_THAN_4GB;	

	return S_OK;
}

STDMETHODIMP vmsBindStatusCallback::GetBindInfo (DWORD *grfBINDF, BINDINFO *pbindinfo)
{
	
	
	*grfBINDF = BINDF_ASYNCHRONOUS | BINDF_ASYNCSTORAGE |
		BINDF_RESYNCHRONIZE | BINDF_GETNEWESTVERSION | BINDF_NOWRITECACHE | BINDF_PRAGMA_NO_CACHE 
		| BINDF_FROMURLMON | BINDF_PULLDATA | BINDF_FROMURLMON;
	
	DWORD cbSize = pbindinfo->cbSize;
	ZeroMemory (pbindinfo, cbSize);
	pbindinfo->cbSize = cbSize;
	pbindinfo->dwBindVerb = m_dwBindVerb;
	if (m_pBindInfo)
	{
		pbindinfo->grfBindInfoF = m_pBindInfo->grfBindInfoF;
		
		if (m_pBindInfo->dwBindVerb == BINDVERB_POST)
		{
			CopyMemory (&pbindinfo->stgmedData, &m_pBindInfo->stgmedData, sizeof (STGMEDIUM));
			pbindinfo->cbstgmedData = m_pBindInfo->cbstgmedData;
		}

		if (cbSize >= offsetof (BINDINFO, dwCodePage))
		{
			pbindinfo->dwOptions = m_pBindInfo->dwOptions;
			pbindinfo->dwOptionsFlags = m_pBindInfo->dwOptionsFlags;
		
			if (cbSize >= offsetof (BINDINFO, securityAttributes))
				pbindinfo->dwCodePage = m_pBindInfo->dwCodePage;
		}
	}
	
	return S_OK;
}

STDMETHODIMP vmsBindStatusCallback::GetPriority (LONG *pnPriority)
{
	if (pnPriority == NULL)
		return E_POINTER;
	*pnPriority = THREAD_PRIORITY_NORMAL;
	return S_OK;
}

STDMETHODIMP vmsBindStatusCallback::OnStartBinding (DWORD dwReserved, IBinding *pib)
{
	if (!pib)
		return E_INVALIDARG;
	
	m_spBinding = pib;

	char sz [10000] = "";
	DWORD dw = sizeof (sz);
	
	IWinInetHttpInfoPtr spHttpInfo (pib);

	if (spHttpInfo != NULL)
	{
		DWORD dwFlags = 0;
	
		HRESULT hr = spHttpInfo->QueryInfo (
			HTTP_QUERY_RAW_HEADERS_CRLF | HTTP_QUERY_FLAG_REQUEST_HEADERS, sz, &dw, &dwFlags, NULL);
	
		LPDWORD pdw = (LPDWORD)sz;
		dw = *pdw;
	
		if (S_OK == hr)
		{
			m_strCookies = "";
			m_strReferer = "";
		
			LPCSTR pszReferer = strstr (sz, "Referer: ");		
			if (pszReferer)
			{
				pszReferer += strlen ("Referer: ");
				while (*pszReferer != 0 && *pszReferer != '\r' && *pszReferer != '\n')
					m_strReferer += *pszReferer++;
			}
		
			LPCSTR pszCookie = strstr (sz, "Cookie: ");		
			if (pszCookie)
			{
				pszCookie += strlen ("Cookie: ");
				while (*pszCookie != 0 && *pszCookie != '\r' && *pszCookie != '\n')
					m_strCookies += *pszCookie++;
			}
		}

		*sz = 0; dw = sizeof (sz); dwFlags = 0;
		spHttpInfo->QueryInfo (HTTP_QUERY_CONTENT_LENGTH, sz, &dw, &dwFlags, NULL);
		if (*sz)
			m_uFileSize = _atoi64 (sz);

		*sz = 0; dw = sizeof (sz); dwFlags = 0;
		spHttpInfo->QueryInfo (HTTP_QUERY_CONTENT_DISPOSITION, sz, &dw, &dwFlags, NULL);
		if (*sz)
			ExtractFileNameFromContentDisposition (sz);
	}
	
	IWinInetInfoPtr spWinInetInfo (pib);
	ATLASSERT (spWinInetInfo != NULL);
	if (spWinInetInfo != NULL)
	{
		

		*sz = 0; dw = sizeof (sz);
		spWinInetInfo->QueryOption (INTERNET_OPTION_URL, sz, &dw);
		if (*sz)
			m_strUrl = sz;
	}

	ATLASSERT (!m_strUrl.empty ());

	if (!m_bHttp && !m_strUrl.empty ())
	{
		m_bHttp = strnicmp (m_strUrl.c_str (), "http:", 5) == 0 || 
			strnicmp (m_strUrl.c_str (), "https:", 6) == 0;
	}

	if (m_tstrFileName.empty () && !m_strUrl.empty ())
	{
		string str = vmsHttpHelper::ExtractFileName (m_strUrl.c_str ());
		string str2;

		if (m_bHttp)
		{
			vmsHttpHelper::DecodeUrl (str.c_str (), str2);
			if (vmsStringsHelper::isUtf8String (str2.c_str ()))
			{
				int iLen = MultiByteToWideChar (CP_UTF8, 0, str2.c_str (), -1, NULL, 0);
				if (iLen > 0)
				{
					USES_CONVERSION;
					LPWSTR pwsz = new wchar_t [++iLen];
					MultiByteToWideChar (CP_UTF8, 0, str2.c_str (), -1, pwsz, iLen);
					m_tstrFileName = W2CT (pwsz);
					delete [] pwsz;
				}
			}
		}
		else
		{
			str2 = str;
		}

		if (m_tstrFileName.empty ())
		{
			USES_CONVERSION;
			m_tstrFileName = A2CT (str2.c_str ());
		}
	}

	if (!m_strUrl.empty ())
		vmsHttpHelper::ExtractHostName (m_strUrl.c_str (), m_strHostName);

	if (m_bDoFailInStartBinding)
		return E_FAIL;

	if (m_uFileSize != _UI64_MAX && m_uFileSize > 2*1024*1024*1024i64)
		return E_FAIL;

	m_htDownload = CreateThread (NULL, 0, _threadDownload, this, 0, &dw);
	return S_OK;
}

STDMETHODIMP vmsBindStatusCallback::OnDataAvailable (DWORD grfBSCF, DWORD dwSize, FORMATETC *pformatetc, STGMEDIUM *pstgmed)
{
	if (!pstgmed || !pformatetc)
	{
		if (m_spBinding != NULL)
			m_spBinding->Abort ();
		m_bOnDataAvailableWasNotCalled = false;
		return E_POINTER;
	}
	if (pstgmed->tymed != TYMED_ISTREAM || pstgmed->pstm == NULL)
	{
		if (m_spBinding != NULL)
			m_spBinding->Abort ();
		m_bOnDataAvailableWasNotCalled = false;
		return E_UNEXPECTED;
	}

	if (m_bAbort)
	{
		DownloadFromStream (pstgmed->pstm);
		return E_ABORT;
	}

	if (!m_bAllowDownload)
	{
		if (!m_bOnDataAvailableWasNotCalled)
			Sleep (900); 
	}

	m_bOnDataAvailableWasNotCalled = false;
	
	return DownloadFromStream (pstgmed->pstm);
}

STDMETHODIMP vmsBindStatusCallback::OnProgress (ULONG ulProgress, ULONG ulProgressMax, ULONG ulStatusCode, LPCWSTR szStatusText)
{
	if (ulStatusCode == BINDSTATUS_BEGINDOWNLOADDATA)
	{
		if (m_uFileSize == _UI64_MAX  && ulProgressMax != 0)
			m_uFileSize = ulProgressMax;
	}

	

	return S_OK;
}

void vmsBindStatusCallback::setDstFile(HANDLE hFile)
{
	EnterCriticalSection (&m_csDataBuffer); 
	m_hFile = hFile;
	LeaveCriticalSection (&m_csDataBuffer);
}

void vmsBindStatusCallback::setAllowDownload()
{
	m_bAllowDownload = true;
}

void vmsBindStatusCallback::setAbort()
{
	m_bAbort = true;
	if (m_spBinding)
	{
		HRESULT hr = m_spBinding->Abort ();
		assert (SUCCEEDED (hr));
	}
}

void vmsBindStatusCallback::getProgress(UINT64 *puDownloaded, UINT64 *puFileSize) const
{
	if (puDownloaded)
		*puDownloaded = m_uDownloaded;
	if (puFileSize)
		*puFileSize = m_uFileSize;
}

LPCTSTR vmsBindStatusCallback::getFileName() const
{
	return m_tstrFileName.c_str ();
}

bool vmsBindStatusCallback::isDone() const
{
	return m_bDone;
}

bool vmsBindStatusCallback::FlushDataToFile()
{
	EnterCriticalSection (&m_csDataBuffer);

	if (m_nDataBufferLen && m_hFile != INVALID_HANDLE_VALUE)
	{
		DWORD dwWritten = 0;
		if (FALSE == WriteFile (m_hFile, &m_vbDataBuffer[0], m_nDataBufferLen, &dwWritten, NULL) || 
			dwWritten != m_nDataBufferLen)
		{
			m_bWriteError = true;
			LeaveCriticalSection (&m_csDataBuffer);
			return false;
		}
		else
		{
			m_nDataBufferLen = 0;
		}
	}

	LeaveCriticalSection (&m_csDataBuffer);
	return true;
}

UINT vmsBindStatusCallback::getSpeed()
{
	return m_speed.GetSpeed ();
}

LPCSTR vmsBindStatusCallback::getHostName() const
{
	return m_strHostName.c_str ();
}

void vmsBindStatusCallback::ExtractFileNameFromContentDisposition(LPCSTR pszCD)
{
	USES_CONVERSION;

	m_tstrFileName = _T ("");

	
	LPCSTR psz = strstr (pszCD, "filename");
	if (psz == NULL)
		return;

	psz += 8;	
	while (*psz == ' ') 
		psz++;

	bool bCharset = false;
	if (*psz == '*') 
	{
		bCharset = true;
		psz++;
	}
	
	if (*psz++ != '=')
		return;
	while (*psz == ' ') 
		psz++;

	char chEnd = ';';

	if  (*psz == '"' || *psz == '\'')
		chEnd = *psz++;
	if (*psz == 0 || *psz == chEnd)
		return;
	
	char szFile [MAX_PATH];
	LPSTR pszFile = szFile;
		
	while (*psz != chEnd && *psz != 0)
		*pszFile++ = *psz++;	
	*pszFile = 0;
	
	if (bCharset)
	{
		LPCSTR psz = strstr (szFile, "''");
		if (psz != NULL)
		{
			if (strnicmp (szFile, "utf-8", 5) == 0)
			{
				wchar_t wsz [MAX_PATH] = L"";
				MultiByteToWideChar (CP_UTF8, 0, psz+2, -1, wsz, MAX_PATH);
				m_tstrFileName = W2CT (wsz);
			}
			else
			{
				strcpy (szFile, psz+2);
			}			
		}
	}

	if (!m_tstrFileName.empty ())
		return;
	
	CheckIfFileNameEncoded (szFile);
	if (!m_tstrFileName.empty ())
		return;

	if (m_bHttp)
	{
		string str;
		vmsHttpHelper::DecodeUrl (szFile, str);

		if (vmsStringsHelper::isUtf8String (str.c_str ()))
		{
			int iLen = MultiByteToWideChar (CP_UTF8, 0, str.c_str (), -1, NULL, 0);
			if (iLen > 0)
			{
				LPWSTR pwsz = new wchar_t [++iLen];
				MultiByteToWideChar (CP_UTF8, 0, str.c_str (), -1, pwsz, iLen);
				m_tstrFileName = W2CT (pwsz);
				delete [] pwsz;
			}
		}
	
		if (m_tstrFileName.empty ())
		{
			USES_CONVERSION;
			m_tstrFileName = A2CT (str.c_str ());
		}
	}
	else
	{
		USES_CONVERSION;
		m_tstrFileName = A2CT (szFile);
	}
}

bool vmsBindStatusCallback::CheckIfFileNameEncoded(LPCSTR pszFileName)
{
	if (strlen (pszFileName) < 13)
		return false;

	if (strnicmp (pszFileName, "=?UTF-8?", 8))
		return false;

	LPCSTR psz = pszFileName + 8;
	if (*psz != 'B' && *psz != 'b') 
		return false;
	if (psz [1] != '?')
		return false; 

	psz += 2;

	string str;
	while (psz [1] && (*psz != '?' || psz [1] != '='))
		str += *psz++;

	if (*psz != '?' || psz [1] != '=')
		return false; 

	LPBYTE pb = new BYTE [str.length ()];
	
	int len = base64_decode (str.c_str (), pb);
	if (len <= 0)
	{
		delete [] pb;
		return false; 
	}

	LPWSTR pwsz = new wchar_t [len+1];
	*pwsz = 0;
	len = MultiByteToWideChar (CP_UTF8, 0, (LPCSTR)pb, len, pwsz, len);
	if (len > 0)
		pwsz [len] = 0;
	USES_CONVERSION;
	m_tstrFileName = W2CT (pwsz);

	delete [] pb;
	delete [] pwsz;

	return true;
}

UINT64 vmsBindStatusCallback::getFileSize() const
{
	return m_uFileSize;
}

HRESULT vmsBindStatusCallback::DownloadFromStream(IStream *pstm)
{
	EnterCriticalSection (&m_csDownload);

	

	BYTE abData [16*1024];
	HRESULT hr;
	
	do 
	{
		DWORD dwToRead = sizeof (abData);
		DWORD dwRead = 0;
		hr = pstm->Read (abData, dwToRead, &dwRead);
		if (dwRead)
		{
			if (!m_bMemoryError && !m_bWriteError)
			{
				if (m_vbDataBuffer.size () < m_nDataBufferLen + dwRead)
				{
					try {
						EnterCriticalSection (&m_csDataBuffer);
						m_vbDataBuffer.resize (m_vbDataBuffer.size () * 2 + dwRead);
						LeaveCriticalSection (&m_csDataBuffer);
					}
					catch (...) {
						m_bMemoryError = true;
						continue;
					}
				}
				
				EnterCriticalSection (&m_csDataBuffer);
				CopyMemory (&m_vbDataBuffer[m_nDataBufferLen], abData, dwRead);
				m_nDataBufferLen += dwRead;
				LeaveCriticalSection (&m_csDataBuffer);
				
				if (m_nDataBufferLen >= 100*1024 && m_hFile != INVALID_HANDLE_VALUE)
				{
					if (false == FlushDataToFile ())
						continue;
					if (m_vbDataBuffer.size () > 100*1024+16*1024)
					{
						EnterCriticalSection (&m_csDataBuffer);
						m_vbDataBuffer.resize (100*1024+16*1024);
						LeaveCriticalSection (&m_csDataBuffer);
					}
				}
			}
			m_uDownloaded += dwRead;
			m_speed.Done (dwRead);
		}
	} 
	while (hr == S_OK);
	
	if ((FAILED (hr) && hr != E_PENDING) || m_bWriteError || m_bMemoryError)
	{
		if (m_spBinding != NULL)
			m_spBinding->Abort ();
		if (m_bWriteError || m_bMemoryError)
			hr = E_FAIL;
		LeaveCriticalSection (&m_csDownload);
		return hr;
	}
	
	if (m_bAbort)
	{
		if (m_spBinding != NULL)
			m_spBinding->Abort ();
		LeaveCriticalSection (&m_csDownload);
		return E_ABORT;
	}
	
	if (hr == S_FALSE)
	{
		
		FlushDataToFile ();
		m_bDone = true;
	}

	LeaveCriticalSection (&m_csDownload);
	return S_OK;
}

DWORD WINAPI vmsBindStatusCallback::_threadDownload(LPVOID lp)
{
	vmsBindStatusCallback *pthis = (vmsBindStatusCallback*)lp;

	while (pthis->m_bAllowDownload == false && pthis->m_bAbort == false)
		Sleep (10);

	if (pthis->m_bAbort)
		return 0;

	HRESULT hr = CoInitialize (NULL);
	while (pthis->m_bDone == false && pthis->m_bAbort == false && 
		pthis->m_bMemoryError == false && pthis->m_bWriteError == false)
	{
		if (pthis->m_spStream)
		{
			if (FAILED (pthis->DownloadFromStream (pthis->m_spStream)))
				break;
		}
		Sleep (5);
	}
	if (SUCCEEDED (hr))
		CoUninitialize ();
	return 0;
}

