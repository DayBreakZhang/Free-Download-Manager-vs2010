/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSDIALOGHELPER_H__7FCAEF88_4C3B_4159_AC5E_2C7E29468470__INCLUDED_)
#define AFX_VMSDIALOGHELPER_H__7FCAEF88_4C3B_4159_AC5E_2C7E29468470__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class vmsDialogHelper  
{
public:
	
	
	
	
	static void SetDlgBytesGroup(CDialog* pDlg, UINT64 uVal, UINT nIDVal, UINT nIDDim);
	
	static BOOL GetDlgBytesGroup(CDialog* pDlg, UINT nIDVal, UINT nIDDim, UINT64 *pVal);

	vmsDialogHelper();
	virtual ~vmsDialogHelper();

};

#endif 
