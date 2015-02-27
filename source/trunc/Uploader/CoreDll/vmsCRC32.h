/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSCRC32_H__73BA404D_0D0A_48EA_90C9_A2ABD2A8B840__INCLUDED_)
#define AFX_VMSCRC32_H__73BA404D_0D0A_48EA_90C9_A2ABD2A8B840__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class vmsCRC32  
{
public:
	void Calculate (void* pData, int nLen);
	unsigned get_Result();

	vmsCRC32();
	virtual ~vmsCRC32();

protected:
	unsigned m_table [256];
	unsigned m_crc32;
};

#endif 
