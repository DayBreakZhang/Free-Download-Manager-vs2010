/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/security/manager/ssl/public/nsIASN1Object.idl
 */

#ifndef __gen_nsIASN1Object_h__
#define __gen_nsIASN1Object_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIASN1Object */
#define NS_IASN1OBJECT_IID_STR "ba8bf582-1dd1-11b2-898c-f40246bc9a63"

#define NS_IASN1OBJECT_IID \
  {0xba8bf582, 0x1dd1, 0x11b2, \
    { 0x89, 0x8c, 0xf4, 0x02, 0x46, 0xbc, 0x9a, 0x63 }}

class NS_NO_VTABLE nsIASN1Object : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IASN1OBJECT_IID)

  enum {
    ASN1_END_CONTENTS = 0U,
    ASN1_BOOLEAN = 1U,
    ASN1_INTEGER = 2U,
    ASN1_BIT_STRING = 3U,
    ASN1_OCTET_STRING = 4U,
    ASN1_NULL = 5U,
    ASN1_OBJECT_ID = 6U,
    ASN1_ENUMERATED = 10U,
    ASN1_UTF8_STRING = 12U,
    ASN1_SEQUENCE = 16U,
    ASN1_SET = 17U,
    ASN1_PRINTABLE_STRING = 19U,
    ASN1_T61_STRING = 20U,
    ASN1_IA5_STRING = 22U,
    ASN1_UTC_TIME = 23U,
    ASN1_GEN_TIME = 24U,
    ASN1_VISIBLE_STRING = 26U,
    ASN1_UNIVERSAL_STRING = 28U,
    ASN1_BMP_STRING = 30U,
    ASN1_HIGH_TAG_NUMBER = 31U,
    ASN1_CONTEXT_SPECIFIC = 32U,
    ASN1_APPLICATION = 33U,
    ASN1_PRIVATE = 34U
  };

  /* attribute unsigned long type; */
  NS_IMETHOD GetType(uint32_t *aType) = 0;
  NS_IMETHOD SetType(uint32_t aType) = 0;

  /* attribute unsigned long tag; */
  NS_IMETHOD GetTag(uint32_t *aTag) = 0;
  NS_IMETHOD SetTag(uint32_t aTag) = 0;

  /* attribute AString displayName; */
  NS_IMETHOD GetDisplayName(nsAString & aDisplayName) = 0;
  NS_IMETHOD SetDisplayName(const nsAString & aDisplayName) = 0;

  /* attribute AString displayValue; */
  NS_IMETHOD GetDisplayValue(nsAString & aDisplayValue) = 0;
  NS_IMETHOD SetDisplayValue(const nsAString & aDisplayValue) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIASN1Object, NS_IASN1OBJECT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIASN1OBJECT \
  NS_IMETHOD GetType(uint32_t *aType); \
  NS_IMETHOD SetType(uint32_t aType); \
  NS_IMETHOD GetTag(uint32_t *aTag); \
  NS_IMETHOD SetTag(uint32_t aTag); \
  NS_IMETHOD GetDisplayName(nsAString & aDisplayName); \
  NS_IMETHOD SetDisplayName(const nsAString & aDisplayName); \
  NS_IMETHOD GetDisplayValue(nsAString & aDisplayValue); \
  NS_IMETHOD SetDisplayValue(const nsAString & aDisplayValue); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIASN1OBJECT(_to) \
  NS_IMETHOD GetType(uint32_t *aType) { return _to GetType(aType); } \
  NS_IMETHOD SetType(uint32_t aType) { return _to SetType(aType); } \
  NS_IMETHOD GetTag(uint32_t *aTag) { return _to GetTag(aTag); } \
  NS_IMETHOD SetTag(uint32_t aTag) { return _to SetTag(aTag); } \
  NS_IMETHOD GetDisplayName(nsAString & aDisplayName) { return _to GetDisplayName(aDisplayName); } \
  NS_IMETHOD SetDisplayName(const nsAString & aDisplayName) { return _to SetDisplayName(aDisplayName); } \
  NS_IMETHOD GetDisplayValue(nsAString & aDisplayValue) { return _to GetDisplayValue(aDisplayValue); } \
  NS_IMETHOD SetDisplayValue(const nsAString & aDisplayValue) { return _to SetDisplayValue(aDisplayValue); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIASN1OBJECT(_to) \
  NS_IMETHOD GetType(uint32_t *aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_IMETHOD SetType(uint32_t aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetType(aType); } \
  NS_IMETHOD GetTag(uint32_t *aTag) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTag(aTag); } \
  NS_IMETHOD SetTag(uint32_t aTag) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTag(aTag); } \
  NS_IMETHOD GetDisplayName(nsAString & aDisplayName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDisplayName(aDisplayName); } \
  NS_IMETHOD SetDisplayName(const nsAString & aDisplayName) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDisplayName(aDisplayName); } \
  NS_IMETHOD GetDisplayValue(nsAString & aDisplayValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDisplayValue(aDisplayValue); } \
  NS_IMETHOD SetDisplayValue(const nsAString & aDisplayValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDisplayValue(aDisplayValue); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsASN1Object : public nsIASN1Object
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIASN1OBJECT

  nsASN1Object();

private:
  ~nsASN1Object();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsASN1Object, nsIASN1Object)

nsASN1Object::nsASN1Object()
{
  /* member initializers and constructor code */
}

nsASN1Object::~nsASN1Object()
{
  /* destructor code */
}

/* attribute unsigned long type; */
NS_IMETHODIMP nsASN1Object::GetType(uint32_t *aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsASN1Object::SetType(uint32_t aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long tag; */
NS_IMETHODIMP nsASN1Object::GetTag(uint32_t *aTag)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsASN1Object::SetTag(uint32_t aTag)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString displayName; */
NS_IMETHODIMP nsASN1Object::GetDisplayName(nsAString & aDisplayName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsASN1Object::SetDisplayName(const nsAString & aDisplayName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString displayValue; */
NS_IMETHODIMP nsASN1Object::GetDisplayValue(nsAString & aDisplayValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsASN1Object::SetDisplayValue(const nsAString & aDisplayValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIASN1Object_h__ */
