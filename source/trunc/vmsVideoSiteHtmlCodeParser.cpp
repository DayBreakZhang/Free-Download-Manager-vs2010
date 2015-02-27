/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "vmsVideoSiteHtmlCodeParser.h"
#include "inetutil.h"

_COM_SMARTPTR_TYPEDEF (IXMLDOMNamedNodeMap, __uuidof (IXMLDOMNamedNodeMap));

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

#define is_valid_char(c) (c >= 32 && c < 127)

vmsVideoSiteHtmlCodeParser::vmsVideoSiteHtmlCodeParser()
{
	CoInitialize (NULL);
}

vmsVideoSiteHtmlCodeParser::~vmsVideoSiteHtmlCodeParser()
{
	CoUninitialize ();
}

BOOL vmsVideoSiteHtmlCodeParser::Parse(LPCSTR pszSite, LPCSTR pszHtml)
{
	switch (GetSupportedSiteIndex (pszSite))
	{
	case 0:
		return Parse_Youtube (pszHtml);

	case 1:
		return Parse_GoogleVideo (pszHtml);

	case 2:
		return Parse_LiveDigital (pszHtml);

	case 3:
		return Parse_MySpace (pszHtml);

	case 4:
		return Parse_Sharkle (pszHtml);

	case 5:
		return Parse_Blennus (pszHtml);

	case 6:
		return Parse_DailyMotion (pszHtml);

	case 7:
		return Parse_Grouper (pszHtml);

	default:
		return FALSE;
	}
}

BOOL vmsVideoSiteHtmlCodeParser::Parse_Youtube(LPCSTR pszHtml)
{
	fsString strTitle, strUrl; 

	
	
	
	
	LPSTR psz = const_cast<LPSTR>(strstr (pszHtml, "<meta name=\"title\""));

	if (psz)
	{
		psz = strstr (psz, "content=");
		if (psz)
		{
			psz += lstrlen ("content=");
			if (*psz == '"')
			{
				psz++;
				while (*psz && *psz != '"')
				{
					if (is_valid_char (*psz))
						strTitle += *psz++;
					else
						psz++;				
				}
			}
		}
	}

	
	
	
	psz = const_cast<LPSTR>(strstr (pszHtml, "swfArgs ="));
	if (psz == NULL)
		return FALSE;
	psz = strchr (psz, '{');
	if (psz == NULL)
		return FALSE;
	psz++;

	fsString strBase = "http://youtube.com/"; 
	fsString strParams;
	
	while (*psz != '}')
	{
		while (*psz == ' ' || *psz == ',')
			psz++;

		fsString str;
	
		while (*psz && *psz != ':')
		{
			if (*psz == ' ')
			{
				str = "";
				break;
			}
			str += *psz++;
		}

		if (str.IsEmpty ())
			break;

		if (*psz == ':')
			psz++;
		while (*psz == ' ')
			psz++;

		if (str.Length () > 2 && str [0] == '"' && str [str.Length () - 1] == '"')
		{
			lstrcpy (str, str.pszString+1);
			str [str.Length () - 1] = 0;
		}

		if (lstrcmpi (str, "BASE_YT_URL") == 0)
		{
			strBase = ExtractValue (psz);
		}
		else
		{
			if (strParams.IsEmpty () == FALSE)
				strParams += '&';

			strParams += str; strParams += "="; strParams += ExtractValue (psz);
		}
	}

	strUrl = strBase;
	strUrl += "get_video?";
	strUrl += strParams;

	

	fsDecodeHtmlText (strTitle);

	m_strVideoTitle = strTitle;
	m_strVideoUrl   = strUrl;
	m_strVideoType  = "flv";
	m_bDirectLink   = TRUE;

	return TRUE;
}

LPCSTR vmsVideoSiteHtmlCodeParser::get_VideoTitle()
{
	return m_strVideoTitle;
}

LPCSTR vmsVideoSiteHtmlCodeParser::get_VideoUrl()
{
	return m_strVideoUrl;
}

LPCSTR vmsVideoSiteHtmlCodeParser::get_VideoType()
{
	return m_strVideoType;
}

BOOL vmsVideoSiteHtmlCodeParser::IsSiteSupported(LPCSTR pszHost)
{
	return GetSupportedSiteIndex (pszHost) != -1;
}

BOOL vmsVideoSiteHtmlCodeParser::Parse_GoogleVideo(LPCSTR pszHtml)
{
	LPCSTR psz = strstr (pszHtml, "/googleplayer.swf?");
	if (psz == NULL)
		return FALSE;
	psz = strstr (psz, "videoUrl");
	if (psz == NULL)
		return FALSE;
	psz = strstr (psz, "http");
	if (psz == NULL)
		return FALSE;

	fsString strUrl;
	while (*psz && *psz != '"')
		strUrl += *psz++;
	if (strUrl [strUrl.GetLength () - 1] == '\\')
		strUrl [strUrl.GetLength () - 1] = 0;
	fsDecodeHtmlUrl (strUrl);

	fsString strTitle;
	psz = strstr (pszHtml, "pvprogtitle");
	if (psz)
	{
		while (*psz && *psz != '>')
			psz++;
		if (*psz)
		{
			psz++;
			while (*psz == ' ')
				psz++;
			while (*psz && *psz != '<')
			{
				if (is_valid_char (*psz))
					strTitle += *psz++;
				else 
					psz++;
			}
			while (strTitle.GetLength () && strTitle [strTitle.GetLength () - 1] == ' ')
				strTitle [strTitle.GetLength () - 1] = 0;
			fsDecodeHtmlText (strTitle);
		}
	}

	m_strVideoTitle = strTitle;
	m_strVideoUrl   = strUrl;
	m_strVideoType  = "flv";
	m_bDirectLink   = TRUE;

	return TRUE;
}

BOOL vmsVideoSiteHtmlCodeParser::Parse_Youtube_RootPage(LPCSTR pszHtml)
{
	fsString strUrl; 

	LPCSTR psz = strstr (pszHtml, "/admp.swf");
	if (psz == NULL)
		return FALSE;

	while (*psz && *psz != '=')
		psz++;
	if (*psz == 0)
		return FALSE;
	psz++;

	fsString strId;

	while (*psz && *psz != '&')
		strId += *psz++;

	strUrl = "http://www.youtube.com/watch?v=";
	strUrl += strId;

	m_strVideoTitle = "";
	m_strVideoUrl   = strUrl;
	m_strVideoType  = "";
	m_bDirectLink = FALSE;

	return TRUE;
}

BOOL vmsVideoSiteHtmlCodeParser::get_IsVideoUrlDirectLink()
{
	return m_bDirectLink;
}

BOOL vmsVideoSiteHtmlCodeParser::Parse_LiveDigital(LPCSTR pszHtml)
{
	LPCSTR psz = strstr (pszHtml, "flashvars");
	if (psz == NULL)
		psz = strstr (pszHtml, "flashVars");
	
	fsString strC, strH;

	if (psz)
	{
		LPCSTR pszC = strstr (psz, "c="), 
			pszH = strstr (psz, "h=");

		if (pszC == NULL || pszH == NULL)
			return FALSE;

		pszC += 2;
		pszH += 2;

		while (*pszC && *pszC != '&' && *pszC != '"')
			strC += *pszC++;

		while (*pszH && *pszH != '&' && *pszH != '"')
			strH += *pszH++;
	}
	else
	{
		
		psz = strstr (pszHtml, "content_id/");
		if (psz)
		{
			psz += lstrlen ("content_id/");
			while (isdigit (*psz))
				strC += *psz++;
		}

		if (strC.IsEmpty ())
		{
			psz = strstr (pszHtml, "/content/");
			if (psz)
			{
				psz += lstrlen ("/content/");
				while (isdigit (*psz))
					strC += *psz++;
				if (strC.IsEmpty ())
					return FALSE;
			}
		}

		strH = "livedigital.com";
	}

	fsString strUrl = "http://";
	strUrl += strH;
	strUrl += "/content/flash_load_content/";
	strUrl += strC;

	m_strVideoTitle = "";
	m_strVideoUrl   = strUrl;
	m_strVideoType  = "";
	m_bDirectLink = FALSE;

	return TRUE;
}

BOOL vmsVideoSiteHtmlCodeParser::Parse_Further(LPCSTR pszSite, LPCSTR pszHtml)
{
	switch (GetSupportedSiteIndex (pszSite))
	{
	case 2:
		return Parse_Further_LiveDigital (pszHtml);

	case 3:
		return Parse_Further_MySpace (pszHtml);

	default:
		return Parse (pszSite, pszHtml);
	}
}

BOOL vmsVideoSiteHtmlCodeParser::Parse_Further_LiveDigital(LPCSTR pszTxt)
{
	LPCSTR psz = strstr (pszTxt, "content_url=");
	if (psz == NULL)
		return FALSE;

	fsString strUrl;
	psz += lstrlen ("content_url=");
	while (*psz && *psz != '&')
		strUrl += *psz++;

	fsDecodeHtmlUrl (strUrl);

	fsString strTitle;

	psz = strstr (pszTxt, "title=");
	if (psz)
	{
		psz += lstrlen ("title=");
		while (*psz && *psz != '&')
		{
			if (is_valid_char (*psz))
				strTitle += *psz++;
			else
				psz++;
		}
		fsDecodeHtmlText (strTitle);
	}

	m_strVideoTitle = strTitle;
	m_strVideoUrl   = strUrl;
	m_strVideoType  = (LPCSTR)strUrl + strUrl.GetLength () - 3;
	m_bDirectLink   = TRUE;

	return TRUE;
}

BOOL vmsVideoSiteHtmlCodeParser::Parse_MySpace(LPCSTR pszHtml)
{
	CString str; 

	LPCSTR psz = strstr (pszHtml, "flashvars=");
	if (psz == NULL)
		psz = strstr (pszHtml, "flashVars=");
	if (psz != NULL)
	{
		psz += 10;

		if (*psz == '"')
			psz++;
		else if (strnicmp (psz, "&quot;", 6) == 0)
			psz += 6;
		else
			return FALSE;

		while (*psz && *psz != '"' && strnicmp (psz, "&quot;", 6))
			str += *psz++;
		if (str.IsEmpty ())
			return FALSE;
		str.Replace ("m=", "mediaID=");
	}
	else
	{
		psz = strstr (pszHtml, "videoID =");
		if (!psz)
		{
			psz = strstr (pszHtml, "videoid=");
			if (!psz)
				return FALSE;
			else 
				psz += 8;
		}
		else
		{
			psz += 9;
		}
		while (*psz == ' ')
			psz++;
		str = "videoID=";
		while (isdigit (*psz))
			str += *psz++;
	}

	fsString strUrl;
	strUrl = "http://"; strUrl += "mediaservices.myspace.com/services/rss.ashx?";
	strUrl += str;

	m_strVideoTitle = "";
	m_strVideoUrl   = strUrl;
	m_strVideoType  = "";
	m_bDirectLink = FALSE;

	return TRUE;
}

BOOL vmsVideoSiteHtmlCodeParser::Parse_Further_MySpace(LPCSTR pszHtml)
{
	USES_CONVERSION;
	IXMLDOMDocumentPtr spXML;
	IXMLDOMNodePtr spNode, spNode2;

	while (*pszHtml && *pszHtml != '<')
		pszHtml++;

	spXML.CreateInstance (__uuidof (DOMDocument));

	if (spXML == NULL)
		return FALSE;

	spXML->put_async (FALSE);

	VARIANT_BOOL bRes;
	spXML->loadXML (A2W (pszHtml), &bRes);
	if (bRes == FALSE)
		return FALSE;

	spXML->selectSingleNode (L"rss", &spNode);
	if (spNode == NULL)
		return FALSE;

	spNode->selectSingleNode (L"channel", &spNode2);
	if (spNode2 == NULL)
		return FALSE;

	spNode = NULL;
	spNode2->selectSingleNode (L"item", &spNode);
	if (spNode == NULL)
		return FALSE;

	spNode2 = NULL;
	spNode->selectSingleNode (L"title", &spNode2);
	if (spNode2 == NULL)
		return FALSE;

	CComBSTR bstrTitle;
	spNode2->get_text (&bstrTitle);

	spNode2 = NULL;
	spNode->selectSingleNode (L"media:content", &spNode2);
	if (spNode2 == NULL)
		return FALSE;
	IXMLDOMNamedNodeMapPtr spAttrs;
	spNode2->get_attributes (&spAttrs);
	if (spAttrs == NULL)
		return FALSE;
	IXMLDOMNodePtr spUrlValue;
	spAttrs->getNamedItem (L"url", &spUrlValue);
	if (spUrlValue == NULL)
		return FALSE;
	COleVariant vtUrl;
	spUrlValue->get_nodeValue (&vtUrl);
	ASSERT (vtUrl.vt == VT_BSTR);
	if (vtUrl.vt != VT_BSTR)
		return FALSE;

	m_strVideoTitle = W2A (bstrTitle);
	fsDecodeHtmlText (m_strVideoTitle);
	m_strVideoUrl   = W2A (vtUrl.bstrVal);
	m_strVideoType  = (LPCSTR)m_strVideoUrl + m_strVideoUrl.GetLength () - 3;
	m_bDirectLink	= TRUE;

	return TRUE;
}

BOOL vmsVideoSiteHtmlCodeParser::Parse_Sharkle(LPCSTR pszHtml)
{
	LPCSTR psz = strstr (pszHtml, "splayer.swf?");
	if (psz == NULL)
		return FALSE;

	psz = strstr (psz, "rnd=");
	if (psz == NULL)
		return FALSE;

	fsString strRnd;

	psz += 4;
	while (*psz && *psz != '&')
		strRnd += *psz++;
	if (strRnd.IsEmpty ())
		return FALSE;

	fsString strUrl;
	strUrl = "http://sharkle.com/inc/misc/about.php?rnd=";
	strUrl += strRnd;
	strUrl += "&ssd=ZeleninGalaburda";

	fsString strTitle;

	psz = strstr (pszHtml, "blog_header");
	if (psz != NULL)
	{
		while (*psz && *psz != '>')
			psz++;
		if (*psz != 0)
		{
			psz++;
			while (*psz == ' ' || is_valid_char (*psz) == FALSE)
				psz++;
			while (*psz && *psz != '<')
			{
				if (is_valid_char (*psz))
					strTitle += *psz++;
				else
					psz++;
			}
			while (strTitle.GetLength () && strTitle [strTitle.GetLength () - 1] == ' ')
				strTitle [strTitle.GetLength () - 1] = 0;
		}
	}

	fsDecodeHtmlText (strTitle);

	m_strVideoTitle = strTitle;
	m_strVideoUrl   = strUrl;
	m_strVideoType  = "flv";
	m_bDirectLink	= TRUE;

	return TRUE;
}

BOOL vmsVideoSiteHtmlCodeParser::Parse_Blennus(LPCSTR pszHtml)
{
	LPCSTR psz = strstr (pszHtml, "embed");
	if (psz == NULL)
		psz = strstr (pszHtml, "EMBED");
	if (psz == NULL)
		return FALSE;

	psz = strstr (psz, "src=");
	if (psz == NULL)
		return FALSE;
	psz += 4;
	if (*psz++ != '"')
		return FALSE;
	fsString strUrl;
	while (*psz && *psz != '"')
		strUrl += *psz++;
	if (strUrl.IsEmpty ())
		return FALSE;

	fsString strTitle;
	psz = strstr (pszHtml, "contentheading");
	if (psz != NULL)
	{
		while (*psz && *psz != '>')
			psz++;
		if (*psz != 0)
		{
			psz++;
			while (*psz == ' ' || is_valid_char (*psz) == FALSE)
				psz++;
			while (*psz && *psz != '<')
			{
				if (is_valid_char (*psz))
					strTitle += *psz++;
				else
					psz++;
			}
			fsDecodeHtmlText (strTitle);
			while (strTitle.GetLength () && strTitle [strTitle.GetLength () - 1] == ' ')
				strTitle [strTitle.GetLength () - 1] = 0;
		}
	}

	fsDecodeHtmlText (strTitle);

	m_strVideoTitle = strTitle;
	m_strVideoUrl   = strUrl;
	m_strVideoType  = "wmv";
	m_bDirectLink	= TRUE;

	return TRUE;
}

BOOL vmsVideoSiteHtmlCodeParser::Parse_DailyMotion(LPCSTR pszHtml)
{
	LPCSTR psz = strstr (pszHtml, "flashvars=");
	if (psz == NULL)
		psz = strstr (pszHtml, "flashVars=");
	if (psz == NULL)
		return FALSE;
	
_lSearchUrl:
	psz = strstr (psz, "url=");
	if (psz == NULL)
		return FALSE;
	psz += 4;
	if (strncmp (psz, "rev=", 4) == 0)
		goto _lSearchUrl;

	fsString strUrl;
	while (*psz && *psz != '&')
		strUrl += *psz++;
	fsDecodeHtmlUrl (strUrl);

	fsString strTitle;
	psz = strstr (pszHtml, "<h1");
	if (psz == NULL)
		psz = strstr (pszHtml, "<H1");
	if (psz != NULL)
	{
		while (*psz && *psz != '>')
			psz++;
		if (*psz != 0)
		{
			psz++;
			while (*psz == ' ' || is_valid_char (*psz) == FALSE)
				psz++;
			while (*psz && *psz != '<')
			{
				if (is_valid_char (*psz))
					strTitle += *psz++;
				else
					psz++;
			}
			fsDecodeHtmlText (strTitle);
			while (strTitle.GetLength () && strTitle [strTitle.GetLength () - 1] == ' ')
				strTitle [strTitle.GetLength () - 1] = 0;
		}
	}

	m_strVideoTitle = strTitle;
	m_strVideoUrl   = strUrl;
	m_strVideoType  = "flv";
	m_bDirectLink	= TRUE;

	return TRUE;
}

BOOL vmsVideoSiteHtmlCodeParser::Parse_Grouper(LPCSTR pszHtml)
{
	LPCSTR psz = strstr (pszHtml, "flvURL=");
	if (psz == NULL)
		return FALSE;
	psz += 7;

	fsString strUrl;
	while (*psz && *psz != '&')
		strUrl += *psz++;

	fsString strTitle;
	psz = strstr (pszHtml, "<h1");
	if (psz == NULL)
		psz = strstr (pszHtml, "<H1");
	if (psz != NULL)
	{
		while (*psz && *psz != '>')
			psz++;
		if (*psz != 0)
		{
			psz++;
			while (*psz == ' ' || is_valid_char (*psz) == FALSE)
				psz++;
			while (*psz && *psz != '<')
			{
				if (is_valid_char (*psz))
					strTitle += *psz++;
				else
					psz++;
			}
			fsDecodeHtmlText (strTitle);
			while (strTitle.GetLength () && strTitle [strTitle.GetLength () - 1] == ' ')
				strTitle [strTitle.GetLength () - 1] = 0;
		}
	}

	m_strVideoTitle = strTitle;
	m_strVideoUrl   = strUrl;
	m_strVideoType  = "flv";
	m_bDirectLink	= TRUE;	

	return TRUE;
}

fsString vmsVideoSiteHtmlCodeParser::ExtractValue(LPSTR &psz)
{
	char c;
	while (*psz == ' ')
		psz++;
	if (*psz == '"' || *psz == '\'')
		c = *psz++;
	else 
		c = ',';
	fsString strRes;
	while (*psz && *psz != c)
	{
		if (*psz == '}' && c == ',')
			break;
		strRes += *psz++;
	}
	if (*psz != '}')
		psz++;
	return strRes;
}
