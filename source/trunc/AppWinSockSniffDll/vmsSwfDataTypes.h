/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSSWFDATATYPES_H__18CC1426_EC90_46E0_A990_BF8F754E46A0__INCLUDED_)
#define AFX_VMSSWFDATATYPES_H__18CC1426_EC90_46E0_A990_BF8F754E46A0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class vmsSwfDataTypes  
{
public:
	static bool read_Bits (LPBYTE &pbData, UINT &uSize, int &cBitsOffset, int cBitsToRead, UINT64 &uVal);
	static bool read_Rect (LPBYTE &pbData, UINT &uSize, RECT &rc);
	vmsSwfDataTypes();
	virtual ~vmsSwfDataTypes();

};

#endif 
