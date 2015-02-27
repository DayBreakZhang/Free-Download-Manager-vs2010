/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_MAINFRM_H__AC3FA611_4FF2_4779_82DF_504A2BF21D9A__INCLUDED_)
#define AFX_MAINFRM_H__AC3FA611_4FF2_4779_82DF_504A2BF21D9A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "AppStatusBar.h"
#include "ChildView.h"
#include "ToolBarEx.h"
#include "fsODMenu.h"	
#include "UpdateDlg.h"	
#include "FloatingWnd.h"
#include "FloatingInfoWnd.h"	
#include "FloatingWndsThread.h"	
#include "orbit_download.h"
#pragma warning (push, 3)
#include "FDMCustomized/FDMCustomized_lib/FDMCustomizations.h"
#include "Wnd_Banner.h"	
#include "FDCButton.h"	
#include "Wnd_FDMGetCustVer_Btn.h"
#pragma warning (pop)

#define WM_SHOWTRAYMENU			(WM_APP+101)
#define WM_SHOWDOWNLOADDIALOG	(WM_APP+102)
#define WM_DOMODAL				(WM_APP+103)

#define ID_APP_EXIT_2	40000

class CMainFrame : public CFrameWnd
{
	friend class CFloatingWnd;
	friend class CFdmApp;
	friend class CFloatingInfo_ListCtrlWnd;
public:
	CMainFrame();
protected: 
	DECLARE_DYNAMIC(CMainFrame)

public:

public:

	//{{AFX_VIRTUAL(CMainFrame)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo);
	virtual void RecalcLayout(BOOL bNotify = TRUE);
	protected:
	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);
	//}}AFX_VIRTUAL

public:
	void ApplyShowSmallTipsSetting();
	static void ShowOnDownloadDoneBalloon (fsDownload* dld);
	void SetActivePlugin (int nIndex);
	
	vmsFDMCustomizations m_Customizations;
	
	
	bool ShowSpreadHelpDialogIfRequired();
	
	BOOL IsFloatingInfoWindowVisible();
	
	void ShowFloatingInfoWindow (BOOL bShow);
	vmsFDMCustomizations* get_Customizations ();
	BOOL m_bInited;	
	
	void RebuidDownloadsList();
	
	
	static void ShowTimeoutBalloon (LPCSTR pszInfo, LPCSTR pszTitle, DWORD dwIcon = NIIF_INFO, BOOL bClear = FALSE);
	
	
	void ShowTrayMenu(BOOL bModeTray = TRUE);
	afx_msg void OnUpdateLngMenu (CCmdUI* pCmdUI);
	void SaveState(DWORD dwWhat);
	
	
	
	
	
	
	void AddPluginMenuView (HMENU hMenuView, fsSetImage* pImages, int cImages, wgMenuViewItem *pItems, int cItems);
	
	void RemovePluginMenuView();
	BOOL m_bCloseAsMinimize;	
	BOOL m_bMinToTray;			
	CFloatingWndsThread* m_pFloatWndsThread;
	
	CImageList m_imgsMenu, m_dimgsMenu;
	
	CImageList m_imgsTool, m_dimgsTool;

	
	void RemovePluginMenu();
	
	void AddPluginMenu (HMENU hMenu, fsSetImage* pImages, int cImages);
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	afx_msg void ConfirmImportMtorrent();
	afx_msg void ConfirmImportDownloadsFromOtherManagers();

protected:  
	CAppStatusBar  m_wndStatusBar;
	CChildView  m_wndView;
	BOOL m_bQueryForExit;	

protected:
	void SaveAllData (DWORD dwWhat);
	afx_msg LRESULT OnDoModal (WPARAM, LPARAM lp);
	static DWORD WINAPI _threadWaitPI (LPVOID);
	afx_msg void OnPI();
	void OnTimer_CheckShowPI();
	afx_msg LRESULT OnMyBalloonClosed (WPARAM, LPARAM);
	struct TimeoutBalloonInfo {
		CString strInfo;
		CString strTitle;
		DWORD dwIcon;
		BOOL bClear;
	};
	afx_msg LRESULT OnShowBalloon (WPARAM wp, LPARAM lp);
	
	class CFdmBalloon* m_pFdmBalloon;
	class CFdmBalloonContent* m_pFdmBalloonContent;
	enum FdmBalloonContentType {
		FBCT_UNKNOWN,
		FBCT_ON_DOWNLOAD_DONE,
	} m_enFdmBalloonContentType;
	void ShowFdmBalloon (CFdmBalloonContent*, FdmBalloonContentType);
	LONG m_cThreadsRunning;
	HANDLE m_hevShuttingDown;
	vmsCriticalSection m_csSaveAllData;
	static DWORD WINAPI _threadAutosave (LPVOID);
	int GetTumMenuPosition();
	UINT m_nUploadsMsg1;
	UINT m_nShutdownMsg;
	afx_msg LRESULT OnPowerBroadCast (WPARAM, LPARAM);
	
	void TotalTraffic_CheckMonthChange();
	
	void ReadTotalTrafficInfo();
	
	UINT64 m_nTrafficUsedPrevMonth, m_nTrafficUsedThisMonth;
	UINT64 m_nTrafficUpldPrevMonth, m_nTrafficUpldThisMonth;
	
	int m_nTotalTraffic_CurrMonth;
	
	afx_msg void OnUpdateTotalSpeed (CCmdUI* pCmdUI);
	afx_msg void OnUpdateTrafficThisMonth (CCmdUI* pCmdUI);
	
	afx_msg void OnLDF (UINT nID);
	
	bool m_bNeedSpreadHelpDialog;
	
	
	bool m_bDontShowSHD;
	
	BOOL ImportListOfDownloads_FromDLInfoListFile(LPCSTR pszFile);
	BOOL ImportDownload (IXMLDOMNode* pNode, DLDS_LIST_REF v);
	
	
	BOOL ImportListOfDownloads_FromURLListFile (LPCSTR pszFile);
	
	afx_msg void OnTUMChanged();
	
	BOOL is_MouseInTray();
	
	afx_msg void OnUpdateSkin (CCmdUI* pCmdUI);
	afx_msg void OnSkin (UINT nID);
	afx_msg LRESULT OnSaveAllData (WPARAM, LPARAM);
	void BuildSkinsMenu();
	
	int get_SkinsMenuPos();
	CWnd_FDMGetCustVer_Btn m_wndFDMCustBtn;
	
	void SetupButton();
	CFDCButton m_btnFDC;
	
	void DisplayBanner (int iIndex);
	CWnd_Banner m_wndBanner;
	CReBar m_wndReBar;
	
	BOOL ReadCusomizationInfo();
	afx_msg LRESULT OnShowTrayMenu (WPARAM, LPARAM);
	void LoadToolImages();
	
	CString m_strTimeoutBallon_Msgs;	
	
	void Balloon_ShowDLInfo(BOOL bCheckSettings = TRUE);
	BOOL m_bTrayMenuShowing;	
	
	
	
	void ShowBalloon (LPCSTR pszInfo, LPCSTR pszTitle, BOOL bCheckSettings = TRUE, DWORD dwIcon = NIIF_INFO);
	void HideBalloon();
	BOOL m_bBalloonShowing;		
	int m_balloonX, m_balloonY;  
	
	afx_msg void OnIdUpdate();
	
	void RemovePluginMenuView2();
	
	void AddPluginMenuView (HMENU hMenu, fsSetImage* pImages, int cImages);
	
	afx_msg void OnTBChange (NMHDR*, LRESULT* res);
	afx_msg void OnTBGetButtonInfo (NMHDR*, LRESULT* res);
	afx_msg void OnTBReset (NMHDR*, LRESULT* res);
	afx_msg void OnTBCustHelp (NMHDR*, LRESULT* res);
	afx_msg void OnTBEndDrag (NMHDR*, LRESULT* res);
	afx_msg void OnTBBeginDrag (NMHDR*, LRESULT* res);
	afx_msg void OnTBEndAdjust (NMHDR*, LRESULT* res);
	afx_msg void OnTBBeginAdjust (NMHDR*, LRESULT* res);
	afx_msg void OnTBQueryInsert (NMHDR*, LRESULT* res);
	afx_msg void OnTBQueryDelete (NMHDR*, LRESULT* res);
	
	virtual LRESULT WindowProc (UINT msg, WPARAM wp, LPARAM lp);
	static UINT m_umsgTaskBarCreated;		
	
	afx_msg void OnDropBox();
	
	void UpdateSettings();
	
	afx_msg void OnImportSettings();
	
	afx_msg void OnExportSettings();
	
	afx_msg void OnSpiderDLWebPage();
	
	afx_msg void OnSpiderDefSettings();
	
	static DWORD WINAPI _threadUpdate (LPVOID lp);
	
	void SetMenuImages();
	
	void ApplyLanguageToMenu();
	void ApplyLanguage();
	
	afx_msg void OnLngMenu (UINT id);
	
	void BuildLngMenu();
	afx_msg void OnViewStatusbar();
	afx_msg void OnViewToolbar();
	
	afx_msg void OnUpdatePluginMenuView (CCmdUI *pCmdUI);
	afx_msg void OnUpdateDropBox (CCmdUI* pCmdUI);
	
	afx_msg void OnAltPlusDigit (UINT nID);
	int m_cPluginMenuViewInserted; 
	void OnUpdateSwitchTo (CCmdUI *pCmdUI);
	
	afx_msg void OnSwitchTo (UINT nID);
	
	void BuildSwitchToMenu();
	void UpdateTitle();
	
	
	void StartUpdate (BOOL bShowDlg);
	CUpdateDlg* m_pUpdateDlg;	
	
	static void _UpdateMgrEvents (fsUpdateMgrEvent ev, UINT* puInfo, LPVOID lp);
	void SaveSettings(DWORD dwWhat);
	void ReadSettings();
	void LoadMenuImages();
	fsODMenu m_odTrayMenu;
	fsODMenu m_odmenu;
	wgMenuViewItem *m_pPluginMenuViewItems;	
	int m_cPluginMenuViewItems;	
	afx_msg LRESULT OnTrayMsg (WPARAM wp, LPARAM lp);
	
	int m_cMenuMainItemsAdded,	
		m_cMenuViewItemsAdded;	
	
	void appendDiagnostics(CString& sMsg, const CString& sDiagnostics) const;
	void appendErrorCode(CString& sMsg, HRESULT hr) const;
	
	afx_msg void OnShowFdmBalloon();
	afx_msg void OnCheckAvpPresence();
	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSetFocus(CWnd *pOldWnd);
	afx_msg void OnClose();
	afx_msg void OnDlddefoptions();
	afx_msg void OnDldroptions();
	afx_msg void OnTumHeavy();
	afx_msg void OnUpdateTumHeavy(CCmdUI* pCmdUI);
	afx_msg void OnTumLight();
	afx_msg void OnUpdateTumLight(CCmdUI* pCmdUI);
	afx_msg void OnTumMedium();
	afx_msg void OnUpdateTumMedium(CCmdUI* pCmdUI);
	afx_msg void OnOptmaster();
	afx_msg void OnDldCreate();
	afx_msg void OnTaskCreateNew();
	afx_msg void OnNeedExit();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnInitMenuPopup(CMenu* pPopupMenu, UINT nIndex, BOOL bSysMenu);
	afx_msg void OnAppExit();
	afx_msg void OnMeasureItem(int nIDCtl, LPMEASUREITEMSTRUCT lpMeasureItemStruct);
	afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
	afx_msg void OnShowmainwindow();
	afx_msg void OnStartall();
	afx_msg void OnStopall();
	afx_msg void OnHelp();
	afx_msg void OnHomepage();
	afx_msg void OnRecommend();
	afx_msg void OnSupport();
	afx_msg void OnUpdate();
	afx_msg void OnProggeneralsettings();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnDial();
	afx_msg void OnEndSession(BOOL bEnding);
	afx_msg void OnHowregister();
	afx_msg void OnHangupwhendone();
	afx_msg void OnUpdateHangupwhendone(CCmdUI* pCmdUI);
	afx_msg void OnTurnoffwhendone();
	afx_msg void OnUpdateTurnoffwhendone(CCmdUI* pCmdUI);
	afx_msg void OnEnterkey();
	afx_msg void OnBuyonline();
	afx_msg void OnMonitorbrowser();
	afx_msg void OnUpdateMonitorbrowser(CCmdUI* pCmdUI);
	afx_msg void OnMonitorclipboard();
	afx_msg void OnUpdateMonitorclipboard(CCmdUI* pCmdUI);
	afx_msg void OnAddsite();
	afx_msg void OnViewSwbar();
	afx_msg void OnUpdateViewSwbar(CCmdUI* pCmdUI);
	afx_msg void OnNcRButtonUp(UINT nHitTest, CPoint point);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg BOOL OnQueryEndSession();
	afx_msg void OnInsert();
	afx_msg void OnDlinfobox();
	afx_msg void OnDllangfiles();
	afx_msg void OnFDC();
	afx_msg void OnProceedFurherInitialization();
	afx_msg void OnAppAbout();
	afx_msg void OnExportlistofdownloads();
	afx_msg void OnImportlistofdownloads();
	
	afx_msg void OnImportDownloadsFromOtherManagers();
	afx_msg void OnExitwhendone();
	afx_msg void OnUpdateExitwhendone(CCmdUI* pCmdUI);
	afx_msg void OnFind();
	afx_msg void OnFindnext();
	afx_msg void OnUpdateFindnext(CCmdUI* pCmdUI);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnDonate();
	afx_msg void OnDldCreatebatch();
	afx_msg void OnFileImportImportlistofdownloadsfromclipboard();
	afx_msg void OnOptionsSm();
	afx_msg void OnSpreadhelp();
	afx_msg void OnExportdlhist();
	afx_msg void OnUpdateExportdlhist(CCmdUI* pCmdUI);
	afx_msg void OnUpdateLdf0(CCmdUI* pCmdUI);
	afx_msg void OnLdfClear();
	afx_msg void OnUpdateLdfClear(CCmdUI* pCmdUI);
	afx_msg void OnPausealldlds();
	afx_msg void OnUpdatePausealldlds(CCmdUI* pCmdUI);
	afx_msg void OnUpdateDlinfobox(CCmdUI* pCmdUI);
	afx_msg void OnAppExit2();
	afx_msg void OnPortableFdm();
	afx_msg void OnUpldroptions();
	afx_msg void OnLoadatstartup();
	afx_msg void OnUpdateLoadatstartup(CCmdUI* pCmdUI);
	afx_msg void OnDldCreateflvdld();
	
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

protected:
	vmsCriticalSection m_csExit;
	bool m_bExitHandlerPerformed;

public:
	bool onExit(bool bQueryExit);

private:
	void UpadateTumToolbarState();
};

//{{AFX_INSERT_LOCATION}}

#endif 
