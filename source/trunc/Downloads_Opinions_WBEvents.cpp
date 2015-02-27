/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "Downloads_Opinions_WBEvents.h"
#include "Downloads_Opinions.h"
#include <mshtml.h>
#include "MainFrm.h"

_COM_SMARTPTR_TYPEDEF(IHTMLInputElement, __uuidof(IHTMLInputElement));

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDownloads_Opinions_WBEvents::CDownloads_Opinions_WBEvents()
{
	EnableAutomation ();
	m_pwndOpinions = NULL;
}

CDownloads_Opinions_WBEvents::~CDownloads_Opinions_WBEvents()
{
}

BEGIN_MESSAGE_MAP(CDownloads_Opinions_WBEvents, CCmdTarget)
	//{{AFX_MSG_MAP(CDownloads_Opinions_WBEvents)
		
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CDownloads_Opinions_WBEvents, CCmdTarget)
	DISP_FUNCTION_ID(CDownloads_Opinions_WBEvents, "DocumentComplete", DISPID_DOCUMENTCOMPLETE, OnDocumentComplete, VT_EMPTY, VTS_DISPATCH VTS_PVARIANT)
	DISP_FUNCTION_ID(CDownloads_Opinions_WBEvents, "NavigateError", DISPID_NAVIGATEERROR, OnNavigateError, VT_EMPTY, VTS_DISPATCH VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PBOOL)
END_DISPATCH_MAP()

void CDownloads_Opinions_WBEvents::OnDocumentComplete(LPDISPATCH pdWB, VARIANT *URL)
{
	IWebBrowser2Ptr spWB (pdWB);
	if (spWB == NULL)
		return;

	IDispatchPtr spdDoc;
	spWB->get_Document (&spdDoc);
	IHTMLDocumentPtr spDoc (spdDoc);
	if (spDoc == NULL)
		return;

	ICustomDocPtr spCD (spDoc); 
	if (spCD != NULL)
		spCD->SetUIHandler (&m_wbUIHandler);

	bool bSetTab = false;
	if (m_pwndOpinions->m_cSetAsCurrentTabAfterLoadComplete)
	{
		InterlockedDecrement (&m_pwndOpinions->m_cSetAsCurrentTabAfterLoadComplete);
		bSetTab = true;
	}

	if (m_pwndOpinions->m_dld == NULL)
		return;

	if (bSetTab)
		_pwndDownloads->m_wndDownloads.m_info.set_CurTab (DIT_OPINIONS);

	

	IDispatch *pdScript;
	spDoc->get_Script (&pdScript);
	if (pdScript == NULL)
		return;

	

	DISPID didFun;
	OLECHAR* pwszFunName = L"processform";

	HRESULT hr;
	hr = pdScript->GetIDsOfNames (IID_NULL, &pwszFunName, 1, LOCALE_SYSTEM_DEFAULT, &didFun);
	if (FAILED (hr))
		return;	
	
	COleVariant vtResult;
	BYTE params [] = {VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR};

	
	

	CString strVersion;
	CMainFrame* pFrm = (CMainFrame*)AfxGetApp ()->m_pMainWnd;
	strVersion.Format ("%s_%d", vmsFdmAppMgr::getBuildNumberAsString (), pFrm->m_Customizations.get_AffiliateID ());

	CString strState;
	if (m_pwndOpinions->m_dld->pMgr->IsDone ())
		strState = "Downloaded";
	else if (m_pwndOpinions->m_dld->pMgr->IsRunning ())
		strState = "Downloading";
	else
		strState = "Paused";
	CString strSize;
	UINT64 u = m_pwndOpinions->m_dld->pMgr->GetSSFileSize ();
	if (u != _UI64_MAX) {
		char sz [100];
		_i64toa ((__int64)u, sz, 10);
		strSize = sz;
	}
	else
		strSize = "Unknown";
	CString strComment = m_pwndOpinions->m_dld->strComment;
	strComment.Replace ("\r\n", " ");
	strComment.Replace ("\r", " ");
	strComment.Replace ("\n", " ");

	

	CString strUrl;
	if (m_pwndOpinions->m_dld->pMgr->IsBittorrent ())
		strUrl = m_pwndOpinions->m_dld->pMgr->GetBtDownloadMgr ()->get_InfoHash ();
	else
		strUrl = m_pwndOpinions->m_dld->pMgr->get_URL ();

	COleDispatchDriver ddr (pdScript);
	ddr.InvokeHelper (didFun, DISPATCH_METHOD, VT_VARIANT, (void*)&vtResult,
		params, strVersion, strUrl, strComment, 
		strState, strSize); 

	
	
	
	
	RetrieveLinkToUsText (spdDoc);
}

HRESULT CDownloads_Opinions_WBEvents::Attach()
{
	IConnectionPointContainerPtr spCPC;

	LPUNKNOWN pUnk = m_pwndOpinions->m_wb.GetControlUnknown ();
	if (pUnk == NULL)
		return E_FAIL;

	spCPC = pUnk;
	if (spCPC == NULL)
		return E_FAIL;

	spCPC->FindConnectionPoint (DIID_DWebBrowserEvents2, &m_spCP);
	if (m_spCP == NULL)
		return E_FAIL;

	return m_spCP->Advise (GetIDispatch (FALSE), &m_dwCookie);
}

void CDownloads_Opinions_WBEvents::Detach()
{
	if (m_spCP)
	{
		m_spCP->Unadvise (m_dwCookie);
		m_spCP = NULL;
	}
}

void CDownloads_Opinions_WBEvents::RetrieveLinkToUsText(IDispatch *pdDoc)
{
	IHTMLDocument2Ptr spDoc (pdDoc);
	ASSERT (spDoc != NULL);
	IHTMLElementCollectionPtr spelForms;
	spDoc->get_forms (&spelForms);
	if (spelForms == NULL)
		return;	

	long cForms = 0;
	spelForms->get_length (&cForms);
	for (long i = 0; i < cForms; i++)
	{
		IDispatchPtr spdel;
		spelForms->item (COleVariant (i), COleVariant (i), &spdel);
		ASSERT (spdel != NULL);
		IHTMLFormElementPtr spForm (spdel);
		ASSERT (spForm != NULL);

		

		bool bFound;
		
		CString str = GetFormInputElementText (spForm, "LINKTOUSTEXT", bFound);
		if (bFound)
			_App.View_SpreadHelpDialog_LinkToUsText (str); 
		
		str = GetFormInputElementText (spForm, "RADIOBUTTON1TEXT", bFound);
		if (bFound)
			_App.View_SpreadHelpDialog_RadioButton1Text (str);
		str = GetFormInputElementText (spForm, "RADIOBUTTON2TEXT", bFound);
		if (bFound)
			_App.View_SpreadHelpDialog_RadioButton2Text (str);
	}
}

CString CDownloads_Opinions_WBEvents::GetFormInputElementText(IHTMLFormElement *pForm, LPCSTR pszElementName, bool& bFound)
{
	bFound = false;
	IDispatchPtr spdelInp;
	pForm->item (COleVariant (pszElementName), COleVariant ((long)0), &spdelInp);
	if (spdelInp == NULL)
		return "";
	IHTMLInputElementPtr spelInp (spdelInp);
	if (spelInp == NULL)
		return "";
	BSTR bstr;
	spelInp->get_defaultValue (&bstr);
	CString strEl = bstr;
	SysFreeString (bstr);
	bFound = true;
	return strEl;
}

void CDownloads_Opinions_WBEvents::OnNavigateError(LPDISPATCH pDisp, VARIANT *URL, VARIANT *TargetFrameName, VARIANT *StatusCode, BOOL *pbCancel)
{
	

	if (m_pwndOpinions->m_cSetAsCurrentTabAfterLoadComplete)
	{
		
		InterlockedDecrement (&m_pwndOpinions->m_cSetAsCurrentTabAfterLoadComplete);
	}
	else
	{
		
		AfxGetApp ()->m_pMainWnd->MessageBox (LS (L_COMMUNITYSERVUNAVAIL), LS (L_ERR), MB_ICONERROR);
		_pwndDownloads->m_wndDownloads.m_info.set_CurTab (DIT_LOG);
	}

	m_pwndOpinions->m_enCS = DOCS_UNKNOWN;
	

	*pbCancel = TRUE;
}
