/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSBINDSTATUSCALLBACK_H__CC76B3A9_8772_4121_ABA6_BF1213528E52__INCLUDED_)
#define AFX_VMSBINDSTATUSCALLBACK_H__CC76B3A9_8772_4121_ABA6_BF1213528E52__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include <comdef.h>
#include <shlguid.h>
#include <wininet.h>
#include "../fsSpeedMeter.h"
#include "bscex.h"

class vmsBindStatusCallback : public IBindStatusCallbackEx,
	public IHttpNegotiate, public IServiceProvider
{
public:

	

	HRESULT __stdcall QueryInterface(REFIID riid, void** ppvObject)
	{
		*ppvObject = NULL;
		
		if (IsEqualGUID (riid, IID_IUnknown))
			*ppvObject = static_cast <IBindStatusCallback*> (this);

		else if (IsEqualGUID (riid, IID_IServiceProvider))
			*ppvObject = static_cast <IServiceProvider*> (this);
		
		else if (IsEqualGUID (riid, IID_IBindStatusCallback))
			*ppvObject = static_cast<IBindStatusCallback*>(this);

		

		else if (IsEqualGUID (riid, IID_IHttpNegotiate))
			*ppvObject = static_cast<IHttpNegotiate*>(this);

		else 
			return E_NOINTERFACE;
		
		AddRef ();
		return S_OK;	
	}

	DWORD __stdcall AddRef()
	{
		return InterlockedIncrement (&m_cRef);
	}
	
	DWORD __stdcall Release()
	{
		LONG l = InterlockedDecrement (&m_cRef);
		if (!l)
			delete this;
		return l;
	}

protected:
	bool m_bHttp;
	bool m_bOnDataAvailableWasNotCalled;
	HANDLE m_htDownload;
	CRITICAL_SECTION m_csDownload;
	static DWORD WINAPI _threadDownload (LPVOID lp);
	HRESULT DownloadFromStream (IStream *pstm);
	bool CheckIfFileNameEncoded(LPCSTR pszFileName);
	void ExtractFileNameFromContentDisposition (LPCSTR psz);
	CRITICAL_SECTION m_csDataBuffer;
	UINT64 m_uDownloaded;
	UINT64 m_uFileSize;
	bool m_bDone;
	bool m_bWriteError, m_bMemoryError;
	HANDLE m_hFile;
	bool m_bAbort;
	bool m_bAllowDownload;
	LONG m_cRef;
	vector <BYTE> m_vbDataBuffer;
	UINT m_nDataBufferLen;
	fsSpeedMeter m_speed;

public:
	
	

	STDMETHOD (QueryService) (REFGUID guidService, REFIID riid, void **ppvObject)
	{
		return QueryInterface (riid, ppvObject);
	}

public:

	

	STDMETHOD (GetBindInfoEx) (DWORD *grfBINDF, BINDINFO *pbindinfo, DWORD *grfBINDF2, DWORD *pdwReserved);

	

	STDMETHOD (GetBindInfo) (DWORD *grfBINDF, BINDINFO *pbindinfo);
	STDMETHOD (GetPriority) (LONG *pnPriority);
	STDMETHOD (OnDataAvailable) (DWORD grfBSCF, DWORD dwSize, FORMATETC *pformatetc, STGMEDIUM *pstgmed);
	
	STDMETHOD (OnLowResource) (DWORD reserved)
	{
		return S_OK;
	}

	STDMETHOD (OnObjectAvailable) (REFIID riid, IUnknown *punk)
	{
		return E_UNEXPECTED;
	}

	STDMETHOD (OnProgress) (ULONG ulProgress, ULONG ulProgressMax, ULONG ulStatusCode, LPCWSTR szStatusText);
	
	STDMETHOD (OnStartBinding) (DWORD dwReserved, IBinding *pib);
	
	STDMETHOD (OnStopBinding) (HRESULT hresult, LPCWSTR szError)
	{
		
		m_spBinding = NULL;
		return S_OK;
	}

	

	STDMETHOD (BeginningTransaction) (LPCWSTR szURL, LPCWSTR szHeaders, DWORD dwReserved, LPWSTR *pszAdditionalHeaders)
	{
		return E_NOTIMPL;
	}

	STDMETHOD (OnResponse) (DWORD dwResponseCode, LPCWSTR szResponseHeaders, LPCWSTR szRequestHeaders, LPWSTR *pszAdditionalRequestHeaders)
	{
		return E_NOTIMPL;
	}

public:
	bool m_bDoFailInStartBinding;
	IStreamPtr m_spStream;
	IBindCtxPtr m_spBindCtx;
	UINT64 getFileSize () const;
	LPCSTR getHostName() const;
	UINT getSpeed ();
	bool FlushDataToFile();
	bool isDone () const;
	LPCTSTR getFileName () const;
	void getProgress (UINT64 *puDownloaded, UINT64 *puFileSize) const;
	void setAbort();
	void setAllowDownload ();
	void setDstFile (HANDLE hFile);
	string m_strCookies, m_strReferer;
	tstring m_tstrFileName;
	string m_strHostName;
	string m_strUrl;
	IBindingPtr m_spBinding;
	BINDINFO* m_pBindInfo;
	DWORD m_grfBINDF;
	DWORD m_dwBindVerb;
	vmsBindStatusCallback();
	virtual ~vmsBindStatusCallback();

};

#endif 
