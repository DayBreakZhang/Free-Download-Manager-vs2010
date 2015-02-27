/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIRDFLiteral.idl
 */

#ifndef __gen_nsIRDFLiteral_h__
#define __gen_nsIRDFLiteral_h__


#ifndef __gen_nsIRDFNode_h__
#include "nsIRDFNode.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#include "nscore.h" // for char16_t

/* starting interface:    nsIRDFLiteral */
#define NS_IRDFLITERAL_IID_STR "e0c493d2-9542-11d2-8eb8-00805f29f370"

#define NS_IRDFLITERAL_IID \
  {0xe0c493d2, 0x9542, 0x11d2, \
    { 0x8e, 0xb8, 0x00, 0x80, 0x5f, 0x29, 0xf3, 0x70 }}

class NS_NO_VTABLE nsIRDFLiteral : public nsIRDFNode {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IRDFLITERAL_IID)

  /* readonly attribute wstring Value; */
  NS_IMETHOD GetValue(char16_t * *aValue) = 0;

  /* [noscript] void GetValueConst ([shared] out wstring aConstValue); */
  NS_IMETHOD GetValueConst(const char16_t * *aConstValue) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIRDFLiteral, NS_IRDFLITERAL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIRDFLITERAL \
  NS_IMETHOD GetValue(char16_t * *aValue); \
  NS_IMETHOD GetValueConst(const char16_t * *aConstValue); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIRDFLITERAL(_to) \
  NS_IMETHOD GetValue(char16_t * *aValue) { return _to GetValue(aValue); } \
  NS_IMETHOD GetValueConst(const char16_t * *aConstValue) { return _to GetValueConst(aConstValue); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIRDFLITERAL(_to) \
  NS_IMETHOD GetValue(char16_t * *aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValue(aValue); } \
  NS_IMETHOD GetValueConst(const char16_t * *aConstValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValueConst(aConstValue); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsRDFLiteral : public nsIRDFLiteral
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIRDFLITERAL

  nsRDFLiteral();

private:
  ~nsRDFLiteral();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsRDFLiteral, nsIRDFLiteral)

nsRDFLiteral::nsRDFLiteral()
{
  /* member initializers and constructor code */
}

nsRDFLiteral::~nsRDFLiteral()
{
  /* destructor code */
}

/* readonly attribute wstring Value; */
NS_IMETHODIMP nsRDFLiteral::GetValue(char16_t * *aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void GetValueConst ([shared] out wstring aConstValue); */
NS_IMETHODIMP nsRDFLiteral::GetValueConst(const char16_t * *aConstValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIRDFDate */
#define NS_IRDFDATE_IID_STR "e13a24e1-c77a-11d2-80be-006097b76b8e"

#define NS_IRDFDATE_IID \
  {0xe13a24e1, 0xc77a, 0x11d2, \
    { 0x80, 0xbe, 0x00, 0x60, 0x97, 0xb7, 0x6b, 0x8e }}

class NS_NO_VTABLE nsIRDFDate : public nsIRDFNode {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IRDFDATE_IID)

  /* readonly attribute PRTime Value; */
  NS_IMETHOD GetValue(PRTime *aValue) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIRDFDate, NS_IRDFDATE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIRDFDATE \
  NS_IMETHOD GetValue(PRTime *aValue); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIRDFDATE(_to) \
  NS_IMETHOD GetValue(PRTime *aValue) { return _to GetValue(aValue); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIRDFDATE(_to) \
  NS_IMETHOD GetValue(PRTime *aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValue(aValue); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsRDFDate : public nsIRDFDate
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIRDFDATE

  nsRDFDate();

private:
  ~nsRDFDate();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsRDFDate, nsIRDFDate)

nsRDFDate::nsRDFDate()
{
  /* member initializers and constructor code */
}

nsRDFDate::~nsRDFDate()
{
  /* destructor code */
}

/* readonly attribute PRTime Value; */
NS_IMETHODIMP nsRDFDate::GetValue(PRTime *aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIRDFInt */
#define NS_IRDFINT_IID_STR "e13a24e3-c77a-11d2-80be-006097b76b8e"

#define NS_IRDFINT_IID \
  {0xe13a24e3, 0xc77a, 0x11d2, \
    { 0x80, 0xbe, 0x00, 0x60, 0x97, 0xb7, 0x6b, 0x8e }}

class NS_NO_VTABLE nsIRDFInt : public nsIRDFNode {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IRDFINT_IID)

  /* readonly attribute long Value; */
  NS_IMETHOD GetValue(int32_t *aValue) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIRDFInt, NS_IRDFINT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIRDFINT \
  NS_IMETHOD GetValue(int32_t *aValue); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIRDFINT(_to) \
  NS_IMETHOD GetValue(int32_t *aValue) { return _to GetValue(aValue); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIRDFINT(_to) \
  NS_IMETHOD GetValue(int32_t *aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValue(aValue); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsRDFInt : public nsIRDFInt
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIRDFINT

  nsRDFInt();

private:
  ~nsRDFInt();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsRDFInt, nsIRDFInt)

nsRDFInt::nsRDFInt()
{
  /* member initializers and constructor code */
}

nsRDFInt::~nsRDFInt()
{
  /* destructor code */
}

/* readonly attribute long Value; */
NS_IMETHODIMP nsRDFInt::GetValue(int32_t *aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIRDFBlob */
#define NS_IRDFBLOB_IID_STR "237f85a2-1dd2-11b2-94af-8122582fc45e"

#define NS_IRDFBLOB_IID \
  {0x237f85a2, 0x1dd2, 0x11b2, \
    { 0x94, 0xaf, 0x81, 0x22, 0x58, 0x2f, 0xc4, 0x5e }}

class NS_NO_VTABLE nsIRDFBlob : public nsIRDFNode {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IRDFBLOB_IID)

  /* [noscript] readonly attribute const_octet_ptr value; */
  NS_IMETHOD GetValue(const uint8_t **aValue) = 0;

  /* readonly attribute long length; */
  NS_IMETHOD GetLength(int32_t *aLength) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIRDFBlob, NS_IRDFBLOB_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIRDFBLOB \
  NS_IMETHOD GetValue(const uint8_t **aValue); \
  NS_IMETHOD GetLength(int32_t *aLength); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIRDFBLOB(_to) \
  NS_IMETHOD GetValue(const uint8_t **aValue) { return _to GetValue(aValue); } \
  NS_IMETHOD GetLength(int32_t *aLength) { return _to GetLength(aLength); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIRDFBLOB(_to) \
  NS_IMETHOD GetValue(const uint8_t **aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValue(aValue); } \
  NS_IMETHOD GetLength(int32_t *aLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLength(aLength); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsRDFBlob : public nsIRDFBlob
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIRDFBLOB

  nsRDFBlob();

private:
  ~nsRDFBlob();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsRDFBlob, nsIRDFBlob)

nsRDFBlob::nsRDFBlob()
{
  /* member initializers and constructor code */
}

nsRDFBlob::~nsRDFBlob()
{
  /* destructor code */
}

/* [noscript] readonly attribute const_octet_ptr value; */
NS_IMETHODIMP nsRDFBlob::GetValue(const uint8_t **aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long length; */
NS_IMETHODIMP nsRDFBlob::GetLength(int32_t *aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIRDFLiteral_h__ */
