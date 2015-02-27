/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/js/src/xpconnect/idl/xpcexception.idl
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
#include "jspubtd.h"

/* starting interface:    nsIXPCException */
#define NS_IXPCEXCEPTION_IID_STR "cac29630-7bf2-4e22-811b-46855a7d5af0"

#define NS_IXPCEXCEPTION_IID \
  {0xcac29630, 0x7bf2, 0x4e22, \
    { 0x81, 0x1b, 0x46, 0x85, 0x5a, 0x7d, 0x5a, 0xf0 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIXPCException : public nsIException {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXPCEXCEPTION_IID)

  /* void initialize (in string aMessage, in nsresult aResult, in string aName, in nsIStackFrame aLocation, in nsISupports aData, in nsIException aInner); */
  NS_SCRIPTABLE NS_IMETHOD Initialize(const char *aMessage, nsresult aResult, const char *aName, nsIStackFrame *aLocation, nsISupports *aData, nsIException *aInner) = 0;

  /* [noscript] xpcexJSVal stealJSVal (); */
  NS_IMETHOD StealJSVal(jsval *_retval NS_OUTPARAM) = 0;

  /* [noscript] void stowJSVal (in xpcexJSContextPtr cx, in xpcexJSVal val); */
  NS_IMETHOD StowJSVal(JSContext *cx, jsval val) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXPCException, NS_IXPCEXCEPTION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXPCEXCEPTION \
  NS_SCRIPTABLE NS_IMETHOD Initialize(const char *aMessage, nsresult aResult, const char *aName, nsIStackFrame *aLocation, nsISupports *aData, nsIException *aInner); \
  NS_IMETHOD StealJSVal(jsval *_retval NS_OUTPARAM); \
  NS_IMETHOD StowJSVal(JSContext *cx, jsval val); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXPCEXCEPTION(_to) \
  NS_SCRIPTABLE NS_IMETHOD Initialize(const char *aMessage, nsresult aResult, const char *aName, nsIStackFrame *aLocation, nsISupports *aData, nsIException *aInner) { return _to Initialize(aMessage, aResult, aName, aLocation, aData, aInner); } \
  NS_IMETHOD StealJSVal(jsval *_retval NS_OUTPARAM) { return _to StealJSVal(_retval); } \
  NS_IMETHOD StowJSVal(JSContext *cx, jsval val) { return _to StowJSVal(cx, val); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXPCEXCEPTION(_to) \
  NS_SCRIPTABLE NS_IMETHOD Initialize(const char *aMessage, nsresult aResult, const char *aName, nsIStackFrame *aLocation, nsISupports *aData, nsIException *aInner) { return !_to ? NS_ERROR_NULL_POINTER : _to->Initialize(aMessage, aResult, aName, aLocation, aData, aInner); } \
  NS_IMETHOD StealJSVal(jsval *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->StealJSVal(_retval); } \
  NS_IMETHOD StowJSVal(JSContext *cx, jsval val) { return !_to ? NS_ERROR_NULL_POINTER : _to->StowJSVal(cx, val); } 

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

/* void initialize (in string aMessage, in nsresult aResult, in string aName, in nsIStackFrame aLocation, in nsISupports aData, in nsIException aInner); */
NS_IMETHODIMP nsXPCException::Initialize(const char *aMessage, nsresult aResult, const char *aName, nsIStackFrame *aLocation, nsISupports *aData, nsIException *aInner)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] xpcexJSVal stealJSVal (); */
NS_IMETHODIMP nsXPCException::StealJSVal(jsval *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void stowJSVal (in xpcexJSContextPtr cx, in xpcexJSVal val); */
NS_IMETHODIMP nsXPCException::StowJSVal(JSContext *cx, jsval val)
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
