/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSVIDEOSITEHTMLCODEPARSER_H__36077242_C9A7_4188_8F8D_CFE99AF921C2__INCLUDED_)
#define AFX_VMSVIDEOSITEHTMLCODEPARSER_H__36077242_C9A7_4188_8F8D_CFE99AF921C2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class vmsVideoSiteHtmlCodeParser  
{
public:
	BOOL Parse_Further (LPCSTR pszSite, LPCSTR pszHtml);
	BOOL get_IsVideoUrlDirectLink();
	BOOL Parse_GoogleVideo (LPCSTR pszHtml);
	static BOOL IsSiteSupported (LPCSTR pszHost);
	LPCSTR get_VideoType();
	LPCSTR get_VideoUrl();
	LPCSTR get_VideoTitle();
	BOOL Parse (LPCSTR pszSite, LPCSTR pszHtml);

	static int GetSupportedSiteIndex (LPCSTR pszSite)
	{
		
		#define register_site_with_subdomains(s,n)\
			if (stricmp (pszSite, ##s) == 0)\
				return n;\
			if (lstrlen (pszSite) > lstrlen ("."##s) && \
					strnicmp (pszSite + lstrlen (pszSite) - lstrlen ("."##s), "."##s, lstrlen ("."##s)) == 0)\
				return n;
		

		if (strnicmp (pszSite, "www.", 4) == 0)
			pszSite += 4;	

		register_site_with_subdomains ("youtube.com", 0);
		

		if (strnicmp (pszSite, "video.google.", 13) == 0)
			return 1;

		register_site_with_subdomains ("livedigital.com", 2);

		register_site_with_subdomains ("myspace.com", 3);

		if (stricmp (pszSite, "sharkle.com") == 0)
			return 4;

		if (stricmp (pszSite, "blennus.com") == 0)
			return 5;

		if (stricmp (pszSite, "dailymotion.com") == 0)
			return 6;

		if (stricmp (pszSite, "grouper.com") == 0)
			return 7;

		return -1;
	}

	vmsVideoSiteHtmlCodeParser();
	virtual ~vmsVideoSiteHtmlCodeParser();

protected:
	static fsString ExtractValue (LPSTR &psz);
	BOOL Parse_Grouper (LPCSTR pszHtml);
	BOOL Parse_DailyMotion (LPCSTR pszHtml);
	BOOL Parse_Blennus (LPCSTR pszHtml);
	BOOL Parse_Sharkle (LPCSTR pszHtml);
	BOOL Parse_Further_MySpace (LPCSTR pszHtml);
	BOOL Parse_MySpace (LPCSTR pszHtml);
	BOOL Parse_Further_LiveDigital (LPCSTR pszTxt);
	BOOL Parse_LiveDigital (LPCSTR pszHtml);
	BOOL m_bDirectLink;
	BOOL Parse_Youtube_RootPage (LPCSTR pszHtml);
	fsString m_strVideoTitle, m_strVideoUrl, m_strVideoType;
	BOOL Parse_Youtube (LPCSTR pszHtml);
};

#endif 
