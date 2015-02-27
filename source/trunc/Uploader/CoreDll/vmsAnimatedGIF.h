/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSANIMATEDGIF_H__8893A64A_E91C_4E1D_8F5E_768AE18C7CB8__INCLUDED_)
#define AFX_VMSANIMATEDGIF_H__8893A64A_E91C_4E1D_8F5E_768AE18C7CB8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#pragma warning (push, 1)
#include <vector>
#pragma warning (pop)

class vmsAnimatedGIF  
{
public:
struct TFrame    
{
	SIZE     m_frameSize;
	SIZE     m_frameOffset;
	UINT     m_nDelay;     
	UINT     m_nDisposal;  
};

	TFrame* get_FrameInfo (int iIndex);
	
	
	
	int SaveGIFFrames (LPCSTR pszFileTemplate);

#pragma pack(1)   

enum GIFBlockTypes
{
	BLOCK_UNKNOWN,
	BLOCK_APPEXT,
	BLOCK_COMMEXT,
	BLOCK_CONTROLEXT,
	BLOCK_PLAINTEXT,
	BLOCK_IMAGE,
	BLOCK_TRAILER
};

enum ControlExtValues 
{
	GCX_PACKED_DISPOSAL,  
	GCX_PACKED_USERINPUT,
	GCX_PACKED_TRANSPCOLOR
};

enum LSDPackedValues  
{
	LSD_PACKED_GLOBALCT,
	LSD_PACKED_CRESOLUTION,
	LSD_PACKED_SORT,
	LSD_PACKED_GLOBALCTSIZE
};

enum IDPackedValues   
{
	ID_PACKED_LOCALCT,
	ID_PACKED_INTERLACE,
	ID_PACKED_SORT,
	ID_PACKED_LOCALCTSIZE
};

struct TGIFHeader       
{
	char m_cSignature[3]; 
						  
	char m_cVersion[3];	
						
};

struct TGIFLSDescriptor 
{
	WORD m_wWidth;	
	WORD m_wHeight; 

	unsigned char m_cPacked;      

	unsigned char m_cBkIndex;     
	unsigned char m_cPixelAspect; 
	inline int GetPackedValue(enum LSDPackedValues Value);
};

struct TGIFAppExtension 
{
	unsigned char m_cExtIntroducer; 
	unsigned char m_cExtLabel; 
	unsigned char m_cBlockSize; 
	char m_cAppIdentifier[8];   
	char m_cAppAuth[3];  
};

struct TGIFControlExt 
{
	unsigned char m_cExtIntroducer; 
	unsigned char m_cControlLabel;  
	unsigned char m_cBlockSize; 
	unsigned char m_cPacked;    
	WORD m_wDelayTime;	
	unsigned char m_cTColorIndex; 
	unsigned char m_cBlockTerm;   
public:
	inline int GetPackedValue(enum ControlExtValues Value);
};

struct TGIFCommentExt  
{
	unsigned char m_cExtIntroducer; 
	unsigned char m_cCommentLabel;  
};

struct TGIFPlainTextExt 
{
	unsigned char m_cExtIntroducer;  
	unsigned char m_cPlainTextLabel; 
	unsigned char m_cBlockSize; 
	WORD m_wLeftPos;    
	WORD m_wTopPos;     
	WORD m_wGridWidth;  
	WORD m_wGridHeight; 
	unsigned char m_cCellWidth;  
	unsigned char m_cCellHeight; 
	unsigned char m_cFgColor; 
	unsigned char m_cBkColor; 
};

struct TGIFImageDescriptor 
{
	unsigned char m_cImageSeparator; 
	WORD m_wLeftPos; 
	WORD m_wTopPos;  
	WORD m_wWidth;   
	WORD m_wHeight;  
	unsigned char m_cPacked; 
	inline int GetPackedValue(enum IDPackedValues Value);
};

#pragma pack() 

	
	
	BOOL Load (LPCSTR pszFile);
	
	BOOL Load(HGLOBAL hGlobal, DWORD dwSize);

	vmsAnimatedGIF();
	virtual ~vmsAnimatedGIF();

protected:
	
	std::vector <TFrame> m_vFramesInfo;
	
	BOOL WriteDataOnDisk (LPCSTR pszFile, HGLOBAL hData, DWORD dwSize);
	
	BOOL Load();
	HGLOBAL m_hGIF;	
	
	BOOL m_bAutoFree;
	
	HGLOBAL GetNextGraphicBlock (UINT *pBlockLen, UINT *pDelay, SIZE *pBlockSize, SIZE *pBlockOffset, UINT *pDisposal);
	UINT GetSubBlocksLen (UINT nStartingOffset);
	int GetNextBlockLen();
	BOOL SkipNextBlock();
	GIFBlockTypes GetNextBlock();
	BOOL SkipNextGraphicBlock();
	void ResetDataPointer();
	void Free();
	LPBYTE	m_pRawData;	
	TGIFHeader* m_pGIFHeader;
	TGIFLSDescriptor* m_pGIFLSDescriptor;
	SIZE m_PictureSize;
	COLORREF m_clrBackground;
	UINT m_nDataSize;
	UINT m_nCurrOffset;
	UINT m_nGlobalCTSize;
};

#endif 
