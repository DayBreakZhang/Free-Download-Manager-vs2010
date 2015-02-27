/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "Utils.h"
#include "FdmApp.h"
#include "vmsMediaConvertMgr.h"
#include "WaitDlg.h"
#include "vmsMediaConverter.h"
#include "Dlg_Convert.h"
#include "mfchelp.h"
#include "MyMessageBox.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

bool vmsMediaConvertMgr::vmsConvertMediaFileContext::loadObjectItselfFromStateBuffer(LPBYTE pbtBuffer, LPDWORD pdwSize, DWORD dwVer)
{
	LPBYTE pbtCurrentPos = pbtBuffer;

	int nId = 0;

	if (!getVarFromBuffer(nId, pbtCurrentPos, pbtBuffer, *pdwSize))
		return false;

	if (!getStrFromBuffer(&stgs.strFormat.pszString, pbtCurrentPos, pbtBuffer, *pdwSize))
		return false;

	if (!getStrFromBuffer(&stgs.strExtension.pszString, pbtCurrentPos, pbtBuffer, *pdwSize))
		return false;

	if (!getStrFromBuffer(&stgs.strAudioCodec.pszString, pbtCurrentPos, pbtBuffer, *pdwSize))
		return false;

	if (!getStrFromBuffer(&stgs.strVideoCodec.pszString, pbtCurrentPos, pbtBuffer, *pdwSize))
		return false;

	if (!getVarFromBuffer(stgs.nAudioBitrate, pbtCurrentPos, pbtBuffer, *pdwSize))
		return false;

	if (!getVarFromBuffer(stgs.nVideoBitrate, pbtCurrentPos, pbtBuffer, *pdwSize))
		return false;

	if (!getVarFromBuffer(stgs.sizeVideo, pbtCurrentPos, pbtBuffer, *pdwSize))
		return false;

	if (!clehEventHandler(nId, this, pvData))
		return false;

	*pdwSize = pbtCurrentPos - pbtBuffer;

	return true;
}

void vmsMediaConvertMgr::vmsConvertMediaFileContext::getObjectItselfStateBuffer(LPBYTE pbtBuffer, LPDWORD pdwSize, bool bSaveToStorage)
{
	DWORD dwRequiredSize = 0;
	LPBYTE pbtCurrentPos = pbtBuffer;

	putVarToBuffer(dld->nID, pbtCurrentPos, 0, 0, &dwRequiredSize);
	putStrToBuffer(stgs.strFormat.pszString, pbtCurrentPos, 0, 0, &dwRequiredSize);
	putStrToBuffer(stgs.strExtension.pszString, pbtCurrentPos, 0, 0, &dwRequiredSize);
	putStrToBuffer(stgs.strAudioCodec.pszString, pbtCurrentPos, 0, 0, &dwRequiredSize);
	putStrToBuffer(stgs.strVideoCodec, pbtCurrentPos, 0, 0, &dwRequiredSize);
	putVarToBuffer(stgs.nAudioBitrate, pbtCurrentPos, 0, 0, &dwRequiredSize);
	putVarToBuffer(stgs.nVideoBitrate, pbtCurrentPos, 0, 0, &dwRequiredSize);
	putVarToBuffer(stgs.sizeVideo, pbtCurrentPos, 0, 0, &dwRequiredSize);

	if (pbtBuffer == NULL) {
		if (pdwSize) {
			*pdwSize = dwRequiredSize;
		}
		return;
	}

	if (pdwSize == 0)
		return;

	putVarToBuffer(dld->nID, pbtCurrentPos, pbtBuffer, *pdwSize, &dwRequiredSize);
	putStrToBuffer(stgs.strFormat.pszString, pbtCurrentPos, pbtBuffer, *pdwSize, &dwRequiredSize);
	putStrToBuffer(stgs.strExtension.pszString, pbtCurrentPos, pbtBuffer, *pdwSize, &dwRequiredSize);
	putStrToBuffer(stgs.strAudioCodec.pszString, pbtCurrentPos, pbtBuffer, *pdwSize, &dwRequiredSize);
	putStrToBuffer(stgs.strVideoCodec, pbtCurrentPos, pbtBuffer, *pdwSize, &dwRequiredSize);
	putVarToBuffer(stgs.nAudioBitrate, pbtCurrentPos, pbtBuffer, *pdwSize, &dwRequiredSize);
	putVarToBuffer(stgs.nVideoBitrate, pbtCurrentPos, pbtBuffer, *pdwSize, &dwRequiredSize);
	putVarToBuffer(stgs.sizeVideo, pbtCurrentPos, pbtBuffer, *pdwSize, &dwRequiredSize);

	*pdwSize = pbtCurrentPos - pbtBuffer;
}

vmsMediaConvertMgr::vmsMediaConvertMgr()
	
	
{
}

vmsMediaConvertMgr::~vmsMediaConvertMgr()
{

}

void vmsMediaConvertMgr::AddTask(vmsDownloadSmartPtr dld, const vmsMediaFileConvertSettings &stgs)
{
	vmsConvertMediaFileContextSmartPtr pCtxPtr;
	pCtxPtr.CreateInstance();

	
	pCtxPtr->dld = dld;
	pCtxPtr->stgs = stgs;
	m_vTasks.push_back (pCtxPtr);
	setDirty();
	m_vTasks.back()->setDirty();
	getPersistObjectChildren ()->addPersistObject ((vmsConvertMediaFileContext*)m_vTasks.back());
	
	
}

BOOL vmsMediaConvertMgr::SaveState()
{
	
	
	
	
	
	
	
	
	
	
	

	if (!isDirty())
		return TRUE;

	CString strFile = fsGetDataFilePath ("mctasks.sav");
	HANDLE hFile = CreateFile (strFile, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS,
		FILE_ATTRIBUTE_HIDDEN, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
		return FALSE;

	DWORD dw;
	std::auto_ptr<BYTE> apbtBufferGuard;

	fsMcMgrFileHdr hdr;
	if (FALSE == WriteFile (hFile, &hdr, sizeof (hdr), &dw, NULL))
		goto _lErr;

	DWORD dwRequiredSize = 0;

	getStateBuffer(0, &dwRequiredSize, false);

	if (dwRequiredSize == 0)
		goto _lErr;

	apbtBufferGuard.reset( new BYTE[dwRequiredSize] );
	LPBYTE pbtBuffer = apbtBufferGuard.get();
	if (pbtBuffer == 0)
		goto _lErr;
	memset(pbtBuffer, 0, dwRequiredSize);

	getStateBuffer(pbtBuffer, &dwRequiredSize, true);

	if (FALSE == WriteFile (hFile, pbtBuffer, dwRequiredSize, &dw, NULL) || dw != dwRequiredSize) {
		goto _lErr;
	}
	CloseHandle (hFile);
	onStateSavedSuccessfully();

	return TRUE;

_lErr:
	CloseHandle (hFile);
	DeleteFile (strFile);
	return FALSE;
}

BOOL vmsMediaConvertMgr::LoadState()
{
	CString strFile = fsGetDataFilePath ("mctasks.sav");
	HANDLE hFile = CreateFile (strFile, GENERIC_READ, 0, NULL, OPEN_EXISTING,
		FILE_ATTRIBUTE_HIDDEN, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
		return GetFileAttributes (strFile) == DWORD (-1);

	DWORD dwRequiredSize = ::GetFileSize(hFile, NULL);

	DWORD dw;
	std::auto_ptr<BYTE> pbtBufferGuard;

	fsMcMgrFileHdr hdr;
	if (FALSE == ReadFile (hFile, &hdr, sizeof (hdr), &dw, NULL))
		goto _lErr;

	if (lstrcmp (hdr.szSig, MCMGRFILE_SIG) || hdr.wVer > MCMGRFILE_CURRENT_VERSION)
		goto _lErr;

	dwRequiredSize -= sizeof (hdr);
	if (dwRequiredSize <= 0) {
		goto _lErr;
	}

	pbtBufferGuard.reset( new BYTE[dwRequiredSize] );
	LPBYTE pbtBuffer = pbtBufferGuard.get();
	if (pbtBuffer == 0) {
		goto _lErr;
	}
	memset(pbtBuffer, 0, dwRequiredSize);

	if (!ReadFile (hFile, pbtBuffer, dwRequiredSize, &dw, NULL) || dw != dwRequiredSize) {
		goto _lErr;
	}
	CloseHandle (hFile);

	if (!loadFromStateBuffer(pbtBuffer, &dwRequiredSize, hdr.wVer))
		goto _lErr;

	return TRUE;

_lErr:
	CloseHandle (hFile);
	DeleteFile (strFile);
	return FALSE;
}

DWORD WINAPI vmsMediaConvertMgr::_threadConvertMediaFile(LPVOID lp)
{
	ProcWaitInfo *info = (ProcWaitInfo*) lp;

	vmsConvertMediaFileContext *pcmfc  = (vmsConvertMediaFileContext*) info->lpParam1;
	BOOL bDontDeleteSourceFile = (BOOL)info->lpParam2;

	CString strDst = pcmfc->dld->pMgr->get_OutputFilePathName ();
	strDst = strDst.Left (strDst.GetLength () - 4); 

	for (int i = 0; ; i++)
	{
		CString str;
		if (i)
			str.Format ("%s (%d).%s", strDst, i, pcmfc->stgs.strExtension);
		else
			str.Format ("%s.%s", strDst, pcmfc->stgs.strExtension);

		if (GetFileAttributes (str) == DWORD (-1))
		{
			strDst = str;
			break;
		}
	}
	
	_DldsMgr.AddEvent (pcmfc->dld, LS (L_CONVERTING), EDT_INQUIRY);

	if (vmsMediaConverter::ConvertMedia (pcmfc->dld->pMgr->get_OutputFilePathName (), 
			strDst, pcmfc->stgs.strFormat, pcmfc->stgs.strAudioCodec, -1, pcmfc->stgs.nAudioBitrate, -1, 
			pcmfc->stgs.strVideoCodec, pcmfc->stgs.nVideoBitrate, -1, pcmfc->stgs.sizeVideo.cx, pcmfc->stgs.sizeVideo.cy,
			&info->iProgress, &info->bNeedStop))
	{
		if (bDontDeleteSourceFile == FALSE)
		{
			pcmfc->dld->pMgr->DeleteFile ();

			fsDownload_Properties *dp = pcmfc->dld->pMgr->GetDownloadMgr ()->GetDP ();
			delete [] dp->pszFileName;
			dp->pszFileName = new char [strDst.GetLength () + 1];
			lstrcpy (dp->pszFileName, strDst);
			pcmfc->dld->pMgr->GetDownloadMgr ()->setDirty();
		}
		else
		{
			CString strDst2 = strDst;
			strDst2.SetAt (strDst2.GetLength () - 3, 't');
			strDst2.SetAt (strDst2.GetLength () - 2, 'm');
			strDst2.SetAt (strDst2.GetLength () - 1, 'p');
			if (FALSE == MoveFile (strDst, strDst2))
				strDst2 = strDst;
			CString strFilter; 
			strFilter.Format ("%s files (*.%s)|*.%s||", pcmfc->stgs.strExtension,
				pcmfc->stgs.strExtension, pcmfc->stgs.strExtension);
			CFileDialog dlg (FALSE, pcmfc->stgs.strExtension, strDst, 
				OFN_OVERWRITEPROMPT|OFN_NOCHANGEDIR, strFilter, AfxGetApp ()->m_pMainWnd);
			if (IDCANCEL == _DlgMgr.DoModal (&dlg))
			{
				DeleteFile (strDst2);
			}
			else
			{
				strDst = dlg.GetPathName ();

				MoveFile (strDst2, strDst);

				info->bWaitDone = TRUE;

				CString strMsg;
				strMsg.Format (LS (L_CONVERTED_OK), strDst);
				UINT nRet = MyMessageBox (NULL, strMsg, LS (L_DONE), NULL, IDI_QUESTION, 
					LS (L_LAUNCH), LS (L_OPENFOLDER), "OK");

				if (nRet == IDC_BTN1)
				{
					ShellExecute (0, "open", strDst, NULL, NULL, SW_SHOW);
				}
				else if (nRet == IDC_BTN2)
				{
					CString strCmd;
					strCmd.Format ("/select,\"%s\"", strDst);
					ShellExecute (NULL, "open", "explorer.exe", strCmd, NULL, SW_SHOW);
				}
			}
		}

		_DldsMgr.AddEvent (pcmfc->dld, LS (L_DONE), EDT_RESPONSE_S);

		if (bDontDeleteSourceFile == FALSE)
			_DldsMgr.DownloadStateChanged (pcmfc->dld);
	}
	else
	{
		DeleteFile (strDst);
		_DldsMgr.AddEvent (pcmfc->dld, info->bNeedStop ? LS (L_CANCELED) : LS (L_FAILED), 
			EDT_RESPONSE_E);
		info->bWaitDone = TRUE;
		if (info->bNeedStop == FALSE)
		{
			CString strMsg;
			strMsg.Format (LS (L_CONVERTED_FAILED), pcmfc->dld->pMgr->get_OutputFilePathName ());
			MessageBox (NULL, strMsg, LS (L_FAILED), MB_ICONERROR); 
		}
	}

	info->bWaitDone = TRUE;
	delete pcmfc;

	return 0;
}

void vmsMediaConvertMgr::ConvertMediaFile(vmsDownloadSmartPtr dld, vmsMediaConvertMgr_OptionsSource enOs)
{
	vmsConvertMediaFileContext *pcmfc = new vmsConvertMediaFileContext;

	if (enOs == MCM_OS_SEARCH_IN_MGR)
	{
		int nIndex = FindDownload (dld);
		if (nIndex == -1)
			return;

		vmsConvertMediaFileContext* ctx = (vmsConvertMediaFileContext*)m_vTasks [nIndex];
		if (ctx == 0)
			return;
		pcmfc->dld = ctx->dld;	
		pcmfc->stgs = ctx->stgs;
		
		
		m_vTasks.erase (m_vTasks.begin () + nIndex);
		setDirty();
		getPersistObjectChildren ()->removePersistObject (nIndex);
		
		
	}
	else
	{
		pcmfc->dld = dld;
		GetDefaultSettings (pcmfc->stgs);

		if (enOs == MCM_OS_SHOW_OPTIONS_UI)
		{
			CDlg_Convert dlg (&pcmfc->stgs);
			if (IDOK != _DlgMgr.DoModal (&dlg))
			{
				delete pcmfc;
				return;
			}
		}
	}

	CWaitDlg *dlg = new CWaitDlg;
	dlg->StartWaiting (LS (L_CONVERTING), _threadConvertMediaFile, TRUE, pcmfc, 
		(LPVOID)(enOs == MCM_OS_SHOW_OPTIONS_UI), 
		NULL, NULL, NULL, NULL, FALSE);
}

int vmsMediaConvertMgr::FindDownload(vmsDownloadSmartPtr dld)
{
	for (size_t i = 0; i < m_vTasks.size (); i++)
	{
		
		
		
		if (m_vTasks [i]->dld->nID == dld->nID)
			return i;
	}

	return -1;
}

void vmsMediaConvertMgr::ConvertMediaFile_SetupDefaultOptions()
{
	vmsMediaFileConvertSettings stgs;
	GetDefaultSettings (stgs);
	CDlg_Convert dlg (&stgs);
	dlg.m_bCustomizingDefSettings = true;
	_DlgMgr.DoModal (&dlg);
}

void vmsMediaConvertMgr::GetDefaultSettings(vmsMediaFileConvertSettings &stgs)
{
	stgs.strFormat = _App.Convert_Format ();
	stgs.strExtension = _App.Convert_Extension ();
	stgs.sizeVideo = _App.Convert_VideoSize ();
	stgs.nAudioBitrate = _App.Convert_AudioBitrate ();
	stgs.nVideoBitrate = _App.Convert_VideoBitrate ();
	stgs.strAudioCodec = _App.Convert_AudioCodec ();
	stgs.strVideoCodec = _App.Convert_VideoCodec ();
}

void vmsMediaConvertMgr::SaveSettingsAsDefault(const vmsMediaFileConvertSettings &stgs)
{
	_App.Convert_AudioBitrate (stgs.nAudioBitrate);
	_App.Convert_Format (stgs.strFormat);
	_App.Convert_VideoBitrate (stgs.nVideoBitrate);
	_App.Convert_VideoSize (stgs.sizeVideo);
	_App.Convert_VideoCodec (stgs.strVideoCodec);
	_App.Convert_AudioCodec (stgs.strAudioCodec);
	_App.Convert_Extension (stgs.strExtension);
}

BOOL vmsMediaConvertMgr::ShowSettingsUI(vmsMediaFileConvertSettings &stgs)
{
	CDlg_Convert dlg (&stgs);
	return IDOK == _DlgMgr.DoModal (&dlg);
}

bool vmsMediaConvertMgr::loadObjectItselfFromStateBuffer(LPBYTE pbtBuffer, LPDWORD pdwSize, DWORD dwVer)
{
	if (pbtBuffer == NULL || pdwSize == NULL)
		return false;

	if (*pdwSize < sizeof(size_t))
		return false;

	m_vTasks.clear ();

	size_t* pszBuffer = (size_t*)pbtBuffer;
	size_t szTaskCount = *pszBuffer;

	size_t szIndex = 0;
	for (szIndex = 0; szIndex < szTaskCount; szIndex++) {
		vmsMediaConvertMgr::vmsConvertMediaFileContextSmartPtr pCtxPtr;
		pCtxPtr.CreateInstance();
		m_vTasks.push_back(pCtxPtr);
		vmsMediaConvertMgr::vmsConvertMediaFileContext* ctx = (vmsMediaConvertMgr::vmsConvertMediaFileContext*)m_vTasks.back();
		if (ctx == 0)
			return false;
		ctx->pvData = &m_vTasks;
		ctx->clehEventHandler = FdmCtfxLoadEventhandler;
		getPersistObjectChildren ()->addPersistObject ((vmsPersistObject*)(vmsMediaConvertMgr::vmsConvertMediaFileContext*)m_vTasks.back());
	}

	*pdwSize = sizeof(size_t);

	return true;
}

void vmsMediaConvertMgr::getObjectItselfStateBuffer(LPBYTE pbtBuffer, LPDWORD pdwSize, bool bSaveToStorage)
{
	if (pbtBuffer == NULL) {
		if (pdwSize) {
			*pdwSize = sizeof(size_t);
		}
		return;
	}

	size_t* pszBuffer = (size_t*)pbtBuffer;
	*pszBuffer = m_vTasks.size ();
	*pdwSize = sizeof(size_t);
}

bool vmsMediaConvertMgr::FdmCtfxLoadEventhandler(int nId, vmsMediaConvertMgr::vmsConvertMediaFileContext* ctx, void* pvData)
{
	if (ctx == 0)
		return false;

	std::vector <vmsConvertMediaFileContextSmartPtr>* pvTasks = (std::vector <vmsConvertMediaFileContextSmartPtr>*)pvData;
	if (pvTasks == 0)
		return false;

	std::vector <vmsConvertMediaFileContextSmartPtr>::iterator iter = pvTasks->begin();
	while (iter != pvTasks->end()) {
		if (ctx == (vmsConvertMediaFileContext*)(*iter)) {
			ctx->dld = _DldsMgr.GetDownloadByID (nId);
			if (ctx->dld == NULL) {
				pvTasks->erase(iter);
			}
			break;
		}
		iter++;
	}

	return true;
}

