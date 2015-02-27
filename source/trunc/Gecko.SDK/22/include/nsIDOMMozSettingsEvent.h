/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/settings/nsIDOMMozSettingsEvent.idl
 */

#ifndef __gen_nsIDOMMozSettingsEvent_h__
#define __gen_nsIDOMMozSettingsEvent_h__


#ifndef __gen_nsIDOMEvent_h__
#include "nsIDOMEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIVariant; /* forward declaration */


/* starting interface:    nsIDOMMozSettingsEvent */
#define NS_IDOMMOZSETTINGSEVENT_IID_STR "d5081bf4-6a63-4ee6-8ce6-f488082dc08f"

#define NS_IDOMMOZSETTINGSEVENT_IID \
  {0xd5081bf4, 0x6a63, 0x4ee6, \
    { 0x8c, 0xe6, 0xf4, 0x88, 0x08, 0x2d, 0xc0, 0x8f }}

class NS_NO_VTABLE nsIDOMMozSettingsEvent : public nsIDOMEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMMOZSETTINGSEVENT_IID)

  /* readonly attribute DOMString settingName; */
  NS_IMETHOD GetSettingName(nsAString & aSettingName) = 0;

  /* readonly attribute nsIVariant settingValue; */
  NS_IMETHOD GetSettingValue(nsIVariant * *aSettingValue) = 0;

  /* [noscript] void initMozSettingsEvent (in DOMString aType, in boolean aCanBubble, in boolean aCancelable, in DOMString aSettingName, in nsIVariant aSettingValue); */
  NS_IMETHOD InitMozSettingsEvent(const nsAString & aType, bool aCanBubble, bool aCancelable, const nsAString & aSettingName, nsIVariant *aSettingValue) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMMozSettingsEvent, NS_IDOMMOZSETTINGSEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMMOZSETTINGSEVENT \
  NS_IMETHOD GetSettingName(nsAString & aSettingName); \
  NS_IMETHOD GetSettingValue(nsIVariant * *aSettingValue); \
  NS_IMETHOD InitMozSettingsEvent(const nsAString & aType, bool aCanBubble, bool aCancelable, const nsAString & aSettingName, nsIVariant *aSettingValue); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMMOZSETTINGSEVENT(_to) \
  NS_IMETHOD GetSettingName(nsAString & aSettingName) { return _to GetSettingName(aSettingName); } \
  NS_IMETHOD GetSettingValue(nsIVariant * *aSettingValue) { return _to GetSettingValue(aSettingValue); } \
  NS_IMETHOD InitMozSettingsEvent(const nsAString & aType, bool aCanBubble, bool aCancelable, const nsAString & aSettingName, nsIVariant *aSettingValue) { return _to InitMozSettingsEvent(aType, aCanBubble, aCancelable, aSettingName, aSettingValue); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMMOZSETTINGSEVENT(_to) \
  NS_IMETHOD GetSettingName(nsAString & aSettingName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSettingName(aSettingName); } \
  NS_IMETHOD GetSettingValue(nsIVariant * *aSettingValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSettingValue(aSettingValue); } \
  NS_IMETHOD InitMozSettingsEvent(const nsAString & aType, bool aCanBubble, bool aCancelable, const nsAString & aSettingName, nsIVariant *aSettingValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitMozSettingsEvent(aType, aCanBubble, aCancelable, aSettingName, aSettingValue); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMMozSettingsEvent : public nsIDOMMozSettingsEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMMOZSETTINGSEVENT

  nsDOMMozSettingsEvent();

private:
  ~nsDOMMozSettingsEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMMozSettingsEvent, nsIDOMMozSettingsEvent)

nsDOMMozSettingsEvent::nsDOMMozSettingsEvent()
{
  /* member initializers and constructor code */
}

nsDOMMozSettingsEvent::~nsDOMMozSettingsEvent()
{
  /* destructor code */
}

/* readonly attribute DOMString settingName; */
NS_IMETHODIMP nsDOMMozSettingsEvent::GetSettingName(nsAString & aSettingName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIVariant settingValue; */
NS_IMETHODIMP nsDOMMozSettingsEvent::GetSettingValue(nsIVariant * *aSettingValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void initMozSettingsEvent (in DOMString aType, in boolean aCanBubble, in boolean aCancelable, in DOMString aSettingName, in nsIVariant aSettingValue); */
NS_IMETHODIMP nsDOMMozSettingsEvent::InitMozSettingsEvent(const nsAString & aType, bool aCanBubble, bool aCancelable, const nsAString & aSettingName, nsIVariant *aSettingValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMMozSettingsEvent_h__ */
