/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "vmsAnimatedGIF.h"
#include <math.h>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

vmsAnimatedGIF::vmsAnimatedGIF()
{
	m_hGIF = NULL;
	m_bAutoFree = FALSE;
	m_nDataSize = 0;
	m_nCurrOffset = 0;
	m_pGIFHeader = NULL;
	m_pGIFLSDescriptor = NULL;
}

vmsAnimatedGIF::~vmsAnimatedGIF()
{
	Free ();
}

BOOL vmsAnimatedGIF::Load(LPCSTR pszFile)
{
	HANDLE hFile = CreateFile (pszFile, GENERIC_READ, FILE_SHARE_READ,
		NULL, OPEN_EXISTING, 0, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
		return FALSE;

	DWORD dwSize;

	dwSize = GetFileSize (hFile, NULL);
	m_hGIF = GlobalAlloc (GMEM_MOVEABLE | GMEM_NODISCARD, dwSize);
	if (m_hGIF == NULL)
		return FALSE;
	m_bAutoFree = TRUE;

	char *pData = reinterpret_cast<char*>(GlobalLock(m_hGIF));
	if (!pData)
	{
		CloseHandle (hFile);
		return FALSE;
	};

	DWORD dw;
	if (FALSE == ReadFile (hFile, pData, dwSize, &dw, NULL))
	{
		CloseHandle (hFile);
		return FALSE;
	}

	GlobalUnlock (m_hGIF);
	CloseHandle (hFile);

	m_nDataSize = dwSize;
	return Load ();
}

BOOL vmsAnimatedGIF::Load(HGLOBAL hGlobal, DWORD dwSize)
{
	Free ();
	m_hGIF = hGlobal;
	m_nDataSize = dwSize;
	return Load ();
}

void vmsAnimatedGIF::Free()
{
	if (m_hGIF)
	{
		if (m_bAutoFree)
		{
			GlobalFree (m_hGIF);
			m_bAutoFree = FALSE;
		}
		m_hGIF = NULL;
	}
	m_vFramesInfo.clear ();
}

void vmsAnimatedGIF::ResetDataPointer()
{
	
	m_nCurrOffset = 
		sizeof(TGIFHeader)+sizeof(TGIFLSDescriptor)+m_nGlobalCTSize;
}

BOOL vmsAnimatedGIF::SkipNextGraphicBlock()
{
	if (!m_pRawData) return FALSE;

	

	enum GIFBlockTypes nBlock;

	nBlock = GetNextBlock();

	while ((nBlock != BLOCK_CONTROLEXT) &&
		   (nBlock != BLOCK_IMAGE) &&
		   (nBlock != BLOCK_PLAINTEXT) &&
		   (nBlock != BLOCK_UNKNOWN) &&
		   (nBlock != BLOCK_TRAILER) )
	{
		if (!SkipNextBlock()) return NULL;
		
		nBlock = GetNextBlock();
	};

	if ((nBlock == BLOCK_UNKNOWN) ||
		(nBlock == BLOCK_TRAILER))
		return FALSE;

	

	if (GetNextBlockLen() <= 0) return FALSE;

	if (nBlock == BLOCK_CONTROLEXT)
	{
		if (!SkipNextBlock()) return FALSE;
		nBlock = GetNextBlock();

		
		while ((nBlock != BLOCK_IMAGE) &&
			   (nBlock != BLOCK_PLAINTEXT) &&
			   (nBlock != BLOCK_UNKNOWN) &&
			   (nBlock != BLOCK_TRAILER) )
		{
			if (!SkipNextBlock()) return NULL;
			nBlock = GetNextBlock();
		};

		if ((nBlock == BLOCK_UNKNOWN) ||
			(nBlock == BLOCK_TRAILER))
			return FALSE;
	};

	
	if (!SkipNextBlock()) return FALSE;

	return TRUE;
}

vmsAnimatedGIF::GIFBlockTypes vmsAnimatedGIF::GetNextBlock()
{
	switch(m_pRawData[m_nCurrOffset])
	{
	case 0x21:
	
		switch(m_pRawData[m_nCurrOffset+1])
		{
		case 0x01:
		
			return BLOCK_PLAINTEXT;
			break;

		case 0xF9:
		
			return BLOCK_CONTROLEXT;
			break;

		case 0xFE:
		
			return BLOCK_COMMEXT;
			break;

		case 0xFF:
		
			return BLOCK_APPEXT;
			break;
		};
		break;
	
	case 0x3B:
	
		return BLOCK_TRAILER;
		break;

	case 0x2C:
	
		return BLOCK_IMAGE;
		break;
	};

	return BLOCK_UNKNOWN;
}

BOOL vmsAnimatedGIF::SkipNextBlock()
{
	if (!m_pRawData) return FALSE;

	int nLen = GetNextBlockLen();
	if ((nLen <= 0) || ((m_nCurrOffset+nLen) > m_nDataSize))
		return FALSE;

	m_nCurrOffset += nLen;
	return TRUE;
}

int vmsAnimatedGIF::GetNextBlockLen()
{
	GIFBlockTypes nBlock = GetNextBlock();

	int nTmp;

	switch(nBlock)
	{
	case BLOCK_UNKNOWN:
		return -1;
		break;

	case BLOCK_TRAILER:
		return 1;
		break;

	case BLOCK_APPEXT:
		nTmp = GetSubBlocksLen(m_nCurrOffset+sizeof(TGIFAppExtension));
		if (nTmp > 0)
			return sizeof(TGIFAppExtension)+nTmp;
		break;

	case BLOCK_COMMEXT:
		nTmp = GetSubBlocksLen(m_nCurrOffset+sizeof(TGIFCommentExt));
		if (nTmp > 0)
			return sizeof(TGIFCommentExt)+nTmp;
		break;

	case BLOCK_CONTROLEXT:
		return sizeof(TGIFControlExt);
		break;

	case BLOCK_PLAINTEXT:
		nTmp = GetSubBlocksLen(m_nCurrOffset+sizeof(TGIFPlainTextExt));
		if (nTmp > 0)
			return sizeof(TGIFPlainTextExt)+nTmp;
		break;

	case BLOCK_IMAGE:
		TGIFImageDescriptor *pIDescr = 
			reinterpret_cast<TGIFImageDescriptor *> (&m_pRawData[m_nCurrOffset]);
		
		
		
		int nLCTSize = (int)
			(pIDescr->GetPackedValue(ID_PACKED_LOCALCT)*3*
			(double)pow((long double)2,(long double)(pIDescr->GetPackedValue(ID_PACKED_LOCALCTSIZE)+1)));

		int nTmp = GetSubBlocksLen(m_nCurrOffset+
			sizeof(TGIFImageDescriptor) + nLCTSize + 1);
		if (nTmp > 0)
			return sizeof(TGIFImageDescriptor) + nLCTSize + 1 + nTmp;
		break;
	};

	return 0;
}

UINT vmsAnimatedGIF::GetSubBlocksLen(UINT nStartingOffset)
{
	UINT nRet = 0;
	UINT nCurOffset = nStartingOffset;
	
	while (m_pRawData[nCurOffset] != 0)
	{
		nRet += m_pRawData[nCurOffset]+1;
		nCurOffset += m_pRawData[nCurOffset]+1;
	};

	return nRet+1;
}

inline int vmsAnimatedGIF::TGIFControlExt::GetPackedValue(enum vmsAnimatedGIF::ControlExtValues Value)
{
	int nRet = (int)m_cPacked;
	switch (Value)
	{
	case GCX_PACKED_DISPOSAL:
		nRet = (nRet & 28) >> 2;
		break;

	case GCX_PACKED_USERINPUT:
		nRet = (nRet & 2) >> 1;
		break;

	case GCX_PACKED_TRANSPCOLOR:
		nRet &= 1;
		break;
	};

	return nRet;
}

inline int vmsAnimatedGIF::TGIFLSDescriptor::GetPackedValue(enum LSDPackedValues Value)
{
	int nRet = (int)m_cPacked;

	switch (Value)
	{
	case LSD_PACKED_GLOBALCT:
		nRet = nRet >> 7;
		break;

	case LSD_PACKED_CRESOLUTION:
		nRet = ((nRet & 0x70) >> 4) + 1;
		break;

	case LSD_PACKED_SORT:
		nRet = (nRet & 8) >> 3;
		break;

	case LSD_PACKED_GLOBALCTSIZE:
		nRet &= 7;
		break;
	};

	return nRet;
}

inline int vmsAnimatedGIF::TGIFImageDescriptor::GetPackedValue(enum IDPackedValues Value)
{
	int nRet = (int)m_cPacked;

	switch (Value)
	{
	case ID_PACKED_LOCALCT:
		nRet >>= 7;
		break;

	case ID_PACKED_INTERLACE:
		nRet = ((nRet & 0x40) >> 6);
		break;

	case ID_PACKED_SORT:
		nRet = (nRet & 0x20) >> 5;
		break;

	case ID_PACKED_LOCALCTSIZE:
		nRet &= 7;
		break;
	};

	return nRet;
}

HGLOBAL vmsAnimatedGIF::GetNextGraphicBlock(UINT *pBlockLen, UINT *pDelay, SIZE *pBlockSize, SIZE *pBlockOffset, UINT *pDisposal)
{
	if (!m_pRawData) return NULL;

	

	*pDisposal = 0;
	enum GIFBlockTypes nBlock;
	nBlock = GetNextBlock();

	while (
		(nBlock != BLOCK_CONTROLEXT) &&
		(nBlock != BLOCK_IMAGE) &&
		(nBlock != BLOCK_PLAINTEXT) &&
		(nBlock != BLOCK_UNKNOWN) &&
		(nBlock != BLOCK_TRAILER)
		)
	{
		if (!SkipNextBlock()) return NULL;
		nBlock = GetNextBlock();
	};

	if ((nBlock == BLOCK_UNKNOWN) ||
		(nBlock == BLOCK_TRAILER))
		return NULL;

	

	int nStart = m_nCurrOffset;
	int nBlockLen = GetNextBlockLen();

	if (nBlockLen <= 0) return NULL;

	if (nBlock == BLOCK_CONTROLEXT)
	{
		
		TGIFControlExt *pControl = 
			reinterpret_cast<TGIFControlExt *> (&m_pRawData[m_nCurrOffset]);
		
		*pDelay = pControl->m_wDelayTime;
		
		*pDisposal = pControl->GetPackedValue(GCX_PACKED_DISPOSAL);

		if (!SkipNextBlock()) return NULL;
		nBlock = GetNextBlock();
		
		
		
		
		while (
			(nBlock != BLOCK_IMAGE) &&
			(nBlock != BLOCK_PLAINTEXT) &&
			(nBlock != BLOCK_UNKNOWN) &&
			(nBlock != BLOCK_TRAILER)
			)
		{
			if (!SkipNextBlock()) return NULL;
			nBlock = GetNextBlock();
			nBlockLen += GetNextBlockLen();
		};

		if ((nBlock == BLOCK_UNKNOWN) || (nBlock == BLOCK_TRAILER))
			return NULL;
		nBlockLen += GetNextBlockLen();
	}
	else
		*pDelay = (UINT)-1; 

	if (nBlock == BLOCK_IMAGE)
	{
		
		TGIFImageDescriptor *pImage = 
			reinterpret_cast<TGIFImageDescriptor *> (&m_pRawData[m_nCurrOffset]);
		pBlockSize->cx = pImage->m_wWidth;
		pBlockSize->cy = pImage->m_wHeight;
		pBlockOffset->cx = pImage->m_wLeftPos;
		pBlockOffset->cy = pImage->m_wTopPos;
	};

	if (!SkipNextBlock()) return NULL;

	HGLOBAL hGlobal = GlobalAlloc(GMEM_FIXED,
		sizeof(TGIFHeader) +
		sizeof(TGIFLSDescriptor) +
		m_nGlobalCTSize +
		nBlockLen + 
		1);  

	if (!hGlobal) return NULL;

	int nOffset = 0; 

	
	unsigned char *pGlobal = reinterpret_cast<unsigned char *> (hGlobal);

	CopyMemory(pGlobal,m_pRawData, 
		sizeof(TGIFHeader)+sizeof(TGIFLSDescriptor)+m_nGlobalCTSize);
	nOffset += sizeof(TGIFHeader)+sizeof(TGIFLSDescriptor)+m_nGlobalCTSize;

	CopyMemory(pGlobal + nOffset,&m_pRawData[nStart], nBlockLen);
	nOffset += nBlockLen;

	pGlobal[nOffset] = 0x3B; 
	nOffset++;

	*pBlockLen = nOffset;

	return hGlobal;
}

int vmsAnimatedGIF::SaveGIFFrames(LPCSTR pszFileTemplate)
{
	UINT nBlockLen;
	HGLOBAL hFrameData;
	UINT nCurFrame = 0;
	TFrame frame;

	m_pRawData = (LPBYTE) GlobalLock (m_hGIF);
	m_vFramesInfo.clear ();

	ResetDataPointer();
	while ((hFrameData = GetNextGraphicBlock(&nBlockLen, 
				&frame.m_nDelay, &frame.m_frameSize,
				&frame.m_frameOffset, &frame.m_nDisposal)) != NULL)
	{
		char szFile [MY_MAX_PATH];
		wsprintf (szFile, pszFileTemplate, nCurFrame);
		if (FALSE == WriteDataOnDisk (szFile, hFrameData, nBlockLen))
			break;

		m_vFramesInfo.push_back (frame);
		nCurFrame++;
	}

	GlobalUnlock (m_hGIF);
	return nCurFrame;
}

BOOL vmsAnimatedGIF::Load()
{
	m_pRawData = (LPBYTE) GlobalLock (m_hGIF);
	if (m_pRawData == NULL)
		return FALSE;
	
	m_pGIFHeader = (TGIFHeader*) m_pRawData;

	if ((memcmp(&m_pGIFHeader->m_cSignature,"GIF", 3) != 0) &&
			((memcmp(&m_pGIFHeader->m_cVersion,"87a", 3) != 0) ||
		(memcmp(&m_pGIFHeader->m_cVersion,"89a", 3) != 0)) )
	{
		GlobalUnlock (m_hGIF);
		return FALSE;
	}

	m_pGIFLSDescriptor = (TGIFLSDescriptor*) (m_pRawData + sizeof (TGIFHeader));
	
	if (m_pGIFLSDescriptor->GetPackedValue(LSD_PACKED_GLOBALCT) == 1)
	{
		
		
		
		m_nGlobalCTSize = static_cast<int>
			(3* (double)(pow((long double)2, (long double)(m_pGIFLSDescriptor->GetPackedValue(LSD_PACKED_GLOBALCTSIZE)+1))));
		
		unsigned char *pBkClr = m_pRawData + sizeof(TGIFHeader) + 
			sizeof(TGIFLSDescriptor) + 3*m_pGIFLSDescriptor->m_cBkIndex;
		m_clrBackground = RGB(pBkClr[0],pBkClr[1],pBkClr[2]);
	};

	
	m_PictureSize.cx = m_pGIFLSDescriptor->m_wWidth;
	m_PictureSize.cy = m_pGIFLSDescriptor->m_wHeight;

	
	UINT nFrameCount=0;
	ResetDataPointer();
	while (SkipNextGraphicBlock())
		nFrameCount++;

	GlobalUnlock (m_hGIF);

	if (nFrameCount < 2) 
	{
		m_pRawData = NULL;
		return FALSE;
	};

	return TRUE;
}

BOOL vmsAnimatedGIF::WriteDataOnDisk(LPCSTR pszFile, HGLOBAL hData, DWORD dwSize)
{
	HANDLE hFile = CreateFile (pszFile, GENERIC_WRITE, 0, NULL,
		CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
		return FALSE;

	LPBYTE pData = (LPBYTE) GlobalLock (hData);
	if (pData == NULL)
		return FALSE;

	DWORD dw;
	BOOL b = WriteFile (hFile, pData, dwSize, &dw, NULL);
	
	CloseHandle (hFile);
	GlobalUnlock (hData);

	return b;
}

vmsAnimatedGIF::TFrame* vmsAnimatedGIF::get_FrameInfo(int iIndex)
{
	return &m_vFramesInfo [iIndex];
}
