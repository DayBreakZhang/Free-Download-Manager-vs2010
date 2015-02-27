/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMWebGLRenderingContext.idl
 */

#ifndef __gen_nsIDOMWebGLRenderingContext_h__
#define __gen_nsIDOMWebGLRenderingContext_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMWebGLRenderingContext */
#define NS_IDOMWEBGLRENDERINGCONTEXT_IID_STR "f1a2fd3a-c6ac-4ee2-a700-5d285d5e3fff"

#define NS_IDOMWEBGLRENDERINGCONTEXT_IID \
  {0xf1a2fd3a, 0xc6ac, 0x4ee2, \
    { 0xa7, 0x00, 0x5d, 0x28, 0x5d, 0x5e, 0x3f, 0xff }}

class NS_NO_VTABLE nsIDOMWebGLRenderingContext : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMWEBGLRENDERINGCONTEXT_IID)

  /* [noscript] DOMString mozGetUnderlyingParamString (in unsigned long pname); */
  NS_IMETHOD MozGetUnderlyingParamString(uint32_t pname, nsAString & _retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMWebGLRenderingContext, NS_IDOMWEBGLRENDERINGCONTEXT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMWEBGLRENDERINGCONTEXT \
  NS_IMETHOD MozGetUnderlyingParamString(uint32_t pname, nsAString & _retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMWEBGLRENDERINGCONTEXT(_to) \
  NS_IMETHOD MozGetUnderlyingParamString(uint32_t pname, nsAString & _retval) { return _to MozGetUnderlyingParamString(pname, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMWEBGLRENDERINGCONTEXT(_to) \
  NS_IMETHOD MozGetUnderlyingParamString(uint32_t pname, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->MozGetUnderlyingParamString(pname, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMWebGLRenderingContext : public nsIDOMWebGLRenderingContext
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMWEBGLRENDERINGCONTEXT

  nsDOMWebGLRenderingContext();

private:
  ~nsDOMWebGLRenderingContext();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMWebGLRenderingContext, nsIDOMWebGLRenderingContext)

nsDOMWebGLRenderingContext::nsDOMWebGLRenderingContext()
{
  /* member initializers and constructor code */
}

nsDOMWebGLRenderingContext::~nsDOMWebGLRenderingContext()
{
  /* destructor code */
}

/* [noscript] DOMString mozGetUnderlyingParamString (in unsigned long pname); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::MozGetUnderlyingParamString(uint32_t pname, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMWebGLRenderingContext_h__ */
