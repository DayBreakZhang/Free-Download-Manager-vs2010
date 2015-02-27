/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSWINSOCKHTTPDLGTREE_H__B0F43D06_A18D_40C8_8DE3_3127E0043FF2__INCLUDED_)
#define AFX_VMSWINSOCKHTTPDLGTREE_H__B0F43D06_A18D_40C8_8DE3_3127E0043FF2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "vmsHttpTrafficCollector.h"
#include "vmsSwfFile.h"

class vmsWinSockHttpDlgTree  
{
public:
	struct WebPageDetails
	{
		myvector <string> vFrameUrls;
	protected:
		friend class vmsWinSockHttpDlgTree;
		
		
		myvector <string> vUrlsOfNotFoundChildren;
		myvector <string> vUrlsOfFoundChildren;
	};
public:
	enum 
	{
		
		TI_WEBPAGE	= 1,
	};
	struct TreeItem;
	typedef vmsObjectSmartPtr <TreeItem> TreeItemPtr;
	struct TreeItem : public vmsObject
	{
		SPHTTPDLG spDlg;
		DWORD dwFlags;  
		myvector <TreeItemPtr> vParent;
		myvector <TreeItemPtr> vChild;
		bool isWebPage () const {return (dwFlags & TI_WEBPAGE) != 0;}
		const vmsSwfFile* getSwfFile () const 
		{
			assert (spDlg->enCT == vmsHttpTrafficCollector::HttpDialog::SWF);
			if (spDlg->enCT != vmsHttpTrafficCollector::HttpDialog::SWF)
				return NULL;
			return (const vmsSwfFile*)pvCustomData;
		}
		const WebPageDetails* getWebPageDetails () const 
		{
			if ((dwFlags & TI_WEBPAGE) == 0)
				return NULL;
			return (const WebPageDetails*)pvCustomData;

		}
		TreeItem () 
		{
			dwFlags = 0; 
			fParentWeight = 0; 
			pvCustomData = NULL;
		}
		~TreeItem () 
		{
			if (pvCustomData)
			{
				if (spDlg->enCT == vmsHttpTrafficCollector::HttpDialog::SWF)
					delete (vmsSwfFile*)pvCustomData;
				else if (dwFlags & TI_WEBPAGE)
					delete (WebPageDetails*)pvCustomData;
			}
		}
	protected:
		friend class vmsWinSockHttpDlgTree;
		string strBodyText; 
		string strUrlParams; 
		string strDecodedUrlParams; 
		float fParentWeight; 
		LPVOID pvCustomData; 
		string strSrcTabUrl; 
		
		
		vector <bool> vUrlWordPresent;
		float fFoundWordsWeight;
		void clearFindItemParentData () {vUrlWordPresent.clear (); fFoundWordsWeight = 0;}
		
		#ifdef LOG_WEBFILES_TREE
		struct ParentInfo {
			TreeItemPtr spParentItem;
			string strReason;
		};
		vector <ParentInfo> vParentsInfo;
		LPCSTR getReasonOfParent (const TreeItem *pItem) const {
			for (size_t i = 0; i < vParentsInfo.size (); i++)
			{
				if (vParentsInfo [i].spParentItem == pItem)
					return vParentsInfo [i].strReason.c_str ();
			}
			return NULL;
		}
		#endif
	};
protected:
	struct _inc_FindItemParents
	{
		enum Step {
			STEP_START					= 0,
			EXACT_URL_MATCH				= 0,
			BY_URL_WORDS				= 1,
			STEP_END					= 1,
			ALL_STEPS					= -1,
		};
		HTTPDLG pDlg;
		LPCSTR pszUrl;
		LPCSTR pszUrlPath;
		LPCSTR pszShortenUrlStart; 
		int nUrlLen;
		int nUrlStart_Path_delta;
		vector <string> vUrlWords; 
		vector <int> vUrlWordWeights;
		int iUrlWordsTotalWeight;
		bool bFindUrlWordsStepPerformed;
		bool bCanBeFoundByRelativePath; 
		
		
		
		
		
		vector <TreeItemPtr> *pvTree;
		size_t nFindIndexStart, nFindIndexEnd;
	};
public:
	int getFlvsInSessionCount () const;
	void MakeItWebPageIfNotAlready (TreeItem *pItem);
	int FindItemIndex (const TreeItem *item) const;
#ifdef LOG_WEBFILES_TREE
	void LogTreeItem (const TreeItem* item, int nDepth, bool bReversed = false) const;
	void LogTreeItem_getHtml (const TreeItem* item, const TreeItem *parentItem, int nDepth, bool bReversed, string &strHtml) const;
	void LogAllWebFiles () const;
	void LogWebFile (TreeItem *item, HTTPDLG pDlg) const;
	
	
	void LogWebFile (TreeItem *item, HTTPDLG pDlg);
	void LogAllFlvTrees () const;
#endif
	void InsertDialog_Async (SPHTTPDLG spDlg);
	void LockRemoveOldDialogs (bool bLock);
	bool HasItemFlvChild (const TreeItem *item, int iMaxDepth);
	void RemoveAllDialogsOlderWhen (UINT nSeconds, UINT nSecondsForWebPagesAndFlvs);
	void GetChildItemsWithPath_EraseDupes (vector <vector <const TreeItem*> > &vChildren) const;
	int FindItemIndexByDialog (HTTPDLG pDlg) const;
	void MoveDialogToTop (HTTPDLG pDlg);
	void GetChildItems (const TreeItem* item, vector <const TreeItem*> &vChildren, vmsHttpTrafficCollector::HttpDialog::ResourceContentType enCT, int nDepth) const;
	void GetChildItemsWithPath (const TreeItem* item, vector <vector <const TreeItem*> > &vChildren, vmsHttpTrafficCollector::HttpDialog::ResourceContentType enCT, int nDepth) const;
	const TreeItem* FindTreeItem (LPCSTR pszUrl, vmsHttpTrafficCollector::HttpDialog::ResourceContentType enRT, BOOL bExactMatchOnly = false, int *pnStartIndex = NULL) const;
	void InsertDialog (SPHTTPDLG spDlg);
	static vmsWinSockHttpDlgTree& o();
	vmsWinSockHttpDlgTree();
	virtual ~vmsWinSockHttpDlgTree();

	bool UrlExistsInProcessHttpDialogsQueue (LPCSTR pszUrl);

protected:
	LONG m_cFlvsInSession;
	static int Item_findChildIndexByUrl (const TreeItem *pItem, LPCSTR pszUrl);
	static void Item_removeChildAddedByWebPageProcessingIfRequired (TreeItem *pWebPage, LPCSTR pszChildUrl);
	static int Item_findDupeChildIndex (const TreeItem *pParent, const TreeItem *pChild);
	static void Item_removeChild (TreeItem *pParent, int nChildIndex, bool bRemoveParentFromChildAlso);
	static void Item_removeParent(TreeItem *pChild, int nParentIndex, bool bRemoveChildFromParentAlso);
	
	
	static void RemoveDupesInStringList (vector <string> &v);
	void FindWebPageChildren (TreeItem *item);
	void DoWebPageAdditionalProcessing (TreeItem *item);
	static void ExtractStringsFromByteArray (const BYTE *pb, UINT uSize, string &strResult);
	static void ProcessSwfData (TreeItem *pItem);
	void FindDialogsInTree (const myvector <SPHTTPDLG> &vDlgs, vector <TreeItemPtr> &vTreeItems) const;
	void FindChildrenOfInsertedItem (int nIndex);
	static void FindItemParents_getParentWeihgt_findUrlWordsInAllTreeItems_forItem (_inc_FindItemParents &fip, TreeItem *item);
	static void FindItemParents_getParentWeihgt_findUrlWordsInTreeItems(_inc_FindItemParents &fip);
	void FindItemParents (TreeItem *item);
	static void ExtractBodyText_html_decodeScriptStrings (LPCSTR pszScript, string &strResult);
	static void ExtractBodyText_html (HTTPDLG pDlg, string &strResult);
	static void FindItemParents_start (HTTPDLG pDlg, _inc_FindItemParents &fip, vector <TreeItemPtr> &vTree, int nFindIndexStart = 0, int nFindIndexEnd = -1);
#ifdef LOG_WEBFILES_TREE
	static float FindItemParents_getParentWeihgt (_inc_FindItemParents &fip, const TreeItem* pDlgParent, const _inc_FindItemParents::Step enStep, string &strReason);
#else
	static float FindItemParents_getParentWeihgt (_inc_FindItemParents &fip, const TreeItem* pDlgParent, const _inc_FindItemParents::Step enStep = _inc_FindItemParents::ALL_STEPS);
#endif

	bool m_bObjClosing;
	static DWORD WINAPI _threadAddDialogs (LPVOID lp);
	HANDLE m_htAddDialogs;
	void Item_clearParents (TreeItem *item, bool bRemoveChildFromParents = true);
#ifdef LOG_WEBFILES_TREE
	void Item_addParentItem (TreeItem *item, TreeItem *pParent, float fParentWeight, bool bAddChildToParent, LPCSTR pszReason);
#else
	void Item_addParentItem (TreeItem *item, TreeItem *pParent, float fParentWeight, bool bAddChildToParent);
#endif
	vmsCriticalSection m_csModifyTree, m_csRemoveOldDialogs, m_csModifyAddDialogsList;
	static void GetChildItems_imp (const TreeItem* item, vector <const TreeItem*> &vChildren, vmsHttpTrafficCollector::HttpDialog::ResourceContentType enCT, int nDepth);
	static void GetChildItemsWithPath_imp (const TreeItem* item, vector <vector <const TreeItem*> > &vChildren, vmsHttpTrafficCollector::HttpDialog::ResourceContentType enCT, int nDepth, vector <const TreeItem*> vPath);
	static void ExtractUrlParameters (HTTPDLG pDlg, string &strResult);
	static void ExtractBodyText (TreeItem *pItem);
	static bool IsHtmlWebPage (LPCSTR pszHtml);
	void FindDialogParents (SPHTTPDLG spDlg, int iParentsStartIndex, int iParentsEndIndex, vector <TreeItemPtr> &vParents, float &fParentsWeight);
	vector <TreeItemPtr> m_vTree;
	vector <SPHTTPDLG> m_vAddDialogsList;

};

typedef const vmsWinSockHttpDlgTree::TreeItem* HTTPDLGTREEITEM;
typedef vmsWinSockHttpDlgTree::TreeItemPtr SPHTTPDLGTREEITEM;
typedef vector <HTTPDLGTREEITEM> HTTPDLGTREEITEMLIST;
typedef vector <SPHTTPDLGTREEITEM> SPHTTPDLGTREEITEMLIST;

#endif 
