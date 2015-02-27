/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsBrowserFlvHistory.h"

vmsBrowserFlvHistory::vmsBrowserFlvHistory()
{

}

vmsBrowserFlvHistory::~vmsBrowserFlvHistory()
{

}

int vmsBrowserFlvHistory::getItemCount() const
{
	return m_vItems.size ();
}

const vmsBrowserFlvHistory::Item* vmsBrowserFlvHistory::getItem(int nIndex) const
{
	assert (nIndex >= 0 && nIndex < m_vItems.size ());
	return &m_vItems [nIndex];
}
