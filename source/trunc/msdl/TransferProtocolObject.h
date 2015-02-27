#ifndef __TPDOBJECT_H_
#define __TPDOBJECT_H_

class TransferProtocolObject
{
public:
	virtual void AddRef () = NULL;
	virtual void Release () = NULL;
};

#endif //__TPDOBJECT_H_