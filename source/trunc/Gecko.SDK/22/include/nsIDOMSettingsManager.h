/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/settings/nsIDOMSettingsManager.idl
 */

#ifndef __gen_nsIDOMSettingsManager_h__
#define __gen_nsIDOMSettingsManager_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

#ifndef __gen_nsIDOMEventTarget_h__
#include "nsIDOMEventTarget.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMDOMRequest; /* forward declaration */

class nsIVariant; /* forward declaration */


/* starting interface:    nsIDOMSettingsLock */
#define NS_IDOMSETTINGSLOCK_IID_STR "ef95ddd0-6308-11e1-b86c-0800200c9a66"

#define NS_IDOMSETTINGSLOCK_IID \
  {0xef95ddd0, 0x6308, 0x11e1, \
    { 0xb8, 0x6c, 0x08, 0x00, 0x20, 0x0c, 0x9a, 0x66 }}

class NS_NO_VTABLE nsIDOMSettingsLock : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSETTINGSLOCK_IID)

  /* readonly attribute boolean closed; */
  NS_IMETHOD GetClosed(bool *aClosed) = 0;

  /* nsIDOMDOMRequest set (in nsIVariant settings); */
  NS_IMETHOD Set(nsIVariant *settings, nsIDOMDOMRequest * *_retval) = 0;

  /* nsIDOMDOMRequest get (in jsval name); */
  NS_IMETHOD Get(const JS::Value & name, nsIDOMDOMRequest * *_retval) = 0;

  /* nsIDOMDOMRequest clear (); */
  NS_IMETHOD Clear(nsIDOMDOMRequest * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSettingsLock, NS_IDOMSETTINGSLOCK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSETTINGSLOCK \
  NS_IMETHOD GetClosed(bool *aClosed); \
  NS_IMETHOD Set(nsIVariant *settings, nsIDOMDOMRequest * *_retval); \
  NS_IMETHOD Get(const JS::Value & name, nsIDOMDOMRequest * *_retval); \
  NS_IMETHOD Clear(nsIDOMDOMRequest * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSETTINGSLOCK(_to) \
  NS_IMETHOD GetClosed(bool *aClosed) { return _to GetClosed(aClosed); } \
  NS_IMETHOD Set(nsIVariant *settings, nsIDOMDOMRequest * *_retval) { return _to Set(settings, _retval); } \
  NS_IMETHOD Get(const JS::Value & name, nsIDOMDOMRequest * *_retval) { return _to Get(name, _retval); } \
  NS_IMETHOD Clear(nsIDOMDOMRequest * *_retval) { return _to Clear(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSETTINGSLOCK(_to) \
  NS_IMETHOD GetClosed(bool *aClosed) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetClosed(aClosed); } \
  NS_IMETHOD Set(nsIVariant *settings, nsIDOMDOMRequest * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Set(settings, _retval); } \
  NS_IMETHOD Get(const JS::Value & name, nsIDOMDOMRequest * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Get(name, _retval); } \
  NS_IMETHOD Clear(nsIDOMDOMRequest * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Clear(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSettingsLock : public nsIDOMSettingsLock
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSETTINGSLOCK

  nsDOMSettingsLock();

private:
  ~nsDOMSettingsLock();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSettingsLock, nsIDOMSettingsLock)

nsDOMSettingsLock::nsDOMSettingsLock()
{
  /* member initializers and constructor code */
}

nsDOMSettingsLock::~nsDOMSettingsLock()
{
  /* destructor code */
}

/* readonly attribute boolean closed; */
NS_IMETHODIMP nsDOMSettingsLock::GetClosed(bool *aClosed)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDOMRequest set (in nsIVariant settings); */
NS_IMETHODIMP nsDOMSettingsLock::Set(nsIVariant *settings, nsIDOMDOMRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDOMRequest get (in jsval name); */
NS_IMETHODIMP nsDOMSettingsLock::Get(const JS::Value & name, nsIDOMDOMRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDOMRequest clear (); */
NS_IMETHODIMP nsDOMSettingsLock::Clear(nsIDOMDOMRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMSettingsManager */
#define NS_IDOMSETTINGSMANAGER_IID_STR "c40b1c70-00fb-11e2-a21f-0800200c9a66"

#define NS_IDOMSETTINGSMANAGER_IID \
  {0xc40b1c70, 0x00fb, 0x11e2, \
    { 0xa2, 0x1f, 0x08, 0x00, 0x20, 0x0c, 0x9a, 0x66 }}

class NS_NO_VTABLE nsIDOMSettingsManager : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSETTINGSMANAGER_IID)

  /* nsIDOMSettingsLock createLock (); */
  NS_IMETHOD CreateLock(nsIDOMSettingsLock * *_retval) = 0;

  /* void addObserver (in DOMString name, in jsval callback); */
  NS_IMETHOD AddObserver(const nsAString & name, const JS::Value & callback) = 0;

  /* void removeObserver (in DOMString name, in jsval callback); */
  NS_IMETHOD RemoveObserver(const nsAString & name, const JS::Value & callback) = 0;

  /* attribute nsIDOMEventListener onsettingchange; */
  NS_IMETHOD GetOnsettingchange(nsIDOMEventListener * *aOnsettingchange) = 0;
  NS_IMETHOD SetOnsettingchange(nsIDOMEventListener *aOnsettingchange) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSettingsManager, NS_IDOMSETTINGSMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSETTINGSMANAGER \
  NS_IMETHOD CreateLock(nsIDOMSettingsLock * *_retval); \
  NS_IMETHOD AddObserver(const nsAString & name, const JS::Value & callback); \
  NS_IMETHOD RemoveObserver(const nsAString & name, const JS::Value & callback); \
  NS_IMETHOD GetOnsettingchange(nsIDOMEventListener * *aOnsettingchange); \
  NS_IMETHOD SetOnsettingchange(nsIDOMEventListener *aOnsettingchange); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSETTINGSMANAGER(_to) \
  NS_IMETHOD CreateLock(nsIDOMSettingsLock * *_retval) { return _to CreateLock(_retval); } \
  NS_IMETHOD AddObserver(const nsAString & name, const JS::Value & callback) { return _to AddObserver(name, callback); } \
  NS_IMETHOD RemoveObserver(const nsAString & name, const JS::Value & callback) { return _to RemoveObserver(name, callback); } \
  NS_IMETHOD GetOnsettingchange(nsIDOMEventListener * *aOnsettingchange) { return _to GetOnsettingchange(aOnsettingchange); } \
  NS_IMETHOD SetOnsettingchange(nsIDOMEventListener *aOnsettingchange) { return _to SetOnsettingchange(aOnsettingchange); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSETTINGSMANAGER(_to) \
  NS_IMETHOD CreateLock(nsIDOMSettingsLock * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateLock(_retval); } \
  NS_IMETHOD AddObserver(const nsAString & name, const JS::Value & callback) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddObserver(name, callback); } \
  NS_IMETHOD RemoveObserver(const nsAString & name, const JS::Value & callback) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveObserver(name, callback); } \
  NS_IMETHOD GetOnsettingchange(nsIDOMEventListener * *aOnsettingchange) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnsettingchange(aOnsettingchange); } \
  NS_IMETHOD SetOnsettingchange(nsIDOMEventListener *aOnsettingchange) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnsettingchange(aOnsettingchange); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSettingsManager : public nsIDOMSettingsManager
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSETTINGSMANAGER

  nsDOMSettingsManager();

private:
  ~nsDOMSettingsManager();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSettingsManager, nsIDOMSettingsManager)

nsDOMSettingsManager::nsDOMSettingsManager()
{
  /* member initializers and constructor code */
}

nsDOMSettingsManager::~nsDOMSettingsManager()
{
  /* destructor code */
}

/* nsIDOMSettingsLock createLock (); */
NS_IMETHODIMP nsDOMSettingsManager::CreateLock(nsIDOMSettingsLock * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addObserver (in DOMString name, in jsval callback); */
NS_IMETHODIMP nsDOMSettingsManager::AddObserver(const nsAString & name, const JS::Value & callback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeObserver (in DOMString name, in jsval callback); */
NS_IMETHODIMP nsDOMSettingsManager::RemoveObserver(const nsAString & name, const JS::Value & callback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDOMEventListener onsettingchange; */
NS_IMETHODIMP nsDOMSettingsManager::GetOnsettingchange(nsIDOMEventListener * *aOnsettingchange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSettingsManager::SetOnsettingchange(nsIDOMEventListener *aOnsettingchange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSettingsManager_h__ */
