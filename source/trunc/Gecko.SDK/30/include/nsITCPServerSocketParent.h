/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsITCPServerSocketParent.idl
 */

#ifndef __gen_nsITCPServerSocketParent_h__
#define __gen_nsITCPServerSocketParent_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

#ifndef __gen_nsITCPSocketParent_h__
#include "nsITCPSocketParent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMTCPServerSocket; /* forward declaration */


/* starting interface:    nsITCPServerSocketParent */
#define NS_ITCPSERVERSOCKETPARENT_IID_STR "161ffc9f-54d3-4f21-a536-4166003d0e1d"

#define NS_ITCPSERVERSOCKETPARENT_IID \
  {0x161ffc9f, 0x54d3, 0x4f21, \
    { 0xa5, 0x36, 0x41, 0x66, 0x00, 0x3d, 0x0e, 0x1d }}

class NS_NO_VTABLE nsITCPServerSocketParent : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITCPSERVERSOCKETPARENT_IID)

  /* void sendCallbackAccept (in nsITCPSocketParent socket); */
  NS_IMETHOD SendCallbackAccept(nsITCPSocketParent *socket) = 0;

  /* void sendCallbackError (in DOMString message, in DOMString filename, in uint32_t lineNumber, in uint32_t columnNumber); */
  NS_IMETHOD SendCallbackError(const nsAString & message, const nsAString & filename, uint32_t lineNumber, uint32_t columnNumber) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITCPServerSocketParent, NS_ITCPSERVERSOCKETPARENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITCPSERVERSOCKETPARENT \
  NS_IMETHOD SendCallbackAccept(nsITCPSocketParent *socket); \
  NS_IMETHOD SendCallbackError(const nsAString & message, const nsAString & filename, uint32_t lineNumber, uint32_t columnNumber); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITCPSERVERSOCKETPARENT(_to) \
  NS_IMETHOD SendCallbackAccept(nsITCPSocketParent *socket) { return _to SendCallbackAccept(socket); } \
  NS_IMETHOD SendCallbackError(const nsAString & message, const nsAString & filename, uint32_t lineNumber, uint32_t columnNumber) { return _to SendCallbackError(message, filename, lineNumber, columnNumber); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITCPSERVERSOCKETPARENT(_to) \
  NS_IMETHOD SendCallbackAccept(nsITCPSocketParent *socket) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendCallbackAccept(socket); } \
  NS_IMETHOD SendCallbackError(const nsAString & message, const nsAString & filename, uint32_t lineNumber, uint32_t columnNumber) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendCallbackError(message, filename, lineNumber, columnNumber); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTCPServerSocketParent : public nsITCPServerSocketParent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITCPSERVERSOCKETPARENT

  nsTCPServerSocketParent();

private:
  ~nsTCPServerSocketParent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsTCPServerSocketParent, nsITCPServerSocketParent)

nsTCPServerSocketParent::nsTCPServerSocketParent()
{
  /* member initializers and constructor code */
}

nsTCPServerSocketParent::~nsTCPServerSocketParent()
{
  /* destructor code */
}

/* void sendCallbackAccept (in nsITCPSocketParent socket); */
NS_IMETHODIMP nsTCPServerSocketParent::SendCallbackAccept(nsITCPSocketParent *socket)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sendCallbackError (in DOMString message, in DOMString filename, in uint32_t lineNumber, in uint32_t columnNumber); */
NS_IMETHODIMP nsTCPServerSocketParent::SendCallbackError(const nsAString & message, const nsAString & filename, uint32_t lineNumber, uint32_t columnNumber)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsITCPServerSocketParent_h__ */
