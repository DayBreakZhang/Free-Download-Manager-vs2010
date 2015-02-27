/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsHttpFlvTrafficAnalyzer5.h"
#include "vmsHttpHelper.h"
#include "vmsUrlWords.h"
#include "vmsHtmlParser.h"
#include "vmsHtmlTagParser.h"
#include "vmsSwfObjectsAndFlvsConformity.h"

vmsHttpFlvTrafficAnalyzer5::vmsHttpFlvTrafficAnalyzer5()
{

}

vmsHttpFlvTrafficAnalyzer5::~vmsHttpFlvTrafficAnalyzer5()
{

}

HRESULT vmsHttpFlvTrafficAnalyzer5::FindFlvDownloads(LPCSTR pszHtmlPageUrl, LPCSTR pszFrameUrl, LPCSTR pszSwfUrl, LPCSTR pszFlashVars,
		vector <string> &vOtherSwfUrls, vector <string> &vOtherFlashVars, vmsWinSockHttpDlgTree *pDlgTree)
{
	LOGFN ("vmsHttpFlvTrafficAnalyzer5::FindFlvDownloads");

	LOG ("Web page url: %s", pszHtmlPageUrl);
	LOG ("Frame url: %s", pszFrameUrl ? pszFrameUrl : "");
	LOG ("Swf url: %s", pszSwfUrl ? pszSwfUrl : "");

	assert (vOtherFlashVars.size () == vOtherSwfUrls.size ());
	if (vOtherFlashVars.size () != vOtherSwfUrls.size ())
		return E_INVALIDARG;

	int nWebPageStartIndex = 0, nFrameStartIndex = 0;
	HTTPDLGTREEITEM p1stWebPage = NULL;

	vector <HTTPDLGTREEITEMLIST> vFlvs;
	vFlvs.reserve (50);

#ifdef LOG_WEBFILES_TREE
	extern LONG _cInOnGetItBtnClicked;
	bool bLog = _cInOnGetItBtnClicked != 0;
	if (!bLog)
	{
		
		
		
		
		static DWORD _dwLastTicks = 0;
		if ((GetKeyState (VK_SHIFT) & GetKeyState (VK_CONTROL) & 0x8000) &&
			(GetTickCount () - _dwLastTicks > 10000))
		{
			bLog = true;
			_dwLastTicks = GetTickCount ();
		}
	}
	if (bLog)
	{
		pDlgTree->LogAllWebFiles ();
		pDlgTree->LogAllFlvTrees ();
	}
#endif

	while (true) 
	{
		HTTPDLGTREEITEM pWebPage = pDlgTree->FindTreeItem (pszHtmlPageUrl, 
			vmsHttpTrafficCollector::HttpDialog::HTML, false, &nWebPageStartIndex);

		if (!pWebPage)
			break;

		if (!p1stWebPage)
			p1stWebPage = pWebPage;

		pDlgTree->MakeItWebPageIfNotAlready ((vmsWinSockHttpDlgTree::TreeItem*)pWebPage);

		HTTPDLGTREEITEM pFrame = pszFrameUrl && *pszFrameUrl ? 
			pDlgTree->FindTreeItem (pszFrameUrl, vmsHttpTrafficCollector::HttpDialog::HTML, false, &nFrameStartIndex) : NULL;

		LOGHTTPDLGTREE ("Web page tree", pWebPage, 5);

#ifdef LOG_WEBFILES_TREE
	if (bLog)
	{
		pDlgTree->LogTreeItem (pWebPage, 5);
		if (pFrame)
			pDlgTree->LogTreeItem (pFrame, 5);
		static LONG _cCalls = 0;
		if (p1stWebPage == pWebPage)
		{
			LogMainCall (InterlockedIncrement (&_cCalls), pszHtmlPageUrl, pszFrameUrl, pszSwfUrl, pszFlashVars,
				vOtherSwfUrls, vOtherFlashVars, pDlgTree, pWebPage, pFrame);
		}
	}
#endif 

		vector <HTTPDLGTREEITEMLIST> vFlvs2;
		vFlvs2.reserve (50);

		pDlgTree->GetChildItemsWithPath (pWebPage, vFlvs2, vmsHttpTrafficCollector::HttpDialog::FLV, 5);
		for (size_t iFlv = 0; iFlv < vFlvs2.size (); iFlv++)
			vFlvs.push_back (vFlvs2 [iFlv]);

		if (pFrame)
		{
			
			vFlvs2.clear ();
			pDlgTree->GetChildItemsWithPath (pFrame, vFlvs2, vmsHttpTrafficCollector::HttpDialog::FLV, 5);
			for (size_t iFlv = 0; iFlv < vFlvs2.size (); iFlv++)
				vFlvs.push_back (vFlvs2 [iFlv]);
		}

		if ((pszFrameUrl == NULL || *pszFrameUrl == 0) && 
			(pszSwfUrl == NULL || *pszSwfUrl == 0) &&
			(pszFlashVars == NULL || *pszFlashVars == 0))
		{
			
			const vmsWinSockHttpDlgTree::WebPageDetails *pwpd = pWebPage->getWebPageDetails ();
			if (pwpd)
			{
				for (size_t i = 0; i < pwpd->vFrameUrls.size (); i++)
				{
					HTTPDLGTREEITEM pFrame = pDlgTree->FindTreeItem (pwpd->vFrameUrls [i].c_str (), 
						vmsHttpTrafficCollector::HttpDialog::HTML);
					if (pFrame)
					{
						vFlvs2.clear ();
						pDlgTree->GetChildItemsWithPath (pFrame, vFlvs2, vmsHttpTrafficCollector::HttpDialog::FLV, 5);
						for (size_t iFlv = 0; iFlv < vFlvs2.size (); iFlv++)
							vFlvs.push_back (vFlvs2 [iFlv]);
					}
				}
			}
		}
	}

	if (!p1stWebPage)
		return E_INVALIDARG;

	pDlgTree->GetChildItemsWithPath_EraseDupes (vFlvs);

	vector <HTTPDLGTREEITEMLIST> vFlvsToAdd;
	string strFlashVars0;

	if (pszSwfUrl && *pszSwfUrl)
	{
		if (pszFlashVars)
			strFlashVars0 = pszFlashVars;
		string str;
		ExtractFlashVarsFromSwfUrl (pszSwfUrl, NULL, pDlgTree, str);
		if (!strFlashVars0.empty ())
			strFlashVars0 += '&';
		strFlashVars0 += str;

		if (!vOtherSwfUrls.empty ())
		{
			vmsSwfObjectsAndFlvsConformity swfConfs (NULL, pDlgTree);
			swfConfs.addSwfObject (pszSwfUrl, pszFlashVars);
			for (size_t i = 0; i < vOtherSwfUrls.size (); i++)
				swfConfs.addSwfObject (vOtherSwfUrls [i].c_str (), vOtherFlashVars [i].c_str ());
			for (size_t i = 0; i < vFlvs.size (); i++)
				swfConfs.addFlv (NULL, NULL, &vFlvs [i]);
			
			swfConfs.FindComformity ();

			for (size_t i = 0; i < swfConfs.getConformitiesCount (); i++)
			{
				const vmsSwfObjectsAndFlvsConformity::Conformity *conf = swfConfs.getConformity (i);
				if (conf->pSwf->strSwfUrl == pszSwfUrl && conf->pSwf->strFlashVars == pszFlashVars)
					vFlvsToAdd.push_back (conf->pFlv->vPathFromWebPageToFlv);
			}
		}
		else
		{
			vFlvsToAdd = vFlvs;
		}
	}
	else
	{
		vFlvsToAdd = vFlvs;
	}

	for (size_t i = 0; i < vFlvsToAdd.size (); i++)
	{
		wstring wstrTitle;
		GetFlvTitle (p1stWebPage->spDlg, strFlashVars0.c_str (), vFlvsToAdd [i], wstrTitle);
		assert (vFlvsToAdd [i][vFlvsToAdd [i].size () - 1]->spDlg->enCT == vmsHttpTrafficCollector::HttpDialog::FLV);
		AddFlvDownload (p1stWebPage->spDlg, vFlvsToAdd [i][vFlvsToAdd [i].size () - 1]->spDlg, wstrTitle.c_str ());
	}
	
	return m_vDownloads.size () ? S_OK : S_FALSE;
}

void vmsHttpFlvTrafficAnalyzer5::GetFlvTitle(HTTPDLG pWebPage, LPCSTR pszFlashVars, HTTPDLGTREEITEMLIST &vFlvTree, wstring &wstrTitle)
{
	assert (!vFlvTree.empty ());
	if (vFlvTree.empty ())
		return;
	assert (vFlvTree [vFlvTree.size () - 1]->spDlg->enCT == vmsHttpTrafficCollector::HttpDialog::FLV);

	wstrTitle = L"";

	if (pszFlashVars && *pszFlashVars)
		ExtractTitleFromFlashVars (pWebPage, pszFlashVars, wstrTitle);

	if (!wstrTitle.empty ())
		return;

	for (int i = ((int)vFlvTree.size ()) - 2; i >= 0; i--)
	{
		HTTPDLG pDlg = vFlvTree [i]->spDlg;

		switch (pDlg->enCT)
		{
		case vmsHttpTrafficCollector::HttpDialog::X_WWW_FORM_URL_ENCODED:
			ExtractTitleFromXWwwFormUrlEncoded (pDlg, wstrTitle);
			break;

		case vmsHttpTrafficCollector::HttpDialog::XML:
			ExtractTitleFromXml (pDlg, wstrTitle, vFlvTree [vFlvTree.size () - 1]->spDlg);
			break;
		}

		if (!wstrTitle.empty ())
			return;
	}

	ExtractTitleFromHtml (pWebPage, wstrTitle);
}

#ifdef LOG_WEBFILES_TREE
void vmsHttpFlvTrafficAnalyzer5::LogMainCall (int iCall, LPCSTR pszHtmlPageUrl, LPCSTR pszFrameUrl, LPCSTR pszSwfUrl, LPCSTR pszFlashVars, vector <string> &vOtherSwfUrls, vector <string> &vOtherFlashVars, const vmsWinSockHttpDlgTree *pDlgTree, HTTPDLGTREEITEM pWebPage, HTTPDLGTREEITEM pFrame)
{
	TCHAR tszFile [MAX_PATH] = _T ("");
	GetTempPath (MAX_PATH, tszFile);
	_tcscat (tszFile, _T ("\\fdmflvsniff\\onDownloadIt-"));
	
	_stprintf (tszFile + _tcslen (tszFile), _T ("%03d.html"), iCall);

	HANDLE hFile = CreateFile (tszFile, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	assert (hFile != INVALID_HANDLE_VALUE);
	if (hFile == INVALID_HANDLE_VALUE)
		return;

	char szTmp [100] = "";

	string strHtml = "<html><body><h3>vmsHttpFlvTrafficAnalyzer5 onGetItButtonClicked</h3>"; 

	strHtml += "<b>Web page URL:</b><br>"; 
	strHtml += pszHtmlPageUrl ? pszHtmlPageUrl : "";
	assert (pWebPage != NULL);
	if (pWebPage)
	{
		strHtml += "<br>[<a href="; strHtml += itoa (pWebPage->spDlg->nID, szTmp, 16);
		strHtml += "-tree.html>tree</a>][<a href=webfiles\\";
		strHtml += szTmp; strHtml += ".txt>file</a>]";
	}
	strHtml += "<br><br>";

	strHtml += "<b>Frame URL:</b><br>";
	strHtml += pszFrameUrl && *pszFrameUrl && strcmp (pszHtmlPageUrl, pszFrameUrl) ? pszFrameUrl : "Not specified (none)";
	if (pFrame && pFrame != pWebPage)
	{
		strHtml += "<br>[<a href="; strHtml += itoa (pFrame->spDlg->nID, szTmp, 16);
		strHtml += "-tree.html>tree</a>][<a href=webfiles\\";
		strHtml += szTmp; strHtml += ".txt>file</a>]";
	}
	strHtml += "<br><br>";

	strHtml += "<b>Target SWF URL:</b><br>";
	strHtml += pszSwfUrl && *pszSwfUrl ? pszSwfUrl : "";
	strHtml += "<br><br>";

	strHtml += "<b>Target SWF FlashVars:</b><br>";
	strHtml += pszFlashVars ? pszFlashVars : "";
	strHtml += "<br><br>";

	assert (vOtherSwfUrls.size () == vOtherFlashVars.size ());

	if (vOtherSwfUrls.size () != vOtherFlashVars.size ())
		strHtml += "<b>ARGS ERROR: vOtherSwfUrls.size () != vOtherFlashVars.size ()</b><br><br>";
	else for (size_t i = 0; i < vOtherSwfUrls.size (); i++)
	{
		char sz [10] = ""; itoa (i, sz, 10);

		strHtml += "<b>Other SWF #"; strHtml += sz; strHtml += " URL:</b><br>";
		strHtml += vOtherSwfUrls [i].c_str ();
		strHtml += "<br><br>";
		
		strHtml += "<b>Other SWF #"; strHtml += sz; strHtml += " FlashVars:</b><br>";
		strHtml += vOtherFlashVars [i].c_str ();
		strHtml += "<br><br>";
	}
	
	DWORD dw = 0;
	WriteFile (hFile, strHtml.c_str (), strHtml.length (), &dw, NULL);

	CloseHandle (hFile);
}
#endif 