/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/netwerk/base/public/nsIIPCSerializable.idl
 */

#ifndef __gen_nsIIPCSerializable_h__
#define __gen_nsIIPCSerializable_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
namespace IPC {
class Message;
}

/* starting interface:    nsIIPCSerializable */
#define NS_IIPCSERIALIZABLE_IID_STR "1f605ac7-666b-471f-9864-1a21a95f11c4"

#define NS_IIPCSERIALIZABLE_IID \
  {0x1f605ac7, 0x666b, 0x471f, \
    { 0x98, 0x64, 0x1a, 0x21, 0xa9, 0x5f, 0x11, 0xc4 }}

class NS_NO_VTABLE nsIIPCSerializable : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IIPCSERIALIZABLE_IID)

  /* [notxpcom] boolean read (in ConstMessage msg, in Iterator iter); */
  NS_IMETHOD_(PRBool ) Read(const IPC::Message *msg, void* *iter) = 0;

  /* [notxpcom] void write (in Message msg); */
  NS_IMETHOD_(void) Write(IPC::Message *msg) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIIPCSerializable, NS_IIPCSERIALIZABLE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIIPCSERIALIZABLE \
  NS_IMETHOD_(PRBool ) Read(const IPC::Message *msg, void* *iter); \
  NS_IMETHOD_(void) Write(IPC::Message *msg); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIIPCSERIALIZABLE(_to) \
  NS_IMETHOD_(PRBool ) Read(const IPC::Message *msg, void* *iter) { return _to Read(msg, iter); } \
  NS_IMETHOD_(void) Write(IPC::Message *msg) { return _to Write(msg); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIIPCSERIALIZABLE(_to) \
  NS_IMETHOD_(PRBool ) Read(const IPC::Message *msg, void* *iter) { return !_to ? NS_ERROR_NULL_POINTER : _to->Read(msg, iter); } \
  NS_IMETHOD_(void) Write(IPC::Message *msg) { return !_to ? NS_ERROR_NULL_POINTER : _to->Write(msg); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsIPCSerializable : public nsIIPCSerializable
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIIPCSERIALIZABLE

  nsIPCSerializable();

private:
  ~nsIPCSerializable();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsIPCSerializable, nsIIPCSerializable)

nsIPCSerializable::nsIPCSerializable()
{
  /* member initializers and constructor code */
}

nsIPCSerializable::~nsIPCSerializable()
{
  /* destructor code */
}

/* [notxpcom] boolean read (in ConstMessage msg, in Iterator iter); */
NS_IMETHODIMP_(PRBool ) nsIPCSerializable::Read(const IPC::Message *msg, void* *iter)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [notxpcom] void write (in Message msg); */
NS_IMETHODIMP_(void) nsIPCSerializable::Write(IPC::Message *msg)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIIPCSerializable_h__ */
