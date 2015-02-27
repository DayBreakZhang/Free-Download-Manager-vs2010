/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIWebVTTListener.idl
 */

#ifndef __gen_nsIWebVTTListener_h__
#define __gen_nsIWebVTTListener_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIWebVTTListener */
#define NS_IWEBVTTLISTENER_IID_STR "2953cf08-403e-4419-8d20-ce286aac026b"

#define NS_IWEBVTTLISTENER_IID \
  {0x2953cf08, 0x403e, 0x4419, \
    { 0x8d, 0x20, 0xce, 0x28, 0x6a, 0xac, 0x02, 0x6b }}

class NS_NO_VTABLE nsIWebVTTListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IWEBVTTLISTENER_IID)

  /* [implicit_jscontext] void onCue (in jsval cue); */
  NS_IMETHOD OnCue(JS::HandleValue cue, JSContext* cx) = 0;

  /* [implicit_jscontext] void onRegion (in jsval region); */
  NS_IMETHOD OnRegion(JS::HandleValue region, JSContext* cx) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIWebVTTListener, NS_IWEBVTTLISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIWEBVTTLISTENER \
  NS_IMETHOD OnCue(JS::HandleValue cue, JSContext* cx); \
  NS_IMETHOD OnRegion(JS::HandleValue region, JSContext* cx); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIWEBVTTLISTENER(_to) \
  NS_IMETHOD OnCue(JS::HandleValue cue, JSContext* cx) { return _to OnCue(cue, cx); } \
  NS_IMETHOD OnRegion(JS::HandleValue region, JSContext* cx) { return _to OnRegion(region, cx); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIWEBVTTLISTENER(_to) \
  NS_IMETHOD OnCue(JS::HandleValue cue, JSContext* cx) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnCue(cue, cx); } \
  NS_IMETHOD OnRegion(JS::HandleValue region, JSContext* cx) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnRegion(region, cx); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsWebVTTListener : public nsIWebVTTListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWEBVTTLISTENER

  nsWebVTTListener();

private:
  ~nsWebVTTListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsWebVTTListener, nsIWebVTTListener)

nsWebVTTListener::nsWebVTTListener()
{
  /* member initializers and constructor code */
}

nsWebVTTListener::~nsWebVTTListener()
{
  /* destructor code */
}

/* [implicit_jscontext] void onCue (in jsval cue); */
NS_IMETHODIMP nsWebVTTListener::OnCue(JS::HandleValue cue, JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] void onRegion (in jsval region); */
NS_IMETHODIMP nsWebVTTListener::OnRegion(JS::HandleValue region, JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIWebVTTListener_h__ */
