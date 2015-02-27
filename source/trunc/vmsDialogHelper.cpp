/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "vmsDialogHelper.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

vmsDialogHelper::vmsDialogHelper()
{

}

vmsDialogHelper::~vmsDialogHelper()
{

}

BOOL vmsDialogHelper::GetDlgBytesGroup(CDialog *pDlg, UINT nIDVal, UINT nIDDim, UINT64 *pVal)
{
	CString str;
	pDlg->GetDlgItemText (nIDVal, str);

	if (str.GetLength () == 0)
	{
		SetLastError (NOERROR);
		return FALSE;
	}

	LPCTSTR ptsz = (LPCTSTR)str;
	while (*ptsz)
	{
		if (!_istdigit (*ptsz) && *ptsz != '.')
		{
			pDlg->MessageBox (LS (L_VALUE_MUSTBE_SOME_NUMBER_GREATER_OR_EQUAL_TO_ZERO), LS (L_INPERR), MB_ICONEXCLAMATION);
			pDlg->GetDlgItem (nIDVal)->SetFocus ();
			SetLastError (ERROR_INVALID_DATA);
			return FALSE;
		}
		ptsz++;
	}

	int iDim = ((CComboBox*) pDlg->GetDlgItem (nIDDim))->GetCurSel ();

	if (iDim == CB_ERR)
	{
		pDlg->MessageBox (LS (L_ENTERDIM), LS (L_INPERR), MB_ICONEXCLAMATION);
		pDlg->GetDlgItem (nIDDim)->SetFocus ();
		SetLastError (ERROR_INVALID_DATA);
		return FALSE;
	}

	double d = atof (str);

	while (iDim--)	
		d *= 1024;	

	*pVal = (UINT64) d;

	return TRUE;
}

void vmsDialogHelper::SetDlgBytesGroup(CDialog *pDlg, UINT64 uVal, UINT nIDVal, UINT nIDDim)
{
	double d = (double)(INT64)uVal;
	int i = 0;

	while (d > 9999)	
	{
		d /= 1024;	
		i++;		
	}

	CString str;
	str.Format ("%.*g", d > 999 ? 4 : 3, d);

	pDlg->SetDlgItemText (nIDVal, str);
	((CComboBox*) pDlg->GetDlgItem (nIDDim))->SetCurSel (i);
}
