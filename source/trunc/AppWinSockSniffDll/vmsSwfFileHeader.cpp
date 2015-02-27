/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsSwfFileHeader.h"
#include "vmsSwfDataTypes.h"

vmsSwfFileHeader::vmsSwfFileHeader()
{

}

vmsSwfFileHeader::~vmsSwfFileHeader()
{

}

bool vmsSwfFileHeader::isSwfCompressed(LPBYTE pbData, UINT uSize)
{
	if (!isValidHeader (pbData, uSize))
		return false;	
	m_bCompressed = pbData [0] == 'C'; 
	m_uVersion = pbData [3];
	m_uFileLength = * (UINT32*)(pbData + 4);
	return m_bCompressed;
}

bool vmsSwfFileHeader::isValidHeader(LPBYTE pbData, UINT uSize)
{
	assert (pbData != NULL);
	if (!pbData)
		return false;
	
	if (uSize < 8)
		return false; 
	
	
	
	if (pbData [0] != 'F' && pbData [0] != 'C')
		return false;
	
	if (pbData [1] != 'W' || pbData [2] != 'S')
		return false;

	return true;
}

bool vmsSwfFileHeader::Parse(LPBYTE pbNonCompressedData, UINT uSize)
{
	RECT rc;
	if (!vmsSwfDataTypes::read_Rect (pbNonCompressedData, uSize, rc))
		return false;
	assert (rc.left == 0 && rc.top == 0);
	m_sFrameSize.cx = rc.right / 20; 
	m_sFrameSize.cy = rc.bottom / 20;
	if (uSize < 4)
		return false;
	m_uFrameRate = (*(UINT16*)pbNonCompressedData) >> 8;
	pbNonCompressedData += 2;
	m_uFrameCount = * (UINT16*)pbNonCompressedData;
	pbNonCompressedData += 2;
	uSize =- 4;
	return true;
}
