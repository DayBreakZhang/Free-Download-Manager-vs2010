/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "UploadsWnd.h"
#include "cmds.h"
#include "DlgUploading.h"
#include "vmsUploadPackageImpl.h"
#include "DlgCreateUpload.h"
#include "UploaderPropsSheet.h"
#include "Dlg_AskCaptcha.h"
#include "DlgUploadDone.h"
#include <atlbase.h>
#include "vmsshareddata.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CUploadsWnd *_pwndUploads = NULL;

#define MSG_ID_CREATEUPLOADINGDLG	(WM_APP + 333)
#define MSG_ID_CREATEUPLOADDONEDLG	(WM_APP + 334)

CUploadsWnd::CUploadsWnd()
{
	m_nUplsDeletedMsg = RegisterWindowMessage (_pszUploadsDeletedNotifyMsg);
}

CUploadsWnd::~CUploadsWnd()
{
}

BEGIN_MESSAGE_MAP(CUploadsWnd, CWnd)
	//{{AFX_MSG_MAP(CUploadsWnd)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_COMMAND(ID_UPL_CREATENEW, OnUplCreatenew)
	ON_COMMAND(ID_UPL_START, OnUplStart)
	ON_COMMAND(ID_UPL_STOP, OnUplStop)
	ON_COMMAND(ID_UPL_PROPERTIES, OnUplProperties)
	ON_COMMAND(ID_UPL_DELETE, OnUplDelete)
	ON_COMMAND(ID_UPL_COPYURL, OnUplCopyurl)
	ON_COMMAND(ID_UPL_OPENINBROWSER, OnUplOpeninbrowser)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
	ON_MESSAGE(MSG_ID_CREATEUPLOADINGDLG, OnCreateUploadingDialog)
	ON_MESSAGE(MSG_ID_CREATEUPLOADDONEDLG, OnCreateUploadDoneDlg)
END_MESSAGE_MAP()

BOOL CUploadsWnd::Create(CWnd *pWndParent)
{
	CRect rc (0, 0, 50, 50);

	_pwndUploads = this;

	if (FALSE == CWnd::Create (AfxRegisterWndClass (0, NULL,
		NULL, NULL), NULL, WS_CHILD | WS_VISIBLE, rc, pWndParent, 0x16721))
		return FALSE;

	return TRUE;
}

int CUploadsWnd::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	m_bShowLog = TRUE; 
	
	if (FALSE == m_wndTasks.Create (this))
		return -1;

	if (FALSE == m_wndLog.Create (this))
		return -1;

	if (FALSE == m_wndSplitter.Create (AfxGetInstanceHandle (), m_hWnd, WST_HORIZONTAL))
		return -1;

	m_wndSplitter.SetWnd1 (m_wndTasks);
	m_wndSplitter.SetWnd2 (m_wndLog);
	m_wndSplitter.SetRatio (_App.View_SplitterRatio ("Uploads_T_L"));

	ShowLog (m_bShowLog);

	_UplsMgr.SetEventFunc (_UploadsMgrEvents, this);

	LoadAll ();
	m_wndTasks.OnUploadCountChanged ();

	SetTimer (1, 1000, NULL);
	
	return 0;
}

void CUploadsWnd::ShowLog(BOOL bShow)
{
	UINT nShow = bShow ? SW_SHOW : SW_HIDE;
	m_wndLog.ShowWindow (nShow);
	::ShowWindow (m_wndSplitter.m_wndSplitter, nShow);

	m_bShowLog = bShow;
	

	RECT rc;
	GetClientRect (&rc);
	OnSize (0, rc.right, rc.bottom);
}

void CUploadsWnd::OnSize(UINT nType, int cx, int cy) 
{
	if (m_bShowLog)
		m_wndSplitter.ApplyRatio ();
	else
		m_wndTasks.MoveWindow (0, 0, cx, cy);	
}

BOOL CUploadsWnd::SaveAll()
{
	_App.View_SplitterRatio ("Uploads_T_L", m_wndSplitter.GetRatio ());
	m_wndTasks.SaveState ("UploadsTasks");
	m_wndLog.SaveState ("UploadsLog");
	return _UplsMgr.SaveAll ();
}

void CUploadsWnd::OnUplCreatenew() 
{
	m_wndTasks.OnUplCreatenew ();
}

vmsUploadSmartPtr CUploadsWnd::CreateNewUpload(LPCSTR pszPkgName, std::vector <fsString> *pvFiles)
{
	AFX_MANAGE_STATE (AfxGetStaticModuleState ());

	CDlgCreateUpload dlg;
	if (pszPkgName)
		dlg.m_pkg.set_name (pszPkgName);
	if (pvFiles)
		dlg.m_pkg.m_vPathes = *pvFiles;
	if (IDOK != _DlgMgr.DoModal (&dlg))
		return NULL;
		
	vmsUploadSmartPtr upl = CreateUpload (&dlg.m_pkg);

	m_wndTasks.OnUploadCountChanged ();
	m_wndTasks.SelectLastUpload ();

	return upl;
}

DWORD CUploadsWnd::_UploadsMgrEvents(fsUploadsMgr *, vmsUploadSmartPtr upl, fsUploadsMgrEvent ev, LPVOID pData, LPVOID pParam)
{
	CUploadsWnd *pthis = (CUploadsWnd*) pParam;

	switch (ev)
	{
	case UME_UPLOAD_WILL_BE_DELETED:
		if (upl == pthis->m_wndLog.get_CurrentUpload ())
			pthis->m_wndLog.set_CurrentUpload (NULL);
		break;

	case UME_UPLOADS_WERE_DELETED:
		pthis->m_wndTasks.OnUploadCountChanged ();
		break;

	case UME_UPLOADER_EVENT:
		if ((int)pData == IUE_OPENINGFILEONDISK)
		{
			upl->AddRef ();
			pthis->PostMessage (MSG_ID_CREATEUPLOADINGDLG, 0, (LPARAM)(fsUpload*)upl);
		}
		break;

	case UME_UPLOAD_LOG_ADDED:
		if (upl == pthis->m_wndLog.get_CurrentUpload ())
			pthis->m_wndLog.AddRecord (upl->log.GetEvent (upl->log.GetEventCount () - 1));
		break;

	case UME_ASK_CAPTCHA_VALUE:
		DWORD dw;
		HANDLE h; 
		h = CreateThread (NULL, 0, _threadAskCaptchaValue, pData, 0, &dw);
		WaitForSingleObject (h, INFINITE);
		break;

	case UME_UPLOAD_STOPPED_OR_DONE:
		if (upl->pMgr->IsDone () && _App.View_UploadDoneDlg ())
		{
			upl->AddRef ();
			pthis->PostMessage (MSG_ID_CREATEUPLOADDONEDLG, 0, (LPARAM)(fsUpload*)upl);
		}
		break;
	}

	if (upl != NULL)
		pthis->m_wndTasks.UpdateUpload (upl);

	return 0;
}

void CUploadsWnd::OnUplStart() 
{
	m_wndTasks.OnUplStart ();	
}

void CUploadsWnd::OnUplStop() 
{
	m_wndTasks.OnUplStop ();	
}

void CUploadsWnd::OnUplProperties() 
{
	m_wndTasks.OnUplProperties ();	
}

void CUploadsWnd::OnUplDelete() 
{
	m_wndTasks.OnUplDelete ();	
}

CWnd* CUploadsWnd::get_Wnd()
{
	return this;
}

void CUploadsWnd::ApplyLanguage()
{
	m_wndTasks.ApplyLanguage ();
	m_wndLog.ApplyLanguage ();

	CRegKey key;
	if (ERROR_SUCCESS == key.Open (HKEY_CURRENT_USER, 
				"Software\\FreeDownloadManager.ORG\\Free Upload Manager\\Settings\\Integration", KEY_ALL_ACCESS) ||
			ERROR_SUCCESS == key.Create (HKEY_CURRENT_USER, "Software\\FreeDownloadManager.ORG\\Free Upload Manager\\Settings\\Integration"))
	{
		key.SetValue (LS (L_UPLOAD), "UploadString");
	}
}

void CUploadsWnd::ApplyLanguageToMenu(CMenu *menu)
{
	m_wndTasks.ApplyLanguageToMenu (menu);
}

BOOL CUploadsWnd::IsListViewColumnShown(vmsWhichListView enLV, int nIndex)
{
	if (enLV == LV_UPLOADS_TASKS)
		return m_wndTasks.IsColumnShown (nIndex);
	else
		return m_wndLog.IsColumnShown (nIndex);
}

void CUploadsWnd::ChangeListViewColumnVisibility(vmsWhichListView enLV, int nIndex)
{
	if (enLV == LV_UPLOADS_TASKS)
		m_wndTasks.ChangeColumnVisibility (nIndex);
	else
		m_wndLog.ChangeColumnVisibility (nIndex);
}

int CUploadsWnd::GetListViewColumnCount(vmsWhichListView enLV)
{
	if (enLV == LV_UPLOADS_TASKS)
		return m_wndTasks.GetHeaderCtrl ()->GetItemCount ();
	else
		return m_wndLog.GetHeaderCtrl ()->GetItemCount ();
}

void CUploadsWnd::UpdateMenu(CMenu *menu)
{
	m_wndTasks.UpdateMenu (menu);
}

void CUploadsWnd::GetMenuCommandState(UINT nCmd, BOOL &bEnabled, BOOL &bChecked)
{
	m_wndTasks.GetMenuCommandState (nCmd, bEnabled, bChecked);
}

void CUploadsWnd::StopAllUploads(BOOL bByUser)
{
	_UplsMgr.StopAllUploads (bByUser);
}

LRESULT CUploadsWnd::OnCreateUploadingDialog(WPARAM, LPARAM lp)
{
	vmsUploadSmartPtr upl = (fsUpload*) lp;
	upl->Release ();

	if (upl->dwState & US_UPLOADINGDLGISSHOWN)
		return 0;

	upl->dwState |= US_UPLOADINGDLGISSHOWN;

	CWnd wnd;
	wnd.m_hWnd = NULL;
	CDlgUploading *dlg = CDlgUploading::CreateInstance (upl, &wnd);
	dlg->ShowWindow (SW_SHOW);
	fsSetForegroundWindow (dlg->m_hWnd);
	dlg->BringWindowToTop ();
	dlg->SetForegroundWindow ();

	return 1;
}

bool CUploadsWnd::CreateUpload(vmsUploadPackage *pkg, BOOL bDialogReq, long *pUplId)
{
	vmsUploadSmartPtr upl;
	vmsUploadPackageImpl *pkgImpl = (vmsUploadPackageImpl*)pkg;

	if (pkg == NULL)
		upl = CreateNewUpload ();
	else if (bDialogReq == FALSE && pkgImpl->m_vPathes.size () != 0 && pkgImpl->m_strName.IsEmpty () == FALSE)
		upl = CreateUpload (pkgImpl);	
	else
		upl = CreateNewUpload (pkgImpl->m_strName, &pkgImpl->m_vPathes);

	if (upl == NULL)
		return false;

	if (pUplId)
		*pUplId = (long)upl->nID;

	m_wndTasks.OnUploadCountChanged ();

	if (pkgImpl)
		delete pkgImpl;

	return true;
}

bool CUploadsWnd::GetUploadUrl(long lId, LPSTR pszUrl, DWORD *cchUrlMax)
{
	vmsUploadSmartPtr upl = _UplsMgr.FindUploadById (lId);
	if (upl == NULL)
		return false;

	lstrcpy (pszUrl, upl->pMgr->get_PackageUrl ());

	if (*pszUrl == 0)
	{
		upl->pMgr->StartUploading (TRUE);
		while (upl->pMgr->IsRunning () && 0 == *upl->pMgr->get_PackageUrl ())
		{
			MSG msg;
			while (PeekMessage (&msg, NULL, 0, 0, PM_REMOVE))
				DispatchMessage (&msg);
			Sleep (50);
		}
		lstrcpy (pszUrl, upl->pMgr->get_PackageUrl ());
	}

	return *pszUrl != 0;
}

vmsUploadSmartPtr CUploadsWnd::CreateUpload(vmsUploadPackageImpl *pkg)
{
	vmsUploadSmartPtr upl;

	Upload_CreateInstance (upl);
	upl->bAutostart = TRUE;
	upl->pMgr->Create (pkg);
	upl->dwState = 0;
	upl->dwFlags = 0;
	upl->dwReserved = 0;

	_UplsMgr.Add (upl);

	return upl;
}

void CUploadsWnd::CreateNewPackage(vmsUploadPackage **p)
{
	*p = new vmsUploadPackageImpl;
}

bool CUploadsWnd::GetUploadPackageName(long lId, LPSTR pszName, UINT cchNameMax)
{
	vmsUploadSmartPtr upl = _UplsMgr.FindUploadById (lId);
	if (upl == NULL)
		return false;

	if (cchNameMax < (UINT)lstrlen (upl->pMgr->get_PackageName ()))
		return false;

	lstrcpy (pszName, upl->pMgr->get_PackageName ());

	return true;
}

void CUploadsWnd::ShowProperties()
{
	AFX_MANAGE_STATE (AfxGetStaticModuleState ());
	CUploaderPropsSheet sheet (LS (L_INTEGRATION_SETTINGS), this);
	_DlgMgr.DoModal (&sheet);
}

#include "CoreDll.h"
extern CCoreDllApp theApp;

HMENU CUploadsWnd::GetUploadsMenu()
{
	return LoadMenu (theApp.m_hInstance, MAKEINTRESOURCE (IDM_UPLOADS));
}

void CUploadsWnd::OnUplCopyurl() 
{
	m_wndTasks.OnUplCopyurl ();	
}

DWORD WINAPI CUploadsWnd::_threadAskCaptchaValue(LPVOID lp)
{
	AFX_MANAGE_STATE (AfxGetStaticModuleState ());

	LPSTR psz = (LPSTR)lp;

	CoInitialize (NULL);

	CDlg_AskCaptcha dlg;
	if (FAILED (dlg.m_img.Load (psz)))
	{
		*psz = 0;
	}
	else
	{
		_DlgMgr.DoModal (&dlg);
		lstrcpy (psz, dlg.m_strValue);
	}

	CoUninitialize ();

	return 0;
}

BOOL CUploadsWnd::LoadAll()
{
	return _UplsMgr.LoadAll ();
}

LRESULT CUploadsWnd::OnCreateUploadDoneDlg(WPARAM, LPARAM lp)
{
	AFX_MANAGE_STATE (AfxGetStaticModuleState ());
	fsUpload* upl = (fsUpload*) lp;

	CWnd wnd;
	wnd.m_hWnd = NULL;
	CDlgUploadDone *dlg = new CDlgUploadDone;
	dlg->m_upl = upl;
	dlg->Create (IDD_UPLOAD_DONE, &wnd);
	dlg->ShowWindow (SW_SHOW);
	upl->Release ();
	return 0;
}

void CUploadsWnd::OnUplOpeninbrowser() 
{
	m_wndTasks.OnUplOpeninbrowser ();	
}

void CUploadsWnd::OnTimer(UINT nIDEvent) 
{
	try 
	{

		for (int i = _UplsMgr.GetCount () - 1; i >= 0; i--)
		{
			if (_UplsMgr.GetUpload (i)->pMgr->IsRunning ())
				m_wndTasks.RedrawItems (i, i);
		}

	}
	catch (...) {}
	
	CWnd::OnTimer(nIDEvent);
}

LRESULT CUploadsWnd::WindowProc(UINT message, WPARAM wParam, LPARAM lParam) 
{
	if (message == m_nUplsDeletedMsg)
		OnDeleteUploads (wParam, lParam);
	
	return CWnd::WindowProc(message, wParam, lParam);
}

void CUploadsWnd::OnDeleteUploads(int cUploads, UINT nIdMem)
{
	CString str; str.Format (_pszSharedMemoryName, nIdMem);
	vmsSharedDataT <UINT> gdata (str, TRUE, cUploads);
	
	UPLS_LIST v;

	for (int i = 0; i < cUploads; i++)
	{
		vmsUploadSmartPtr upl = _UplsMgr.FindUploadById (gdata [i]);
		if (upl == NULL)
			continue;
		
		upl->dwFlags |= UF_DONTNOTIFYABOUTDELETE;
		v.push_back (upl);
	}

	if (v.size ())
		_UplsMgr.DeleteUploads (v);
}

vmsUploadsStat* CUploadsWnd::get_UploadsStat()
{
	return this;
}

BOOL CUploadsWnd::IsUploadsRunning()
{
	return _UplsMgr.IsRunning ();
}
