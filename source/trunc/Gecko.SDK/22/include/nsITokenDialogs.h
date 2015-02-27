/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/security/manager/ssl/public/nsITokenDialogs.idl
 */

#ifndef __gen_nsITokenDialogs_h__
#define __gen_nsITokenDialogs_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIInterfaceRequestor; /* forward declaration */

class nsIProtectedAuthThread; /* forward declaration */


/* starting interface:    nsITokenDialogs */
#define NS_ITOKENDIALOGS_IID_STR "a1cbc159-468c-495d-8068-61dd538cbcca"

#define NS_ITOKENDIALOGS_IID \
  {0xa1cbc159, 0x468c, 0x495d, \
    { 0x80, 0x68, 0x61, 0xdd, 0x53, 0x8c, 0xbc, 0xca }}

class NS_NO_VTABLE nsITokenDialogs : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITOKENDIALOGS_IID)

  /* void ChooseToken (in nsIInterfaceRequestor ctx, [array, size_is (count)] in wstring tokenNameList, in unsigned long count, out wstring tokenName, out boolean canceled); */
  NS_IMETHOD ChooseToken(nsIInterfaceRequestor *ctx, const PRUnichar * *tokenNameList, uint32_t count, PRUnichar * *tokenName, bool *canceled) = 0;

  /* void displayProtectedAuth (in nsIInterfaceRequestor ctx, in nsIProtectedAuthThread runnable); */
  NS_IMETHOD DisplayProtectedAuth(nsIInterfaceRequestor *ctx, nsIProtectedAuthThread *runnable) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITokenDialogs, NS_ITOKENDIALOGS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITOKENDIALOGS \
  NS_IMETHOD ChooseToken(nsIInterfaceRequestor *ctx, const PRUnichar * *tokenNameList, uint32_t count, PRUnichar * *tokenName, bool *canceled); \
  NS_IMETHOD DisplayProtectedAuth(nsIInterfaceRequestor *ctx, nsIProtectedAuthThread *runnable); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITOKENDIALOGS(_to) \
  NS_IMETHOD ChooseToken(nsIInterfaceRequestor *ctx, const PRUnichar * *tokenNameList, uint32_t count, PRUnichar * *tokenName, bool *canceled) { return _to ChooseToken(ctx, tokenNameList, count, tokenName, canceled); } \
  NS_IMETHOD DisplayProtectedAuth(nsIInterfaceRequestor *ctx, nsIProtectedAuthThread *runnable) { return _to DisplayProtectedAuth(ctx, runnable); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITOKENDIALOGS(_to) \
  NS_IMETHOD ChooseToken(nsIInterfaceRequestor *ctx, const PRUnichar * *tokenNameList, uint32_t count, PRUnichar * *tokenName, bool *canceled) { return !_to ? NS_ERROR_NULL_POINTER : _to->ChooseToken(ctx, tokenNameList, count, tokenName, canceled); } \
  NS_IMETHOD DisplayProtectedAuth(nsIInterfaceRequestor *ctx, nsIProtectedAuthThread *runnable) { return !_to ? NS_ERROR_NULL_POINTER : _to->DisplayProtectedAuth(ctx, runnable); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTokenDialogs : public nsITokenDialogs
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITOKENDIALOGS

  nsTokenDialogs();

private:
  ~nsTokenDialogs();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsTokenDialogs, nsITokenDialogs)

nsTokenDialogs::nsTokenDialogs()
{
  /* member initializers and constructor code */
}

nsTokenDialogs::~nsTokenDialogs()
{
  /* destructor code */
}

/* void ChooseToken (in nsIInterfaceRequestor ctx, [array, size_is (count)] in wstring tokenNameList, in unsigned long count, out wstring tokenName, out boolean canceled); */
NS_IMETHODIMP nsTokenDialogs::ChooseToken(nsIInterfaceRequestor *ctx, const PRUnichar * *tokenNameList, uint32_t count, PRUnichar * *tokenName, bool *canceled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void displayProtectedAuth (in nsIInterfaceRequestor ctx, in nsIProtectedAuthThread runnable); */
NS_IMETHODIMP nsTokenDialogs::DisplayProtectedAuth(nsIInterfaceRequestor *ctx, nsIProtectedAuthThread *runnable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_TOKENDIALOGS_CONTRACTID "@mozilla.org/nsTokenDialogs;1"

#endif /* __gen_nsITokenDialogs_h__ */
