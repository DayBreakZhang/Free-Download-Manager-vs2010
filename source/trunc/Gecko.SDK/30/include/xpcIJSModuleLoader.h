/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\xpcIJSModuleLoader.idl
 */

#ifndef __gen_xpcIJSModuleLoader_h__
#define __gen_xpcIJSModuleLoader_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#include "js/TypeDecls.h"
class nsAXPCNativeCallContext;

/* starting interface:    xpcIJSModuleLoader */
#define XPCIJSMODULELOADER_IID_STR "243d1a31-db9f-47a1-9922-55a1ad5515fb"

#define XPCIJSMODULELOADER_IID \
  {0x243d1a31, 0xdb9f, 0x47a1, \
    { 0x99, 0x22, 0x55, 0xa1, 0xad, 0x55, 0x15, 0xfb }}

class NS_NO_VTABLE xpcIJSModuleLoader : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(XPCIJSMODULELOADER_IID)

  /* [implicit_jscontext,optional_argc] jsval import (in AUTF8String aResourceURI, [optional] in jsval targetObj); */
  NS_IMETHOD Import(const nsACString & aResourceURI, JS::HandleValue targetObj, JSContext* cx, uint8_t _argc, JS::MutableHandleValue _retval) = 0;

  /* [noscript] JSObjectPtr importInto (in AUTF8String aResourceURI, in JSObjectPtr targetObj, in nsAXPCNativeCallContextPtr cc); */
  NS_IMETHOD ImportInto(const nsACString & aResourceURI, JSObject *targetObj, nsAXPCNativeCallContext *cc, JSObject **_retval) = 0;

  /* void unload (in AUTF8String aResourceURI); */
  NS_IMETHOD Unload(const nsACString & aResourceURI) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(xpcIJSModuleLoader, XPCIJSMODULELOADER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_XPCIJSMODULELOADER \
  NS_IMETHOD Import(const nsACString & aResourceURI, JS::HandleValue targetObj, JSContext* cx, uint8_t _argc, JS::MutableHandleValue _retval); \
  NS_IMETHOD ImportInto(const nsACString & aResourceURI, JSObject *targetObj, nsAXPCNativeCallContext *cc, JSObject **_retval); \
  NS_IMETHOD Unload(const nsACString & aResourceURI); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_XPCIJSMODULELOADER(_to) \
  NS_IMETHOD Import(const nsACString & aResourceURI, JS::HandleValue targetObj, JSContext* cx, uint8_t _argc, JS::MutableHandleValue _retval) { return _to Import(aResourceURI, targetObj, cx, _argc, _retval); } \
  NS_IMETHOD ImportInto(const nsACString & aResourceURI, JSObject *targetObj, nsAXPCNativeCallContext *cc, JSObject **_retval) { return _to ImportInto(aResourceURI, targetObj, cc, _retval); } \
  NS_IMETHOD Unload(const nsACString & aResourceURI) { return _to Unload(aResourceURI); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_XPCIJSMODULELOADER(_to) \
  NS_IMETHOD Import(const nsACString & aResourceURI, JS::HandleValue targetObj, JSContext* cx, uint8_t _argc, JS::MutableHandleValue _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Import(aResourceURI, targetObj, cx, _argc, _retval); } \
  NS_IMETHOD ImportInto(const nsACString & aResourceURI, JSObject *targetObj, nsAXPCNativeCallContext *cc, JSObject **_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ImportInto(aResourceURI, targetObj, cc, _retval); } \
  NS_IMETHOD Unload(const nsACString & aResourceURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->Unload(aResourceURI); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public xpcIJSModuleLoader
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_XPCIJSMODULELOADER

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, xpcIJSModuleLoader)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* [implicit_jscontext,optional_argc] jsval import (in AUTF8String aResourceURI, [optional] in jsval targetObj); */
NS_IMETHODIMP _MYCLASS_::Import(const nsACString & aResourceURI, JS::HandleValue targetObj, JSContext* cx, uint8_t _argc, JS::MutableHandleValue _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] JSObjectPtr importInto (in AUTF8String aResourceURI, in JSObjectPtr targetObj, in nsAXPCNativeCallContextPtr cc); */
NS_IMETHODIMP _MYCLASS_::ImportInto(const nsACString & aResourceURI, JSObject *targetObj, nsAXPCNativeCallContext *cc, JSObject **_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void unload (in AUTF8String aResourceURI); */
NS_IMETHODIMP _MYCLASS_::Unload(const nsACString & aResourceURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_xpcIJSModuleLoader_h__ */
