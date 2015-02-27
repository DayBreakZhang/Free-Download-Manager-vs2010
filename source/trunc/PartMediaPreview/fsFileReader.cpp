/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "fsFileReader.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

fsFileReader::fsFileReader(fsFileStream* pStream, HRESULT* phr) :
	CAsyncReader (NAME("File Reader"), NULL, pStream, phr)
{
	if (pStream->Get_MediaType ())
		m_mt = *pStream->Get_MediaType ();
}

fsFileReader::~fsFileReader()
{

}

void fsFileReader::Set_MediaType(const AM_MEDIA_TYPE *mt)
{
	m_mt = *mt;
}
