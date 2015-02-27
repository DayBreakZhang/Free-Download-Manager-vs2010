/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsWinSockHttpDlgTree.h"
#include "vmsUrlWords.h"
#include "vmsHttpHelper.h"
#include "vmsHtmlParser.h"
#include <shlwapi.h>
#include "vmsHtmlTagParser.h"
#include "vmsSwfFile.h"
#include "vmsUrl.h"
#include "vmsBrowserSpecialInfo.h"
#include "vmsUrlFromBrowser.h"
#include <atlbase.h>

extern LPCSTR strstrni (LPCSTR pszSrc, LPCSTR pszSrch, int lenSrc);

#define LOCKTREE vmsCriticalSectionAutoLock csalLOCKTREE ((LPCRITICAL_SECTION)&m_csModifyTree)
#define LOCKREMOVEOLDDLGS vmsCriticalSectionAutoLock csalLOCKREMOVEOLDDLGS ((LPCRITICAL_SECTION)&m_csRemoveOldDialogs)

vmsWinSockHttpDlgTree::vmsWinSockHttpDlgTree()
{
	m_htAddDialogs = NULL;
	m_bObjClosing = false;
	m_cFlvsInSession = 0;
}

vmsWinSockHttpDlgTree::~vmsWinSockHttpDlgTree()
{
	m_bObjClosing = true;
	if (m_htAddDialogs)
	{
		WaitForSingleObject (m_htAddDialogs, INFINITE);
		CloseHandle (m_htAddDialogs);
	}
}

vmsWinSockHttpDlgTree& vmsWinSockHttpDlgTree::o()
{
	static vmsWinSockHttpDlgTree o;
	return o;
}

#include "vmsUrlMonSpyDll.h"

void vmsWinSockHttpDlgTree::InsertDialog(SPHTTPDLG spDlg)
{
	LOGFN ("vmsWinSockHttpDlgTree::InsertDialog");

	assert (spDlg->pHttpResponse != NULL);
	if (spDlg->pHttpResponse && spDlg->pHttpResponse->getStatusCode () / 100 != 2)
		return; 
	

	if (spDlg->spUrlMonRequest)
	{
		static bool _bDontWait = false; 
		if (!_bDontWait)
		{
			for (int i = 0; i < 300 && !spDlg->spUrlMonRequest->isSrcTabCalculated (); i++)
				Sleep (10);
			assert (spDlg->spUrlMonRequest->isSrcTabCalculated ());
			if (!spDlg->spUrlMonRequest->isSrcTabCalculated ())
				_bDontWait = true; 
		}
	}

	LOCKTREE;

	TreeItemPtr item;
	item.CreateInstance ();
	
	item->spDlg = spDlg;

	if (spDlg->spUrlMonRequest)
	{
		USES_CONVERSION;
		item->strSrcTabUrl = W2CA (spDlg->spUrlMonRequest->getSrcTabUrl ());
	}

	vmsBrowserSpecialInfo::o ().Lock ();
	int nUrlInfoIndex = vmsBrowserSpecialInfo::o ().findUrlIndex (spDlg->strRequestUrl.c_str ());
	if (nUrlInfoIndex != -1)
	{
		vmsBrowserSpecialInfo::UrlInfo *urlInfo = vmsBrowserSpecialInfo::o ().getUrlInfo (nUrlInfoIndex);
		assert (urlInfo != NULL);
		if (urlInfo)
		{
			if (urlInfo->strSrcTabUrl != "about:blank")
				item->strSrcTabUrl = urlInfo->strSrcTabUrl;
			vmsBrowserSpecialInfo::o ().RemoveUrlInfo (nUrlInfoIndex);
		}
	}
	vmsBrowserSpecialInfo::o ().Unlock ();

	ExtractBodyText (item);

	ExtractUrlParameters (spDlg, item->strUrlParams);
	string strTmp;
	vmsHttpHelper::DecodeUrl (item->strUrlParams.c_str (), strTmp);
	if (strstr (strTmp.c_str (), "://")) 
		item->strDecodedUrlParams = strTmp; 

	if (spDlg->enCT == vmsHttpTrafficCollector::HttpDialog::HTML &&
			IsHtmlWebPage (item->strBodyText.c_str ()))
	{
		LOG ("Web page: %s", spDlg->strRequestUrl.c_str ());
		item->dwFlags |= TI_WEBPAGE;
		DoWebPageAdditionalProcessing (item);
	}
	else
	{
		FindItemParents (item);
	}

	if (m_vTree.empty () || m_vTree [m_vTree.size ()-1]->spDlg->nID < item->spDlg->nID)
	{
		m_vTree.push_back (item);
	}
	else
	{
		int nIndex = m_vTree.size () - 2;
		while (nIndex >= 0 && m_vTree [nIndex]->spDlg->nID > item->spDlg->nID)
			nIndex--;
		nIndex++;
		m_vTree.insert (m_vTree.begin () + nIndex, item);
		FindChildrenOfInsertedItem (nIndex);
	}

	if (spDlg->enCT == vmsHttpTrafficCollector::HttpDialog::FLV)
		InterlockedIncrement (&m_cFlvsInSession);

	LOG ("Added dialog:");
	LOG ("URL: %s", spDlg->strRequestUrl.c_str ());
	vmsLogHelper::LogHttpDlgTreeList ("Parents", item->vParent);
}

bool vmsWinSockHttpDlgTree::IsHtmlWebPage(LPCSTR pszHtml)
{
	assert (pszHtml != NULL);
	if (pszHtml == NULL || *pszHtml == 0)
		return false;
	extern LPCSTR strstrni (LPCSTR pszSrc, LPCSTR pszSrch, int lenSrc);
	int len = strlen (pszHtml);
	return len >= 40000 ||
		(strstrni (pszHtml, "<embed", len) || strstrni (pszHtml, "<object", len) || strstrni (pszHtml, "<script", len));
}

void vmsWinSockHttpDlgTree::ExtractBodyText(TreeItem *pItem)
{
	pItem->strBodyText = "";

	assert (pItem->spDlg !=- NULL);
	if (!pItem->spDlg)
		return;

	if (pItem->spDlg->vbResponseBody.empty ())
		return;

	string strTmp;

	switch (pItem->spDlg->enCT)
	{
	case vmsHttpTrafficCollector::HttpDialog::X_WWW_FORM_URL_ENCODED:
		strTmp.assign ((LPSTR)&pItem->spDlg->vbResponseBody [0], pItem->spDlg->vbResponseBody.size ());
		vmsHttpHelper::DecodeUrl (strTmp.c_str (), pItem->strBodyText);
		break;

	case vmsHttpTrafficCollector::HttpDialog::AMF:
		ExtractStringsFromByteArray (&pItem->spDlg->vbResponseBody [0], pItem->spDlg->vbResponseBody.size (), pItem->strBodyText);
		break;

	case vmsHttpTrafficCollector::HttpDialog::HTML:
		if (strstrni ((LPCSTR)&pItem->spDlg->vbResponseBody [0], "<html", pItem->spDlg->vbResponseBody.size ()))
			ExtractBodyText_html (pItem->spDlg, pItem->strBodyText);
		else
			pItem->strBodyText.assign ((LPSTR)&pItem->spDlg->vbResponseBody [0], pItem->spDlg->vbResponseBody.size ());
		break;

	case vmsHttpTrafficCollector::HttpDialog::SWF:
		ProcessSwfData (pItem);
		break;

	default:
		pItem->strBodyText.assign ((LPSTR)&pItem->spDlg->vbResponseBody [0], pItem->spDlg->vbResponseBody.size ());
		break;
	}
}

const vmsWinSockHttpDlgTree::TreeItem* vmsWinSockHttpDlgTree::FindTreeItem(LPCSTR pszUrl, vmsHttpTrafficCollector::HttpDialog::ResourceContentType enRT, BOOL bExactMatchOnly, int *pnStartIndex) const
{
	int nStartIndex = pnStartIndex ? *pnStartIndex : 0;

	if (nStartIndex < 0)
		nStartIndex = 0;
	
	LOCKTREE;

	if (nStartIndex >= m_vTree.size ())
		return NULL;

	vmsUrlFromBrowser::FindEqualUrlData feud;
	vmsUrlFromBrowser::FindEqualUrl_start (pszUrl, feud);

	DWORD adwCM [] = {
		vmsUrlFromBrowser::CM_JUST_COMPARE,
		vmsUrlFromBrowser::CM_WO_ANCHOR,
		vmsUrlFromBrowser::CM_DECODED | vmsUrlFromBrowser::CM_DECODED_WO_ANCHOR,
	};
	int iCMcount = bExactMatchOnly ? 1 : sizeof (adwCM) / sizeof (DWORD); 

	for (int nCM = 0; nCM < iCMcount; nCM++)
	for (int i = nStartIndex; i < m_vTree.size (); i++)
	{
		const vmsHttpTrafficCollector::HttpDialog* pDlg = m_vTree [i]->spDlg;
		if (!(pDlg->enCT & enRT))
			continue;
		DWORD dwCM = adwCM [nCM];
		if (pDlg->enCT != vmsHttpTrafficCollector::HttpDialog::HTML)
		{
			dwCM &= ~ (vmsUrlFromBrowser::CM_WO_ANCHOR | vmsUrlFromBrowser::CM_DECODED_WO_ANCHOR);
			if (!dwCM)
				continue;
		}		
		if (vmsUrlFromBrowser::FindEqualUrl_isEqual (pDlg->strRequestUrl.c_str (), dwCM, feud))
		{
			if (pnStartIndex)
				*pnStartIndex = i + 1;
			return m_vTree [i];
		}
	}

	if (pnStartIndex)
		*pnStartIndex = -1;

	return NULL;
}

void vmsWinSockHttpDlgTree::ExtractUrlParameters(HTTPDLG pDlg, string &strResult)
{
	strResult = "";
	assert (pDlg != NULL);
	if (!pDlg)
		return;
	string str0, str1;
	vector <string> v0, vParams;
	vmsUrlWords::ExtractWords (pDlg->strRequestUrl.c_str (), str0, v0, str1, vParams);
	string strUrlVals2; vmsHttpTrafficCollector::ExtractUrlValuesFromPostData (pDlg, strUrlVals2);
	if (!strUrlVals2.empty ())
		vmsUrlWords::ExtractWordsFromUrlEncodedValues (strUrlVals2.c_str (), vParams);
	for (size_t i = 0; i < vParams.size (); i++)
	{
		if (!strResult.empty ())
			strResult += ' ';
		strResult += vParams [i];
	}
}

void vmsWinSockHttpDlgTree::GetChildItems(HTTPDLGTREEITEM item, vector <HTTPDLGTREEITEM> &vChildren, vmsHttpTrafficCollector::HttpDialog::ResourceContentType enCT, int nDepth) const
{
	LOCKTREE;
	vChildren.clear ();
	if (nDepth > 15)
		nDepth = 15;
	GetChildItems_imp (item, vChildren, enCT, nDepth);
}

void vmsWinSockHttpDlgTree::GetChildItems_imp(HTTPDLGTREEITEM item, vector <HTTPDLGTREEITEM> &vChildren, vmsHttpTrafficCollector::HttpDialog::ResourceContentType enCT, int nDepth)
{
	for (size_t i = 0; i < item->vChild.size (); i++)
	{
		if (item->vChild [i]->spDlg->enCT == enCT)
			vChildren.push_back (item->vChild [i]);
	}

	if (nDepth > 0)
	{
		for (size_t i = 0; i < item->vChild.size (); i++)
			GetChildItems_imp (item->vChild [i], vChildren, enCT, nDepth-1);
	}
}

void vmsWinSockHttpDlgTree::MoveDialogToTop(HTTPDLG pDlg)
{
	LOGFN ("vmsWinSockHttpDlgTree::MoveDialogToTop");

	LOCKTREE;

	int nDlgOldIndex = FindItemIndexByDialog (pDlg);
	if (nDlgOldIndex <= 0)
		return;

	SPHTTPDLGTREEITEM dlgTreeItem = m_vTree [nDlgOldIndex];
	m_vTree.erase (m_vTree.begin () + nDlgOldIndex);
	m_vTree.insert (m_vTree.begin (), dlgTreeItem);

	FindChildrenOfInsertedItem (0);

	if (pDlg->enCT == vmsHttpTrafficCollector::HttpDialog::FLV)
		InterlockedIncrement (&m_cFlvsInSession);

	LOG ("Dialog was moved to top:");
	LOG ("URL: %s", dlgTreeItem->spDlg->strRequestUrl.c_str ());
	vmsLogHelper::LogHttpDlgTreeList ("Children", dlgTreeItem->vChild);
}

int vmsWinSockHttpDlgTree::FindItemIndexByDialog(HTTPDLG pDlg) const
{
	for (size_t i = 0; i < m_vTree.size (); i++)
	{
		if (m_vTree [i]->spDlg == pDlg)
			return i;
	}

	return -1;
}

void vmsWinSockHttpDlgTree::Item_clearParents(TreeItem *item, bool bRemoveChildFromParents)
{
	if (bRemoveChildFromParents)
	{
		for (size_t i = 0; i < item->vParent.size (); i++)
		{
			SPHTTPDLGTREEITEM &parentItem = item->vParent [i];
			for (size_t j = 0; j < parentItem->vChild.size (); j++)
			{
				if (parentItem->vChild [j] == item)
				{
					parentItem->vChild.erase (parentItem->vChild.begin () + j);
					break;
				}
			}
		}
	}
	item->vParent.clear ();
	item->fParentWeight = 0;
	#ifdef LOG_WEBFILES_TREE
		item->vParentsInfo.clear ();
	#endif
}

void vmsWinSockHttpDlgTree::Item_addParentItem(TreeItem *item, TreeItem *pParent, float fParentWeight, bool bAddChildToParent
#ifdef LOG_WEBFILES_TREE
			, LPCSTR pszReason
#endif
										   )
{
	if (item->fParentWeight && (item->fParentWeight < fParentWeight))
		Item_clearParents (item, bAddChildToParent);

	item->fParentWeight = fParentWeight;
	item->vParent.push_back (pParent);

	#ifdef LOG_WEBFILES_TREE
		TreeItem::ParentInfo tpi;
		tpi.spParentItem = pParent;
		tpi.strReason = pszReason;
		item->vParentsInfo.push_back (tpi);
	#endif

	if (bAddChildToParent)
		pParent->vChild.push_back (item);
}

void vmsWinSockHttpDlgTree::GetChildItemsWithPath(HTTPDLGTREEITEM item, vector <vector <HTTPDLGTREEITEM> > &vChildren, vmsHttpTrafficCollector::HttpDialog::ResourceContentType enCT, int nDepth) const
{
	LOCKTREE;
	vChildren.clear ();
	if (nDepth > 15)
		nDepth = 15;
	HTTPDLGTREEITEMLIST vPath;
	GetChildItemsWithPath_imp (item, vChildren, enCT, nDepth, vPath);
}

void vmsWinSockHttpDlgTree::GetChildItemsWithPath_imp(HTTPDLGTREEITEM item, vector <HTTPDLGTREEITEMLIST> &vChildren, vmsHttpTrafficCollector::HttpDialog::ResourceContentType enCT, int nDepth, HTTPDLGTREEITEMLIST vPath)
{
	for (size_t i = 0; i < item->vChild.size (); i++)
	{
		if (item->vChild [i]->spDlg->enCT == enCT)
		{
			vPath.push_back (item->vChild [i]);
			vChildren.push_back (vPath);
			vPath.erase (vPath.end ()-1);
		}
	}
	
	if (nDepth > 0)
	{
		for (size_t i = 0; i < item->vChild.size (); i++)
		{
			HTTPDLGTREEITEM pChild = item->vChild [i];
			if (pChild->vChild.empty ())
				continue;
			vPath.push_back (pChild);
			GetChildItemsWithPath_imp (pChild, vChildren, enCT, nDepth-1, vPath);
			vPath.erase (vPath.end ()-1);
		}
	}
}

void vmsWinSockHttpDlgTree::GetChildItemsWithPath_EraseDupes(vector <HTTPDLGTREEITEMLIST> &vChildren) const
{
	LOCKTREE;

	for (int i = 0; i < vChildren.size (); i++)
	{
		HTTPDLGTREEITEMLIST &v = vChildren [i];

		for (int j = i+1; j < vChildren.size (); j++)
		{
			HTTPDLGTREEITEMLIST &v2 = vChildren [j];

			if (v [v.size ()-1] == v2 [v2.size ()-1])
			{
				
				if (v.size () <= v2.size ())
				{
					vChildren.erase (vChildren.begin () + j--);
				}
				else
				{
					vChildren.erase (vChildren.begin () + i--);
					break;
				}
			}
		}
	}
}

bool vmsWinSockHttpDlgTree::HasItemFlvChild (const TreeItem *item, int iMaxDepth)
{
	for (size_t i = 0; i < item->vChild.size (); i++)
	{
		if (item->vChild [i]->spDlg->enCT == vmsHttpTrafficCollector::HttpDialog::FLV)
			return true;
	}

	if (iMaxDepth)
	{
		iMaxDepth--;

		for (size_t i = 0; i < item->vChild.size (); i++)
		{
			if (HasItemFlvChild (item->vChild [i], iMaxDepth))
				return true;
		}
	}

	return false;
}

void vmsWinSockHttpDlgTree::RemoveAllDialogsOlderWhen(UINT nSeconds, UINT nSecondsForWebPagesAndFlvs)
{
	LOGFN ("vmsWinSockHttpDlgTree::RemoveAllDialogsOlderWhen");
	
	LOCKREMOVEOLDDLGS;
	LOCKTREE;
	
	DWORD dwTicksNow = GetTickCount ();

	vector <TreeItemPtr> vNewTree;
	vNewTree.reserve (m_vTree.size ());
		
	for (size_t i = 0; i < m_vTree.size (); i++)
	{
		TreeItem *item = m_vTree [i];
		DWORD dwInterval;

		if (item->spDlg->enCT == vmsHttpTrafficCollector::HttpDialog::FLV ||
				item->spDlg->enCT == vmsHttpTrafficCollector::HttpDialog::SWF)
		{
			dwInterval = nSecondsForWebPagesAndFlvs;
		}
		else if (item->isWebPage () && HasItemFlvChild (item, 5))
		{
			dwInterval = nSecondsForWebPagesAndFlvs;
		}
		else
		{
			dwInterval = nSeconds;
		}
		
		if ((dwTicksNow - item->spDlg->dwTicksWhenCompleted) < (dwInterval * 1000))
			vNewTree.push_back (item);
	}
	
	if (vNewTree.size () != m_vTree.size ())
		m_vTree = vNewTree;
}

void vmsWinSockHttpDlgTree::LockRemoveOldDialogs(bool bLock)
{
	if (bLock)
		EnterCriticalSection (&m_csRemoveOldDialogs);
	else
		LeaveCriticalSection (&m_csRemoveOldDialogs);
}

void vmsWinSockHttpDlgTree::InsertDialog_Async(SPHTTPDLG spDlg)
{
	EnterCriticalSection (&m_csModifyAddDialogsList);
	
	m_vAddDialogsList.push_back (spDlg);

	if (!m_htAddDialogs)
	{
		DWORD dw;
		m_htAddDialogs = CreateThread (NULL, 0, _threadAddDialogs, this, 0, &dw);
	}

	LeaveCriticalSection (&m_csModifyAddDialogsList);
}

DWORD WINAPI vmsWinSockHttpDlgTree::_threadAddDialogs(LPVOID lp)
{
	vmsWinSockHttpDlgTree *pthis = (vmsWinSockHttpDlgTree*)lp;

	while (!pthis->m_bObjClosing)
	{
		while (!pthis->m_vAddDialogsList.empty ())
		{
			EnterCriticalSection (&pthis->m_csModifyAddDialogsList);
			SPHTTPDLG spDlg = pthis->m_vAddDialogsList [0];
			LeaveCriticalSection (&pthis->m_csModifyAddDialogsList);
			LOG ("ADDING TO TREE ID=%x", spDlg->nID);
			pthis->InsertDialog (spDlg);
			EnterCriticalSection (&pthis->m_csModifyAddDialogsList);
			pthis->m_vAddDialogsList.erase (pthis->m_vAddDialogsList.begin ());
			LeaveCriticalSection (&pthis->m_csModifyAddDialogsList);
		}

		Sleep (10);
	}

	return 0;
}

bool vmsWinSockHttpDlgTree::UrlExistsInProcessHttpDialogsQueue (LPCSTR pszUrl)
{
	bool bExists = false;
	EnterCriticalSection (&m_csModifyAddDialogsList);
	for (size_t i = 0; i < m_vAddDialogsList.size (); i++)
	{
		SPHTTPDLG spDlg = m_vAddDialogsList [i];
		if (spDlg->strRequestUrl == pszUrl)
		{
			bExists = true;
			break;
		}
	}
	LeaveCriticalSection (&m_csModifyAddDialogsList);
	return bExists;
}

void vmsWinSockHttpDlgTree::ExtractBodyText_html(HTTPDLG pDlg, string &strResult)
{
	LOGFN ("vmsWinSockHttpDlgTree::ExtractBodyText_html");

	strResult = "";
	assert (!pDlg->vbResponseBody.empty ());
	if (pDlg->vbResponseBody.empty ())
		return;

	LPCSTR psz = pDlg->getBodyText ();

	while (psz && *psz)
	{
		psz = strchr (psz, '<');
		if (!psz)
			return;

		vmsHtmlTagParser tag;
		int nTagHeadLen = tag.Parse (psz);

		LPCSTR pszTagItselfName = tag.getName ();
		if (*pszTagItselfName == '/')
			pszTagItselfName++;

		string strTagHead; strTagHead.assign (psz, nTagHeadLen);
		assert (!strTagHead.empty ());
		psz += nTagHeadLen;
		if (strTagHead.empty ())
			psz++;
		
		if (!stricmp (pszTagItselfName, "a") || !stricmp (pszTagItselfName, "!--"))
			continue; 

		strResult += strTagHead;

		if (!stricmp (tag.getName (), "script"))
		{
			LPCSTR pszEndScript = psz;
			while (true)
			{
				pszEndScript = StrStrIA (pszEndScript, "</script");
				if (!pszEndScript)
					break;
				if (pszEndScript [8] == '>' || isspace (pszEndScript [8]))
					break;
				pszEndScript++; 
			}

			string strScript;

			if (!pszEndScript)
			{
				strScript = psz;
				psz += strlen (psz);
			}
			else
			{
				if (pszEndScript != psz)
				{
					strScript.assign (psz, pszEndScript-psz);
					psz = pszEndScript;
				}
			}

			if (!strScript.empty ())
			{
				string strScript2;
				ExtractBodyText_html_decodeScriptStrings (strScript.c_str (), strScript2);
				strResult += strScript2;
			}
		}
	}
}

void vmsWinSockHttpDlgTree::ExtractBodyText_html_decodeScriptStrings(LPCSTR pszScript, string &strResult)
{
	assert (pszScript != NULL);
	strResult = "";

	if (!pszScript)
		return;

	bool bInString = false;
	bool bSpecSymb = false;

	while (*pszScript)
	{
		char ch = *pszScript++;

		 

		if (bInString && ch == '\\' && *pszScript)
		{
			char ch = *pszScript++;

			switch (ch)
			{
			case 'n': ch = '\n'; break;
			case 'r': ch = '\r'; break;
			case 't': ch = '\t'; break;
			case '\\': ch = '\\'; break;
			case '"': ch = '"'; break;
			case '\'': ch = '\''; break;
			default: ch = ' '; 
			}

			bSpecSymb = true;
		}

		if (bSpecSymb)
		{
			bSpecSymb = false;
		}
		else
		{
			if (ch == '"' || ch == '\'')
				bInString = !bInString;
		}

		strResult += ch;
	}
}

void vmsWinSockHttpDlgTree::FindItemParents(TreeItem *item)
{
	LOGFN ("vmsWinSockHttpDlgTree::FindItemParents");

	assert (item != NULL);
	if (!item)
		return;
	
	assert (item->spDlg != NULL);
	if (!item->spDlg)
		return;
	
	if (m_vTree.empty ())
		return;

	LOCKTREE;
	
#ifdef SCL_ENABLE
	
	if (item->spDlg->enCT != vmsHttpTrafficCollector::HttpDialog::FLV)
		LOG ("Find parents for %s", item->spDlg->strRequestUrl.c_str ());
	else
		LOG ("Find parents for [FLV] %s", item->spDlg->strRequestUrl.c_str ());
#endif

	if (!item->strSrcTabUrl.empty ())
	{
		int nIndex = 0;
		TreeItem* pParent = NULL, *pLastParent = NULL;
		while (pParent = (TreeItem*)FindTreeItem (item->strSrcTabUrl.c_str (), vmsHttpTrafficCollector::HttpDialog::HTML, false, &nIndex))
		{
			pLastParent = pParent;
			if (Item_findDupeChildIndex (pParent, item) != -1)
				continue;
			#ifdef LOG_WEBFILES_TREE
				Item_addParentItem (item, pParent, 1.1f, true, "by SrcTabUrl");
			#else
				Item_addParentItem (item, pParent, 1.1f, true);
			#endif
		}
		if (item->vParent.empty () && pLastParent)
		{
			#ifdef LOG_WEBFILES_TREE
				Item_addParentItem (item, pLastParent, 1.1f, true, "by SrcTabUrl");
			#else
				Item_addParentItem (item, pLastParent, 1.1f, true);
			#endif
		}
		return;
	}

	SPHTTPDLG spDlgFindParentsFor = item->spDlg;
	while (spDlgFindParentsFor->spDlgRedirectChainPrev)
		spDlgFindParentsFor = spDlgFindParentsFor->spDlgRedirectChainPrev;

#ifdef SCL_ENABLE
	if (spDlgFindParentsFor != item->spDlg)
		LOG (" find parents for redirect root: %s", spDlgFindParentsFor->strRequestUrl.c_str ());
#endif

	vector <TreeItemPtr> vDialogsSearchIn;

	if (!spDlgFindParentsFor->vDlgsRefererLinksTo.empty () &&
			(spDlgFindParentsFor->dwFlags & vmsHttpTrafficCollector::HttpDialog::REFERER_NONSAFE) == 0)
	{
		LOGsnl ("have referer dialog(s).");

		
		FindDialogsInTree (spDlgFindParentsFor->vDlgsRefererLinksTo, vDialogsSearchIn);

		
		if ((spDlgFindParentsFor->dwFlags & vmsHttpTrafficCollector::HttpDialog::REFERER_AMBIGOUS) == 0)
		{
			LOGsnl ("have non ambigous referer");

			
			if (vDialogsSearchIn.empty ())
			{
				LOGsnl ("we'll add parents as soon as they will be added.");
				return; 
			}
			for (size_t i = 0; i < vDialogsSearchIn.size (); i++)
			{
				bool bDoNotAddDupe = item->vParent.empty () == false || (i+1 < vDialogsSearchIn.size ()) || 
						vDialogsSearchIn.size () < spDlgFindParentsFor->vDlgsRefererLinksTo.size () ;
				if (bDoNotAddDupe && Item_findDupeChildIndex (vDialogsSearchIn [i], item) != -1)
					continue; 
				TreeItem *pParent = vDialogsSearchIn [i];
				if (pParent->getWebPageDetails ())
					Item_removeChildAddedByWebPageProcessingIfRequired (pParent, item->spDlg->strRequestUrl.c_str ());
				#ifdef LOG_WEBFILES_TREE
					Item_addParentItem (item, pParent, 1.1f, true, "by referer");
				#else
					Item_addParentItem (item, pParent, 1.1f, true);
				#endif
			}
			return;
		}
	}

	vector <TreeItemPtr> &vTree = vDialogsSearchIn.empty () ? m_vTree : vDialogsSearchIn;

#ifdef SCL_ENABLE
	LOGsnl (vDialogsSearchIn.empty () ? "search in the whole tree." : "search in referered dialogs");
#endif
	
	_inc_FindItemParents fip;
	FindItemParents_start (spDlgFindParentsFor, fip, vTree);
	
	for (int iStep = _inc_FindItemParents::STEP_START; iStep <= _inc_FindItemParents::STEP_END; iStep++)
	{
		item->fParentWeight = 0;
		
		for (int i = 0; i < vTree.size (); i++)
		{
			TreeItemPtr& treeItem = vTree [i];
			#ifdef LOG_WEBFILES_TREE
				string strReason;				
				float fWeight = FindItemParents_getParentWeihgt (fip, treeItem, (_inc_FindItemParents::Step)iStep, strReason);
			#else
				float fWeight = FindItemParents_getParentWeihgt (fip, treeItem, (_inc_FindItemParents::Step)iStep);
			#endif
			if (fWeight && (fWeight >= item->fParentWeight))
			{
				#ifdef LOG_WEBFILES_TREE
					Item_addParentItem (item, treeItem, fWeight, false, strReason.c_str ());
				#else
					Item_addParentItem (item, treeItem, fWeight, false);
				#endif
			}
		}
		
		if (!item->vParent.empty ())
			break;
	}

	for (int i = 0; i < (int)item->vParent.size (); i++)
	{
		TreeItem *pParent = item->vParent [i];
		if (pParent->getWebPageDetails ())
			Item_removeChildAddedByWebPageProcessingIfRequired (pParent, item->spDlg->strRequestUrl.c_str ());
		if (item->vParent.size () > 1 && Item_findDupeChildIndex (pParent, item) != -1)
		{
			Item_removeParent (item, i--, false);
			continue;
		}
		pParent->vChild.push_back (item);
	}
}

void vmsWinSockHttpDlgTree::FindItemParents_start(HTTPDLG pDlg, _inc_FindItemParents &fip, vector <TreeItemPtr> &vTree, int nFindIndexStart, int nFindIndexEnd)
{
	fip.vUrlWords.clear (); fip.vUrlWordWeights.clear ();
	fip.pvTree = &vTree;
	assert (!vTree.empty ());
	if (vTree.empty ())
		return;
	assert (nFindIndexStart >= 0);
	fip.nFindIndexStart = nFindIndexStart;
	assert (nFindIndexEnd >= nFindIndexStart || nFindIndexEnd == -1);
	fip.nFindIndexEnd = nFindIndexEnd == -1 ? vTree.size () - 1 : nFindIndexEnd;
	assert (fip.nFindIndexStart < fip.pvTree->size () && fip.nFindIndexStart <= fip.nFindIndexEnd);
	assert (fip.nFindIndexEnd < fip.pvTree->size ());
	if (fip.nFindIndexEnd >= fip.pvTree->size ())
		fip.nFindIndexEnd = fip.pvTree->size () - 1;
	if (fip.nFindIndexStart > fip.nFindIndexEnd)
		fip.nFindIndexStart = fip.nFindIndexEnd;
	fip.pDlg = pDlg;
	fip.pszUrl = pDlg->strRequestUrl.c_str ();
	fip.pszUrlPath = vmsUrl::GetFilePathStart (fip.pszUrl);
	assert (fip.pszUrlPath != NULL);
	fip.pszShortenUrlStart = strstr (fip.pszUrl, "://");
	assert (fip.pszShortenUrlStart != NULL);
	if (fip.pszShortenUrlStart)
		fip.pszShortenUrlStart++; 
	else 
		fip.pszShortenUrlStart = fip.pszUrl;
	fip.nUrlLen = pDlg->strRequestUrl.length ();
	fip.nUrlStart_Path_delta = fip.pszUrlPath - fip.pszShortenUrlStart;
	vmsUrlWords::ExtractWords2 (fip.pszUrl, fip.vUrlWords);
	fip.bFindUrlWordsStepPerformed = false;
	fip.bCanBeFoundByRelativePath = false;
	LPCSTR pszPathEnd = vmsUrl::GetFileNamePartStart (fip.pszUrl);
	if (pszPathEnd)
	{
		bool bAlphasOnly = true;
		while (*pszPathEnd && bAlphasOnly)
			bAlphasOnly = isalpha ((BYTE)*pszPathEnd++) != 0;
		if (!bAlphasOnly)
			fip.bCanBeFoundByRelativePath = true;
	}
	string strUrlVals2; vmsHttpTrafficCollector::ExtractUrlValuesFromPostData (pDlg, strUrlVals2);
	if (!strUrlVals2.empty ())
		vmsUrlWords::ExtractWordsFromUrlEncodedValues (strUrlVals2.c_str (), fip.vUrlWords);
	for (size_t i = 0; i < fip.vUrlWords.size (); i++)
		fip.vUrlWordWeights.push_back (vmsUrlWords::GetUrlWordWeight (fip.vUrlWords [i].c_str ()));
	fip.iUrlWordsTotalWeight = 0;
	for (int i = 0; i < fip.vUrlWords.size (); i++)
		fip.iUrlWordsTotalWeight += fip.vUrlWordWeights [i];
}

float vmsWinSockHttpDlgTree::FindItemParents_getParentWeihgt (_inc_FindItemParents &fip, const TreeItem* pDlgParentTreeItem, const _inc_FindItemParents::Step enStep
#ifdef LOG_WEBFILES_TREE
, string &strReason
#endif
)
{
	if (enStep == _inc_FindItemParents::ALL_STEPS || enStep == _inc_FindItemParents::EXACT_URL_MATCH)
	{
		
		assert (fip.pszUrlPath != NULL);
		LPCSTR pszFind = strstr (pDlgParentTreeItem->strBodyText.c_str (), fip.pszUrlPath);
		bool bDontCheckFullUrlExistance = false;
		
		#ifdef LOG_WEBFILES_TREE
			if (pszFind)
				strReason = "has full path specified";
		#endif

		if (!pszFind && fip.bCanBeFoundByRelativePath)
		{
			
			LPCSTR pszPathEnd = vmsUrl::GetFileNamePartStart (pDlgParentTreeItem->spDlg->strRequestUrl.c_str ());
			if (pszPathEnd)
			{
				int nFullPathLen = pszPathEnd - pDlgParentTreeItem->spDlg->strRequestUrl.c_str ();
				if (nFullPathLen < fip.nUrlLen &&
						!strncmp (pDlgParentTreeItem->spDlg->strRequestUrl.c_str (), fip.pszUrl, nFullPathLen))
				{
					pszFind = strstr (pDlgParentTreeItem->strBodyText.c_str (), fip.pszUrl + nFullPathLen);
					if (pszFind)
					{
						bDontCheckFullUrlExistance = true;
						#ifdef LOG_WEBFILES_TREE
							strReason = "has relative path specified";
						#endif
					}
				}
			}
		}
		
		if (pszFind && !bDontCheckFullUrlExistance)
		{
			if (fip.pDlg->strRequestHost != pDlgParentTreeItem->spDlg->strRequestHost)
			{
				
				if (pszFind - pDlgParentTreeItem->strBodyText.c_str () < fip.nUrlStart_Path_delta)
					pszFind = NULL; 
				else if (strncmp (pszFind - fip.nUrlStart_Path_delta, fip.pszShortenUrlStart, fip.nUrlStart_Path_delta))
					pszFind = NULL;
				#ifdef LOG_WEBFILES_TREE
					if (pszFind)
						strReason = "has full url specified";
				#endif
			}
		}
		
		if (pszFind)
		{
			return 1.1f;
		}
		else
		{
			
			if (pDlgParentTreeItem->strDecodedUrlParams.length () >= fip.nUrlLen)
			{
				if (strstr (pDlgParentTreeItem->strDecodedUrlParams.c_str (), fip.pszUrl))
				{
					#ifdef LOG_WEBFILES_TREE
						strReason = "full url is specified in url parameters";
					#endif
					return 1.1f;
				}
			}
		}
	}
	
	if (enStep == _inc_FindItemParents::ALL_STEPS || enStep == _inc_FindItemParents::BY_URL_WORDS)
	{
		assert (!fip.vUrlWords.empty ());

		if (!fip.bFindUrlWordsStepPerformed)
			FindItemParents_getParentWeihgt_findUrlWordsInTreeItems (fip);

		if (!fip.vUrlWords.empty ())
		{
			
			assert (fip.pDlg->strRequestHost == fip.vUrlWords [0]);

			if (pDlgParentTreeItem->fFoundWordsWeight == 1.0f)
			{
				#ifdef LOG_WEBFILES_TREE
					strReason = "contains all url words";
				#endif
				return 1.0f;
			}

			
			vector <bool> vUrlWordPresent = pDlgParentTreeItem->vUrlWordPresent;

			#ifdef LOG_WEBFILES_TREE
				strReason = "parent has words: ";
				bool bNeedComma = false;
				{for (size_t i = 0; i < vUrlWordPresent.size (); i++)
				{
					if (vUrlWordPresent [i])
					{
						if (bNeedComma)
							strReason += ", ";
						strReason += fip.vUrlWords [i];
						bNeedComma = true;
					}
				}}
				if (!bNeedComma)
					strReason += "{none}";
				bNeedComma = false;
				strReason += ". Other children has words: ";
			#endif

			
			
			
			
			
			float fChildrenMaxUrlWordWeight = 0;

			for (size_t iChildItem = 0; iChildItem < pDlgParentTreeItem->vChild.size (); iChildItem++)
			{
				TreeItem *child = pDlgParentTreeItem->vChild [iChildItem];
				fChildrenMaxUrlWordWeight = max (fChildrenMaxUrlWordWeight, child->fFoundWordsWeight);
				assert (child->vUrlWordPresent.size () == fip.vUrlWords.size ());
				if (child->fFoundWordsWeight == 0.0f && vUrlWordPresent [0])
					continue;
				for (size_t iWord = 0; iWord < child->vUrlWordPresent.size (); iWord++)
				{
					if (vUrlWordPresent [iWord])
						continue;
					bool bWordPresent = child->vUrlWordPresent [iWord];
					if (!bWordPresent && (iWord == 0))
					{
						
						if (child->spDlg->strRequestHost == fip.pDlg->strRequestHost)
							bWordPresent = true;
						else if (child->spDlg->vCanHaveChildrenWithHosts.findIndex (fip.pDlg->strRequestHost) != -1)
							bWordPresent = true;
					}
					if (bWordPresent)
					{
						#ifdef LOG_WEBFILES_TREE
							if (bNeedComma)
								strReason += ",  ";
							strReason += "<a href=webfiles\\";
							char sz [100]; strReason += itoa (child->spDlg->nID, sz, 16);
							strReason += ".txt>"; strReason += fip.vUrlWords [iWord]; strReason += "</a>";
							bNeedComma = true;
						#endif
						vUrlWordPresent [iWord] = true;
					}
				}
			}

			bool bHostOk = vUrlWordPresent [0] || 
				pDlgParentTreeItem->spDlg->strRequestHost == fip.pDlg->strRequestHost;

			if (!bHostOk)
			{
				#ifdef LOG_WEBFILES_TREE
					strReason = "";
				#endif
				return 0.0f;
			}

			#ifdef LOG_WEBFILES_TREE
				if (!bNeedComma)
					strReason += "{none}";
			#endif

			int iWeight = 0;
			for (size_t iWord = 0; iWord < vUrlWordPresent.size (); iWord++)
			{
				if (vUrlWordPresent [iWord])
					iWeight += fip.vUrlWordWeights [iWord];
			}

			float fWeight = (float)iWeight / (float)fip.iUrlWordsTotalWeight;

			
			
			
			
			
			
			if (fWeight == fChildrenMaxUrlWordWeight)
				fWeight = pDlgParentTreeItem->fFoundWordsWeight;

			
			
			
			
			
			
			
			

			return fWeight;
		}
	}
	
	#ifdef LOG_WEBFILES_TREE
		strReason = "";
	#endif
	return 0.0f;
}

void vmsWinSockHttpDlgTree::FindItemParents_getParentWeihgt_findUrlWordsInTreeItems(_inc_FindItemParents &fip)
{
	for (size_t i = fip.nFindIndexStart; i <= fip.nFindIndexEnd; i++)
	{
		TreeItem *item = fip.pvTree->at (i);
		item->clearFindItemParentData ();
		for (size_t j = 0; j < item->vChild.size (); j++)
			item->vChild [j]->clearFindItemParentData ();
	}

	if (fip.vUrlWords.empty ())
	{
		fip.bFindUrlWordsStepPerformed = true;
		return;
	}

	for (size_t i = fip.nFindIndexStart; i <= fip.nFindIndexEnd; i++)
		FindItemParents_getParentWeihgt_findUrlWordsInAllTreeItems_forItem (fip, fip.pvTree->at (i));

	for (size_t i = fip.nFindIndexStart; i <= fip.nFindIndexEnd; i++)
	{
		TreeItem *item = fip.pvTree->at (i);
		for (size_t j = 0; j < item->vChild.size (); j++)
		{
			if (item->vChild [j]->vUrlWordPresent.empty ())
				FindItemParents_getParentWeihgt_findUrlWordsInAllTreeItems_forItem (fip, item->vChild [j]);
		}
	}

	fip.bFindUrlWordsStepPerformed = true;
}

void vmsWinSockHttpDlgTree::FindItemParents_getParentWeihgt_findUrlWordsInAllTreeItems_forItem(_inc_FindItemParents &fip, TreeItem *item)
{
	assert (item->vUrlWordPresent.empty ());

	int iWeight = 0;

	if (item->spDlg->strRequestUrl == fip.pszUrl)
	{
		for (size_t iWord = 0; iWord < fip.vUrlWords.size (); iWord++)
			item->vUrlWordPresent.push_back (false);
	}
	else for (size_t iWord = 0; iWord < fip.vUrlWords.size (); iWord++)
	{
		bool bFound = strstr (item->strUrlParams.c_str (), fip.vUrlWords [iWord].c_str ()) != NULL;
		bool bSkip = false;
		if (bFound && (item->dwFlags & TI_WEBPAGE) == 0)
		{
			
			bFound = false;
			bSkip = true;
		}
		if (!bSkip)
		{
			if (!bFound)
				bFound = strstr (item->strBodyText.c_str (), fip.vUrlWords [iWord].c_str ()) != NULL;
		}
		
		if (bFound)
			iWeight += fip.vUrlWordWeights [iWord];

		item->vUrlWordPresent.push_back (bFound);
	}

	item->fFoundWordsWeight = (float)iWeight / (float)fip.iUrlWordsTotalWeight;
}

#ifdef LOG_WEBFILES_TREE
void vmsWinSockHttpDlgTree::LogTreeItem(const TreeItem *item, int nDepth, bool bReversed) const
{
	TCHAR tszPath [MAX_PATH] = _T ("");
	GetTempPath (MAX_PATH, tszPath);
	_tcscat (tszPath, _T ("\\fdmflvsniff"));
	CreateDirectory (tszPath, NULL);

	string strHtml; strHtml.reserve (100*1024);
	strHtml = "<html><body><h3>";
	if (bReversed)
		strHtml += "Reversed tree ";
	else
		strHtml += "Tree ";
	strHtml += "with depth = ";
	char sz [100]; strHtml += itoa (nDepth, sz, 10);
	strHtml += " of ";
	strHtml += item->spDlg->strRequestUrl;
	strHtml += "</h3>";
	LogTreeItem_getHtml (item, NULL, nDepth, bReversed, strHtml);
	strHtml += "</body></html>";

	tstring tstr = tszPath; tstr += "\\";
	TCHAR tsz [100]; tstr += _itot (item->spDlg->nID, tsz, 16);
	tstr += bReversed ? _T ("-tree-r.html") : _T ("-tree.html");
	HANDLE hFile = CreateFile (tstr.c_str (), GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	assert (hFile != INVALID_HANDLE_VALUE);
	DWORD dw;
	WriteFile (hFile, strHtml.c_str (), strHtml.size (), &dw, NULL);
	CloseHandle (hFile);
}

void vmsWinSockHttpDlgTree::LogTreeItem_getHtml(const TreeItem *item, const TreeItem *parentItem, int nDepth, bool bReversed, string &strHtml) const
{
	string strName = item->spDlg->strRequestUrl;
	if (strName.length () > 60)
	{
		strName.erase (strName.begin () + 60, strName.end ());
		strName += "...";
	}
	strHtml += "<a href=webfiles\\"; 
	char sz [100]; strHtml += itoa (item->spDlg->nID, sz, 16);
	strHtml += ".txt>"; strHtml += strName; strHtml += "</a>";
	strHtml += ", "; 
	switch (item->spDlg->enCT)
	{
	case vmsHttpTrafficCollector::HttpDialog::HTML: strHtml += "HTML"; break;
	case vmsHttpTrafficCollector::HttpDialog::X_WWW_FORM_URL_ENCODED: strHtml += "X_WWW_FORM_URL_ENCODED"; break;
	case vmsHttpTrafficCollector::HttpDialog::FLV: strHtml += "FLV"; break;
	case vmsHttpTrafficCollector::HttpDialog::XML: strHtml += "XML"; break;
	case vmsHttpTrafficCollector::HttpDialog::SWF: strHtml += "SWF"; break;
	case vmsHttpTrafficCollector::HttpDialog::AMF: strHtml += "AMF"; break;
	case vmsHttpTrafficCollector::HttpDialog::JSCRIPT: strHtml += "JSCRIPT"; break;
	default: strHtml += "UNKNOWN";
	}
	strHtml += ", index="; strHtml += itoa  (FindItemIndex (item), sz, 10);
	strHtml += " [<a href=\""; strHtml += item->spDlg->strRequestUrl; strHtml += "\">url</a>]<br>";
	if (parentItem)
	{
		strHtml += "parent weight = ";
		sprintf (sz, "%.*g", 3, bReversed ? parentItem->fParentWeight : item->fParentWeight);
		strHtml += sz; strHtml += "<br>";
		strHtml += "parent reason = ";
		LPCSTR pszReason = bReversed ? parentItem->getReasonOfParent (item) : item->getReasonOfParent (parentItem);
		if (!pszReason)
			pszReason = "{unknown}";
		strHtml += pszReason;
		strHtml += "<br>";
		
	}
	

	const vector <TreeItemPtr> &vItems = bReversed ? item->vParent : item->vChild; 
		
	if (nDepth > 0 && !vItems.empty ())
	{
		strHtml += "<table border=1 cellpadding=10>";
		for (size_t i = 0; i < vItems.size (); i++)
		{
			strHtml += "<tr><td>";
			LogTreeItem_getHtml (vItems [i], item, nDepth-1, bReversed, strHtml);
			strHtml += "</td></tr>";
		}
		strHtml += "</table>";
	}
}

void vmsWinSockHttpDlgTree::LogAllWebFiles () const
{
	TCHAR tszPath [MAX_PATH] = _T ("");
	GetTempPath (MAX_PATH, tszPath);
	_tcscat (tszPath, _T ("\\fdmflvsniff"));
	CreateDirectory (tszPath, NULL);
	for (size_t i = 0; i < m_vTree.size (); i++)
		LogWebFile (m_vTree [i], NULL);
}

void vmsWinSockHttpDlgTree::LogWebFile (TreeItem *item, HTTPDLG pDlg) const
{
	assert (item != NULL || pDlg != NULL);
	if (!item && !pDlg)
		return;

	if (item)
		pDlg = item->spDlg;

	TCHAR tszPath [MAX_PATH] = _T ("");
	GetTempPath (MAX_PATH, tszPath);
	_tcscat (tszPath, _T ("\\fdmflvsniff"));

	TCHAR tsz [100]; DWORD dw;

	tstring tstr = tszPath; tstr += _T ("\\webfiles\\");
	tstr += _itot (pDlg->nID, tsz, 16);
	tstr += _T (".txt"); 
	
	if (GetFileAttributes (tstr.c_str ()) != DWORD (-1))
		return;
	
	HANDLE hFile = CreateFile (tstr.c_str (), GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	assert (hFile != INVALID_HANDLE_VALUE);
	WriteFile (hFile, pDlg->strRequestUrl.c_str (), pDlg->strRequestUrl.length (), &dw, NULL);
	char sz [500]; sprintf (sz, "\r\nIndex=%d\r\nProvider: ", item ? FindItemIndex (item) : -1);
	switch (pDlg->enProvider)
	{
	case vmsHttpTrafficCollector::HttpDialog::PROV_UNKNOWN: strcat (sz, "unknown\r\n"); break;
	case vmsHttpTrafficCollector::HttpDialog::PROV_WININET: strcat (sz, "wininet\r\n"); break;
	case vmsHttpTrafficCollector::HttpDialog::PROV_WINSOCK: strcat (sz, "winsock\r\n"); break;
	case vmsHttpTrafficCollector::HttpDialog::PROV_EXTERNAL: strcat (sz, "external\r\n"); break;
	}
	if (pDlg->spDlgRedirectChainPrev)
	{
		strcat (sz, "From redirect. Parent request ID: 0x");
		itoa (pDlg->spDlgRedirectChainPrev->nID, sz + strlen (sz), 16);
		strcat (sz, ".\r\n");
		
		int nIndex = FindItemIndexByDialog (pDlg->spDlgRedirectChainPrev);
		TreeItem *itemRedirectChainPrev = nIndex != -1 ? m_vTree [nIndex] : NULL;
		LogWebFile (itemRedirectChainPrev, pDlg->spDlgRedirectChainPrev);
	}
	WriteFile (hFile, sz, strlen (sz), &dw, NULL);
	WriteFile (hFile, "\r\n\r\n", 4, &dw, NULL);
	if (item)
	{
		if (item->strBodyText.empty ())
			WriteFile (hFile, "<<NO_CONTENT>>", 14, &dw, NULL);
		else
			WriteFile (hFile, item->strBodyText.c_str (), item->strBodyText.length (), &dw, NULL);
	}
	else
	{
		if (pDlg->vbResponseBody.empty ())
			WriteFile (hFile, "<<NO_CONTENT>>", 14, &dw, NULL);
		else
			WriteFile (hFile, &pDlg->vbResponseBody [0], pDlg->vbResponseBody.size (), &dw, NULL);
	}
	WriteFile (hFile, "\r\n\r\nHeaders:\r\n", 14, &dw, NULL);
	WriteFile (hFile, pDlg->strRequestHeaders.c_str (), pDlg->strRequestHeaders.length (), &dw, NULL);
	if (!pDlg->vbRequestBody.empty ())
	{
		WriteFile (hFile, &pDlg->vbRequestBody [0], pDlg->vbRequestBody.size (), &dw, NULL);
		WriteFile (hFile, "\r\n", 2, &dw, NULL);
	}
	WriteFile (hFile, pDlg->strResponseHeaders.c_str (), pDlg->strResponseHeaders.length (), &dw, NULL);
	CloseHandle (hFile);
}

void vmsWinSockHttpDlgTree::LogAllFlvTrees () const
{
	for (size_t i = 0; i < m_vTree.size (); i++)
	{
		if (m_vTree [i]->spDlg->enCT == vmsHttpTrafficCollector::HttpDialog::FLV)
			LogTreeItem (m_vTree [i], 5, true);
	}
}

#endif

int vmsWinSockHttpDlgTree::FindItemIndex(const TreeItem *item) const
{
	for (size_t i = 0; i < m_vTree.size (); i++)
	{
		if (m_vTree [i] == item)
			return i;
	}
	
	return -1;
}

void vmsWinSockHttpDlgTree::FindChildrenOfInsertedItem(int nIndex)
{
	LOGFN ("vmsWinSockHttpDlgTree::FindChildrenOfInsertedItem");

	TreeItem *parentItem = m_vTree [nIndex];

	for (int i = nIndex + 1; i < m_vTree.size (); i++)
	{
		SPHTTPDLGTREEITEM &otherItem = m_vTree [i];

		if (otherItem->dwFlags & TI_WEBPAGE)
			continue; 

		if ((parentItem->dwFlags & TI_WEBPAGE) && !otherItem->strSrcTabUrl.empty () &&
				vmsUrlFromBrowser::isEqual (otherItem->strSrcTabUrl.c_str (), parentItem->spDlg->strRequestUrl.c_str ()))
		{
			
			#ifdef LOG_WEBFILES_TREE
				Item_addParentItem (otherItem, parentItem, 1.1f, true, "by SrcTabUrl");
			#else
				Item_addParentItem (otherItem, parentItem, 1.1f, true);
			#endif

			continue;			
		}

		if (!otherItem->strSrcTabUrl.empty ())
			continue;

		SPHTTPDLG spDlgFindParentsFor = otherItem->spDlg;
		while (spDlgFindParentsFor->spDlgRedirectChainPrev)
			spDlgFindParentsFor = spDlgFindParentsFor->spDlgRedirectChainPrev;

		

		if (!spDlgFindParentsFor->vDlgsRefererLinksTo.empty () &&
				(spDlgFindParentsFor->dwFlags & vmsHttpTrafficCollector::HttpDialog::REFERER_NONSAFE) == 0)
		{
			if (spDlgFindParentsFor->vDlgsRefererLinksTo.findIndex (parentItem->spDlg) == -1)
				continue; 

			if ((spDlgFindParentsFor->dwFlags & vmsHttpTrafficCollector::HttpDialog::REFERER_AMBIGOUS) == 0)
			{
				if (parentItem->getWebPageDetails ())
					Item_removeChildAddedByWebPageProcessingIfRequired (parentItem, otherItem->spDlg->strRequestUrl.c_str ());

				
				#ifdef LOG_WEBFILES_TREE
					Item_addParentItem (otherItem, parentItem, 1.1f, true, "by referer");
				#else
					Item_addParentItem (otherItem, parentItem, 1.1f, true);
				#endif

				continue;
			}
		}

		_inc_FindItemParents fip;
		FindItemParents_start (spDlgFindParentsFor, fip, m_vTree, nIndex, nIndex);

		_inc_FindItemParents::Step enSteps = otherItem->fParentWeight >= 1.0 ? 
			_inc_FindItemParents::EXACT_URL_MATCH : _inc_FindItemParents::ALL_STEPS;

		#ifdef LOG_WEBFILES_TREE
			string strReason;				
			float fWeight = FindItemParents_getParentWeihgt (fip, parentItem, enSteps, strReason);
		#else
			float fWeight = FindItemParents_getParentWeihgt (fip, parentItem, enSteps);
		#endif

		if (fWeight && fWeight >= otherItem->fParentWeight)
		{
			if (parentItem->getWebPageDetails ())
				Item_removeChildAddedByWebPageProcessingIfRequired (parentItem, otherItem->spDlg->strRequestUrl.c_str ());
			#ifdef LOG_WEBFILES_TREE
				Item_addParentItem (otherItem, parentItem, fWeight, true, strReason.c_str ());
			#else
				Item_addParentItem (otherItem, parentItem, fWeight, true);
			#endif
		}
	}
}

void vmsWinSockHttpDlgTree::FindDialogsInTree(const myvector <SPHTTPDLG> &vDlgs, vector <TreeItemPtr> &vTreeItems) const
{
	
	int cFound = 0;
	for (int i = m_vTree.size () - 1; i >= 0; i--)
	{
		if (vDlgs.findIndex (m_vTree [i]->spDlg) != -1)
		{
			vTreeItems.push_back (m_vTree [i]);
			if (++cFound == vDlgs.size ())
				break; 
		}
	}
}

void vmsWinSockHttpDlgTree::MakeItWebPageIfNotAlready(TreeItem *pItem)
{
	if (pItem->dwFlags & TI_WEBPAGE)
		return;
	if (!pItem->vParent.empty ())
		Item_clearParents (pItem);
}

void vmsWinSockHttpDlgTree::ProcessSwfData(TreeItem *pItem)
{
	assert (pItem != NULL);
	assert (pItem->spDlg != NULL);
	assert (pItem->spDlg->enCT == vmsHttpTrafficCollector::HttpDialog::SWF);

	if (pItem->spDlg->vbResponseBody.empty ())
		return;

	LPBYTE pbSwfData = &pItem->spDlg->vbResponseBody [0];

	vmsSwfFile *pSwfFile = new vmsSwfFile;

	if (pSwfFile->isCompressed (pbSwfData, pItem->spDlg->vbResponseBody.size ()))
	{
		LPBYTE pb = NULL; UINT uSize = 0;
		BOOL bOK = pSwfFile->Decompress (pbSwfData, pItem->spDlg->vbResponseBody.size (), &pb, &uSize);
		if (bOK && pb != NULL && uSize != 0)
		{
			if (!pSwfFile->Parse (pb, uSize))
			{
				delete pSwfFile; 
				pSwfFile = NULL;
			}
			
			delete [] pb;
			if (pSwfFile)
			{
				pItem->pvCustomData = pSwfFile;
				pSwfFile = NULL;
			}
		}
	}

	if (pSwfFile)
		delete pSwfFile;

	
	pItem->spDlg->vbResponseBody.clear ();
}

void vmsWinSockHttpDlgTree::ExtractStringsFromByteArray(const BYTE *pb, UINT uSize, string &strResult)
{
	strResult = "";

	assert (pb != NULL);
	if (!pb || !uSize)
		return;

	bool bNeedSpace = false;

	for (UINT i = 0; i < uSize; i++)
	{
		if ((*pb > 31 && *pb < 127))
		{
			if (bNeedSpace)
			{
				strResult += ' ';
				bNeedSpace = false;
			}
			strResult += *pb;
		}
		else
		{
#ifdef _DEBUG
			if (*pb == '\t' || *pb == '\r' || *pb == '\n')
			{
				strResult += *pb;
				bNeedSpace = false;
			}
			else
			{
				bNeedSpace = true;
			}
#else
			bNeedSpace = true;
#endif
		}
		pb++;
	}
}

void vmsWinSockHttpDlgTree::DoWebPageAdditionalProcessing(TreeItem *item)
{
	assert (item != NULL);
	if (!item)
		return;
	assert (item->dwFlags & TI_WEBPAGE);
	if ((item->dwFlags & TI_WEBPAGE) == 0)
		return;
	WebPageDetails *pwpd = new WebPageDetails;

	LPCSTR psz = item->strBodyText.c_str ();
	
	while (psz && *psz)
	{
		psz = strchr (psz, '<');
		if (!psz)
			break;
		
		vmsHtmlTagParser tag;
		int nTagHeadLen = tag.Parse (psz);

		assert (psz + nTagHeadLen - item->strBodyText.c_str () <= item->strBodyText.length ());
				
		psz += nTagHeadLen;
		if (!nTagHeadLen)
			psz++;
				
		if (!stricmp (tag.getName (), "script") || 
			!stricmp (tag.getName (), "frame") || 
			!stricmp (tag.getName (), "iframe"))
		{
			const vmsHtmlTagParser::TagAttribute *pSrc = tag.findAttribute ("src");
			if (pSrc)
			{
				string strUrl;
				vmsHtmlParser::DecodeHtmlSpecEntites (pSrc->strValue.c_str (), strUrl);
				if (!vmsUrl::isAbsolute (strUrl.c_str ()))
				{
					string strAbsUrl;
					vmsUrl::GetAbsoluteUrlFromRelative2 (item->spDlg->strRequestUrl.c_str (), strUrl.c_str (), strAbsUrl);
					strUrl = strAbsUrl;
				}
				if (!strUrl.empty ())
				{
					pwpd->vUrlsOfNotFoundChildren.push_back (strUrl);
					if (!stricmp (tag.getName (), "frame") || !stricmp (tag.getName (), "iframe"))
						pwpd->vFrameUrls.push_back (strUrl);
				}
			}
		}
	}

	RemoveDupesInStringList (pwpd->vUrlsOfNotFoundChildren);

	item->pvCustomData = pwpd;

	FindWebPageChildren (item);
}

void vmsWinSockHttpDlgTree::FindWebPageChildren(TreeItem *item)
{
	assert (item != NULL && (item->dwFlags & TI_WEBPAGE) != 0);
	if (!item)
		return;
	if (!(item->dwFlags & TI_WEBPAGE))
		return;

	WebPageDetails *pwpd = (WebPageDetails*) item->getWebPageDetails ();
	if (!pwpd)
		return;

	LOCKTREE;

	for (int j = m_vTree.size () - 1; j >= 0 && !pwpd->vUrlsOfNotFoundChildren.empty (); j--)
	{
		TreeItem *item2 = m_vTree [j];
		int nIndex = pwpd->vUrlsOfNotFoundChildren.findIndex (item2->spDlg->strRequestUrl);
		if (nIndex != -1)
		{
			#ifdef LOG_WEBFILES_TREE
				Item_addParentItem (item2, item, 1.1f, true, "by html parsing");
			#else
				Item_addParentItem (item2, item, 1.1f, true);
			#endif
			pwpd->vUrlsOfFoundChildren.push_back (item2->spDlg->strRequestUrl);
			pwpd->vUrlsOfNotFoundChildren.erase (pwpd->vUrlsOfNotFoundChildren.begin () + nIndex);
		}
	}
}

void vmsWinSockHttpDlgTree::RemoveDupesInStringList(vector <string> &v)
{
	if (v.empty ())
		return;

	for (int i = 0; i < (int)v.size (); i++)
	{
		for (int j = i + 1; j < (int)v.size (); j++)
		{
			if (v [i] == v [j])
				v.erase (v.begin () + j--);
		}
	}
}

void vmsWinSockHttpDlgTree::Item_removeChild(TreeItem *pParent, int nChildIndex, bool bRemoveParentFromChildAlso)
{
	assert (nChildIndex >= 0 && nChildIndex < (int)pParent->vChild.size ());
	if (nChildIndex < 0 || nChildIndex >= (int)pParent->vChild.size ())
		return;
	TreeItemPtr spChild = pParent->vChild [nChildIndex];
	pParent->vChild.erase (pParent->vChild.begin () + nChildIndex);	
	if (bRemoveParentFromChildAlso)
	{
		int nIndex = spChild->vParent.findIndex (pParent);
		if (nIndex != -1)
			Item_removeParent (spChild, nIndex, false);
	}
}

void vmsWinSockHttpDlgTree::Item_removeParent(TreeItem *pChild, int nParentIndex, bool bRemoveChildFromParentAlso)
{
	assert (nParentIndex >= 0 && nParentIndex < (int)pChild->vParent.size ());
	if (nParentIndex < 0 || nParentIndex >= (int)pChild->vParent.size ())
		return;
	TreeItemPtr spParent = pChild->vParent [nParentIndex];
	pChild->vParent.erase (pChild->vParent.begin () + nParentIndex);
	
	#ifdef LOG_WEBFILES_TREE
	for (size_t i = 0; i < pChild->vParentsInfo.size (); i++)
	{
		if (pChild->vParentsInfo [i].spParentItem == spParent)
		{
			pChild->vParentsInfo.erase (pChild->vParentsInfo.begin () + i);
			break;
		}
	}
	#endif	

	if (bRemoveChildFromParentAlso)
	{
		int nIndex = spParent->vChild.findIndex (pChild);
		if (nIndex != -1)
			Item_removeChild (spParent, nIndex, false);
	}
}

int vmsWinSockHttpDlgTree::Item_findDupeChildIndex(const TreeItem *pParent, const TreeItem *pChild)
{
	assert (pParent != NULL && pChild != NULL);
	if (!pParent || !pChild)
		return -1;
	for (int i = 0; i < pParent->vChild.size (); i++)
	{
		const TreeItem *child = pParent->vChild [i];
		if (child->spDlg->vbResponseBody.size () == pChild->spDlg->vbResponseBody.size () &&
				child->spDlg->strRequestUrl == pChild->spDlg->strRequestUrl &&
				child->spDlg->vbRequestBody.size () == pChild->spDlg->vbRequestBody.size ())
		{
			if (!child->spDlg->vbRequestBody.empty () && 
					memcmp (&child->spDlg->vbRequestBody [0], &pChild->spDlg->vbRequestBody [0], child->spDlg->vbRequestBody.size ()))
				continue; 
			return i; 
		}
	}
	return -1;
}

void vmsWinSockHttpDlgTree::Item_removeChildAddedByWebPageProcessingIfRequired(TreeItem *pWebPage, LPCSTR pszChildUrl)
{
	assert (pWebPage != NULL && pszChildUrl != NULL);
	if (!pWebPage || !pszChildUrl)
		return;
	WebPageDetails *pwpd = (WebPageDetails*)pWebPage->getWebPageDetails ();
	assert (pwpd != NULL);
	if (!pwpd)
		return;
	int nIndex = pwpd->vUrlsOfFoundChildren.findIndex (pszChildUrl);
	if (nIndex == -1)
		return;
	pwpd->vUrlsOfFoundChildren.erase (pwpd->vUrlsOfFoundChildren.begin () + nIndex);
	nIndex = Item_findChildIndexByUrl (pWebPage, pszChildUrl);
	if (nIndex != -1)
		Item_removeChild (pWebPage, nIndex, true);
}

int vmsWinSockHttpDlgTree::Item_findChildIndexByUrl(const TreeItem *pItem, LPCSTR pszUrl)
{
	assert (pItem != NULL && pszUrl != NULL);
	if (!pItem || !pszUrl)
		return -1;
	for (int i = 0; i < (int)pItem->vChild.size (); i++)
	{
		if (pItem->vChild [i]->spDlg->strRequestUrl == pszUrl)
			return i;
	}
	return -1;
}

int vmsWinSockHttpDlgTree::getFlvsInSessionCount() const
{
	return m_cFlvsInSession;
}
