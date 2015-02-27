/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/network/interfaces/nsITCPSocketParent.idl
 */

#ifndef __gen_nsITCPSocketParent_h__
#define __gen_nsITCPSocketParent_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMTCPSocket; /* forward declaration */


/* starting interface:    nsITCPSocketParent */
#define NS_ITCPSOCKETPARENT_IID_STR "4e7246c6-a8b3-426d-9c17-76dab1e1e14a"

#define NS_ITCPSOCKETPARENT_IID \
  {0x4e7246c6, 0xa8b3, 0x426d, \
    { 0x9c, 0x17, 0x76, 0xda, 0xb1, 0xe1, 0xe1, 0x4a }}

class NS_NO_VTABLE nsITCPSocketParent : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITCPSOCKETPARENT_IID)

  /* [implicit_jscontext] void initJS (in jsval intermediary); */
  NS_IMETHOD InitJS(const JS::Value & intermediary, JSContext* cx) = 0;

  /* [implicit_jscontext] void sendCallback (in DOMString type, in jsval data, in DOMString readyState, in uint32_t bufferedAmount); */
  NS_IMETHOD SendCallback(const nsAString & type, const JS::Value & data, const nsAString & readyState, uint32_t bufferedAmount, JSContext* cx) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITCPSocketParent, NS_ITCPSOCKETPARENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITCPSOCKETPARENT \
  NS_IMETHOD InitJS(const JS::Value & intermediary, JSContext* cx); \
  NS_IMETHOD SendCallback(const nsAString & type, const JS::Value & data, const nsAString & readyState, uint32_t bufferedAmount, JSContext* cx); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITCPSOCKETPARENT(_to) \
  NS_IMETHOD InitJS(const JS::Value & intermediary, JSContext* cx) { return _to InitJS(intermediary, cx); } \
  NS_IMETHOD SendCallback(const nsAString & type, const JS::Value & data, const nsAString & readyState, uint32_t bufferedAmount, JSContext* cx) { return _to SendCallback(type, data, readyState, bufferedAmount, cx); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITCPSOCKETPARENT(_to) \
  NS_IMETHOD InitJS(const JS::Value & intermediary, JSContext* cx) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitJS(intermediary, cx); } \
  NS_IMETHOD SendCallback(const nsAString & type, const JS::Value & data, const nsAString & readyState, uint32_t bufferedAmount, JSContext* cx) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendCallback(type, data, readyState, bufferedAmount, cx); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTCPSocketParent : public nsITCPSocketParent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITCPSOCKETPARENT

  nsTCPSocketParent();

private:
  ~nsTCPSocketParent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsTCPSocketParent, nsITCPSocketParent)

nsTCPSocketParent::nsTCPSocketParent()
{
  /* member initializers and constructor code */
}

nsTCPSocketParent::~nsTCPSocketParent()
{
  /* destructor code */
}

/* [implicit_jscontext] void initJS (in jsval intermediary); */
NS_IMETHODIMP nsTCPSocketParent::InitJS(const JS::Value & intermediary, JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] void sendCallback (in DOMString type, in jsval data, in DOMString readyState, in uint32_t bufferedAmount); */
NS_IMETHODIMP nsTCPSocketParent::SendCallback(const nsAString & type, const JS::Value & data, const nsAString & readyState, uint32_t bufferedAmount, JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsITCPSocketIntermediary */
#define NS_ITCPSOCKETINTERMEDIARY_IID_STR "afa42841-a6cb-4a91-912f-93099f6a3d18"

#define NS_ITCPSOCKETINTERMEDIARY_IID \
  {0xafa42841, 0xa6cb, 0x4a91, \
    { 0x91, 0x2f, 0x93, 0x09, 0x9f, 0x6a, 0x3d, 0x18 }}

class NS_NO_VTABLE nsITCPSocketIntermediary : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITCPSOCKETINTERMEDIARY_IID)

  /* nsIDOMTCPSocket open (in nsITCPSocketParent parent, in DOMString host, in unsigned short port, in boolean useSSL, in DOMString binaryType); */
  NS_IMETHOD Open(nsITCPSocketParent *parent, const nsAString & host, uint16_t port, bool useSSL, const nsAString & binaryType, nsIDOMTCPSocket * *_retval) = 0;

  /* void sendString (in DOMString data); */
  NS_IMETHOD SendString(const nsAString & data) = 0;

  /* void sendArrayBuffer (in jsval data); */
  NS_IMETHOD SendArrayBuffer(const JS::Value & data) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITCPSocketIntermediary, NS_ITCPSOCKETINTERMEDIARY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITCPSOCKETINTERMEDIARY \
  NS_IMETHOD Open(nsITCPSocketParent *parent, const nsAString & host, uint16_t port, bool useSSL, const nsAString & binaryType, nsIDOMTCPSocket * *_retval); \
  NS_IMETHOD SendString(const nsAString & data); \
  NS_IMETHOD SendArrayBuffer(const JS::Value & data); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITCPSOCKETINTERMEDIARY(_to) \
  NS_IMETHOD Open(nsITCPSocketParent *parent, const nsAString & host, uint16_t port, bool useSSL, const nsAString & binaryType, nsIDOMTCPSocket * *_retval) { return _to Open(parent, host, port, useSSL, binaryType, _retval); } \
  NS_IMETHOD SendString(const nsAString & data) { return _to SendString(data); } \
  NS_IMETHOD SendArrayBuffer(const JS::Value & data) { return _to SendArrayBuffer(data); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITCPSOCKETINTERMEDIARY(_to) \
  NS_IMETHOD Open(nsITCPSocketParent *parent, const nsAString & host, uint16_t port, bool useSSL, const nsAString & binaryType, nsIDOMTCPSocket * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Open(parent, host, port, useSSL, binaryType, _retval); } \
  NS_IMETHOD SendString(const nsAString & data) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendString(data); } \
  NS_IMETHOD SendArrayBuffer(const JS::Value & data) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendArrayBuffer(data); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTCPSocketIntermediary : public nsITCPSocketIntermediary
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITCPSOCKETINTERMEDIARY

  nsTCPSocketIntermediary();

private:
  ~nsTCPSocketIntermediary();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsTCPSocketIntermediary, nsITCPSocketIntermediary)

nsTCPSocketIntermediary::nsTCPSocketIntermediary()
{
  /* member initializers and constructor code */
}

nsTCPSocketIntermediary::~nsTCPSocketIntermediary()
{
  /* destructor code */
}

/* nsIDOMTCPSocket open (in nsITCPSocketParent parent, in DOMString host, in unsigned short port, in boolean useSSL, in DOMString binaryType); */
NS_IMETHODIMP nsTCPSocketIntermediary::Open(nsITCPSocketParent *parent, const nsAString & host, uint16_t port, bool useSSL, const nsAString & binaryType, nsIDOMTCPSocket * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sendString (in DOMString data); */
NS_IMETHODIMP nsTCPSocketIntermediary::SendString(const nsAString & data)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sendArrayBuffer (in jsval data); */
NS_IMETHODIMP nsTCPSocketIntermediary::SendArrayBuffer(const JS::Value & data)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsITCPSocketParent_h__ */
