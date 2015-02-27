/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/js/xpconnect/idl/nsIJSEngineTelemetryStats.idl
 */

#ifndef __gen_nsIJSEngineTelemetryStats_h__
#define __gen_nsIJSEngineTelemetryStats_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIJSEngineTelemetryStats */
#define NS_IJSENGINETELEMETRYSTATS_IID_STR "5a6ea52b-4e23-402f-93e3-59f29b2f1a88"

#define NS_IJSENGINETELEMETRYSTATS_IID \
  {0x5a6ea52b, 0x4e23, 0x402f, \
    { 0x93, 0xe3, 0x59, 0xf2, 0x9b, 0x2f, 0x1a, 0x88 }}

class NS_NO_VTABLE nsIJSEngineTelemetryStats : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IJSENGINETELEMETRYSTATS_IID)

  /* [implicit_jscontext] readonly attribute jsval telemetryValue; */
  NS_IMETHOD GetTelemetryValue(JSContext* cx, JS::Value *aTelemetryValue) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIJSEngineTelemetryStats, NS_IJSENGINETELEMETRYSTATS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIJSENGINETELEMETRYSTATS \
  NS_IMETHOD GetTelemetryValue(JSContext* cx, JS::Value *aTelemetryValue); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIJSENGINETELEMETRYSTATS(_to) \
  NS_IMETHOD GetTelemetryValue(JSContext* cx, JS::Value *aTelemetryValue) { return _to GetTelemetryValue(cx, aTelemetryValue); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIJSENGINETELEMETRYSTATS(_to) \
  NS_IMETHOD GetTelemetryValue(JSContext* cx, JS::Value *aTelemetryValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTelemetryValue(cx, aTelemetryValue); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsJSEngineTelemetryStats : public nsIJSEngineTelemetryStats
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIJSENGINETELEMETRYSTATS

  nsJSEngineTelemetryStats();

private:
  ~nsJSEngineTelemetryStats();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsJSEngineTelemetryStats, nsIJSEngineTelemetryStats)

nsJSEngineTelemetryStats::nsJSEngineTelemetryStats()
{
  /* member initializers and constructor code */
}

nsJSEngineTelemetryStats::~nsJSEngineTelemetryStats()
{
  /* destructor code */
}

/* [implicit_jscontext] readonly attribute jsval telemetryValue; */
NS_IMETHODIMP nsJSEngineTelemetryStats::GetTelemetryValue(JSContext* cx, JS::Value *aTelemetryValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIJSEngineTelemetryStats_h__ */
