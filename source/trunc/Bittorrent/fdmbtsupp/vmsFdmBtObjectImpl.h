/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#pragma once
#include "vmsfdmbtobject.h"

template <class baseInterface>
class vmsFdmBtObjectImpl :
	public baseInterface
{
public:
	vmsFdmBtObjectImpl(void) {m_cRefs = 0;};
	virtual ~vmsFdmBtObjectImpl(void) {};
public:
	virtual void AddRef(void) {
		InterlockedIncrement (&m_cRefs);
	};
	virtual void Release(void) {
		if (0 == InterlockedDecrement (&m_cRefs))
			delete this;
	};
protected:
	LONG m_cRefs;
};

