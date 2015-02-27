/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/indexedDB/nsIIDBKeyRange.idl
 */

#ifndef __gen_nsIIDBKeyRange_h__
#define __gen_nsIIDBKeyRange_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIIDBKeyRange */
#define NS_IIDBKEYRANGE_IID_STR "8aeb8660-76b3-4651-b8c2-9894ae6dfe68"

#define NS_IIDBKEYRANGE_IID \
  {0x8aeb8660, 0x76b3, 0x4651, \
    { 0xb8, 0xc2, 0x98, 0x94, 0xae, 0x6d, 0xfe, 0x68 }}

class NS_NO_VTABLE nsIIDBKeyRange : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IIDBKEYRANGE_IID)

  /* [implicit_jscontext] readonly attribute jsval lower; */
  NS_IMETHOD GetLower(JSContext* cx, JS::Value *aLower) = 0;

  /* [implicit_jscontext] readonly attribute jsval upper; */
  NS_IMETHOD GetUpper(JSContext* cx, JS::Value *aUpper) = 0;

  /* readonly attribute boolean lowerOpen; */
  NS_IMETHOD GetLowerOpen(bool *aLowerOpen) = 0;

  /* readonly attribute boolean upperOpen; */
  NS_IMETHOD GetUpperOpen(bool *aUpperOpen) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIIDBKeyRange, NS_IIDBKEYRANGE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIIDBKEYRANGE \
  NS_IMETHOD GetLower(JSContext* cx, JS::Value *aLower); \
  NS_IMETHOD GetUpper(JSContext* cx, JS::Value *aUpper); \
  NS_IMETHOD GetLowerOpen(bool *aLowerOpen); \
  NS_IMETHOD GetUpperOpen(bool *aUpperOpen); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIIDBKEYRANGE(_to) \
  NS_IMETHOD GetLower(JSContext* cx, JS::Value *aLower) { return _to GetLower(cx, aLower); } \
  NS_IMETHOD GetUpper(JSContext* cx, JS::Value *aUpper) { return _to GetUpper(cx, aUpper); } \
  NS_IMETHOD GetLowerOpen(bool *aLowerOpen) { return _to GetLowerOpen(aLowerOpen); } \
  NS_IMETHOD GetUpperOpen(bool *aUpperOpen) { return _to GetUpperOpen(aUpperOpen); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIIDBKEYRANGE(_to) \
  NS_IMETHOD GetLower(JSContext* cx, JS::Value *aLower) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLower(cx, aLower); } \
  NS_IMETHOD GetUpper(JSContext* cx, JS::Value *aUpper) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUpper(cx, aUpper); } \
  NS_IMETHOD GetLowerOpen(bool *aLowerOpen) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLowerOpen(aLowerOpen); } \
  NS_IMETHOD GetUpperOpen(bool *aUpperOpen) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUpperOpen(aUpperOpen); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsIDBKeyRange : public nsIIDBKeyRange
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIIDBKEYRANGE

  nsIDBKeyRange();

private:
  ~nsIDBKeyRange();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsIDBKeyRange, nsIIDBKeyRange)

nsIDBKeyRange::nsIDBKeyRange()
{
  /* member initializers and constructor code */
}

nsIDBKeyRange::~nsIDBKeyRange()
{
  /* destructor code */
}

/* [implicit_jscontext] readonly attribute jsval lower; */
NS_IMETHODIMP nsIDBKeyRange::GetLower(JSContext* cx, JS::Value *aLower)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] readonly attribute jsval upper; */
NS_IMETHODIMP nsIDBKeyRange::GetUpper(JSContext* cx, JS::Value *aUpper)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean lowerOpen; */
NS_IMETHODIMP nsIDBKeyRange::GetLowerOpen(bool *aLowerOpen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean upperOpen; */
NS_IMETHODIMP nsIDBKeyRange::GetUpperOpen(bool *aUpperOpen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIIDBKeyRange_h__ */
