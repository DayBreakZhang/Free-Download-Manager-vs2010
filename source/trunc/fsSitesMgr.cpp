/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "Utils.h"
#include "FdmApp.h"
#include "fsSitesMgr.h"
#include "inetutil.h"
#include "misc.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

fsSitesMgr::fsSitesMgr()
{
	m_pfnEvents = NULL;
}

fsSitesMgr::~fsSitesMgr()
{

}

void fsSitesMgr::AddSite(fsSiteInfoPtr site)
{
	assert (site != NULL);
	if (!site)
		return;
	vmsAUTOLOCKSECTION (m_csSites);
	m_vSites.push_back (site);
	vmsAUTOLOCKSECTION_UNLOCK (m_csSites);
	setDirty();
	Event (SM_SITEADDED, site);
}

fsSiteInfo* fsSitesMgr::GetSite(int iIndex)
{
	return m_vSites [iIndex];
}

fsSiteInfo* fsSitesMgr::FindSite(LPCSTR pszSite, DWORD dwValidFor, BOOL bAllReq)
{
	vmsAUTOLOCKSECTION (m_csSites);

	for (size_t i = 0; i < m_vSites.size (); i++)
	{
		fsSiteInfo *site = m_vSites [i];
		if (fsIsServersEqual (site->strName, pszSite, site->dwValidFor & SITE_VALIDFOR_SUBDOMAINS))
		{
			if (bAllReq)
			{
				
				if ((site->dwValidFor & dwValidFor) == dwValidFor)
					return m_vSites [i];
			}
			else
			{
				
				
				if (site->dwValidFor & dwValidFor)
					return m_vSites [i];
			}
		}
	}

	return NULL;
}

void fsSitesMgr::DeleteSite(fsSiteInfo *pSite)
{
	vmsAUTOLOCKSECTION (m_csSites);
	std::vector <fsSiteInfoPtr>::iterator it;
	it = std::find (m_vSites.begin (), m_vSites.end (), pSite);
	if (it == m_vSites.end ())
		return;
	Event (SM_SITEDELETED, pSite);
	m_vSites.erase (it);
	setDirty();
}

void fsSitesMgr::DeleteAllTempSites()
{
	vmsAUTOLOCKSECTION (m_csSites);

	for (int i = m_vSites.size () - 1; i >= 0; i--)
	{
		if (m_vSites [i]->bTemp)
		{
			Event (SM_SITEDELETED, m_vSites [i]);
			m_vSites.erase (m_vSites.begin () + i);
		}
	}
}

int fsSitesMgr::GetSiteCount()
{
	return m_vSites.size ();
}

void fsSitesMgr::SetEventsFunc(fntSitesMgrEvents pfn, LPVOID lpParam)
{
	m_pfnEvents = pfn;
	m_lpEventsParam = lpParam;
}

void fsSitesMgr::Event(fsSitesMgrEvent ev, fsSiteInfo* site)
{
	if (m_pfnEvents)
		m_pfnEvents (ev, site, m_lpEventsParam);
}

BOOL fsSitesMgr::SaveToFile(HANDLE hFile)
{
	vmsAUTOLOCKSECTION (m_csSites);

	int cPermSites = GetSiteCount () - GetTempSiteCount ();

	DWORD dw;

	fsSitesFileHdr hdr;

	if (!WriteFile (hFile, &hdr, sizeof (hdr), &dw, NULL))
		return FALSE;

	if (!WriteFile (hFile, &cPermSites, sizeof (cPermSites), &dw, NULL))
		return FALSE;

	BOOL bMaySavePwds = _App.SM_KeepPasswords () && 
		_App.SM_DontSavePwdsToDisk () == FALSE;
	
	for (int i = 0; i < GetSiteCount (); i++)
	{
		fsSiteInfo *site = GetSite (i);

		if (site->bTemp)
			continue;

		if (!fsSaveStrToFile (site->strName, hFile))
			return FALSE;

		if (!fsSaveStrToFile (bMaySavePwds ? site->strPassword : NULL, hFile))
			return FALSE;

		if (!fsSaveStrToFile (bMaySavePwds ? site->strUser : NULL, hFile))
			return FALSE;

		UINT nGrpId = site->pGroup ? site->pGroup->nId : (UINT)-1;
		if (!WriteFile (hFile, &nGrpId, sizeof (UINT), &dw, NULL))
			return FALSE;

		if (!WriteFile (hFile, &site->dwFtpFlags, sizeof (site->dwFtpFlags), &dw, NULL))
			return FALSE;

		if (!WriteFile (hFile, &site->cConnsNow, sizeof (site->cConnsNow), &dw, NULL))
			return FALSE;

		if (!WriteFile (hFile, &site->cMaxConns, sizeof (site->cMaxConns), &dw, NULL))
			return FALSE;

		if (!WriteFile (hFile, &site->dwValidFor, sizeof (site->dwValidFor), &dw, NULL))
			return FALSE;
	}

	return TRUE;	
}

void fsSitesMgr::getObjectItselfStateBuffer(LPBYTE pbtBuffer, LPDWORD pdwSize, bool bSaveToStorage)
{
	DWORD dwRequiredSize = 0;
	LPBYTE pbtCurrentPos = pbtBuffer;

	int cPermSites = GetSiteCount () - GetTempSiteCount ();

	putVarToBuffer(cPermSites, pbtCurrentPos, 0, 0, &dwRequiredSize);

	BOOL bMaySavePwds = _App.SM_KeepPasswords () && 
		_App.SM_DontSavePwdsToDisk () == FALSE;
	
	for (int i = 0; i < GetSiteCount (); i++) {
		fsSiteInfo *site = GetSite (i);

		if (site->bTemp)
			continue;

		UINT nGrpId = site->pGroup ? site->pGroup->nId : (UINT)-1;

		putStrToBuffer(site->strName, pbtCurrentPos, 0, 0, &dwRequiredSize);
		putStrToBuffer(bMaySavePwds ? site->strPassword : NULL, pbtCurrentPos, 0, 0, &dwRequiredSize);
		putStrToBuffer(bMaySavePwds ? site->strUser : NULL, pbtCurrentPos, 0, 0, &dwRequiredSize);
		putVarToBuffer(nGrpId, pbtCurrentPos, 0, 0, &dwRequiredSize);
		putVarToBuffer(site->dwFtpFlags, pbtCurrentPos, 0, 0, &dwRequiredSize);
		putVarToBuffer(site->cConnsNow, pbtCurrentPos, 0, 0, &dwRequiredSize);
		putVarToBuffer(site->cMaxConns, pbtCurrentPos, 0, 0, &dwRequiredSize);
		putVarToBuffer(site->dwValidFor, pbtCurrentPos, 0, 0, &dwRequiredSize);
	}

	if (pbtBuffer == NULL) {
		if (pdwSize) {
			*pdwSize = dwRequiredSize;
		}
		return;
	}

	putVarToBuffer(cPermSites, pbtCurrentPos, pbtBuffer, *pdwSize, &dwRequiredSize);

	for (int i = 0; i < GetSiteCount (); i++) {
		fsSiteInfo *site = GetSite (i);

		if (site->bTemp)
			continue;

		UINT nGrpId = site->pGroup ? site->pGroup->nId : (UINT)-1;

		putStrToBuffer(site->strName, pbtCurrentPos, pbtBuffer, *pdwSize, &dwRequiredSize);
		putStrToBuffer(bMaySavePwds ? site->strPassword : NULL, pbtCurrentPos, pbtBuffer, *pdwSize, &dwRequiredSize);
		putStrToBuffer(bMaySavePwds ? site->strUser : NULL, pbtCurrentPos, pbtBuffer, *pdwSize, &dwRequiredSize);
		putVarToBuffer(nGrpId, pbtCurrentPos, pbtBuffer, *pdwSize, &dwRequiredSize);
		putVarToBuffer(site->dwFtpFlags, pbtCurrentPos, pbtBuffer, *pdwSize, &dwRequiredSize);
		putVarToBuffer(site->cConnsNow, pbtCurrentPos, pbtBuffer, *pdwSize, &dwRequiredSize);
		putVarToBuffer(site->cMaxConns, pbtCurrentPos, pbtBuffer, *pdwSize, &dwRequiredSize);
		putVarToBuffer(site->dwValidFor, pbtCurrentPos, pbtBuffer, *pdwSize, &dwRequiredSize);
	}

	*pdwSize = pbtCurrentPos - pbtBuffer;
}

int fsSitesMgr::GetTempSiteCount()
{
	vmsAUTOLOCKSECTION (m_csSites);

	int c = 0;

	for (int i = m_vSites.size () - 1; i >= 0; i--)
		if (m_vSites [i]->bTemp)
			c++;

	return c;
}

BOOL fsSitesMgr::LoadFromFile(HANDLE hFile)
{
	vmsAUTOLOCKSECTION (m_csSites);

	int cSites;

	DWORD dw;
	BOOL bOldVer = FALSE;

	m_vSites.clear ();

	fsSitesFileHdr hdr;
	if (!ReadFile (hFile, &hdr, sizeof (hdr), &dw, NULL))
		bOldVer = TRUE;
	else
	{
		if (strcmp (hdr.szSig, SITESFILE_SIG))
		{
			bOldVer = TRUE;
			SetFilePointer (hFile, 0, NULL, FILE_BEGIN);
		}
		else if (hdr.wVer > SITESFILE_CURRENT_VERSION)
			return FALSE;
	}

	if (!ReadFile (hFile, &cSites, sizeof (cSites), &dw, NULL) || dw != sizeof (cSites))
		return FALSE;
	
	for (int i = 0; i < cSites; i++)
	{
		fsSiteInfoPtr site;
		site.CreateInstance ();

		if (bOldVer)
		{
			fsSiteInfo_v1 sitev1;
			if (!ReadFile (hFile, &sitev1, sizeof (fsSiteInfo_v1), &dw, NULL) || dw != sizeof (fsSiteInfo_v1))
				return FALSE;

			site->dwFtpFlags = sitev1.bFtpPassive;
			site->bTemp = sitev1.bTemp;
			site->cConnsNow = sitev1.cConnsNow;
			site->cMaxConns = sitev1.cMaxConns;
			site->dwValidFor = SITE_VALIDFOR_HTTP|SITE_VALIDFOR_HTTPS|SITE_VALIDFOR_FTP|SITE_VALIDFOR_SUBDOMAINS;
		}
		else
		{
			if (hdr.wVer < 3)
			{
				fsSiteInfo_v2 sitev2;

				if (!ReadFile (hFile, &sitev2, sizeof (sitev2), &dw, NULL) || dw != sizeof (sitev2))
					return FALSE;

				if (!fsReadStrFromFile (&sitev2.strGroup.pszString, hFile))
					return FALSE;

				site->dwFtpFlags = sitev2.dwFtpFlags;
				site->bTemp = sitev2.bTemp;
				site->cConnsNow = sitev2.cConnsNow;
				site->cMaxConns = sitev2.cMaxConns;
				site->dwValidFor = sitev2.dwValidFor;
			}
		}

		if (!fsReadStrFromFile (&site->strName.pszString, hFile))
			return FALSE;

		if (!fsReadStrFromFile (&site->strPassword.pszString, hFile))
			return FALSE;

		if (!fsReadStrFromFile (&site->strUser.pszString, hFile))
			return FALSE;

		if (hdr.wVer >= 3)
		{
			UINT nId;
			if (!ReadFile (hFile, &nId, sizeof (nId), &dw, NULL))
				return FALSE;
			site->pGroup = nId != (UINT)-1 ? _DldsGrps.FindGroup (nId) : NULL;

			if (!ReadFile (hFile, &site->dwFtpFlags, sizeof (site->dwFtpFlags), &dw, NULL))
				return FALSE;

			if (!ReadFile (hFile, &site->cConnsNow, sizeof (site->cConnsNow), &dw, NULL))
				return FALSE;

			if (!ReadFile (hFile, &site->cMaxConns, sizeof (site->cMaxConns), &dw, NULL))
				return FALSE;

			if (!ReadFile (hFile, &site->dwValidFor, sizeof (site->dwValidFor), &dw, NULL))
				return FALSE;
		}

		site->cConnsNow = 0;
		site->bTemp = FALSE;

		AddSite (site);
	}

	return TRUE;	
}

bool fsSitesMgr::loadObjectItselfFromStateBuffer(LPBYTE pbtBuffer, LPDWORD pdwSize, DWORD dwVer)
{
	vmsAUTOLOCKSECTION (m_csSites);

	LPBYTE pbtCurrentPos = pbtBuffer;

	int cSites = 0;

	m_vSites.clear ();

	if (!getVarFromBuffer(cSites, pbtCurrentPos, pbtBuffer, *pdwSize))
		return false;
	
	for (int i = 0; i < cSites; i++) {
		fsSiteInfoPtr site;
		site.CreateInstance ();

		if (dwVer <= 1) {
			fsSiteInfo_v1 sitev1;

			if (!getVarFromBuffer(sitev1, pbtCurrentPos, pbtBuffer, *pdwSize))
				return false;

			site->dwFtpFlags = sitev1.bFtpPassive;
			site->bTemp = sitev1.bTemp;
			site->cConnsNow = sitev1.cConnsNow;
			site->cMaxConns = sitev1.cMaxConns;
			site->dwValidFor = SITE_VALIDFOR_HTTP|SITE_VALIDFOR_HTTPS|SITE_VALIDFOR_FTP|SITE_VALIDFOR_SUBDOMAINS;

		} else {
			if (dwVer < 3) {

				fsSiteInfo_v2 sitev2;

				if (!getVarFromBuffer(sitev2, pbtCurrentPos, pbtBuffer, *pdwSize))
					return false;

				if (!getStrFromBuffer(&sitev2.strGroup.pszString, pbtCurrentPos, pbtBuffer, *pdwSize))
					return false;

				site->dwFtpFlags = sitev2.dwFtpFlags;
				site->bTemp = sitev2.bTemp;
				site->cConnsNow = sitev2.cConnsNow;
				site->cMaxConns = sitev2.cMaxConns;
				site->dwValidFor = sitev2.dwValidFor;
			}
		}

		if (!getStrFromBuffer(&site->strName.pszString, pbtCurrentPos, pbtBuffer, *pdwSize))
			return false;

		if (!getStrFromBuffer(&site->strPassword.pszString, pbtCurrentPos, pbtBuffer, *pdwSize))
			return false;

		if (!getStrFromBuffer(&site->strUser.pszString, pbtCurrentPos, pbtBuffer, *pdwSize))
			return false;

		if (dwVer >= 3) {

			UINT nId;
			if (!getVarFromBuffer(nId, pbtCurrentPos, pbtBuffer, *pdwSize))
				return false;
			site->pGroup = nId != (UINT)-1 ? _DldsGrps.FindGroup (nId) : NULL;

			if (!getVarFromBuffer(site->dwFtpFlags, pbtCurrentPos, pbtBuffer, *pdwSize))
				return false;

			if (!getVarFromBuffer(site->cConnsNow, pbtCurrentPos, pbtBuffer, *pdwSize))
				return false;

			if (!getVarFromBuffer(site->cMaxConns, pbtCurrentPos, pbtBuffer, *pdwSize))
				return false;

			if (!getVarFromBuffer(site->dwValidFor, pbtCurrentPos, pbtBuffer, *pdwSize))
				return false;
		}

		site->cConnsNow = 0;
		site->bTemp = FALSE;

		AddSite (site);
	}

	*pdwSize = pbtCurrentPos - pbtBuffer;

	return true;
}

void fsSitesMgr::SiteUpdated(fsSiteInfo *pSite)
{
	Event (SM_SITEUPDATED, pSite);
}

void fsSitesMgr::DeleteAllPasswords()
{
	vmsAUTOLOCKSECTION (m_csSites);
	for (int i = m_vSites.size () - 1; i >= 0; i--)
	{
		fsSiteInfo* site = m_vSites [i];
		site->strUser = NULL;
		site->strPassword = NULL;
		setDirty();
		SiteUpdated (site);
	}
}

void fsSitesMgr::CheckGroups()
{
	vmsAUTOLOCKSECTION (m_csSites);

	std::vector <fsSiteInfoPtr> v;

	for (int i = m_vSites.size () - 1; i >= 0; i--)
	{
		fsSiteInfo *site = m_vSites [i];
		if (site->pGroup != NULL && site->pGroup->bAboutToBeDeleted)
		{
			site->pGroup = NULL;
			setDirty();
			v.push_back (site);
		}
	}

	vmsAUTOLOCKSECTION_UNLOCK (m_csSites);	

	for (size_t j = 0; j < v.size (); j++)
		SiteUpdated (v [j]);
}

void fsSitesMgr::LockList(bool bLock)
{
	if (bLock)
		EnterCriticalSection (&m_csSites);
	else
		LeaveCriticalSection (&m_csSites);
}

void fsSitesMgr::LockList(vmsCriticalSectionAutoLock& csal)
{
	csal.Attach (&m_csSites);
}
