/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/core/nsIDOMDocumentType.idl
 */

#ifndef __gen_nsIDOMDocumentType_h__
#define __gen_nsIDOMDocumentType_h__


#ifndef __gen_nsIDOMNode_h__
#include "nsIDOMNode.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMDocumentType */
#define NS_IDOMDOCUMENTTYPE_IID_STR "7568365e-240f-4818-b2fc-0680bfb50942"

#define NS_IDOMDOCUMENTTYPE_IID \
  {0x7568365e, 0x240f, 0x4818, \
    { 0xb2, 0xfc, 0x06, 0x80, 0xbf, 0xb5, 0x09, 0x42 }}

class NS_NO_VTABLE nsIDOMDocumentType : public nsIDOMNode {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMDOCUMENTTYPE_IID)

  /* readonly attribute DOMString name; */
  NS_IMETHOD GetName(nsAString & aName) = 0;

  /* readonly attribute DOMString publicId; */
  NS_IMETHOD GetPublicId(nsAString & aPublicId) = 0;

  /* readonly attribute DOMString systemId; */
  NS_IMETHOD GetSystemId(nsAString & aSystemId) = 0;

  /* readonly attribute DOMString internalSubset; */
  NS_IMETHOD GetInternalSubset(nsAString & aInternalSubset) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMDocumentType, NS_IDOMDOCUMENTTYPE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMDOCUMENTTYPE \
  NS_IMETHOD GetName(nsAString & aName); \
  NS_IMETHOD GetPublicId(nsAString & aPublicId); \
  NS_IMETHOD GetSystemId(nsAString & aSystemId); \
  NS_IMETHOD GetInternalSubset(nsAString & aInternalSubset); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMDOCUMENTTYPE(_to) \
  NS_IMETHOD GetName(nsAString & aName) { return _to GetName(aName); } \
  NS_IMETHOD GetPublicId(nsAString & aPublicId) { return _to GetPublicId(aPublicId); } \
  NS_IMETHOD GetSystemId(nsAString & aSystemId) { return _to GetSystemId(aSystemId); } \
  NS_IMETHOD GetInternalSubset(nsAString & aInternalSubset) { return _to GetInternalSubset(aInternalSubset); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMDOCUMENTTYPE(_to) \
  NS_IMETHOD GetName(nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_IMETHOD GetPublicId(nsAString & aPublicId) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPublicId(aPublicId); } \
  NS_IMETHOD GetSystemId(nsAString & aSystemId) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSystemId(aSystemId); } \
  NS_IMETHOD GetInternalSubset(nsAString & aInternalSubset) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInternalSubset(aInternalSubset); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMDocumentType : public nsIDOMDocumentType
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMDOCUMENTTYPE

  nsDOMDocumentType();

private:
  ~nsDOMDocumentType();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMDocumentType, nsIDOMDocumentType)

nsDOMDocumentType::nsDOMDocumentType()
{
  /* member initializers and constructor code */
}

nsDOMDocumentType::~nsDOMDocumentType()
{
  /* destructor code */
}

/* readonly attribute DOMString name; */
NS_IMETHODIMP nsDOMDocumentType::GetName(nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString publicId; */
NS_IMETHODIMP nsDOMDocumentType::GetPublicId(nsAString & aPublicId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString systemId; */
NS_IMETHODIMP nsDOMDocumentType::GetSystemId(nsAString & aSystemId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString internalSubset; */
NS_IMETHODIMP nsDOMDocumentType::GetInternalSubset(nsAString & aInternalSubset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMDocumentType_h__ */
