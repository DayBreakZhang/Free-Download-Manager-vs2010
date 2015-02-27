/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMNavigatorSystemMessages.idl
 */

#ifndef __gen_nsIDOMNavigatorSystemMessages_h__
#define __gen_nsIDOMNavigatorSystemMessages_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMSystemMessageCallback */
#define NS_IDOMSYSTEMMESSAGECALLBACK_IID_STR "42692976-57fd-4bb4-ab95-2b97ebdc5056"

#define NS_IDOMSYSTEMMESSAGECALLBACK_IID \
  {0x42692976, 0x57fd, 0x4bb4, \
    { 0xab, 0x95, 0x2b, 0x97, 0xeb, 0xdc, 0x50, 0x56 }}

class NS_NO_VTABLE nsIDOMSystemMessageCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSYSTEMMESSAGECALLBACK_IID)

  /* void handleMessage (in jsval message); */
  NS_IMETHOD HandleMessage(JS::HandleValue message) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSystemMessageCallback, NS_IDOMSYSTEMMESSAGECALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSYSTEMMESSAGECALLBACK \
  NS_IMETHOD HandleMessage(JS::HandleValue message); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSYSTEMMESSAGECALLBACK(_to) \
  NS_IMETHOD HandleMessage(JS::HandleValue message) { return _to HandleMessage(message); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSYSTEMMESSAGECALLBACK(_to) \
  NS_IMETHOD HandleMessage(JS::HandleValue message) { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleMessage(message); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSystemMessageCallback : public nsIDOMSystemMessageCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSYSTEMMESSAGECALLBACK

  nsDOMSystemMessageCallback();

private:
  ~nsDOMSystemMessageCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSystemMessageCallback, nsIDOMSystemMessageCallback)

nsDOMSystemMessageCallback::nsDOMSystemMessageCallback()
{
  /* member initializers and constructor code */
}

nsDOMSystemMessageCallback::~nsDOMSystemMessageCallback()
{
  /* destructor code */
}

/* void handleMessage (in jsval message); */
NS_IMETHODIMP nsDOMSystemMessageCallback::HandleMessage(JS::HandleValue message)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMNavigatorSystemMessages */
#define NS_IDOMNAVIGATORSYSTEMMESSAGES_IID_STR "091e90dd-0e8b-463d-8cdc-9225d3a6ff90"

#define NS_IDOMNAVIGATORSYSTEMMESSAGES_IID \
  {0x091e90dd, 0x0e8b, 0x463d, \
    { 0x8c, 0xdc, 0x92, 0x25, 0xd3, 0xa6, 0xff, 0x90 }}

class NS_NO_VTABLE nsIDOMNavigatorSystemMessages : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMNAVIGATORSYSTEMMESSAGES_IID)

  /* void mozSetMessageHandler (in DOMString type, in nsIDOMSystemMessageCallback callback); */
  NS_IMETHOD MozSetMessageHandler(const nsAString & type, nsIDOMSystemMessageCallback *callback) = 0;

  /* boolean mozHasPendingMessage (in DOMString type); */
  NS_IMETHOD MozHasPendingMessage(const nsAString & type, bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMNavigatorSystemMessages, NS_IDOMNAVIGATORSYSTEMMESSAGES_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMNAVIGATORSYSTEMMESSAGES \
  NS_IMETHOD MozSetMessageHandler(const nsAString & type, nsIDOMSystemMessageCallback *callback); \
  NS_IMETHOD MozHasPendingMessage(const nsAString & type, bool *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMNAVIGATORSYSTEMMESSAGES(_to) \
  NS_IMETHOD MozSetMessageHandler(const nsAString & type, nsIDOMSystemMessageCallback *callback) { return _to MozSetMessageHandler(type, callback); } \
  NS_IMETHOD MozHasPendingMessage(const nsAString & type, bool *_retval) { return _to MozHasPendingMessage(type, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMNAVIGATORSYSTEMMESSAGES(_to) \
  NS_IMETHOD MozSetMessageHandler(const nsAString & type, nsIDOMSystemMessageCallback *callback) { return !_to ? NS_ERROR_NULL_POINTER : _to->MozSetMessageHandler(type, callback); } \
  NS_IMETHOD MozHasPendingMessage(const nsAString & type, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->MozHasPendingMessage(type, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMNavigatorSystemMessages : public nsIDOMNavigatorSystemMessages
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMNAVIGATORSYSTEMMESSAGES

  nsDOMNavigatorSystemMessages();

private:
  ~nsDOMNavigatorSystemMessages();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMNavigatorSystemMessages, nsIDOMNavigatorSystemMessages)

nsDOMNavigatorSystemMessages::nsDOMNavigatorSystemMessages()
{
  /* member initializers and constructor code */
}

nsDOMNavigatorSystemMessages::~nsDOMNavigatorSystemMessages()
{
  /* destructor code */
}

/* void mozSetMessageHandler (in DOMString type, in nsIDOMSystemMessageCallback callback); */
NS_IMETHODIMP nsDOMNavigatorSystemMessages::MozSetMessageHandler(const nsAString & type, nsIDOMSystemMessageCallback *callback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean mozHasPendingMessage (in DOMString type); */
NS_IMETHODIMP nsDOMNavigatorSystemMessages::MozHasPendingMessage(const nsAString & type, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMNavigatorSystemMessages_h__ */
