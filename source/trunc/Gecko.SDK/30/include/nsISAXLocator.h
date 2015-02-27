/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsISAXLocator.idl
 */

#ifndef __gen_nsISAXLocator_h__
#define __gen_nsISAXLocator_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsISAXLocator */
#define NS_ISAXLOCATOR_IID_STR "7a307c6c-6cc9-11da-be43-001422106990"

#define NS_ISAXLOCATOR_IID \
  {0x7a307c6c, 0x6cc9, 0x11da, \
    { 0xbe, 0x43, 0x00, 0x14, 0x22, 0x10, 0x69, 0x90 }}

class NS_NO_VTABLE nsISAXLocator : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISAXLOCATOR_IID)

  /* readonly attribute long columnNumber; */
  NS_IMETHOD GetColumnNumber(int32_t *aColumnNumber) = 0;

  /* readonly attribute long lineNumber; */
  NS_IMETHOD GetLineNumber(int32_t *aLineNumber) = 0;

  /* readonly attribute AString publicId; */
  NS_IMETHOD GetPublicId(nsAString & aPublicId) = 0;

  /* readonly attribute AString systemId; */
  NS_IMETHOD GetSystemId(nsAString & aSystemId) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISAXLocator, NS_ISAXLOCATOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISAXLOCATOR \
  NS_IMETHOD GetColumnNumber(int32_t *aColumnNumber); \
  NS_IMETHOD GetLineNumber(int32_t *aLineNumber); \
  NS_IMETHOD GetPublicId(nsAString & aPublicId); \
  NS_IMETHOD GetSystemId(nsAString & aSystemId); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISAXLOCATOR(_to) \
  NS_IMETHOD GetColumnNumber(int32_t *aColumnNumber) { return _to GetColumnNumber(aColumnNumber); } \
  NS_IMETHOD GetLineNumber(int32_t *aLineNumber) { return _to GetLineNumber(aLineNumber); } \
  NS_IMETHOD GetPublicId(nsAString & aPublicId) { return _to GetPublicId(aPublicId); } \
  NS_IMETHOD GetSystemId(nsAString & aSystemId) { return _to GetSystemId(aSystemId); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISAXLOCATOR(_to) \
  NS_IMETHOD GetColumnNumber(int32_t *aColumnNumber) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetColumnNumber(aColumnNumber); } \
  NS_IMETHOD GetLineNumber(int32_t *aLineNumber) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLineNumber(aLineNumber); } \
  NS_IMETHOD GetPublicId(nsAString & aPublicId) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPublicId(aPublicId); } \
  NS_IMETHOD GetSystemId(nsAString & aSystemId) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSystemId(aSystemId); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSAXLocator : public nsISAXLocator
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISAXLOCATOR

  nsSAXLocator();

private:
  ~nsSAXLocator();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSAXLocator, nsISAXLocator)

nsSAXLocator::nsSAXLocator()
{
  /* member initializers and constructor code */
}

nsSAXLocator::~nsSAXLocator()
{
  /* destructor code */
}

/* readonly attribute long columnNumber; */
NS_IMETHODIMP nsSAXLocator::GetColumnNumber(int32_t *aColumnNumber)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long lineNumber; */
NS_IMETHODIMP nsSAXLocator::GetLineNumber(int32_t *aLineNumber)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString publicId; */
NS_IMETHODIMP nsSAXLocator::GetPublicId(nsAString & aPublicId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString systemId; */
NS_IMETHODIMP nsSAXLocator::GetSystemId(nsAString & aSystemId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISAXLocator_h__ */
