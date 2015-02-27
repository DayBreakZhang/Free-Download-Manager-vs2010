/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSSWFFILEHEADER_H__E973E8C4_F13C_4633_8488_BFDDC1AC6718__INCLUDED_)
#define AFX_VMSSWFFILEHEADER_H__E973E8C4_F13C_4633_8488_BFDDC1AC6718__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class vmsSwfFileHeader  
{
public:
	bool Parse (LPBYTE pbNonCompressedData, UINT uSize);
	static bool isValidHeader (LPBYTE pbData, UINT uSize);
	bool isSwfCompressed (LPBYTE pbData, UINT uSize);
	vmsSwfFileHeader();
	virtual ~vmsSwfFileHeader();

public:
	bool m_bCompressed;
	BYTE m_uVersion;
	UINT32 m_uFileLength;
	SIZE m_sFrameSize;  
	BYTE m_uFrameRate; 
	UINT16 m_uFrameCount;
};

#endif 
