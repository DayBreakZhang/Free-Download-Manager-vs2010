/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsLogHelper.h"

vmsLogHelper::vmsLogHelper()
{

}

vmsLogHelper::~vmsLogHelper()
{

}

void vmsLogHelper::LogHttpDlgList(LPCSTR pszListName, const HTTPDLGLIST &vDlgs)
{
	LOG ("%s:", pszListName);
	if (vDlgs.empty ())
	{
		LOGsnl ("|-(empty)");
		return;
	}
	for (size_t i = 0; i < vDlgs.size (); i++)
		LOG ("|-(%I64d bytes)-%s", (__int64)vDlgs [i]->nContentLength, vDlgs [i]->strRequestUrl.c_str ());
}

void vmsLogHelper::LogStringList(LPCSTR pszListName, const vector <string> &v)
{
	LOG ("%s:", pszListName);
	if (v.empty ())
	{
		LOGsnl ("|-(empty)");
		return;
	}
	for (size_t i = 0; i < v.size (); i++)
		LOG ("|-%s", v [i].c_str ());
}

void vmsLogHelper::LogHttpDlgTreeList(LPCSTR pszListName, const vector <vmsWinSockHttpDlgTree::TreeItemPtr> &vItems)
{
	LOG ("%s:", pszListName);
	if (vItems.empty ())
	{
		LOGsnl ("|-(empty)");
		return;
	}
	for (size_t i = 0; i < vItems.size (); i++)
		LOG ("|-(%I64d bytes)-%s", (__int64)vItems [i]->spDlg->nContentLength, vItems [i]->spDlg->strRequestUrl.c_str ());
}

void vmsLogHelper::LogHttpDlgTree (LPCSTR pszName, HTTPDLGTREEITEM item, int nDepth)
{
	LOG ("%s, depth %d:", pszName, nDepth);
	LogHttpTree (item, nDepth, "");
}

void vmsLogHelper::LogHttpTree(HTTPDLGTREEITEM item, int nDepth, LPCSTR pszSpaces)
{
	if (nDepth <= 0)
		return;
	LOG ("%s|-%s", pszSpaces, item->spDlg->strRequestUrl.c_str ());
	string strSpaces = pszSpaces; strSpaces += ' ';
	for (size_t i = 0; i < item->vChild.size (); i++)
		LogHttpTree (item->vChild [i], nDepth-1, strSpaces.c_str ());
}
