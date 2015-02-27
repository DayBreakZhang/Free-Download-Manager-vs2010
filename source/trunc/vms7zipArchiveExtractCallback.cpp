/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "vms7zipArchiveExtractCallback.h"
#include <archive\PropVariant.h>
#include <archive\String.h>
#include <archive\PropVariantConversions.h>
#include <archive\StringConvert.h>
#include <archive\FileStreams.h>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

vms7zipArchiveExtractCallback::vms7zipArchiveExtractCallback(IInArchive* pArc, LPCSTR pszOutFolder, vmsArchiveCallback* pAC, LPCSTR pszSrcArcFileName)
{
	m_pArc = pArc;
	m_pAC = pAC;
	_bstr_t bstr = pszOutFolder;
	m_strOutFolder = bstr;

	if (m_strOutFolder [m_strOutFolder.Length () - 1] != '\\')
		m_strOutFolder += '\\';

	CString str = m_strOutFolder;
	fsBuildPathToFile (str);

	m_bSplit = false;
	m_uPosition = 0;

	m_enOverwriteMode = NExtract::NOverwriteMode::kAskBefore;

	m_pFileStream = NULL;
	m_bAbortedByUser = false;

	m_strSrcArcFileName = pszSrcArcFileName;
}

vms7zipArchiveExtractCallback::~vms7zipArchiveExtractCallback()
{
	if (m_pFileStream)
		m_pFileStream->Release ();
}

STDMETHODIMP vms7zipArchiveExtractCallback::SetTotal(UInt64 total)
{
	m_uTotal = total;
	return S_OK;
}

STDMETHODIMP vms7zipArchiveExtractCallback::SetCompleted(const UInt64 *completeValue)
{
	if (m_pAC) 
	{
		double d = (double)(INT64)(*completeValue) / (INT64)m_uTotal;
		if (false == m_pAC->SetProgress ((int)(d * 100))) 
		{
			m_bAbortedByUser = true;
			return E_ABORT;
		}
	}
	return S_OK;
}

STDMETHODIMP vms7zipArchiveExtractCallback::QueryInterface(REFIID riid, void **ppvObject)
{
	return E_NOTIMPL;
}

ULONG vms7zipArchiveExtractCallback::AddRef()
{
	return 1;
}

ULONG vms7zipArchiveExtractCallback::Release()
{
	return 1;
}

STDMETHODIMP vms7zipArchiveExtractCallback::GetStream(UInt32 index, ISequentialOutStream **outStream, Int32 askExtractMode)
{
	*outStream = NULL;
	m_bAbortedByUser = false;

	
	NWindows::NCOM::CPropVariant propVariant;
	m_pArc->GetProperty (index, kpidPath, &propVariant);
	UString s = ConvertPropVariantToString(propVariant);

	if (s == L"")
	{
		
		
		

		m_strFurtherExtractFile = m_strSrcArcFileName;
		LPCSTR psz = strrchr (m_strFurtherExtractFile, '.');
		if (psz) 
		{
			int pos = psz - m_strFurtherExtractFile;
			m_strFurtherExtractFile.Delete (pos, m_strFurtherExtractFile.GetLength () - pos);
		}

		BSTR bstr  = m_strFurtherExtractFile.AllocSysString ();
		s = bstr;
		SysFreeString (bstr);
	}
	else 
	{
		m_strFurtherExtractFile = "";
	}

	m_bSplit = false;

	m_strCurFile = s;
	
	if (m_pAC) 
	{
		if (m_pAC->BeforeExtract (m_strCurFile) == false) 
		{
			m_bAbortedByUser = true;
			return E_ABORT;
		}
	}

	PROPVARIANT pva;
	PropVariantInit (&pva);

	m_pArc->GetProperty (index, kpidPosition, &pva);
	if (pva.vt != VT_EMPTY)
	{
		if (pva.vt != VT_UI8)
			return E_FAIL;
		m_uPosition = pva.uhVal.QuadPart;
		m_bSplit = true;
	}

	PropVariantClear (&pva);
	m_pArc->GetProperty (index, kpidAttributes, &pva);
	m_bAttributesDefined = pva.vt != VT_EMPTY;
	if (m_bAttributesDefined)
		m_dwAttributes = pva.ulVal;

	PropVariantClear (&pva);
	m_pArc->GetProperty (index, kpidLastWriteTime, &pva);
	m_bLastWriteTimeDefined = pva.vt == VT_FILETIME;
	if (m_bLastWriteTimeDefined)
		m_timeLastWrite = pva.filetime;

	m_uCurFileNewSize = (UInt64)-1;
	PropVariantClear (&pva);
	m_pArc->GetProperty (index, kpidSize, &pva);
	if (pva.vt != VT_EMPTY)
		m_uCurFileNewSize = ConvertPropVariantToUInt64 (pva);

	bool bAnti = false;
	PropVariantClear (&pva);
	m_pArc->GetProperty (index, kpidIsAnti, &pva);
	if (pva.vt == VT_BOOL)
		bAnti = pva.boolVal != VARIANT_FALSE;

	PropVariantClear (&pva);
	m_pArc->GetProperty(index, kpidIsFolder, &pva);
	bool bIsFolder = pva.vt == VT_BOOL ? pva.boolVal != 0 : false;

	UString s2 = m_strOutFolder;
	s2 += s;

	
	
	if (m_strFurtherExtractFile != "")
		m_strFurtherExtractFile = s2;

	if (bIsFolder) 
	{
		CString str = s2;
		if (bAnti)
		{
			RemoveDirectory (str);
		}
		else
		{
			
			str += "\\file.ext";
			fsBuildPathToFile (str);
		}
		return S_OK;
	}

	CString str = s2;
	fsBuildPathToFile (str);

	if (m_bSplit == false)
	{
		CString strFile = s2;
		
		if (GetFileAttributes (strFile) != DWORD (-1)) 
		{
			NExtract::NOverwriteMode::EEnum enOM = m_enOverwriteMode;
			if (enOM == NExtract::NOverwriteMode::kAskBefore) 
			{
				enOM = AskOverwrite (); 
				if (enOM == NExtract::NOverwriteMode::kAskBefore) 
				{
					m_bAbortedByUser = true;
					return E_ABORT;
				}
			}
			switch (enOM)
			{
				case NExtract::NOverwriteMode::kSkipExisting: 
					return S_OK;
				case NExtract::NOverwriteMode::kWithoutPrompt:
					break;
				default: 
					ASSERT (FALSE); 
					break;
			}
		}

		if (m_pFileStream)
			m_pFileStream->Release ();

		m_pFileStream = new COutFileStream;
		m_pFileStream->AddRef ();
		bool b = m_pFileStream->Create (s2, true);
		if (b)
		{
			if (m_bSplit)
				m_pFileStream->Seek (m_uPosition, STREAM_SEEK_SET, NULL);
			CMyComPtr<ISequentialOutStream> outStreamLoc(m_pFileStream);
			*outStream = outStreamLoc;
			(*outStream)->AddRef ();
		}
	}

	
	return S_OK;
}

STDMETHODIMP vms7zipArchiveExtractCallback::PrepareOperation(Int32 askExtractMode)
{
	return S_OK;
}

STDMETHODIMP vms7zipArchiveExtractCallback::SetOperationResult(Int32 resultEOperationResult)
{
	switch(resultEOperationResult)
	{
    case NArchive::NExtract::NOperationResult::kOK:
		UpdateFileInfo ();
		if (m_pFileStream) 
		{
			m_pFileStream->Release ();
			m_pFileStream = NULL;
		}
  		if (m_pAC)
			m_pAC->AfterExtract (m_strCurFile, AC_ER_OK);
	    return S_OK;
 
    default:
		if (m_pFileStream) 
		{
			m_pFileStream->Release ();
			m_pFileStream = NULL;
			CString str = m_strOutFolder; str += m_strCurFile;
			DeleteFile (str);
		}
		if (m_pAC)
			m_pAC->AfterExtract (m_strCurFile, AC_ER_FAILED);
        return E_FAIL;
    }
}

NExtract::NOverwriteMode::EEnum vms7zipArchiveExtractCallback::AskOverwrite()
{
	NExtract::NOverwriteMode::EEnum enOverwriteMode = NExtract::NOverwriteMode::kWithoutPrompt;

	if (m_pAC != NULL) 
	{
		vmsAC_OverwriteMode enOM = AC_OM_OVERWRITE;
		bool bForAll = false;

		vmsOverwriteFileInfo ofi;
		CString str = m_strOutFolder; str += m_strCurFile;
		ofi.pszFile = str;
		ofi.ptimeNewLastWrite = m_bLastWriteTimeDefined ? &m_timeLastWrite : NULL;
		ofi.puNewSize = m_uCurFileNewSize != (UInt64)-1 ? &m_uCurFileNewSize : NULL;
		m_pAC->AskOverwrite (ofi, enOM, bForAll);

		switch (enOM) 
		{
		case AC_OM_OVERWRITE:
			enOverwriteMode = NExtract::NOverwriteMode::kWithoutPrompt;
			break;

		case AC_OM_SKIP:
			enOverwriteMode = NExtract::NOverwriteMode::kSkipExisting;
			break;

		case AC_OM_CANCEL:
			return NExtract::NOverwriteMode::kAskBefore;
		}

		if (bForAll)
			m_enOverwriteMode = enOverwriteMode;
	}

	return enOverwriteMode;
}

void vms7zipArchiveExtractCallback::UpdateFileInfo()
{
	if (m_pFileStream && m_bLastWriteTimeDefined)
		m_pFileStream->File.SetLastWriteTime (&m_timeLastWrite);

	CString strFile = m_strOutFolder; 
	strFile += m_strCurFile;

	if (m_bAttributesDefined)
		SetFileAttributes (strFile, m_dwAttributes);	
}

bool vms7zipArchiveExtractCallback::is_AbortedByUser()
{
	return m_bAbortedByUser;
}

LPCSTR vms7zipArchiveExtractCallback::get_FurtherExtractFile()
{
	return m_strFurtherExtractFile;
}
