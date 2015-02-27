; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CWebInterfaceDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Web Interface.h"

ClassCount=2
Class1=CWebInterfaceApp
Class2=CWebInterfaceDlg

ResourceCount=4
Resource2=IDD_WEBINTERFACE_DIALOG
Resource1=IDR_MAINFRAME
Resource3=IDM_TRAY (Neutral (Default))
Resource4=IDD_WEBINTERFACE_DIALOG (English (U.S.))

[CLS:CWebInterfaceApp]
Type=0
HeaderFile=Web Interface.h
ImplementationFile=Web Interface.cpp
Filter=N
BaseClass=CWinApp
VirtualFilter=AC

[CLS:CWebInterfaceDlg]
Type=0
HeaderFile=Web InterfaceDlg.h
ImplementationFile=Web InterfaceDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CWebInterfaceDlg



[DLG:IDD_WEBINTERFACE_DIALOG]
Type=1
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Class=CWebInterfaceDlg

[DLG:IDD_WEBINTERFACE_DIALOG (English (U.S.))]
Type=1
Class=CWebInterfaceDlg
ControlCount=15
Control1=IDC_STATIC,static,1342308352
Control2=IDC_PORT,edit,1350639744
Control3=IDC_STATIC,button,1342177287
Control4=IDC_STATIC,button,1342177287
Control5=IDC_STATIC,static,1342308352
Control6=IDC_SERV_ADDR,edit,1350633600
Control7=IDOK,button,1342242817
Control8=IDCANCEL,button,1342242816
Control9=IDC_AUTORUN,button,1342242819
Control10=IDC_OPEN_IN_BROWSER,button,1342242816
Control11=IDC_USEPWD,button,1342242819
Control12=IDC__S0,static,1342308352
Control13=IDC_USER,edit,1350631552
Control14=IDC__S1,static,1342308352
Control15=IDC_PWD,edit,1350631584

[MNU:IDM_TRAY (Neutral (Default))]
Type=1
Class=?
Command1=ID_CONFIGURE
Command2=ID_SHUTDOWN
CommandCount=2

