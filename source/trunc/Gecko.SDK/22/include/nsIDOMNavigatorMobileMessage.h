/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/mobilemessage/interfaces/nsIDOMNavigatorMobileMessage.idl
 */

#ifndef __gen_nsIDOMNavigatorMobileMessage_h__
#define __gen_nsIDOMNavigatorMobileMessage_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMMozMobileMessageManager; /* forward declaration */


/* starting interface:    nsIDOMMozNavigatorMobileMessage */
#define NS_IDOMMOZNAVIGATORMOBILEMESSAGE_IID_STR "baefbb1a-7fe4-11e2-abff-cf1a90f9139f"

#define NS_IDOMMOZNAVIGATORMOBILEMESSAGE_IID \
  {0xbaefbb1a, 0x7fe4, 0x11e2, \
    { 0xab, 0xff, 0xcf, 0x1a, 0x90, 0xf9, 0x13, 0x9f }}

class NS_NO_VTABLE nsIDOMMozNavigatorMobileMessage : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMMOZNAVIGATORMOBILEMESSAGE_IID)

  /* readonly attribute nsIDOMMozMobileMessageManager mozMobileMessage; */
  NS_IMETHOD GetMozMobileMessage(nsIDOMMozMobileMessageManager * *aMozMobileMessage) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMMozNavigatorMobileMessage, NS_IDOMMOZNAVIGATORMOBILEMESSAGE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMMOZNAVIGATORMOBILEMESSAGE \
  NS_IMETHOD GetMozMobileMessage(nsIDOMMozMobileMessageManager * *aMozMobileMessage); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMMOZNAVIGATORMOBILEMESSAGE(_to) \
  NS_IMETHOD GetMozMobileMessage(nsIDOMMozMobileMessageManager * *aMozMobileMessage) { return _to GetMozMobileMessage(aMozMobileMessage); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMMOZNAVIGATORMOBILEMESSAGE(_to) \
  NS_IMETHOD GetMozMobileMessage(nsIDOMMozMobileMessageManager * *aMozMobileMessage) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozMobileMessage(aMozMobileMessage); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMMozNavigatorMobileMessage : public nsIDOMMozNavigatorMobileMessage
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMMOZNAVIGATORMOBILEMESSAGE

  nsDOMMozNavigatorMobileMessage();

private:
  ~nsDOMMozNavigatorMobileMessage();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMMozNavigatorMobileMessage, nsIDOMMozNavigatorMobileMessage)

nsDOMMozNavigatorMobileMessage::nsDOMMozNavigatorMobileMessage()
{
  /* member initializers and constructor code */
}

nsDOMMozNavigatorMobileMessage::~nsDOMMozNavigatorMobileMessage()
{
  /* destructor code */
}

/* readonly attribute nsIDOMMozMobileMessageManager mozMobileMessage; */
NS_IMETHODIMP nsDOMMozNavigatorMobileMessage::GetMozMobileMessage(nsIDOMMozMobileMessageManager * *aMozMobileMessage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMNavigatorMobileMessage_h__ */
