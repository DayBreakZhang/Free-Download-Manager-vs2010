/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSZLIBHELPER_H__2A49F334_B108_4A46_A57E_295BB822879A__INCLUDED_)
#define AFX_VMSZLIBHELPER_H__2A49F334_B108_4A46_A57E_295BB822879A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class vmsZlibHelper  
{
public:
	static BOOL DecompressDeflate(LPBYTE pbData, UINT nSize, LPBYTE *ppUncompressed, UINT *puUncompressedSize);
	static BOOL DecompressGzip(LPBYTE pbData, UINT nSize, LPBYTE *ppUncompressed, UINT *puUncompressedSize);
	vmsZlibHelper();
	virtual ~vmsZlibHelper();

protected:
	enum 
	{
		FTEXT = 0x01,
		FHCRC = 0x02,
		FEXTRA = 0x04,
		FNAME = 0x08,
		FCOMMENT = 0x10,
		FRESERVED = 0xe0,
			
		GZIP_MAGIC0 = 0x1f,
		GZIP_MAGIC1 = 0x8b,
	};

protected:
	static int GetGzipHeaderSize (LPBYTE pbData, UINT nSize);
};

#endif 
