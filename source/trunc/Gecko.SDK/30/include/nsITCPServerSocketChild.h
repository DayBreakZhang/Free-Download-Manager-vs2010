/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsITCPServerSocketChild.idl
 */

#ifndef __gen_nsITCPServerSocketChild_h__
#define __gen_nsITCPServerSocketChild_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

#ifndef __gen_nsIDOMTCPServerSocket_h__
#include "nsIDOMTCPServerSocket.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsITCPServerSocketInternal; /* forward declaration */


/* starting interface:    nsITCPServerSocketChild */
#define NS_ITCPSERVERSOCKETCHILD_IID_STR "41a77ec8-fd86-409e-aea9-af2ca407ef8e"

#define NS_ITCPSERVERSOCKETCHILD_IID \
  {0x41a77ec8, 0xfd86, 0x409e, \
    { 0xae, 0xa9, 0xaf, 0x2c, 0xa4, 0x07, 0xef, 0x8e }}

class NS_NO_VTABLE nsITCPServerSocketChild : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITCPSERVERSOCKETCHILD_IID)

  /* [implicit_jscontext] void listen (in nsITCPServerSocketInternal serverSocket, in unsigned short port, in unsigned short backlog, in DOMString binaryType); */
  NS_IMETHOD Listen(nsITCPServerSocketInternal *serverSocket, uint16_t port, uint16_t backlog, const nsAString & binaryType, JSContext* cx) = 0;

  /* void close (); */
  NS_IMETHOD Close(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITCPServerSocketChild, NS_ITCPSERVERSOCKETCHILD_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITCPSERVERSOCKETCHILD \
  NS_IMETHOD Listen(nsITCPServerSocketInternal *serverSocket, uint16_t port, uint16_t backlog, const nsAString & binaryType, JSContext* cx); \
  NS_IMETHOD Close(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITCPSERVERSOCKETCHILD(_to) \
  NS_IMETHOD Listen(nsITCPServerSocketInternal *serverSocket, uint16_t port, uint16_t backlog, const nsAString & binaryType, JSContext* cx) { return _to Listen(serverSocket, port, backlog, binaryType, cx); } \
  NS_IMETHOD Close(void) { return _to Close(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITCPSERVERSOCKETCHILD(_to) \
  NS_IMETHOD Listen(nsITCPServerSocketInternal *serverSocket, uint16_t port, uint16_t backlog, const nsAString & binaryType, JSContext* cx) { return !_to ? NS_ERROR_NULL_POINTER : _to->Listen(serverSocket, port, backlog, binaryType, cx); } \
  NS_IMETHOD Close(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Close(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTCPServerSocketChild : public nsITCPServerSocketChild
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITCPSERVERSOCKETCHILD

  nsTCPServerSocketChild();

private:
  ~nsTCPServerSocketChild();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsTCPServerSocketChild, nsITCPServerSocketChild)

nsTCPServerSocketChild::nsTCPServerSocketChild()
{
  /* member initializers and constructor code */
}

nsTCPServerSocketChild::~nsTCPServerSocketChild()
{
  /* destructor code */
}

/* [implicit_jscontext] void listen (in nsITCPServerSocketInternal serverSocket, in unsigned short port, in unsigned short backlog, in DOMString binaryType); */
NS_IMETHODIMP nsTCPServerSocketChild::Listen(nsITCPServerSocketInternal *serverSocket, uint16_t port, uint16_t backlog, const nsAString & binaryType, JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void close (); */
NS_IMETHODIMP nsTCPServerSocketChild::Close()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsITCPServerSocketChild_h__ */
