/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSLOGHELPER_H__47A0D511_2D05_4482_9402_8371C487CCCB__INCLUDED_)
#define AFX_VMSLOGHELPER_H__47A0D511_2D05_4482_9402_8371C487CCCB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "vmsWinSockHttpTrafficCollector.h"
#include "vmsWinSockHttpDlgTree.h"

#ifdef SCL_ENABLE
#define LOGHTTPDLGLIST(name, list) vmsLogHelper::LogHttpDlgList (name, list)
#define LOGHTTPDLGTREELIST(name, list) vmsLogHelper::LogHttpDlgTreeList (name, list)
#define LOGHTTPDLGTREE(name, item, depth) vmsLogHelper::LogHttpDlgTree (name, item, depth)
#define LOGSTRINGLIST(name, list) vmsLogHelper::LogStringList (name, list)
#else
#define LOGHTTPDLGLIST(name, list) 
#define LOGHTTPDLGTREELIST(name, list)
#define LOGHTTPDLGTREE(name, item, depth)
#define LOGSTRINGLIST(name, list)
#endif

class vmsLogHelper  
{
public:
	static void LogHttpDlgTree (LPCSTR pszName, HTTPDLGTREEITEM item, int nDepth);
	static void LogHttpDlgTreeList (LPCSTR pszListName, const vector <vmsWinSockHttpDlgTree::TreeItemPtr> &vItems);
	static void LogHttpDlgList (LPCSTR pszListName, const HTTPDLGLIST &vDlgs);
	static void LogStringList (LPCSTR pszListName, const vector <string> &v);
	vmsLogHelper();
	virtual ~vmsLogHelper();

protected:
	static void LogHttpTree (HTTPDLGTREEITEM item, int nDepth, LPCSTR pszSpaces);
};

#endif 
