/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/settings/nsISettingsService.idl
 */

#ifndef __gen_nsISettingsService_h__
#define __gen_nsISettingsService_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsISettingsServiceCallback */
#define NS_ISETTINGSSERVICECALLBACK_IID_STR "aad47850-2e87-11e2-81c1-0800200c9a66"

#define NS_ISETTINGSSERVICECALLBACK_IID \
  {0xaad47850, 0x2e87, 0x11e2, \
    { 0x81, 0xc1, 0x08, 0x00, 0x20, 0x0c, 0x9a, 0x66 }}

class NS_NO_VTABLE nsISettingsServiceCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISETTINGSSERVICECALLBACK_IID)

  /* void handle (in DOMString aName, in jsval aResult); */
  NS_IMETHOD Handle(const nsAString & aName, const JS::Value & aResult) = 0;

  /* void handleError (in DOMString aErrorMessage); */
  NS_IMETHOD HandleError(const nsAString & aErrorMessage) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISettingsServiceCallback, NS_ISETTINGSSERVICECALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISETTINGSSERVICECALLBACK \
  NS_IMETHOD Handle(const nsAString & aName, const JS::Value & aResult); \
  NS_IMETHOD HandleError(const nsAString & aErrorMessage); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISETTINGSSERVICECALLBACK(_to) \
  NS_IMETHOD Handle(const nsAString & aName, const JS::Value & aResult) { return _to Handle(aName, aResult); } \
  NS_IMETHOD HandleError(const nsAString & aErrorMessage) { return _to HandleError(aErrorMessage); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISETTINGSSERVICECALLBACK(_to) \
  NS_IMETHOD Handle(const nsAString & aName, const JS::Value & aResult) { return !_to ? NS_ERROR_NULL_POINTER : _to->Handle(aName, aResult); } \
  NS_IMETHOD HandleError(const nsAString & aErrorMessage) { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleError(aErrorMessage); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSettingsServiceCallback : public nsISettingsServiceCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISETTINGSSERVICECALLBACK

  nsSettingsServiceCallback();

private:
  ~nsSettingsServiceCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSettingsServiceCallback, nsISettingsServiceCallback)

nsSettingsServiceCallback::nsSettingsServiceCallback()
{
  /* member initializers and constructor code */
}

nsSettingsServiceCallback::~nsSettingsServiceCallback()
{
  /* destructor code */
}

/* void handle (in DOMString aName, in jsval aResult); */
NS_IMETHODIMP nsSettingsServiceCallback::Handle(const nsAString & aName, const JS::Value & aResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void handleError (in DOMString aErrorMessage); */
NS_IMETHODIMP nsSettingsServiceCallback::HandleError(const nsAString & aErrorMessage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsISettingsServiceLock */
#define NS_ISETTINGSSERVICELOCK_IID_STR "d7a395a0-e292-11e1-834e-1761d57f5f99"

#define NS_ISETTINGSSERVICELOCK_IID \
  {0xd7a395a0, 0xe292, 0x11e1, \
    { 0x83, 0x4e, 0x17, 0x61, 0xd5, 0x7f, 0x5f, 0x99 }}

class NS_NO_VTABLE nsISettingsServiceLock : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISETTINGSSERVICELOCK_IID)

  /* void set (in string aName, in jsval aValue, in nsISettingsServiceCallback aCallback, [optional] in string aMessage); */
  NS_IMETHOD Set(const char * aName, const JS::Value & aValue, nsISettingsServiceCallback *aCallback, const char * aMessage) = 0;

  /* void get (in string aName, in nsISettingsServiceCallback aCallback); */
  NS_IMETHOD Get(const char * aName, nsISettingsServiceCallback *aCallback) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISettingsServiceLock, NS_ISETTINGSSERVICELOCK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISETTINGSSERVICELOCK \
  NS_IMETHOD Set(const char * aName, const JS::Value & aValue, nsISettingsServiceCallback *aCallback, const char * aMessage); \
  NS_IMETHOD Get(const char * aName, nsISettingsServiceCallback *aCallback); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISETTINGSSERVICELOCK(_to) \
  NS_IMETHOD Set(const char * aName, const JS::Value & aValue, nsISettingsServiceCallback *aCallback, const char * aMessage) { return _to Set(aName, aValue, aCallback, aMessage); } \
  NS_IMETHOD Get(const char * aName, nsISettingsServiceCallback *aCallback) { return _to Get(aName, aCallback); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISETTINGSSERVICELOCK(_to) \
  NS_IMETHOD Set(const char * aName, const JS::Value & aValue, nsISettingsServiceCallback *aCallback, const char * aMessage) { return !_to ? NS_ERROR_NULL_POINTER : _to->Set(aName, aValue, aCallback, aMessage); } \
  NS_IMETHOD Get(const char * aName, nsISettingsServiceCallback *aCallback) { return !_to ? NS_ERROR_NULL_POINTER : _to->Get(aName, aCallback); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSettingsServiceLock : public nsISettingsServiceLock
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISETTINGSSERVICELOCK

  nsSettingsServiceLock();

private:
  ~nsSettingsServiceLock();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSettingsServiceLock, nsISettingsServiceLock)

nsSettingsServiceLock::nsSettingsServiceLock()
{
  /* member initializers and constructor code */
}

nsSettingsServiceLock::~nsSettingsServiceLock()
{
  /* destructor code */
}

/* void set (in string aName, in jsval aValue, in nsISettingsServiceCallback aCallback, [optional] in string aMessage); */
NS_IMETHODIMP nsSettingsServiceLock::Set(const char * aName, const JS::Value & aValue, nsISettingsServiceCallback *aCallback, const char * aMessage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void get (in string aName, in nsISettingsServiceCallback aCallback); */
NS_IMETHODIMP nsSettingsServiceLock::Get(const char * aName, nsISettingsServiceCallback *aCallback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsISettingsService */
#define NS_ISETTINGSSERVICE_IID_STR "f656f0c0-f776-11e1-a21f-0800200c9a66"

#define NS_ISETTINGSSERVICE_IID \
  {0xf656f0c0, 0xf776, 0x11e1, \
    { 0xa2, 0x1f, 0x08, 0x00, 0x20, 0x0c, 0x9a, 0x66 }}

class NS_NO_VTABLE nsISettingsService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISETTINGSSERVICE_IID)

  /* nsISettingsServiceLock createLock (); */
  NS_IMETHOD CreateLock(nsISettingsServiceLock * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISettingsService, NS_ISETTINGSSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISETTINGSSERVICE \
  NS_IMETHOD CreateLock(nsISettingsServiceLock * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISETTINGSSERVICE(_to) \
  NS_IMETHOD CreateLock(nsISettingsServiceLock * *_retval) { return _to CreateLock(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISETTINGSSERVICE(_to) \
  NS_IMETHOD CreateLock(nsISettingsServiceLock * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateLock(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSettingsService : public nsISettingsService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISETTINGSSERVICE

  nsSettingsService();

private:
  ~nsSettingsService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSettingsService, nsISettingsService)

nsSettingsService::nsSettingsService()
{
  /* member initializers and constructor code */
}

nsSettingsService::~nsSettingsService()
{
  /* destructor code */
}

/* nsISettingsServiceLock createLock (); */
NS_IMETHODIMP nsSettingsService::CreateLock(nsISettingsServiceLock * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISettingsService_h__ */
