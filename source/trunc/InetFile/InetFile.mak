# Microsoft Developer Studio Generated NMAKE File, Based on InetFile.dsp
!IF "$(CFG)" == ""
CFG=InetFile - Win32 Debug
!MESSAGE No configuration specified. Defaulting to InetFile - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "InetFile - Win32 Release" && "$(CFG)" != "InetFile - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "InetFile.mak" CFG="InetFile - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "InetFile - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "InetFile - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "InetFile - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release

ALL : "..\lib.add\InetFile.lib"


CLEAN :
	-@erase "$(INTDIR)\fsFtpConnection.obj"
	-@erase "$(INTDIR)\fsFtpFile.obj"
	-@erase "$(INTDIR)\fsFtpFiles.obj"
	-@erase "$(INTDIR)\fsHTMLParser.obj"
	-@erase "$(INTDIR)\fsHttpConnection.obj"
	-@erase "$(INTDIR)\fsHttpFile.obj"
	-@erase "$(INTDIR)\fsHttpFiles.obj"
	-@erase "$(INTDIR)\fsinet.obj"
	-@erase "$(INTDIR)\fsInternetFile.obj"
	-@erase "$(INTDIR)\fsInternetFile2.obj"
	-@erase "$(INTDIR)\fsInternetFiles.obj"
	-@erase "$(INTDIR)\fsInternetSession.obj"
	-@erase "$(INTDIR)\fsInternetURLFile.obj"
	-@erase "$(INTDIR)\fsInternetURLFileDownloader.obj"
	-@erase "$(INTDIR)\fsInternetURLFiles.obj"
	-@erase "$(INTDIR)\fsInternetURLServer.obj"
	-@erase "$(INTDIR)\fsLocalFile.obj"
	-@erase "$(INTDIR)\fsServerConnection.obj"
	-@erase "$(INTDIR)\fsSpeaking.obj"
	-@erase "$(INTDIR)\fsURL.obj"
	-@erase "$(INTDIR)\strparsing.obj"
	-@erase "$(INTDIR)\system.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "..\lib.add\InetFile.lib"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /WX /GX /ZI /Od /I "../include.add/" /D "NDEBUG" /D "WIN32" /D "_MBCS" /D "_LIB" /D "CURL_STATICLIB" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /EHa /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\InetFile.bsc" 
BSC32_SBRS= \
	
LIB32=link.exe -lib
LIB32_FLAGS=/nologo /out:"..\lib.add\InetFile.lib" 
LIB32_OBJS= \
	"$(INTDIR)\fsFtpConnection.obj" \
	"$(INTDIR)\fsFtpFile.obj" \
	"$(INTDIR)\fsFtpFiles.obj" \
	"$(INTDIR)\fsHTMLParser.obj" \
	"$(INTDIR)\fsHttpConnection.obj" \
	"$(INTDIR)\fsHttpFile.obj" \
	"$(INTDIR)\fsHttpFiles.obj" \
	"$(INTDIR)\fsinet.obj" \
	"$(INTDIR)\fsInternetFile.obj" \
	"$(INTDIR)\fsInternetFile2.obj" \
	"$(INTDIR)\fsInternetFiles.obj" \
	"$(INTDIR)\fsInternetSession.obj" \
	"$(INTDIR)\fsInternetURLFile.obj" \
	"$(INTDIR)\fsInternetURLFileDownloader.obj" \
	"$(INTDIR)\fsInternetURLFiles.obj" \
	"$(INTDIR)\fsInternetURLServer.obj" \
	"$(INTDIR)\fsLocalFile.obj" \
	"$(INTDIR)\fsServerConnection.obj" \
	"$(INTDIR)\fsSpeaking.obj" \
	"$(INTDIR)\fsURL.obj" \
	"$(INTDIR)\strparsing.obj" \
	"$(INTDIR)\system.obj"

"..\lib.add\InetFile.lib" : "$(OUTDIR)" $(DEF_FILE) $(LIB32_OBJS)
    $(LIB32) @<<
  $(LIB32_FLAGS) $(DEF_FLAGS) $(LIB32_OBJS)
<<

!ELSEIF  "$(CFG)" == "InetFile - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug

ALL : "..\lib.add\InetFile_d.lib"


CLEAN :
	-@erase "$(INTDIR)\fsFtpConnection.obj"
	-@erase "$(INTDIR)\fsFtpFile.obj"
	-@erase "$(INTDIR)\fsFtpFiles.obj"
	-@erase "$(INTDIR)\fsHTMLParser.obj"
	-@erase "$(INTDIR)\fsHttpConnection.obj"
	-@erase "$(INTDIR)\fsHttpFile.obj"
	-@erase "$(INTDIR)\fsHttpFiles.obj"
	-@erase "$(INTDIR)\fsinet.obj"
	-@erase "$(INTDIR)\fsInternetFile.obj"
	-@erase "$(INTDIR)\fsInternetFile2.obj"
	-@erase "$(INTDIR)\fsInternetFiles.obj"
	-@erase "$(INTDIR)\fsInternetSession.obj"
	-@erase "$(INTDIR)\fsInternetURLFile.obj"
	-@erase "$(INTDIR)\fsInternetURLFileDownloader.obj"
	-@erase "$(INTDIR)\fsInternetURLFiles.obj"
	-@erase "$(INTDIR)\fsInternetURLServer.obj"
	-@erase "$(INTDIR)\fsLocalFile.obj"
	-@erase "$(INTDIR)\fsServerConnection.obj"
	-@erase "$(INTDIR)\fsSpeaking.obj"
	-@erase "$(INTDIR)\fsURL.obj"
	-@erase "$(INTDIR)\strparsing.obj"
	-@erase "$(INTDIR)\system.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "..\lib.add\InetFile_d.lib"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W4 /Gm /GX /ZI /Od /I "../include.add/" /D "_DEBUG" /D "WIN32" /D "_MBCS" /D "_LIB" /D "CURL_STATICLIB" /D "BUILDING_LIBCURL" /D "USE_SSLEAY" /Fp"$(INTDIR)\InetFile.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /EHa /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\InetFile.bsc" 
BSC32_SBRS= \
	
LIB32=link.exe -lib
LIB32_FLAGS=/nologo /out:"..\lib.add\InetFile_d.lib" 
LIB32_OBJS= \
	"$(INTDIR)\fsFtpConnection.obj" \
	"$(INTDIR)\fsFtpFile.obj" \
	"$(INTDIR)\fsFtpFiles.obj" \
	"$(INTDIR)\fsHTMLParser.obj" \
	"$(INTDIR)\fsHttpConnection.obj" \
	"$(INTDIR)\fsHttpFile.obj" \
	"$(INTDIR)\fsHttpFiles.obj" \
	"$(INTDIR)\fsinet.obj" \
	"$(INTDIR)\fsInternetFile.obj" \
	"$(INTDIR)\fsInternetFile2.obj" \
	"$(INTDIR)\fsInternetFiles.obj" \
	"$(INTDIR)\fsInternetSession.obj" \
	"$(INTDIR)\fsInternetURLFile.obj" \
	"$(INTDIR)\fsInternetURLFileDownloader.obj" \
	"$(INTDIR)\fsInternetURLFiles.obj" \
	"$(INTDIR)\fsInternetURLServer.obj" \
	"$(INTDIR)\fsLocalFile.obj" \
	"$(INTDIR)\fsServerConnection.obj" \
	"$(INTDIR)\fsSpeaking.obj" \
	"$(INTDIR)\fsURL.obj" \
	"$(INTDIR)\strparsing.obj" \
	"$(INTDIR)\system.obj"

"..\lib.add\InetFile_d.lib" : "$(OUTDIR)" $(DEF_FILE) $(LIB32_OBJS)
    $(LIB32) @<<
  $(LIB32_FLAGS) $(DEF_FLAGS) $(LIB32_OBJS)
<<

!ENDIF 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("InetFile.dep")
!INCLUDE "InetFile.dep"
!ELSE 
!MESSAGE Warning: cannot find "InetFile.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "InetFile - Win32 Release" || "$(CFG)" == "InetFile - Win32 Debug"
SOURCE=.\fsFtpConnection.cpp

"$(INTDIR)\fsFtpConnection.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\fsFtpFile.cpp

"$(INTDIR)\fsFtpFile.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\fsFtpFiles.cpp

"$(INTDIR)\fsFtpFiles.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\fsHTMLParser.cpp

"$(INTDIR)\fsHTMLParser.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\fsHttpConnection.cpp

"$(INTDIR)\fsHttpConnection.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\fsHttpFile.cpp

"$(INTDIR)\fsHttpFile.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\fsHttpFiles.cpp

"$(INTDIR)\fsHttpFiles.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\fsinet.cpp

"$(INTDIR)\fsinet.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\fsInternetFile.cpp

"$(INTDIR)\fsInternetFile.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\fsInternetFile2.cpp

"$(INTDIR)\fsInternetFile2.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\fsInternetFiles.cpp

"$(INTDIR)\fsInternetFiles.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\fsInternetSession.cpp

"$(INTDIR)\fsInternetSession.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\fsInternetURLFile.cpp

"$(INTDIR)\fsInternetURLFile.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\fsInternetURLFileDownloader.cpp

"$(INTDIR)\fsInternetURLFileDownloader.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\fsInternetURLFiles.cpp

"$(INTDIR)\fsInternetURLFiles.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\fsInternetURLServer.cpp

"$(INTDIR)\fsInternetURLServer.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\fsLocalFile.cpp

"$(INTDIR)\fsLocalFile.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\fsServerConnection.cpp

"$(INTDIR)\fsServerConnection.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\fsSpeaking.cpp

"$(INTDIR)\fsSpeaking.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\fsURL.cpp

"$(INTDIR)\fsURL.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\strparsing.cpp

"$(INTDIR)\strparsing.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\system.cpp

"$(INTDIR)\system.obj" : $(SOURCE) "$(INTDIR)"



!ENDIF 

