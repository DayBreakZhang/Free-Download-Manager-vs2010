/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSMEDIACONVERTMGR_H__E56F64FA_0DF5_42D7_AD8D_7A05F234E360__INCLUDED_)
#define AFX_VMSMEDIACONVERTMGR_H__E56F64FA_0DF5_42D7_AD8D_7A05F234E360__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "fsDownload.h"
#include "vmsPersistObject.h"

struct vmsMediaFileConvertSettings
{
	fsString strFormat; 
	fsString strExtension; 
	fsString strAudioCodec, strVideoCodec;
	int nAudioBitrate, nVideoBitrate;
	CSize sizeVideo;
};

enum vmsMediaConvertMgr_OptionsSource
{
	MCM_OS_SEARCH_IN_MGR,
	MCM_OS_USE_DEFAULTS,
	MCM_OS_SHOW_OPTIONS_UI,
};

class vmsMediaConvertMgr : public vmsPersistObject
{
public:
	
	static BOOL ShowSettingsUI(vmsMediaFileConvertSettings &stgs);
	static void SaveSettingsAsDefault(const vmsMediaFileConvertSettings &stgs);
	static void GetDefaultSettings (vmsMediaFileConvertSettings& stgs);
	void ConvertMediaFile_SetupDefaultOptions();
	void ConvertMediaFile (vmsDownloadSmartPtr dld, vmsMediaConvertMgr_OptionsSource enOs);
	BOOL LoadState();
	BOOL SaveState();
	
	void AddTask (vmsDownloadSmartPtr dld, const vmsMediaFileConvertSettings &stgs);
	
	
	virtual bool loadObjectItselfFromStateBuffer(LPBYTE pb, LPDWORD pdwSize, DWORD dwVer);
	virtual void getObjectItselfStateBuffer(LPBYTE pb, LPDWORD pdwSize, bool bSaveToStorage);

	vmsMediaConvertMgr();
	virtual ~vmsMediaConvertMgr();

protected:
	int FindDownload (vmsDownloadSmartPtr dld);
	static DWORD WINAPI _threadConvertMediaFile(LPVOID lp);

	struct vmsConvertMediaFileContext;

	
	typedef bool (*CtfxLoadEventHandler)(int nId, vmsMediaConvertMgr::vmsConvertMediaFileContext* ctx, void* pvData);
	
	struct vmsConvertMediaFileContext : public vmsObject, public vmsPersistObject
	{
		vmsDownloadSmartPtr dld;
		vmsMediaFileConvertSettings stgs;

		
		void* pvData;
		CtfxLoadEventHandler clehEventHandler;

		virtual bool loadObjectItselfFromStateBuffer(LPBYTE pb, LPDWORD pdwSize, DWORD dwVer);
		virtual void getObjectItselfStateBuffer(LPBYTE pb, LPDWORD pdwSize, bool bSaveToStorage);
	};

	typedef vmsObjectSmartPtr<vmsMediaConvertMgr::vmsConvertMediaFileContext> vmsConvertMediaFileContextSmartPtr;

	std::vector <vmsConvertMediaFileContextSmartPtr> m_vTasks;

	static bool FdmCtfxLoadEventhandler(int nId, vmsMediaConvertMgr::vmsConvertMediaFileContext* ctx, void* pvData);

	
	
	

	
	#define MCMGRFILE_CURRENT_VERSION	(1)
	
	#define MCMGRFILE_SIG "FDM Media Convert Tasks"
	
	struct fsMcMgrFileHdr
	{
		char szSig [sizeof (MCMGRFILE_SIG) + 1];
		WORD wVer;

		fsMcMgrFileHdr ()
		{
			strcpy (szSig, MCMGRFILE_SIG);
			wVer = MCMGRFILE_CURRENT_VERSION;
		}
	};

};

#endif 
