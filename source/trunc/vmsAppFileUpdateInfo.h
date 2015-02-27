/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#pragma once
#include <vmsTmpFileName.h>
class vmsAppFileUpdateInfo
{
public:
	struct Info
	{
		tstring tstrFileURL;
		tstring tstrVersion;
	};
public:
	vmsAppFileUpdateInfo(LPCTSTR ptszFileUpdateInfoURL, LPCTSTR ptszFileName, UINT nAppBuildNumber) :
		m_tstrUpdateInfoURL (ptszFileUpdateInfoURL),
		m_tstrFileName (ptszFileName),
		m_nAppBuildNumber (nAppBuildNumber)
	{
	}

	virtual ~vmsAppFileUpdateInfo(void)
	{
	}

	const Info* getResult () const {return &m_result;}

	bool Retrieve ()
	{
		vmsTmpFileName tmpFile (_T ("tmp"), _T ("xml"));
		DeleteUrlCacheEntry (m_tstrUpdateInfoURL.c_str ());
		HRESULT hr = URLDownloadToFile (NULL, m_tstrUpdateInfoURL.c_str (), tmpFile, 0, NULL);
		if (FAILED (hr))
			return false;
		IXMLDOMDocumentPtr spXML;
		spXML.CreateInstance (__uuidof (DOMDocument));
		if (!spXML)
			return false;
		spXML->put_async (FALSE);
		VARIANT_BOOL bRes = FALSE;
		spXML->load (COleVariant (tmpFile), &bRes);
		if (!bRes)
			return false;
		IXMLDOMNodePtr spNode;
		spXML->selectSingleNode (L"FileUpdateInfo", &spNode);
		if (!spNode)
			return false;
		return ProcessUpdateInfoXml (spNode);
	}

protected:
	bool ProcessUpdateInfoXml (IXMLDOMNode *pNode)
	{
		m_result = Info ();

		IXMLDOMNodeListPtr spList;
		pNode->get_childNodes (&spList);
		if (!spList)
			return false;

		IXMLDOMNodePtr spItem;
		while (SUCCEEDED (spList->nextNode (&spItem)) && spItem)
		{
			CComBSTR bstrName;
			spItem->get_nodeName (&bstrName);
			if (_wcsicmp (bstrName, L"Builds"))
			{
				spItem = NULL;
				continue;
			}

			IXMLDOMNamedNodeMapPtr spAttrs;
			spItem->get_attributes (&spAttrs);
			if (!spAttrs)
				return false;

			IXMLDOMNodePtr spMin, spMax;
			spAttrs->getNamedItem (L"min", &spMin);
			spAttrs->getNamedItem (L"max", &spMax);

			UINT nMin = UINT_MAX, nMax = UINT_MAX;

			COleVariant vtMin, vtMax;
			if (spMin)
				spMin->get_nodeValue (&vtMin);
			if (spMax)
				spMax->get_nodeValue (&vtMax);

			if (vtMin.vt == VT_BSTR)
				nMin = _wtoi (vtMin.bstrVal);
			if (vtMax.vt == VT_BSTR)
				nMax = _wtoi (vtMax.bstrVal);

			if (m_nAppBuildNumber >= nMin && m_nAppBuildNumber <= nMax)
			{
				ReadUpdateInfo (spItem, m_result);
				break;
			}

			spItem = NULL;
		}
		return true;
	}

	static bool ReadUpdateInfo (IXMLDOMNode *pNode, Info& res)
	{
		USES_CONVERSION;

		IXMLDOMNodeListPtr spList;
		pNode->get_childNodes (&spList);
		if (!spList)
			return false;

		res = Info ();

		IXMLDOMNodePtr spItem;
		while (SUCCEEDED (spList->nextNode (&spItem)) && spItem)
		{
			CComBSTR bstrName;
			spItem->get_nodeName (&bstrName);

			CComBSTR bstrText; 
			spItem->get_text (&bstrText);

			if (!_wcsicmp (bstrName, L"URL"))
				res.tstrFileURL = W2CT (bstrText);

			if (!_wcsicmp (bstrName, L"Version"))
				res.tstrVersion = W2CT (bstrText);

			spItem = NULL;
		}

		return true;
	}

protected:
	tstring m_tstrUpdateInfoURL;
	tstring m_tstrFileName;
	UINT m_nAppBuildNumber;
	Info m_result;
};

