/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsUrlWords.h"
#include "vmsHttpHelper.h"

#define URL_WORD_MIN_LENGTH			5

vmsUrlWords::vmsUrlWords()
{

}

vmsUrlWords::~vmsUrlWords()
{

}

void vmsUrlWords::ExtractWords(LPCSTR pszUrl, string &strHost, vector <string> &vstrFolders,
							   string &strFileName, vector <string> &vUrlValues)
{
	strHost = strFileName = "";
	vstrFolders.clear ();
	vUrlValues.clear ();

	LPCSTR psz = strstr (pszUrl, "://");
	if (!psz)
		return;

	psz += 3;

	LPCSTR psz2 = strchr (psz, '/');
	if (!psz2)
		return;

	strHost.assign (psz, psz2 - psz);

	psz = psz2 + 1;

	LPCSTR pszQ = strchr (psz, '?');

	do 
	{
		LPCSTR pszS = strchr (psz, '/');
		if (!pszS)
			break;
		if (pszQ && pszS > pszQ)
			break;
		string str;
		str.assign (psz, pszS-psz);
		psz = pszS + 1;
		if (!str.empty ())
			vstrFolders.push_back (str);
	} 
	while (*psz);

	if (*psz == 0)
		return;

	if (!pszQ)
	{
		strFileName = psz;
		return;
	}

	if (pszQ != psz)
		strFileName.assign (psz, pszQ - psz);

	psz = pszQ + 1;

	vmsHttpHelper::ExtractUrlEncodedValues (psz, NULL, &vUrlValues);
}

void vmsUrlWords::ExtractWords2(LPCSTR pszUrl, vector <string> &vWords)
{
	string strHost, strFileName;
	vector <string> vFolders, vUrlVals;
	ExtractWords (pszUrl, strHost, vFolders, strFileName, vUrlVals);

	vWords.clear ();

	vWords.push_back (strHost);

	for (size_t i = 0; i < vFolders.size (); i++)
	{
		if (vFolders [i].length () >= URL_WORD_MIN_LENGTH)
			vWords.push_back (vFolders [i]);
	}

	if (strFileName.length () >= URL_WORD_MIN_LENGTH)
	{
		vWords.push_back (strFileName);
		vector <string> vTmp; 
		SplitWord (strFileName.c_str (), vTmp);
		for (size_t i = 0; i < vTmp.size (); i++)
		{
			if (vTmp [i].length () >= URL_WORD_MIN_LENGTH)
				vWords.push_back (vTmp [i]);
		}
	}

	for (size_t i = 0; i < vUrlVals.size (); i++)
	{
		if (vUrlVals [i].length () < URL_WORD_MIN_LENGTH)
			continue;
		vWords.push_back (vUrlVals [i]);
		vector <string> vTmp; 
		SplitWord (vUrlVals [i].c_str (), vTmp);
		for (size_t j = 0; j < vTmp.size (); j++)
		{
			if (vTmp [j].length () >= URL_WORD_MIN_LENGTH)
				vWords.push_back (vTmp [j]);
		}
	}

}

void vmsUrlWords::SplitWord(LPCSTR pszWord, vector <string> &vSubWords)
{
	vSubWords.clear ();

	if (!pszWord)
		return;

	bool bNotSolid = false;

	while (*pszWord)
	{
		size_t nNext = strcspn (pszWord, "-_~.");

		if (pszWord [nNext])
		{
			bNotSolid = true;
			string str; str.assign (pszWord, nNext);
			vSubWords.push_back (str);
			pszWord += nNext+1;
		}
		else
		{
			if (bNotSolid)
				vSubWords.push_back (pszWord); 
			break;
		}
	}
}

void vmsUrlWords::ExtractWordsFromUrlEncodedValues(LPCSTR pszValues, vector <string> &vResult)
{
	vector <string> vUrlVals;
	vmsHttpHelper::ExtractUrlEncodedValues (pszValues, NULL, &vUrlVals);
	for (size_t i = 0; i < vUrlVals.size (); i++)
	{
		if (vUrlVals [i].length () >= URL_WORD_MIN_LENGTH)
			vResult.push_back (vUrlVals [i]);
	}
}

int vmsUrlWords::GetUrlWordWeight(LPCSTR pszWord)
{
	assert (pszWord != NULL);
	if (!pszWord || !*pszWord)
		return 0;

	int cAlpha = 0, cDigits = 0;

	while (*pszWord)
	{
		if (isdigit ((BYTE)*pszWord))
			cDigits++;
		else if (isalpha ((BYTE)*pszWord))
			cAlpha++;
		pszWord++;
	}

	if (!cDigits)
		return 1; 

	if (cAlpha / cDigits >= 2)
		return 2;

	if (cDigits < 3)
		return 2;

	if (cAlpha < 3)
		return 3;

	return 10 + cDigits + cAlpha;
}
