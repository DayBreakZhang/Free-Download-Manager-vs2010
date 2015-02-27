/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsComSupport.h"
#include <objbase.h>

vmsComSupport::vmsComSupport()
{
	m_bNeedUninitialize = SUCCEEDED (CoInitialize (NULL));
}

vmsComSupport::~vmsComSupport()
{
	if (m_bNeedUninitialize)
		CoUninitialize ();
}
