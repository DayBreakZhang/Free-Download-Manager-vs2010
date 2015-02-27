/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"

#include "lib.add/vmsPostRequest.cpp"
#include "lib.Add/vmsZip.cpp"
#include "lib.Add/vmsUnZip.cpp"

SCL_INITOBJECT (_T ("fdm"), 0);

fsAppSettings _App;
fsTrayIconMgr _TrayMgr;
fsDialogsMgr _DlgMgr;
fsClipboardMgr _ClipbrdMgr;
CToolBarEx _TBMgr;
fsUpdateMgr _UpdateMgr;
fsAutorunMgr _AutorunMgr;
fsCmdHistoryMgr _LastUrlFiles;
fsCmdHistoryMgr _LastUrlPaths;
fsCmdHistoryMgr _LastBatchUrls;
fsCmdHistoryMgr _LastFolders;
fsCmdHistoryMgr _LastFlashVideoUrls;
fsCmdHistoryMgr _LastFlashVideoDstFolders;
fsContextHelpMgr _CHMgr;
fsMFCLangMgr _LngMgr;
fsSitesMgr _SitesMgr;
fsIEContextMenuMgr _IECMM;
vmsFdmOpNetIntegrationMgr _NOMgr;
fsIECatchMgr _IECatchMgr;
fsSoundsMgr _Snds;
fsHistoriesMgr _HsMgr;

fsCmdHistoryMgr _LastFind;
vmsSkinMgr _SkinMgr;
fsDownloadsMgr _DldsMgr;
vmsTheme _theme;
vmsDownloadsGroupsMgr _DldsGrps;
FILETIME _timeAppHasStarted;
vmsBtSupport _BT;
vmsMediaConvertMgr _MediaConvertMgr;
fsPluginMgr _PluginMgr;
vmsFdmAppMgr _AppMgr;

DWORD _dwAppState = 0;

#ifdef _ATL_STATIC_REGISTRY
#include <statreg.h>
#endif

