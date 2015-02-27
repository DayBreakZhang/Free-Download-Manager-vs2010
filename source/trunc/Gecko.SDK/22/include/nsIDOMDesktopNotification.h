/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/notification/nsIDOMDesktopNotification.idl
 */

#ifndef __gen_nsIDOMDesktopNotification_h__
#define __gen_nsIDOMDesktopNotification_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMEventListener; /* forward declaration */

class nsIDOMDesktopNotification; /* forward declaration */

class nsIObserver; /* forward declaration */


/* starting interface:    nsIDOMDesktopNotificationCenter */
#define NS_IDOMDESKTOPNOTIFICATIONCENTER_IID_STR "ccea6185-0a3d-45ab-9058-1004dd4b8c50"

#define NS_IDOMDESKTOPNOTIFICATIONCENTER_IID \
  {0xccea6185, 0x0a3d, 0x45ab, \
    { 0x90, 0x58, 0x10, 0x04, 0xdd, 0x4b, 0x8c, 0x50 }}

class NS_NO_VTABLE nsIDOMDesktopNotificationCenter : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMDESKTOPNOTIFICATIONCENTER_IID)

  /* nsIDOMDesktopNotification createNotification (in DOMString title, in DOMString description, [optional] in DOMString iconURL); */
  NS_IMETHOD CreateNotification(const nsAString & title, const nsAString & description, const nsAString & iconURL, nsIDOMDesktopNotification * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMDesktopNotificationCenter, NS_IDOMDESKTOPNOTIFICATIONCENTER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMDESKTOPNOTIFICATIONCENTER \
  NS_IMETHOD CreateNotification(const nsAString & title, const nsAString & description, const nsAString & iconURL, nsIDOMDesktopNotification * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMDESKTOPNOTIFICATIONCENTER(_to) \
  NS_IMETHOD CreateNotification(const nsAString & title, const nsAString & description, const nsAString & iconURL, nsIDOMDesktopNotification * *_retval) { return _to CreateNotification(title, description, iconURL, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMDESKTOPNOTIFICATIONCENTER(_to) \
  NS_IMETHOD CreateNotification(const nsAString & title, const nsAString & description, const nsAString & iconURL, nsIDOMDesktopNotification * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateNotification(title, description, iconURL, _retval); } 

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
NS_IMETHODIMP nsDOMDesktopNotificationCenter::CreateNotification(const nsAString & title, const nsAString & description, const nsAString & iconURL, nsIDOMDesktopNotification * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMDesktopNotification */
#define NS_IDOMDESKTOPNOTIFICATION_IID_STR "77bc6adc-77d6-4b29-9844-7eaac25e995d"

#define NS_IDOMDESKTOPNOTIFICATION_IID \
  {0x77bc6adc, 0x77d6, 0x4b29, \
    { 0x98, 0x44, 0x7e, 0xaa, 0xc2, 0x5e, 0x99, 0x5d }}

class NS_NO_VTABLE nsIDOMDesktopNotification : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMDESKTOPNOTIFICATION_IID)

  /* void show (); */
  NS_IMETHOD Show(void) = 0;

  /* [implicit_jscontext] attribute jsval onclick; */
  NS_IMETHOD GetOnclick(JSContext* cx, JS::Value *aOnclick) = 0;
  NS_IMETHOD SetOnclick(JSContext* cx, const JS::Value & aOnclick) = 0;

  /* [implicit_jscontext] attribute jsval onclose; */
  NS_IMETHOD GetOnclose(JSContext* cx, JS::Value *aOnclose) = 0;
  NS_IMETHOD SetOnclose(JSContext* cx, const JS::Value & aOnclose) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMDesktopNotification, NS_IDOMDESKTOPNOTIFICATION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMDESKTOPNOTIFICATION \
  NS_IMETHOD Show(void); \
  NS_IMETHOD GetOnclick(JSContext* cx, JS::Value *aOnclick); \
  NS_IMETHOD SetOnclick(JSContext* cx, const JS::Value & aOnclick); \
  NS_IMETHOD GetOnclose(JSContext* cx, JS::Value *aOnclose); \
  NS_IMETHOD SetOnclose(JSContext* cx, const JS::Value & aOnclose); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMDESKTOPNOTIFICATION(_to) \
  NS_IMETHOD Show(void) { return _to Show(); } \
  NS_IMETHOD GetOnclick(JSContext* cx, JS::Value *aOnclick) { return _to GetOnclick(cx, aOnclick); } \
  NS_IMETHOD SetOnclick(JSContext* cx, const JS::Value & aOnclick) { return _to SetOnclick(cx, aOnclick); } \
  NS_IMETHOD GetOnclose(JSContext* cx, JS::Value *aOnclose) { return _to GetOnclose(cx, aOnclose); } \
  NS_IMETHOD SetOnclose(JSContext* cx, const JS::Value & aOnclose) { return _to SetOnclose(cx, aOnclose); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMDESKTOPNOTIFICATION(_to) \
  NS_IMETHOD Show(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Show(); } \
  NS_IMETHOD GetOnclick(JSContext* cx, JS::Value *aOnclick) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnclick(cx, aOnclick); } \
  NS_IMETHOD SetOnclick(JSContext* cx, const JS::Value & aOnclick) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnclick(cx, aOnclick); } \
  NS_IMETHOD GetOnclose(JSContext* cx, JS::Value *aOnclose) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnclose(cx, aOnclose); } \
  NS_IMETHOD SetOnclose(JSContext* cx, const JS::Value & aOnclose) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnclose(cx, aOnclose); } 

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

/* [implicit_jscontext] attribute jsval onclick; */
NS_IMETHODIMP nsDOMDesktopNotification::GetOnclick(JSContext* cx, JS::Value *aOnclick)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMDesktopNotification::SetOnclick(JSContext* cx, const JS::Value & aOnclick)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onclose; */
NS_IMETHODIMP nsDOMDesktopNotification::GetOnclose(JSContext* cx, JS::Value *aOnclose)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMDesktopNotification::SetOnclose(JSContext* cx, const JS::Value & aOnclose)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIAppNotificationService */
#define NS_IAPPNOTIFICATIONSERVICE_IID_STR "7fb4f0f9-ff5b-4620-8e1b-d82d723605af"

#define NS_IAPPNOTIFICATIONSERVICE_IID \
  {0x7fb4f0f9, 0xff5b, 0x4620, \
    { 0x8e, 0x1b, 0xd8, 0x2d, 0x72, 0x36, 0x05, 0xaf }}

class NS_NO_VTABLE nsIAppNotificationService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IAPPNOTIFICATIONSERVICE_IID)

  /* void showAppNotification (in AString imageUrl, in AString title, in AString text, [optional] in boolean textClickable, [optional] in AString manifestURL, [optional] in nsIObserver alertListener); */
  NS_IMETHOD ShowAppNotification(const nsAString & imageUrl, const nsAString & title, const nsAString & text, bool textClickable, const nsAString & manifestURL, nsIObserver *alertListener) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAppNotificationService, NS_IAPPNOTIFICATIONSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIAPPNOTIFICATIONSERVICE \
  NS_IMETHOD ShowAppNotification(const nsAString & imageUrl, const nsAString & title, const nsAString & text, bool textClickable, const nsAString & manifestURL, nsIObserver *alertListener); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIAPPNOTIFICATIONSERVICE(_to) \
  NS_IMETHOD ShowAppNotification(const nsAString & imageUrl, const nsAString & title, const nsAString & text, bool textClickable, const nsAString & manifestURL, nsIObserver *alertListener) { return _to ShowAppNotification(imageUrl, title, text, textClickable, manifestURL, alertListener); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIAPPNOTIFICATIONSERVICE(_to) \
  NS_IMETHOD ShowAppNotification(const nsAString & imageUrl, const nsAString & title, const nsAString & text, bool textClickable, const nsAString & manifestURL, nsIObserver *alertListener) { return !_to ? NS_ERROR_NULL_POINTER : _to->ShowAppNotification(imageUrl, title, text, textClickable, manifestURL, alertListener); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAppNotificationService : public nsIAppNotificationService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIAPPNOTIFICATIONSERVICE

  nsAppNotificationService();

private:
  ~nsAppNotificationService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAppNotificationService, nsIAppNotificationService)

nsAppNotificationService::nsAppNotificationService()
{
  /* member initializers and constructor code */
}

nsAppNotificationService::~nsAppNotificationService()
{
  /* destructor code */
}

/* void showAppNotification (in AString imageUrl, in AString title, in AString text, [optional] in boolean textClickable, [optional] in AString manifestURL, [optional] in nsIObserver alertListener); */
NS_IMETHODIMP nsAppNotificationService::ShowAppNotification(const nsAString & imageUrl, const nsAString & title, const nsAString & text, bool textClickable, const nsAString & manifestURL, nsIObserver *alertListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMDesktopNotification_h__ */
