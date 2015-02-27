/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsITCPSocketChild.idl
 */

#ifndef __gen_nsITCPSocketChild_h__
#define __gen_nsITCPSocketChild_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsITCPSocketInternal; /* forward declaration */

class nsIDOMWindow; /* forward declaration */


/* starting interface:    nsITCPSocketChild */
#define NS_ITCPSOCKETCHILD_IID_STR "292ebb3a-beac-4e06-88b0-b5b4e88ebd1c"

#define NS_ITCPSOCKETCHILD_IID \
  {0x292ebb3a, 0xbeac, 0x4e06, \
    { 0x88, 0xb0, 0xb5, 0xb4, 0xe8, 0x8e, 0xbd, 0x1c }}

class NS_NO_VTABLE nsITCPSocketChild : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITCPSOCKETCHILD_IID)

  /* [implicit_jscontext] void sendOpen (in nsITCPSocketInternal socket, in DOMString host, in unsigned short port, in boolean ssl, in DOMString binaryType, in nsIDOMWindow window, in jsval windowVal); */
  NS_IMETHOD SendOpen(nsITCPSocketInternal *socket, const nsAString & host, uint16_t port, bool ssl, const nsAString & binaryType, nsIDOMWindow *window, JS::HandleValue windowVal, JSContext* cx) = 0;

  /* [implicit_jscontext] void sendSend (in jsval data, in unsigned long byteOffset, in unsigned long byteLength, in unsigned long trackingNumber); */
  NS_IMETHOD SendSend(JS::HandleValue data, uint32_t byteOffset, uint32_t byteLength, uint32_t trackingNumber, JSContext* cx) = 0;

  /* void sendResume (); */
  NS_IMETHOD SendResume(void) = 0;

  /* void sendSuspend (); */
  NS_IMETHOD SendSuspend(void) = 0;

  /* void sendClose (); */
  NS_IMETHOD SendClose(void) = 0;

  /* void sendStartTLS (); */
  NS_IMETHOD SendStartTLS(void) = 0;

  /* [implicit_jscontext] void setSocketAndWindow (in nsITCPSocketInternal socket, in jsval windowVal); */
  NS_IMETHOD SetSocketAndWindow(nsITCPSocketInternal *socket, JS::HandleValue windowVal, JSContext* cx) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITCPSocketChild, NS_ITCPSOCKETCHILD_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITCPSOCKETCHILD \
  NS_IMETHOD SendOpen(nsITCPSocketInternal *socket, const nsAString & host, uint16_t port, bool ssl, const nsAString & binaryType, nsIDOMWindow *window, JS::HandleValue windowVal, JSContext* cx); \
  NS_IMETHOD SendSend(JS::HandleValue data, uint32_t byteOffset, uint32_t byteLength, uint32_t trackingNumber, JSContext* cx); \
  NS_IMETHOD SendResume(void); \
  NS_IMETHOD SendSuspend(void); \
  NS_IMETHOD SendClose(void); \
  NS_IMETHOD SendStartTLS(void); \
  NS_IMETHOD SetSocketAndWindow(nsITCPSocketInternal *socket, JS::HandleValue windowVal, JSContext* cx); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITCPSOCKETCHILD(_to) \
  NS_IMETHOD SendOpen(nsITCPSocketInternal *socket, const nsAString & host, uint16_t port, bool ssl, const nsAString & binaryType, nsIDOMWindow *window, JS::HandleValue windowVal, JSContext* cx) { return _to SendOpen(socket, host, port, ssl, binaryType, window, windowVal, cx); } \
  NS_IMETHOD SendSend(JS::HandleValue data, uint32_t byteOffset, uint32_t byteLength, uint32_t trackingNumber, JSContext* cx) { return _to SendSend(data, byteOffset, byteLength, trackingNumber, cx); } \
  NS_IMETHOD SendResume(void) { return _to SendResume(); } \
  NS_IMETHOD SendSuspend(void) { return _to SendSuspend(); } \
  NS_IMETHOD SendClose(void) { return _to SendClose(); } \
  NS_IMETHOD SendStartTLS(void) { return _to SendStartTLS(); } \
  NS_IMETHOD SetSocketAndWindow(nsITCPSocketInternal *socket, JS::HandleValue windowVal, JSContext* cx) { return _to SetSocketAndWindow(socket, windowVal, cx); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITCPSOCKETCHILD(_to) \
  NS_IMETHOD SendOpen(nsITCPSocketInternal *socket, const nsAString & host, uint16_t port, bool ssl, const nsAString & binaryType, nsIDOMWindow *window, JS::HandleValue windowVal, JSContext* cx) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendOpen(socket, host, port, ssl, binaryType, window, windowVal, cx); } \
  NS_IMETHOD SendSend(JS::HandleValue data, uint32_t byteOffset, uint32_t byteLength, uint32_t trackingNumber, JSContext* cx) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendSend(data, byteOffset, byteLength, trackingNumber, cx); } \
  NS_IMETHOD SendResume(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendResume(); } \
  NS_IMETHOD SendSuspend(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendSuspend(); } \
  NS_IMETHOD SendClose(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendClose(); } \
  NS_IMETHOD SendStartTLS(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendStartTLS(); } \
  NS_IMETHOD SetSocketAndWindow(nsITCPSocketInternal *socket, JS::HandleValue windowVal, JSContext* cx) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSocketAndWindow(socket, windowVal, cx); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTCPSocketChild : public nsITCPSocketChild
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITCPSOCKETCHILD

  nsTCPSocketChild();

private:
  ~nsTCPSocketChild();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsTCPSocketChild, nsITCPSocketChild)

nsTCPSocketChild::nsTCPSocketChild()
{
  /* member initializers and constructor code */
}

nsTCPSocketChild::~nsTCPSocketChild()
{
  /* destructor code */
}

/* [implicit_jscontext] void sendOpen (in nsITCPSocketInternal socket, in DOMString host, in unsigned short port, in boolean ssl, in DOMString binaryType, in nsIDOMWindow window, in jsval windowVal); */
NS_IMETHODIMP nsTCPSocketChild::SendOpen(nsITCPSocketInternal *socket, const nsAString & host, uint16_t port, bool ssl, const nsAString & binaryType, nsIDOMWindow *window, JS::HandleValue windowVal, JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] void sendSend (in jsval data, in unsigned long byteOffset, in unsigned long byteLength, in unsigned long trackingNumber); */
NS_IMETHODIMP nsTCPSocketChild::SendSend(JS::HandleValue data, uint32_t byteOffset, uint32_t byteLength, uint32_t trackingNumber, JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sendResume (); */
NS_IMETHODIMP nsTCPSocketChild::SendResume()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sendSuspend (); */
NS_IMETHODIMP nsTCPSocketChild::SendSuspend()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sendClose (); */
NS_IMETHODIMP nsTCPSocketChild::SendClose()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sendStartTLS (); */
NS_IMETHODIMP nsTCPSocketChild::SendStartTLS()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] void setSocketAndWindow (in nsITCPSocketInternal socket, in jsval windowVal); */
NS_IMETHODIMP nsTCPSocketChild::SetSocketAndWindow(nsITCPSocketInternal *socket, JS::HandleValue windowVal, JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsITCPSocketChild_h__ */
