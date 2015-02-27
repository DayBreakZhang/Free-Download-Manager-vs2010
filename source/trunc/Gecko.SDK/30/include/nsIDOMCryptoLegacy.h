/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMCryptoLegacy.idl
 */

#ifndef __gen_nsIDOMCryptoLegacy_h__
#define __gen_nsIDOMCryptoLegacy_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMWindow; /* forward declaration */


/* starting interface:    nsIDOMCrypto */
#define NS_IDOMCRYPTO_IID_STR "c25ecf08-3f46-4420-bee4-8505792fd63a"

#define NS_IDOMCRYPTO_IID \
  {0xc25ecf08, 0x3f46, 0x4420, \
    { 0xbe, 0xe4, 0x85, 0x05, 0x79, 0x2f, 0xd6, 0x3a }}

class NS_NO_VTABLE nsIDOMCrypto : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMCRYPTO_IID)

  /* [notxpcom] void init (in nsIDOMWindow window); */
  NS_IMETHOD_(void) Init(nsIDOMWindow *window) = 0;

  /* attribute boolean enableSmartCardEvents; */
  NS_IMETHOD GetEnableSmartCardEvents(bool *aEnableSmartCardEvents) = 0;
  NS_IMETHOD SetEnableSmartCardEvents(bool aEnableSmartCardEvents) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMCrypto, NS_IDOMCRYPTO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMCRYPTO \
  NS_IMETHOD_(void) Init(nsIDOMWindow *window); \
  NS_IMETHOD GetEnableSmartCardEvents(bool *aEnableSmartCardEvents); \
  NS_IMETHOD SetEnableSmartCardEvents(bool aEnableSmartCardEvents); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMCRYPTO(_to) \
  NS_IMETHOD_(void) Init(nsIDOMWindow *window) { return _to Init(window); } \
  NS_IMETHOD GetEnableSmartCardEvents(bool *aEnableSmartCardEvents) { return _to GetEnableSmartCardEvents(aEnableSmartCardEvents); } \
  NS_IMETHOD SetEnableSmartCardEvents(bool aEnableSmartCardEvents) { return _to SetEnableSmartCardEvents(aEnableSmartCardEvents); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMCRYPTO(_to) \
  NS_IMETHOD_(void) Init(nsIDOMWindow *window); \
  NS_IMETHOD GetEnableSmartCardEvents(bool *aEnableSmartCardEvents) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEnableSmartCardEvents(aEnableSmartCardEvents); } \
  NS_IMETHOD SetEnableSmartCardEvents(bool aEnableSmartCardEvents) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetEnableSmartCardEvents(aEnableSmartCardEvents); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMCrypto : public nsIDOMCrypto
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMCRYPTO

  nsDOMCrypto();

private:
  ~nsDOMCrypto();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMCrypto, nsIDOMCrypto)

nsDOMCrypto::nsDOMCrypto()
{
  /* member initializers and constructor code */
}

nsDOMCrypto::~nsDOMCrypto()
{
  /* destructor code */
}

/* [notxpcom] void init (in nsIDOMWindow window); */
NS_IMETHODIMP_(void) nsDOMCrypto::Init(nsIDOMWindow *window)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean enableSmartCardEvents; */
NS_IMETHODIMP nsDOMCrypto::GetEnableSmartCardEvents(bool *aEnableSmartCardEvents)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMCrypto::SetEnableSmartCardEvents(bool aEnableSmartCardEvents)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMCryptoLegacy_h__ */
