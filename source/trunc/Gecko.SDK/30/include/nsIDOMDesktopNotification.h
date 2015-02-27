/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMDesktopNotification.idl
 */

#ifndef __gen_nsIDOMDesktopNotification_h__
#define __gen_nsIDOMDesktopNotification_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIObserver; /* forward declaration */


/* starting interface:    nsIAppNotificationService */
#define NS_IAPPNOTIFICATIONSERVICE_IID_STR "50cb17d2-dc8a-4aa6-bcd3-94d76af14e20"

#define NS_IAPPNOTIFICATIONSERVICE_IID \
  {0x50cb17d2, 0xdc8a, 0x4aa6, \
    { 0xbc, 0xd3, 0x94, 0xd7, 0x6a, 0xf1, 0x4e, 0x20 }}

class NS_NO_VTABLE nsIAppNotificationService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IAPPNOTIFICATIONSERVICE_IID)

  /* void showAppNotification (in AString imageUrl, in AString title, in AString text, in nsIObserver alertListener, in jsval details); */
  NS_IMETHOD ShowAppNotification(const nsAString & imageUrl, const nsAString & title, const nsAString & text, nsIObserver *alertListener, JS::HandleValue details) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAppNotificationService, NS_IAPPNOTIFICATIONSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIAPPNOTIFICATIONSERVICE \
  NS_IMETHOD ShowAppNotification(const nsAString & imageUrl, const nsAString & title, const nsAString & text, nsIObserver *alertListener, JS::HandleValue details); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIAPPNOTIFICATIONSERVICE(_to) \
  NS_IMETHOD ShowAppNotification(const nsAString & imageUrl, const nsAString & title, const nsAString & text, nsIObserver *alertListener, JS::HandleValue details) { return _to ShowAppNotification(imageUrl, title, text, alertListener, details); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIAPPNOTIFICATIONSERVICE(_to) \
  NS_IMETHOD ShowAppNotification(const nsAString & imageUrl, const nsAString & title, const nsAString & text, nsIObserver *alertListener, JS::HandleValue details) { return !_to ? NS_ERROR_NULL_POINTER : _to->ShowAppNotification(imageUrl, title, text, alertListener, details); } 

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

/* void showAppNotification (in AString imageUrl, in AString title, in AString text, in nsIObserver alertListener, in jsval details); */
NS_IMETHODIMP nsAppNotificationService::ShowAppNotification(const nsAString & imageUrl, const nsAString & title, const nsAString & text, nsIObserver *alertListener, JS::HandleValue details)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMDesktopNotification_h__ */
