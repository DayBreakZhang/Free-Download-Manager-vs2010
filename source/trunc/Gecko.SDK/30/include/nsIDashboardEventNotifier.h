/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDashboardEventNotifier.idl
 */

#ifndef __gen_nsIDashboardEventNotifier_h__
#define __gen_nsIDashboardEventNotifier_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDashboardEventNotifier */
#define NS_IDASHBOARDEVENTNOTIFIER_IID_STR "24fdfcbe-54cb-4997-8392-3c476126ea3b"

#define NS_IDASHBOARDEVENTNOTIFIER_IID \
  {0x24fdfcbe, 0x54cb, 0x4997, \
    { 0x83, 0x92, 0x3c, 0x47, 0x61, 0x26, 0xea, 0x3b }}

class NS_NO_VTABLE nsIDashboardEventNotifier : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDASHBOARDEVENTNOTIFIER_IID)

  /* void addHost (in ACString aHost, in unsigned long aSerial, in boolean aEncrypted); */
  NS_IMETHOD AddHost(const nsACString & aHost, uint32_t aSerial, bool aEncrypted) = 0;

  /* void removeHost (in ACString aHost, in unsigned long aSerial); */
  NS_IMETHOD RemoveHost(const nsACString & aHost, uint32_t aSerial) = 0;

  /* void newMsgSent (in ACString aHost, in unsigned long aSerial, in unsigned long aLength); */
  NS_IMETHOD NewMsgSent(const nsACString & aHost, uint32_t aSerial, uint32_t aLength) = 0;

  /* void newMsgReceived (in ACString aHost, in unsigned long aSerial, in unsigned long aLength); */
  NS_IMETHOD NewMsgReceived(const nsACString & aHost, uint32_t aSerial, uint32_t aLength) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDashboardEventNotifier, NS_IDASHBOARDEVENTNOTIFIER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDASHBOARDEVENTNOTIFIER \
  NS_IMETHOD AddHost(const nsACString & aHost, uint32_t aSerial, bool aEncrypted); \
  NS_IMETHOD RemoveHost(const nsACString & aHost, uint32_t aSerial); \
  NS_IMETHOD NewMsgSent(const nsACString & aHost, uint32_t aSerial, uint32_t aLength); \
  NS_IMETHOD NewMsgReceived(const nsACString & aHost, uint32_t aSerial, uint32_t aLength); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDASHBOARDEVENTNOTIFIER(_to) \
  NS_IMETHOD AddHost(const nsACString & aHost, uint32_t aSerial, bool aEncrypted) { return _to AddHost(aHost, aSerial, aEncrypted); } \
  NS_IMETHOD RemoveHost(const nsACString & aHost, uint32_t aSerial) { return _to RemoveHost(aHost, aSerial); } \
  NS_IMETHOD NewMsgSent(const nsACString & aHost, uint32_t aSerial, uint32_t aLength) { return _to NewMsgSent(aHost, aSerial, aLength); } \
  NS_IMETHOD NewMsgReceived(const nsACString & aHost, uint32_t aSerial, uint32_t aLength) { return _to NewMsgReceived(aHost, aSerial, aLength); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDASHBOARDEVENTNOTIFIER(_to) \
  NS_IMETHOD AddHost(const nsACString & aHost, uint32_t aSerial, bool aEncrypted) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddHost(aHost, aSerial, aEncrypted); } \
  NS_IMETHOD RemoveHost(const nsACString & aHost, uint32_t aSerial) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveHost(aHost, aSerial); } \
  NS_IMETHOD NewMsgSent(const nsACString & aHost, uint32_t aSerial, uint32_t aLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->NewMsgSent(aHost, aSerial, aLength); } \
  NS_IMETHOD NewMsgReceived(const nsACString & aHost, uint32_t aSerial, uint32_t aLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->NewMsgReceived(aHost, aSerial, aLength); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDashboardEventNotifier : public nsIDashboardEventNotifier
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDASHBOARDEVENTNOTIFIER

  nsDashboardEventNotifier();

private:
  ~nsDashboardEventNotifier();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDashboardEventNotifier, nsIDashboardEventNotifier)

nsDashboardEventNotifier::nsDashboardEventNotifier()
{
  /* member initializers and constructor code */
}

nsDashboardEventNotifier::~nsDashboardEventNotifier()
{
  /* destructor code */
}

/* void addHost (in ACString aHost, in unsigned long aSerial, in boolean aEncrypted); */
NS_IMETHODIMP nsDashboardEventNotifier::AddHost(const nsACString & aHost, uint32_t aSerial, bool aEncrypted)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeHost (in ACString aHost, in unsigned long aSerial); */
NS_IMETHODIMP nsDashboardEventNotifier::RemoveHost(const nsACString & aHost, uint32_t aSerial)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void newMsgSent (in ACString aHost, in unsigned long aSerial, in unsigned long aLength); */
NS_IMETHODIMP nsDashboardEventNotifier::NewMsgSent(const nsACString & aHost, uint32_t aSerial, uint32_t aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void newMsgReceived (in ACString aHost, in unsigned long aSerial, in unsigned long aLength); */
NS_IMETHODIMP nsDashboardEventNotifier::NewMsgReceived(const nsACString & aHost, uint32_t aSerial, uint32_t aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDashboardEventNotifier_h__ */
