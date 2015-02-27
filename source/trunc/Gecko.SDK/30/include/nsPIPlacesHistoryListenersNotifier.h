/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsPIPlacesHistoryListenersNotifier.idl
 */

#ifndef __gen_nsPIPlacesHistoryListenersNotifier_h__
#define __gen_nsPIPlacesHistoryListenersNotifier_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */


/* starting interface:    nsPIPlacesHistoryListenersNotifier */
#define NS_PIPLACESHISTORYLISTENERSNOTIFIER_IID_STR "808cf36c-4c9a-4bdb-91a4-d60a6fc25add"

#define NS_PIPLACESHISTORYLISTENERSNOTIFIER_IID \
  {0x808cf36c, 0x4c9a, 0x4bdb, \
    { 0x91, 0xa4, 0xd6, 0x0a, 0x6f, 0xc2, 0x5a, 0xdd }}

class NS_NO_VTABLE nsPIPlacesHistoryListenersNotifier : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_PIPLACESHISTORYLISTENERSNOTIFIER_IID)

  /* void notifyOnPageExpired (in nsIURI aURI, in PRTime aVisitTime, in boolean aWholeEntry, in ACString aGUID, in unsigned short aReason, in unsigned long aTransitionType); */
  NS_IMETHOD NotifyOnPageExpired(nsIURI *aURI, PRTime aVisitTime, bool aWholeEntry, const nsACString & aGUID, uint16_t aReason, uint32_t aTransitionType) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsPIPlacesHistoryListenersNotifier, NS_PIPLACESHISTORYLISTENERSNOTIFIER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSPIPLACESHISTORYLISTENERSNOTIFIER \
  NS_IMETHOD NotifyOnPageExpired(nsIURI *aURI, PRTime aVisitTime, bool aWholeEntry, const nsACString & aGUID, uint16_t aReason, uint32_t aTransitionType); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSPIPLACESHISTORYLISTENERSNOTIFIER(_to) \
  NS_IMETHOD NotifyOnPageExpired(nsIURI *aURI, PRTime aVisitTime, bool aWholeEntry, const nsACString & aGUID, uint16_t aReason, uint32_t aTransitionType) { return _to NotifyOnPageExpired(aURI, aVisitTime, aWholeEntry, aGUID, aReason, aTransitionType); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSPIPLACESHISTORYLISTENERSNOTIFIER(_to) \
  NS_IMETHOD NotifyOnPageExpired(nsIURI *aURI, PRTime aVisitTime, bool aWholeEntry, const nsACString & aGUID, uint16_t aReason, uint32_t aTransitionType) { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyOnPageExpired(aURI, aVisitTime, aWholeEntry, aGUID, aReason, aTransitionType); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public nsPIPlacesHistoryListenersNotifier
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSPIPLACESHISTORYLISTENERSNOTIFIER

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, nsPIPlacesHistoryListenersNotifier)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* void notifyOnPageExpired (in nsIURI aURI, in PRTime aVisitTime, in boolean aWholeEntry, in ACString aGUID, in unsigned short aReason, in unsigned long aTransitionType); */
NS_IMETHODIMP _MYCLASS_::NotifyOnPageExpired(nsIURI *aURI, PRTime aVisitTime, bool aWholeEntry, const nsACString & aGUID, uint16_t aReason, uint32_t aTransitionType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsPIPlacesHistoryListenersNotifier_h__ */
