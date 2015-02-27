/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "Downloads_VideoPreview.h"
#include "fsDownloadsMgr.h"
#include "fsDirectXVersion.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDownloads_VideoPreview::CDownloads_VideoPreview()
{
	m_hFile = INVALID_HANDLE_VALUE;
	m_vidman.m_parent = this;
	m_pActiveDownload = NULL;
	m_dwDXVersion = 0;
	m_bUsingVideo2 = FALSE;
}

CDownloads_VideoPreview::~CDownloads_VideoPreview()
{
	
}

BEGIN_MESSAGE_MAP(CDownloads_VideoPreview, CWnd)
	//{{AFX_MSG_MAP(CDownloads_VideoPreview)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_ERASEBKGND()
	ON_MESSAGE (WM_VIDEONOTIFY, OnGraphMessage)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CDownloads_VideoPreview::Set_ActiveDownload(vmsDownloadSmartPtr dld)
{
	if (m_pActiveDownload != dld)
	{
		Stop ();
		m_pActiveDownload = dld;
		m_vidman.Update ();
	}
}

BOOL CDownloads_VideoPreview::Create(CWnd *pWndParent)
{
	CRect rc (0, 0, 50, 50);

	if (FALSE == CWnd::Create (AfxRegisterWndClass (0, LoadCursor (NULL, IDC_ARROW), (HBRUSH) (COLOR_WINDOW+1), NULL) ,
			NULL, WS_CHILD, rc, pWndParent, 0x121a))
		return FALSE;

	return TRUE;
}

int CDownloads_VideoPreview::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (FALSE == m_wndVideo.Create (this))
		return -1;

	m_vidman.Create (IDD_VIDMAN, this);
	m_vidman.ShowWindow (SW_SHOW);

	m_vidseek.Create (IDD_VIDSEEK, this);
	m_vidseek.ShowWindow (SW_SHOW);

	m_vidseek.m_hWndDuration = m_vidman.GetDlgItem (IDC__DURATIONVAL)->m_hWnd;

	return 0;
}

void CDownloads_VideoPreview::OnSize(UINT nType, int cx, int cy) 
{
	CWnd::OnSize(nType, cx, cy);
	
	if (cx == 0 || cy == 0)
		return;

	RECT rc;
	m_vidman.GetClientRect (&rc);

	int cx_vidman = rc.right;

	m_vidseek.GetClientRect (&rc);

	int cy_vidseek = rc.bottom;

	m_wndVideo.MoveWindow (2, 2, cx - cx_vidman, cy - cy_vidseek);
	if (m_bUsingVideo2)
		m_wndVideo2.MoveWindow (2, 2, cx - cx_vidman, cy - cy_vidseek);
	m_vidman.MoveWindow (cx - cx_vidman, 2, cx_vidman, cy);
	m_vidseek.MoveWindow (2, cy - cy_vidseek, cx - cx_vidman, cy_vidseek);
}

BOOL CDownloads_VideoPreview::OnEraseBkgnd(CDC* pDC) 
{
	
	
	
	
	if (m_wndVideo.m_player.Get_State () != VFPS_CLOSED)
	{
    	CRect rc;

		
		m_wndVideo.GetWindowRect(&rc);
		ScreenToClient(&rc);

		
		pDC->ExcludeClipRect(&rc);
	}

	return CWnd::OnEraseBkgnd(pDC);
}

LRESULT CDownloads_VideoPreview::WindowProc(UINT message, WPARAM wParam, LPARAM lParam) 
{
	m_wndVideo.m_player.NotifyOwnerMessage (m_hWnd, message, wParam, lParam);
	return CWnd::WindowProc(message, wParam, lParam);
}

void CDownloads_VideoPreview::Stop()
{
	if (m_bUsingVideo2 == FALSE)
	{
		m_vidseek.Set_MediaSeeking (NULL);
		m_wndVideo.m_player.Close ();
	}
	else
	{
		m_bUsingVideo2 = FALSE;
		m_wndVideo2.DestroyWindow ();
		m_wndVideo.ShowWindow (SW_SHOW);
	}
	m_vidman.Update ();
	CloseFile ();
}

void CDownloads_VideoPreview::Pause()
{
	m_wndVideo.m_player.Pause ();
	m_vidman.Update ();
}

vmsDownloadSmartPtr CDownloads_VideoPreview::Get_ActiveDownload()
{
	return m_pActiveDownload;
}

void CDownloads_VideoPreview::Play()
{
	USES_CONVERSION;

	if (m_bUsingVideo2)
		return;

	if (m_wndVideo.m_player.Get_State () != VFPS_CLOSED)
	{
		if (m_wndVideo.m_player.Get_State () != VFPS_RUNNING)
			m_wndVideo.m_player.Run ();
		return;
	}
 
 	if (m_pActiveDownload)
 	{
 		HRESULT hr = E_FAIL;
		BOOL bWasErrMsg = FALSE;

		
		if (S_FALSE == CoInitialize (NULL))
			CoUninitialize ();
		 
 		if (m_pActiveDownload->pMgr->IsDone ())
 		{	
			hr = m_wndVideo.m_player.Open2 (m_pActiveDownload->pMgr->get_OutputFilePathName ());

			if (FAILED (hr))
			{
				fsString strFile = m_pActiveDownload->pMgr->get_OutputFilePathName ();
				LPCSTR psz = strrchr (strFile, '.');
				if (psz++)
				{
					if (lstrcmpi (psz, "flv") == 0)
					{
						CRect rc (0,0,0,0);
						m_wndVideo.GetWindowRect (&rc);
						ScreenToClient (&rc);
						m_wndVideo2.Create (NULL, WS_CHILD, rc, this, 0x111a);
						m_wndVideo2.SetBackgroundColor (0);
						m_wndVideo2.LoadMovie (0, ((CFdmApp*)AfxGetApp ())->m_strAppPath + "player.swf");

						m_wndVideo.ShowWindow (SW_HIDE);
						m_wndVideo2.ShowWindow (SW_SHOW);
						m_bUsingVideo2 = TRUE;
	
						CString str;
						str = "<invoke name=\"loadAndPlayVideo\" returntype=\"xml\">";
						str += "<arguments><string>"; str += strFile;
						str += "</string></arguments></invoke>";
						m_wndVideo2.CallFunction (str);

						hr = S_OK;
					}
				}
			}

			
 		}
 		else
 		{
			UINT64 nAvail = Get_AvailFileSize ();

 			if (nAvail)
 			{
  				if (FALSE == OpenFile ())
				{
					hr = E_FAIL;
					bWasErrMsg = TRUE;
				}
				else
 					hr = m_wndVideo.m_player.Open (m_hFile, nAvail);

				if (FAILED (hr) && bWasErrMsg == FALSE)
				{
					CloseFile ();
					hr = m_wndVideo.m_player.Open2 (m_pActiveDownload->pMgr->get_OutputFilePathName ());
				}
			}
			else
				bWasErrMsg = TRUE;
 		}
 
 		if (FAILED (hr))
		{
			CloseFile ();

 			if (bWasErrMsg == FALSE)
			{
				if (m_dwDXVersion == 0)
					m_dwDXVersion = fsDirectXVersion::GetCurrentVersion ();

				if (m_dwDXVersion < 0x0800)
				{
					CString strErr = LS (L_FAILEDTOOPENFILE);
					strErr += "\n\n"; strErr += LS (L_NEEDDX8ORBETTER);
					MessageBox (strErr, LS (L_ERR), MB_ICONERROR);
				}
				else
				{
					CString strErr = LS (L_FAILEDTOOPENFILE);
					strErr += "\n\n"; strErr += LS (L_UNKMEDIATYPE);
					MessageBox (strErr, LS (L_ERR), MB_ICONERROR);
				}
			}

			m_vidseek.Set_MediaSeeking (NULL);
			return;
		}

		if (m_bUsingVideo2 == FALSE)
		{
			IMediaSeeking* pMS = Get_Player ()->Get_MediaSeeking ();
			m_vidseek.Set_MediaSeeking (pMS);
			if (pMS)
				pMS->Release ();

			m_wndVideo.m_player.Run ();
			m_vidman.ApplyVolumeSettings ();
		}
 	}
}

fsPartMediaPlayer* CDownloads_VideoPreview::Get_Player()
{
	return &m_wndVideo.m_player;
}

LRESULT CDownloads_VideoPreview::OnGraphMessage(WPARAM, LPARAM)
{
	Get_Player ()->HandleGraphEvent ();

	if (Get_Player ()->Get_State () == VFPS_STOPPED)
		Stop (); 

	m_vidman.Update ();
	return 0;
}

void CDownloads_VideoPreview::Set_Volume(long lVolume)
{
	Get_Player ()->Set_Volume (lVolume);
}

CString CDownloads_VideoPreview::Get_FileName()
{
	if (m_pActiveDownload == NULL)
		return "";

	char szFile [10000];
	*szFile = 0;
	CDownloads_Tasks::GetFileName (m_pActiveDownload, szFile);
	return szFile;
}

UINT64 CDownloads_VideoPreview::Get_FileSize()
{
	if (m_pActiveDownload == NULL)
		return 0;

	return m_pActiveDownload->pMgr->GetLDFileSize ();
}

UINT64 CDownloads_VideoPreview::Get_AvailFileSize()
{
	if (m_pActiveDownload == NULL)
		return 0;

	if (m_pActiveDownload->pMgr->IsDone ())
		return m_pActiveDownload->pMgr->GetLDFileSize ();

	if (m_pActiveDownload->pMgr->GetNumberOfSections ())
 	{
		UINT64 uRes = 0;
		

		if (m_pActiveDownload->pMgr->GetBtDownloadMgr () == FALSE)
		{
			BOOL bDone;

			do
			{
				bDone = TRUE;
	
		 		for (int i = 0; i < m_pActiveDownload->pMgr->GetNumberOfSections (); i++)
				{
					vmsSectionInfo sect;
 					m_pActiveDownload->pMgr->GetSectionInfo (i, &sect, TRUE);

					if (uRes == sect.uDStart)
					{
						uRes = sect.uDCurrent;
						bDone = sect.uDCurrent != sect.uDEnd || sect.uDEnd == 0;
						break;
					}
				}
			}
			while (bDone == FALSE);
		}
		else
		{
	 		uRes = m_pActiveDownload->pMgr->GetBtDownloadMgr ()->get_SplittedByteCountAtBeginningOfFile ();
		}

		return uRes;
	}

	return 0;
}

CString CDownloads_VideoPreview::GetDuration()
{
	return m_vidseek.GetDuration ();
}

void CDownloads_VideoPreview::UpdateCommand(UINT nID, BOOL *pbEnabled, BOOL *pbChecked)
{
	m_vidman.UpdateCommand (nID, pbEnabled, pbChecked);
}

void CDownloads_VideoPreview::SaveState()
{
	m_vidman.SaveSettings ();
}

BOOL CDownloads_VideoPreview::OpenFile()
{
	CloseFile ();

	fsString strFile = m_pActiveDownload->pMgr->get_OutputFilePathName ();
 
 	m_hFile = CreateFile (strFile, GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE,
 		NULL, OPEN_EXISTING, 0, NULL);
 
 	if (m_hFile == INVALID_HANDLE_VALUE)
 	{
		char szErr [10000];
		fsErrorToStr (szErr, 10000, NULL);
		CString strErr = LS (L_FAILEDTOOPENFILE);
		strErr += "\n\n"; strErr += szErr;
		MessageBox (strErr, LS (L_ERR), MB_ICONERROR);
		return FALSE;
	}

	return TRUE;
}

void CDownloads_VideoPreview::CloseFile()
{
	if (m_hFile != INVALID_HANDLE_VALUE)
	{
 		CloseHandle (m_hFile);
		m_hFile = INVALID_HANDLE_VALUE;
	}
}

void CDownloads_VideoPreview::ApplyLanguage()
{
	m_vidman.ApplyLanguage ();
}

void CDownloads_VideoPreview::Convert()
{
	m_vidman.Convert ();
}

void CDownloads_VideoPreview::set_InFVDownloads(BOOL b)
{
	m_vidman.m_bInFVDownloads = b;
}

BOOL CDownloads_VideoPreview::IsPlaying()
{
	return m_bUsingVideo2 || Get_Player ()->Get_State () == VFPS_RUNNING;
}

BOOL CDownloads_VideoPreview::IsPauseAvail()
{
	return !m_bUsingVideo2;
}

BOOL CDownloads_VideoPreview::IsPaused()
{
	if (m_bUsingVideo2)
		return FALSE;
	return Get_Player ()->Get_State () == VFPS_PAUSED;
}

BOOL CDownloads_VideoPreview::IsMuteAvail()
{
	return !m_bUsingVideo2;
}
