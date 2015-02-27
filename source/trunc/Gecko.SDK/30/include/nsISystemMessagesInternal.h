/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsISystemMessagesInternal.idl
 */

#ifndef __gen_nsISystemMessagesInternal_h__
#define __gen_nsISystemMessagesInternal_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIDOMWindow; /* forward declaration */


/* starting interface:    nsISystemMessagesInternal */
#define NS_ISYSTEMMESSAGESINTERNAL_IID_STR "6296a314-2abf-4cd0-9097-5e81ee6832e2"

#define NS_ISYSTEMMESSAGESINTERNAL_IID \
  {0x6296a314, 0x2abf, 0x4cd0, \
    { 0x90, 0x97, 0x5e, 0x81, 0xee, 0x68, 0x32, 0xe2 }}

class NS_NO_VTABLE nsISystemMessagesInternal : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISYSTEMMESSAGESINTERNAL_IID)

  /* void sendMessage (in DOMString type, in jsval message, in nsIURI pageURI, in nsIURI manifestURI, [optional] in jsval extra); */
  NS_IMETHOD SendMessage(const nsAString & type, JS::HandleValue message, nsIURI *pageURI, nsIURI *manifestURI, JS::HandleValue extra) = 0;

  /* void broadcastMessage (in DOMString type, in jsval message, [optional] in jsval extra); */
  NS_IMETHOD BroadcastMessage(const nsAString & type, JS::HandleValue message, JS::HandleValue extra) = 0;

  /* void registerPage (in DOMString type, in nsIURI pageURI, in nsIURI manifestURI); */
  NS_IMETHOD RegisterPage(const nsAString & type, nsIURI *pageURI, nsIURI *manifestURI) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISystemMessagesInternal, NS_ISYSTEMMESSAGESINTERNAL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISYSTEMMESSAGESINTERNAL \
  NS_IMETHOD SendMessage(const nsAString & type, JS::HandleValue message, nsIURI *pageURI, nsIURI *manifestURI, JS::HandleValue extra); \
  NS_IMETHOD BroadcastMessage(const nsAString & type, JS::HandleValue message, JS::HandleValue extra); \
  NS_IMETHOD RegisterPage(const nsAString & type, nsIURI *pageURI, nsIURI *manifestURI); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISYSTEMMESSAGESINTERNAL(_to) \
  NS_IMETHOD SendMessage(const nsAString & type, JS::HandleValue message, nsIURI *pageURI, nsIURI *manifestURI, JS::HandleValue extra) { return _to SendMessage(type, message, pageURI, manifestURI, extra); } \
  NS_IMETHOD BroadcastMessage(const nsAString & type, JS::HandleValue message, JS::HandleValue extra) { return _to BroadcastMessage(type, message, extra); } \
  NS_IMETHOD RegisterPage(const nsAString & type, nsIURI *pageURI, nsIURI *manifestURI) { return _to RegisterPage(type, pageURI, manifestURI); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISYSTEMMESSAGESINTERNAL(_to) \
  NS_IMETHOD SendMessage(const nsAString & type, JS::HandleValue message, nsIURI *pageURI, nsIURI *manifestURI, JS::HandleValue extra) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendMessage(type, message, pageURI, manifestURI, extra); } \
  NS_IMETHOD BroadcastMessage(const nsAString & type, JS::HandleValue message, JS::HandleValue extra) { return !_to ? NS_ERROR_NULL_POINTER : _to->BroadcastMessage(type, message, extra); } \
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

/* void sendMessage (in DOMString type, in jsval message, in nsIURI pageURI, in nsIURI manifestURI, [optional] in jsval extra); */
NS_IMETHODIMP nsSystemMessagesInternal::SendMessage(const nsAString & type, JS::HandleValue message, nsIURI *pageURI, nsIURI *manifestURI, JS::HandleValue extra)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void broadcastMessage (in DOMString type, in jsval message, [optional] in jsval extra); */
NS_IMETHODIMP nsSystemMessagesInternal::BroadcastMessage(const nsAString & type, JS::HandleValue message, JS::HandleValue extra)
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
  NS_IMETHOD WrapMessage(JS::HandleValue message, nsIDOMWindow *window, JS::MutableHandleValue _retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISystemMessagesWrapper, NS_ISYSTEMMESSAGESWRAPPER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISYSTEMMESSAGESWRAPPER \
  NS_IMETHOD WrapMessage(JS::HandleValue message, nsIDOMWindow *window, JS::MutableHandleValue _retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISYSTEMMESSAGESWRAPPER(_to) \
  NS_IMETHOD WrapMessage(JS::HandleValue message, nsIDOMWindow *window, JS::MutableHandleValue _retval) { return _to WrapMessage(message, window, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISYSTEMMESSAGESWRAPPER(_to) \
  NS_IMETHOD WrapMessage(JS::HandleValue message, nsIDOMWindow *window, JS::MutableHandleValue _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->WrapMessage(message, window, _retval); } 

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
NS_IMETHODIMP nsSystemMessagesWrapper::WrapMessage(JS::HandleValue message, nsIDOMWindow *window, JS::MutableHandleValue _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsISystemMessagesConfigurator */
#define NS_ISYSTEMMESSAGESCONFIGURATOR_IID_STR "a0e970f6-faa9-4605-89d6-fafae8b10a80"

#define NS_ISYSTEMMESSAGESCONFIGURATOR_IID \
  {0xa0e970f6, 0xfaa9, 0x4605, \
    { 0x89, 0xd6, 0xfa, 0xfa, 0xe8, 0xb1, 0x0a, 0x80 }}

class NS_NO_VTABLE nsISystemMessagesConfigurator : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISYSTEMMESSAGESCONFIGURATOR_IID)

  /* readonly attribute boolean mustShowRunningApp; */
  NS_IMETHOD GetMustShowRunningApp(bool *aMustShowRunningApp) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISystemMessagesConfigurator, NS_ISYSTEMMESSAGESCONFIGURATOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISYSTEMMESSAGESCONFIGURATOR \
  NS_IMETHOD GetMustShowRunningApp(bool *aMustShowRunningApp); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISYSTEMMESSAGESCONFIGURATOR(_to) \
  NS_IMETHOD GetMustShowRunningApp(bool *aMustShowRunningApp) { return _to GetMustShowRunningApp(aMustShowRunningApp); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISYSTEMMESSAGESCONFIGURATOR(_to) \
  NS_IMETHOD GetMustShowRunningApp(bool *aMustShowRunningApp) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMustShowRunningApp(aMustShowRunningApp); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSystemMessagesConfigurator : public nsISystemMessagesConfigurator
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISYSTEMMESSAGESCONFIGURATOR

  nsSystemMessagesConfigurator();

private:
  ~nsSystemMessagesConfigurator();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSystemMessagesConfigurator, nsISystemMessagesConfigurator)

nsSystemMessagesConfigurator::nsSystemMessagesConfigurator()
{
  /* member initializers and constructor code */
}

nsSystemMessagesConfigurator::~nsSystemMessagesConfigurator()
{
  /* destructor code */
}

/* readonly attribute boolean mustShowRunningApp; */
NS_IMETHODIMP nsSystemMessagesConfigurator::GetMustShowRunningApp(bool *aMustShowRunningApp)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISystemMessagesInternal_h__ */
