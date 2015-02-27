/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSSWFFILE_H__2FDB399F_FBCC_4E75_BD67_3252BE873054__INCLUDED_)
#define AFX_VMSSWFFILE_H__2FDB399F_FBCC_4E75_BD67_3252BE873054__INCLUDED_

#include "vmsSwfFileHeader.h"	
#if _MSC_VER > 1000
#pragma once
#endif 

class vmsSwfFile  
{
public:
	const vmsSwfFileHeader* getHeader () const;
	bool Parse (LPBYTE pbNonCompressedData, UINT uSize);
	bool Decompress (LPBYTE pbSwfData, UINT uSize, LPBYTE *ppbResult, UINT *puResultSize);
	bool isCompressed (LPBYTE pbSwfData, UINT uSize);
	vmsSwfFile();
	virtual ~vmsSwfFile();

protected:
	vmsSwfFileHeader m_header;
};

#endif 
