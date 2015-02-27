/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsDataFile.h"
using namespace vmsFDM;

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

vmsDataFile::vmsDataFile()
{
	m_tData.GetData ().strName = "vmsDataFile v1.0";
}

vmsDataFile::~vmsDataFile()
{

}

LPDATAFILETREE vmsDataFile::FindItem(LPCSTR pszSection, LPCSTR pszValueName, LPDATAFILETREE ptRoot)
{
	if (ptRoot == NULL)
		ptRoot = &m_tData;

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
	SaveToFile (file, &m_tData);
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

void vmsDataFile::LoadFromFile(HANDLE hFile)
{
	vmsFile file (hFile, false);
	m_tData.Clear ();
	LoadFromFile (file, &m_tData);
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

LPDATAFILETREE vmsDataFile::CreateSection(LPCSTR pszSection, LPDATAFILETREE ptRoot)
{
	if (ptRoot == NULL)
		ptRoot = &m_tData;

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

void vmsDataFile::get_Value(LPCSTR pszSection, LPCSTR pszValueName, int &iValue)
{
	LPDATAFILETREE item = FindItem (pszSection, pszValueName);
	if (item)
		iValue = item->GetData ().vt;
}

void vmsDataFile::get_Value(LPCSTR pszSection, LPCSTR pszValueName, __int64 &i64Value)
{
	LPDATAFILETREE item = FindItem (pszSection, pszValueName);
	if (item)
		i64Value = item->GetData ().vt;
}

void vmsDataFile::get_Value(LPCSTR pszSection, LPCSTR pszValueName, double &fValue)
{
	LPDATAFILETREE item = FindItem (pszSection, pszValueName);
	if (item)
		fValue = item->GetData ().vt;
}

void vmsDataFile::get_Value(LPCSTR pszSection, LPCSTR pszValueName, LPCSTR &pszValue)
{
	LPDATAFILETREE item = FindItem (pszSection, pszValueName);
	if (item)
		pszValue = item->GetData ().vt;
}

void vmsDataFile::get_Value(LPCSTR pszSection, LPCSTR pszValueName, LPBYTE &pbValue, UINT &nValueSize)
{
	LPDATAFILETREE item = FindItem (pszSection, pszValueName);
	if (item)
	{
		pbValue = item->GetData ().vt;
		nValueSize = item->GetData ().vt.bytebuffersize ();
	}
}
