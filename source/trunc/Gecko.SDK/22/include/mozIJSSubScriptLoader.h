/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/js/xpconnect/idl/mozIJSSubScriptLoader.idl
 */

#ifndef __gen_mozIJSSubScriptLoader_h__
#define __gen_mozIJSSubScriptLoader_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    mozIJSSubScriptLoader */
#define MOZIJSSUBSCRIPTLOADER_IID_STR "837d0211-c448-4bb8-a9bf-922ba33b9d37"

#define MOZIJSSUBSCRIPTLOADER_IID \
  {0x837d0211, 0xc448, 0x4bb8, \
    { 0xa9, 0xbf, 0x92, 0x2b, 0xa3, 0x3b, 0x9d, 0x37 }}

class NS_NO_VTABLE mozIJSSubScriptLoader : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(MOZIJSSUBSCRIPTLOADER_IID)

  /* [implicit_jscontext] jsval loadSubScript (in AString url, [optional] in jsval obj, [optional] in AString charset); */
  NS_IMETHOD LoadSubScript(const nsAString & url, const JS::Value & obj, const nsAString & charset, JSContext* cx, JS::Value *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(mozIJSSubScriptLoader, MOZIJSSUBSCRIPTLOADER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_MOZIJSSUBSCRIPTLOADER \
  NS_IMETHOD LoadSubScript(const nsAString & url, const JS::Value & obj, const nsAString & charset, JSContext* cx, JS::Value *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_MOZIJSSUBSCRIPTLOADER(_to) \
  NS_IMETHOD LoadSubScript(const nsAString & url, const JS::Value & obj, const nsAString & charset, JSContext* cx, JS::Value *_retval) { return _to LoadSubScript(url, obj, charset, cx, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_MOZIJSSUBSCRIPTLOADER(_to) \
  NS_IMETHOD LoadSubScript(const nsAString & url, const JS::Value & obj, const nsAString & charset, JSContext* cx, JS::Value *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->LoadSubScript(url, obj, charset, cx, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public mozIJSSubScriptLoader
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_MOZIJSSUBSCRIPTLOADER

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, mozIJSSubScriptLoader)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* [implicit_jscontext] jsval loadSubScript (in AString url, [optional] in jsval obj, [optional] in AString charset); */
NS_IMETHODIMP _MYCLASS_::LoadSubScript(const nsAString & url, const JS::Value & obj, const nsAString & charset, JSContext* cx, JS::Value *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_mozIJSSubScriptLoader_h__ */
