/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSHTTPTRAFFICCOLLECTOR_H__B5D82E6A_4E18_4FE3_A82C_CDC599153570__INCLUDED_)
#define AFX_VMSHTTPTRAFFICCOLLECTOR_H__B5D82E6A_4E18_4FE3_A82C_CDC599153570__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "vmsHttpRequestParser.h"
#include "vmsHttpResponseParser.h"
#include "vmsObject.h"
#include "../iefdm/UrlMonSpy/vmsUrlMonRequest.h"

class vmsHttpTrafficCollector  
{
	friend class vmsWinSockHttpTrafficCollector;
	friend class vmsWinInetHttpTrafficCollector;
	friend class vmsExternalHttpTrafficCollector;
public:
	enum {RequestBodyMaxSize = 30*1024};
	enum {ResponseBodyMaxSize = 1*1024*1024};
public:
	struct HttpDialog;
	typedef vmsObjectSmartPtr <HttpDialog> HttpDialogPtr;
	struct HttpDialog : public vmsObject
	{
		enum State
		{
			SENDING_REQUEST_HEADERS,
			REQUEST_HEADERS_SENT,
			SENDING_REQUEST_BODY,
			RECEIVING_RESPONSE_HEADERS,
			RESPONSE_HEADERS_RCVD,
			RECEIVING_RESPONSE_BODY,
			DONE,    
		};
		enum ResourceContentType
		{
			UNKNOWN					= 1,
			HTML					= 1 << 1,		
			X_WWW_FORM_URL_ENCODED	= 1 << 2,		
			FLV						= 1 << 3,
			XML						= 1 << 4,
			SWF						= 1 << 5,
			AMF						= 1 << 6,
			JSCRIPT					= 1 << 7,
			ALL						= 0xffffffff
		};
		
		enum PointersByRefererToDialogType
		{
			PTRBYREFERER_TODIALOG_TYPE_UNKNOWN,
			
			PTRBYREFERER_TODIALOG_SAFE,
			
			PTRBYREFERER_TODIALOG_CANBEAMBIGUOUS,
			
			PTRBYREFERER_TODIALOG_NONSAFE,
		};
		enum Flags
		{
			
			CHECK_REAL_CONTENT_TYPE	= 1,
			
			BODY_DECOMPRESSED		= 1 << 1,
			
			REFERER_DAMAGED			= 1 << 2, 
			REFERER_AMBIGOUS		= 1 << 3, 
			REFERER_NONSAFE			= 1 << 4, 
				
			
			SCRAP_FILE				= 1 << 5,
		};
		State enState;
		string strRequestUrl;
		string strRequestHost;
		vmsHttpRequestParser *pHttpRequest;
		string strRequestHeaders;
		vector <BYTE> vbRequestBody;
		DWORD dwFlags;
		
		
		
		
		
		
		myvector <HttpDialogPtr> vDlgsRefererLinksTo;
		
		
		myvector <string> vCanHaveChildrenWithHosts;
		vmsHttpResponseParser *pHttpResponse;
		string strResponseHeaders;
		vector <BYTE> vbResponseBody;
		bool isBodyText () const {
			return enCT == HTML || enCT == X_WWW_FORM_URL_ENCODED || enCT == XML || enCT == JSCRIPT;
		}
		LPSTR getBodyText () const {
			if (vbResponseBody.empty ())
				return "";
			assert (vbResponseBody [vbResponseBody.size ()-1] == 0);
			if (vbResponseBody [vbResponseBody.size ()-1])
				return "";
			return (LPSTR)&vbResponseBody [0];
		}
		HttpDialogPtr spDlgPrevInSession;	
		HttpDialogPtr spDlgRedirectChainPrev; 
		HttpDialogPtr spDlgRedirectChainNext; 
		ResourceContentType enCT;
		PointersByRefererToDialogType enPBRTDT;
		UINT64 nContentLength; 
		DWORD dwTicksWhenCompleted; 
		LONG nID;
		bool bSaveResponseBody;
		vmsUrlMonRequestPtr spUrlMonRequest;
		string strRequestUrlOfFullResource; 
#ifdef _DEBUG
		enum Provider {
			PROV_UNKNOWN,
			PROV_WINSOCK,
			PROV_WININET,
			PROV_EXTERNAL,
		};
		Provider enProvider;
#endif
		
	protected:
		friend class vmsHttpTrafficCollector;
		friend class vmsWinSockHttpTrafficCollector;
		friend class vmsWinInetHttpTrafficCollector;
		friend class vmsExternalHttpTrafficCollector;
		friend class vmsBrowserCachedFlvTrafficCollector;
		SOCKET s;	
		HINTERNET hWInetFile; 
		
	public:
		HttpDialog () 
		{
			s = INVALID_SOCKET;
			hWInetFile = NULL;
			bSaveResponseBody = false; 
			enCT = ResourceContentType::UNKNOWN;
			enPBRTDT = PTRBYREFERER_TODIALOG_TYPE_UNKNOWN;
			pHttpRequest = NULL;
			pHttpResponse = NULL;
			nID = -1;
			dwTicksWhenCompleted = 0;
			nContentLength = _UI64_MAX;
			dwFlags = 0;
#ifdef _DEBUG
			enProvider = Provider::PROV_UNKNOWN;
#endif
		}

		~HttpDialog ()
		{
			if (pHttpRequest)
				delete pHttpRequest;
			if (pHttpResponse)
				delete pHttpResponse;
		}
	};
public:
	static void ExtractUrlValuesFromPostData(const HttpDialog *pDlg, string &strValues);
	void LockRemoveOldDialogs (bool bLock);
	void LockDialogsLists(bool bLock);
	void RemoveAllDialogsOlderWhen (UINT nSeconds);
	int getHttpDialogIndex (const HttpDialog *pDlg) const;
	const HttpDialog* getHttpDialog (int nIndex) const;
	int getHttpDialogCount () const;
	void GetHttpDialogs (int nStartIndex, int nEndIndex, DWORD dwContentTypes, vector <const HttpDialog*> &vDialogs) const;
	
	static bool isFlashSwfCT (LPCSTR pszContentType);
	
	static bool isResponseBodyContainsText (const HttpDialog* pDlg, LPCSTR pszText, bool bMatchCase = true);
	void FinishDialog (const HttpDialog *pDlg);
	void MoveDialogToTop (const HttpDialog *pDlg);
	const HttpDialog* FindDialogByRequestUrl (LPCSTR pszUrl, HttpDialog::ResourceContentType enRT = HttpDialog::ALL, bool bSearchInCompleted = true) const;
	static bool isFlashVideoCT (LPCSTR pszContentType);

public:
	HttpDialogPtr CreateHttpDialogStore ();
	vmsHttpTrafficCollector();
	virtual ~vmsHttpTrafficCollector();

protected:
	void FindUrlMonRequest (HttpDialog *pDlg);
	HttpDialog::PointersByRefererToDialogType GetPointersByRefererToDialogType (const HttpDialog *pDlg);
	void FindRefererDialogs (HttpDialog *pDlg);
	void ProcessAddToTreeDialogList();
	void ScheduleAddDialogToTree (HttpDialogPtr spDlg);
	bool isContentLengthValid (HttpDialog *pDlg) const;
	bool isNeedBody (const HttpDialog *pDlg) const;
	void onHttpRequestHdrsAvailable (HttpDialog *pDlg);
	void ExtractHttpHeadersFromWInetFile(HttpDialog *pDlg);
	void onDataReceived (HttpDialog *pDlg);
	void onHttpResponseHdrsAvailable (HttpDialog *pDlg);
	void ExtractContentType (HttpDialog *pDlg);
	int FindDialogIndexById (LONG nID, bool bSearchInCompleted = false) const;
	void DeleteDialogFromListByID (LONG nID);
	static bool IsBodyFlashVideo (const HttpDialog* pDlg);
	const HttpDialog* FindDialogByRequestUrl2 (LPCSTR pszUrl, HttpDialog::ResourceContentType enRT, const vector <HttpDialogPtr> &vDlg) const;
	static void DecompressBodyIfRequired(HttpDialog *pDlg);
	
	void CloseDialog (HttpDialog* pDlg);
	void MoveDialogToCompleted (HttpDialog *pDlg);
	void DeleteDialogFromListBySocket (SOCKET s);
	int FindDialogIndexBySocket (SOCKET s, bool bFindInCompleted = false) const;
	int FindDialogIndexByWInetFile (HINTERNET hFile, bool bFindInCompleted = false) const;
	void ExtractRequestUrlFromSocket (vmsHttpTrafficCollector::HttpDialog *pDlg);
	void ExtractRequestUrlFromWInetFile (vmsHttpTrafficCollector::HttpDialog *pDlg);
	vector <HttpDialogPtr> m_vDialogsInProgress, m_vCompletedDialogs;
	vector <HttpDialogPtr> m_vDialogsToAddToTree;
	LONG m_nNextDlgID;
	CRITICAL_SECTION m_csModifyDialogsVector, m_csRemoveOldDialogs;
	vmsCriticalSection m_cs_vDialogsToAddToTree;
	void onFlvDetected(HttpDialog* pDlg);
};

typedef const vmsHttpTrafficCollector::HttpDialog* HTTPDLG;
typedef vmsHttpTrafficCollector::HttpDialogPtr SPHTTPDLG;
typedef vector <HTTPDLG> HTTPDLGLIST;
typedef vector <SPHTTPDLG> SPHTTPDLGLIST;

#endif 
