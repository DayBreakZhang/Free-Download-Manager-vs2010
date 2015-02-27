/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSMETALINKFILE_H__D69EE721_C692_46B8_B91E_1F7A24B5C3A6__INCLUDED_)
#define AFX_VMSMETALINKFILE_H__D69EE721_C692_46B8_B91E_1F7A24B5C3A6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "list.h"

struct vmsMetalinkFile_File_Hash
{
	fsString strAlgorithm;
	fsString strChecksum;
};

struct vmsMetalinkFile_File_Url
{
	fsString strProtocol;
	fsString strUrl;
};

struct vmsMetalinkFile_File
{
	fsString strName;
	fsString strOS;
	fs::list <vmsMetalinkFile_File_Hash> vHashes;
	fs::list <vmsMetalinkFile_File_Url> vMirrors;
};

class vmsMetalinkFile  
{
public:
	
	BOOL Parse (LPCSTR pszFile);
	
	LPCSTR get_Description();
	
	int get_FileCount();
	vmsMetalinkFile_File* get_File (int nIndex);
	
	vmsMetalinkFile();
	virtual ~vmsMetalinkFile();

protected:
	
	BOOL ReadUrlNode (IXMLDOMNode *pNode, vmsMetalinkFile_File_Url* url);
	BOOL ReadHashNode (IXMLDOMNode *pNode, vmsMetalinkFile_File_Hash* hash);
	BOOL ReadResourcesNode (IXMLDOMNode *pNode, vmsMetalinkFile_File *file);
	BOOL ReadVerificationNode (IXMLDOMNode *pNode, vmsMetalinkFile_File *file);
	BOOL ReadFileNode (IXMLDOMNode *pFile);
	BOOL ReadFilesNode (IXMLDOMNode* pFiles);
	
	fsString m_strDescription;
	fs::list <vmsMetalinkFile_File> m_vFiles;
};

#endif 
