/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIAuthPrompt2.idl
 */

#ifndef __gen_nsIAuthPrompt2_h__
#define __gen_nsIAuthPrompt2_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIAuthPromptCallback; /* forward declaration */

class nsIChannel; /* forward declaration */

class nsICancelable; /* forward declaration */

class nsIAuthInformation; /* forward declaration */


/* starting interface:    nsIAuthPrompt2 */
#define NS_IAUTHPROMPT2_IID_STR "651395eb-8612-4876-8ac0-a88d4dce9e1e"

#define NS_IAUTHPROMPT2_IID \
  {0x651395eb, 0x8612, 0x4876, \
    { 0x8a, 0xc0, 0xa8, 0x8d, 0x4d, 0xce, 0x9e, 0x1e }}

class NS_NO_VTABLE nsIAuthPrompt2 : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IAUTHPROMPT2_IID)

  enum {
    LEVEL_NONE = 0U,
    LEVEL_PW_ENCRYPTED = 1U,
    LEVEL_SECURE = 2U
  };

  /* boolean promptAuth (in nsIChannel aChannel, in uint32_t level, in nsIAuthInformation authInfo); */
  NS_IMETHOD PromptAuth(nsIChannel *aChannel, uint32_t level, nsIAuthInformation *authInfo, bool *_retval) = 0;

  /* nsICancelable asyncPromptAuth (in nsIChannel aChannel, in nsIAuthPromptCallback aCallback, in nsISupports aContext, in uint32_t level, in nsIAuthInformation authInfo); */
  NS_IMETHOD AsyncPromptAuth(nsIChannel *aChannel, nsIAuthPromptCallback *aCallback, nsISupports *aContext, uint32_t level, nsIAuthInformation *authInfo, nsICancelable * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAuthPrompt2, NS_IAUTHPROMPT2_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIAUTHPROMPT2 \
  NS_IMETHOD PromptAuth(nsIChannel *aChannel, uint32_t level, nsIAuthInformation *authInfo, bool *_retval); \
  NS_IMETHOD AsyncPromptAuth(nsIChannel *aChannel, nsIAuthPromptCallback *aCallback, nsISupports *aContext, uint32_t level, nsIAuthInformation *authInfo, nsICancelable * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIAUTHPROMPT2(_to) \
  NS_IMETHOD PromptAuth(nsIChannel *aChannel, uint32_t level, nsIAuthInformation *authInfo, bool *_retval) { return _to PromptAuth(aChannel, level, authInfo, _retval); } \
  NS_IMETHOD AsyncPromptAuth(nsIChannel *aChannel, nsIAuthPromptCallback *aCallback, nsISupports *aContext, uint32_t level, nsIAuthInformation *authInfo, nsICancelable * *_retval) { return _to AsyncPromptAuth(aChannel, aCallback, aContext, level, authInfo, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIAUTHPROMPT2(_to) \
  NS_IMETHOD PromptAuth(nsIChannel *aChannel, uint32_t level, nsIAuthInformation *authInfo, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->PromptAuth(aChannel, level, authInfo, _retval); } \
  NS_IMETHOD AsyncPromptAuth(nsIChannel *aChannel, nsIAuthPromptCallback *aCallback, nsISupports *aContext, uint32_t level, nsIAuthInformation *authInfo, nsICancelable * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->AsyncPromptAuth(aChannel, aCallback, aContext, level, authInfo, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAuthPrompt2 : public nsIAuthPrompt2
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIAUTHPROMPT2

  nsAuthPrompt2();

private:
  ~nsAuthPrompt2();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAuthPrompt2, nsIAuthPrompt2)

nsAuthPrompt2::nsAuthPrompt2()
{
  /* member initializers and constructor code */
}

nsAuthPrompt2::~nsAuthPrompt2()
{
  /* destructor code */
}

/* boolean promptAuth (in nsIChannel aChannel, in uint32_t level, in nsIAuthInformation authInfo); */
NS_IMETHODIMP nsAuthPrompt2::PromptAuth(nsIChannel *aChannel, uint32_t level, nsIAuthInformation *authInfo, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsICancelable asyncPromptAuth (in nsIChannel aChannel, in nsIAuthPromptCallback aCallback, in nsISupports aContext, in uint32_t level, in nsIAuthInformation authInfo); */
NS_IMETHODIMP nsAuthPrompt2::AsyncPromptAuth(nsIChannel *aChannel, nsIAuthPromptCallback *aCallback, nsISupports *aContext, uint32_t level, nsIAuthInformation *authInfo, nsICancelable * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAuthPrompt2_h__ */
