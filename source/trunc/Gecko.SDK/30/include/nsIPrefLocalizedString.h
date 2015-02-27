/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIPrefLocalizedString.idl
 */

#ifndef __gen_nsIPrefLocalizedString_h__
#define __gen_nsIPrefLocalizedString_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIPrefLocalizedString */
#define NS_IPREFLOCALIZEDSTRING_IID_STR "ae419e24-1dd1-11b2-b39a-d3e5e7073802"

#define NS_IPREFLOCALIZEDSTRING_IID \
  {0xae419e24, 0x1dd1, 0x11b2, \
    { 0xb3, 0x9a, 0xd3, 0xe5, 0xe7, 0x07, 0x38, 0x02 }}

class NS_NO_VTABLE nsIPrefLocalizedString : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPREFLOCALIZEDSTRING_IID)

  /* attribute wstring data; */
  NS_IMETHOD GetData(char16_t * *aData) = 0;
  NS_IMETHOD SetData(const char16_t * aData) = 0;

  /* wstring toString (); */
  NS_IMETHOD ToString(char16_t * *_retval) = 0;

  /* void setDataWithLength (in unsigned long length, [size_is (length)] in wstring data); */
  NS_IMETHOD SetDataWithLength(uint32_t length, const char16_t * data) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPrefLocalizedString, NS_IPREFLOCALIZEDSTRING_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPREFLOCALIZEDSTRING \
  NS_IMETHOD GetData(char16_t * *aData); \
  NS_IMETHOD SetData(const char16_t * aData); \
  NS_IMETHOD ToString(char16_t * *_retval); \
  NS_IMETHOD SetDataWithLength(uint32_t length, const char16_t * data); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPREFLOCALIZEDSTRING(_to) \
  NS_IMETHOD GetData(char16_t * *aData) { return _to GetData(aData); } \
  NS_IMETHOD SetData(const char16_t * aData) { return _to SetData(aData); } \
  NS_IMETHOD ToString(char16_t * *_retval) { return _to ToString(_retval); } \
  NS_IMETHOD SetDataWithLength(uint32_t length, const char16_t * data) { return _to SetDataWithLength(length, data); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPREFLOCALIZEDSTRING(_to) \
  NS_IMETHOD GetData(char16_t * *aData) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetData(aData); } \
  NS_IMETHOD SetData(const char16_t * aData) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetData(aData); } \
  NS_IMETHOD ToString(char16_t * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ToString(_retval); } \
  NS_IMETHOD SetDataWithLength(uint32_t length, const char16_t * data) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDataWithLength(length, data); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPrefLocalizedString : public nsIPrefLocalizedString
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPREFLOCALIZEDSTRING

  nsPrefLocalizedString();

private:
  ~nsPrefLocalizedString();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsPrefLocalizedString, nsIPrefLocalizedString)

nsPrefLocalizedString::nsPrefLocalizedString()
{
  /* member initializers and constructor code */
}

nsPrefLocalizedString::~nsPrefLocalizedString()
{
  /* destructor code */
}

/* attribute wstring data; */
NS_IMETHODIMP nsPrefLocalizedString::GetData(char16_t * *aData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrefLocalizedString::SetData(const char16_t * aData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* wstring toString (); */
NS_IMETHODIMP nsPrefLocalizedString::ToString(char16_t * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setDataWithLength (in unsigned long length, [size_is (length)] in wstring data); */
NS_IMETHODIMP nsPrefLocalizedString::SetDataWithLength(uint32_t length, const char16_t * data)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#define NS_PREFLOCALIZEDSTRING_CID                     \
  { /* {064d9cee-1dd2-11b2-83e3-d25ab0193c26} */       \
    0x064d9cee,                                        \
    0x1dd2,                                            \
    0x11b2,                                            \
    { 0x83, 0xe3, 0xd2, 0x5a, 0xb0, 0x19, 0x3c, 0x26 } \
  }
#define NS_PREFLOCALIZEDSTRING_CONTRACTID "@mozilla.org/pref-localizedstring;1"

#endif /* __gen_nsIPrefLocalizedString_h__ */
