/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/core/nsIDocumentRegister.idl
 */

#ifndef __gen_nsIDocumentRegister_h__
#define __gen_nsIDocumentRegister_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDocumentRegister */
#define NS_IDOCUMENTREGISTER_IID_STR "e35935bd-ebae-4e0d-93bf-efa93ab14c05"

#define NS_IDOCUMENTREGISTER_IID \
  {0xe35935bd, 0xebae, 0x4e0d, \
    { 0x93, 0xbf, 0xef, 0xa9, 0x3a, 0xb1, 0x4c, 0x05 }}

class NS_NO_VTABLE nsIDocumentRegister : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOCUMENTREGISTER_IID)

  /* [implicit_jscontext,optional_argc] jsval register (in DOMString name, [optional] in jsval options) raises (DOMException); */
  NS_IMETHOD Register(const nsAString & name, const JS::Value & options, JSContext* cx, uint8_t _argc, JS::Value *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDocumentRegister, NS_IDOCUMENTREGISTER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOCUMENTREGISTER \
  NS_IMETHOD Register(const nsAString & name, const JS::Value & options, JSContext* cx, uint8_t _argc, JS::Value *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOCUMENTREGISTER(_to) \
  NS_IMETHOD Register(const nsAString & name, const JS::Value & options, JSContext* cx, uint8_t _argc, JS::Value *_retval) { return _to Register(name, options, cx, _argc, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOCUMENTREGISTER(_to) \
  NS_IMETHOD Register(const nsAString & name, const JS::Value & options, JSContext* cx, uint8_t _argc, JS::Value *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Register(name, options, cx, _argc, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDocumentRegister : public nsIDocumentRegister
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOCUMENTREGISTER

  nsDocumentRegister();

private:
  ~nsDocumentRegister();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDocumentRegister, nsIDocumentRegister)

nsDocumentRegister::nsDocumentRegister()
{
  /* member initializers and constructor code */
}

nsDocumentRegister::~nsDocumentRegister()
{
  /* destructor code */
}

/* [implicit_jscontext,optional_argc] jsval register (in DOMString name, [optional] in jsval options) raises (DOMException); */
NS_IMETHODIMP nsDocumentRegister::Register(const nsAString & name, const JS::Value & options, JSContext* cx, uint8_t _argc, JS::Value *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDocumentRegister_h__ */
