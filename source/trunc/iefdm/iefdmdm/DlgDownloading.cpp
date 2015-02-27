/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "DlgDownloading.h"
#include "vmsIeProtectedMode.h"

BOOL CDlgDownloading::PromptUserChooseSaveLocation()
{
	BOOL bPM = FALSE;
	if (SUCCEEDED (vmsIeProtectedMode::IEIsProtectedModeProcess (&bPM)) && bPM)
	{
		USES_CONVERSION;
		HANDLE hState = NULL;
		wchar_t wszFilter [1000];
		LPCTSTR ptszExt = vmsFileExtension::getExtensionPart (m_pBSC->getFileName ());
		if (ptszExt)
		{
			TCHAR tsz [1000];
			_stprintf (tsz, _T ("%s (*.%s)|*.%s|"), vmsFileExtension::GetExtensionName (ptszExt).c_str (),
				ptszExt, ptszExt);
			wcscpy (wszFilter, T2CW (tsz));
		}
		else
		{
			wcscpy (wszFilter, L"All Files (*.*)|*.*|");
		}
		LPWSTR pwszFileChosen = NULL;
		HRESULT hr = vmsIeProtectedMode::IEShowSaveFileDialog (m_hWnd, T2CW (m_pBSC->getFileName ()),
			NULL, wszFilter, ptszExt ? T2CW (ptszExt) : NULL, 1, 
			OFN_HIDEREADONLY | OFN_NOCHANGEDIR | OFN_OVERWRITEPROMPT | OFN_PATHMUSTEXIST,
			&pwszFileChosen, &hState);

		if (FAILED (hr) || hr == S_FALSE)
			return FALSE;

		TCHAR tszTmpPath [MAX_PATH] = _T ("");
		GetTempPath (MAX_PATH, tszTmpPath);
		if (*tszTmpPath && tszTmpPath [_tcslen (tszTmpPath)-1] != '\\')
			_tcscat (tszTmpPath, _T ("\\"));
		_tcscat (tszTmpPath, m_pBSC->getFileName ());
		m_tstrCurFile = tszTmpPath;

		m_tstrDstFile = W2CT (pwszFileChosen);
		CoTaskMemFree (pwszFileChosen);

		m_hIePmSaveFileState = hState;

		return TRUE;
	}

	
	
	OPENFILENAME ofn;
	ZeroMemory (&ofn, sizeof (ofn));
	ofn.lStructSize = sizeof (ofn);
	ofn.hwndOwner = m_hWnd;
	
	TCHAR tszFilter [1000];
	LPCTSTR ptszExt = vmsFileExtension::getExtensionPart (m_pBSC->getFileName ());
	if (ptszExt != NULL && *ptszExt != 0)
	{
		LPTSTR ptsz = tszFilter;
		_stprintf (ptsz, _T ("%s (*.%s)"), vmsFileExtension::GetExtensionName (ptszExt).c_str (),
			ptszExt);
		ptsz += _tcslen (ptsz) + 1;
		_stprintf (ptsz, _T ("*.%s"), ptszExt);
		ptsz += _tcslen (ptsz) + 1;
		*ptsz = 0;
		ofn.lpstrFilter = tszFilter;
	}
	
	TCHAR tszFile [1000];
	_tcscpy (tszFile, m_pBSC->getFileName ());
	ofn.lpstrFile = tszFile;
	ofn.nMaxFile = sizeof (tszFile) / sizeof (TCHAR);
	ofn.Flags = OFN_EXPLORER | OFN_HIDEREADONLY | OFN_NOCHANGEDIR | OFN_OVERWRITEPROMPT | 
		OFN_PATHMUSTEXIST;
	ofn.lpstrDefExt = ptszExt;
	
	if (FALSE == GetSaveFileName (&ofn))
		return FALSE;
	
	m_tstrDstFile = m_tstrCurFile = ofn.lpstrFile;

	return TRUE;
}
