/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "fdmapp.h"
#include "DlgPI2_WbCustomization.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

CDlgPI2_WbCustomization::CDlgPI2_WbCustomization()
{
	m_pwndParent = NULL;
}

CDlgPI2_WbCustomization::~CDlgPI2_WbCustomization()
{

}

BOOL CDlgPI2_WbCustomization::OnNavigateURL(LPCTSTR ptszUrl)
{
	CString str = ptszUrl;
	if (str.Left (4) == "cmd:")
	{
		str = str.Right (str.GetLength () - 6);
		UINT nCmd = _ttoi (str);
		ASSERT (m_pwndParent != NULL);
		if (m_pwndParent)
			m_pwndParent->PostMessage (WM_COMMAND, nCmd);
		return TRUE;
	}
	return CWebBrowser2Customization::OnNavigateURL (ptszUrl);
}
