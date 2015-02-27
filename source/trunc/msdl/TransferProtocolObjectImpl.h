#pragma once
#include "TransferProtocolobject.h"
#include <WTypes.h>

template <class baseInterface>
class TransferProtocolObjectImpl :
	public baseInterface
{
public:
	TransferProtocolObjectImpl(void) {m_cRefs = 0;};
	virtual ~TransferProtocolObjectImpl(void) {};
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

