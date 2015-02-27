/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/toolkit/components/feeds/nsIFeedResult.idl
 */

#ifndef __gen_nsIFeedResult_h__
#define __gen_nsIFeedResult_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIFeedContainer; /* forward declaration */

class nsIProperties; /* forward declaration */

class nsIURI; /* forward declaration */


/* starting interface:    nsIFeedResult */
#define NS_IFEEDRESULT_IID_STR "7a180b78-0f46-4569-8c22-f3d720ea1c57"

#define NS_IFEEDRESULT_IID \
  {0x7a180b78, 0x0f46, 0x4569, \
    { 0x8c, 0x22, 0xf3, 0xd7, 0x20, 0xea, 0x1c, 0x57 }}

class NS_NO_VTABLE nsIFeedResult : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IFEEDRESULT_IID)

  /* attribute boolean bozo; */
  NS_IMETHOD GetBozo(bool *aBozo) = 0;
  NS_IMETHOD SetBozo(bool aBozo) = 0;

  /* attribute nsIFeedContainer doc; */
  NS_IMETHOD GetDoc(nsIFeedContainer * *aDoc) = 0;
  NS_IMETHOD SetDoc(nsIFeedContainer *aDoc) = 0;

  /* attribute nsIURI uri; */
  NS_IMETHOD GetUri(nsIURI * *aUri) = 0;
  NS_IMETHOD SetUri(nsIURI *aUri) = 0;

  /* attribute AString version; */
  NS_IMETHOD GetVersion(nsAString & aVersion) = 0;
  NS_IMETHOD SetVersion(const nsAString & aVersion) = 0;

  /* attribute nsIURI stylesheet; */
  NS_IMETHOD GetStylesheet(nsIURI * *aStylesheet) = 0;
  NS_IMETHOD SetStylesheet(nsIURI *aStylesheet) = 0;

  /* attribute nsIProperties headers; */
  NS_IMETHOD GetHeaders(nsIProperties * *aHeaders) = 0;
  NS_IMETHOD SetHeaders(nsIProperties *aHeaders) = 0;

  /* void registerExtensionPrefix (in AString aNamespace, in AString aPrefix); */
  NS_IMETHOD RegisterExtensionPrefix(const nsAString & aNamespace, const nsAString & aPrefix) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIFeedResult, NS_IFEEDRESULT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIFEEDRESULT \
  NS_IMETHOD GetBozo(bool *aBozo); \
  NS_IMETHOD SetBozo(bool aBozo); \
  NS_IMETHOD GetDoc(nsIFeedContainer * *aDoc); \
  NS_IMETHOD SetDoc(nsIFeedContainer *aDoc); \
  NS_IMETHOD GetUri(nsIURI * *aUri); \
  NS_IMETHOD SetUri(nsIURI *aUri); \
  NS_IMETHOD GetVersion(nsAString & aVersion); \
  NS_IMETHOD SetVersion(const nsAString & aVersion); \
  NS_IMETHOD GetStylesheet(nsIURI * *aStylesheet); \
  NS_IMETHOD SetStylesheet(nsIURI *aStylesheet); \
  NS_IMETHOD GetHeaders(nsIProperties * *aHeaders); \
  NS_IMETHOD SetHeaders(nsIProperties *aHeaders); \
  NS_IMETHOD RegisterExtensionPrefix(const nsAString & aNamespace, const nsAString & aPrefix); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIFEEDRESULT(_to) \
  NS_IMETHOD GetBozo(bool *aBozo) { return _to GetBozo(aBozo); } \
  NS_IMETHOD SetBozo(bool aBozo) { return _to SetBozo(aBozo); } \
  NS_IMETHOD GetDoc(nsIFeedContainer * *aDoc) { return _to GetDoc(aDoc); } \
  NS_IMETHOD SetDoc(nsIFeedContainer *aDoc) { return _to SetDoc(aDoc); } \
  NS_IMETHOD GetUri(nsIURI * *aUri) { return _to GetUri(aUri); } \
  NS_IMETHOD SetUri(nsIURI *aUri) { return _to SetUri(aUri); } \
  NS_IMETHOD GetVersion(nsAString & aVersion) { return _to GetVersion(aVersion); } \
  NS_IMETHOD SetVersion(const nsAString & aVersion) { return _to SetVersion(aVersion); } \
  NS_IMETHOD GetStylesheet(nsIURI * *aStylesheet) { return _to GetStylesheet(aStylesheet); } \
  NS_IMETHOD SetStylesheet(nsIURI *aStylesheet) { return _to SetStylesheet(aStylesheet); } \
  NS_IMETHOD GetHeaders(nsIProperties * *aHeaders) { return _to GetHeaders(aHeaders); } \
  NS_IMETHOD SetHeaders(nsIProperties *aHeaders) { return _to SetHeaders(aHeaders); } \
  NS_IMETHOD RegisterExtensionPrefix(const nsAString & aNamespace, const nsAString & aPrefix) { return _to RegisterExtensionPrefix(aNamespace, aPrefix); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIFEEDRESULT(_to) \
  NS_IMETHOD GetBozo(bool *aBozo) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBozo(aBozo); } \
  NS_IMETHOD SetBozo(bool aBozo) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetBozo(aBozo); } \
  NS_IMETHOD GetDoc(nsIFeedContainer * *aDoc) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDoc(aDoc); } \
  NS_IMETHOD SetDoc(nsIFeedContainer *aDoc) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDoc(aDoc); } \
  NS_IMETHOD GetUri(nsIURI * *aUri) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUri(aUri); } \
  NS_IMETHOD SetUri(nsIURI *aUri) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetUri(aUri); } \
  NS_IMETHOD GetVersion(nsAString & aVersion) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVersion(aVersion); } \
  NS_IMETHOD SetVersion(const nsAString & aVersion) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetVersion(aVersion); } \
  NS_IMETHOD GetStylesheet(nsIURI * *aStylesheet) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStylesheet(aStylesheet); } \
  NS_IMETHOD SetStylesheet(nsIURI *aStylesheet) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetStylesheet(aStylesheet); } \
  NS_IMETHOD GetHeaders(nsIProperties * *aHeaders) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHeaders(aHeaders); } \
  NS_IMETHOD SetHeaders(nsIProperties *aHeaders) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHeaders(aHeaders); } \
  NS_IMETHOD RegisterExtensionPrefix(const nsAString & aNamespace, const nsAString & aPrefix) { return !_to ? NS_ERROR_NULL_POINTER : _to->RegisterExtensionPrefix(aNamespace, aPrefix); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsFeedResult : public nsIFeedResult
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFEEDRESULT

  nsFeedResult();

private:
  ~nsFeedResult();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsFeedResult, nsIFeedResult)

nsFeedResult::nsFeedResult()
{
  /* member initializers and constructor code */
}

nsFeedResult::~nsFeedResult()
{
  /* destructor code */
}

/* attribute boolean bozo; */
NS_IMETHODIMP nsFeedResult::GetBozo(bool *aBozo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFeedResult::SetBozo(bool aBozo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIFeedContainer doc; */
NS_IMETHODIMP nsFeedResult::GetDoc(nsIFeedContainer * *aDoc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFeedResult::SetDoc(nsIFeedContainer *aDoc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIURI uri; */
NS_IMETHODIMP nsFeedResult::GetUri(nsIURI * *aUri)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFeedResult::SetUri(nsIURI *aUri)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString version; */
NS_IMETHODIMP nsFeedResult::GetVersion(nsAString & aVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFeedResult::SetVersion(const nsAString & aVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIURI stylesheet; */
NS_IMETHODIMP nsFeedResult::GetStylesheet(nsIURI * *aStylesheet)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFeedResult::SetStylesheet(nsIURI *aStylesheet)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIProperties headers; */
NS_IMETHODIMP nsFeedResult::GetHeaders(nsIProperties * *aHeaders)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFeedResult::SetHeaders(nsIProperties *aHeaders)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void registerExtensionPrefix (in AString aNamespace, in AString aPrefix); */
NS_IMETHODIMP nsFeedResult::RegisterExtensionPrefix(const nsAString & aNamespace, const nsAString & aPrefix)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIFeedResult_h__ */
