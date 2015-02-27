; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=COptsGeneralPage
LastTemplate=CPropertyPage
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "fum.h"
LastPage=0

ClassCount=9
Class1=CChildView
Class2=CFUMApp
Class3=CAboutDlg
Class4=CMainFrame
Class5=COptSheet
Class6=COptsProxyPage
Class7=CUrlWnd

ResourceCount=7
Resource1=IDD_UPDATE (Neutral)
Resource2=IDR_MAINFRAME (English (U.S.))
Resource3=IDD_ABOUTBOX (English (U.S.))
Class8=CDlgUpdate
Resource4=IDM_TRAY (Neutral)
Resource5=IDD_OPTS_GENERAL (Neutral)
Class9=COptsGeneralPage
Resource6=IDD_OPTS_PROXY (Neutral)
Resource7=IDR_MAINFRAME (Neutral)

[CLS:CChildView]
Type=0
BaseClass=CWnd
HeaderFile=ChildView.h
ImplementationFile=ChildView.cpp

[CLS:CFUMApp]
Type=0
BaseClass=CWinApp
HeaderFile=FUM.h
ImplementationFile=FUM.cpp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=FUM.cpp
ImplementationFile=FUM.cpp
LastObject=CAboutDlg

[CLS:CMainFrame]
Type=0
BaseClass=CFrameWnd
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=W
VirtualFilter=fWC

[CLS:COptSheet]
Type=0
BaseClass=CPropertySheet
HeaderFile=OptSheet.h
ImplementationFile=OptSheet.cpp

[CLS:COptsProxyPage]
Type=0
BaseClass=CPropertyPage
HeaderFile=OptsProxyPage.h
ImplementationFile=OptsProxyPage.cpp

[CLS:CUrlWnd]
Type=0
BaseClass=CStatic
HeaderFile=UrlWnd.h
ImplementationFile=UrlWnd.cpp

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg

[DLG:IDD_OPTS_PROXY]
Type=1
Class=COptsProxyPage

[DLG:IDD_UPDATE (Neutral)]
Type=1
Class=CDlgUpdate
ControlCount=2
Control1=IDCANCEL,button,1342242816
Control2=IDC_PROGRESS,msctls_progress32,1350565888

[DLG:IDD_OPTS_PROXY (Neutral)]
Type=1
Class=?
ControlCount=14
Control1=IDC__GETFROM,button,1342177287
Control2=IDC_GETFROMIE,button,1342177289
Control3=IDC_MANUALLY,button,1342177289
Control4=IDC_DONTUSEPROXY,button,1342177289
Control5=IDC__SETTINGS,button,1342177287
Control6=IDC__ADDRESS,static,1342308352
Control7=IDC_PROXYNAME,edit,1350631552
Control8=IDC__PORT,static,1342308352
Control9=IDC_PORT,edit,1350639744
Control10=IDC_AUTHORIZATION,button,1342242819
Control11=IDC__USER,static,1342308352
Control12=IDC__PASSWORD,static,1342308352
Control13=IDC_USER,edit,1350631552
Control14=IDC_PASSWORD,edit,1350631584

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
Class=?
ControlCount=11
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342177283
Control3=IDC__NAME,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC__VER,static,1342308352
Control6=IDC__FIRM,static,1342308608
Control7=IDC_STATIC,static,1342308352
Control8=IDC__WARN,static,1342308352
Control9=IDC_STATIC,static,1342177296
Control10=IDC__SUPPORT,static,1342308608
Control11=IDC__DOWNLOAD,static,1342308608

[MNU:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
Command1=ID_APP_EXIT
Command2=ID_VIEW_TOOLBAR
Command3=ID_VIEW_STATUS_BAR
Command4=ID_VIEW_LU_1
Command5=ID_VIEW_LU_2
Command6=ID_VIEW_LU_3
Command7=ID_VIEW_LU_4
Command8=ID_VIEW_LU_5
Command9=ID_VIEW_LU_6
Command10=ID_VIEW_LU_7
Command11=ID_VIEW_LUL_1
Command12=ID_VIEW_LUL_2
Command13=ID_VIEW_LUL_3
Command14=ID_LNGMENU_START
Command15=ID_TOOLS_GENERALSETTINGS
Command16=ID_HELP
Command17=ID_HOMEPAGE
Command18=ID_RECOMMEND
Command19=ID_SUPPORT
Command20=ID_APP_ABOUT
CommandCount=20

[CLS:CDlgUpdate]
Type=0
HeaderFile=DlgUpdate.h
ImplementationFile=DlgUpdate.cpp
BaseClass=CDialog
Filter=D
LastObject=CDlgUpdate
VirtualFilter=dWC

[MNU:IDM_TRAY (Neutral)]
Type=1
Class=?
Command1=ID_SHOWMAINWINDOW
Command2=ID_CREATENEWUPLOAD
Command3=ID_APP_ABOUT
Command4=ID_APP_EXIT
CommandCount=4

[DLG:IDD_OPTS_GENERAL (Neutral)]
Type=1
Class=COptsGeneralPage
ControlCount=6
Control1=IDC_AUTOSTART,button,1342242819
Control2=IDC_STARTMINIMIZED,button,1342242819
Control3=IDC_MINTOTRAY,button,1342242819
Control4=IDC_CLOSEASMINIMIZE,button,1342242819
Control5=IDC__SYSTEM,button,1342177287
Control6=IDC__STARTUP,button,1342177287

[CLS:COptsGeneralPage]
Type=0
HeaderFile=OptsGeneralPage.h
ImplementationFile=OptsGeneralPage.cpp
BaseClass=CPropertyPage
Filter=D
LastObject=COptsGeneralPage
VirtualFilter=idWC

[ACL:IDR_MAINFRAME (Neutral)]
Type=1
Class=?
Command1=ID_APP_EXIT
CommandCount=1

