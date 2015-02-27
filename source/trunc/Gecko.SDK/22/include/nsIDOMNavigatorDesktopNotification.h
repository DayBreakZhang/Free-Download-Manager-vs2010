/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/notification/nsIDOMNavigatorDesktopNotification.idl
 */

#ifndef __gen_nsIDOMNavigatorDesktopNotification_h__
#define __gen_nsIDOMNavigatorDesktopNotification_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMDesktopNotificationCenter; /* forward declaration */


/* starting interface:    nsIDOMNavigatorDesktopNotification */
#define NS_IDOMNAVIGATORDESKTOPNOTIFICATION_IID_STR "ec2e6e4f-2f65-439c-b6c6-27e89b03b348"

#define NS_IDOMNAVIGATORDESKTOPNOTIFICATION_IID \
  {0xec2e6e4f, 0x2f65, 0x439c, \
    { 0xb6, 0xc6, 0x27, 0xe8, 0x9b, 0x03, 0xb3, 0x48 }}

class NS_NO_VTABLE nsIDOMNavigatorDesktopNotification : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMNAVIGATORDESKTOPNOTIFICATION_IID)

  /* readonly attribute nsIDOMDesktopNotificationCenter mozNotification; */
  NS_IMETHOD GetMozNotification(nsIDOMDesktopNotificationCenter * *aMozNotification) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMNavigatorDesktopNotification, NS_IDOMNAVIGATORDESKTOPNOTIFICATION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMNAVIGATORDESKTOPNOTIFICATION \
  NS_IMETHOD GetMozNotification(nsIDOMDesktopNotificationCenter * *aMozNotification); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMNAVIGATORDESKTOPNOTIFICATION(_to) \
  NS_IMETHOD GetMozNotification(nsIDOMDesktopNotificationCenter * *aMozNotification) { return _to GetMozNotification(aMozNotification); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMNAVIGATORDESKTOPNOTIFICATION(_to) \
  NS_IMETHOD GetMozNotification(nsIDOMDesktopNotificationCenter * *aMozNotification) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozNotification(aMozNotification); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMNavigatorDesktopNotification : public nsIDOMNavigatorDesktopNotification
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMNAVIGATORDESKTOPNOTIFICATION

  nsDOMNavigatorDesktopNotification();

private:
  ~nsDOMNavigatorDesktopNotification();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMNavigatorDesktopNotification, nsIDOMNavigatorDesktopNotification)

nsDOMNavigatorDesktopNotification::nsDOMNavigatorDesktopNotification()
{
  /* member initializers and constructor code */
}

nsDOMNavigatorDesktopNotification::~nsDOMNavigatorDesktopNotification()
{
  /* destructor code */
}

/* readonly attribute nsIDOMDesktopNotificationCenter mozNotification; */
NS_IMETHODIMP nsDOMNavigatorDesktopNotification::GetMozNotification(nsIDOMDesktopNotificationCenter * *aMozNotification)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMNavigatorDesktopNotification_h__ */
