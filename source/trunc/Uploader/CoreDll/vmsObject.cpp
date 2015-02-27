/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsObject.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

vmsObject::vmsObject()
{
	m_cRefs = 0;
}

vmsObject::~vmsObject()
{

}

void vmsObject::AddRef()
{
	InterlockedIncrement (&m_cRefs);
}

void vmsObject::Release()
{
	if (0 == InterlockedDecrement (&m_cRefs))
		delete this;
}
