/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsSwfObjectsAndFlvsConformity.h"
#include "vmsHttpHelper.h"
#include "vmsUrlWords.h"

vmsSwfObjectsAndFlvsConformity::vmsSwfObjectsAndFlvsConformity(const vmsHttpTrafficCollector *pTraffic, const vmsWinSockHttpDlgTree *pTree)
{
	m_pTraffic = pTraffic;
	m_pTree = pTree;
}

vmsSwfObjectsAndFlvsConformity::~vmsSwfObjectsAndFlvsConformity()
{

}

void vmsSwfObjectsAndFlvsConformity::addSwfObject(LPCSTR pszSwfUrl, LPCSTR pszFlashVars, HTTPDLGTREEITEM pItem)
{
	SwfObject swf;
	swf.pItem = pItem;
	swf.strSwfUrl = pszSwfUrl;
	if (pszFlashVars)
		swf.strFlashVars = pszFlashVars;
	if (!swf.pItem)
		swf.pItem = m_pTree->FindTreeItem (pszSwfUrl, vmsHttpTrafficCollector::HttpDialog::SWF);
	if (!swf.pItem && m_pTraffic)
	{
		HTTPDLG pDlg = m_pTraffic->FindDialogByRequestUrl (pszSwfUrl);
		if (pDlg && pDlg->spDlgRedirectChainNext)
		{
			while (pDlg->spDlgRedirectChainNext)
				pDlg = pDlg->spDlgRedirectChainNext;
			swf.pItem = m_pTree->FindTreeItem (pDlg->strRequestUrl.c_str (), vmsHttpTrafficCollector::HttpDialog::SWF);
		}
	}
	if (swf.pItem && swf.strSwfUrl.empty ())
		swf.strSwfUrl = swf.pItem->spDlg->strRequestUrl;
	if (pszFlashVars)
		vmsHttpHelper::ExtractUrlEncodedValues (pszFlashVars, NULL, &swf.vUrlWords);
	vector <string> v; string strTmp0, strTmp1; vector <string> vTmp;
	vmsUrlWords::ExtractWords (swf.strSwfUrl.c_str (), strTmp0, vTmp, strTmp1, v);
	for (size_t i = 0; i < v.size (); i++)
		swf.vUrlWords.push_back (v [i]);
	for (size_t i = 0; i < swf.vUrlWords.size (); i++)
	{
		string str;
		vmsHttpHelper::DecodeUrl (swf.vUrlWords [i].c_str (), str);
		swf.vDecodedUrlWords.push_back (str);
	}
	m_vSwfs.push_back (swf);
}

void vmsSwfObjectsAndFlvsConformity::addFlv(LPCSTR pszUrl, HTTPDLGTREEITEM pItem, HTTPDLGTREEITEMLIST *pTreePathFromWebPageToFlv)
{
	Flv flv;
	if (pszUrl)
		flv.strUrl = pszUrl;
	flv.pItem = pItem;
	if (pTreePathFromWebPageToFlv)
		flv.vPathFromWebPageToFlv = *pTreePathFromWebPageToFlv;
	if (!flv.pItem && !flv.vPathFromWebPageToFlv.empty ())
		flv.pItem = flv.vPathFromWebPageToFlv [flv.vPathFromWebPageToFlv.size () - 1];
	if (flv.pItem && flv.strUrl.empty ())
		flv.strUrl = flv.pItem->spDlg->strRequestUrl;
	if (flv.pItem)
	{
		HTTPDLGTREEITEM pItem = flv.pItem;
		while (pItem && pItem->spDlg->pHttpRequest)
		{
			HTTPDLG pDlgRedir = pItem->spDlg->spDlgRedirectChainPrev;
			while (pDlgRedir)
			{
				flv.vReferers.push_back (pDlgRedir->strRequestUrl);
				pDlgRedir = pDlgRedir->spDlgRedirectChainPrev;
			}
			const vmsHttpRequestParser::HdrField* pReferer = pItem->spDlg->pHttpRequest->FieldByName ("Referer");
			if (!pReferer)
				break;
			flv.vReferers.push_back (pReferer->strValue);
			if (!m_pTree)
				break;
			if (pReferer->strValue == pItem->spDlg->strRequestUrl)
				break; 
			pItem = m_pTree->FindTreeItem (pReferer->strValue.c_str (), vmsHttpTrafficCollector::HttpDialog::ALL);
			if (pItem && pItem->isWebPage ())
				pItem = NULL;
		}
	}
	m_vFlvs.push_back (flv);
}

void vmsSwfObjectsAndFlvsConformity::FindComformity()
{
	m_vConfs.clear ();

	vector <Flv*> vFlvs;
	for (size_t i = 0; i < m_vFlvs.size (); i++)
		vFlvs.push_back (&m_vFlvs [i]);

	FindComformity_byUrlInFlashVars (vFlvs);

	RemoveDupesFromUrlWords ();

	for (size_t nFlv = 0; nFlv < vFlvs.size (); nFlv++)
	{
		Flv &flv = *vFlvs [nFlv];

		vector <float> vWeights;
		vWeights.assign (m_vSwfs.size (), 0.0f);
		
		CalculateWeights_byUrlWordsPresense (flv, vWeights);
		CalculateWeights_bySwfDetails (flv, vWeights);
		
		CalculateWeights_byFlvReferer (flv, vWeights);

		
		
		bool bAllWeights0 = true;
		for (size_t i = 0; i < vWeights.size (); i++)
		{
			if (vWeights [i])
				bAllWeights0 = false;
		}
		if (bAllWeights0)
			vWeights.assign (m_vSwfs.size (), 1.0f);
		

		vector <SwfObject*> vSwfs;
		float fWeightMax = 0;

		for (size_t i = 0; i < vWeights.size (); i++)
		{
			float fWeight = vWeights [i];

			if (fWeight && fWeight >= fWeightMax)
			{
				if (fWeight > fWeightMax)
				{
					vSwfs.clear ();
					fWeightMax = fWeight;
				}
				vSwfs.push_back (&m_vSwfs [i]);
			}
		}

		Conformity conf;
		conf.pFlv = vFlvs [nFlv];

		for (size_t i = 0; i < vSwfs.size (); i++)
		{
			conf.pSwf = vSwfs [i];
			m_vConfs.push_back (conf);
		}
	}
}

void vmsSwfObjectsAndFlvsConformity::FindComformity_byUrlInFlashVars(vector <Flv*> &vFlvs)
{
	for (int i = 0; i < (int)vFlvs.size (); i++)
	{
		Flv *pFlv = vFlvs [i];

		bool bFound = false;
		int cK = pFlv->vPathFromWebPageToFlv.empty () ? 0 : pFlv->vPathFromWebPageToFlv.size () - 1;

		vector <bool> vbFoundForSwf;
		vbFoundForSwf.assign (m_vSwfs.size (), false);

		for (int k = cK; k >= 0 && !bFound; k--)
		{
			const string *pstrUrl;
			string strUrl2;

			if (k == (int)pFlv->vPathFromWebPageToFlv.size ())
				pstrUrl = &pFlv->strUrl;
			else
				pstrUrl = &pFlv->vPathFromWebPageToFlv [k]->spDlg->strRequestUrl;

			assert (!pstrUrl->empty ());
			if (pstrUrl->empty ())
				continue;
			if (pstrUrl->at (pstrUrl->length () - 1) == '#')
				strUrl2.assign (pstrUrl->c_str (), pstrUrl->length () - 1);
			else
				strUrl2 = *pstrUrl + '#';

			for (size_t j = 0; j < m_vSwfs.size (); j++)
			{
				if (vbFoundForSwf [j])
					continue;
				if (m_vSwfs [j].vDecodedUrlWords.findIndex (*pstrUrl) != -1 || 
						m_vSwfs [j].vDecodedUrlWords.findIndex (strUrl2) != -1)
				{
					vbFoundForSwf [j] = true;
					bFound = true;
				}
			}
		}

		assert (vbFoundForSwf.size () == m_vSwfs.size ());

		if (bFound)
		{
			Conformity conf;
			conf.pFlv = pFlv;

			for (size_t j = 0; j < m_vSwfs.size (); j++)
			{
				if (vbFoundForSwf [j])
				{
					conf.pSwf = &m_vSwfs [j];
					m_vConfs.push_back (conf);
				}
			}

			vFlvs.erase (vFlvs.begin () + i--);
		}			
	}
}

void vmsSwfObjectsAndFlvsConformity::RemoveDupesFromUrlWords()
{
	for (size_t nSwf = 0; nSwf < m_vSwfs.size (); nSwf++)
	{
		SwfObject &swf = m_vSwfs [nSwf];

		for (int nWord = 0; nWord < (int)swf.vUrlWords.size (); nWord++)
		{
			string &strWord = swf.vUrlWords [nWord];
			bool bNonUnique = false;

			for (size_t i = nSwf + 1; i < m_vSwfs.size (); i++)
			{
				SwfObject &swf2 = m_vSwfs [i];

				for (int j = 0; j < (int)swf2.vUrlWords.size (); j++)
				{
					if (strWord == swf2.vUrlWords [j])
					{
						bNonUnique = true;
						swf2.vUrlWords.erase (swf2.vUrlWords.begin () + j);
						swf2.vDecodedUrlWords.erase (swf2.vDecodedUrlWords.begin () + j);
						j--;
					}
				}
			}

			if (bNonUnique)
			{
				swf.vUrlWords.erase (swf.vUrlWords.begin () + nWord);
				swf.vDecodedUrlWords.erase (swf.vDecodedUrlWords.begin () + nWord);
				nWord--;
			}
		}
	}
}

void vmsSwfObjectsAndFlvsConformity::CalculateWeights_byUrlWordsPresense(const Flv &flv, vector <float> &vWeights)
{
	assert (vWeights.size () == m_vSwfs.size ());
	if (vWeights.size () != m_vSwfs.size ())
		return;

	for (size_t nSwf = 0; nSwf < m_vSwfs.size (); nSwf++)
	{
		SwfObject &swf = m_vSwfs [nSwf];

		vector <bool> vbUrlWordFound; 
		vbUrlWordFound.assign (swf.vUrlWords.size (), false);

		if (!flv.vPathFromWebPageToFlv.empty ())
		{
			for (size_t i = 0; i < flv.vPathFromWebPageToFlv.size (); i++)
			{
				vector <string> vUrlWords;
				ExtractUrlWords (flv.vPathFromWebPageToFlv [i]->spDlg, vUrlWords);
				CalculateWeights_byUrlWordsPresense_findWords (swf.vUrlWords, vUrlWords, vbUrlWordFound);
			}
		}
		else if (flv.pItem)
		{
			vector <string> vUrlWords;
			ExtractUrlWords (flv.pItem->spDlg, vUrlWords);
			CalculateWeights_byUrlWordsPresense_findWords (swf.vUrlWords, vUrlWords, vbUrlWordFound);
		}
		else
		{
			assert (!flv.strUrl.empty ());
			vector <string> vUrlWords;
			string strTmp0, strTmp1; vector <string> vTmp;
			vmsUrlWords::ExtractWords (flv.strUrl.c_str (), strTmp0, vTmp, strTmp1, vUrlWords);
			CalculateWeights_byUrlWordsPresense_findWords (swf.vUrlWords, vUrlWords, vbUrlWordFound);
		}

		for (size_t i = 0; i < vbUrlWordFound.size (); i++)
		{
			if (vbUrlWordFound [i])
				vWeights [nSwf] += vmsUrlWords::GetUrlWordWeight (swf.vUrlWords [i].c_str ());
		}
	}
}

void vmsSwfObjectsAndFlvsConformity::ExtractUrlWords(HTTPDLG pDlg, vector <string> &vUrlWords)
{
	assert (pDlg != NULL);
	if (!pDlg)
		return;
	vUrlWords.clear ();
	string strTmp0, strTmp1; vector <string> vTmp;
	vmsUrlWords::ExtractWords (pDlg->strRequestUrl.c_str (), strTmp0, vTmp, strTmp1, vUrlWords);
	string strPostData; vmsHttpTrafficCollector::ExtractUrlValuesFromPostData (pDlg, strPostData);
	if (!strPostData.empty ())
	{
		vector <string> vUrlWords2;
		vmsHttpHelper::ExtractUrlEncodedValues (strPostData.c_str (), NULL, &vUrlWords2);
		for (size_t j = 0; j < vUrlWords2.size (); j++)
			vUrlWords.push_back (vUrlWords2 [j]);
	}
}

void vmsSwfObjectsAndFlvsConformity::CalculateWeights_byUrlWordsPresense_findWords(const myvector <string> &vWordsWhere, const vector <string> &vWordsWhat, vector <bool> &vbResult)
{
	assert (vWordsWhere.size () == vbResult.size ());
	if (vWordsWhere.size () != vbResult.size ())
		return;

	for (size_t i = 0; i < vWordsWhat.size (); i++)
	{
		int nIndex = vWordsWhere.findIndex (vWordsWhat [i]);
		if (nIndex != -1)
			vbResult [nIndex] = true;
	}
}

int vmsSwfObjectsAndFlvsConformity::getConformitiesCount() const
{
	return m_vConfs.size ();
}

const vmsSwfObjectsAndFlvsConformity::Conformity* vmsSwfObjectsAndFlvsConformity::getConformity(int nIndex) const
{
	assert (nIndex >= 0 && nIndex < m_vConfs.size ());
	return &m_vConfs [nIndex];
}

void vmsSwfObjectsAndFlvsConformity::CalculateWeights_bySwfDetails(const Flv &flv, vector <float> &vWeights)
{
	assert (vWeights.size () == m_vSwfs.size ());
	if (vWeights.size () != m_vSwfs.size ())
		return;

	for (size_t nSwf = 0; nSwf < m_vSwfs.size (); nSwf++)
	{
		SwfObject &swf = m_vSwfs [nSwf];

		if (!swf.pItem)
			continue;

		const vmsSwfFile *pSwfFile = swf.pItem->getSwfFile ();
		if (!pSwfFile)
			continue;

		if (pSwfFile->getHeader ()->m_uFrameCount == 1)
			vWeights [nSwf] += 10;

		if (pSwfFile->getHeader ()->m_sFrameSize.cx > 300 && pSwfFile->getHeader ()->m_sFrameSize.cy > 200)
			vWeights [nSwf] += 10;
	}
}

void vmsSwfObjectsAndFlvsConformity::CalculateWeights_byFlvReferer(const Flv &flv, vector <float> &vWeights)
{
	assert (vWeights.size () == m_vSwfs.size ());
	if (vWeights.size () != m_vSwfs.size ())
		return;

	if (flv.vReferers.empty ())
		return;

	myvector <bool> vRefererFound;
	vRefererFound.assign (m_vSwfs.size (), false);

	for (size_t nSwf = 0; nSwf < m_vSwfs.size (); nSwf++)
		vRefererFound [nSwf] = -1 != flv.vReferers.findIndex (m_vSwfs [nSwf].pItem ? m_vSwfs [nSwf].pItem->spDlg->strRequestUrl.c_str () : m_vSwfs [nSwf].strSwfUrl.c_str ());

	bool bFound = vRefererFound.findIndex (true) != -1;

	if (!bFound)
		return;
	
	for (size_t nSwf = 0; nSwf < m_vSwfs.size (); nSwf++)
	{
		if (vRefererFound [nSwf])
			vWeights [nSwf] += 100;
		else
			vWeights [nSwf] = 0;
	}
}
