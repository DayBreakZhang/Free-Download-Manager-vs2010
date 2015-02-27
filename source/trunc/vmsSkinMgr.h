/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSSKINMGR_H__3007DDD4_437C_4D37_B1A8_88EA19D78531__INCLUDED_)
#define AFX_VMSSKINMGR_H__3007DDD4_437C_4D37_B1A8_88EA19D78531__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

struct vmsSkinInfo
{
	CString		strName;	
	int			tbSizeX;	
	int			tbSizeY;	
	BOOL		tbUseAlpha;	
	CString		strSkinFolder;	
	int			nFDMBuild;	

	vmsSkinInfo () {
		tbSizeX = tbSizeY = 32;
		tbUseAlpha = TRUE;
		
		
		nFDMBuild = 335;	
		
	}
};

#define SM_ALLOWICONS		1

#define SM_ALLOWBITMAPS		2

class vmsSkinMgr  
{
public:
	COLORREF getLinkTextColor () const;
	BOOL tbUseAlpha_ForAllPluginMenuImages();
	
	vmsSkinInfo* get_Skin (int iIndex);
	
	int get_Current();
	
	int get_Count();
	
	
	HICON icon (UINT nID, int cx = 0, int cy = 0);
	
	BOOL tbUseAlpha();
	
	int tbSizeY();
	int tbSizeX();
	
	
	void Initialize();
	HBITMAP bmp (UINT nID);
	void set_CurrentSkin (int iSkin = -1 );
	
	
	void Scan ();
	vmsSkinMgr();
	virtual ~vmsSkinMgr();

protected:
	DWORD m_dwFlags;	
	
	HICON icon_x(UINT nID, LPCSTR pszName, int cx = 0, int cy = 0);
	
	HBITMAP bmp_x (UINT nID, LPCSTR pszName);
	HINSTANCE m_hInst;	
	int m_nCurrSkin;	
	
	void Scan_TryFolder (LPCSTR pszFolder);
	
	fs::list <vmsSkinInfo> m_vList;

};

#endif 
