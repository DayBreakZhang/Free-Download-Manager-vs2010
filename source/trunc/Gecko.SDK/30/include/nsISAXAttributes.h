/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsISAXAttributes.idl
 */

#ifndef __gen_nsISAXAttributes_h__
#define __gen_nsISAXAttributes_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsISAXAttributes */
#define NS_ISAXATTRIBUTES_IID_STR "e347005e-6cd0-11da-be43-001422106990"

#define NS_ISAXATTRIBUTES_IID \
  {0xe347005e, 0x6cd0, 0x11da, \
    { 0xbe, 0x43, 0x00, 0x14, 0x22, 0x10, 0x69, 0x90 }}

class NS_NO_VTABLE nsISAXAttributes : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISAXATTRIBUTES_IID)

  /* long getIndexFromName (in AString uri, in AString localName); */
  NS_IMETHOD GetIndexFromName(const nsAString & uri, const nsAString & localName, int32_t *_retval) = 0;

  /* long getIndexFromQName (in AString qName); */
  NS_IMETHOD GetIndexFromQName(const nsAString & qName, int32_t *_retval) = 0;

  /* readonly attribute long length; */
  NS_IMETHOD GetLength(int32_t *aLength) = 0;

  /* AString getLocalName (in unsigned long index); */
  NS_IMETHOD GetLocalName(uint32_t index, nsAString & _retval) = 0;

  /* AString getQName (in unsigned long index); */
  NS_IMETHOD GetQName(uint32_t index, nsAString & _retval) = 0;

  /* AString getType (in unsigned long index); */
  NS_IMETHOD GetType(uint32_t index, nsAString & _retval) = 0;

  /* AString getTypeFromName (in AString uri, in AString localName); */
  NS_IMETHOD GetTypeFromName(const nsAString & uri, const nsAString & localName, nsAString & _retval) = 0;

  /* AString getTypeFromQName (in AString qName); */
  NS_IMETHOD GetTypeFromQName(const nsAString & qName, nsAString & _retval) = 0;

  /* AString getURI (in unsigned long index); */
  NS_IMETHOD GetURI(uint32_t index, nsAString & _retval) = 0;

  /* AString getValue (in unsigned long index); */
  NS_IMETHOD GetValue(uint32_t index, nsAString & _retval) = 0;

  /* AString getValueFromName (in AString uri, in AString localName); */
  NS_IMETHOD GetValueFromName(const nsAString & uri, const nsAString & localName, nsAString & _retval) = 0;

  /* AString getValueFromQName (in AString qName); */
  NS_IMETHOD GetValueFromQName(const nsAString & qName, nsAString & _retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISAXAttributes, NS_ISAXATTRIBUTES_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISAXATTRIBUTES \
  NS_IMETHOD GetIndexFromName(const nsAString & uri, const nsAString & localName, int32_t *_retval); \
  NS_IMETHOD GetIndexFromQName(const nsAString & qName, int32_t *_retval); \
  NS_IMETHOD GetLength(int32_t *aLength); \
  NS_IMETHOD GetLocalName(uint32_t index, nsAString & _retval); \
  NS_IMETHOD GetQName(uint32_t index, nsAString & _retval); \
  NS_IMETHOD GetType(uint32_t index, nsAString & _retval); \
  NS_IMETHOD GetTypeFromName(const nsAString & uri, const nsAString & localName, nsAString & _retval); \
  NS_IMETHOD GetTypeFromQName(const nsAString & qName, nsAString & _retval); \
  NS_IMETHOD GetURI(uint32_t index, nsAString & _retval); \
  NS_IMETHOD GetValue(uint32_t index, nsAString & _retval); \
  NS_IMETHOD GetValueFromName(const nsAString & uri, const nsAString & localName, nsAString & _retval); \
  NS_IMETHOD GetValueFromQName(const nsAString & qName, nsAString & _retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISAXATTRIBUTES(_to) \
  NS_IMETHOD GetIndexFromName(const nsAString & uri, const nsAString & localName, int32_t *_retval) { return _to GetIndexFromName(uri, localName, _retval); } \
  NS_IMETHOD GetIndexFromQName(const nsAString & qName, int32_t *_retval) { return _to GetIndexFromQName(qName, _retval); } \
  NS_IMETHOD GetLength(int32_t *aLength) { return _to GetLength(aLength); } \
  NS_IMETHOD GetLocalName(uint32_t index, nsAString & _retval) { return _to GetLocalName(index, _retval); } \
  NS_IMETHOD GetQName(uint32_t index, nsAString & _retval) { return _to GetQName(index, _retval); } \
  NS_IMETHOD GetType(uint32_t index, nsAString & _retval) { return _to GetType(index, _retval); } \
  NS_IMETHOD GetTypeFromName(const nsAString & uri, const nsAString & localName, nsAString & _retval) { return _to GetTypeFromName(uri, localName, _retval); } \
  NS_IMETHOD GetTypeFromQName(const nsAString & qName, nsAString & _retval) { return _to GetTypeFromQName(qName, _retval); } \
  NS_IMETHOD GetURI(uint32_t index, nsAString & _retval) { return _to GetURI(index, _retval); } \
  NS_IMETHOD GetValue(uint32_t index, nsAString & _retval) { return _to GetValue(index, _retval); } \
  NS_IMETHOD GetValueFromName(const nsAString & uri, const nsAString & localName, nsAString & _retval) { return _to GetValueFromName(uri, localName, _retval); } \
  NS_IMETHOD GetValueFromQName(const nsAString & qName, nsAString & _retval) { return _to GetValueFromQName(qName, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISAXATTRIBUTES(_to) \
  NS_IMETHOD GetIndexFromName(const nsAString & uri, const nsAString & localName, int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIndexFromName(uri, localName, _retval); } \
  NS_IMETHOD GetIndexFromQName(const nsAString & qName, int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIndexFromQName(qName, _retval); } \
  NS_IMETHOD GetLength(int32_t *aLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLength(aLength); } \
  NS_IMETHOD GetLocalName(uint32_t index, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLocalName(index, _retval); } \
  NS_IMETHOD GetQName(uint32_t index, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetQName(index, _retval); } \
  NS_IMETHOD GetType(uint32_t index, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(index, _retval); } \
  NS_IMETHOD GetTypeFromName(const nsAString & uri, const nsAString & localName, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTypeFromName(uri, localName, _retval); } \
  NS_IMETHOD GetTypeFromQName(const nsAString & qName, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTypeFromQName(qName, _retval); } \
  NS_IMETHOD GetURI(uint32_t index, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetURI(index, _retval); } \
  NS_IMETHOD GetValue(uint32_t index, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValue(index, _retval); } \
  NS_IMETHOD GetValueFromName(const nsAString & uri, const nsAString & localName, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValueFromName(uri, localName, _retval); } \
  NS_IMETHOD GetValueFromQName(const nsAString & qName, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValueFromQName(qName, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSAXAttributes : public nsISAXAttributes
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISAXATTRIBUTES

  nsSAXAttributes();

private:
  ~nsSAXAttributes();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSAXAttributes, nsISAXAttributes)

nsSAXAttributes::nsSAXAttributes()
{
  /* member initializers and constructor code */
}

nsSAXAttributes::~nsSAXAttributes()
{
  /* destructor code */
}

/* long getIndexFromName (in AString uri, in AString localName); */
NS_IMETHODIMP nsSAXAttributes::GetIndexFromName(const nsAString & uri, const nsAString & localName, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getIndexFromQName (in AString qName); */
NS_IMETHODIMP nsSAXAttributes::GetIndexFromQName(const nsAString & qName, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long length; */
NS_IMETHODIMP nsSAXAttributes::GetLength(int32_t *aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getLocalName (in unsigned long index); */
NS_IMETHODIMP nsSAXAttributes::GetLocalName(uint32_t index, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getQName (in unsigned long index); */
NS_IMETHODIMP nsSAXAttributes::GetQName(uint32_t index, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getType (in unsigned long index); */
NS_IMETHODIMP nsSAXAttributes::GetType(uint32_t index, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getTypeFromName (in AString uri, in AString localName); */
NS_IMETHODIMP nsSAXAttributes::GetTypeFromName(const nsAString & uri, const nsAString & localName, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getTypeFromQName (in AString qName); */
NS_IMETHODIMP nsSAXAttributes::GetTypeFromQName(const nsAString & qName, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getURI (in unsigned long index); */
NS_IMETHODIMP nsSAXAttributes::GetURI(uint32_t index, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getValue (in unsigned long index); */
NS_IMETHODIMP nsSAXAttributes::GetValue(uint32_t index, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getValueFromName (in AString uri, in AString localName); */
NS_IMETHODIMP nsSAXAttributes::GetValueFromName(const nsAString & uri, const nsAString & localName, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getValueFromQName (in AString qName); */
NS_IMETHODIMP nsSAXAttributes::GetValueFromQName(const nsAString & qName, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISAXAttributes_h__ */
