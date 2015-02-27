/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef __DOWNLOADPROPERTIES_H_
#define __DOWNLOADPROPERTIES_H_

#include "inetfile/inetfile.h"

enum fsNetworkProtocol
{
	NP_HTTP,
	NP_HTTPS,
	NP_FTP,
	NP_FILE		
};

#define FTP_USEPASSIVEMODE			1

#define FTP_DONTSENDLIST			2

enum fsInternetAccessTypeEx	
{
	IATE_NOPROXY		= IAT_NOPROXY,			
	IATE_PRECONFIGPROXY	= IAT_PRECONFIGPROXY,	
	IATE_MANUALPROXY	= IAT_MANUALPROXY,		
	IATE_FIREFOXPROXY,							
};

struct fsDownload_NetworkProperties
{
	WORD wRollBackSize;		

	
	LPSTR pszAgent;	

	
	fsInternetAccessTypeEx enAccType;	
	LPSTR pszProxyName;		
	LPSTR pszProxyUserName;	
	LPSTR pszProxyPassword;	

	
	fsNetworkProtocol enProtocol;	
	LPSTR pszServerName;	
	INTERNET_PORT  uServerPort;	
	LPSTR pszUserName;	
	LPSTR pszPassword;

	
	LPSTR pszPathName;	

	
	BOOL  bUseHttp11;	
	LPSTR pszReferer;	
	BOOL  bUseCookie;	

	
	DWORD dwFtpFlags;	
	fsFtpTransferType enFtpTransferType;	
	
	
	LPSTR pszASCIIExts;

	
	LPSTR pszCookies;	
	LPSTR pszPostData; 

	
	DWORD dwFlags;				
	
	
	WORD  wLowSpeed_Factor;
	
	WORD  wLowSpeed_Duration;

};

#define DNPF_RESTARTSECTIONWHENSPEEDTOOLOW					1

#define DNPF_IMMEDIATELY_SEND_AUTH_AS_BASIC					(1<<1)

#define DNPF_DONT_UPDATE_ORIGINAL_URL_AFTER_REDIRECT		(1<<2)

struct fsDNP_BuffersInfo
{
	UINT nAgentSize;
	UINT nProxyNameSize;
	UINT nProxyUserNameSize;
	UINT nProxyPasswordSize;
	UINT nServerNameSize;
	UINT nUserNameSize;
	UINT nPasswordSize;
	UINT nPathNameSize;
	UINT nRefferSize;
	UINT nTransferTypeExtsSize;
	UINT nCookiesSize;
	UINT nPostDataSize;
};

enum fsDownloadFileError	
{
	DFE_NOTFOUND		= 0,	
	DFE_ACCDENIED		= 1,	

	DFE_UNKNOWN			= 2		
};

enum fsDownloadFileErrorProcessing
{
	DFEP_STOP,		
	DFEP_IGNORE		
};

enum fsAlreadyExistReaction
{
	AER_ASKUSER,	
	AER_REWRITE,	
	AER_RENAME,		
	AER_RESUME,		
	AER_STOP,		
	AER_RENAME_2	
};

enum fsSizeChangeReaction
{
	SCR_ASKUSER,	
	SCR_RESTART,	
	SCR_ADJUSTFORNEWSIZE,	
	SCR_STOP,		
};

enum vmsIntegrityCheckFailedReaction
{
	ICFR_ASKUSER,		
	ICFR_RESTART,	
	ICFR_IGNORE,
};

#define DPF_DONTRESTARTIFNORESUME		1	
#define DPF_USEZIPPREVIEW				2

#define DPF_USEHIDDENATTRIB				4

#define DPF_APPENDCOMMENTTOFILENAME		8

#define DPF_STARTWHENDONE				16

#define DPF_STARTWHENDONE_NOCONF		32

#define DPF_RETRDATEFROMSERVER			64

#define DPF_GENERATEDESCFILE			128

struct fsDownload_Properties
{
	WORD  wStructSize;	

	
	UINT  uTrafficRestriction;	
	UINT  uMaxAttempts;			
	UINT  uRetriesTime;			
	UINT  uTimeout;				
	
	
	UINT  uSectionMinSize;		
	UINT  uMaxSections;			
	BOOL  bRestartSpeedLow;		

	
	LPSTR pszFileName;			
	BOOL  bReserveDiskSpace;	
	
	
	BOOL  bIgnoreRestrictions;	
	
	
	fsDownloadFileErrorProcessing aEP [DFE_UNKNOWN];
	fsAlreadyExistReaction enAER;	
	fsSizeChangeReaction enSCR;	
	LPSTR pszAdditionalExt;		
	DWORD dwFlags;	
	LPSTR pszCreateExt;			

	
	BOOL bCheckIntegrityWhenDone;	
	vmsIntegrityCheckFailedReaction enICFR;	
	LPSTR pszCheckSum;		
	
	
	
	
	DWORD dwIntegrityCheckAlgorithm;

};

struct fsDP_BuffersInfo
{
	UINT nAdditionalExtSize;	
};

extern void fsDNP_SetAuth (fsDownload_NetworkProperties* dnp, LPCSTR pszUser, LPCSTR pszPassword);

extern BOOL fsDNP_GetDefaults (fsDownload_NetworkProperties *pDNP, fsDNP_BuffersInfo* pBuffs, BOOL bAllocate);

extern void fsDNP_GetDefaults_Free (fsDownload_NetworkProperties *pDNP);

extern fsInternetResult fsDNP_ApplyUrl (fsDownload_NetworkProperties *dnp, LPCSTR pszUrl);

extern BOOL fsDP_GetDefaults (fsDownload_Properties *pDP, fsDP_BuffersInfo* pBuffs, BOOL bAllocate);

extern fsInternetResult fsDNP_GetByUrl (fsDownload_NetworkProperties *pDNP, fsDNP_BuffersInfo* pBuffs, BOOL bAllocate, LPCSTR pszUrl);

extern void fsDNP_GetByUrl_Free (fsDownload_NetworkProperties *pDNP);

extern fsNetworkProtocol fsSchemeToNP (INTERNET_SCHEME scheme);
extern INTERNET_SCHEME fsNPToScheme (fsNetworkProtocol np);

extern fsInternetResult fsGetProxyByNP (fsDownload_NetworkProperties *pDNP, fsDNP_BuffersInfo* pBuffs, BOOL bAllocate);

extern BOOL fsGetProxy (fsNetworkProtocol np, CString& strProxy, CString& strUser, CString& strPassword);

extern BOOL fsDNP_CloneSettings (fsDownload_NetworkProperties *dst, fsDownload_NetworkProperties *src);

extern void fsDNP_GetURL (fsDownload_NetworkProperties* dnp, LPSTR pszURL);

#endif