/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DLGEXPORTDOWNLOADS_H__5B1FA9EB_3411_4A64_8ECE_DFE914184E18__INCLUDED_)
#define AFX_DLGEXPORTDOWNLOADS_H__5B1FA9EB_3411_4A64_8ECE_DFE914184E18__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CDlgExportDownloads : public CDialog
{

public:
	
	
	static BOOL ExportDownloads_ToURLListFile (LPCSTR pszFile, DLDS_LIST* pvpDlds, BOOL bAppend);
	
	static BOOL ExportDownloads_ToDLInfoListFile (LPCSTR pszFile, DLDS_LIST* pvpDlds, BOOL bAppend);
	
	
	
	
	static void ExportDownloads (int iWhich, BOOL bNoDone, BOOL bAppend);
	CDlgExportDownloads(CWnd* pParent = NULL);   

	//{{AFX_DATA(CDlgExportDownloads)
	enum { IDD = IDD_EXPDLDS };
		
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDlgExportDownloads)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	static BOOL ExportDownload_ToXML (IXMLDOMDocument* pDoc, IXMLDOMNode* pRoot, vmsDownloadSmartPtr dld);
	void ApplyLanguage();

	
	//{{AFX_MSG(CDlgExportDownloads)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
