/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/rdf/base/idl/nsIRDFResource.idl
 */

#ifndef __gen_nsIRDFResource_h__
#define __gen_nsIRDFResource_h__


#ifndef __gen_nsrootidl_h__
#include "nsrootidl.h"
#endif

#ifndef __gen_nsIRDFNode_h__
#include "nsIRDFNode.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIRDFResource */
#define NS_IRDFRESOURCE_IID_STR "fb9686a7-719a-49dc-9107-10dea5739341"

#define NS_IRDFRESOURCE_IID \
  {0xfb9686a7, 0x719a, 0x49dc, \
    { 0x91, 0x07, 0x10, 0xde, 0xa5, 0x73, 0x93, 0x41 }}

class NS_NO_VTABLE nsIRDFResource : public nsIRDFNode {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IRDFRESOURCE_IID)

  /* readonly attribute string Value; */
  NS_IMETHOD GetValue(char * *aValue) = 0;

  /* readonly attribute AUTF8String ValueUTF8; */
  NS_IMETHOD GetValueUTF8(nsACString & aValueUTF8) = 0;

  /* [noscript] void GetValueConst ([shared] out string aConstValue); */
  NS_IMETHOD GetValueConst(const char * *aConstValue) = 0;

  /* void Init (in string uri); */
  NS_IMETHOD Init(const char * uri) = 0;

  /* boolean EqualsString (in string aURI); */
  NS_IMETHOD EqualsString(const char * aURI, bool *_retval) = 0;

  /* void GetDelegate (in string aKey, in nsIIDRef aIID, [iid_is (aIID), retval] out nsQIResult aResult); */
  NS_IMETHOD GetDelegate(const char * aKey, const nsIID & aIID, void **aResult) = 0;

  /* void ReleaseDelegate (in string aKey); */
  NS_IMETHOD ReleaseDelegate(const char * aKey) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIRDFResource, NS_IRDFRESOURCE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIRDFRESOURCE \
  NS_IMETHOD GetValue(char * *aValue); \
  NS_IMETHOD GetValueUTF8(nsACString & aValueUTF8); \
  NS_IMETHOD GetValueConst(const char * *aConstValue); \
  NS_IMETHOD Init(const char * uri); \
  NS_IMETHOD EqualsString(const char * aURI, bool *_retval); \
  NS_IMETHOD GetDelegate(const char * aKey, const nsIID & aIID, void **aResult); \
  NS_IMETHOD ReleaseDelegate(const char * aKey); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIRDFRESOURCE(_to) \
  NS_IMETHOD GetValue(char * *aValue) { return _to GetValue(aValue); } \
  NS_IMETHOD GetValueUTF8(nsACString & aValueUTF8) { return _to GetValueUTF8(aValueUTF8); } \
  NS_IMETHOD GetValueConst(const char * *aConstValue) { return _to GetValueConst(aConstValue); } \
  NS_IMETHOD Init(const char * uri) { return _to Init(uri); } \
  NS_IMETHOD EqualsString(const char * aURI, bool *_retval) { return _to EqualsString(aURI, _retval); } \
  NS_IMETHOD GetDelegate(const char * aKey, const nsIID & aIID, void **aResult) { return _to GetDelegate(aKey, aIID, aResult); } \
  NS_IMETHOD ReleaseDelegate(const char * aKey) { return _to ReleaseDelegate(aKey); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIRDFRESOURCE(_to) \
  NS_IMETHOD GetValue(char * *aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValue(aValue); } \
  NS_IMETHOD GetValueUTF8(nsACString & aValueUTF8) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValueUTF8(aValueUTF8); } \
  NS_IMETHOD GetValueConst(const char * *aConstValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValueConst(aConstValue); } \
  NS_IMETHOD Init(const char * uri) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(uri); } \
  NS_IMETHOD EqualsString(const char * aURI, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->EqualsString(aURI, _retval); } \
  NS_IMETHOD GetDelegate(const char * aKey, const nsIID & aIID, void **aResult) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDelegate(aKey, aIID, aResult); } \
  NS_IMETHOD ReleaseDelegate(const char * aKey) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReleaseDelegate(aKey); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsRDFResource : public nsIRDFResource
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIRDFRESOURCE

  nsRDFResource();

private:
  ~nsRDFResource();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsRDFResource, nsIRDFResource)

nsRDFResource::nsRDFResource()
{
  /* member initializers and constructor code */
}

nsRDFResource::~nsRDFResource()
{
  /* destructor code */
}

/* readonly attribute string Value; */
NS_IMETHODIMP nsRDFResource::GetValue(char * *aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String ValueUTF8; */
NS_IMETHODIMP nsRDFResource::GetValueUTF8(nsACString & aValueUTF8)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void GetValueConst ([shared] out string aConstValue); */
NS_IMETHODIMP nsRDFResource::GetValueConst(const char * *aConstValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void Init (in string uri); */
NS_IMETHODIMP nsRDFResource::Init(const char * uri)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean EqualsString (in string aURI); */
NS_IMETHODIMP nsRDFResource::EqualsString(const char * aURI, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void GetDelegate (in string aKey, in nsIIDRef aIID, [iid_is (aIID), retval] out nsQIResult aResult); */
NS_IMETHODIMP nsRDFResource::GetDelegate(const char * aKey, const nsIID & aIID, void **aResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void ReleaseDelegate (in string aKey); */
NS_IMETHODIMP nsRDFResource::ReleaseDelegate(const char * aKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIRDFResource_h__ */
