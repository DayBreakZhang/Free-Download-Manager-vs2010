/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "fdmapp.h"
#include "DlgPI2.h"
#include "DlgPI2_SureToCancel.h"
#include "DlgPI2_IfRemind.h"
#include "vmsXmlHelper.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDlgPI2::CDlgPI2(CWnd* pParent )
	: CDialog(CDlgPI2::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgPI2)
		
	//}}AFX_DATA_INIT

	m_bCancelledByUser = false;

	m_wbCust.setHostUiInfoFlags (m_wbCust.getHostUiInfoFlags () | 
		DOCHOSTUIFLAG_DIALOG | DOCHOSTUIFLAG_NO3DBORDER | DOCHOSTUIFLAG_NO3DOUTERBORDER | 
		DOCHOSTUIFLAG_SCROLL_NO);

	m_wbCust.m_pwndParent = this;
}

void CDlgPI2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgPI2)
	DDX_Control(pDX, IDC_WB, m_wb);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlgPI2, CDialog)
	//{{AFX_MSG_MAP(CDlgPI2)
	ON_BN_CLICKED(ID_CANCEL2, OnCancel2)
	ON_WM_SYSCOMMAND()
	//}}AFX_MSG_MAP
	ON_COMMAND(10000, OnShowWhatIsFavSites)
END_MESSAGE_MAP()

BOOL CDlgPI2::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_wbCust.Attach (&m_wb);

	m_wb.Navigate (_T ("about:blank"), NULL, NULL, NULL, NULL);

	std::string str;
	getHtml (str);
	
	CString str2;
	str2.Format (_T ("%x"), GetSysColor (COLOR_3DFACE));
	
	char c0 = str2[0], c1 = str2[1];
	str2.SetAt (0, str2 [4]);
	str2.SetAt (1, str2 [5]);
	str2.SetAt (4, c0);
	str2.SetAt (5, c1);

	CFont *pFont = CFont::FromHandle((HFONT)::GetStockObject(DEFAULT_GUI_FONT));
	LOGFONT lf;
	pFont->GetLogFont (&lf);
	
	CString strHTML;
	strHTML.Format ("<html><head><meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\">\
</head><style type=\"text/css\"><!--\nbody {margin-left: 0px; margin-top: 0px; margin-right: 0px;\
margin-bottom: 0px; font-size: %dpx; font-family: %s; } \n-->\n</style><body bgcolor='#%s'>\
<p align='justify'>%s</p></body></html>", abs (lf.lfHeight), lf.lfFaceName, (LPCTSTR)str2, (LPCSTR)str.c_str ());
	
	CStdioFile file;
	TCHAR tszTmpPath [MAX_PATH];
	TCHAR tszTmpFile [MAX_PATH];
	GetTempPath (MAX_PATH, tszTmpPath);
	GetTempFileName (tszTmpPath, _T ("pi"), 0, tszTmpFile);
	m_strHtmlFile = tszTmpFile;
	file.Open (m_strHtmlFile, CFile::modeCreate | CFile::modeWrite);
	file.WriteString (strHTML);
	file.Close ();
	
	CString strUrl;
	strUrl.Format (_T ("file://%s"), m_strHtmlFile);
	
	m_wb.Navigate (strUrl, 0, 0, 0, 0);

	SetWindowText (LS (L_PI_LIKE_FDM_TRYPI));
	
	
	return TRUE;  
	              
}

CString getDefaultBrowserName ()
{
	TCHAR szBrowser [MAX_PATH];
	DWORD dwBrowserLen = MAX_PATH;
		
	HKEY hReg;
	
	if (ERROR_SUCCESS != RegOpenKeyEx (HKEY_CLASSES_ROOT, _T ("http\\shell\\open\\command"), 0, 
			KEY_QUERY_VALUE, &hReg))
		return _T ("Internet Explorer");
	
	if (ERROR_SUCCESS != RegQueryValueEx (hReg, NULL, NULL, NULL, (LPBYTE) szBrowser, &dwBrowserLen))
	{
		RegCloseKey (hReg);
		return _T ("Internet Explorer");
	}
	
	RegCloseKey (hReg);
	
	if (_tcsstr (szBrowser, _T ("iexplore.exe")))
		return _T ("Internet Explorer");

	if (_tcsstr (szBrowser, _T ("firefox.exe")))
		return _T ("Firefox");

	return _T ("Internet Explorer");
};

void CDlgPI2::getHtml(std::string &str)
{
	str = vmsXmlHelper::toUtf8 (LS (L_PI_ABOUT_0));
	str += _T ("<br><br>");
	str += vmsXmlHelper::toUtf8 (LS (L_PI_ABOUT_1));
	str += _T (" <a href=\"cmd://10000\">");
	str += vmsXmlHelper::toUtf8 (LS (L_FAVORITE_SITES));
	str += _T ("</a> ");
	str += vmsXmlHelper::toUtf8 (LS (L_PI_ABOUT_2));
	str += ' ';
	str += vmsXmlHelper::toUtf8 ((LPCTSTR)getDefaultBrowserName ());
	str += '.';
}

void CDlgPI2::OnShowWhatIsFavSites()
{
	MessageBox (LS (L_WHATIS_FAVSITES), _T ("Personal Informer"), MB_ICONINFORMATION);
}

void CDlgPI2::OnCancel2() 
{
	CDlgPI2_SureToCancel dlg;
	if (dlg.DoModal () == IDOK)
	{
		PostMessage (WM_COMMAND, IDOK);
		return;
	}
	
	CDlgPI2_IfRemind dlg2;
	if (IDOK == dlg2.DoModal ())
	{
		EndDialog (ID_REMIND_ME_LATER);
		return;
	}
	
	m_bCancelledByUser = true;
	EndDialog (IDCANCEL);
}

void CDlgPI2::OnSysCommand(UINT nID, LPARAM lParam) 
{
	if (nID == SC_CLOSE)
	{
		PostMessage (WM_COMMAND, ID_CANCEL2);
		return;
	}
	
	CDialog::OnSysCommand(nID, lParam);
}
