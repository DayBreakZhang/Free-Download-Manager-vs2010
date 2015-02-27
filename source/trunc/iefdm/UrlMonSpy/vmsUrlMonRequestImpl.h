/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#pragma once
#include "vmsurlmonrequest.h"
#include "vmsUrlMonRequestCollector.h"
class vmsUrlMonRequestImpl : public vmsUrlMonRequest
{
public:
	virtual LPCWSTR getUrl () const
	{
		assert (m_spReq != NULL);
		return m_spReq ? m_spReq->wstrUrl.c_str () : NULL;
	}
	virtual LPCWSTR getRedirectedUrl () const
	{
		assert (m_spReq != NULL);
		return m_spReq ? m_spReq->wstrRedirectedUrl.c_str () : NULL;
	}
	virtual LPCWSTR getSrcTabUrl () const
	{
		assert (m_spReq != NULL);
		return m_spReq ? m_spReq->wstrSrcTabUrl.c_str () : NULL;
	}
	virtual LPCSTR getRequestHeaders () const
	{
		assert (m_spReq != NULL);
		return m_spReq ? m_spReq->strRequestHeaders.c_str () : NULL;
	}
	virtual LPCSTR getResponseHeaders () const
	{
		assert (m_spReq != NULL);
		return m_spReq ? m_spReq->strResponseHeaders.c_str () : NULL;
	}
	virtual bool isCompleted () const
	{
		assert (m_spReq != NULL);
		return m_spReq ? m_spReq->dwTicksCompleted != 0 : false;
	}
	virtual LPBYTE getPostData () const
	{
		assert (m_spReq != NULL);
		return m_spReq ? &m_spReq->vbPostData [0] : NULL;
	}
	virtual DWORD getPostDataSize () const
	{
		assert (m_spReq != NULL);
		return m_spReq ? m_spReq->vbPostData.size () : 0;
	}
	virtual bool isSrcTabCalculated () const
	{
		assert (m_spReq != NULL);
		return m_spReq ? m_spReq->dwthridContinue != 0 : false;
	}
	vmsUrlMonRequestImpl(void);
	virtual ~vmsUrlMonRequestImpl(void);
	vmsUrlMonRequestCollector::RequestPtr m_spReq;
};

typedef vmsObjectSmartPtr <vmsUrlMonRequestImpl> vmsUrlMonRequestImplPtr;
