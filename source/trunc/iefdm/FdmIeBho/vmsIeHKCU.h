/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSIEHKCU_H__FE6A1008_A855_4A11_AD7B_6FB2C15D426F__INCLUDED_)
#define AFX_VMSIEHKCU_H__FE6A1008_A855_4A11_AD7B_6FB2C15D426F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class vmsIeHKCU  
{
public:
	CRegKey& getKey ();
	void Close();
	LONG Create (LPCTSTR ptszPath, REGSAM samDesired);
	LONG Open (LPCTSTR ptszPath, REGSAM samDesired);
	vmsIeHKCU();
	virtual ~vmsIeHKCU();

protected:
	static bool IsIeInProtectedMode ();
	CRegKey m_key;
};

#endif 
