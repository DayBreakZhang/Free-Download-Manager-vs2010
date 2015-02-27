/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsITokenPasswordDialogs.idl
 */

#ifndef __gen_nsITokenPasswordDialogs_h__
#define __gen_nsITokenPasswordDialogs_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIInterfaceRequestor; /* forward declaration */


/* starting interface:    nsITokenPasswordDialogs */
#define NS_ITOKENPASSWORDDIALOGS_IID_STR "be26b580-1dd1-11b2-9946-c598d0d07727"

#define NS_ITOKENPASSWORDDIALOGS_IID \
  {0xbe26b580, 0x1dd1, 0x11b2, \
    { 0x99, 0x46, 0xc5, 0x98, 0xd0, 0xd0, 0x77, 0x27 }}

class NS_NO_VTABLE nsITokenPasswordDialogs : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITOKENPASSWORDDIALOGS_IID)

  /* void setPassword (in nsIInterfaceRequestor ctx, in wstring tokenName, out boolean canceled); */
  NS_IMETHOD SetPassword(nsIInterfaceRequestor *ctx, const char16_t * tokenName, bool *canceled) = 0;

  /* void getPassword (in nsIInterfaceRequestor ctx, in wstring tokenName, out wstring password, out boolean canceled); */
  NS_IMETHOD GetPassword(nsIInterfaceRequestor *ctx, const char16_t * tokenName, char16_t * *password, bool *canceled) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITokenPasswordDialogs, NS_ITOKENPASSWORDDIALOGS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITOKENPASSWORDDIALOGS \
  NS_IMETHOD SetPassword(nsIInterfaceRequestor *ctx, const char16_t * tokenName, bool *canceled); \
  NS_IMETHOD GetPassword(nsIInterfaceRequestor *ctx, const char16_t * tokenName, char16_t * *password, bool *canceled); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITOKENPASSWORDDIALOGS(_to) \
  NS_IMETHOD SetPassword(nsIInterfaceRequestor *ctx, const char16_t * tokenName, bool *canceled) { return _to SetPassword(ctx, tokenName, canceled); } \
  NS_IMETHOD GetPassword(nsIInterfaceRequestor *ctx, const char16_t * tokenName, char16_t * *password, bool *canceled) { return _to GetPassword(ctx, tokenName, password, canceled); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITOKENPASSWORDDIALOGS(_to) \
  NS_IMETHOD SetPassword(nsIInterfaceRequestor *ctx, const char16_t * tokenName, bool *canceled) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPassword(ctx, tokenName, canceled); } \
  NS_IMETHOD GetPassword(nsIInterfaceRequestor *ctx, const char16_t * tokenName, char16_t * *password, bool *canceled) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPassword(ctx, tokenName, password, canceled); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTokenPasswordDialogs : public nsITokenPasswordDialogs
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITOKENPASSWORDDIALOGS

  nsTokenPasswordDialogs();

private:
  ~nsTokenPasswordDialogs();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsTokenPasswordDialogs, nsITokenPasswordDialogs)

nsTokenPasswordDialogs::nsTokenPasswordDialogs()
{
  /* member initializers and constructor code */
}

nsTokenPasswordDialogs::~nsTokenPasswordDialogs()
{
  /* destructor code */
}

/* void setPassword (in nsIInterfaceRequestor ctx, in wstring tokenName, out boolean canceled); */
NS_IMETHODIMP nsTokenPasswordDialogs::SetPassword(nsIInterfaceRequestor *ctx, const char16_t * tokenName, bool *canceled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getPassword (in nsIInterfaceRequestor ctx, in wstring tokenName, out wstring password, out boolean canceled); */
NS_IMETHODIMP nsTokenPasswordDialogs::GetPassword(nsIInterfaceRequestor *ctx, const char16_t * tokenName, char16_t * *password, bool *canceled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_TOKENPASSWORDSDIALOG_CONTRACTID "@mozilla.org/nsTokenPasswordDialogs;1"

#endif /* __gen_nsITokenPasswordDialogs_h__ */
