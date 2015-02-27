/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\xpcexception.idl
 */

#ifndef __gen_xpcexception_h__
#define __gen_xpcexception_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIException_h__
#include "nsIException.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIXPCException */
#define NS_IXPCEXCEPTION_IID_STR "dd250248-2586-4ec1-a68f-8d14ef452517"

#define NS_IXPCEXCEPTION_IID \
  {0xdd250248, 0x2586, 0x4ec1, \
    { 0xa6, 0x8f, 0x8d, 0x14, 0xef, 0x45, 0x25, 0x17 }}

class NS_NO_VTABLE nsIXPCException : public nsIException {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXPCEXCEPTION_IID)

  /* void initialize (in AUTF8String aMessage, in nsresult aResult, in AUTF8String aName, in nsIStackFrame aLocation, in nsISupports aData, in nsIException aInner); */
  NS_IMETHOD Initialize(const nsACString & aMessage, nsresult aResult, const nsACString & aName, nsIStackFrame *aLocation, nsISupports *aData, nsIException *aInner) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXPCException, NS_IXPCEXCEPTION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXPCEXCEPTION \
  NS_IMETHOD Initialize(const nsACString & aMessage, nsresult aResult, const nsACString & aName, nsIStackFrame *aLocation, nsISupports *aData, nsIException *aInner); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXPCEXCEPTION(_to) \
  NS_IMETHOD Initialize(const nsACString & aMessage, nsresult aResult, const nsACString & aName, nsIStackFrame *aLocation, nsISupports *aData, nsIException *aInner) { return _to Initialize(aMessage, aResult, aName, aLocation, aData, aInner); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXPCEXCEPTION(_to) \
  NS_IMETHOD Initialize(const nsACString & aMessage, nsresult aResult, const nsACString & aName, nsIStackFrame *aLocation, nsISupports *aData, nsIException *aInner) { return !_to ? NS_ERROR_NULL_POINTER : _to->Initialize(aMessage, aResult, aName, aLocation, aData, aInner); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXPCException : public nsIXPCException
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXPCEXCEPTION

  nsXPCException();

private:
  ~nsXPCException();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsXPCException, nsIXPCException)

nsXPCException::nsXPCException()
{
  /* member initializers and constructor code */
}

nsXPCException::~nsXPCException()
{
  /* destructor code */
}

/* void initialize (in AUTF8String aMessage, in nsresult aResult, in AUTF8String aName, in nsIStackFrame aLocation, in nsISupports aData, in nsIException aInner); */
NS_IMETHODIMP nsXPCException::Initialize(const nsACString & aMessage, nsresult aResult, const nsACString & aName, nsIStackFrame *aLocation, nsISupports *aData, nsIException *aInner)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

/********************************************************/
// {5632BF70-51EC-11d3-9896-006008962422}
#define NS_XPCEXCEPTION_CID  \
{ 0x5632bf70, 0x51ec, 0x11d3, \
    { 0x98, 0x96, 0x0, 0x60, 0x8, 0x96, 0x24, 0x22 } }

#endif /* __gen_xpcexception_h__ */
