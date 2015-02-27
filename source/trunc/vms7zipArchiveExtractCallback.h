/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_vms7zipArchiveExtractCallback_H__DEC4C09F_A9EE_40B3_9CA3_99C17CF06198__INCLUDED_)
#define AFX_vms7zipArchiveExtractCallback_H__DEC4C09F_A9EE_40B3_9CA3_99C17CF06198__INCLUDED_

#include "vmsArchiveCallback.h"	
#if _MSC_VER > 1000
#pragma once
#endif 

#include "vmsArchiveCallback.h"
#include <archive\IArchive.h>
#include <archive\String.h>
#include <archive\extractmode.h>

class vms7zipArchiveExtractCallback : public IArchiveExtractCallback
{
public:
	
	LPCSTR get_FurtherExtractFile ();
	
	bool is_AbortedByUser();

	
	STDMETHOD(SetOperationResult )(Int32 resultEOperationResult);
	STDMETHOD(PrepareOperation )(Int32 askExtractMode);
	STDMETHOD(GetStream )(UInt32 index, ISequentialOutStream **outStream, Int32 askExtractMode);

	
	ULONG STDMETHODCALLTYPE Release();
	ULONG STDMETHODCALLTYPE AddRef ();
	STDMETHOD(QueryInterface )(REFIID riid, void** ppvObject);

	
	STDMETHOD(SetCompleted )(const UInt64 *completeValue);
	STDMETHOD(SetTotal )(UInt64 total);

	
	vms7zipArchiveExtractCallback(IInArchive* pArc, LPCSTR pszOutFolder, vmsArchiveCallback* pAC, LPCSTR pszSrcArcFileName);
	virtual ~vms7zipArchiveExtractCallback();

protected:
	
	
	
	
	
	CString m_strFurtherExtractFile;
	
	bool m_bAbortedByUser;
	
	void UpdateFileInfo();
	
	NExtract::NOverwriteMode::EEnum AskOverwrite();
	
	UInt64 m_uTotal;
	
	UInt64 m_uCurFileNewSize;
	
	vmsArchiveCallback* m_pAC;
	IInArchive* m_pArc;
	
	UString m_strOutFolder;
	
	CString m_strCurFile;
	
	bool m_bSplit;
	
	UInt64 m_uPosition;
	
	bool m_bAttributesDefined;
	DWORD m_dwAttributes;
	
	bool m_bLastWriteTimeDefined;
	FILETIME m_timeLastWrite;
	NExtract::NOverwriteMode::EEnum m_enOverwriteMode;
	
	class COutFileStream* m_pFileStream;
	
	CString m_strSrcArcFileName;
};

#endif 
