/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "DlgExportDownloads.h"
#include "DownloadsWnd.h"
#include "vmsLogger.h"

extern CDownloadsWnd* _pwndDownloads;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDlgExportDownloads::CDlgExportDownloads(CWnd* pParent )
	: CDialog(CDlgExportDownloads::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgExportDownloads)
		
	//}}AFX_DATA_INIT
}

void CDlgExportDownloads::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgExportDownloads)
		
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlgExportDownloads, CDialog)
	//{{AFX_MSG_MAP(CDlgExportDownloads)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDlgExportDownloads::OnInitDialog() 
{
	CDialog::OnInitDialog();

	CheckRadioButton (IDC_ALL, IDC_SELECTED, IDC_ALL + _App.Export_WhichDlds ());
	CheckDlgButton (IDC_NOCOMPLETED, _App.Export_DontExpCompleted () ? BST_CHECKED : BST_UNCHECKED);
	CheckDlgButton (IDC_APPEND, _App.Export_Append () ? BST_CHECKED : BST_UNCHECKED);
	
	ApplyLanguage ();
	
	return TRUE;  
	              
}

void CDlgExportDownloads::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC_ALL, L_EXPALLDLDS),
		fsDlgLngInfo (IDC_ALLINLIST, L_EXPDLDSINLIST),
		fsDlgLngInfo (IDC_SELECTED, L_EXPSELDLDS),
		fsDlgLngInfo (IDC_NOCOMPLETED, L_DONTEXPCOMPLDLDS),
		fsDlgLngInfo (IDC_APPEND, L_APPENDIFFILEEXISTS),
		fsDlgLngInfo (IDC__EXPORTOPTS, L_EXPORTOPTIONS),
		fsDlgLngInfo (IDCANCEL, L_CANCEL),
	};

	CString str = _LngMgr.GetStringNP (L_EXPORT);
	str += "...";
	SetDlgItemText (IDC__EXPORT, str);

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), L_EXPORTLISTOFDLDS);
}

void CDlgExportDownloads::OnOK() 
{
	int iWhich = 0;
	if (IsDlgButtonChecked (IDC_ALLINLIST) == BST_CHECKED)
		iWhich = 1;
	else if (IsDlgButtonChecked (IDC_SELECTED) == BST_CHECKED)
		iWhich = 2;

	BOOL bNoDone = IsDlgButtonChecked (IDC_NOCOMPLETED) == BST_CHECKED;
	BOOL bAppend = IsDlgButtonChecked (IDC_APPEND) == BST_CHECKED;

	_App.Export_WhichDlds (iWhich);
	_App.Export_DontExpCompleted (bNoDone);
	_App.Export_Append (bAppend);

	ExportDownloads (iWhich, bNoDone, bAppend);
	
	CDialog::OnOK();
}

void CDlgExportDownloads::ExportDownloads(int iWhich, BOOL bNoDone, BOOL bAppend)
{
	DLDS_LIST vpDlds;

	

	switch (iWhich)
	{
		case 0:	
		{
			_DldsMgr.LockList (true);
			size_t nCount = _DldsMgr.GetCount ();
			for (size_t i = 0; i < nCount; i++)
			{
				vmsDownloadSmartPtr dld = _DldsMgr.GetDownload (i);
				if (bNoDone && dld->pMgr->IsDone ())
					continue;	
				vpDlds.push_back (dld);
			}
			_DldsMgr.UnlockList (true);
		}
		break;

		case 1:	
		{
			CDownloads_Tasks* list = &_pwndDownloads->m_wndDownloads.m_tasks;
			int cItems = list->GetItemCount ();
			for (int i = 0; i < cItems; i++)
			{
				vmsDownloadSmartPtr dld;

				try 
				{
					dld = (fsDownload*) list->GetItemData (i);

					if (bNoDone && dld->pMgr->IsDone ())
						dld = NULL;
				}
				catch (const std::exception& ex)
				{
					ASSERT (FALSE);
					vmsLogger::WriteLog("CDlgExportDownloads::ExportDownloads " + tstring(ex.what()));
					dld = NULL;
				}
				catch (...)
				{
					ASSERT (FALSE);
					vmsLogger::WriteLog("CDlgExportDownloads::ExportDownloads unknown exception");
					dld = NULL;
				}

				if (dld)
					vpDlds.push_back (dld);
			}
		}
		break;

		case 2:	
		{
			CDownloads_Tasks* list = &_pwndDownloads->m_wndDownloads.m_tasks;
			POSITION pos = list->GetFirstSelectedItemPosition ();
			while (pos)
			{
				int iItem = list->GetNextSelectedItem (pos);
				vmsDownloadSmartPtr dld;

				try 
				{
					dld = (fsDownload*) list->GetItemData (iItem);
					
					if (bNoDone && dld->pMgr->IsDone ())
						dld = NULL;
				}
				catch (const std::exception& ex)
				{
					ASSERT (FALSE);
					vmsLogger::WriteLog("CDlgExportDownloads::ExportDownloads " + tstring(ex.what()));
					dld = NULL;
				}
				catch (...)
				{
					ASSERT (FALSE);
					vmsLogger::WriteLog("CDlgExportDownloads::ExportDownloads unknown exception");
					dld = NULL;
				}

				if (dld)
					vpDlds.push_back (dld);
			}
		}
		break;
	}

	if (vpDlds.empty ())
	{
		AfxGetApp ()->m_pMainWnd->MessageBox (LS (L_NODLDSTOEXPORT), NULL, MB_ICONEXCLAMATION);
	}
	else 
	{
		CString strFilter;
		strFilter.Format ("%s (*.txt)|*.txt|%s (*.xml)|*.xml||", LS (L_URLLISTFILES), LS (L_DLINFOLISTFILES));
		UINT flags = OFN_NOCHANGEDIR;
		if (bAppend == FALSE)
			flags |= OFN_OVERWRITEPROMPT;
		CFileDialog dlg (FALSE, "txt", NULL, flags, strFilter, NULL);

		if (_DlgMgr.DoModal (&dlg) == IDCANCEL)
			return;

		

		if (dlg.GetFileExt ().CollateNoCase ("txt") == 0)
			ExportDownloads_ToURLListFile (dlg.GetPathName (), &vpDlds, bAppend);
		else
			ExportDownloads_ToDLInfoListFile (dlg.GetPathName (), &vpDlds, bAppend);
	}
}

BOOL CDlgExportDownloads::ExportDownloads_ToURLListFile(LPCSTR pszFile, DLDS_LIST* pvpDlds, BOOL bAppend)
{
	CStdioFile file;

	UINT mode = CFile::modeWrite;

	if (bAppend == FALSE || GetFileAttributes (pszFile) == DWORD (-1))
		mode |= CFile::modeCreate;

	if (FALSE == file.Open (pszFile, mode))
	{
		::MessageBox (NULL, LS (L_CANTOPENFILE), LS (L_ERR), MB_ICONERROR);
		return FALSE;
	}

	if ((mode & CFile::modeCreate) == 0)
		file.SeekToEnd ();

	for (size_t i = 0; i < pvpDlds->size (); i++)
	{
		try 
		{
			file.WriteString (pvpDlds->at (i)->pMgr->get_URL ());
			file.WriteString ("\n");
		} 
		catch (const std::exception& ex)
		{
			ASSERT (FALSE);
			vmsLogger::WriteLog("CDlgExportDownloads::ExportDownloads_ToURLListFile " + tstring(ex.what()));
			return FALSE;
		}
		catch (...)
		{
			ASSERT (FALSE);
			vmsLogger::WriteLog("CDlgExportDownloads::ExportDownloads_ToURLListFile unknown exception");
			return FALSE;
		}
	}

	return TRUE;
}

BOOL CDlgExportDownloads::ExportDownloads_ToDLInfoListFile(LPCSTR pszFile, DLDS_LIST* pvpDlds, BOOL bAppend)
{
	IXMLDOMDocumentPtr spXML;
	IXMLDOMNodePtr spNode, spNode2;

	spXML.CreateInstance (__uuidof (DOMDocument));

	if (spXML == NULL)
		return FALSE;

	spXML->put_async (FALSE);

	VARIANT_BOOL bRes = FALSE;
	if (bAppend)
	{
		spXML->load (COleVariant (pszFile), &bRes);
		if (bRes)
		{
			spXML->selectSingleNode (L"FDM_Downloads_Info_List", &spNode);
			if (spNode == NULL)
				bRes = FALSE;
		}
	}

	if (bRes == FALSE)
	{
		spXML->createNode (COleVariant ((long)NODE_ELEMENT), L"FDM_Downloads_Info_List", NULL, &spNode);
		spXML->appendChild (spNode, &spNode2);
	}

	for (size_t i = 0; i < pvpDlds->size (); i++)
	{
		ExportDownload_ToXML (spXML, spNode, pvpDlds->at (i));
	}

	CComBSTR bstr;
	spXML->get_xml (&bstr);

	CString str = bstr;
	str.Replace ("><", ">\n<");

	bstr = str;

	spXML->loadXML (bstr, &bRes);
	
	spXML->save (COleVariant (pszFile));

	return TRUE;
}

BOOL CDlgExportDownloads::ExportDownload_ToXML(IXMLDOMDocument *pDoc, IXMLDOMNode *pRoot, vmsDownloadSmartPtr dld)
{
	
	static UINT _nLastGrpId = (UINT)-1;
	static fsString _strLastGrpFullName;

	if (_nLastGrpId != dld->pGroup->nId)
	{
		_strLastGrpFullName = _DldsGrps.GetGroupFullName (dld->pGroup->nId);
		_nLastGrpId = dld->pGroup->nId;
	}
	

	IXMLDOMNodePtr spNode, spNodeDL, spNodeTmp;
	
	pDoc->createNode (COleVariant ((long)NODE_ELEMENT), L"download", NULL, &spNode);
	pRoot->appendChild (spNode, &spNodeDL);

	spNode = NULL;
	pDoc->createNode (COleVariant ((long)NODE_ELEMENT), L"url", NULL, &spNode);
	spNode->put_nodeTypedValue (COleVariant (dld->pMgr->get_URL ()));
	spNodeDL->appendChild (spNode, &spNodeTmp);

	if (dld->strComment != "")
	{
		spNode = NULL; spNodeTmp = NULL;
		pDoc->createNode (COleVariant ((long)NODE_ELEMENT), L"comment", NULL, &spNode);
		spNode->put_nodeTypedValue (COleVariant (dld->strComment));
		spNodeDL->appendChild (spNode, &spNodeTmp);
	}

	spNode = NULL; spNodeTmp = NULL;
	pDoc->createNode (COleVariant ((long)NODE_ELEMENT), L"group", NULL, &spNode);
	spNode->put_nodeTypedValue (COleVariant (_strLastGrpFullName));
	spNodeDL->appendChild (spNode, &spNodeTmp);

	return TRUE;
}
