/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsSwfFile.h"
#include "vmsZlibHelper.h"

vmsSwfFile::vmsSwfFile()
{

}

vmsSwfFile::~vmsSwfFile()
{

}

bool vmsSwfFile::isCompressed(LPBYTE pbSwfData, UINT uSize)
{
	return m_header.isSwfCompressed (pbSwfData, uSize);
}

bool vmsSwfFile::Decompress(LPBYTE pbSwfData, UINT uSize, LPBYTE *ppbResult, UINT *puResultSize)
{
	assert (pbSwfData != NULL);
	assert (ppbResult != NULL && puResultSize != NULL);
	if (!pbSwfData)
		return false;
	if (ppbResult == NULL || puResultSize == NULL)
		return false;	
	
	assert (isCompressed (pbSwfData, uSize));
	if (!isCompressed (pbSwfData, uSize))
		return false;
	
	return vmsZlibHelper::DecompressGzip (pbSwfData + 8, uSize - 8, ppbResult, puResultSize) && 
		*ppbResult != NULL && *puResultSize != 0;		
}

bool vmsSwfFile::Parse(LPBYTE pbNonCompressedData, UINT uSize)
{
	if (!m_header.Parse (pbNonCompressedData, uSize))
		return false;

	return true;
}

const vmsSwfFileHeader* vmsSwfFile::getHeader() const
{
	return &m_header;
}
