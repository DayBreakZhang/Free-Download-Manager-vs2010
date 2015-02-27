/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/messages/interfaces/nsISystemMessagesInternal.idl
 */

#ifndef __gen_nsISystemMessagesInternal_h__
#define __gen_nsISystemMessagesInternal_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIDOMWindow; /* forward declaration */


/* starting interface:    nsISystemMessagesInternal */
#define NS_ISYSTEMMESSAGESINTERNAL_IID_STR "d8de761a-94fe-44d5-80eb-3c8bd8cd7d0b"

#define NS_ISYSTEMMESSAGESINTERNAL_IID \
  {0xd8de761a, 0x94fe, 0x44d5, \
    { 0x80, 0xeb, 0x3c, 0x8b, 0xd8, 0xcd, 0x7d, 0x0b }}

class NS_NO_VTABLE nsISystemMessagesInternal : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISYSTEMMESSAGESINTERNAL_IID)

  /* void sendMessage (in DOMString type, in jsval message, in nsIURI pageURI, in nsIURI manifestURI); */
  NS_IMETHOD SendMessage(const nsAString & type, const JS::Value & message, nsIURI *pageURI, nsIURI *manifestURI) = 0;

  /* void broadcastMessage (in DOMString type, in jsval message); */
  NS_IMETHOD BroadcastMessage(const nsAString & type, const JS::Value & message) = 0;

  /* void registerPage (in DOMString type, in nsIURI pageURI, in nsIURI manifestURI); */
  NS_IMETHOD RegisterPage(const nsAString & type, nsIURI *pageURI, nsIURI *manifestURI) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISystemMessagesInternal, NS_ISYSTEMMESSAGESINTERNAL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISYSTEMMESSAGESINTERNAL \
  NS_IMETHOD SendMessage(const nsAString & type, const JS::Value & message, nsIURI *pageURI, nsIURI *manifestURI); \
  NS_IMETHOD BroadcastMessage(const nsAString & type, const JS::Value & message); \
  NS_IMETHOD RegisterPage(const nsAString & type, nsIURI *pageURI, nsIURI *manifestURI); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISYSTEMMESSAGESINTERNAL(_to) \
  NS_IMETHOD SendMessage(const nsAString & type, const JS::Value & message, nsIURI *pageURI, nsIURI *manifestURI) { return _to SendMessage(type, message, pageURI, manifestURI); } \
  NS_IMETHOD BroadcastMessage(const nsAString & type, const JS::Value & message) { return _to BroadcastMessage(type, message); } \
  NS_IMETHOD RegisterPage(const nsAString & type, nsIURI *pageURI, nsIURI *manifestURI) { return _to RegisterPage(type, pageURI, manifestURI); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISYSTEMMESSAGESINTERNAL(_to) \
  NS_IMETHOD SendMessage(const nsAString & type, const JS::Value & message, nsIURI *pageURI, nsIURI *manifestURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendMessage(type, message, pageURI, manifestURI); } \
  NS_IMETHOD BroadcastMessage(const nsAString & type, const JS::Value & message) { return !_to ? NS_ERROR_NULL_POINTER : _to->BroadcastMessage(type, message); } \
  NS_IMETHOD RegisterPage(const nsAString & type, nsIURI *pageURI, nsIURI *manifestURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->RegisterPage(type, pageURI, manifestURI); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSystemMessagesInternal : public nsISystemMessagesInternal
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISYSTEMMESSAGESINTERNAL

  nsSystemMessagesInternal();

private:
  ~nsSystemMessagesInternal();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSystemMessagesInternal, nsISystemMessagesInternal)

nsSystemMessagesInternal::nsSystemMessagesInternal()
{
  /* member initializers and constructor code */
}

nsSystemMessagesInternal::~nsSystemMessagesInternal()
{
  /* destructor code */
}

/* void sendMessage (in DOMString type, in jsval message, in nsIURI pageURI, in nsIURI manifestURI); */
NS_IMETHODIMP nsSystemMessagesInternal::SendMessage(const nsAString & type, const JS::Value & message, nsIURI *pageURI, nsIURI *manifestURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void broadcastMessage (in DOMString type, in jsval message); */
NS_IMETHODIMP nsSystemMessagesInternal::BroadcastMessage(const nsAString & type, const JS::Value & message)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void registerPage (in DOMString type, in nsIURI pageURI, in nsIURI manifestURI); */
NS_IMETHODIMP nsSystemMessagesInternal::RegisterPage(const nsAString & type, nsIURI *pageURI, nsIURI *manifestURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsISystemMessagesWrapper */
#define NS_ISYSTEMMESSAGESWRAPPER_IID_STR "002f0e82-91f0-41de-ad43-569a2b9d12df"

#define NS_ISYSTEMMESSAGESWRAPPER_IID \
  {0x002f0e82, 0x91f0, 0x41de, \
    { 0xad, 0x43, 0x56, 0x9a, 0x2b, 0x9d, 0x12, 0xdf }}

class NS_NO_VTABLE nsISystemMessagesWrapper : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISYSTEMMESSAGESWRAPPER_IID)

  /* jsval wrapMessage (in jsval message, in nsIDOMWindow window); */
  NS_IMETHOD WrapMessage(const JS::Value & message, nsIDOMWindow *window, JS::Value *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISystemMessagesWrapper, NS_ISYSTEMMESSAGESWRAPPER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISYSTEMMESSAGESWRAPPER \
  NS_IMETHOD WrapMessage(const JS::Value & message, nsIDOMWindow *window, JS::Value *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISYSTEMMESSAGESWRAPPER(_to) \
  NS_IMETHOD WrapMessage(const JS::Value & message, nsIDOMWindow *window, JS::Value *_retval) { return _to WrapMessage(message, window, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISYSTEMMESSAGESWRAPPER(_to) \
  NS_IMETHOD WrapMessage(const JS::Value & message, nsIDOMWindow *window, JS::Value *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->WrapMessage(message, window, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSystemMessagesWrapper : public nsISystemMessagesWrapper
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISYSTEMMESSAGESWRAPPER

  nsSystemMessagesWrapper();

private:
  ~nsSystemMessagesWrapper();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSystemMessagesWrapper, nsISystemMessagesWrapper)

nsSystemMessagesWrapper::nsSystemMessagesWrapper()
{
  /* member initializers and constructor code */
}

nsSystemMessagesWrapper::~nsSystemMessagesWrapper()
{
  /* destructor code */
}

/* jsval wrapMessage (in jsval message, in nsIDOMWindow window); */
NS_IMETHODIMP nsSystemMessagesWrapper::WrapMessage(const JS::Value & message, nsIDOMWindow *window, JS::Value *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISystemMessagesInternal_h__ */
