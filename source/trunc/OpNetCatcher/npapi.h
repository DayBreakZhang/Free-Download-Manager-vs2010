/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef _NPAPI_H_
#define _NPAPI_H_

#ifdef _WINDOWS
#	ifndef XP_PC
#		define XP_PC 1
#	endif 
#endif 

#ifdef __MWERKS__
#	define _declspec __declspec
#	ifdef macintosh
#		ifndef XP_MAC
#			define XP_MAC 1
#		endif 
#	endif 
#	ifdef __INTEL__
#		undef NULL
#		ifndef XP_PC
#			define XP_PC 1
#		endif 
#	endif 
#endif 

#include "jri.h"		

#define NP_VERSION_MAJOR 0
#define NP_VERSION_MINOR 9

 
#ifndef _UINT16
typedef unsigned short uint16;
#endif
#ifndef _UINT32
#if defined(__alpha)
typedef unsigned int uint32;
#else 
typedef unsigned long uint32;
#endif 
#endif
#ifndef _INT16
typedef short int16;
#endif
#ifndef _INT32
#if defined(__alpha)
typedef int int32;
#else 
typedef long int32;
#endif 
#endif

#ifndef FALSE
#define FALSE (0)
#endif
#ifndef TRUE
#define TRUE (1)
#endif
#ifndef NULL
#define NULL (0L)
#endif

typedef unsigned char	NPBool;
typedef void*			NPEvent;
typedef int16			NPError;
typedef int16			NPReason;
typedef char*			NPMIMEType;

typedef struct _NPP
{
    void*	pdata;			
    void*	ndata;			
} NPP_t;

typedef NPP_t*  NPP;

typedef struct _NPStream
{
    void*		pdata;		
    void*		ndata;		
    const char*		url;
    uint32		end;
    uint32		lastmodified;
    void*		notifyData;
} NPStream;

typedef struct _NPByteRange
{
    int32	offset;			
    uint32	length;
    struct _NPByteRange* next;
} NPByteRange;

typedef struct _NPSavedData
{
    int32	len;
    void*	buf;
} NPSavedData;

typedef struct _NPRect
{
    uint16	top;
    uint16	left;
    uint16	bottom;
    uint16	right;
} NPRect;

#ifdef XP_UNIX

#include <X11/Xlib.h>

enum {
	NP_SETWINDOW = 1,
	NP_PRINT
};

typedef struct
{
    int32		type;
} NPAnyCallbackStruct;

typedef struct
{
    int32			type;
    Display*		display;
    Visual*			visual;
    Colormap		colormap;
    unsigned int	depth;
} NPSetWindowCallbackStruct;

typedef struct
{
    int32			type;
    FILE*			fp;
} NPPrintCallbackStruct;

typedef enum {
	NPPVpluginNameString = 1,
	NPPVpluginDescriptionString
} NPPVariable;

typedef enum {
	NPNVxDisplay = 1,
	NPNVxtAppContext
} NPNVariable;

#endif 

typedef struct _NPWindow 
{
    void*	window;		
    uint32	x;			
    uint32	y; 			
    uint32	width;		
    uint32	height;
    NPRect	clipRect;	
						
#ifdef XP_UNIX
    void *	ws_info;	
#endif 
} NPWindow;

typedef struct _NPFullPrint
{
    NPBool	pluginPrinted;	
							
    NPBool	printOne;		
							
    void*	platformPrint;	
} NPFullPrint;

typedef struct _NPEmbedPrint
{
    NPWindow	window;
    void*	platformPrint;	
} NPEmbedPrint;

typedef struct _NPPrint
{
    uint16	mode;						
    union
    {
		NPFullPrint		fullPrint;		
		NPEmbedPrint	embedPrint;		
    } print;
} NPPrint;

#ifdef XP_MAC

 
#include <Quickdraw.h>
#include <Events.h>

typedef struct NP_Port
{
    CGrafPtr	port;		
    int32		portx;		
    int32		porty;
} NP_Port;

#define getFocusEvent       (osEvt + 16)
#define loseFocusEvent      (osEvt + 17)
#define adjustCursorEvent   (osEvt + 18)

#endif 

#define NP_EMBED		1
#define NP_FULL			2

#define NP_NORMAL		1
#define NP_SEEK			2
#define NP_ASFILE		3
#define NP_ASFILEONLY		4

#define NP_MAXREADY	(((unsigned)(~0)<<1)>>1)

#define NPERR_BASE							0
#define NPERR_NO_ERROR						(NPERR_BASE + 0)
#define NPERR_GENERIC_ERROR					(NPERR_BASE + 1)
#define NPERR_INVALID_INSTANCE_ERROR		(NPERR_BASE + 2)
#define NPERR_INVALID_FUNCTABLE_ERROR		(NPERR_BASE + 3)
#define NPERR_MODULE_LOAD_FAILED_ERROR		(NPERR_BASE + 4)
#define NPERR_OUT_OF_MEMORY_ERROR			(NPERR_BASE + 5)
#define NPERR_INVALID_PLUGIN_ERROR			(NPERR_BASE + 6)
#define NPERR_INVALID_PLUGIN_DIR_ERROR		(NPERR_BASE + 7)
#define NPERR_INCOMPATIBLE_VERSION_ERROR	(NPERR_BASE + 8)
#define NPERR_INVALID_PARAM 				(NPERR_BASE + 9)
#define NPERR_INVALID_URL 					(NPERR_BASE + 10)
#define NPERR_FILE_NOT_FOUND 				(NPERR_BASE + 11)
#define NPERR_NO_DATA		 				(NPERR_BASE + 12)
#define NPERR_STREAM_NOT_SEEKABLE			(NPERR_BASE + 13)

#define NPRES_BASE                      	0
#define NPRES_DONE			               	(NPRES_BASE + 0)
#define NPRES_NETWORK_ERR               	(NPRES_BASE + 1)
#define NPRES_USER_BREAK                	(NPRES_BASE + 2)

#define NP_NOERR  NP_NOERR_is_obsolete_use_NPERR_NO_ERROR
#define NP_EINVAL NP_EINVAL_is_obsolete_use_NPERR_GENERIC_ERROR
#define NP_EABORT NP_EABORT_is_obsolete_use_NPRES_USER_BREAK

#define NPVERS_HAS_STREAMOUTPUT				8
#define NPVERS_HAS_NOTIFICATION				9
#define NPVERS_HAS_LIVECONNECT				9
#define NPVERS_WIN16_HAS_LIVECONNECT		10

#if defined(_WINDOWS) && !defined(WIN32)
#define NP_LOADDS  _loadds
#else
#define NP_LOADDS
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifdef XP_UNIX
char*					NPP_GetMIMEDescription(void);
NPError					NPP_GetValue(void *instance, NPPVariable variable,
									 void *value);
#endif 
NPError               	NPP_Initialize(void);
void                  	NPP_Shutdown(void);
NPError     NP_LOADDS	NPP_New(NPMIMEType pluginType, NPP instance,
								uint16 mode, int16 argc, char* argn[],
								char* argv[], NPSavedData* saved);
NPError     NP_LOADDS	NPP_Destroy(NPP instance, NPSavedData** save);
NPError     NP_LOADDS	NPP_SetWindow(NPP instance, NPWindow* window);
NPError     NP_LOADDS	NPP_NewStream(NPP instance, NPMIMEType type,
									  NPStream* stream, NPBool seekable,
									  uint16* stype);
NPError     NP_LOADDS	NPP_DestroyStream(NPP instance, NPStream* stream,
										  NPReason reason);
int32       NP_LOADDS	NPP_WriteReady(NPP instance, NPStream* stream);
int32       NP_LOADDS	NPP_Write(NPP instance, NPStream* stream, int32 offset,
								  int32 len, void* buffer);
void        NP_LOADDS	NPP_StreamAsFile(NPP instance, NPStream* stream,
										 const char* fname);
void        NP_LOADDS	NPP_Print(NPP instance, NPPrint* platformPrint);
int16       NP_LOADDS 	NPP_HandleEvent(NPP instance, void* event);
void        NP_LOADDS	NPP_URLNotify(NPP instance, const char* url,
									  NPReason reason, void* notifyData);
jref		NP_LOADDS	NPP_GetJavaClass(void);

 
#ifdef XP_UNIX
NPError			NPN_GetValue(NPP instance, NPNVariable variable,
							 void *value);
#endif 
void        	NPN_Version(int* plugin_major, int* plugin_minor,
							int* netscape_major, int* netscape_minor);
NPError     	NPN_GetURLNotify(NPP instance, const char* url,
								 const char* target, void* notifyData);
NPError     	NPN_GetURL(NPP instance, const char* url,
						   const char* target);
NPError     	NPN_PostURLNotify(NPP instance, const char* url,
								  const char* target, uint32 len,
								  const char* buf, NPBool file,
								  void* notifyData);
NPError     	NPN_PostURL(NPP instance, const char* url,
							const char* target, uint32 len,
							const char* buf, NPBool file);
NPError     	NPN_RequestRead(NPStream* stream, NPByteRange* rangeList);
NPError     	NPN_NewStream(NPP instance, NPMIMEType type,
							  const char* target, NPStream** stream);
int32       	NPN_Write(NPP instance, NPStream* stream, int32 len,
						  void* buffer);
NPError    		NPN_DestroyStream(NPP instance, NPStream* stream,
								  NPReason reason);
void        	NPN_Status(NPP instance, const char* message);
const char* 	NPN_UserAgent(NPP instance);
void*       	NPN_MemAlloc(uint32 size);
void        	NPN_MemFree(void* ptr);
uint32      	NPN_MemFlush(uint32 size);
void			NPN_ReloadPlugins(NPBool reloadPages);
JRIEnv*			NPN_GetJavaEnv(void);
jref			NPN_GetJavaPeer(NPP instance);

#ifdef __cplusplus
}  
#endif

#endif 
