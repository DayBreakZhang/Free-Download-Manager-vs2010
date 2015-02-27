/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsSwfDataTypes.h"

vmsSwfDataTypes::vmsSwfDataTypes()
{

}

vmsSwfDataTypes::~vmsSwfDataTypes()
{

}

bool vmsSwfDataTypes::read_Rect(LPBYTE &pbData, UINT &uSize, RECT &rc)
{
	if (!uSize)
		return false;

	UINT64 uTmp; 
	int cBitsOffset = 0;

	read_Bits (pbData, uSize, cBitsOffset, 5, uTmp);
	UINT cBitsPerValue = (UINT)uTmp;

	if (!read_Bits (pbData, uSize, cBitsOffset, cBitsPerValue, uTmp))
		return false;
	rc.left = uTmp;

	if (!read_Bits (pbData, uSize, cBitsOffset, cBitsPerValue, uTmp))
		return false;
	rc.right = uTmp;

	if (!read_Bits (pbData, uSize, cBitsOffset, cBitsPerValue, uTmp))
		return false;
	rc.top = uTmp;

	if (!read_Bits (pbData, uSize, cBitsOffset, cBitsPerValue, uTmp))
		return false;
	rc.bottom = uTmp;

	if (cBitsOffset)
	{
		
		pbData++;
		uSize--;
	}

	return true;
}

bool vmsSwfDataTypes::read_Bits(LPBYTE &pbData, UINT &uSize, int &cBitsOffset, int cBitsToRead, UINT64 &uVal)
{
	if (!uSize)
		return false;
	assert (cBitsOffset >= 0 && cBitsOffset < 8);
	if (cBitsOffset < 0 || cBitsOffset > 7)
		return false;
	assert (cBitsToRead > 0);
	if (cBitsToRead <= 0)
		return false;

	uVal = 0;

	while (cBitsToRead)
	{
		BYTE uByte = *pbData;
		if (cBitsOffset)
			uByte <<= cBitsOffset;
		int cBitsRead = (cBitsOffset + cBitsToRead <= 8) ? cBitsToRead : 8 - cBitsOffset;
		uByte >>= 8 - cBitsRead;
		uVal <<= cBitsRead;
		uVal |= uByte;
		cBitsToRead -= cBitsRead;
		cBitsOffset += cBitsRead;
		if (cBitsOffset == 8)
		{
			pbData++;
			uSize--;
			cBitsOffset = 0;
			if (cBitsToRead && !uSize)
				return false;
		}
	}

	return true;
}
