/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSFLASHHELPER_H__946677FB_A944_4239_BB78_C359FB68A392__INCLUDED_)
#define AFX_VMSFLASHHELPER_H__946677FB_A944_4239_BB78_C359FB68A392__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include <comdef.h>
#include <vector>
typedef std::vector <IDispatchPtr> FLASHLIST, *LPFLASHLIST;
#include <fsString.h>

class vmsFlashHelper  
{
public:
	static void GetFlashInfo (IDispatchPtr spFlash, IHTMLDocument2Ptr spDoc, fsString* pstrMovieURL, fsString* pstrMovieHTML);
	
	
	static BOOL is_FlashElement (IHTMLElementPtr spEl, IDispatchPtr& spFlashDisp, IDispatchPtr &spFlashObject);
	static void GetFlashMoviesObjList (IHTMLDocument2Ptr spDoc, LPFLASHLIST pv, BOOL bIncludingFrames = TRUE);
	static void GetFlashMoviesList (IHTMLDocument2Ptr spDoc, std::vector <fsString>* pslURLs, std::vector <fsString>* pslHTMLs = NULL);
	static void SaveFlashMovies(IHTMLDocument2Ptr spDoc, LPCSTR pszFolder, BOOL bIncludingFrames = TRUE);
	static void DisableFlashMovies (IHTMLDocument2Ptr spDoc, BOOL bIncludingFrames = TRUE);
	vmsFlashHelper();
	virtual ~vmsFlashHelper();

protected:
	static void GetFlashMoviesObjList_noframes(IHTMLDocument2Ptr spDoc, LPFLASHLIST pv);
	static void SaveFlashMovies_noframes(IHTMLDocument2Ptr spDoc, LPCSTR pszFolder);
};

#endif 
