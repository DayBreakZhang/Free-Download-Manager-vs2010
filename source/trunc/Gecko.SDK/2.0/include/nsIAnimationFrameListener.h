/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/dom/interfaces/base/nsIAnimationFrameListener.idl
 */

#ifndef __gen_nsIAnimationFrameListener_h__
#define __gen_nsIAnimationFrameListener_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIAnimationFrameListener */
#define NS_IANIMATIONFRAMELISTENER_IID_STR "ba240e38-c15a-4fb2-802a-8a48f09331bd"

#define NS_IANIMATIONFRAMELISTENER_IID \
  {0xba240e38, 0xc15a, 0x4fb2, \
    { 0x80, 0x2a, 0x8a, 0x48, 0xf0, 0x93, 0x31, 0xbd }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIAnimationFrameListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IANIMATIONFRAMELISTENER_IID)

  /**
   * The timestamp is the same as it would be for the a corresponding
   * MozBeforePaint event.
   */
  /* void onBeforePaint (in DOMTimeStamp timeStamp); */
  NS_SCRIPTABLE NS_IMETHOD OnBeforePaint(DOMTimeStamp timeStamp) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAnimationFrameListener, NS_IANIMATIONFRAMELISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIANIMATIONFRAMELISTENER \
  NS_SCRIPTABLE NS_IMETHOD OnBeforePaint(DOMTimeStamp timeStamp); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIANIMATIONFRAMELISTENER(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnBeforePaint(DOMTimeStamp timeStamp) { return _to OnBeforePaint(timeStamp); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIANIMATIONFRAMELISTENER(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnBeforePaint(DOMTimeStamp timeStamp) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnBeforePaint(timeStamp); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAnimationFrameListener : public nsIAnimationFrameListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIANIMATIONFRAMELISTENER

  nsAnimationFrameListener();

private:
  ~nsAnimationFrameListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAnimationFrameListener, nsIAnimationFrameListener)

nsAnimationFrameListener::nsAnimationFrameListener()
{
  /* member initializers and constructor code */
}

nsAnimationFrameListener::~nsAnimationFrameListener()
{
  /* destructor code */
}

/* void onBeforePaint (in DOMTimeStamp timeStamp); */
NS_IMETHODIMP nsAnimationFrameListener::OnBeforePaint(DOMTimeStamp timeStamp)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAnimationFrameListener_h__ */
