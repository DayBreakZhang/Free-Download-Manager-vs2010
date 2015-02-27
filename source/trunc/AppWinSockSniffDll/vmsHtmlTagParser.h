/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSHTMLTAGPARSER_H__A32BA56F_FB2C_4029_9B82_0CBEA6F81D3A__INCLUDED_)
#define AFX_VMSHTMLTAGPARSER_H__A32BA56F_FB2C_4029_9B82_0CBEA6F81D3A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class vmsHtmlTagParser  
{
public:
	struct TagAttribute
	{
		string strName;
		string strValue;
		char chQ;  

		TagAttribute () {chQ = '\0';} 
	};
public:
	LPCSTR getName () const;
	const TagAttribute* findAttribute (LPCSTR pszName) const;
	
	int Parse (LPCSTR pszTagHead);
	vmsHtmlTagParser(LPCSTR pszTagHead = NULL);
	virtual ~vmsHtmlTagParser();

protected:
	string m_strName;
	vector <TagAttribute> m_vAttribs;

};

#endif 
