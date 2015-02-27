/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSSECURITY_H__CA3685E7_1205_4240_821F_4349BA5DCB0B__INCLUDED_)
#define AFX_VMSSECURITY_H__CA3685E7_1205_4240_821F_4349BA5DCB0B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

const LPCSTR FdmCryptSignatureMarker = "8E3662E2-7906-4b3d-BD36-862116149559";

class vmsSecurity  
{
public:
	static bool ExtractFileFromSignedFile (LPCTSTR ptszSrcFile, LPCTSTR ptszDstFile);
	static bool VerifySign (LPCTSTR ptszFile, LPCTSTR ptszPubKey);
	vmsSecurity();
	virtual ~vmsSecurity();

};

#endif 
