/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIFinalizationWitnessService.idl
 */

#ifndef __gen_nsIFinalizationWitnessService_h__
#define __gen_nsIFinalizationWitnessService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIFinalizationWitnessService */
#define NS_IFINALIZATIONWITNESSSERVICE_IID_STR "15686f9d-483e-4361-98cd-37f1e8f1e61d"

#define NS_IFINALIZATIONWITNESSSERVICE_IID \
  {0x15686f9d, 0x483e, 0x4361, \
    { 0x98, 0xcd, 0x37, 0xf1, 0xe8, 0xf1, 0xe6, 0x1d }}

class NS_NO_VTABLE nsIFinalizationWitnessService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IFINALIZATIONWITNESSSERVICE_IID)

  /* [implicit_jscontext] jsval make (in string aTopic, in wstring aString); */
  NS_IMETHOD Make(const char * aTopic, const char16_t * aString, JSContext* cx, JS::MutableHandleValue _retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIFinalizationWitnessService, NS_IFINALIZATIONWITNESSSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIFINALIZATIONWITNESSSERVICE \
  NS_IMETHOD Make(const char * aTopic, const char16_t * aString, JSContext* cx, JS::MutableHandleValue _retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIFINALIZATIONWITNESSSERVICE(_to) \
  NS_IMETHOD Make(const char * aTopic, const char16_t * aString, JSContext* cx, JS::MutableHandleValue _retval) { return _to Make(aTopic, aString, cx, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIFINALIZATIONWITNESSSERVICE(_to) \
  NS_IMETHOD Make(const char * aTopic, const char16_t * aString, JSContext* cx, JS::MutableHandleValue _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Make(aTopic, aString, cx, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsFinalizationWitnessService : public nsIFinalizationWitnessService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFINALIZATIONWITNESSSERVICE

  nsFinalizationWitnessService();

private:
  ~nsFinalizationWitnessService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsFinalizationWitnessService, nsIFinalizationWitnessService)

nsFinalizationWitnessService::nsFinalizationWitnessService()
{
  /* member initializers and constructor code */
}

nsFinalizationWitnessService::~nsFinalizationWitnessService()
{
  /* destructor code */
}

/* [implicit_jscontext] jsval make (in string aTopic, in wstring aString); */
NS_IMETHODIMP nsFinalizationWitnessService::Make(const char * aTopic, const char16_t * aString, JSContext* cx, JS::MutableHandleValue _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#define FINALIZATIONWITNESSSERVICE_CID {0x15686f9d,0x483e,0x4361,{0x98,0xcd,0x37,0xf1,0xe8,0xf1,0xe6,0x1d}}
#define FINALIZATIONWITNESSSERVICE_CONTRACTID "@mozilla.org/toolkit/finalizationwitness;1"

#endif /* __gen_nsIFinalizationWitnessService_h__ */
