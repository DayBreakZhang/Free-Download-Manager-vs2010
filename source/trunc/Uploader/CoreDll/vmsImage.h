/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSIMAGE_H__23C3F1D7_011F_4A56_B3CF_025736AEE582__INCLUDED_)
#define AFX_VMSIMAGE_H__23C3F1D7_011F_4A56_B3CF_025736AEE582__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include <IImgCtx.h>
#pragma warning (push, 1)
#include <vector>
#pragma warning (pop)

class vmsImage  
{
public:
	
	HRESULT Load (LPCSTR pszFile);
	
	int get_FrameCount();
	
	void Draw (HDC dc, RECT& rc);
	void set_CurrentFrame (int iIndex);
	
	int get_FrameDisp (int iIndex);
	
	UINT get_FrameDelay (int iIndex);
	
	BOOL is_Loaded();
	
	CSize get_Size();
	
	void Free();
	
	vmsImage();
	virtual ~vmsImage();

protected:
	
	IImgCtx* LoadImage (LPCSTR pszFile);
	IImgCtx* m_pImage;	
	
	std::vector <IImgCtx*> m_vFrames;
	std::vector <int> m_vFrameDelays;
	std::vector <int> m_vFrameDisps;
};

#endif 
