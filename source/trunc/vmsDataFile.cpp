/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsDataFile.h"
#include "Utils.h"
using namespace vmsFDM;

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

vmsDataFile::vmsDataFile()
{
	m_tData.CreateInstance ();
	m_tData->GetData ().strName = "vmsDataFile v1.0";
}

vmsDataFile::~vmsDataFile()
{

}

LPDATAFILETREE vmsDataFile::FindItem(LPCSTR pszSection, LPCSTR pszValueName, LPDATAFILETREE ptRoot)
{
	if (ptRoot == NULL)
		ptRoot = m_tData;

	fsString strS; 

	if (pszSection && *pszSection)
	{
		while (*pszSection && *pszSection != '\\' && *pszSection != '/')
			strS += *pszSection++;

		if (*pszSection)
			pszSection++;
	}

	if (strS.IsEmpty () == FALSE)
	{
		
		for (int i = 0; i < ptRoot->GetLeafCount (); i++)
		{
			LPDATAFILETREE ptLeaf = ptRoot->GetLeaf (i);
			if (ptLeaf->GetData ().vt.empty () && ptLeaf->GetData ().strName == strS)
				
				return *pszSection || (pszValueName && *pszValueName) ? 
					FindItem (pszSection, pszValueName, ptLeaf) : ptLeaf;
		}

		return NULL; 
	}

	

	for (int i = 0; i < ptRoot->GetLeafCount (); i++)
	{
		LPDATAFILETREE ptLeaf = ptRoot->GetLeaf (i);
		if (ptLeaf->GetData ().vt.empty () == false && ptLeaf->GetData ().strName == pszValueName)
			return ptLeaf;
	}

	return NULL;	
}

void vmsDataFile::SaveToFile(HANDLE hFile)
{
	vmsFile file;
	file.Attach (hFile, false);
	SaveToFile (file, m_tData);
}

void vmsDataFile::SaveToFile(vmsFile &file, LPDATAFILETREE ptRoot)
{
	ASSERT (ptRoot != NULL);

	SaveToFile (file, ptRoot->GetData ());

	if (ptRoot->GetData ().vt.empty () == false)
		return;

	file.WriteInt (ptRoot->GetLeafCount ());

	for (int i = 0; i < ptRoot->GetLeafCount (); i++)
		SaveToFile (file, ptRoot->GetLeaf (i));
}

void vmsDataFile::SaveToFile(vmsFile &file, vmsDataFileItem &item)
{
	
	file.WriteString (item.strName);

	

	
	int iDT = (int)item.vt.type ();
	file.Write (&iDT, sizeof (iDT));

	
	switch (item.vt.type ())
	{
	case VVT_EMPTY: break;
	case VVT_INT: file.WriteInt (item.vt); break;
	case VVT_DOUBLE: file.WriteDouble (item.vt); break;
	case VVT_INT64: file.WriteInt64 (item.vt); break;
	case VVT_ASTRING: file.WriteString (item.vt); break;
	case VVT_LPBYTE: 
		file.WriteInt (item.vt.bytebuffersize ());
		file.Write ((LPBYTE)item.vt, item.vt.bytebuffersize ()); 
		break;
	default: ASSERT (false); 
	}
}

void vmsDataFile::SaveToBuffer(LPBYTE& pbtCurrentPos, LPBYTE pbtBuffer, DWORD dwBufferSize, DWORD* pdwRequiredSize)
{
	SaveToBuffer(pbtCurrentPos, pbtBuffer, dwBufferSize, pdwRequiredSize, m_tData);
}

void vmsDataFile::SaveToBuffer(LPBYTE& pbtCurrentPos, LPBYTE pbtBuffer, DWORD dwBufferSize, DWORD* pdwRequiredSize, LPDATAFILETREE ptRoot)
{
	ASSERT (ptRoot != NULL);

	if (pbtBuffer == NULL) {

		SaveToBuffer (pbtCurrentPos, 0, 0, pdwRequiredSize, ptRoot->GetData ());

		if (ptRoot->GetData ().vt.empty () == false) {
			return;
		}

		int nCount = ptRoot->GetLeafCount ();
		putVarToBuffer(nCount, pbtCurrentPos, 0, 0, pdwRequiredSize);

		for (int i = 0; i < ptRoot->GetLeafCount (); i++) {
			SaveToBuffer (pbtCurrentPos, 0, 0, pdwRequiredSize, ptRoot->GetLeaf (i));
		}

		return;

	}

	SaveToBuffer (pbtCurrentPos, pbtBuffer, dwBufferSize, 0, ptRoot->GetData ());

	if (ptRoot->GetData ().vt.empty () == false) {
		return;
	}

	int nCount = ptRoot->GetLeafCount ();
	putVarToBuffer(nCount, pbtCurrentPos, pbtBuffer, dwBufferSize, 0);

	for (int i = 0; i < ptRoot->GetLeafCount (); i++) {
		SaveToBuffer (pbtCurrentPos, pbtBuffer, dwBufferSize, 0, ptRoot->GetLeaf (i));
	}
}

void vmsDataFile::SaveToBuffer(LPBYTE& pbtCurrentPos, LPBYTE pbtBuffer, DWORD dwBufferSize, DWORD* pdwRequiredSize, vmsDataFileItem &item)
{
	
	putStrToBuffer(item.strName.pszString, pbtCurrentPos, 0, 0, pdwRequiredSize);

	int i = 0;
	double dblVal = 0.;
	__int64 i64Val = 0;
	int nBufferSize = 0;

	

	
	int iDT = (int)item.vt.type ();
	putVarToBuffer(iDT, pbtCurrentPos, 0, 0, pdwRequiredSize);

	
	switch (item.vt.type ())
	{
		case VVT_EMPTY: 
			break;
		case VVT_INT:
			i = item.vt;
			putVarToBuffer(i, pbtCurrentPos, 0, 0, pdwRequiredSize);
			break;
		case VVT_DOUBLE: 
			dblVal = item.vt;
			putVarToBuffer(dblVal, pbtCurrentPos, 0, 0, pdwRequiredSize);
			break;
		case VVT_INT64:
			i64Val = item.vt;
			putVarToBuffer(i64Val, pbtCurrentPos, 0, 0, pdwRequiredSize);
			break;
		case VVT_ASTRING: 
			putStrToBuffer((LPCTSTR)item.vt, pbtCurrentPos, 0, 0, pdwRequiredSize);
			break;
		case VVT_LPBYTE: 
			nBufferSize = item.vt.bytebuffersize ();
			putVarToBuffer(nBufferSize, pbtCurrentPos, 0, 0, pdwRequiredSize);
			if (pdwRequiredSize) {
				*pdwRequiredSize += item.vt.bytebuffersize ();
			}
			break;
		default: 
			ASSERT (false); 
	}

	if (pbtBuffer == NULL)
		return;

	
	putStrToBuffer(item.strName.pszString, pbtCurrentPos, pbtBuffer, dwBufferSize, 0);

	

	
	putVarToBuffer(iDT, pbtCurrentPos, pbtBuffer, dwBufferSize, 0);

	
	switch (item.vt.type ())
	{
		case VVT_EMPTY: 
			break;
		case VVT_INT:
			i = item.vt;
			putVarToBuffer(i, pbtCurrentPos, pbtBuffer, dwBufferSize, 0);
			break;
		case VVT_DOUBLE: 
			dblVal = item.vt;
			putVarToBuffer(dblVal, pbtCurrentPos, pbtBuffer, dwBufferSize, 0);
			break;
		case VVT_INT64:
			i64Val = item.vt;
			putVarToBuffer(i64Val, pbtCurrentPos, pbtBuffer, dwBufferSize, 0);
			break;
		case VVT_ASTRING: 
			putStrToBuffer((LPCTSTR)item.vt, pbtCurrentPos, pbtBuffer, dwBufferSize, 0);
			break;
		case VVT_LPBYTE: 
			nBufferSize = item.vt.bytebuffersize ();
			putVarToBuffer(nBufferSize, pbtCurrentPos, pbtBuffer, dwBufferSize, 0);
			memcpy(pbtCurrentPos, (void*)(LPBYTE)item.vt, nBufferSize);
			pbtCurrentPos += nBufferSize;
			break;
		default: 
			ASSERT (false); 
	}
}

void vmsDataFile::LoadFromFile(HANDLE hFile)
{
	vmsFile file (hFile, false);
	m_tData->Clear ();
	LoadFromFile (file, m_tData);
}

void vmsDataFile::LoadFromFile(vmsFile &file, LPDATAFILETREE ptRoot)
{
	ASSERT (ptRoot != NULL);

	LoadFromFile (file, ptRoot->GetData ());

	if (ptRoot->GetData ().vt.empty () == false)
		return;	

	int cLeafs;
	file.ReadInt (cLeafs);

	for (int i = 0; i < cLeafs; i++)
		LoadFromFile (file, ptRoot->AddLeaf (vmsDataFileItem ()));
}

void vmsDataFile::LoadFromFile(vmsFile &file, vmsDataFileItem &item)
{
	
	file.ReadString (item.strName);

	

	
	int enType;
	file.ReadInt (enType);

	int i; double f; __int64 i64; fsString str; 
	LPBYTE pb; int nSize;

	
	switch (enType)
	{
	case VVT_EMPTY: break;
	case VVT_INT: file.ReadInt (i); item.vt = i; break;
	case VVT_DOUBLE: file.ReadDouble (f); item.vt = f; break;
	case VVT_INT64: file.ReadInt64 (i64); item.vt = i64; break;
	case VVT_ASTRING: file.ReadString (str); item.vt = str; break;
	case VVT_LPBYTE: 
		file.ReadInt (nSize);
		pb = new BYTE [nSize];
		file.Read (pb, nSize);
		item.vt.set (pb, nSize);
		delete [] pb;
		break;
	default: ASSERT (false); 
	}
}

void vmsDataFile::LoadFromBuffer(LPBYTE& pbtCurrentPos, LPBYTE pbtBuffer, DWORD dwBufferSizeSize)
{
	LoadFromBuffer(pbtCurrentPos, pbtBuffer, dwBufferSizeSize, m_tData);
}

bool vmsDataFile::LoadFromBuffer(LPBYTE& pbtCurrentPos, LPBYTE pbtBuffer, DWORD dwBufferSizeSize, LPDATAFILETREE ptRoot)
{
	ASSERT (ptRoot != NULL);

	if (!LoadFromBuffer (pbtCurrentPos, pbtBuffer, dwBufferSizeSize, ptRoot->GetData ()))
		return false;

	if (ptRoot->GetData ().vt.empty () == false) {
		return true;	
	}

	int cLeafs;
	if (!getVarFromBuffer(cLeafs, pbtCurrentPos, pbtBuffer, dwBufferSizeSize))
		return false;

	for (int i = 0; i < cLeafs; i++) {
		if (!LoadFromBuffer (pbtCurrentPos, pbtBuffer, dwBufferSizeSize, ptRoot->AddLeaf (vmsDataFileItem ())))
			return false;
	}

	return true;
}

bool vmsDataFile::LoadFromBuffer(LPBYTE& pbtCurrentPos, LPBYTE pbtBuffer, DWORD dwBufferSizeSize, vmsDataFileItem &item)
{
	
	if (!getStrFromBuffer(&item.strName.pszString, pbtCurrentPos, pbtBuffer, dwBufferSizeSize))
		return false;

	

	
	int enType;
	if (!getVarFromBuffer(enType, pbtCurrentPos, pbtBuffer, dwBufferSizeSize))
		return false;

	int i; double f; __int64 i64; fsString str; 
	LPBYTE pb; int nSize;

	
	switch (enType)
	{
		case VVT_EMPTY: 
			break;
		case VVT_INT: 
			if (!getVarFromBuffer(i, pbtCurrentPos, pbtBuffer, dwBufferSizeSize))
				return false;
			item.vt = i;
			break;
		case VVT_DOUBLE: 
			if (!getVarFromBuffer(f, pbtCurrentPos, pbtBuffer, dwBufferSizeSize))
				return false;
			item.vt = f; 
			break;
		case VVT_INT64: 
			if (!getVarFromBuffer(i64, pbtCurrentPos, pbtBuffer, dwBufferSizeSize))
				return false;
			item.vt = i64; 
			break;
		case VVT_ASTRING: 
			if (!getStrFromBuffer(&str.pszString, pbtCurrentPos, pbtBuffer, dwBufferSizeSize))
				return false;
			item.vt = str; 
			break;
		case VVT_LPBYTE: 
			if (!getVarFromBuffer(nSize, pbtCurrentPos, pbtBuffer, dwBufferSizeSize))
				return false;
			pb = new BYTE [nSize];
			memcpy(pb, pbtCurrentPos, nSize);
			item.vt.set (pb, nSize);
			delete [] pb;
			pbtCurrentPos += nSize;
			break;
		default: 
			ASSERT (false); 
	}

	return true;
}

LPDATAFILETREE vmsDataFile::CreateSection(LPCSTR pszSection, LPDATAFILETREE ptRoot)
{
	if (ptRoot == NULL)
		ptRoot = m_tData;

	if (pszSection == NULL || *pszSection == 0)
		return ptRoot;

	fsString strS;
	while (*pszSection && *pszSection != '\\' && *pszSection != '/')
		strS += *pszSection++;

	if (*pszSection)
		pszSection++;

	if (strS != "")
	for (int i = 0; i < ptRoot->GetLeafCount (); i++)
	{
		LPDATAFILETREE ptLeaf = ptRoot->GetLeaf (i);
		if (ptLeaf->GetData ().vt.empty () && ptLeaf->GetData ().strName == strS) 
			return CreateSection (pszSection, ptLeaf);
	}

	
	
	LPDATAFILETREE ptLeaf = ptRoot->AddLeaf (vmsDataFileItem ());
	ptLeaf->GetData ().strName = strS;
	return CreateSection (pszSection, ptLeaf);
}

LPDATAFILEITEM vmsDataFile::CreateItem(LPDATAFILETREE pSection, LPCSTR pszItemName)
{
	LPDATAFILETREE ptLeaf = FindItem (NULL, pszItemName, pSection);
	if (ptLeaf == NULL)
	{
		ptLeaf = pSection->AddLeaf (vmsDataFileItem ());
		ptLeaf->GetData ().strName = pszItemName;
	}
	return &ptLeaf->GetData ().vt;
}

LPDATAFILEITEM vmsDataFile::CreateItem(LPCSTR pszSection, LPCSTR pszItemName)
{
	return CreateItem (CreateSection (pszSection), pszItemName);
}

void vmsDataFile::set_Value(LPCSTR pszSection, LPCSTR pszValueName, int iValue)
{
	LPDATAFILEITEM item = CreateItem (pszSection, pszValueName);
	item->set (iValue);
}

void vmsDataFile::set_Value(LPCSTR pszSection, LPCSTR pszValueName, __int64 i64Value)
{
	LPDATAFILEITEM item = CreateItem (pszSection, pszValueName);
	item->set (i64Value);
}

void vmsDataFile::set_Value(LPCSTR pszSection, LPCSTR pszValueName, double fValue)
{
	LPDATAFILEITEM item = CreateItem (pszSection, pszValueName);
	item->set (fValue);
}

void vmsDataFile::set_Value(LPCSTR pszSection, LPCSTR pszValueName, LPCSTR pszValue)
{
	LPDATAFILEITEM item = CreateItem (pszSection, pszValueName);
	item->set (pszValue);
}

void vmsDataFile::set_Value(LPCSTR pszSection, LPCSTR pszValueName, LPBYTE pbValue, UINT nValueSize)
{
	LPDATAFILEITEM item = CreateItem (pszSection, pszValueName);
	item->set (pbValue, nValueSize);
}

bool vmsDataFile::get_Value(LPCSTR pszSection, LPCSTR pszValueName, int &iValue)
{
	LPDATAFILETREE item = FindItem (pszSection, pszValueName);
	if (item) {
		iValue = item->GetData ().vt;
		return true;
	}
	return false;
}

bool vmsDataFile::get_Value(LPCSTR pszSection, LPCSTR pszValueName, __int64 &i64Value)
{
	LPDATAFILETREE item = FindItem (pszSection, pszValueName);
	if (item) {
		i64Value = item->GetData ().vt;
		return true;
	}
	return false;
}

bool vmsDataFile::get_Value(LPCSTR pszSection, LPCSTR pszValueName, double &fValue)
{
	LPDATAFILETREE item = FindItem (pszSection, pszValueName);
	if (item) {
		fValue = item->GetData ().vt;
		return true;
	}
	return false;
}

bool vmsDataFile::get_Value(LPCSTR pszSection, LPCSTR pszValueName, LPCSTR &pszValue)
{
	LPDATAFILETREE item = FindItem (pszSection, pszValueName);
	if (item) {
		pszValue = item->GetData ().vt;
		return true;
	}
	return false;
}

bool vmsDataFile::get_Value(LPCSTR pszSection, LPCSTR pszValueName, LPBYTE &pbValue, UINT &nValueSize)
{
	LPDATAFILETREE item = FindItem (pszSection, pszValueName);
	if (item && item->GetData ().vt.type () != VVT_EMPTY)
	{
		pbValue = item->GetData ().vt;
		nValueSize = item->GetData ().vt.bytebuffersize ();
		return true;
	}
	return false;
}
