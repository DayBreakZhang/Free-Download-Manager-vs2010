# Microsoft Developer Studio Project File - Name="AppWinSockSniffDll" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=AppWinSockSniffDll - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "AppWinSockSniffDll.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "AppWinSockSniffDll.mak" CFG="AppWinSockSniffDll - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "AppWinSockSniffDll - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "AppWinSockSniffDll - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "AppWinSockSniffDll - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "APPWINSOCKSNIFFDLL_EXPORTS" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /Zi /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "APPWINSOCKSNIFFDLL_EXPORTS" /Yu"stdafx.h" /FD /EHa /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x419 /d "NDEBUG"
# ADD RSC /l 0x419 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib detours.lib ws2_32.lib wininet.lib shlwapi.lib /nologo /dll /debug /machine:I386 /out:"../bin/Release/flvsniff.dll"
# SUBTRACT LINK32 /map

!ELSEIF  "$(CFG)" == "AppWinSockSniffDll - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "APPWINSOCKSNIFFDLL_EXPORTS" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "APPWINSOCKSNIFFDLL_EXPORTS" /Yu"stdafx.h" /FD /GZ /EHa /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x419 /d "_DEBUG"
# ADD RSC /l 0x419 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib detours.lib ws2_32.lib wininet.lib shlwapi.lib /nologo /dll /debug /machine:I386 /out:"../bin/Debug/flvsniff.dll" /pdbtype:sept

!ENDIF 

# Begin Target

# Name "AppWinSockSniffDll - Win32 Release"
# Name "AppWinSockSniffDll - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\zlib\adler32.c
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=.\AppWinSockSniffDll.cpp
# End Source File
# Begin Source File

SOURCE=.\AppWinSockSniffDll.def
# End Source File
# Begin Source File

SOURCE=.\zlib\compress.c
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=.\zlib\crc32.c
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=.\zlib\deflate.c
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=.\flvsniff.rc
# End Source File
# Begin Source File

SOURCE=.\zlib\gzio.c
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=.\zlib\infback.c
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=.\zlib\inffast.c
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=.\zlib\inflate.c
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=.\zlib\inftrees.c
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\zlib\trees.c
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=.\zlib\uncompr.c
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=.\vmsBrowserCachedFlvTrafficCollector.cpp
# End Source File
# Begin Source File

SOURCE=.\vmsBrowserFlvHistory.cpp
# End Source File
# Begin Source File

SOURCE=.\vmsBrowserSpecialInfo.cpp
# End Source File
# Begin Source File

SOURCE=.\vmsCharsets.cpp
# End Source File
# Begin Source File

SOURCE=.\vmsDownloadForTrafficCollector.cpp
# End Source File
# Begin Source File

SOURCE=.\vmsExternalHttpTrafficCollector.cpp
# End Source File
# Begin Source File

SOURCE=.\vmsFfDiskCacheBlockFile.cpp
# End Source File
# Begin Source File

SOURCE=.\vmsFfDiskCacheMap.cpp
# End Source File
# Begin Source File

SOURCE=.\vmsFile.cpp
# End Source File
# Begin Source File

SOURCE=.\vmsFileUtil.cpp
# End Source File
# Begin Source File

SOURCE=.\vmsFindFlvDownloadsResultsCache.cpp
# End Source File
# Begin Source File

SOURCE=.\vmsFirefoxFlvHistory.cpp
# End Source File
# Begin Source File

SOURCE=.\vmsFirefoxUtil.cpp
# End Source File
# Begin Source File

SOURCE=.\vmsHtmlParser.cpp
# End Source File
# Begin Source File

SOURCE=.\vmsHtmlTagParser.cpp
# End Source File
# Begin Source File

SOURCE=.\vmsHttpFlvTrafficAnalyzer.cpp
# End Source File
# Begin Source File

SOURCE=.\vmsHttpFlvTrafficAnalyzer2.cpp
# End Source File
# Begin Source File

SOURCE=.\vmsHttpFlvTrafficAnalyzer3.cpp
# End Source File
# Begin Source File

SOURCE=.\vmsHttpFlvTrafficAnalyzer4.cpp
# End Source File
# Begin Source File

SOURCE=.\vmsHttpFlvTrafficAnalyzer5.cpp
# End Source File
# Begin Source File

SOURCE=.\vmsHttpHelper.cpp
# End Source File
# Begin Source File

SOURCE=.\vmsHttpParser.cpp
# End Source File
# Begin Source File

SOURCE=.\vmsHttpRequestParser.cpp
# End Source File
# Begin Source File

SOURCE=.\vmsHttpResponseParser.cpp
# End Source File
# Begin Source File

SOURCE=.\vmsHttpTrafficCollector.cpp
# End Source File
# Begin Source File

SOURCE=.\vmsIeFlvHistory.cpp
# End Source File
# Begin Source File

SOURCE=.\vmsLogHelper.cpp
# End Source File
# Begin Source File

SOURCE=..\vmsSharedData.cpp
# End Source File
# Begin Source File

SOURCE=.\vmsSniffDllWnd.cpp
# End Source File
# Begin Source File

SOURCE=.\vmsSwfDataTypes.cpp
# End Source File
# Begin Source File

SOURCE=.\vmsSwfFile.cpp
# End Source File
# Begin Source File

SOURCE=.\vmsSwfFileHeader.cpp
# End Source File
# Begin Source File

SOURCE=.\vmsSwfObjectsAndFlvsConformity.cpp
# End Source File
# Begin Source File

SOURCE=.\vmsTransferFlvDownloadsToFdm.cpp
# End Source File
# Begin Source File

SOURCE=.\vmsUrl.cpp
# End Source File
# Begin Source File

SOURCE=.\vmsUrlFromBrowser.cpp
# End Source File
# Begin Source File

SOURCE=.\vmsUrlMonSpyDll.cpp
# End Source File
# Begin Source File

SOURCE=.\vmsUrlWords.cpp
# End Source File
# Begin Source File

SOURCE=.\vmsWinInetHttpTrafficCollector.cpp
# End Source File
# Begin Source File

SOURCE=.\vmsWinSockHttpDlgTree.cpp
# End Source File
# Begin Source File

SOURCE=.\vmsWinSockHttpTrafficAnalyzer.cpp
# End Source File
# Begin Source File

SOURCE=.\vmsWinSockHttpTrafficCollector.cpp
# End Source File
# Begin Source File

SOURCE=.\vmsXmlHelper.cpp
# End Source File
# Begin Source File

SOURCE=.\vmsZlibHelper.cpp
# End Source File
# Begin Source File

SOURCE=.\zlib\zutil.c
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\vmsBrowserCachedFlvTrafficCollector.h
# End Source File
# Begin Source File

SOURCE=.\vmsBrowserFlvHistory.h
# End Source File
# Begin Source File

SOURCE=.\vmsBrowserSpecialInfo.h
# End Source File
# Begin Source File

SOURCE=.\vmsCharsets.h
# End Source File
# Begin Source File

SOURCE=.\vmsCriticalSection.h
# End Source File
# Begin Source File

SOURCE=.\vmsDownloadForTrafficCollector.h
# End Source File
# Begin Source File

SOURCE=.\vmsExternalHttpTrafficCollector.h
# End Source File
# Begin Source File

SOURCE=.\vmsFfDiskCacheBlockFile.h
# End Source File
# Begin Source File

SOURCE=.\vmsFfDiskCacheMap.h
# End Source File
# Begin Source File

SOURCE=.\vmsFile.h
# End Source File
# Begin Source File

SOURCE=.\vmsFileUtil.h
# End Source File
# Begin Source File

SOURCE=.\vmsFindFlvDownloadsResultsCache.h
# End Source File
# Begin Source File

SOURCE=.\vmsFirefoxFlvHistory.h
# End Source File
# Begin Source File

SOURCE=.\vmsFirefoxUtil.h
# End Source File
# Begin Source File

SOURCE=.\vmsHtmlParser.h
# End Source File
# Begin Source File

SOURCE=.\vmsHtmlTagParser.h
# End Source File
# Begin Source File

SOURCE=.\vmsHttpFlvTrafficAnalyzer.h
# End Source File
# Begin Source File

SOURCE=.\vmsHttpFlvTrafficAnalyzer2.h
# End Source File
# Begin Source File

SOURCE=.\vmsHttpFlvTrafficAnalyzer3.h
# End Source File
# Begin Source File

SOURCE=.\vmsHttpFlvTrafficAnalyzer4.h
# End Source File
# Begin Source File

SOURCE=.\vmsHttpFlvTrafficAnalyzer5.h
# End Source File
# Begin Source File

SOURCE=.\vmsHttpHelper.h
# End Source File
# Begin Source File

SOURCE=.\vmsHttpParser.h
# End Source File
# Begin Source File

SOURCE=.\vmsHttpRequestParser.h
# End Source File
# Begin Source File

SOURCE=.\vmsHttpResponseParser.h
# End Source File
# Begin Source File

SOURCE=.\vmsHttpTrafficCollector.h
# End Source File
# Begin Source File

SOURCE=.\vmsIeFlvHistory.h
# End Source File
# Begin Source File

SOURCE=.\vmsLogHelper.h
# End Source File
# Begin Source File

SOURCE=.\vmsSniffDllWnd.h
# End Source File
# Begin Source File

SOURCE=.\vmsSwfDataTypes.h
# End Source File
# Begin Source File

SOURCE=.\vmsSwfFile.h
# End Source File
# Begin Source File

SOURCE=.\vmsSwfFileHeader.h
# End Source File
# Begin Source File

SOURCE=.\vmsSwfObjectsAndFlvsConformity.h
# End Source File
# Begin Source File

SOURCE=.\vmsTransferFlvDownloadsToFdm.h
# End Source File
# Begin Source File

SOURCE=.\vmsUrl.h
# End Source File
# Begin Source File

SOURCE=.\vmsUrlFromBrowser.h
# End Source File
# Begin Source File

SOURCE=.\vmsUrlMonSpyDll.h
# End Source File
# Begin Source File

SOURCE=.\vmsUrlWords.h
# End Source File
# Begin Source File

SOURCE=.\vmsWinInetHttpTrafficCollector.h
# End Source File
# Begin Source File

SOURCE=.\vmsWinSockHttpDlgTree.h
# End Source File
# Begin Source File

SOURCE=.\vmsWinSockHttpTrafficAnalyzer.h
# End Source File
# Begin Source File

SOURCE=.\vmsWinSockHttpTrafficCollector.h
# End Source File
# Begin Source File

SOURCE=.\vmsXmlHelper.h
# End Source File
# Begin Source File

SOURCE=.\vmsZlibHelper.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
