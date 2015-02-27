; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CUploaderProps_Integration
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "coredll.h"
LastPage=0

ClassCount=14
Class1=CCoreDllApp
Class2=CDlgCreateUpload
Class3=CDlgUploading
Class4=CListCtrlEx
Class5=CUpload_GeneralPage
Class6=CUploaderPropsSheet
Class7=CUploadPropertiesSheet
Class8=CUploads_Log
Class9=CUploads_Tasks
Class10=CUploadsWnd
Class11=CWndLog

ResourceCount=8
Resource1=IDD_CREATE_UPLOAD (Neutral)
Resource2=IDD_UPLOAD_GENERAL (Neutral)
Resource3=IDD_UPLOADING (Neutral)
Resource4=IDD_ASK_CAPTCHA (Neutral)
Resource5=IDM_LOG (Neutral)
Class12=CUploaderProps_Integration
Resource6=IDD_UPLOAD_DONE (Neutral)
Class13=CDlg_AskCaptcha
Resource7=IDM_UPLOADS (Neutral)
Class14=CDlgUploadDone
Resource8=IDD_UPLDR_INTEGRATION

[CLS:CCoreDllApp]
Type=0
BaseClass=CWinApp
HeaderFile=CoreDll.h
ImplementationFile=CoreDll.cpp
LastObject=CCoreDllApp

[CLS:CDlgCreateUpload]
Type=0
BaseClass=CDialog
HeaderFile=DlgCreateUpload.h
ImplementationFile=DlgCreateUpload.cpp
Filter=D
VirtualFilter=dWC
LastObject=CDlgCreateUpload

[CLS:CDlgUploading]
Type=0
BaseClass=CDialog
HeaderFile=DlgUploading.h
ImplementationFile=DlgUploading.cpp
Filter=D
VirtualFilter=dWC

[CLS:CListCtrlEx]
Type=0
BaseClass=CListCtrl
HeaderFile=ListCtrlEx.h
ImplementationFile=ListCtrlEx.cpp

[CLS:CUpload_GeneralPage]
Type=0
BaseClass=CPropertyPage
HeaderFile=Upload_GeneralPage.h
ImplementationFile=Upload_GeneralPage.cpp
Filter=D
VirtualFilter=idWC
LastObject=CUpload_GeneralPage

[CLS:CUploaderPropsSheet]
Type=0
BaseClass=CPropertySheet
HeaderFile=UploaderPropsSheet.h
ImplementationFile=UploaderPropsSheet.cpp
Filter=D
VirtualFilter=hWC

[CLS:CUploadPropertiesSheet]
Type=0
BaseClass=CPropertySheet
HeaderFile=UploadPropertiesSheet.h
ImplementationFile=UploadPropertiesSheet.cpp

[CLS:CUploads_Log]
Type=0
BaseClass=CWndLog
HeaderFile=Uploads_Log.h
ImplementationFile=Uploads_Log.cpp

[CLS:CUploads_Tasks]
Type=0
BaseClass=CListCtrlEx
HeaderFile=Uploads_Tasks.h
ImplementationFile=Uploads_Tasks.cpp
Filter=W
VirtualFilter=FWC

[CLS:CUploadsWnd]
Type=0
BaseClass=CWnd
HeaderFile=UploadsWnd.h
ImplementationFile=UploadsWnd.cpp
Filter=W
VirtualFilter=WC

[CLS:CWndLog]
Type=0
BaseClass=CListCtrlEx
HeaderFile=WndLog.h
ImplementationFile=WndLog.cpp

[DLG:IDD_CREATE_UPLOAD]
Type=1
Class=CDlgCreateUpload

[DLG:IDD_UPLOADING]
Type=1
Class=CDlgUploading

[DLG:IDD_UPLOAD_GENERAL]
Type=1
Class=CUpload_GeneralPage

[MNU:IDM_LOG (Neutral)]
Type=1
Class=?
Command1=ID_CLEAR
Command2=ID_COPY_TO_CB
Command3=ID_AUTOSCROLL
CommandCount=3

[MNU:IDM_UPLOADS (Neutral)]
Type=1
Class=?
Command1=ID_UPL_CREATENEW
Command2=ID_UPL_START
Command3=ID_UPL_STOP
Command4=ID_UPL_DELETE
Command5=ID_UPL_OPENINBROWSER
Command6=ID_UPL_COPYURL
Command7=ID_UPL_PROPERTIES
CommandCount=7

[DLG:IDD_UPLOADING (Neutral)]
Type=1
Class=?
ControlCount=15
Control1=IDC_URL,edit,1350633600
Control2=IDC_COPY,button,1342242816
Control3=IDC_PAUSE,button,1342242816
Control4=IDC_ABORT,button,1342242816
Control5=IDCANCEL,button,1342242817
Control6=IDC_STATIC,static,1342308352
Control7=IDC__UPLOADED_,static,1342308352
Control8=IDC_PROGRESS,msctls_progress32,1350565888
Control9=IDC__UPLOADED,static,1342308352
Control10=IDC__TOTALSIZE_,static,1342308352
Control11=IDC__TOTALSIZE,static,1342308352
Control12=IDC__SPEED_,static,1342308352
Control13=IDC__SPEED,static,1342308352
Control14=IDC__TIMELEFT_,static,1342308352
Control15=IDC__TIMELEFT,static,1342308352

[DLG:IDD_CREATE_UPLOAD (Neutral)]
Type=1
Class=CDlgCreateUpload
ControlCount=32
Control1=IDC_FILES,SysListView32,1350647809
Control2=IDC_PKGNAME,edit,1484849280
Control3=IDC_COMPRESS,combobox,1344339971
Control4=IDC_SETPWD,button,1342242819
Control5=IDC_PWD,edit,1350631584
Control6=IDC_PWD_R,edit,1350631584
Control7=IDC_DAYSTOKEEP,combobox,1344339971
Control8=IDC_NUMBEROFDLDS,combobox,1344339971
Control9=IDC_PLACETOCAT,button,1342242819
Control10=IDC_ADVANCEDINFO,button,1342242819
Control11=IDC_DESC,edit,1352732740
Control12=IDC_TAGS,edit,1350631552
Control13=IDC_SNDRNAME,edit,1350631552
Control14=IDC_SNDREMAIL,edit,1350631552
Control15=IDC_RCVREMAIL,edit,1350631552
Control16=IDC_AGREE,button,1342242819
Control17=IDOK,button,1342242817
Control18=IDCANCEL,button,1342242816
Control19=IDC__TB_FILES,static,1073741831
Control20=IDC__PKGNAME,static,1342308352
Control21=IDC__FILESTOUPLOAD,static,1342308352
Control22=IDC__KEEPTHESEFILES,static,1342308352
Control23=IDC__SUPPOSEDNUMBEROFDLDS,static,1342308352
Control24=IDC__PWD,static,1342308352
Control25=IDC__PWD_R,static,1342308352
Control26=IDC__DESC,static,1342308352
Control27=IDC__TAGS,static,1342308352
Control28=IDC__SNDRNAME,static,1342308352
Control29=IDC__SNDREMAIL,static,1342308352
Control30=IDC__RCVREMAIL,static,1342308352
Control31=IDC__COMPRESS,static,1342308352
Control32=IDC__TERMS,static,1342308608

[DLG:IDD_UPLOAD_GENERAL (Neutral)]
Type=1
Class=?
ControlCount=27
Control1=IDC_FILES,SysListView32,1484865537
Control2=IDC_PKGNAME,edit,1350633600
Control3=IDC_COMPRESS,combobox,1478557699
Control4=IDC_SETPWD,button,1476460547
Control5=IDC_PWD,edit,1350633632
Control6=IDC_PWD_R,edit,1350633632
Control7=IDC_DAYSTOKEEP,combobox,1478557699
Control8=IDC_NUMBEROFDLDS,combobox,1478557699
Control9=IDC_PLACETOCAT,button,1476460547
Control10=IDC_ADVANCEDINFO,button,1476460547
Control11=IDC_DESC,edit,1352734788
Control12=IDC_TAGS,edit,1350633600
Control13=IDC_SNDRNAME,edit,1350633600
Control14=IDC_SNDREMAIL,edit,1350633600
Control15=IDC_RCVREMAIL,edit,1350633600
Control16=IDC__PKGNAME,static,1342308352
Control17=IDC__FILESTOUPLOAD,static,1342308352
Control18=IDC__KEEPTHESEFILES,static,1342308352
Control19=IDC__SUPPOSEDNUMBEROFDLDS,static,1342308352
Control20=IDC__PWD,static,1342308352
Control21=IDC__PWD_R,static,1342308352
Control22=IDC__DESC,static,1342308352
Control23=IDC__TAGS,static,1342308352
Control24=IDC__SNDRNAME,static,1342308352
Control25=IDC__SNDREMAIL,static,1342308352
Control26=IDC__RCVREMAIL,static,1342308352
Control27=IDC__COMPRESS,static,1342308352

[DLG:IDD_UPLDR_INTEGRATION]
Type=1
Class=CUploaderProps_Integration
ControlCount=9
Control1=IDC_CM,button,1342242819
Control2=IDC_STM,button,1342242819
Control3=IDC_IE,button,1342242819
Control4=IDC_OE,button,1342242819
Control5=IDC__S0,button,1342177287
Control6=IDC_OE_ASKUPLOAD,button,1342242819
Control7=IDC_OE__MINSIZE,static,1342308352
Control8=IDC_OE_MINSIZE,edit,1350639746
Control9=IDC__KB,static,1342308352

[CLS:CUploaderProps_Integration]
Type=0
HeaderFile=UploaderProps_Integration.h
ImplementationFile=UploaderProps_Integration.cpp
BaseClass=CPropertyPage
Filter=D
LastObject=CUploaderProps_Integration
VirtualFilter=idWC

[DLG:IDD_ASK_CAPTCHA (Neutral)]
Type=1
Class=CDlg_AskCaptcha
ControlCount=4
Control1=IDC_VALUE,edit,1350631552
Control2=IDOK,button,1342242817
Control3=IDC__MSG,static,1342308352
Control4=IDC__IMG,static,1073741832

[CLS:CDlg_AskCaptcha]
Type=0
HeaderFile=Dlg_AskCaptcha.h
ImplementationFile=Dlg_AskCaptcha.cpp
BaseClass=CDialog
Filter=D
LastObject=CDlg_AskCaptcha
VirtualFilter=dWC

[DLG:IDD_UPLOAD_DONE (Neutral)]
Type=1
Class=CDlgUploadDone
ControlCount=6
Control1=IDC_URL,edit,1350633600
Control2=IDC_DONTSHOWAGAIN,button,1342242819
Control3=IDC_OPEN,button,1342242816
Control4=IDC_COPY,button,1342242816
Control5=IDCANCEL,button,1342242817
Control6=IDC__MSG,static,1342308352

[CLS:CDlgUploadDone]
Type=0
HeaderFile=DlgUploadDone.h
ImplementationFile=DlgUploadDone.cpp
BaseClass=CDialog
Filter=D
LastObject=CDlgUploadDone
VirtualFilter=dWC

