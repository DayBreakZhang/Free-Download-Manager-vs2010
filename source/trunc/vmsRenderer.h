/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSRENDERER_H__DB28ADC5_9D53_4826_8DAA_3F22AD6993EC__INCLUDED_)
#define AFX_VMSRENDERER_H__DB28ADC5_9D53_4826_8DAA_3F22AD6993EC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class vmsRenderer  
{
public:
	
	CDC* Start (CDC* dc, RECT *rc);
	
	void End();

	
	
	
	
	
	
	
	
	

	vmsRenderer();
	virtual ~vmsRenderer();

protected:
	
	CDC* m_dcDst;
	
	CDC m_dcDraw;
	
	CBitmap m_bmDraw;
	
	CRect m_rcDraw;
	
	HGDIOBJ m_hbmOld;
};

#endif 
