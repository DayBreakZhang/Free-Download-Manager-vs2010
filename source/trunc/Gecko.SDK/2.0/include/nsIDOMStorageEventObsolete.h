/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/dom/interfaces/storage/nsIDOMStorageEventObsolete.idl
 */

#ifndef __gen_nsIDOMStorageEventObsolete_h__
#define __gen_nsIDOMStorageEventObsolete_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

#ifndef __gen_nsIDOMEvent_h__
#include "nsIDOMEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMStorageEventObsolete */
#define NS_IDOMSTORAGEEVENTOBSOLETE_IID_STR "c0178907-847d-41c0-8a62-31301bb946fa"

#define NS_IDOMSTORAGEEVENTOBSOLETE_IID \
  {0xc0178907, 0x847d, 0x41c0, \
    { 0x8a, 0x62, 0x31, 0x30, 0x1b, 0xb9, 0x46, 0xfa }}

/**
 * Interface for a client side storage. See
 * http://www.whatwg.org/specs/web-apps/current-work/#scs-client-side
 * for more information.
 *
 * Event sent to a window when a storage area changes.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMStorageEventObsolete : public nsIDOMEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSTORAGEEVENTOBSOLETE_IID)

  /**
   * Domain of the storage area which changed, or #session for
   * session storage.
   */
  /* readonly attribute DOMString domain; */
  NS_SCRIPTABLE NS_IMETHOD GetDomain(nsAString & aDomain) = 0;

  /**
   * Initialize a storage event.
   */
  /* void initStorageEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in DOMString domainArg); */
  NS_SCRIPTABLE NS_IMETHOD InitStorageEvent(const nsAString & typeArg, PRBool canBubbleArg, PRBool cancelableArg, const nsAString & domainArg) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMStorageEventObsolete, NS_IDOMSTORAGEEVENTOBSOLETE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSTORAGEEVENTOBSOLETE \
  NS_SCRIPTABLE NS_IMETHOD GetDomain(nsAString & aDomain); \
  NS_SCRIPTABLE NS_IMETHOD InitStorageEvent(const nsAString & typeArg, PRBool canBubbleArg, PRBool cancelableArg, const nsAString & domainArg); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSTORAGEEVENTOBSOLETE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetDomain(nsAString & aDomain) { return _to GetDomain(aDomain); } \
  NS_SCRIPTABLE NS_IMETHOD InitStorageEvent(const nsAString & typeArg, PRBool canBubbleArg, PRBool cancelableArg, const nsAString & domainArg) { return _to InitStorageEvent(typeArg, canBubbleArg, cancelableArg, domainArg); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSTORAGEEVENTOBSOLETE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetDomain(nsAString & aDomain) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDomain(aDomain); } \
  NS_SCRIPTABLE NS_IMETHOD InitStorageEvent(const nsAString & typeArg, PRBool canBubbleArg, PRBool cancelableArg, const nsAString & domainArg) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitStorageEvent(typeArg, canBubbleArg, cancelableArg, domainArg); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMStorageEventObsolete : public nsIDOMStorageEventObsolete
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSTORAGEEVENTOBSOLETE

  nsDOMStorageEventObsolete();

private:
  ~nsDOMStorageEventObsolete();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMStorageEventObsolete, nsIDOMStorageEventObsolete)

nsDOMStorageEventObsolete::nsDOMStorageEventObsolete()
{
  /* member initializers and constructor code */
}

nsDOMStorageEventObsolete::~nsDOMStorageEventObsolete()
{
  /* destructor code */
}

/* readonly attribute DOMString domain; */
NS_IMETHODIMP nsDOMStorageEventObsolete::GetDomain(nsAString & aDomain)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initStorageEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in DOMString domainArg); */
NS_IMETHODIMP nsDOMStorageEventObsolete::InitStorageEvent(const nsAString & typeArg, PRBool canBubbleArg, PRBool cancelableArg, const nsAString & domainArg)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMStorageEventObsolete_h__ */
