/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSHTTPPARSER_H__D147ED53_0DB7_4DBB_81C4_B046B4397AB3__INCLUDED_)
#define AFX_VMSHTTPPARSER_H__D147ED53_0DB7_4DBB_81C4_B046B4397AB3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class vmsHttpParser  
{
public:
	struct HdrField
	{
		string strName;
		string strValue;
	};

public:
	const HdrField* FieldByName (LPCSTR pszName) const;
	void ParseHeader (LPCSTR pszHdr);

	vmsHttpParser();
	virtual ~vmsHttpParser();

protected:
	static void ExtractFieldValue (LPCSTR pszHdr, LPCSTR pszFieldName, string *pstrResult);
	bool ExtractHdrField (LPCSTR &pszHdr, HdrField &hdrf);
	vector <HdrField> m_vFields;
};

#endif 
