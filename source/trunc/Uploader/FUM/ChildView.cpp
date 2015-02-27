/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FUM.h"
#include "ChildView.h"
#include "mfchelp.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

vmsUploadsDll::vmsUploadsWnd *_pwndUploads = NULL;

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}

BEGIN_MESSAGE_MAP(CChildView,CWnd )
	//{{AFX_MSG_MAP(CChildView)
	ON_WM_PAINT()
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_COMMAND(ID_TOOLS_UPLOADERSETTINGS, OnToolsUploadersettings)
	ON_WM_INITMENUPOPUP()
	//}}AFX_MSG_MAP

	ON_UPDATE_COMMAND_UI_RANGE (50000, 50100, OnUpdatePluginCommand)
	ON_COMMAND_RANGE (50000, 50100, OnPluginCommand)

	ON_COMMAND_RANGE (ID_VIEW_LU_1, ID_VIEW_LU_7, OnViewUploadsColumn)
	ON_UPDATE_COMMAND_UI_RANGE (ID_VIEW_LU_1, ID_VIEW_LU_7, OnUpdateViewUploadsColumn)

	ON_COMMAND_RANGE (ID_VIEW_LUL_1, ID_VIEW_LUL_3, OnViewUploadsLogColumn)
	ON_UPDATE_COMMAND_UI_RANGE (ID_VIEW_LUL_1, ID_VIEW_LUL_3, OnUpdateViewUploadsLogColumn)

END_MESSAGE_MAP()

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), HBRUSH(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); 
	
	
	
	
}

int CChildView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CWnd ::OnCreate(lpCreateStruct) == -1)
		return -1;

#ifndef _DEBUG
	m_hUploadsDll = LoadLibrary (vmsGetAppFolder () + "fumcore.dll");
#else
	m_hUploadsDll = LoadLibrary ("D:\\VCW\\FDM\\FDM\\Uploader\\CoreDll\\Debug\\fumcore.dll");
	ASSERT (m_hUploadsDll != NULL);
#endif
	if (m_hUploadsDll == NULL)
		return -1;

	vmsUploadsDll::FNGV pfnGetVersion = (vmsUploadsDll::FNGV) GetProcAddress (m_hUploadsDll,
     	"_GetVersion");
	DWORD dwInterfaceVer;
    pfnGetVersion (&dwInterfaceVer, NULL);
	if (dwInterfaceVer != vmsUploadsDll::DLL_INTERFACE_VERSION)
	{
		FreeLibrary (m_hUploadsDll);
		m_hUploadsDll = NULL;

		::MessageBox (AfxGetApp ()->m_pMainWnd->m_hWnd, 
			LS (L_FUM_FUMCOREDLL_REQTOUPDATE), LS (L_WARNING), MB_ICONERROR);

		return -1;
	}

	vmsUploadsDll::FNSDC pfnSetCaller = (vmsUploadsDll::FNSDC) GetProcAddress (m_hUploadsDll, 
		"_SetDllCaller");
	ASSERT (pfnSetCaller != NULL);
	pfnSetCaller (&m_udc);

	vmsUploadsDll::FNCUW pfnCreate = (vmsUploadsDll::FNCUW) GetProcAddress (m_hUploadsDll, 
		"_CreateUploadsWindow");
	ASSERT (pfnCreate != NULL);

	_pwndUploads = m_pwndUploads = pfnCreate (this);
	
	return 0;
}

void CChildView::OnSize(UINT nType, int cx, int cy) 
{
	CWnd ::OnSize(nType, cx, cy);
	
	m_pwndUploads->get_Wnd ()->MoveWindow (0, 0, cx, cy);	
}

void CChildView::OnToolsUploadersettings() 
{
	m_pwndUploads->ShowProperties ();
}

void CChildView::OnInitMenuPopup(CMenu* pPopupMenu, UINT nIndex, BOOL bSysMenu) 
{
	CWnd ::OnInitMenuPopup(pPopupMenu, nIndex, bSysMenu);
	m_pwndUploads->UpdateMenu (pPopupMenu);
}

void CChildView::OnUpdatePluginCommand(CCmdUI *pCmdUI)
{
	BOOL bEnabled, bChecked;
	m_pwndUploads->GetMenuCommandState (pCmdUI->m_nID, bEnabled, bChecked);
	pCmdUI->Enable (bEnabled);
	pCmdUI->SetCheck (bChecked);
}

void CChildView::OnPluginCommand(UINT nCmd)
{
	m_pwndUploads->get_Wnd ()->SendMessage (WM_COMMAND, nCmd);
}

void CChildView::OnViewUploadsColumn(UINT nId)
{
	m_pwndUploads->ChangeListViewColumnVisibility (
		vmsUploadsDll::LV_UPLOADS_TASKS, nId - ID_VIEW_LU_1);
}

void CChildView::OnUpdateViewUploadsColumn(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck (
		m_pwndUploads->IsListViewColumnShown (vmsUploadsDll::LV_UPLOADS_TASKS, pCmdUI->m_nID - ID_VIEW_LU_1));

	pCmdUI->Enable (
		m_pwndUploads->GetListViewColumnCount (vmsUploadsDll::LV_UPLOADS_TASKS) > 1);
}

void CChildView::OnViewUploadsLogColumn(UINT nId)
{
	m_pwndUploads->ChangeListViewColumnVisibility (
		vmsUploadsDll::LV_TASK_LOG, nId - ID_VIEW_LUL_1);	
}

void CChildView::OnUpdateViewUploadsLogColumn(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck (
		m_pwndUploads->IsListViewColumnShown (vmsUploadsDll::LV_TASK_LOG, pCmdUI->m_nID - ID_VIEW_LUL_1));

	pCmdUI->Enable (
		m_pwndUploads->GetListViewColumnCount (vmsUploadsDll::LV_TASK_LOG) > 1);
}

