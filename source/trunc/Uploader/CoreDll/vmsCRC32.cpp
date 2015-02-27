/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsCRC32.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

vmsCRC32::vmsCRC32()
{
	const unsigned CRC_POLY = 0xEDB88320;
    unsigned i, j, r;
    for (i = 0; i < 256; i++){
           for (r = i, j = 8; j; j--)
                 r = r & 1? (r >> 1) ^ CRC_POLY: r >> 1;
           m_table[i] = r;
    }

	m_crc32 = 0;
}

vmsCRC32::~vmsCRC32()
{

}

void vmsCRC32::Calculate(void *pData, int nLen)
{
	const unsigned CRC_MASK = 0xD202EF8D;
    register unsigned char* pdata = (unsigned char*)pData;
    unsigned crc = m_crc32;
    while (nLen--){
           crc = m_table [BYTE (crc) ^ *pdata++] ^ crc >> 8;
           crc ^= CRC_MASK;
    }
    m_crc32 = crc;
}

unsigned vmsCRC32::get_Result()
{
	return m_crc32;
}
