/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsHttpFlvTrafficAnalyzer.h"
#include "vmsCharsets.h"
#include <atlbase.h>
#include "vmsHttpHelper.h"
#include "vmsXmlHelper.h"
#include "vmsWinSockHttpTrafficAnalyzer.h"
#include "vmsUrlWords.h"

vmsHttpFlvTrafficAnalyzer::vmsHttpFlvTrafficAnalyzer()
{

}

vmsHttpFlvTrafficAnalyzer::~vmsHttpFlvTrafficAnalyzer()
{

}

int vmsHttpFlvTrafficAnalyzer::get_FlvDownloadCount() const
{
	return m_vDownloads.size ();
}

const vmsHttpFlvTrafficAnalyzer::FlvDownload* vmsHttpFlvTrafficAnalyzer::getFlvDownload(int nIndex) const
{
	assert (nIndex > 0 && nIndex < m_vDownloads.size ());
	return &m_vDownloads [nIndex];
}

const vector <vmsHttpFlvTrafficAnalyzer::FlvDownload>& vmsHttpFlvTrafficAnalyzer::getFlvDownloads() const
{
	return m_vDownloads;
}

void vmsHttpFlvTrafficAnalyzer::AddFlvDownload(const vmsHttpTrafficCollector::HttpDialog *pSrcHtmlDlg, const vmsHttpTrafficCollector::HttpDialog *pDlg, LPCWSTR pwszTitle)
{
	FlvDownload flv;
	const vmsHttpParser::HdrField *pFld;
	flv.strUrl = pDlg->dwFlags & vmsHttpTrafficCollector::HttpDialog::SCRAP_FILE ? pDlg->strRequestUrlOfFullResource : pDlg->strRequestUrl;
	if (pDlg->pHttpRequest)
	{
		pFld = pDlg->pHttpRequest->FieldByName ("Referer");
		if (pFld)
			flv.strReferer = pFld->strValue;
		pFld = pDlg->pHttpRequest->FieldByName ("Cookie");
		if (pFld)
			flv.strCookies = pFld->strValue;
		if (pDlg->pHttpRequest->getRequestType () == vmsHttpRequestParser::POST)
			flv.vbPostData = pDlg->vbRequestBody;
	}
	if (pDlg->pHttpResponse)
	{
		pFld = pDlg->pHttpResponse->FieldByName ("Content-Type");
		if (pFld)
			flv.strContentType = pFld->strValue;
		if (!(pDlg->dwFlags & vmsHttpTrafficCollector::HttpDialog::SCRAP_FILE))
		{
			pFld = pDlg->pHttpResponse->FieldByName ("Content-Length");
			if (pFld)
				flv.strContentLength = pFld->strValue;
		}
	}
	if (pwszTitle)
		flv.wstrTitle = pwszTitle;
	m_vDownloads.push_back (flv);
}

void vmsHttpFlvTrafficAnalyzer::ExtractTitleFromHtml(const vmsHttpTrafficCollector::HttpDialog *pHtmlDlg, wstring &wstrTitle)
{
	wstrTitle = L"";

	assert (pHtmlDlg != NULL);
	if (!pHtmlDlg)
		return;

	if (pHtmlDlg->vbResponseBody.empty ())
		return;
	
	extern LPCSTR strstrni (LPCSTR pszSrc, LPCSTR pszSrch, int lenSrc);
	LPCSTR psz = strstrni ((LPCSTR)&pHtmlDlg->vbResponseBody [0], "<title>", pHtmlDlg->vbResponseBody.size ());
	if (psz)
	{
		psz += 7;
		LPCSTR pszEnd = (LPCSTR)&pHtmlDlg->vbResponseBody [0] + pHtmlDlg->vbResponseBody.size ();
		string strTitle;
		while (psz < pszEnd)
		{
			if (*psz != '<')
				strTitle += *psz++;
			else 
				break;
		}
		if (*psz == '<')
		{
			const vmsHttpParser::HdrField *pFld = pHtmlDlg->pHttpResponse->FieldByName ("Content-Type");
			LPCSTR pszCharset = pFld ? strstr (pFld->strValue.c_str (), "charset") : NULL;
			if (pszCharset)
			{
				pszCharset += 7;
				while (*pszCharset == ' ')
					pszCharset++;
				if (*pszCharset == '=')
				{
					pszCharset++;
					while (*pszCharset == ' ')
						pszCharset++;
					string strCharset;
					while (*pszCharset != ' ' && *pszCharset != 0)
						strCharset += *pszCharset++;
					UINT nCP = vmsCharsets::GetCpIdFromName (strCharset.c_str ());
					if (nCP)
					{
						int n = MultiByteToWideChar (nCP, 0, strTitle.c_str (), -1, NULL, 0);
						assert (n != 0);
						LPWSTR pwsz = new WCHAR [n+1];
						MultiByteToWideChar (nCP, 0, strTitle.c_str (), -1, pwsz, n);
						wstrTitle = pwsz;
						delete [] pwsz;
					}
				}
			}
			
			if (wstrTitle.empty ())
			{
				USES_CONVERSION;
				wstrTitle = A2W (strTitle.c_str ());
			}
				
			while (wstrTitle.empty () == false && wstrTitle [0] <= ' ')
				wstrTitle.erase (wstrTitle.begin ());
			while (wstrTitle.empty () == false && wstrTitle [wstrTitle.length ()-1] <= ' ')
				wstrTitle.erase (wstrTitle.end ()-1);
			for (int i = 0; i < wstrTitle.length (); i++)
			{
				if (wstrTitle [i] < ' ')
					wstrTitle [i] = ' ';
				if (i && wstrTitle [i] == ' ' && wstrTitle [i-1] == ' ')
					wstrTitle.erase (wstrTitle.begin () + i--);
			}
		}
	}
}

void vmsHttpFlvTrafficAnalyzer::ExtractTitleFromXWwwFormUrlEncoded(const vmsHttpTrafficCollector::HttpDialog *pDlg, wstring &wstrTitle)
{
	wstrTitle = L"";

	assert (pDlg != NULL);
	if (!pDlg)
		return;
	assert (pDlg->enCT == vmsHttpTrafficCollector::HttpDialog::X_WWW_FORM_URL_ENCODED);

	if (pDlg->vbResponseBody.empty ())
		return;
	
	extern LPCSTR strstrni (LPCSTR pszSrc, LPCSTR pszSrch, int lenSrc);
	LPCSTR psz = strstrni ((LPCSTR)&pDlg->vbResponseBody [0], "&title=", pDlg->vbResponseBody.size ());
	if (!psz)
		return;

	psz += 7; 
	int iLenAvail = (int)pDlg->vbResponseBody.size () - (psz - (LPCSTR)&pDlg->vbResponseBody [0]);

	string strTitle;
	while (iLenAvail > 0 && *psz != '&')
	{
		strTitle += *psz++;
		iLenAvail--;
	}

	if (strTitle.empty ())
		return;

	for (int i = 0; i < strTitle.length (); i++)
	{
		if (strTitle [i] == '+')
			strTitle [i] = ' ';
	}

	string strDecodedTitle;
	vmsHttpHelper::DecodeUrl (strTitle.c_str (), strDecodedTitle);

	int n = MultiByteToWideChar (CP_UTF8, 0, strDecodedTitle.c_str (), -1, NULL, 0);
	assert (n != 0);
	LPWSTR pwsz = new WCHAR [n+1]; *pwsz = 0;
	MultiByteToWideChar (CP_UTF8, 0, strDecodedTitle.c_str (), -1, pwsz, n);
	wstrTitle = pwsz;
	delete [] pwsz;
}

void vmsHttpFlvTrafficAnalyzer::ExtractTitleFromXml(const vmsHttpTrafficCollector::HttpDialog *pDlg, wstring &wstrTitle, const vmsHttpTrafficCollector::HttpDialog* pFlvDlg)
{
	extern LPCSTR strstrni (LPCSTR pszSrc, LPCSTR pszSrch, int lenSrc);
	extern LPCSTR strstrn (LPCSTR pszSrc, LPCSTR pszSrch, int lenSrc);

	wstrTitle = L"";
	
	assert (pDlg != NULL);
	if (!pDlg)
		return;
	assert (pDlg->enCT == vmsHttpTrafficCollector::HttpDialog::XML);
	
	if (pDlg->vbResponseBody.empty ())
		return;

	LPCSTR pszXml = (LPCSTR)&pDlg->vbResponseBody [0];
	int iXmlLen = pDlg->vbResponseBody.size ();

	

	LPCSTR pszXml2 = strstrni (pszXml, "encoding=\"", iXmlLen);
	if (!pszXml2)
		return;
	
	pszXml2 += 10;
	iXmlLen -= pszXml2 - pszXml;
	pszXml = pszXml2;
	if (iXmlLen < 5)
		return;

	if (strnicmp (pszXml, "utf-8", 5))
		return;

	

	USES_CONVERSION;
	tstring tstrRequestUrl = A2CT (pFlvDlg->strRequestUrl.c_str ());
	
	
	string strUrl = vmsXmlHelper::toUtf8noEncode (tstrRequestUrl);
	pszXml2 = strstrn (pszXml, strUrl.c_str (), iXmlLen);

	if (!pszXml2)
	{
		
		strUrl = vmsXmlHelper::toUtf8 (tstrRequestUrl);
		pszXml2 = strstrn (pszXml, strUrl.c_str (), iXmlLen);
		if (!pszXml2)
		{
			
			strUrl = pFlvDlg->strRequestUrl;
			pszXml2 = strstrn (pszXml, strUrl.c_str (), iXmlLen);
		}
	}

	

	LPCSTR pszVideoSectionTag = pszXml;

	if (pszXml2)
	{
		

		bool bAsAttr = pszXml2 [-1] != '>'; 

		if (bAsAttr)
		{
			
			
			while (pszXml2 > pszXml && *pszXml2 != '"')
				pszXml2--;
			pszXml2--;
			if (pszXml2 > pszXml)
			{
				bool bInQ = false;
				while (pszXml2 > pszXml)
				{
					if (*pszXml2 == '"')
						bInQ = !bInQ;
					else if (*pszXml2 == '<' && bInQ == false)
						break;
					pszXml2--;
				}
				if (pszXml2 > pszXml)
					pszVideoSectionTag = pszXml2;
			}
		}
		else
		{
			
			

			
			while (pszXml2 > pszXml && *pszXml2 != '<')
				pszXml2--;
			pszXml2--;
			if (pszXml2 > pszXml)
			{
				
				bool bInT = false; 
				while (pszXml2 > pszXml)
				{
					if (*pszXml2 == '<')
					{
						if (bInT)
						{
							
							bInT = false;
						}
						else
						{
							if (pszXml2 [1] == '/')
							{
								bInT = true; 
							}
							else
							{
								
								
								break;
							}
						}
					}
					pszXml2--;
				}
				if (pszXml2 > pszXml)
					pszVideoSectionTag = pszXml2;
			}
		}
	}

	

	int iXmlLen2 = iXmlLen - (pszVideoSectionTag - pszXml);

	LPCSTR apszTags [] = {"title=\"", "<title>", "name=\"", "<name>"};
	int iTag;
	LPCSTR pszTitle = NULL;
	
	do
	{	
		for (iTag = 0; iTag < sizeof (apszTags)/sizeof (LPCSTR) && pszTitle == NULL; iTag++)
			pszTitle = strstrni (pszVideoSectionTag, apszTags [iTag], iXmlLen2);
		if (!pszTitle)
		{
			if (pszVideoSectionTag != pszXml)
			{
				
				pszVideoSectionTag = pszXml;
				iXmlLen2 = iXmlLen;
			}
			else
			{
				return; 
			}			
		}
	}
	while (pszTitle == NULL);

	pszTitle += strlen (apszTags [iTag]);

	LPCSTR pszTitleE = pszTitle;
	int iXmlLen3 = iXmlLen - (pszTitle - pszXml);
	char chEnd = pszTitle [-1] == '>' ? '<' : '"';
	while (*pszTitleE != chEnd && iXmlLen3)
	{
		pszTitleE++;
		iXmlLen3--;
	}
	if (!iXmlLen3)
		return; 
	string strTitle; strTitle.assign (pszTitle, pszTitleE-pszTitle);

	int n = MultiByteToWideChar (CP_UTF8, 0, strTitle.c_str (), -1, NULL, 0);
	assert (n != 0);
	LPWSTR pwsz = new WCHAR [n+1]; *pwsz = 0;
	MultiByteToWideChar (CP_UTF8, 0, strTitle.c_str (), -1, pwsz, n);
	wstrTitle = pwsz;
	delete [] pwsz;
}

void vmsHttpFlvTrafficAnalyzer::DecodeWebPageString(const vmsHttpTrafficCollector::HttpDialog* pHtmlDlg, LPCSTR pszString, wstring &wstrResult)
{
	const vmsHttpParser::HdrField *pFld = pHtmlDlg->pHttpResponse->FieldByName ("Content-Type");
	LPCSTR pszCharset = pFld ? strstr (pFld->strValue.c_str (), "charset") : NULL;
	if (pszCharset)
	{
		pszCharset += 7;
		while (*pszCharset == ' ')
			pszCharset++;
		if (*pszCharset == '=')
		{
			pszCharset++;
			while (*pszCharset == ' ')
				pszCharset++;
			string strCharset;
			while (*pszCharset != ' ' && *pszCharset != 0)
				strCharset += *pszCharset++;
			UINT nCP = vmsCharsets::GetCpIdFromName (strCharset.c_str ());
			if (nCP)
				vmsCharsets::DecodeString (pszString, nCP, wstrResult);
		}
	}
	if (wstrResult.empty ())
		vmsCharsets::DecodeString (pszString, CP_UTF8, wstrResult);
}

void vmsHttpFlvTrafficAnalyzer::FindDialogsByUrlExactMatch(LPCSTR pszSrcText, const HTTPDLGLIST &vDlgs, HTTPDLGLIST &vResult)
{
	assert (pszSrcText != NULL && *pszSrcText != 0);
	
	vResult.clear ();
	
	string strTmp;
	
	for (size_t i = 0; i < vDlgs.size (); i++)
	{
		HTTPDLG pDlg = vDlgs [i];
		LPCSTR pszFlvUrl = pDlg->strRequestUrl.c_str ();
		if (pszFlvUrl [pDlg->strRequestUrl.length ()-1] == '&')
		{
			strTmp.assign (pszFlvUrl, pDlg->strRequestUrl.length ()-1);
			pszFlvUrl = strTmp.c_str ();
		}
		if (strstr (pszSrcText, pszFlvUrl))
			vResult.push_back (pDlg);
	}
}

void vmsHttpFlvTrafficAnalyzer::FindDialogsByFileUrlMatch(LPCSTR pszSrcText, const HTTPDLGLIST &vDlgs, HTTPDLGLIST &vResult)
{
	
	
	
	assert (pszSrcText != NULL && *pszSrcText != 0);
	
	vResult.clear ();
	
	int iDlgFound = -1;
	
	for (size_t iDlg = 0; iDlg < vDlgs.size (); iDlg++)
	{
		string strFileUrl; vmsHttpHelper::ExtractFileUrl (vDlgs [iDlg]->strRequestUrl.c_str (),
			strFileUrl);
		if (strFileUrl.empty ())
			continue;
		if (strstr (pszSrcText, strFileUrl.c_str ()) != NULL)
		{
			if (iDlgFound == -1)
			{
				iDlgFound = iDlg;
			}
			else if (vDlgs [iDlgFound]->strRequestUrl != vDlgs [iDlg]->strRequestUrl)
			{
				iDlgFound = -1;
				break;
			}
		}
	}
	
	if (iDlgFound != -1)
		vResult.push_back (vDlgs [iDlgFound]);
}

void vmsHttpFlvTrafficAnalyzer::FindFlvDownloadInInBetweenDlgs(const vmsHttpTrafficCollector *pTraffic, HTTPDLG pWebPage, HTTPDLGLIST vFlvs, FindFlvDownloadInInBetweenDlgs_Type enFindType)
{
	FindFlvDownloadInInBetweenDlgs (pTraffic, pWebPage, NULL, NULL, NULL, vFlvs, enFindType);
}

void vmsHttpFlvTrafficAnalyzer::FindFlvDownloadInInBetweenDlgs(const vmsHttpTrafficCollector *pTraffic, HTTPDLG pWebPage, LPCSTR pszSwfUrl, LPCSTR pszFlashVars, LPCSTR pszSwfContext, HTTPDLGLIST vFlvs, FindFlvDownloadInInBetweenDlgs_Type enFindType)
{
	LOGFN ("vmsHttpFlvTrafficAnalyzer::FindFlvDownloadInInBetweenDlgs");

	if (!pszSwfUrl)
	{
		assert (pWebPage != NULL);
		if (!pWebPage)
			return;
		pszSwfUrl = pWebPage->strRequestUrl.c_str ();
	}

	string strBody;
	if (!pszSwfContext)
	{
		assert (pWebPage != NULL);
		if (!pWebPage)
			return;
		strBody.assign ((LPSTR)&pWebPage->vbResponseBody [0], pWebPage->vbResponseBody.size ());
		pszSwfContext = strBody.c_str ();
	}	

	int nStartIndex = pWebPage ? pTraffic->getHttpDialogIndex (pWebPage) + 1 : 0;

	
	
	

	HTTPDLGLIST vFlvs2;

	DWORD adwCTs [] = {
		vmsHttpTrafficCollector::HttpDialog::AMF,
		vmsHttpTrafficCollector::HttpDialog::X_WWW_FORM_URL_ENCODED,
		vmsHttpTrafficCollector::HttpDialog::XML,
		vmsHttpTrafficCollector::HttpDialog::HTML,
	};

	for (int iCT = 0; iCT < sizeof (adwCTs) / sizeof (DWORD); iCT++)
	{
		
		HTTPDLGLIST vBetwDlgs;
		pTraffic->GetHttpDialogs (nStartIndex, -1, adwCTs [iCT], vBetwDlgs);

		
		HTTPDLGLIST vBetwDlgs2;
		
		
		
		vector <HTTPDLGLIST>  vBetwToFlvMap;
		
		
		for (size_t iDlg = 0; iDlg < vBetwDlgs.size (); iDlg++)
		{
			HTTPDLG pDlg = vBetwDlgs [iDlg];
			if (pDlg->vbResponseBody.empty ())
				continue; 
			if (pDlg->enCT == vmsHttpTrafficCollector::HttpDialog::HTML &&
					pDlg->vbResponseBody.size () > 1000)
				continue; 

			string strBody; 
			
			if (pDlg->enCT == vmsHttpTrafficCollector::HttpDialog::AMF)
			{
				for (size_t i = 0; i < pDlg->vbResponseBody.size (); i++)
				{
					if (pDlg->vbResponseBody [i] >= ' ')
						strBody += pDlg->vbResponseBody [i];
				}
			}
			else if (pDlg->enCT == vmsHttpTrafficCollector::HttpDialog::X_WWW_FORM_URL_ENCODED)
			{
				
				string str; str.assign ((LPSTR)&pDlg->vbResponseBody [0], pDlg->vbResponseBody.size ());
				vmsHttpHelper::DecodeUrl (str.c_str (), strBody);
			}
			else 
			{
				
				strBody.assign ((LPSTR)&pDlg->vbResponseBody [0], pDlg->vbResponseBody.size ());
			}

			
			if (enFindType == FDT_EXACTURLMATCH)
				FindDialogsByUrlExactMatch (strBody.c_str (), vFlvs, vFlvs2);
			else if (enFindType == FDT_FILEURLMATCH)
				FindDialogsByFileUrlMatch (strBody.c_str (), vFlvs, vFlvs2);
			else if (enFindType == FDT_BYUNIQUEWORDS)
				FindDialogsByUniqueUrlWordsMatch (strBody.c_str (), vFlvs, vFlvs2);
			else
				return;

			if (!vFlvs2.empty ())
			{
				
				vBetwDlgs2.push_back (pDlg);
				vBetwToFlvMap.push_back (vFlvs2);
			}
		}

		
		if (vBetwDlgs2.empty ())
			continue; 

		LOGHTTPDLGLIST ("List of dialogs with FLVs", vBetwDlgs2);

		
		

		LOGsnl ("Found dialogs with FLVs. Find their source.");

		HTTPDLGLIST vBetwDlgsFoundInSwfContext;
		FindDialogsByUrlExactMatch (pszSwfContext, vBetwDlgs2, vBetwDlgsFoundInSwfContext);
		LOGHTTPDLGLIST ("List of these dialogs belonging to source page (exact match)", vBetwDlgsFoundInSwfContext);
		if (vBetwDlgsFoundInSwfContext.empty ())
		{
			FindDialogsByFileUrlMatch (pszSwfContext, vBetwDlgs, vBetwDlgsFoundInSwfContext);
			LOGHTTPDLGLIST ("List of these dialogs belonging to source page (file url match)", vBetwDlgsFoundInSwfContext);
		}
		if (vBetwDlgsFoundInSwfContext.empty ())
		{
			FindDialogsByUniqueUrlWordsMatch (pszSwfContext, vBetwDlgs, vBetwDlgsFoundInSwfContext);
			LOGHTTPDLGLIST ("List of these dialogs belonging to source page (unique url word match)", vBetwDlgsFoundInSwfContext);
		}
		if (vBetwDlgsFoundInSwfContext.empty ())
		{
			FindDialogsByUniqueUrlWordsMatch2 (pszSwfUrl, vBetwDlgs, vBetwDlgsFoundInSwfContext);
			LOGHTTPDLGLIST ("List of these dialogs belonging to source page (unique url words2 match)", vBetwDlgsFoundInSwfContext);
		}

		if (!vBetwDlgsFoundInSwfContext.empty ())
		{
			
			

			
			wstring wstrTitle;
			if (pszFlashVars)
				ExtractTitleFromFlashVars (pWebPage, pszFlashVars, wstrTitle);
			if (wstrTitle.empty () && pWebPage)
				ExtractTitleFromHtml (pWebPage, wstrTitle);

			
			for (size_t i = 0; i < vBetwDlgsFoundInSwfContext.size (); i++)
			{
				
				for (size_t j = 0; j < vBetwDlgs2.size (); j++)
				{
					if (vBetwDlgs2 [j] == vBetwDlgsFoundInSwfContext [i])
					{
						
						HTTPDLG pBetwDlg = vBetwDlgs2 [j];

						
						for (size_t k = 0; k < vBetwToFlvMap [j].size (); k++)
						{
							HTTPDLG pFlvDlg = vBetwToFlvMap [j][k];

							
							wstring wstrTitle2;
							if (pBetwDlg->enCT == vmsHttpTrafficCollector::HttpDialog::X_WWW_FORM_URL_ENCODED)
								ExtractTitleFromXWwwFormUrlEncoded (pBetwDlg, wstrTitle2);
							else if (pBetwDlg->enCT == vmsHttpTrafficCollector::HttpDialog::XML)
								ExtractTitleFromXml (pBetwDlg, wstrTitle2, pFlvDlg);

							if (wstrTitle2.empty ())
								wstrTitle2 = wstrTitle;

							AddFlvDownload (pWebPage, pFlvDlg, wstrTitle2.c_str ());
						}
						break;
					}
				}
			}

			return;
		}
	}
}

void vmsHttpFlvTrafficAnalyzer::ExtractTitleFromFlashVars(HTTPDLG pWebPage, LPCSTR pszFlashVars, wstring &wstrTitle)
{
	wstrTitle = L"";
	
	vector <string> vstrNames, vstrValues;
	vmsHttpHelper::ExtractUrlEncodedValues (pszFlashVars, &vstrNames, &vstrValues);
	assert (vstrNames.size () == vstrValues.size ());
	if (vstrValues.empty ())
		return;	
	
	string strTitle;
	
	for (size_t i = 0; i < vstrValues.size (); i++)
	{
		if (stricmp (vstrNames [i].c_str (), "title") == 0 || 
			stricmp (vstrNames [i].c_str (), "videoTitle") == 0)
		{
			vmsHttpHelper::DecodeUrl (vstrValues [i].c_str (), strTitle);
			break;
		}
	}
	
	if (strTitle.empty ())
		return;
	
	if (pWebPage)
		DecodeWebPageString (pWebPage, strTitle.c_str (), wstrTitle);
	else
		vmsCharsets::DecodeString (strTitle.c_str (), CP_UTF8, wstrTitle);
}

void vmsHttpFlvTrafficAnalyzer::FindDialogsByUniqueUrlWordsMatch(LPCSTR pszSwfContext, const HTTPDLGLIST &vDlgs, HTTPDLGLIST &vResult)
{
	LOGFN ("vmsHttpFlvTrafficAnalyzer::FindDialogsByUniqueUrlWordsMatch");

	vResult.clear ();
	
	vector < vector <string> > vvUniqueWords;
	vmsWinSockHttpTrafficAnalyzer::FindUniqueUrlWords (vDlgs, vvUniqueWords);
	
	assert (vvUniqueWords.size () == vDlgs.size ());
	
	for (size_t iDlg = 0; iDlg < vvUniqueWords.size (); iDlg++)
	{
		vector <string> &vWords = vvUniqueWords [iDlg];
		if (vWords.empty ())
			continue;
		for (size_t iW = 0; iW < vWords.size (); iW++)
		{
			if (strstr (pszSwfContext, vWords [iW].c_str ()) != NULL)
			{
				vResult.push_back (vDlgs [iDlg]);
				LOG ("Unique url word \"%s\" is containing in source text", vWords [iW].c_str ());
				LOG ("|-dialog url-%s", vDlgs [iDlg]->strRequestUrl.c_str ());
				break;
			}
		}
	}
}

void vmsHttpFlvTrafficAnalyzer::FindDialogsByUniqueUrlWordsMatch2(LPCSTR pszSomeUrl, const HTTPDLGLIST &vDlgs, HTTPDLGLIST &vResult)
{
	LOGFN ("vmsHttpFlvTrafficAnalyzer::FindDialogsByUniqueUrlWordsMatch2");

	assert (pszSomeUrl != NULL);
	
	vResult.clear ();
	
	if (!pszSomeUrl)
		return;
	
	vector <string> vWords;
	vmsUrlWords::ExtractWords2 (pszSomeUrl, vWords);
	if (vWords.empty ())
		return;
	
	string strWords;
	
	for (size_t i = 0; i < vWords.size (); i++)
	{
		strWords += vWords [i];
		strWords += ' ';
	}
	
	FindDialogsByUniqueUrlWordsMatch (strWords.c_str (), vDlgs, vResult);
}

void vmsHttpFlvTrafficAnalyzer::ExtractFlashVarsFromSwfUrl(LPCSTR pszUrl, const vmsHttpTrafficCollector *pTraffic, const vmsWinSockHttpDlgTree *pTree, string &strResult)
{
	strResult = "";

	assert (pszUrl != NULL);
	
	if (pszUrl == NULL || *pszUrl == 0)
		return;

	const vmsHttpTrafficCollector::HttpDialog* pSwfDlg = NULL;
	string strSwfUrl;

	if (pTree)
	{
		HTTPDLGTREEITEM pItem = pTree->FindTreeItem (pszUrl, vmsHttpTrafficCollector::HttpDialog::SWF, true);
		if (pItem)
			pSwfDlg = pItem->spDlg;
	}
	if (!pSwfDlg && pTraffic)
		pSwfDlg = pTraffic->FindDialogByRequestUrl (pszUrl);

	if (pSwfDlg)
	{
		while (pSwfDlg->spDlgRedirectChainPrev)
			pSwfDlg = pSwfDlg->spDlgRedirectChainPrev;
		strSwfUrl = pSwfDlg->strRequestUrl;
	}
	else
	{
		strSwfUrl = pszUrl;
	}
		
	LPCSTR psz = strchr (strSwfUrl.c_str (), '?');
	if (psz)
		strResult = psz + 1;
}

void vmsHttpFlvTrafficAnalyzer::AddFlvDownloads(const vmsHttpFlvTrafficAnalyzer &taFrom)
{
	for (size_t i = 0; i < taFrom.m_vDownloads.size (); i++)
		m_vDownloads.push_back (taFrom.m_vDownloads [i]);
}
