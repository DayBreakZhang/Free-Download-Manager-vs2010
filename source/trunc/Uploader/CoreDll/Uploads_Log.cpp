/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "Uploads_Log.h"

#define ID_CLEAR                        	32797

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CUploads_Log::CUploads_Log()
{
}

CUploads_Log::~CUploads_Log()
{
}

BEGIN_MESSAGE_MAP(CUploads_Log, CWndLog)
	//{{AFX_MSG_MAP(CUploads_Log)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CUploads_Log::Create(CWnd *pParent)
{
	if (!CWndLog::Create (pParent))
		return FALSE;

	ReadState ("UploadsLog");

	return TRUE;
}

void CUploads_Log::set_CurrentUpload(vmsUploadSmartPtr upl)
{
	if (m_pUpload == upl)
		return;

	
	vmsUploadSmartPtr upl2 = m_pUpload;

	m_pEvMgr = upl ? &upl->log : NULL;
	m_pUpload = upl;
	
	OnForceUpdate ();
}

vmsUploadSmartPtr CUploads_Log::get_CurrentUpload()
{
	return m_pUpload;
}
