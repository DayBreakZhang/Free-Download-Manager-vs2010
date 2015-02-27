/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/dom/indexedDB/nsIIDBKeyRange.idl
 */

#ifndef __gen_nsIIDBKeyRange_h__
#define __gen_nsIIDBKeyRange_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIVariant; /* forward declaration */


/* starting interface:    nsIIDBKeyRange */
#define NS_IIDBKEYRANGE_IID_STR "a1505e41-7e48-4542-9fa5-3f2c98233567"

#define NS_IIDBKEYRANGE_IID \
  {0xa1505e41, 0x7e48, 0x4542, \
    { 0x9f, 0xa5, 0x3f, 0x2c, 0x98, 0x23, 0x35, 0x67 }}

/**
 * IDBKeyRange interface.  See
 * http://dev.w3.org/2006/webapi/WebSimpleDB/#idl-def-IDBKeyRange for more
 * information.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIIDBKeyRange : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IIDBKEYRANGE_IID)

  /* readonly attribute nsIVariant lower; */
  NS_SCRIPTABLE NS_IMETHOD GetLower(nsIVariant **aLower) = 0;

  /* readonly attribute nsIVariant upper; */
  NS_SCRIPTABLE NS_IMETHOD GetUpper(nsIVariant **aUpper) = 0;

  /* readonly attribute boolean lowerOpen; */
  NS_SCRIPTABLE NS_IMETHOD GetLowerOpen(PRBool *aLowerOpen) = 0;

  /* readonly attribute boolean upperOpen; */
  NS_SCRIPTABLE NS_IMETHOD GetUpperOpen(PRBool *aUpperOpen) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIIDBKeyRange, NS_IIDBKEYRANGE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIIDBKEYRANGE \
  NS_SCRIPTABLE NS_IMETHOD GetLower(nsIVariant **aLower); \
  NS_SCRIPTABLE NS_IMETHOD GetUpper(nsIVariant **aUpper); \
  NS_SCRIPTABLE NS_IMETHOD GetLowerOpen(PRBool *aLowerOpen); \
  NS_SCRIPTABLE NS_IMETHOD GetUpperOpen(PRBool *aUpperOpen); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIIDBKEYRANGE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetLower(nsIVariant **aLower) { return _to GetLower(aLower); } \
  NS_SCRIPTABLE NS_IMETHOD GetUpper(nsIVariant **aUpper) { return _to GetUpper(aUpper); } \
  NS_SCRIPTABLE NS_IMETHOD GetLowerOpen(PRBool *aLowerOpen) { return _to GetLowerOpen(aLowerOpen); } \
  NS_SCRIPTABLE NS_IMETHOD GetUpperOpen(PRBool *aUpperOpen) { return _to GetUpperOpen(aUpperOpen); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIIDBKEYRANGE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetLower(nsIVariant **aLower) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLower(aLower); } \
  NS_SCRIPTABLE NS_IMETHOD GetUpper(nsIVariant **aUpper) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUpper(aUpper); } \
  NS_SCRIPTABLE NS_IMETHOD GetLowerOpen(PRBool *aLowerOpen) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLowerOpen(aLowerOpen); } \
  NS_SCRIPTABLE NS_IMETHOD GetUpperOpen(PRBool *aUpperOpen) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUpperOpen(aUpperOpen); } 

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

/* readonly attribute nsIVariant lower; */
NS_IMETHODIMP nsIDBKeyRange::GetLower(nsIVariant **aLower)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIVariant upper; */
NS_IMETHODIMP nsIDBKeyRange::GetUpper(nsIVariant **aUpper)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean lowerOpen; */
NS_IMETHODIMP nsIDBKeyRange::GetLowerOpen(PRBool *aLowerOpen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean upperOpen; */
NS_IMETHODIMP nsIDBKeyRange::GetUpperOpen(PRBool *aUpperOpen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIIDBKeyRange_h__ */
