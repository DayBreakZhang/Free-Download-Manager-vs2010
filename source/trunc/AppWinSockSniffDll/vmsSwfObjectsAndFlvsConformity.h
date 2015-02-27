/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSSWFOBJECTSANDFLVSCONFORMITY_H__FB1E9660_1E10_4200_8569_6B2A464C53FF__INCLUDED_)
#define AFX_VMSSWFOBJECTSANDFLVSCONFORMITY_H__FB1E9660_1E10_4200_8569_6B2A464C53FF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class vmsSwfObjectsAndFlvsConformity  
{
public:
	struct SwfObject
	{
		HTTPDLGTREEITEM pItem; 
		string strSwfUrl;
		string strFlashVars;
		SwfObject () {pItem = NULL;}
	protected:
		friend class vmsSwfObjectsAndFlvsConformity;
		myvector <string> vUrlWords;
		myvector <string> vDecodedUrlWords;
	};
	struct Flv
	{
		HTTPDLGTREEITEM pItem; 
		HTTPDLGTREEITEMLIST vPathFromWebPageToFlv; 
		string strUrl;
		Flv () {pItem = NULL;}
	protected:
		friend class vmsSwfObjectsAndFlvsConformity;
		myvector <string> vReferers;
	};
	struct Conformity
	{
		SwfObject *pSwf;
		Flv *pFlv;
	};
public:
	const Conformity* getConformity (int nIndex) const;
	int getConformitiesCount () const;
	void FindComformity();
	void addFlv (LPCSTR pszUrl, HTTPDLGTREEITEM pItem = NULL, HTTPDLGTREEITEMLIST *pTreePathFromWebPageToFlv = NULL);
	void addSwfObject (LPCSTR pszSwfUrl, LPCSTR pszFlashVars, HTTPDLGTREEITEM pItem = NULL);
	vmsSwfObjectsAndFlvsConformity(const vmsHttpTrafficCollector *pTraffic, const vmsWinSockHttpDlgTree *pTree);
	virtual ~vmsSwfObjectsAndFlvsConformity();

protected:
	void CalculateWeights_byFlvReferer(const Flv &flv, vector <float> &vWeights);
	void CalculateWeights_bySwfDetails(const Flv &flv, vector <float> &vWeights);
	static void CalculateWeights_byUrlWordsPresense_findWords(const myvector <string> &vWordsWhere, const vector <string> &vWordsWhat, vector <bool> &vbResult);
	static void ExtractUrlWords (HTTPDLG pDlg, vector <string> &vUrlWords);
	void CalculateWeights_byUrlWordsPresense (const Flv& flv, vector <float> &vWeights);
	void RemoveDupesFromUrlWords();
	void FindComformity_byUrlInFlashVars (vector <Flv*> &vFlvs);
	vector <SwfObject> m_vSwfs;
	vector <Flv> m_vFlvs;
	vector <Conformity> m_vConfs;
	const vmsWinSockHttpDlgTree *m_pTree;
	const vmsHttpTrafficCollector *m_pTraffic;
};

#endif 
