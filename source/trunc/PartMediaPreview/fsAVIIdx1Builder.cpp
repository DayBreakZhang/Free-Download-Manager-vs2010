/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#define WINVER 0x501
#define _WIN32_IE 0x501
#define _WIN32_WINNT 0x501

#include "fsAVIIdx1Builder.h"
#include <fsString.h>
#include "../system.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

fsAVIIdx1Builder::fsAVIIdx1Builder()
{

}

fsAVIIdx1Builder::~fsAVIIdx1Builder()
{

}

inline BOOL Read (HANDLE hFile, LPVOID pBuf, DWORD dwSize)
{
	return ReadFile (hFile, pBuf, dwSize, &dwSize, NULL);
}

inline BOOL Read (HANDLE hFile, LPSTR pStr, DWORD dwSize)
{
	pStr [dwSize] = 0;
	return ReadFile (hFile, pStr, dwSize, &dwSize, NULL);
}

inline BOOL Write (HANDLE hFile, LPVOID pBuf, DWORD dwSize)
{
	return WriteFile (hFile, pBuf, dwSize, &dwSize, NULL);
}

inline void Seek (HANDLE hFile, DWORD dw)
{
	SetFilePointer (hFile, dw, NULL, FILE_BEGIN);
}

inline DWORD GetFilePos (HANDLE hFile)
{
	return SetFilePointer (hFile, 0, NULL, FILE_CURRENT);
}

inline DWORD GetFileSize (HANDLE hFile)
{
	return ::GetFileSize (hFile, NULL);
}

typedef struct {
    DWORD  ckid;
    DWORD  dwFlags;
    DWORD  dwChunkOffset;
    DWORD  dwChunkLength;
} AVIINDEXENTRY;

BOOL fsAVIIdx1Builder::BuildIdx1(HANDLE in, HANDLE out, UINT64 uInMaxPos)
{
	fsString strChunk;
	DWORD dw = 0;

	if (uInMaxPos == _UI64_MAX)
	{
		DWORD dw1, dw2;
		dw1 = GetFileSize (in, &dw2);
		uInMaxPos = UINT64 (dw1) | UINT64 (dw2) << 32;
	}

	strChunk.alloc (4);
	
	UINT64 uPos = 16;
	fsSetFilePointer (in, uPos, FILE_BEGIN);

	
	Read (in, &dw, 4);
	uPos += 4+dw;

	fsSetFilePointer (in, uPos, FILE_BEGIN);

	do
	{
		
		Read (in, strChunk, 4);
		Read (in, &dw, 4);
		uPos += 8;

		if (strChunk == "JUNK" || strChunk == "JUNQ")
		{
			uPos += dw;
			fsSetFilePointer (in, uPos, FILE_BEGIN);
			continue;
		}

		if (strChunk != "LIST")
			return FALSE; 

		m_uIdx1Start = uPos + dw;

		Read (in, strChunk, 4);
		uPos += 4;

		if (strChunk != "movi")
		{
			uPos += dw-4;
			fsSetFilePointer (in, uPos, FILE_BEGIN);
			continue;
		}
	}
	while (strChunk != "movi");

	Write (out, "idx1", 4);
	Write (out, &dw, 4); 

	DWORD dwOffset = 4;

	do
	{
		for (int i = 0; i < 16; i++)
		{
			Read (in, strChunk, 4);
			if (stricmp (strChunk+2, "wb") == 0 ||
					stricmp (strChunk+2, "dc") == 0 ||
					stricmp (strChunk+2, "db") == 0)
				break;

			fsSetFilePointer (in, ++uPos, FILE_BEGIN);	
			dwOffset++;
		}

		if (stricmp (strChunk+2, "wb") &&
				stricmp (strChunk+2, "dc") &&
				stricmp (strChunk+2, "db"))
			return FALSE;

		Read (in, &dw, 4);
		uPos += 8;

		if (uPos + dw > uInMaxPos)
			break;

		AVIINDEXENTRY e;
		e.ckid = *((LPDWORD)(LPSTR)strChunk);
		e.dwChunkLength = dw;
		e.dwChunkOffset = dwOffset;
		e.dwFlags = 0;
		if (strChunk == "LIST")
			e.dwFlags |= 0x1; 

		Write (out, &e, sizeof (e));

		uPos += dw;
		dwOffset += 8 + dw;
		fsSetFilePointer (in, uPos, FILE_BEGIN);
	}
	while (uPos < m_uIdx1Start);

	dw = GetFileSize (out) - 8;
	Seek (out, 4);
	Write (out, &dw, 4);

	return TRUE;
}

UINT64 fsAVIIdx1Builder::Get_Idx1StartPosition()
{
	return m_uIdx1Start;
}
