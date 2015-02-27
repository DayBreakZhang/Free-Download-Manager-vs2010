/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/dom/interfaces/core/nsIDOM3Attr.idl
 */

#ifndef __gen_nsIDOM3Attr_h__
#define __gen_nsIDOM3Attr_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

#ifndef __gen_nsIDOM3TypeInfo_h__
#include "nsIDOM3TypeInfo.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOM3Attr */
#define NS_IDOM3ATTR_IID_STR "274ef301-065c-450d-a75b-e7673d257293"

#define NS_IDOM3ATTR_IID \
  {0x274ef301, 0x065c, 0x450d, \
    { 0xa7, 0x5b, 0xe7, 0x67, 0x3d, 0x25, 0x72, 0x93 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOM3Attr : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOM3ATTR_IID)

  /* readonly attribute nsIDOM3TypeInfo schemaTypeInfo; */
  NS_SCRIPTABLE NS_IMETHOD GetSchemaTypeInfo(nsIDOM3TypeInfo **aSchemaTypeInfo) = 0;

  /* readonly attribute boolean isId; */
  NS_SCRIPTABLE NS_IMETHOD GetIsId(PRBool *aIsId) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOM3Attr, NS_IDOM3ATTR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOM3ATTR \
  NS_SCRIPTABLE NS_IMETHOD GetSchemaTypeInfo(nsIDOM3TypeInfo **aSchemaTypeInfo); \
  NS_SCRIPTABLE NS_IMETHOD GetIsId(PRBool *aIsId); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOM3ATTR(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetSchemaTypeInfo(nsIDOM3TypeInfo **aSchemaTypeInfo) { return _to GetSchemaTypeInfo(aSchemaTypeInfo); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsId(PRBool *aIsId) { return _to GetIsId(aIsId); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOM3ATTR(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetSchemaTypeInfo(nsIDOM3TypeInfo **aSchemaTypeInfo) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSchemaTypeInfo(aSchemaTypeInfo); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsId(PRBool *aIsId) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsId(aIsId); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOM3Attr : public nsIDOM3Attr
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOM3ATTR

  nsDOM3Attr();

private:
  ~nsDOM3Attr();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOM3Attr, nsIDOM3Attr)

nsDOM3Attr::nsDOM3Attr()
{
  /* member initializers and constructor code */
}

nsDOM3Attr::~nsDOM3Attr()
{
  /* destructor code */
}

/* readonly attribute nsIDOM3TypeInfo schemaTypeInfo; */
NS_IMETHODIMP nsDOM3Attr::GetSchemaTypeInfo(nsIDOM3TypeInfo **aSchemaTypeInfo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isId; */
NS_IMETHODIMP nsDOM3Attr::GetIsId(PRBool *aIsId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOM3Attr_h__ */
