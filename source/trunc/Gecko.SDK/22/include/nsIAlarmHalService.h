/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/alarm/nsIAlarmHalService.idl
 */

#ifndef __gen_nsIAlarmHalService_h__
#define __gen_nsIAlarmHalService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIAlarmFiredCb */
#define NS_IALARMFIREDCB_IID_STR "9f3ed2c0-aed9-11e1-8c3d-5310bd393466"

#define NS_IALARMFIREDCB_IID \
  {0x9f3ed2c0, 0xaed9, 0x11e1, \
    { 0x8c, 0x3d, 0x53, 0x10, 0xbd, 0x39, 0x34, 0x66 }}

class NS_NO_VTABLE nsIAlarmFiredCb : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IALARMFIREDCB_IID)

  /* void onAlarmFired (); */
  NS_IMETHOD OnAlarmFired(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAlarmFiredCb, NS_IALARMFIREDCB_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIALARMFIREDCB \
  NS_IMETHOD OnAlarmFired(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIALARMFIREDCB(_to) \
  NS_IMETHOD OnAlarmFired(void) { return _to OnAlarmFired(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIALARMFIREDCB(_to) \
  NS_IMETHOD OnAlarmFired(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnAlarmFired(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAlarmFiredCb : public nsIAlarmFiredCb
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIALARMFIREDCB

  nsAlarmFiredCb();

private:
  ~nsAlarmFiredCb();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAlarmFiredCb, nsIAlarmFiredCb)

nsAlarmFiredCb::nsAlarmFiredCb()
{
  /* member initializers and constructor code */
}

nsAlarmFiredCb::~nsAlarmFiredCb()
{
  /* destructor code */
}

/* void onAlarmFired (); */
NS_IMETHODIMP nsAlarmFiredCb::OnAlarmFired()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsITimezoneChangedCb */
#define NS_ITIMEZONECHANGEDCB_IID_STR "0ca52e84-ba8f-11e1-87e8-63235527db9e"

#define NS_ITIMEZONECHANGEDCB_IID \
  {0x0ca52e84, 0xba8f, 0x11e1, \
    { 0x87, 0xe8, 0x63, 0x23, 0x55, 0x27, 0xdb, 0x9e }}

class NS_NO_VTABLE nsITimezoneChangedCb : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITIMEZONECHANGEDCB_IID)

  /* void onTimezoneChanged (in int32_t aTimezoneOffset); */
  NS_IMETHOD OnTimezoneChanged(int32_t aTimezoneOffset) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITimezoneChangedCb, NS_ITIMEZONECHANGEDCB_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITIMEZONECHANGEDCB \
  NS_IMETHOD OnTimezoneChanged(int32_t aTimezoneOffset); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITIMEZONECHANGEDCB(_to) \
  NS_IMETHOD OnTimezoneChanged(int32_t aTimezoneOffset) { return _to OnTimezoneChanged(aTimezoneOffset); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITIMEZONECHANGEDCB(_to) \
  NS_IMETHOD OnTimezoneChanged(int32_t aTimezoneOffset) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnTimezoneChanged(aTimezoneOffset); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTimezoneChangedCb : public nsITimezoneChangedCb
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITIMEZONECHANGEDCB

  nsTimezoneChangedCb();

private:
  ~nsTimezoneChangedCb();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsTimezoneChangedCb, nsITimezoneChangedCb)

nsTimezoneChangedCb::nsTimezoneChangedCb()
{
  /* member initializers and constructor code */
}

nsTimezoneChangedCb::~nsTimezoneChangedCb()
{
  /* destructor code */
}

/* void onTimezoneChanged (in int32_t aTimezoneOffset); */
NS_IMETHODIMP nsTimezoneChangedCb::OnTimezoneChanged(int32_t aTimezoneOffset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_ALARMHALSERVICE_CID { 0x7dafea4c, 0x7163, 0x4b70, { 0x95, 0x4e, 0x5a, 0xd4, 0x09, 0x94, 0x83, 0xd7 } }
#define ALARMHALSERVICE_CONTRACTID "@mozilla.org/alarmHalService;1"

/* starting interface:    nsIAlarmHalService */
#define NS_IALARMHALSERVICE_IID_STR "057b1ee4-f696-486d-bd55-205e21e88fab"

#define NS_IALARMHALSERVICE_IID \
  {0x057b1ee4, 0xf696, 0x486d, \
    { 0xbd, 0x55, 0x20, 0x5e, 0x21, 0xe8, 0x8f, 0xab }}

class NS_NO_VTABLE nsIAlarmHalService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IALARMHALSERVICE_IID)

  /* bool setAlarm (in int32_t aSeconds, in int32_t aNanoseconds); */
  NS_IMETHOD SetAlarm(int32_t aSeconds, int32_t aNanoseconds, bool *_retval) = 0;

  /* void setAlarmFiredCb (in nsIAlarmFiredCb aAlarmFiredCb); */
  NS_IMETHOD SetAlarmFiredCb(nsIAlarmFiredCb *aAlarmFiredCb) = 0;

  /* void setTimezoneChangedCb (in nsITimezoneChangedCb aTimezoneChangedCb); */
  NS_IMETHOD SetTimezoneChangedCb(nsITimezoneChangedCb *aTimezoneChangedCb) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAlarmHalService, NS_IALARMHALSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIALARMHALSERVICE \
  NS_IMETHOD SetAlarm(int32_t aSeconds, int32_t aNanoseconds, bool *_retval); \
  NS_IMETHOD SetAlarmFiredCb(nsIAlarmFiredCb *aAlarmFiredCb); \
  NS_IMETHOD SetTimezoneChangedCb(nsITimezoneChangedCb *aTimezoneChangedCb); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIALARMHALSERVICE(_to) \
  NS_IMETHOD SetAlarm(int32_t aSeconds, int32_t aNanoseconds, bool *_retval) { return _to SetAlarm(aSeconds, aNanoseconds, _retval); } \
  NS_IMETHOD SetAlarmFiredCb(nsIAlarmFiredCb *aAlarmFiredCb) { return _to SetAlarmFiredCb(aAlarmFiredCb); } \
  NS_IMETHOD SetTimezoneChangedCb(nsITimezoneChangedCb *aTimezoneChangedCb) { return _to SetTimezoneChangedCb(aTimezoneChangedCb); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIALARMHALSERVICE(_to) \
  NS_IMETHOD SetAlarm(int32_t aSeconds, int32_t aNanoseconds, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAlarm(aSeconds, aNanoseconds, _retval); } \
  NS_IMETHOD SetAlarmFiredCb(nsIAlarmFiredCb *aAlarmFiredCb) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAlarmFiredCb(aAlarmFiredCb); } \
  NS_IMETHOD SetTimezoneChangedCb(nsITimezoneChangedCb *aTimezoneChangedCb) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTimezoneChangedCb(aTimezoneChangedCb); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAlarmHalService : public nsIAlarmHalService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIALARMHALSERVICE

  nsAlarmHalService();

private:
  ~nsAlarmHalService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAlarmHalService, nsIAlarmHalService)

nsAlarmHalService::nsAlarmHalService()
{
  /* member initializers and constructor code */
}

nsAlarmHalService::~nsAlarmHalService()
{
  /* destructor code */
}

/* bool setAlarm (in int32_t aSeconds, in int32_t aNanoseconds); */
NS_IMETHODIMP nsAlarmHalService::SetAlarm(int32_t aSeconds, int32_t aNanoseconds, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAlarmFiredCb (in nsIAlarmFiredCb aAlarmFiredCb); */
NS_IMETHODIMP nsAlarmHalService::SetAlarmFiredCb(nsIAlarmFiredCb *aAlarmFiredCb)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setTimezoneChangedCb (in nsITimezoneChangedCb aTimezoneChangedCb); */
NS_IMETHODIMP nsAlarmHalService::SetTimezoneChangedCb(nsITimezoneChangedCb *aTimezoneChangedCb)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAlarmHalService_h__ */
