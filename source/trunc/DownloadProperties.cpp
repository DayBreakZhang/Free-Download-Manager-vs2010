/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "DownloadProperties.h"
#include "Hash\vmsHash.h"

BOOL fsFillBuffer (LPSTR *ppszBuffer, UINT* pnSize, LPCSTR pszFrom, BOOL bAllocate)
{
	if (pszFrom == NULL)
		return FALSE;

	UINT len = strlen (pszFrom);

	
	if (len >= *pnSize && !bAllocate)
		return FALSE;

	*pnSize = len+1;	

	if (bAllocate)
		fsnew (*ppszBuffer, CHAR, len+1);

	if (*ppszBuffer)
		strcpy (*ppszBuffer, pszFrom);

	return TRUE;
}

BOOL fsDNP_GetDefaults (fsDownload_NetworkProperties *pDNP, fsDNP_BuffersInfo* pBuffs, BOOL bAllocate)
{
	BOOL bResult = TRUE;

	if (pDNP == NULL || pBuffs == NULL)
	{
		SetLastError (ERROR_INVALID_PARAMETER);
		return FALSE;
	}

#ifndef FDM_DLDR__RAWCODEONLY
	pDNP->wRollBackSize = _App.RollBackSize ();
	pDNP->enAccType = _App.InternetAccessType ();
	pDNP->dwFtpFlags = _App.FtpFlags ();
	pDNP->bUseHttp11 = _App.UseHttp11 ();
	pDNP->enFtpTransferType = _App.FtpTransferType ();
	pDNP->bUseCookie = _App.UseCookie ();
	pDNP->dwFlags = _App.DNPFlags ();
	pDNP->wLowSpeed_Duration = _App.LowSpeed_Duration ();
	pDNP->wLowSpeed_Factor = _App.LowSpeed_Factor ();

	bResult &= fsFillBuffer (&pDNP->pszAgent, &pBuffs->nAgentSize, _App.Agent (), bAllocate);
	bResult &= fsFillBuffer (&pDNP->pszPassword, &pBuffs->nPasswordSize, _App.UserPassword (), bAllocate);
	bResult &= fsFillBuffer (&pDNP->pszReferer, &pBuffs->nRefferSize, _App.Referer (), bAllocate);
	bResult &= fsFillBuffer (&pDNP->pszUserName, &pBuffs->nUserNameSize, _App.UserName (), bAllocate);
	bResult &= fsFillBuffer (&pDNP->pszASCIIExts, &pBuffs->nTransferTypeExtsSize, _App.ASCIIExts (), bAllocate);
	bResult &= fsFillBuffer (&pDNP->pszCookies, &pBuffs->nCookiesSize, "", bAllocate);
	bResult &= fsFillBuffer (&pDNP->pszPostData, &pBuffs->nPostDataSize, "", bAllocate);
	
#else
	pDNP->wRollBackSize = 3500;
	pDNP->enAccType = IATE_PRECONFIGPROXY;
	pDNP->dwFtpFlags = FTP_USEPASSIVEMODE;
	pDNP->bUseHttp11 = FALSE;
	pDNP->enFtpTransferType = FTT_BINARY;
	pDNP->bUseCookie = TRUE;
	pDNP->dwFlags = 0;
	pDNP->wLowSpeed_Duration = 1;
	pDNP->wLowSpeed_Factor = 3;

	bResult &= fsFillBuffer (&pDNP->pszAgent, &pBuffs->nAgentSize, "FDMuiless", bAllocate);
	bResult &= fsFillBuffer (&pDNP->pszPassword, &pBuffs->nPasswordSize, "", bAllocate);
	bResult &= fsFillBuffer (&pDNP->pszReferer, &pBuffs->nRefferSize, "", bAllocate);
	bResult &= fsFillBuffer (&pDNP->pszUserName, &pBuffs->nUserNameSize, "", bAllocate);
	bResult &= fsFillBuffer (&pDNP->pszASCIIExts, &pBuffs->nTransferTypeExtsSize, "", bAllocate);
	bResult &= fsFillBuffer (&pDNP->pszCookies, &pBuffs->nCookiesSize, "", bAllocate);
	bResult &= fsFillBuffer (&pDNP->pszPostData, &pBuffs->nPostDataSize, "", bAllocate);
#endif

	if (!bResult)
		SetLastError (ERROR_INSUFFICIENT_BUFFER);

	return bResult;
}

void fsDNP_GetDefaults_Free (fsDownload_NetworkProperties *pDNP)
{
	SAFE_DELETE_ARRAY (pDNP->pszPassword);
	SAFE_DELETE_ARRAY (pDNP->pszProxyName);
	SAFE_DELETE_ARRAY (pDNP->pszProxyPassword);
	SAFE_DELETE_ARRAY (pDNP->pszProxyUserName);
	SAFE_DELETE_ARRAY (pDNP->pszReferer);
	SAFE_DELETE_ARRAY (pDNP->pszUserName);
	SAFE_DELETE_ARRAY (pDNP->pszAgent);
	SAFE_DELETE_ARRAY (pDNP->pszASCIIExts);
	SAFE_DELETE_ARRAY (pDNP->pszCookies);
	SAFE_DELETE_ARRAY (pDNP->pszPostData);
}

BOOL fsDP_GetDefaults (fsDownload_Properties *pDP, fsDP_BuffersInfo* pBuffs, BOOL bAllocate)
{
	if (pDP == NULL)
	{
		SetLastError (ERROR_INVALID_PARAMETER);
		return FALSE;
	}

	if (pDP->wStructSize != sizeof (fsDownload_Properties))
	{
		SetLastError (ERROR_INVALID_DATA);
		return FALSE;
	}

#ifndef FDM_DLDR__RAWCODEONLY
	pDP->bIgnoreRestrictions = _App.IgnoreRestrictions ();
	pDP->bRestartSpeedLow = _App.RestartSpeedLow ();
	pDP->uMaxAttempts = _App.MaxAttempts ();
	pDP->uMaxSections = _App.MaxSections ();
	pDP->uSectionMinSize = _App.SectionMinSize ();
	pDP->uTrafficRestriction = _App.TrafficRestriction ();
	pDP->uRetriesTime = _App.RetriesTime ();
	pDP->bReserveDiskSpace = _App.ReserveDiskSpace ();
	pDP->uTimeout = _App.Timeout ();

	pDP->aEP [DFE_NOTFOUND] = _App.NotFoundReaction ();
	pDP->aEP [DFE_ACCDENIED] = _App.AccDeniedReaction ();

	pDP->enAER = _App.AlreadyExistReaction ();
	pDP->enSCR = _App.SizeChangeReaction ();

	pDP->dwFlags = _App.DownloadFlags ();

	if (_App.UseZipPreview ())
		pDP->dwFlags |= DPF_USEZIPPREVIEW;
	else
		pDP->dwFlags &= ~DPF_USEZIPPREVIEW;

	pDP->bCheckIntegrityWhenDone = _App.Download_CheckIntegrityWhenDone ();
	pDP->dwIntegrityCheckAlgorithm = HA_MD5;
	pDP->enICFR = (vmsIntegrityCheckFailedReaction)_App.Download_IntegrityCheckFailedReaction ();
	pDP->pszCheckSum = new char [1]; *pDP->pszCheckSum = 0;

#else
	pDP->bIgnoreRestrictions = FALSE;
	pDP->bRestartSpeedLow = TRUE;
	pDP->uMaxAttempts = UINT_MAX;
	pDP->uMaxSections = 1;
	pDP->uSectionMinSize = 300*1024;
	pDP->uTrafficRestriction = UINT_MAX;
	pDP->uRetriesTime = 5*1000;
	pDP->bReserveDiskSpace = TRUE;
	pDP->uTimeout = 2*60*1000;

	pDP->aEP [DFE_NOTFOUND] = DFEP_STOP;
	pDP->aEP [DFE_ACCDENIED] = DFEP_STOP;

	pDP->enAER = AER_REWRITE;
	pDP->enSCR = SCR_STOP;

	pDP->dwFlags = 0;

	pDP->bCheckIntegrityWhenDone = FALSE;
	pDP->pszCheckSum = new char [1]; *pDP->pszCheckSum = 0;
#endif

	if (bAllocate)
		pDP->pszCheckSum = new char [1];
	*pDP->pszCheckSum = 0;

	BOOL bResult = TRUE;

#ifndef FDM_DLDR__RAWCODEONLY
	bResult &= fsFillBuffer (&pDP->pszAdditionalExt, &pBuffs->nAdditionalExtSize, _App.AdditionalExtension (), bAllocate);
	bResult &= fsFillBuffer (&pDP->pszCreateExt, &pBuffs->nAdditionalExtSize, _App.Download_CreateExt (), bAllocate);
#else
	bResult &= fsFillBuffer (&pDP->pszAdditionalExt, &pBuffs->nAdditionalExtSize, "", bAllocate);
	bResult &= fsFillBuffer (&pDP->pszCreateExt, &pBuffs->nAdditionalExtSize, "", bAllocate);
#endif

	return bResult ? IR_SUCCESS : IR_ERROR;
}

fsInternetResult fsDNP_GetByUrl (fsDownload_NetworkProperties *pDNP, fsDNP_BuffersInfo* pBuffs, BOOL bAllocate, LPCSTR pszUrl)
{
	
	if (!fsDNP_GetDefaults (pDNP, pBuffs, bAllocate))
		return IR_ERROR;
	
	fsURL url;
	BOOL bOk = TRUE;

	fsInternetResult ir = url.Crack (pszUrl);	
	if (ir != IR_SUCCESS)
	{
		fsDNP_GetDefaults_Free (pDNP);
		return ir;
	}

	pDNP->enProtocol = fsSchemeToNP (url.GetInternetScheme ());

	
	fsGetProxyByNP (pDNP, pBuffs, bAllocate);

	pDNP->uServerPort = url.GetPort ();

	bOk &= fsFillBuffer (&pDNP->pszServerName, &pBuffs->nServerNameSize, url.GetHostName (), bAllocate);
	bOk &= fsFillBuffer (&pDNP->pszPathName, &pBuffs->nPathNameSize, url.GetPath (), bAllocate);

	LPCSTR pszUser = url.GetUserName ();
	LPCSTR pszPass = url.GetPassword ();

	if (*pszUser)
	{
		if (bAllocate)
			SAFE_DELETE_ARRAY (pDNP->pszUserName);

		bOk &= fsFillBuffer (&pDNP->pszUserName, &pBuffs->nUserNameSize, pszUser, bAllocate);
	}

	if (*pszPass)
	{
		if (bAllocate)
			SAFE_DELETE_ARRAY (pDNP->pszPassword);

		bOk &= fsFillBuffer (&pDNP->pszPassword, &pBuffs->nPasswordSize, pszPass, bAllocate);
	}

	return IR_SUCCESS;
}

void fsDNP_SetAuth (fsDownload_NetworkProperties* dnp, LPCSTR pszUser, LPCSTR pszPassword)
{
	SAFE_DELETE_ARRAY (dnp->pszUserName);
	SAFE_DELETE_ARRAY (dnp->pszPassword);

	if (pszUser)
	{
		dnp->pszUserName = new char [strlen (pszUser) + 1];
		strcpy (dnp->pszUserName, pszUser);
	}

	if (pszPassword)
	{
		dnp->pszPassword = new char [strlen (pszPassword) + 1];
		strcpy (dnp->pszPassword, pszPassword);
	}
}

fsInternetResult fsDNP_ApplyUrl (fsDownload_NetworkProperties *dnp, LPCSTR pszUrl)
{
	fsURL url;
	fsInternetResult ir;

	ir = url.Crack (pszUrl);
	if (ir != IR_SUCCESS)
		return ir;
	
	fsNetworkProtocol np = fsSchemeToNP (url.GetInternetScheme ());

	if (dnp->enProtocol != np)  
	{
		fsDNP_BuffersInfo buffs;

		SAFE_DELETE_ARRAY (dnp->pszProxyName);
		SAFE_DELETE_ARRAY (dnp->pszProxyUserName);
		SAFE_DELETE_ARRAY (dnp->pszProxyPassword);

		dnp->enProtocol = np;

		fsGetProxyByNP (dnp, &buffs, TRUE);
	}

	dnp->uServerPort = url.GetPort ();

	SAFE_DELETE_ARRAY (dnp->pszPathName);
	fsnew (dnp->pszPathName, char, strlen (url.GetPath ()) + 1);
	strcpy (dnp->pszPathName, url.GetPath ());

	SAFE_DELETE_ARRAY (dnp->pszServerName);
	fsnew (dnp->pszServerName, char, strlen (url.GetHostName ()) + 1);
	strcpy (dnp->pszServerName, url.GetHostName ());

	if (*url.GetUserName ())
	{
		SAFE_DELETE_ARRAY (dnp->pszUserName);
		fsnew (dnp->pszUserName, char, strlen (url.GetUserName ()) + 1);
		strcpy (dnp->pszUserName, url.GetUserName ());

		SAFE_DELETE_ARRAY (dnp->pszPassword);
		fsnew (dnp->pszPassword, char, strlen (url.GetPassword ()) + 1);
		strcpy (dnp->pszPassword, url.GetPassword ());
	}
	else
	{
		*dnp->pszUserName = 0;
		*dnp->pszPassword = 0;
	}

	return IR_SUCCESS;
}

void fsDNP_GetByUrl_Free (fsDownload_NetworkProperties *pDNP)
{
	fsDNP_GetDefaults_Free (pDNP);
	SAFE_DELETE_ARRAY (pDNP->pszPathName);
	SAFE_DELETE_ARRAY (pDNP->pszServerName);
}

fsNetworkProtocol fsSchemeToNP (INTERNET_SCHEME scheme)
{
	switch (scheme)
	{
		case INTERNET_SCHEME_FTP:
			return NP_FTP;
			
		case INTERNET_SCHEME_HTTP: 
			return NP_HTTP;
			
		case INTERNET_SCHEME_HTTPS:
			return NP_HTTPS;

		case INTERNET_SCHEME_FILE:
			return NP_FILE;
	}

	ASSERT (FALSE);
	return (fsNetworkProtocol) -1;
}

INTERNET_SCHEME fsNPToScheme (fsNetworkProtocol np)
{
	switch (np)
	{
		case NP_HTTP:
			return INTERNET_SCHEME_HTTP;

		case NP_HTTPS:
			return INTERNET_SCHEME_HTTPS;

		case NP_FTP:
			return INTERNET_SCHEME_FTP;

		case NP_FILE:
			return INTERNET_SCHEME_FILE;	

		default:
			ASSERT (0);
			return INTERNET_SCHEME_UNKNOWN;
	}
}

fsInternetResult fsGetProxyByNP (fsDownload_NetworkProperties *pDNP, fsDNP_BuffersInfo* pBuffs, BOOL bAllocate)
{
	BOOL bOk = TRUE;

	switch (pDNP->enProtocol)
	{
		case NP_FTP:
#ifndef FDM_DLDR__RAWCODEONLY
			bOk &= fsFillBuffer (&pDNP->pszProxyName, &pBuffs->nProxyNameSize, _App.FtpProxy_Name (), bAllocate);
			bOk &= fsFillBuffer (&pDNP->pszProxyPassword, &pBuffs->nProxyPasswordSize, _App.FtpProxy_Password (), bAllocate);
			bOk &= fsFillBuffer (&pDNP->pszProxyUserName, &pBuffs->nProxyUserNameSize, _App.FtpProxy_UserName (), bAllocate);
#else
			bOk &= fsFillBuffer (&pDNP->pszProxyName, &pBuffs->nProxyNameSize, "", bAllocate);
			bOk &= fsFillBuffer (&pDNP->pszProxyPassword, &pBuffs->nProxyPasswordSize, "", bAllocate);
			bOk &= fsFillBuffer (&pDNP->pszProxyUserName, &pBuffs->nProxyUserNameSize, "", bAllocate);
#endif
			break;
			
		case NP_HTTP: 
#ifndef FDM_DLDR__RAWCODEONLY
			bOk &= fsFillBuffer (&pDNP->pszProxyName, &pBuffs->nProxyNameSize, _App.HttpProxy_Name (), bAllocate);
			bOk &= fsFillBuffer (&pDNP->pszProxyPassword, &pBuffs->nProxyPasswordSize, _App.HttpProxy_Password (), bAllocate);
			bOk &= fsFillBuffer (&pDNP->pszProxyUserName, &pBuffs->nProxyUserNameSize, _App.HttpProxy_UserName (), bAllocate);
#else
			bOk &= fsFillBuffer (&pDNP->pszProxyName, &pBuffs->nProxyNameSize, "", bAllocate);
			bOk &= fsFillBuffer (&pDNP->pszProxyPassword, &pBuffs->nProxyPasswordSize, "", bAllocate);
			bOk &= fsFillBuffer (&pDNP->pszProxyUserName, &pBuffs->nProxyUserNameSize, "", bAllocate);
#endif
			break;

		case NP_HTTPS:
#ifndef FDM_DLDR__RAWCODEONLY
			bOk &= fsFillBuffer (&pDNP->pszProxyName, &pBuffs->nProxyNameSize, _App.HttpsProxy_Name (), bAllocate);
			bOk &= fsFillBuffer (&pDNP->pszProxyPassword, &pBuffs->nProxyPasswordSize, _App.HttpsProxy_Password (), bAllocate);
			bOk &= fsFillBuffer (&pDNP->pszProxyUserName, &pBuffs->nProxyUserNameSize, _App.HttpsProxy_UserName (), bAllocate);
#else
			bOk &= fsFillBuffer (&pDNP->pszProxyName, &pBuffs->nProxyNameSize, "", bAllocate);
			bOk &= fsFillBuffer (&pDNP->pszProxyPassword, &pBuffs->nProxyPasswordSize, "", bAllocate);
			bOk &= fsFillBuffer (&pDNP->pszProxyUserName, &pBuffs->nProxyUserNameSize, "", bAllocate);
#endif
			break;

		case NP_FILE:
			bOk &= fsFillBuffer (&pDNP->pszProxyName, &pBuffs->nProxyNameSize, "", bAllocate);
			bOk &= fsFillBuffer (&pDNP->pszProxyPassword, &pBuffs->nProxyPasswordSize, "", bAllocate);
			bOk &= fsFillBuffer (&pDNP->pszProxyUserName, &pBuffs->nProxyUserNameSize, "", bAllocate);
			break;

		default:
			return IR_BADURL;
	}

	return bOk ? IR_SUCCESS : IR_ERROR;
}

BOOL fsGetProxy (fsNetworkProtocol np, CString& strProxy, CString& strUser, CString& strPassword)
{
	switch (np)
	{
		case NP_HTTP:
#ifndef FDM_DLDR__RAWCODEONLY
			strProxy = _App.HttpProxy_Name ();
			strUser = _App.HttpProxy_UserName ();
			strPassword = _App.HttpProxy_Password ();
#else
			strProxy = "";
			strUser = "";
			strPassword = "";
#endif
		break;

		case NP_HTTPS:
#ifndef FDM_DLDR__RAWCODEONLY
			strProxy = _App.HttpsProxy_Name ();
			strUser = _App.HttpsProxy_UserName ();
			strPassword = _App.HttpsProxy_Password ();
#else
			strProxy = "";
			strUser = "";
			strPassword = "";
#endif
		break;

		case NP_FTP:
#ifndef FDM_DLDR__RAWCODEONLY
			strProxy = _App.FtpProxy_Name ();
			strUser = _App.FtpProxy_UserName ();
			strPassword = _App.FtpProxy_Password ();
#else
			strProxy = "";
			strUser = "";
			strPassword = "";
#endif
		break;

		case NP_FILE:
            strProxy = "";
			strUser = "";
			strPassword = "";
		break;

		default:
			return FALSE;
	}

	return TRUE;
}

BOOL fsIsSameProtocols (fsNetworkProtocol np1, fsNetworkProtocol np2)
{
	return np1 == np2 || 
		( 
		  (np1 == NP_HTTP || np1 == NP_HTTPS) && (np2 == NP_HTTP || np2 == NP_HTTPS) 
		);
}

BOOL fsDNP_CloneSettings (fsDownload_NetworkProperties *dst, fsDownload_NetworkProperties *src)
{
	if (fsIsSameProtocols (src->enProtocol, dst->enProtocol) == FALSE)
		return FALSE;

	dst->wRollBackSize = src->wRollBackSize;
	dst->enAccType = src->enAccType;
	dst->dwFtpFlags = src->dwFtpFlags;
	dst->bUseHttp11 = src->bUseHttp11;
	dst->enFtpTransferType = src->enFtpTransferType;
	dst->bUseCookie = src->bUseCookie;

	UINT u;
	
	SAFE_DELETE_ARRAY (dst->pszAgent);
	SAFE_DELETE_ARRAY (dst->pszASCIIExts);

	fsFillBuffer (&dst->pszAgent, &u, src->pszAgent, TRUE);
	fsFillBuffer (&dst->pszASCIIExts, &u, src->pszASCIIExts, TRUE);

	SAFE_DELETE_ARRAY (dst->pszProxyName);
	SAFE_DELETE_ARRAY (dst->pszProxyUserName);
	SAFE_DELETE_ARRAY (dst->pszProxyPassword);

	fsFillBuffer (&dst->pszProxyName, &u, src->pszProxyName, TRUE);
	fsFillBuffer (&dst->pszProxyUserName, &u, src->pszProxyUserName, TRUE);
	fsFillBuffer (&dst->pszProxyPassword, &u, src->pszProxyPassword, TRUE);

	dst->dwFlags = src->dwFlags;

	return TRUE;
}

void fsDNP_GetURL (fsDownload_NetworkProperties* dnp, LPSTR pszURL)
{
	DWORD dw = 10000;
	fsURL url;

	if (IR_SUCCESS != url.Create (fsNPToScheme (dnp->enProtocol), dnp->pszServerName,
			dnp->uServerPort, dnp->pszUserName, dnp->pszPassword, dnp->pszPathName, pszURL, &dw))
		*pszURL = 0;
}