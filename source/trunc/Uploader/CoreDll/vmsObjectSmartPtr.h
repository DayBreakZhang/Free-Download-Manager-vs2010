/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSOBJECTSMARTPTR_H__1ECD7954_DB25_4982_A113_4574EA1C10B7__INCLUDED_)
#define AFX_VMSOBJECTSMARTPTR_H__1ECD7954_DB25_4982_A113_4574EA1C10B7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "vmsObject.h"

template <class T = vmsObject>
class vmsObjectSmartPtr  
{
public:
	vmsObjectSmartPtr (const vmsObjectSmartPtr &ptr)
	{
		m_pObj = NULL;
		*this = ptr;
	}

	vmsObjectSmartPtr(T *pObj = NULL)
	{
		m_pObj = pObj;
		if (m_pObj)
			m_pObj->AddRef ();
	}
	
	vmsObjectSmartPtr& operator =(const vmsObjectSmartPtr &ptr)
	{
		if (m_pObj)
			m_pObj->Release ();
		m_pObj = ptr.m_pObj;
		if (m_pObj)
			m_pObj->AddRef ();
		return *this;
	}
	
	virtual ~vmsObjectSmartPtr() 
	{
		if (m_pObj)
			m_pObj->Release ();
	}

	T* operator -> () const {return m_pObj;}
	operator T* () const {return m_pObj;}

	void CreateInstance ()
	{
		if (m_pObj)
			m_pObj->Release ();
		m_pObj = new T;
		m_pObj->AddRef ();
	}

protected:
	T *m_pObj;
};

#endif 
