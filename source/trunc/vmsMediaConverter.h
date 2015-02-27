/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSMEDIACONVERTER_H__1762A7AC_DBF0_48DE_84F5_ED51698BCC51__INCLUDED_)
#define AFX_VMSMEDIACONVERTER_H__1762A7AC_DBF0_48DE_84F5_ED51698BCC51__INCLUDED_

#include "vmsDLL.h"	
#if _MSC_VER > 1000
#pragma once
#endif 

class vmsMediaConverter  
{
public:
	static BOOL ConvertMedia(LPCSTR pszSrcFile, LPCSTR pszDstFile, LPCSTR pszDstFormat,
						  LPCSTR pszAudioCodec, int nAudioChannels, int nAudioBitrate, 
						  int nAudioRate,
						  LPCSTR pszVideoCodec, int nVideoBitrate, int nVideoFrameRate,
						  int nVideoFrameWidth, int nVideoFrameHeight,
						  int* pnProgress, BOOL *pbCancel);
	vmsMediaConverter();
	virtual ~vmsMediaConverter();

protected:
	static void Initialize();
	static void Shutdown();
	static vmsDLL m_dll;
	static long m_cDllRefs;
};

#endif 
