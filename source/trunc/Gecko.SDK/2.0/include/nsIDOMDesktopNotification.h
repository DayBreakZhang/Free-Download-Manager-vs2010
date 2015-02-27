/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/dom/interfaces/notification/nsIDOMDesktopNotification.idl
 */

#ifndef __gen_nsIDOMDesktopNotification_h__
#define __gen_nsIDOMDesktopNotification_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMEventListener; /* forward declaration */

class nsIDOMDesktopNotification; /* forward declaration */


/* starting interface:    nsIDOMDesktopNotificationCenter */
#define NS_IDOMDESKTOPNOTIFICATIONCENTER_IID_STR "ccea6185-0a3d-45ab-9058-1004dd4b8c50"

#define NS_IDOMDESKTOPNOTIFICATIONCENTER_IID \
  {0xccea6185, 0x0a3d, 0x45ab, \
    { 0x90, 0x58, 0x10, 0x04, 0xdd, 0x4b, 0x8c, 0x50 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMDesktopNotificationCenter : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMDESKTOPNOTIFICATIONCENTER_IID)

  /* nsIDOMDesktopNotification createNotification (in DOMString title, in DOMString description, [optional] in DOMString iconURL); */
  NS_SCRIPTABLE NS_IMETHOD CreateNotification(const nsAString & title, const nsAString & description, const nsAString & iconURL, nsIDOMDesktopNotification **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMDesktopNotificationCenter, NS_IDOMDESKTOPNOTIFICATIONCENTER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMDESKTOPNOTIFICATIONCENTER \
  NS_SCRIPTABLE NS_IMETHOD CreateNotification(const nsAString & title, const nsAString & description, const nsAString & iconURL, nsIDOMDesktopNotification **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMDESKTOPNOTIFICATIONCENTER(_to) \
  NS_SCRIPTABLE NS_IMETHOD CreateNotification(const nsAString & title, const nsAString & description, const nsAString & iconURL, nsIDOMDesktopNotification **_retval NS_OUTPARAM) { return _to CreateNotification(title, description, iconURL, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMDESKTOPNOTIFICATIONCENTER(_to) \
  NS_SCRIPTABLE NS_IMETHOD CreateNotification(const nsAString & title, const nsAString & description, const nsAString & iconURL, nsIDOMDesktopNotification **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateNotification(title, description, iconURL, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMDesktopNotificationCenter : public nsIDOMDesktopNotificationCenter
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMDESKTOPNOTIFICATIONCENTER

  nsDOMDesktopNotificationCenter();

private:
  ~nsDOMDesktopNotificationCenter();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMDesktopNotificationCenter, nsIDOMDesktopNotificationCenter)

nsDOMDesktopNotificationCenter::nsDOMDesktopNotificationCenter()
{
  /* member initializers and constructor code */
}

nsDOMDesktopNotificationCenter::~nsDOMDesktopNotificationCenter()
{
  /* destructor code */
}

/* nsIDOMDesktopNotification createNotification (in DOMString title, in DOMString description, [optional] in DOMString iconURL); */
NS_IMETHODIMP nsDOMDesktopNotificationCenter::CreateNotification(const nsAString & title, const nsAString & description, const nsAString & iconURL, nsIDOMDesktopNotification **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMDesktopNotification */
#define NS_IDOMDESKTOPNOTIFICATION_IID_STR "9131fd07-a7db-4b3a-a98b-6d9f3746682f"

#define NS_IDOMDESKTOPNOTIFICATION_IID \
  {0x9131fd07, 0xa7db, 0x4b3a, \
    { 0xa9, 0x8b, 0x6d, 0x9f, 0x37, 0x46, 0x68, 0x2f }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMDesktopNotification : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMDESKTOPNOTIFICATION_IID)

  /* void show (); */
  NS_SCRIPTABLE NS_IMETHOD Show(void) = 0;

  /* attribute nsIDOMEventListener onclick; */
  NS_SCRIPTABLE NS_IMETHOD GetOnclick(nsIDOMEventListener **aOnclick) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetOnclick(nsIDOMEventListener *aOnclick) = 0;

  /* attribute nsIDOMEventListener onclose; */
  NS_SCRIPTABLE NS_IMETHOD GetOnclose(nsIDOMEventListener **aOnclose) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetOnclose(nsIDOMEventListener *aOnclose) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMDesktopNotification, NS_IDOMDESKTOPNOTIFICATION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMDESKTOPNOTIFICATION \
  NS_SCRIPTABLE NS_IMETHOD Show(void); \
  NS_SCRIPTABLE NS_IMETHOD GetOnclick(nsIDOMEventListener **aOnclick); \
  NS_SCRIPTABLE NS_IMETHOD SetOnclick(nsIDOMEventListener *aOnclick); \
  NS_SCRIPTABLE NS_IMETHOD GetOnclose(nsIDOMEventListener **aOnclose); \
  NS_SCRIPTABLE NS_IMETHOD SetOnclose(nsIDOMEventListener *aOnclose); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMDESKTOPNOTIFICATION(_to) \
  NS_SCRIPTABLE NS_IMETHOD Show(void) { return _to Show(); } \
  NS_SCRIPTABLE NS_IMETHOD GetOnclick(nsIDOMEventListener **aOnclick) { return _to GetOnclick(aOnclick); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnclick(nsIDOMEventListener *aOnclick) { return _to SetOnclick(aOnclick); } \
  NS_SCRIPTABLE NS_IMETHOD GetOnclose(nsIDOMEventListener **aOnclose) { return _to GetOnclose(aOnclose); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnclose(nsIDOMEventListener *aOnclose) { return _to SetOnclose(aOnclose); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMDESKTOPNOTIFICATION(_to) \
  NS_SCRIPTABLE NS_IMETHOD Show(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Show(); } \
  NS_SCRIPTABLE NS_IMETHOD GetOnclick(nsIDOMEventListener **aOnclick) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnclick(aOnclick); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnclick(nsIDOMEventListener *aOnclick) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnclick(aOnclick); } \
  NS_SCRIPTABLE NS_IMETHOD GetOnclose(nsIDOMEventListener **aOnclose) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnclose(aOnclose); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnclose(nsIDOMEventListener *aOnclose) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnclose(aOnclose); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMDesktopNotification : public nsIDOMDesktopNotification
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMDESKTOPNOTIFICATION

  nsDOMDesktopNotification();

private:
  ~nsDOMDesktopNotification();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMDesktopNotification, nsIDOMDesktopNotification)

nsDOMDesktopNotification::nsDOMDesktopNotification()
{
  /* member initializers and constructor code */
}

nsDOMDesktopNotification::~nsDOMDesktopNotification()
{
  /* destructor code */
}

/* void show (); */
NS_IMETHODIMP nsDOMDesktopNotification::Show()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDOMEventListener onclick; */
NS_IMETHODIMP nsDOMDesktopNotification::GetOnclick(nsIDOMEventListener **aOnclick)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMDesktopNotification::SetOnclick(nsIDOMEventListener *aOnclick)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDOMEventListener onclose; */
NS_IMETHODIMP nsDOMDesktopNotification::GetOnclose(nsIDOMEventListener **aOnclose)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMDesktopNotification::SetOnclose(nsIDOMEventListener *aOnclose)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMDesktopNotification_h__ */
