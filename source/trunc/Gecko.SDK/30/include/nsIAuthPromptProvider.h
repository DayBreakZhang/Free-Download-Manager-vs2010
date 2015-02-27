/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIAuthPromptProvider.idl
 */

#ifndef __gen_nsIAuthPromptProvider_h__
#define __gen_nsIAuthPromptProvider_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIAuthPromptProvider */
#define NS_IAUTHPROMPTPROVIDER_IID_STR "bd9dc0fa-68ce-47d0-8859-6418c2ae8576"

#define NS_IAUTHPROMPTPROVIDER_IID \
  {0xbd9dc0fa, 0x68ce, 0x47d0, \
    { 0x88, 0x59, 0x64, 0x18, 0xc2, 0xae, 0x85, 0x76 }}

class NS_NO_VTABLE nsIAuthPromptProvider : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IAUTHPROMPTPROVIDER_IID)

  enum {
    PROMPT_NORMAL = 0U,
    PROMPT_PROXY = 1U
  };

  /* void getAuthPrompt (in uint32_t aPromptReason, in nsIIDRef iid, [iid_is (iid), retval] out nsQIResult result); */
  NS_IMETHOD GetAuthPrompt(uint32_t aPromptReason, const nsIID & iid, void **result) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAuthPromptProvider, NS_IAUTHPROMPTPROVIDER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIAUTHPROMPTPROVIDER \
  NS_IMETHOD GetAuthPrompt(uint32_t aPromptReason, const nsIID & iid, void **result); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIAUTHPROMPTPROVIDER(_to) \
  NS_IMETHOD GetAuthPrompt(uint32_t aPromptReason, const nsIID & iid, void **result) { return _to GetAuthPrompt(aPromptReason, iid, result); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIAUTHPROMPTPROVIDER(_to) \
  NS_IMETHOD GetAuthPrompt(uint32_t aPromptReason, const nsIID & iid, void **result) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAuthPrompt(aPromptReason, iid, result); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAuthPromptProvider : public nsIAuthPromptProvider
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIAUTHPROMPTPROVIDER

  nsAuthPromptProvider();

private:
  ~nsAuthPromptProvider();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAuthPromptProvider, nsIAuthPromptProvider)

nsAuthPromptProvider::nsAuthPromptProvider()
{
  /* member initializers and constructor code */
}

nsAuthPromptProvider::~nsAuthPromptProvider()
{
  /* destructor code */
}

/* void getAuthPrompt (in uint32_t aPromptReason, in nsIIDRef iid, [iid_is (iid), retval] out nsQIResult result); */
NS_IMETHODIMP nsAuthPromptProvider::GetAuthPrompt(uint32_t aPromptReason, const nsIID & iid, void **result)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAuthPromptProvider_h__ */
