/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsWinSockHttpTrafficAnalyzer.h"
#include "vmsHttpHelper.h"
#include "vmsUrlWords.h"

vmsWinSockHttpTrafficAnalyzer::vmsWinSockHttpTrafficAnalyzer()
{

}

vmsWinSockHttpTrafficAnalyzer::~vmsWinSockHttpTrafficAnalyzer()
{

}

void vmsWinSockHttpTrafficAnalyzer::FindPossibleSourceDialogs(
		const vmsHttpTrafficCollector::HttpDialog* pDlg,
		const vmsHttpTrafficCollector *pTraffic,
		int nStartIndex, int nEndIndex, DWORD dwContentType,
		const vmsHttpTrafficCollector::HttpDialog* pSuspectSrcDlg,
		DialogPossibleSources &vResult)
{
	vResult.clear ();

	assert (pTraffic != NULL);
	if (!pTraffic)
		return;

	assert (nStartIndex >= 0 && nEndIndex < pTraffic->getHttpDialogCount () &&
		nStartIndex <= nEndIndex);
	if (!(nStartIndex >= 0 && nEndIndex < pTraffic->getHttpDialogCount () &&
			nStartIndex <= nEndIndex))
		return;

	assert (pDlg != NULL);
	if (!pDlg)
		return;

	assert (dwContentType != 0);
	if (!dwContentType)
		return;

	vector <string> vReqUrlValues;
	vmsHttpHelper::ExtractUrlValues (pDlg->strRequestUrl.c_str (), NULL, &vReqUrlValues);

	string str = vmsHttpHelper::ExtractFileName (pDlg->strRequestUrl.c_str ());
	string strExt;
	if (!str.empty ())
	{
		vReqUrlValues.push_back (str);
		if (strrchr (str.c_str (), '.'))
			strExt = strrchr (str.c_str (), '.') + 1;
	}

	int i;
	
	for (i = 0; i < vReqUrlValues.size (); i++)
	{
		if (vReqUrlValues [i].length () < 3)
			vReqUrlValues.erase (vReqUrlValues.begin ()+i--);
	}

	
	

	int cOrigUrlValues = vReqUrlValues.size ();

	for (i = 0; i < cOrigUrlValues; i++)
	{
		LPCSTR pszVal = vReqUrlValues [i].c_str ();
		bool bNotSolid = false;
		while (*pszVal)
		{
			size_t nNext = strcspn (pszVal, "-_~.");
			if (pszVal [nNext])
			{
				bNotSolid = true;
				if (nNext > 4)
				{
					string str; str.assign (pszVal, nNext);
					if (str != strExt)
						vReqUrlValues.push_back (str);
				}
				pszVal += nNext+1;
			}
			else
			{
				
				if (bNotSolid)
					vReqUrlValues.push_back (pszVal); 
				break;
			}
		}
	}

	for (i = 0; i < vReqUrlValues.size (); i++)
	{
		DialogContainingWord *p = new DialogContainingWord;
		p->strWord = vReqUrlValues [i];
		vResult.push_back (p);
	}

	if (pSuspectSrcDlg)
	{
		

		for (int j = 0; j < vResult.size (); j++)
		{		
			bool bContains = 
				
				(vmsHttpTrafficCollector::isResponseBodyContainsText (pSuspectSrcDlg, vResult [j]->strWord.c_str ()));
		
			if (!bContains)
				continue; 

			for (int i = nEndIndex; i >= nStartIndex; i--)
			{
				const vmsHttpTrafficCollector::HttpDialog* pSomeDlg = pTraffic->getHttpDialog (i);
				if ((pSomeDlg->enCT & dwContentType) == 0)
					continue;
				if (pSomeDlg->vbResponseBody.empty () && pSomeDlg != pSuspectSrcDlg)
					continue;

				if (pSomeDlg != pSuspectSrcDlg)
				{
					bContains = vmsHttpTrafficCollector::isResponseBodyContainsText (
						pSomeDlg, vResult [j]->strWord.c_str ());
				}
				else
				{
					bContains = true;
				}

				if (bContains)
					vResult [j]->vDlgs.push_back (pSomeDlg);
			}

			if (vResult [j]->vDlgs.size () == 1)
				return; 
		}

		return;
	}

	
	assert (pSuspectSrcDlg == NULL);

	

	for (i = nEndIndex; i >= nStartIndex; i--)
	{
		const vmsHttpTrafficCollector::HttpDialog* pSomeDlg = pTraffic->getHttpDialog (i);
		if ((pSomeDlg->enCT & dwContentType) == 0)
			continue;
		if (pSomeDlg->vbResponseBody.empty ())
			continue;
		
		for (int j = 0; j < vResult.size (); j++)
		{
			bool bContains = vmsHttpTrafficCollector::isResponseBodyContainsText (pSomeDlg, vResult [j]->strWord.c_str ());
			
			if (bContains)
				vResult [j]->vDlgs.push_back (pSomeDlg);
		}
	}
}

float vmsWinSockHttpTrafficAnalyzer::CalculatePossibleSourceDialogWeight(const vmsHttpTrafficCollector::HttpDialog* pDlg, bool bDontFindUnique, const DialogPossibleSources& vDPS)
{
	if (vDPS.empty ())
		return 0;

	double fWeight = 0; 
	int cEntries = 0; 
	
	for (int j = 0; j < vDPS.size (); j++)
	{
		for (int k = 0; k < vDPS [j]->vDlgs.size (); k++)
		{
			if (vDPS [j]->vDlgs [k] == pDlg)
			{
				
				if (!bDontFindUnique && vDPS [j]->vDlgs.size () == 1)
					cEntries = -1; 
				else
					cEntries++;
				break;
			}
		}
		
		if (cEntries == -1)
			break;
	}
	
	if (cEntries == -1)
		fWeight = 1.01; 
	else
		fWeight = (double)cEntries / (double)vDPS.size ();
	
	return fWeight;
}

int vmsWinSockHttpTrafficAnalyzer::FindRedirectsRoot(const vmsHttpTrafficCollector *pTraffic, int nHttpDlgIndex)
{
	assert (nHttpDlgIndex >= 0);

	if (nHttpDlgIndex <= 0)
		return -1;
	
	const vmsHttpTrafficCollector::HttpDialog* pRrDlg = pTraffic->getHttpDialog (nHttpDlgIndex);
	int nResultIndex = -1;
	
	for (int i = nHttpDlgIndex-1; i >= 0; i--)
	{
		const vmsHttpTrafficCollector::HttpDialog* pDlg = pTraffic->getHttpDialog (i);
		const vmsHttpParser::HdrField *pLoc = pDlg->pHttpResponse->FieldByName ("Location");
		if (!pLoc)
			continue;
		if (pLoc->strValue == pRrDlg->strRequestUrl)
		{
			pRrDlg = pDlg;
			nResultIndex = i;
		}
	}
	
	return nResultIndex;
}

void vmsWinSockHttpTrafficAnalyzer::FindOutgoingDialogs(
	const vmsHttpTrafficCollector *pTraffic, 
	int nSrcDlgIndex, DWORD dwOutgoingContentTypes, 
	bool bDontFindUnique,
	vector <const vmsHttpTrafficCollector::HttpDialog*> &vOutgoingDlgs)
{
	vOutgoingDlgs.clear ();

	int cDlgs = pTraffic->getHttpDialogCount ();
	const vmsHttpTrafficCollector::HttpDialog *pSrcDlg = pTraffic->getHttpDialog (nSrcDlgIndex);

	
	vector <const vmsHttpTrafficCollector::HttpDialog*> vOutgDlgs;
	
	
	vector <float> vOutgDlgsWeights;

	for (int i = nSrcDlgIndex+1; i < cDlgs; i++)
	{
		const vmsHttpTrafficCollector::HttpDialog *pDlg = pTraffic->getHttpDialog (i);
		if ((pDlg->enCT & dwOutgoingContentTypes) == 0)
			continue;

		int nRRi = FindRedirectsRoot (pTraffic, i);
		if (nRRi == -1)
			nRRi = i;

		if (nRRi < nSrcDlgIndex)
			continue;
		
		DialogPossibleSources vDPS;
		FindPossibleSourceDialogs (pTraffic->getHttpDialog (nRRi), pTraffic, 0, nRRi-1, pSrcDlg->enCT, pSrcDlg, vDPS);

		float fWeight = CalculatePossibleSourceDialogWeight (pSrcDlg, bDontFindUnique, vDPS);
		
		if (fWeight)
		{
			vOutgDlgs.push_back (pDlg);
			vOutgDlgsWeights.push_back (fWeight);
		}

		Free (vDPS);
	}

	

	double fMaxWeight = 0;
	
	for (int i = 0; i < vOutgDlgsWeights.size (); i++)
	{
		if (vOutgDlgsWeights [i] > fMaxWeight)
		{
			vOutgoingDlgs.clear ();
			vOutgoingDlgs.push_back (vOutgDlgs [i]);
			fMaxWeight = vOutgDlgsWeights [i];
		}
		else if (vOutgDlgsWeights [i] == fMaxWeight && fMaxWeight != 0)
		{
			vOutgoingDlgs.push_back (vOutgDlgs [i]);
		}
	}
}

void vmsWinSockHttpTrafficAnalyzer::Free(DialogPossibleSources &v)
{
	for (size_t i = 0; i < v.size (); i++)
		delete v [i];
	v.clear ();
}

void vmsWinSockHttpTrafficAnalyzer::FindOutgoingDialogsByReferer(
	const vmsHttpTrafficCollector *pTraffic, 
	int nSrcDlgIndex, DWORD dwOutgoingContentTypes, 
	vector <const vmsHttpTrafficCollector::HttpDialog*> &vOutgoingDlgs)
{
	vOutgoingDlgs.clear ();
	
	int cDlgs = pTraffic->getHttpDialogCount ();
	const vmsHttpTrafficCollector::HttpDialog *pSrcDlg = pTraffic->getHttpDialog (nSrcDlgIndex);
		
	for (int i = nSrcDlgIndex+1; i < cDlgs; i++)
	{
		const vmsHttpTrafficCollector::HttpDialog *pDlg = pTraffic->getHttpDialog (i);
		if ((pDlg->enCT & dwOutgoingContentTypes) == 0)
			continue;

		if (!pDlg->pHttpRequest)
			continue;

		const vmsHttpParser::HdrField *pReferer = pDlg->pHttpRequest->FieldByName ("Referer");
		if (!pReferer)
			continue;
	
		if (pSrcDlg->strRequestUrl == pReferer->strValue)
			vOutgoingDlgs.push_back (pDlg);
		else if (pReferer->strValue.length () > 100 &&
					strncmp (pSrcDlg->strRequestUrl.c_str (), pReferer->strValue.c_str (), pReferer->strValue.length ()) == 0)
			vOutgoingDlgs.push_back (pDlg);
	}
}

void vmsWinSockHttpTrafficAnalyzer::FindUniqueUrlWords(const vector <const vmsHttpTrafficCollector::HttpDialog*> &vDlgs, 
			vector < vector <string> > &vvUniqueWords)
{
	vvUniqueWords.clear ();
	
	for (size_t iDlg = 0; iDlg < vDlgs.size (); iDlg++)
	{
		vector <string> vWords;
		vmsUrlWords::ExtractWords2 (vDlgs [iDlg]->strRequestUrl.c_str (), vWords);
		vvUniqueWords.push_back (vWords);
	}

	
	string strNonUniqueWords;

	for (size_t iV = 0; iV < vvUniqueWords.size (); iV++)
	{
		vector <string> &vWords = vvUniqueWords [iV];

		for (int iWord = 0; iWord < vWords.size (); iWord++)
		{
			string &strWord = vWords [iWord];
			bool bNonUnique = false;

			
			if (strWord.length () < 4 || strstr (strNonUniqueWords.c_str (), strWord.c_str ()))
			{
				vWords.erase (vWords.begin () + iWord);
				iWord--;
				continue;
			}

			for (size_t iVother = iV+1; iVother < vvUniqueWords.size (); iVother++)
			{
				if (vDlgs [iV]->strRequestUrl == vDlgs [iVother]->strRequestUrl)
					continue;
				
				vector <string> &vWordsOther = vvUniqueWords [iVother];
				for (size_t i = 0; i < vWordsOther.size (); i++)
				{
					if (strWord == vWordsOther [i])
					{
						bNonUnique = true;
						break;
					}
				}
				if (bNonUnique)
					break;
			}

			if (bNonUnique)
			{
				
				strNonUniqueWords += strWord;
				strNonUniqueWords += ' ';

				vWords.erase (vWords.begin () + iWord);
				iWord--;
			}
		}
	}
}
