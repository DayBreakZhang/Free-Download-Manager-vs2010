/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DLG_OPTIONS_PAGE_H__B00A0DA1_8AF4_4293_B6A6_9A25A7734225__INCLUDED_)
#define AFX_DLG_OPTIONS_PAGE_H__B00A0DA1_8AF4_4293_B6A6_9A25A7734225__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CDlg_Options_Page : public CDialog  
{
public:
	bool isBrowserRestartRequired () {return m_bRestartOfBrowserIsRequired;}
	void setBrowserRestartRequired (bool b) {m_bRestartOfBrowserIsRequired = b;}
	bool isElevateRequired();
	LPCTSTR getFdmElevateArgs () const {return m_tstrFdmElevateArgs;}
	virtual CString get_PageTitle () = NULL;
	virtual CString get_PageShortTitle () = NULL;
	virtual BOOL Apply () = NULL;

	LPCSTR get_Template();

	CDlg_Options_Page(UINT u, CWnd* wnd);
	virtual ~CDlg_Options_Page();

protected:
	void setElevateRequired (bool bRequired);
	bool m_bElevateRequired;
	CString m_tstrFdmElevateArgs;
	CWnd* get_ReflectParent();
	int m_nReflectLevel;
	bool m_bRestartOfBrowserIsRequired;
	virtual void OnCancel();
	virtual void OnOK ();

	DECLARE_MESSAGE_MAP();
};

#endif 
