/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef __WG_PLUGINS_H_
#define __WG_PLUGINS_H_

#define WGP_MENU_CMDFIRST 		50000
#define WGP_MENU_CMDLAST		50900

#define WGP_MENU_VIEWSMPLITEM_CMDSTART	(WGP_MENU_CMDLAST-100)

#define WM_WGP_READYTOSHUTDOWN	(WM_APP + 0)
#define WM_WGP_SHUTDOWN			(WM_APP + 1)
#define WM_WGP_UPDATE_MENUMAIN	(WM_APP + 2)
#define WM_WGP_UPDATE_MENUVIEW	(WM_APP + 3)
#define WM_WGP_UPDATE_CMDITEM	(WM_APP + 4)
#define WM_WGP_INSERT			(WM_APP + 5)

#define WGP_CMDITEMSTATE_ENABLED	0
#define WGP_CMDITEMSTATE_DISABLED	1
#define WGP_CMDITEMSTATE_CHECKED	2

struct wgMenuViewItem
{
	LPCSTR pszName;
	BOOL* pbView;
	wgMenuViewItem (LPCSTR psz, BOOL *pb) : pszName (psz), pbView (pb) {}
	wgMenuViewItem () {}
};

struct wgTButtonInfo
{
	int iIdCommand;
	BYTE bStyle;
	LPCSTR pszToolTip;
	LPCSTR pszName;
    wgTButtonInfo (int cmd, BYTE style, LPCSTR pszTip, LPCSTR pszBtnName = NULL) : iIdCommand (cmd), bStyle (style), 
		pszToolTip (pszTip), pszName (pszBtnName) {};
	wgTButtonInfo () {};
};

struct wgMenuItemImage
{
	int iIdItem;
	int iImage, iCheckImage;

	wgMenuItemImage (int i = 0, int im = -1, int icm = -1) : iIdItem (i), iImage (im), iCheckImage (icm) {};
};

enum wgLanguage
{
	WGL_UNKNOWN
};

#endif