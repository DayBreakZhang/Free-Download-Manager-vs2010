/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DLGEXPORTHISTORY_H__F5D1B7B2_F926_4427_A007_E22EAF2F7CB8__INCLUDED_)
#define AFX_DLGEXPORTHISTORY_H__F5D1B7B2_F926_4427_A007_E22EAF2F7CB8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CDlgExportHistory : public CDialog
{

public:
	
	
	static void ExportHistory(int iWhich, BOOL bCompletedOnly, BOOL bAppend);

	CDlgExportHistory(CWnd* pParent = NULL);   

	//{{AFX_DATA(CDlgExportHistory)
	enum { IDD = IDD_EXPHIST };
		
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDlgExportHistory)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	static CString TimeToStr (FILETIME& time);
	static BOOL ExportHistory (LPCSTR pszFile, fs::list <fsDLHistoryRecord*> &vpHist, BOOL bAppend);
	void ApplyLanguage();

	
	//{{AFX_MSG(CDlgExportHistory)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
