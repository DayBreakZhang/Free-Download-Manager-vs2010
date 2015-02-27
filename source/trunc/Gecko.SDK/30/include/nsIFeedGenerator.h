/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIFeedGenerator.idl
 */

#ifndef __gen_nsIFeedGenerator_h__
#define __gen_nsIFeedGenerator_h__


#ifndef __gen_nsIFeedElementBase_h__
#include "nsIFeedElementBase.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */


/* starting interface:    nsIFeedGenerator */
#define NS_IFEEDGENERATOR_IID_STR "0fecd56b-bd92-481b-a486-b8d489cdd385"

#define NS_IFEEDGENERATOR_IID \
  {0x0fecd56b, 0xbd92, 0x481b, \
    { 0xa4, 0x86, 0xb8, 0xd4, 0x89, 0xcd, 0xd3, 0x85 }}

class NS_NO_VTABLE nsIFeedGenerator : public nsIFeedElementBase {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IFEEDGENERATOR_IID)

  /* attribute AString agent; */
  NS_IMETHOD GetAgent(nsAString & aAgent) = 0;
  NS_IMETHOD SetAgent(const nsAString & aAgent) = 0;

  /* attribute AString version; */
  NS_IMETHOD GetVersion(nsAString & aVersion) = 0;
  NS_IMETHOD SetVersion(const nsAString & aVersion) = 0;

  /* attribute nsIURI uri; */
  NS_IMETHOD GetUri(nsIURI * *aUri) = 0;
  NS_IMETHOD SetUri(nsIURI *aUri) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIFeedGenerator, NS_IFEEDGENERATOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIFEEDGENERATOR \
  NS_IMETHOD GetAgent(nsAString & aAgent); \
  NS_IMETHOD SetAgent(const nsAString & aAgent); \
  NS_IMETHOD GetVersion(nsAString & aVersion); \
  NS_IMETHOD SetVersion(const nsAString & aVersion); \
  NS_IMETHOD GetUri(nsIURI * *aUri); \
  NS_IMETHOD SetUri(nsIURI *aUri); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIFEEDGENERATOR(_to) \
  NS_IMETHOD GetAgent(nsAString & aAgent) { return _to GetAgent(aAgent); } \
  NS_IMETHOD SetAgent(const nsAString & aAgent) { return _to SetAgent(aAgent); } \
  NS_IMETHOD GetVersion(nsAString & aVersion) { return _to GetVersion(aVersion); } \
  NS_IMETHOD SetVersion(const nsAString & aVersion) { return _to SetVersion(aVersion); } \
  NS_IMETHOD GetUri(nsIURI * *aUri) { return _to GetUri(aUri); } \
  NS_IMETHOD SetUri(nsIURI *aUri) { return _to SetUri(aUri); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIFEEDGENERATOR(_to) \
  NS_IMETHOD GetAgent(nsAString & aAgent) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAgent(aAgent); } \
  NS_IMETHOD SetAgent(const nsAString & aAgent) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAgent(aAgent); } \
  NS_IMETHOD GetVersion(nsAString & aVersion) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVersion(aVersion); } \
  NS_IMETHOD SetVersion(const nsAString & aVersion) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetVersion(aVersion); } \
  NS_IMETHOD GetUri(nsIURI * *aUri) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUri(aUri); } \
  NS_IMETHOD SetUri(nsIURI *aUri) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetUri(aUri); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsFeedGenerator : public nsIFeedGenerator
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFEEDGENERATOR

  nsFeedGenerator();

private:
  ~nsFeedGenerator();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsFeedGenerator, nsIFeedGenerator)

nsFeedGenerator::nsFeedGenerator()
{
  /* member initializers and constructor code */
}

nsFeedGenerator::~nsFeedGenerator()
{
  /* destructor code */
}

/* attribute AString agent; */
NS_IMETHODIMP nsFeedGenerator::GetAgent(nsAString & aAgent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFeedGenerator::SetAgent(const nsAString & aAgent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString version; */
NS_IMETHODIMP nsFeedGenerator::GetVersion(nsAString & aVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFeedGenerator::SetVersion(const nsAString & aVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIURI uri; */
NS_IMETHODIMP nsFeedGenerator::GetUri(nsIURI * *aUri)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFeedGenerator::SetUri(nsIURI *aUri)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIFeedGenerator_h__ */
