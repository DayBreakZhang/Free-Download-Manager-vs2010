/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSCOOKIE_H__EC0577CA_4887_4432_8D95_1E758F0F6C62__INCLUDED_)
#define AFX_VMSCOOKIE_H__EC0577CA_4887_4432_8D95_1E758F0F6C62__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

struct vmsSingleCookie
{
	string strName;
	string strValue;
};

class vmsCookie  
{
public:
	void Add (vmsCookie *pc);
	int GetCommonItemCount (vmsCookie *pc);
	string toString();
	int FindItemByName (LPCSTR pszName);
	vmsSingleCookie* get_Item (int nIndex);
	int get_ItemCount();
	void Set (LPCSTR pszCookie);
	vmsCookie();
	virtual ~vmsCookie();

protected:
	vector <vmsSingleCookie> m_vItems;

};

#endif 
