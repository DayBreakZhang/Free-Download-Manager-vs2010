/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "DlgExportHistory.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern CDownloadsWnd* _pwndDownloads;

CDlgExportHistory::CDlgExportHistory(CWnd* pParent )
	: CDialog(CDlgExportHistory::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgExportHistory)
		
	//}}AFX_DATA_INIT
}

void CDlgExportHistory::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgExportHistory)
		
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlgExportHistory, CDialog)
	//{{AFX_MSG_MAP(CDlgExportHistory)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDlgExportHistory::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	CheckRadioButton (IDC_ALL, IDC_SELECTED, IDC_ALL + _App.Export_WhichHist ());
	CheckDlgButton (IDC_COMPLETEDONLY, _App.Export_Hist_CompletedOnly () ? BST_CHECKED : BST_UNCHECKED);
	CheckDlgButton (IDC_APPEND, _App.Export_Hist_Append () ? BST_CHECKED : BST_UNCHECKED);
	
	ApplyLanguage ();
	
	return TRUE;  
	              
}

void CDlgExportHistory::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC_ALL, L_EXPORTALLENTRIES),
		fsDlgLngInfo (IDC_ALLINLIST, L_EXPORTALLENTRIESINLIST),
		fsDlgLngInfo (IDC_SELECTED, L_EXPORTSELECTEDENTRIES),
		fsDlgLngInfo (IDC_COMPLETEDONLY, L_EXPORTCOMPENTRIESONLY),
		fsDlgLngInfo (IDC_APPEND, L_APPENDIFFILEEXISTS),
		fsDlgLngInfo (IDC__EXPORTOPTS, L_EXPORTOPTIONS),
		fsDlgLngInfo (IDCANCEL, L_CANCEL),
	};

	CString str = _LngMgr.GetStringNP (L_EXPORT);
	str += "...";
	SetDlgItemText (IDC__EXPORT, str);

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), L_EXPORTDLHIST);
}

void CDlgExportHistory::OnOK() 
{
	int iWhich = 0;
	if (IsDlgButtonChecked (IDC_ALLINLIST) == BST_CHECKED)
		iWhich = 1;
	else if (IsDlgButtonChecked (IDC_SELECTED) == BST_CHECKED)
		iWhich = 2;

	BOOL bCompletedOnly = IsDlgButtonChecked (IDC_COMPLETEDONLY) == BST_CHECKED;
	BOOL bAppend = IsDlgButtonChecked (IDC_APPEND) == BST_CHECKED;

	_App.Export_WhichHist (iWhich);
	_App.Export_Hist_CompletedOnly (bCompletedOnly);
	_App.Export_Hist_Append (bAppend);

	ExportHistory (iWhich, bCompletedOnly, bAppend);
	
	CDialog::OnOK();
}

void CDlgExportHistory::ExportHistory(int iWhich, BOOL bCompletedOnly, BOOL bAppend)
{
	fs::list <fsDLHistoryRecord*> vpHist;

	

	switch (iWhich)
	{
	case 0:
		{
			_DldsMgr.m_histmgr.Lock ();
			for (int i = 0; i < _DldsMgr.m_histmgr.GetRecordCount (); i++)
			{
				fsDLHistoryRecord* rec = _DldsMgr.m_histmgr.GetRecord (i);
				if (bCompletedOnly && rec->dateDownloaded.dwHighDateTime == 0)
					continue;
				vpHist.add (rec);
			}
			_DldsMgr.m_histmgr.Unlock ();
		}
		break;

	case 1:
		{
			CDownloads_History* list = &_pwndDownloads->m_wndHistory;
			int cItems = list->GetItemCount ();
			for (int i = cItems-1; i >= 0; i--)
			{
				fsDLHistoryRecord* rec = (fsDLHistoryRecord*) list->GetItemData (i);
				if (bCompletedOnly && rec->dateDownloaded.dwHighDateTime == 0)
					continue;
				vpHist.add (rec);
			}
		}
		break;

	case 2:
		CDownloads_History* list = &_pwndDownloads->m_wndHistory;
		POSITION pos = list->GetFirstSelectedItemPosition ();
		while (pos)
		{
			int nItem = list->GetNextSelectedItem (pos);
			fsDLHistoryRecord* rec = (fsDLHistoryRecord*) list->GetItemData (nItem);
			if (bCompletedOnly && rec->dateDownloaded.dwHighDateTime == 0)
				continue;
			vpHist.add (rec);
		}
	}

	if (vpHist.size () == 0)
	{
		AfxGetApp ()->m_pMainWnd->MessageBox (LS (L_NOTHINGTOEXPORT), NULL, MB_ICONEXCLAMATION);		
		return;
	}

	CString strFilter;
	strFilter.Format ("%s (*.html)|*.html||", LS (L_HTMLFILES));
	UINT flags = OFN_NOCHANGEDIR;
	if (bAppend == FALSE)
		flags |= OFN_OVERWRITEPROMPT;
	CFileDialog dlg (FALSE, "html", NULL, flags, strFilter, NULL);

	if (_DlgMgr.DoModal (&dlg) == IDCANCEL)
		return;

	ExportHistory (dlg.GetPathName (), vpHist, bAppend);
}

BOOL CDlgExportHistory::ExportHistory(LPCSTR pszFile, fs::list <fsDLHistoryRecord*> &vpHist, BOOL bAppend)
{
	HANDLE hFile = CreateFile (pszFile, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_ALWAYS,
		FILE_ATTRIBUTE_NORMAL, NULL);

	if (hFile == INVALID_HANDLE_VALUE)
		return FALSE;

	CString str;

	if (bAppend && GetLastError () == ERROR_ALREADY_EXISTS)
	{
		

		

		DWORD  dwSize = GetFileSize (hFile, NULL);
		if (dwSize > 10000)
		{
			SetFilePointer (hFile, dwSize - 10000, NULL, FILE_BEGIN);
			dwSize = 10000;
		}

		DWORD dw;
		LPSTR psz = new char [dwSize+1];
		ReadFile (hFile, psz, dwSize, &dw, NULL);
		psz [dwSize] = 0;

		int nLen = lstrlen (psz);

		if (nLen != (int) dwSize)
		{
			
			CloseHandle (hFile);
			return FALSE;
		}

		
		LPSTR psz2 = psz + nLen - 7;
		while (psz2 != psz)
		{
			if (_memicmp (psz2, "</body>", 7) == 0)
			{
				*psz2 = 0;
				break;
			}

			*psz2--;
		}

		if (psz2 == psz)
		{
			
			CloseHandle (hFile);
			return FALSE;
		}

		

		SetFilePointer (hFile, (psz2 - psz) - nLen, NULL, FILE_END);
		SetEndOfFile (hFile);

		delete [] psz;
	}
	else
	{
		

		SetEndOfFile (hFile);
		str = "<html>\n"; 
		str += "<style type=\"text/css\">\n";
		str += "<!--\n";
		str += "H3 { font-size: 19px; font-family: Tahoma; color: #cc0000;}\n";
		str += "TR { font-size: 12px; font-family: Tahoma; color: #000033}\n";
		str += "TD { font-size: 12px; font-family: Tahoma; color: #000033}\n";
		str += "A,A:visited,A:active { text-decoration: none; }\n";
		str += "A:hover { text-decoration: underline; }\n";
		str += "-->\n";
		str += "</style>\n";
		str += "<body>\n";
		str += "<h3>"; str += LS (L_FDMHIST); str += "</h3>\n";
		
	}

	for (int i = 0; i < vpHist.size (); i++)
	{
		fsDLHistoryRecord* rec = vpHist [i];

		str += "<table width=\"75%\" border=\"1\">\n";
		str += "<tr><td width=\"180\">"; str += LS (L_URLOFDOWNLOAD); str += ":</td>"; 
		str += "<td><a href=\""; str += rec->strURL; str += "\"> "; str += rec->strURL; str += "</a></td></tr>\n";

		if (rec->dateDownloaded.dwHighDateTime) {
			str += "<tr><td>"; str += LS (L_DLDEDTOFILE); str += ":</td><td>"; str += rec->strSavedTo; str += "</td></tr>\n";
			str += "<tr><td>"; str += LS (L_SIZEOFFILE); str += ":</td><td>"; str += BytesToString (rec->uFileSize); str += "</td></tr>\n";
			str += "<tr><td>"; str += LS (L_DLDWASCOMPLETED); str += ":</td><td>"; str += TimeToStr (rec->dateDownloaded); str += "</td></tr>\n";
		}
		else {	
			str += "<tr><td>"; str += LS (L_DLDWASDELETED); str += ":</td><td>"; str += TimeToStr (rec->dateRecordAdded); str += "</td></tr>\n";
		}
		
		if (rec->strComment != "")
		{
			CString str2 = rec->strComment; str2.Replace ("\n", "<br>");
			str += "<tr><td>"; str += LS (L_DESC); str += ":</td><td>"; str += str2; str += "</td></tr>\n";
		}

		str += "</table><br>\n";
	}

	
	str += "</body></html>";

	DWORD dw;
	WriteFile (hFile, str, str.GetLength (), &dw, NULL);

	CloseHandle (hFile);

	return TRUE;
}

CString CDlgExportHistory::TimeToStr(FILETIME &time)
{
	char szDate [100], szTime [100];
	FileTimeToStr (&time, szDate, szTime, TRUE);
	CString str = szDate; str += ", "; str += szTime;
	return str;
}
