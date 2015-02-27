/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "fsSoundsMgr.h"
#include <mmsystem.h>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

fsSoundsMgr::fsSoundsMgr()
{

}

fsSoundsMgr::~fsSoundsMgr()
{

}

void fsSoundsMgr::ReadSettings()
{
	m_bUseSounds = _App.Snd_Use ();
	m_strDownloadComplete = _App.Snd_DownloadComplete ();
	m_strDownloadAdded = _App.Snd_DownloadAdded ();
	m_strNoActiveDownloads = _App.Snd_NoActiveDownloads ();
	m_strDialingOK = _App.Snd_DialingOK ();
	m_strDialingFailed = _App.Snd_DialingFailed ();
	m_strDownloadFailed = _App.Snd_DownloadFailed ();
}

void fsSoundsMgr::Event(fsSoundsMgrEvent ev)
{
	if (FALSE == m_bUseSounds)
		return;

	switch (ev)
	{
		case SME_DOWNLOADCOMPLETE:
			PlaySnd (m_strDownloadComplete);
			break;

		case SME_DOWNLOADADDED:
			PlaySnd (m_strDownloadAdded);
			break;

		case SME_NOACTIVEDOWNLOADS:
			PlaySnd (m_strNoActiveDownloads);
			break;

		case SME_DIALINGOK:
			PlaySnd (m_strDialingOK);
			break;

		case SME_DIALINGFAILED:
			PlaySnd (m_strDialingFailed);
			break;

		case SME_DOWNLOADFAILED:
			PlaySnd (m_strDownloadFailed);
			break;
	}
}

void fsSoundsMgr::PlaySnd(LPCSTR pszSoundFile)
{
	if (pszSoundFile == NULL || *pszSoundFile == 0)
		return;

	PlaySound (pszSoundFile, NULL, SND_ASYNC | SND_FILENAME | SND_NODEFAULT);
}
