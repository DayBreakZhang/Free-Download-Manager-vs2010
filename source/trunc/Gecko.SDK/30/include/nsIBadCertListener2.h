/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIBadCertListener2.idl
 */

#ifndef __gen_nsIBadCertListener2_h__
#define __gen_nsIBadCertListener2_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsISSLStatus; /* forward declaration */

class nsIInterfaceRequestor; /* forward declaration */


/* starting interface:    nsIBadCertListener2 */
#define NS_IBADCERTLISTENER2_IID_STR "2c3d268c-ad82-49f3-99aa-e9ffddd7a0dc"

#define NS_IBADCERTLISTENER2_IID \
  {0x2c3d268c, 0xad82, 0x49f3, \
    { 0x99, 0xaa, 0xe9, 0xff, 0xdd, 0xd7, 0xa0, 0xdc }}

class NS_NO_VTABLE nsIBadCertListener2 : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IBADCERTLISTENER2_IID)

  /* boolean notifyCertProblem (in nsIInterfaceRequestor socketInfo, in nsISSLStatus status, in AUTF8String targetSite); */
  NS_IMETHOD NotifyCertProblem(nsIInterfaceRequestor *socketInfo, nsISSLStatus *status, const nsACString & targetSite, bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIBadCertListener2, NS_IBADCERTLISTENER2_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIBADCERTLISTENER2 \
  NS_IMETHOD NotifyCertProblem(nsIInterfaceRequestor *socketInfo, nsISSLStatus *status, const nsACString & targetSite, bool *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIBADCERTLISTENER2(_to) \
  NS_IMETHOD NotifyCertProblem(nsIInterfaceRequestor *socketInfo, nsISSLStatus *status, const nsACString & targetSite, bool *_retval) { return _to NotifyCertProblem(socketInfo, status, targetSite, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIBADCERTLISTENER2(_to) \
  NS_IMETHOD NotifyCertProblem(nsIInterfaceRequestor *socketInfo, nsISSLStatus *status, const nsACString & targetSite, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyCertProblem(socketInfo, status, targetSite, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsBadCertListener2 : public nsIBadCertListener2
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIBADCERTLISTENER2

  nsBadCertListener2();

private:
  ~nsBadCertListener2();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsBadCertListener2, nsIBadCertListener2)

nsBadCertListener2::nsBadCertListener2()
{
  /* member initializers and constructor code */
}

nsBadCertListener2::~nsBadCertListener2()
{
  /* destructor code */
}

/* boolean notifyCertProblem (in nsIInterfaceRequestor socketInfo, in nsISSLStatus status, in AUTF8String targetSite); */
NS_IMETHODIMP nsBadCertListener2::NotifyCertProblem(nsIInterfaceRequestor *socketInfo, nsISSLStatus *status, const nsACString & targetSite, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIBadCertListener2_h__ */
