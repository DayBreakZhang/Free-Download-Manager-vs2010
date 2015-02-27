/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "vmsBatchList.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

vmsBatchList::vmsBatchList()
{

}

vmsBatchList::~vmsBatchList()
{

}

bool vmsBatchList::Create(LPCSTR pszTemplate, LPCSTR pszNumbers, char chStart, char chEnd)
{
	m_v.clear ();

	if (pszNumbers == NULL || strstr (pszTemplate, "(*)") == NULL)
		return CreateAZBatch (pszTemplate, chStart, chEnd);

	BOOL bAZ = strstr (pszTemplate, "(*a)") || strstr (pszTemplate, "(*A)");

	while (*pszNumbers)
	{
		int nStart, nEnd, nStep = 1, nWB = 1;

#define skip_digits while (*pszNumbers >= '0' && *pszNumbers <= '9') pszNumbers++;
#define skip_spaces while (*pszNumbers == ' ') pszNumbers++;
#define skip_number {skip_digits; skip_spaces;}
#define check_nz if (*pszNumbers == 0) return false;

		
		nStart = nEnd = atoi (pszNumbers);
		skip_number;

		if (*pszNumbers == 0 || *pszNumbers == ',') {
			if (*pszNumbers) {
				
				pszNumbers++;
				skip_spaces;
			}
		}
		else {
			if (*pszNumbers == '-')
			{
				pszNumbers++;
				skip_spaces;
				check_nz;

				
				nEnd = atoi (pszNumbers);
				skip_number;
			}

			while (*pszNumbers && *pszNumbers != ',') {

				char chWhat = *pszNumbers++;
				skip_spaces;

				int nValue = atoi (pszNumbers);
				skip_number;

				switch (chWhat) {
				
				case BATCHLIST_STEP_SYMBOL: nStep = nValue; break;
				
				case BATCHLIST_WILDCARD_SYMBOL: nWB = nValue; break; 
				default: return false;
				}
			}

			if (nEnd < nStart || nStep == 0)
				return false; 

			if (*pszNumbers == ',') {
				pszNumbers++;
				skip_spaces;
			}
		}

		

		for (int n = nStart; n <= nEnd; n += nStep)
		{
			CString str = pszTemplate;
			CString strN;
			strN.Format ("%d", n);
			int j = nWB - strN.GetLength ();
			while (j-- > 0) strN.Insert (0, '0');
			str.Replace ("(*)", strN);

			
			
			
			
			
			
			
			
			
			

			if (bAZ)
				CreateAZBatch (str, chStart, chEnd);
			else
				m_v.add (str);
		}
	}

	return true;
}

int vmsBatchList::get_ResultCount()
{
	return m_v.size ();
}

LPCSTR vmsBatchList::get_Result(int nIndex)
{
	return m_v [nIndex];
}

bool vmsBatchList::CreateAZBatch(LPCSTR pszTemplate, char chStart, char chEnd)
{
	for (char c = chStart; c <= chEnd; c++)
	{
		CString str = pszTemplate;
		CString strA = c;
		CString stra = c;
		strA.MakeUpper ();
		stra.MakeLower ();
		
		str.Replace ("(*A)", strA);
		str.Replace ("(*a)", stra);

		m_v.add (str);
	}

	return true;
}

void vmsBatchList::Clear()
{
	m_v.clear ();
}
