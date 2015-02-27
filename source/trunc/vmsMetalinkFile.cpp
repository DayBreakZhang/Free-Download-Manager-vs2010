/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "vmsMetalinkFile.h"

_COM_SMARTPTR_TYPEDEF (IXMLDOMNamedNodeMap, __uuidof (IXMLDOMNamedNodeMap));

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

vmsMetalinkFile::vmsMetalinkFile()
{
	CoInitialize (NULL);
}

vmsMetalinkFile::~vmsMetalinkFile()
{
	CoUninitialize ();
}

BOOL vmsMetalinkFile::Parse(LPCSTR pszFile)
{
	USES_CONVERSION;

	IXMLDOMDocumentPtr spXML;
	IXMLDOMNodePtr spNode;

	spXML.CreateInstance (__uuidof (DOMDocument));

	if (spXML == NULL)
		return FALSE;

	spXML->put_async (FALSE);

	VARIANT_BOOL bRes;
	spXML->load (COleVariant (pszFile), &bRes);
	if (bRes == FALSE)
		return FALSE;

	spXML->selectSingleNode (L"metalink", &spNode);
	if (spNode == NULL)
		return FALSE;

	IXMLDOMNodeListPtr spNodeList;
	spNode->get_childNodes (&spNodeList);

	if (spNodeList == NULL)
		return FALSE;

	IXMLDOMNodePtr spItem;

	BOOL bHasOkFilesNode = FALSE;

	while (SUCCEEDED (spNodeList->nextNode (&spItem)) && spItem != NULL)
	{
		CComBSTR bstrName;
		spItem->get_nodeName (&bstrName);

		if (bstrName == L"description")
		{
			CComBSTR bstrText;
			spItem->get_text (&bstrText);
			m_strDescription = W2A (bstrText);
		}

		else if (bstrName == L"files")
		{
			if (ReadFilesNode (spItem))
				bHasOkFilesNode = TRUE;
		}

		spItem = NULL;
	}

	return bHasOkFilesNode;
}

BOOL vmsMetalinkFile::ReadFilesNode(IXMLDOMNode *pFiles)
{
	IXMLDOMNodeListPtr spNodeList;
	pFiles->get_childNodes (&spNodeList);

	if (spNodeList == NULL)
		return FALSE;

	IXMLDOMNodePtr spItem;
	BOOL bHasOkFileNode = FALSE;

	while (SUCCEEDED (spNodeList->nextNode (&spItem)) && spItem != NULL)
	{
		CComBSTR bstrName;
		spItem->get_nodeName (&bstrName);

		if (bstrName == L"file")
		{
			if (ReadFileNode (spItem))
				bHasOkFileNode = TRUE;
		}

		spItem = NULL;
	}

	return bHasOkFileNode;
}

BOOL vmsMetalinkFile::ReadFileNode(IXMLDOMNode *pFile)
{
	USES_CONVERSION;

	IXMLDOMNodeListPtr spNodeList;
	pFile->get_childNodes (&spNodeList);

	if (spNodeList == NULL)
		return FALSE;

	vmsMetalinkFile_File file;

	IXMLDOMNamedNodeMapPtr spAttrs;
	pFile->get_attributes (&spAttrs);
	if (spAttrs != NULL)
	{
		IXMLDOMNodePtr spFileName;
		spAttrs->getNamedItem (L"name", &spFileName);
		if (spFileName != NULL)
		{
			COleVariant vt;
			spFileName->get_nodeValue (&vt);
			ASSERT (vt.vt == VT_BSTR);
			if (vt.vt == VT_BSTR)
				file.strName = W2A (vt.bstrVal);
		}
	}

	IXMLDOMNodePtr spItem;
	while (SUCCEEDED (spNodeList->nextNode (&spItem)) && spItem != NULL)
	{
		CComBSTR bstrName;
		spItem->get_nodeName (&bstrName);

		if (bstrName == L"verification")
		{
			ReadVerificationNode (spItem, &file);			
		}

		else if (bstrName == L"resources")
		{
			ReadResourcesNode (spItem, &file);
		}

		else if (bstrName == L"os")
		{
			CComBSTR bstrText;
			spItem->get_text (&bstrText);
			file.strOS = W2A (bstrText);
		}

		spItem = NULL;
	}

	if (file.vMirrors.size () == 0)
		return FALSE;

	m_vFiles.add (file);

	return TRUE;
}

BOOL vmsMetalinkFile::ReadVerificationNode(IXMLDOMNode *pNode, vmsMetalinkFile_File *file)
{
	IXMLDOMNodeListPtr spNodeList;
	pNode->get_childNodes (&spNodeList);

	if (spNodeList == NULL)
		return FALSE;

	IXMLDOMNodePtr spItem;
	while (SUCCEEDED (spNodeList->nextNode (&spItem)) && spItem != NULL)
	{
		CComBSTR bstrName;
		spItem->get_nodeName (&bstrName);

		if (bstrName == L"hash")
		{
			vmsMetalinkFile_File_Hash hash;
			if (ReadHashNode (spItem, &hash))
				file->vHashes.add (hash);
		}

		spItem = NULL;
	}

	return TRUE;
}

BOOL vmsMetalinkFile::ReadResourcesNode(IXMLDOMNode *pNode, vmsMetalinkFile_File *file)
{
	IXMLDOMNodeListPtr spNodeList;
	pNode->get_childNodes (&spNodeList);

	if (spNodeList == NULL)
		return FALSE;

	IXMLDOMNodePtr spItem;
	while (SUCCEEDED (spNodeList->nextNode (&spItem)) && spItem != NULL)
	{
		CComBSTR bstrName;
		spItem->get_nodeName (&bstrName);

		if (bstrName == L"url")
		{
			vmsMetalinkFile_File_Url url;
			if (ReadUrlNode (spItem, &url))
				file->vMirrors.add (url);
		}

		spItem = NULL;
	}

	return TRUE;
}

BOOL vmsMetalinkFile::ReadHashNode(IXMLDOMNode *pNode, vmsMetalinkFile_File_Hash *hash)
{
	USES_CONVERSION;

	IXMLDOMNamedNodeMapPtr spAttrs;
	pNode->get_attributes (&spAttrs);
	if (spAttrs == NULL)
		return FALSE;

	IXMLDOMNodePtr spType;
	spAttrs->getNamedItem (L"type", &spType);
	if (spType == NULL)
		return FALSE;

	COleVariant vt;
	spType->get_nodeValue (&vt);
	ASSERT (vt.vt == VT_BSTR);
	if (vt.vt == VT_BSTR)
		hash->strAlgorithm = W2A (vt.bstrVal);
	
	CComBSTR bstrText;
	pNode->get_text (&bstrText);
	if (bstrText.Length () == 0)
		return FALSE;

	hash->strChecksum = W2A (bstrText);

	return TRUE;
}

BOOL vmsMetalinkFile::ReadUrlNode(IXMLDOMNode *pNode, vmsMetalinkFile_File_Url *url)
{
	USES_CONVERSION;

	IXMLDOMNamedNodeMapPtr spAttrs;
	pNode->get_attributes (&spAttrs);
	if (spAttrs == NULL)
		return FALSE;

	IXMLDOMNodePtr spType;
	spAttrs->getNamedItem (L"type", &spType);
	if (spType == NULL)
		return FALSE;

	COleVariant vt;
	spType->get_nodeValue (&vt);
	ASSERT (vt.vt == VT_BSTR);
	if (vt.vt == VT_BSTR)
		url->strProtocol = W2A (vt.bstrVal);
	
	CComBSTR bstrText;
	pNode->get_text (&bstrText);
	if (bstrText.Length () == 0)
		return FALSE;

	url->strUrl = W2A (bstrText);

	return TRUE;
}

LPCSTR vmsMetalinkFile::get_Description()
{
	return m_strDescription;
}

int vmsMetalinkFile::get_FileCount()
{
	return m_vFiles.size ();
}

vmsMetalinkFile_File* vmsMetalinkFile::get_File(int nIndex)
{
	ASSERT (nIndex < get_FileCount ());
	return &m_vFiles [nIndex];
}
