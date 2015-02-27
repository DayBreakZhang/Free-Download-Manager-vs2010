/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSNOTEVERYWHERESUPPORTEDFUNCTIONS_H__0FED89AF_F5BC_411C_9AC5_7E54AC78C984__INCLUDED_)
#define AFX_VMSNOTEVERYWHERESUPPORTEDFUNCTIONS_H__0FED89AF_F5BC_411C_9AC5_7E54AC78C984__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class vmsNotEverywhereSupportedFunctions  
{
public:
	static LONG RegOverridePredefKey (HKEY, HKEY);
	vmsNotEverywhereSupportedFunctions();
	virtual ~vmsNotEverywhereSupportedFunctions();
};

#endif 
