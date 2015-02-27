/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSIMAGE_CTXFREE_H__387C75BC_AD47_430E_95FF_8B90F9C49F7B__INCLUDED_)
#define AFX_VMSIMAGE_CTXFREE_H__387C75BC_AD47_430E_95FF_8B90F9C49F7B__INCLUDED_

#include "vmsImage.h"	
#if _MSC_VER > 1000
#pragma once
#endif 

class vmsImage_CtxFree  
{
public:
	
	HRESULT Load (LPCSTR pszFile);
	
	int get_FrameCount();
	
	void Draw(HDC dc, RECT &rc);
	void set_CurrentFrame (int iIndex);
	
	int get_FrameDelay (int iIndex);
	
	SIZE get_Size();
	
	void Free();
	
	BOOL is_Loaded();
	
	vmsImage_CtxFree();
	virtual ~vmsImage_CtxFree();

protected:
	void DrawBitmap (HDC dc, int iBitmap, POINT pt);
	int m_iCurrentFrame;
	
	int m_cFrames;
	
	void CreateImagesBitmaps();
	
	vmsImage m_Image;
	std::vector <HBITMAP> m_vBitmaps;
	
	std::vector <SIZE> m_vSizes;
	std::vector <int> m_vFrameDelays;
};

#endif 
