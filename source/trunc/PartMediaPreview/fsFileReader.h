/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_FSFILEREADER_H__988547EF_AC69_4F72_979F_52571675E5B2__INCLUDED_)
#define AFX_FSFILEREADER_H__988547EF_AC69_4F72_979F_52571675E5B2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include <dshow.h>
#include <DShow/wxdebug.h>
#include <DShow/combase.h>
#include <DShow/reftime.h>
#include <DShow/wxutil.h>
#include <DShow/mtype.h>
#include <DShow/wxlist.h>
#include <DShow/amfilter.h>
#include <DShow/asyncio.h>
#include <DShow/asyncrdr.h>
#include "fsFileStream.h"

class fsFileReader : public CAsyncReader 
{
public:
	void Set_MediaType (const AM_MEDIA_TYPE* mt);
	fsFileReader(fsFileStream* pStream, HRESULT* phr);
	virtual ~fsFileReader();

};

#endif 
