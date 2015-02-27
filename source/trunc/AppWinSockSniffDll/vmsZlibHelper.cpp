/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsZlibHelper.h"
#include "zlib/zlib.h"
#include "zlib/zutil.h"

vmsZlibHelper::vmsZlibHelper()
{

}

vmsZlibHelper::~vmsZlibHelper()
{

}

BOOL vmsZlibHelper::DecompressGzip(LPBYTE pbData, UINT nSize, LPBYTE *ppUncompressed, UINT *puUncompressedSize)
{
	LOGFN ("vmsZlibHelper::DecompressGzip");

	UINT uBufSize = nSize * 100;
	LPBYTE pUncompressed;
	do 
	{
		try {
			pUncompressed = NULL;
			pUncompressed = new BYTE [uBufSize];
		}
		catch (...) {}

		if (pUncompressed == NULL)
		{
			uBufSize /= 2;
			if (uBufSize < nSize*3)
			{
				LOGsnl ("Decompress: out of memory");
				return FALSE; 
			}
		}
	}
	while (pUncompressed == NULL);

	
	int err;
    z_stream d_stream;
	
    d_stream.zalloc = Z_NULL;
    d_stream.zfree = Z_NULL;
    d_stream.opaque = Z_NULL;
	
    d_stream.next_in  = pbData;
    d_stream.avail_in = nSize;
	
    d_stream.avail_out = uBufSize;
    d_stream.next_out = pUncompressed;
	
    err = inflateInit2 (&d_stream, 32+MAX_WBITS);
	if (err != 0)
	{
		inflateEnd (&d_stream);
		delete [] pUncompressed;
		return FALSE;
	}
	
    err = inflate (&d_stream, Z_NO_FLUSH);
    if (err == 0 || err == Z_STREAM_END)
    {
        err = inflateEnd (&d_stream);
        if (err != 0)
		{
            delete [] pUncompressed;
			return FALSE;
		}
    }
    else
	{
		inflateEnd (&d_stream);
		delete [] pUncompressed;
		return FALSE;
	}

	*ppUncompressed = pUncompressed;
	*puUncompressedSize = d_stream.total_out;

    return TRUE;
}

int vmsZlibHelper::GetGzipHeaderSize(LPBYTE pbData, UINT nSize)
{
	assert (pbData != NULL);
	assert (nSize != 0);

	UINT nTotalSize = nSize;

	if (nSize < 10)
		return -1;

	if (pbData [0] != GZIP_MAGIC0 || pbData [1] != GZIP_MAGIC1) 
		return -1;

	UINT uMethod = pbData [2];
	UINT uFlags  = pbData [3];

	
	if (uMethod != Z_DEFLATED || (uFlags & FRESERVED) != 0) 
		return -1; 

	
	nSize -= 10;
	pbData += 10;

	if (uFlags & FEXTRA)
	{
		if (nSize < 2)
			return -1;

		UINT nExtraLen = (pbData [1] << 8) | pbData [0];

		if (nSize < (nExtraLen + 2)) 
			return -1;

		nSize -= nExtraLen + 2;
		pbData += nExtraLen + 2;
	}

	if (uFlags & FNAME)
	{
		while (nSize && *pbData)
		{
			nSize--;
			pbData++;
		}
		
		if (nSize == 0 || *pbData) 
			return -1;

		nSize--; 
		pbData++;
	}

	if (uFlags & FCOMMENT)
	{
		while (nSize && *pbData)
		{
			nSize--;
			pbData++;
		}
		
		if (nSize == 0 || *pbData) 
			return -1;
		
		nSize--; 
		pbData++;
	}

	if (uFlags & FHCRC)
	{
		if (nSize < 2)
			return -1;
		nSize -= 2;
		pbData += 2;
	}

	return nTotalSize - nSize;
}

BOOL vmsZlibHelper::DecompressDeflate(LPBYTE pbData, UINT nSize, LPBYTE *ppUncompressed, UINT *puUncompressedSize)
{
	LOGFN ("vmsZlibHelper::DecompressDeflate");

	UINT uBufSize = nSize * 100;
	LPBYTE pUncompressed;
	do 
	{
		try {
			pUncompressed = NULL;
			pUncompressed = new BYTE [uBufSize];
		}
		catch (...) {}
		
		if (pUncompressed == NULL)
		{
			uBufSize /= 2;
			if (uBufSize < nSize*3)
			{
				LOGsnl ("Decompress: out of memory");
				return FALSE; 
			}
		}
	}
	while (pUncompressed == NULL);
	
	int err;
    z_stream d_stream;
	
    d_stream.zalloc = Z_NULL;
    d_stream.zfree = Z_NULL;
    d_stream.opaque = Z_NULL;
	
    d_stream.next_in  = pbData;
    d_stream.avail_in = nSize;
	
    d_stream.avail_out = uBufSize;
    d_stream.next_out = pUncompressed;
	
    err = inflateInit (&d_stream);
	if (err != 0)
	{
		inflateEnd (&d_stream);
		delete [] pUncompressed;
		return FALSE;
	}
	
    err = inflate (&d_stream, Z_NO_FLUSH);
    if (err == 0 || err == Z_STREAM_END)
    {
        err = inflateEnd (&d_stream);
        if (err != 0)
		{
            delete [] pUncompressed;
			return FALSE;
		}
    }
    else
	{
		inflateEnd (&d_stream);
		delete [] pUncompressed;
		return FALSE;
	}

	*ppUncompressed = pUncompressed;
	*puUncompressedSize = d_stream.total_out;
	
    return TRUE;
}
