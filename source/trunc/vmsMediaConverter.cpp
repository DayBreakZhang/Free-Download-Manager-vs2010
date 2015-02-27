/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "vmsMediaConverter.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

vmsDLL vmsMediaConverter::m_dll;
long vmsMediaConverter::m_cDllRefs = 0;

vmsMediaConverter::vmsMediaConverter()
{
	
}

vmsMediaConverter::~vmsMediaConverter()
{

}

BOOL vmsMediaConverter::ConvertMedia(LPCSTR pszSrcFile, LPCSTR pszDstFile, LPCSTR pszDstFormat,
						  LPCSTR pszAudioCodec, int nAudioChannels, int nAudioBitrate, 
						  int nAudioRate,
						  LPCSTR pszVideoCodec, int nVideoBitrate, int nVideoFrameRate,
						  int nVideoFrameWidth, int nVideoFrameHeight,
						  int* pnProgress, BOOL *pbCancel)
{
	enum ConvertResult
	{
		CR_OK						= 0,
		CR_INVALID_ARGS				= 1,
		CR_DLL_RELOAD_IS_REQUIRED	= 2,
		CR_FAILED					= 3,
	};

	static vmsCriticalSectionEx _cs;

	if (pbCancel)
	{
		while (_cs.isLocked () && *pbCancel == FALSE)
			Sleep (200);
		if (*pbCancel)
			return FALSE;
	}

	_cs.Lock ();

	Initialize ();

	BOOL bRes = FALSE;
	
	typedef BOOL (*FNCM)(LPCSTR pszSrcFile, LPCSTR pszDstFile, LPCSTR pszDstFormat,
						  LPCSTR pszAudioCodec, int nAudioChannels, int nAudioBitrate, 
						  int nAudioRate,
						  LPCSTR pszVideoCodec, int nVideoBitrate, int nVideoFrameRate,
						  int nVideoFrameWidth, int nVideoFrameHeight,
						  int* pnProgress, BOOL *pbCancel);

	typedef int (*FNC)(LPCSTR pszSrcFile, LPCSTR pszDstFile, LPCSTR pszDstFormat,
						  LPCSTR pszAudioCodec, int nAudioChannels, int nAudioBitrate, 
						  int nAudioRate,
						  LPCSTR pszVideoCodec, int nVideoBitrate, int nVideoFrameRate,
						  int nVideoFrameWidth, int nVideoFrameHeight, int nThreads,
						  int* pnProgress, BOOL *pbCancel, int *pnFfmpegResult);

	FNC pfn = (FNC) m_dll.GetProcAddress ("Convert");
	if (pfn)
	{
		int nRes = pfn (pszSrcFile, pszDstFile, pszDstFormat, pszAudioCodec, nAudioChannels,
			nAudioBitrate, nAudioRate, pszVideoCodec, nVideoBitrate, nVideoFrameRate,
			nVideoFrameWidth, nVideoFrameHeight, 1, pnProgress, pbCancel, NULL);
		if (nRes == CR_DLL_RELOAD_IS_REQUIRED)
			MessageBox (*AfxGetApp ()->m_pMainWnd, "Failed to convert media file. Please try restart FDM.\nError: -2.\nPlease report us about this error.", LS (L_ERROR), MB_ICONERROR);
		bRes = nRes == CR_OK;
		if (pbCancel && *pbCancel)
			bRes = FALSE;
	}
	else 
	{
		FNCM pfn = (FNCM) m_dll.GetProcAddress ("ConvertMediaFile"); 
		if (pfn)
		{
			bRes = pfn (pszSrcFile, pszDstFile, pszDstFormat, pszAudioCodec, nAudioChannels,
				nAudioBitrate, nAudioRate, pszVideoCodec, nVideoBitrate, nVideoFrameRate,
				nVideoFrameWidth, nVideoFrameHeight, pnProgress, pbCancel);
		}
	}

	Shutdown ();

	if (!bRes)
		DeleteFile (pszDstFile);

	_cs.Unlock ();

	return bRes;
}

void vmsMediaConverter::Initialize()
{
	InterlockedIncrement (&m_cDllRefs);

	if (m_dll.is_Loaded () == false)
	{
		m_dll.Load ("mediaconverter.dll");
		typedef void (*FNI)();
		FNI pfn = (FNI) m_dll.GetProcAddress ("Initialize");
		if (pfn)
			pfn ();
	}
}

void vmsMediaConverter::Shutdown()
{
	InterlockedDecrement (&m_cDllRefs);

	if (m_cDllRefs == 0)
	{
		typedef void (*FNS)();
		FNS pfn = (FNS) m_dll.GetProcAddress ("Shutdown");
		if (pfn)
			pfn ();
		m_dll.Free ();
	}
}
