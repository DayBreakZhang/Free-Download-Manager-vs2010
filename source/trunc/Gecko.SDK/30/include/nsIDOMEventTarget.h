/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMEventTarget.idl
 */

#ifndef __gen_nsIDOMEventTarget_h__
#define __gen_nsIDOMEventTarget_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#include "mozilla/EventForwards.h"
#include "mozilla/dom/Nullable.h"
#include "js/TypeDecls.h"
using mozilla::dom::Nullable;
namespace mozilla {
class EventListenerManager;
namespace dom {
class EventTarget;
} // namespace dom
} // namespace mozilla
class nsPresContext;
class nsEventChainPreVisitor;
class nsEventChainPostVisitor;
class nsIScriptContext; /* forward declaration */

class nsIDOMEventListener; /* forward declaration */

class nsIDOMEvent; /* forward declaration */


/* starting interface:    nsIDOMEventTarget */
#define NS_IDOMEVENTTARGET_IID_STR "b128448c-7b53-4769-92cb-cd6eafee676c"

#define NS_IDOMEVENTTARGET_IID \
  {0xb128448c, 0x7b53, 0x4769, \
    { 0x92, 0xcb, 0xcd, 0x6e, 0xaf, 0xee, 0x67, 0x6c }}

class nsIDOMEventTarget : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMEVENTTARGET_IID)

  /* [optional_argc] void addEventListener (in DOMString type, in nsIDOMEventListener listener, [optional] in boolean useCapture, [optional] in boolean wantsUntrusted); */
  NS_IMETHOD AddEventListener(const nsAString & type, nsIDOMEventListener *listener, bool useCapture, bool wantsUntrusted, uint8_t _argc) = 0;

  /* [noscript,optional_argc] void addSystemEventListener (in DOMString type, in nsIDOMEventListener listener, [optional] in boolean aUseCapture, [optional] in boolean aWantsUntrusted); */
  NS_IMETHOD AddSystemEventListener(const nsAString & type, nsIDOMEventListener *listener, bool aUseCapture, bool aWantsUntrusted, uint8_t _argc) = 0;

   // non-virtual so it won't affect the vtable
  nsresult AddEventListener(const nsAString& aType,
                            nsIDOMEventListener* aListener,
                            bool aUseCapture)
  {
    return AddEventListener(aType, aListener, aUseCapture, false, 1);
  }
  // non-virtual so it won't affect the vtable
  nsresult AddEventListener(const nsAString& aType,
                            nsIDOMEventListener* aListener,
                            bool aUseCapture,
                            bool aWantsUntrusted)
  {
    return AddEventListener(aType, aListener, aUseCapture, aWantsUntrusted, 2);
  }
  // non-virtual so it won't affect the vtable
  nsresult AddSystemEventListener(const nsAString& aType,
                                  nsIDOMEventListener* aListener,
                                  bool aUseCapture)
  {
    return AddSystemEventListener(aType, aListener, aUseCapture, false, 1);
  }
  // non-virtual so it won't affect the vtable
  nsresult AddSystemEventListener(const nsAString& aType,
                                  nsIDOMEventListener* aListener,
                                  bool aUseCapture,
                                  bool aWantsUntrusted)
  {
    return AddSystemEventListener(aType, aListener, aUseCapture,
                                  aWantsUntrusted, 2);
  }
  /* void removeEventListener (in DOMString type, in nsIDOMEventListener listener, [optional] in boolean useCapture); */
  NS_IMETHOD RemoveEventListener(const nsAString & type, nsIDOMEventListener *listener, bool useCapture) = 0;

  /* [noscript] void removeSystemEventListener (in DOMString type, in nsIDOMEventListener listener, [optional] in boolean aUseCapture); */
  NS_IMETHOD RemoveSystemEventListener(const nsAString & type, nsIDOMEventListener *listener, bool aUseCapture) = 0;

  /* boolean dispatchEvent (in nsIDOMEvent evt) raises (DOMException); */
  NS_IMETHOD DispatchEvent(nsIDOMEvent *evt, bool *_retval) = 0;

  /* [nostdcall,notxpcom] EventTargetPtr GetTargetForDOMEvent (); */
  virtual mozilla::dom::EventTarget * GetTargetForDOMEvent(void) = 0;

  /* [nostdcall,notxpcom] EventTargetPtr GetTargetForEventTargetChain (); */
  virtual mozilla::dom::EventTarget * GetTargetForEventTargetChain(void) = 0;

  /* [noscript,nostdcall] void PreHandleEvent (in nsEventChainPreVisitorRef aVisitor); */
  virtual nsresult PreHandleEvent(nsEventChainPreVisitor & aVisitor) = 0;

  /* [noscript,nostdcall] void WillHandleEvent (in nsEventChainPostVisitorRef aVisitor); */
  virtual nsresult WillHandleEvent(nsEventChainPostVisitor & aVisitor) = 0;

  /* [noscript,nostdcall] void PostHandleEvent (in nsEventChainPostVisitorRef aVisitor); */
  virtual nsresult PostHandleEvent(nsEventChainPostVisitor & aVisitor) = 0;

  /* [noscript,nostdcall] void DispatchDOMEvent (in WidgetEventPtr aEvent, in nsIDOMEvent aDOMEvent, in nsPresContextPtr aPresContext, in nsEventStatusPtr aEventStatus); */
  virtual nsresult DispatchDOMEvent(mozilla::WidgetEvent *aEvent, nsIDOMEvent *aDOMEvent, nsPresContext *aPresContext, nsEventStatus *aEventStatus) = 0;

  /* [nostdcall,notxpcom] nsIScriptContext GetContextForEventHandlers (out nsresult aRv); */
  virtual nsIScriptContext * GetContextForEventHandlers(nsresult *aRv) = 0;

  /* [nostdcall,notxpcom] JSContextPtr GetJSContextForEventHandlers (); */
  virtual JSContext * GetJSContextForEventHandlers(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMEventTarget, NS_IDOMEVENTTARGET_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMEVENTTARGET \
  NS_IMETHOD AddEventListener(const nsAString & type, nsIDOMEventListener *listener, bool useCapture, bool wantsUntrusted, uint8_t _argc); \
  NS_IMETHOD AddSystemEventListener(const nsAString & type, nsIDOMEventListener *listener, bool aUseCapture, bool aWantsUntrusted, uint8_t _argc); \
  NS_IMETHOD RemoveEventListener(const nsAString & type, nsIDOMEventListener *listener, bool useCapture); \
  NS_IMETHOD RemoveSystemEventListener(const nsAString & type, nsIDOMEventListener *listener, bool aUseCapture); \
  NS_IMETHOD DispatchEvent(nsIDOMEvent *evt, bool *_retval); \
  virtual mozilla::dom::EventTarget * GetTargetForDOMEvent(void); \
  virtual mozilla::dom::EventTarget * GetTargetForEventTargetChain(void); \
  virtual nsresult PreHandleEvent(nsEventChainPreVisitor & aVisitor); \
  virtual nsresult WillHandleEvent(nsEventChainPostVisitor & aVisitor); \
  virtual nsresult PostHandleEvent(nsEventChainPostVisitor & aVisitor); \
  virtual nsresult DispatchDOMEvent(mozilla::WidgetEvent *aEvent, nsIDOMEvent *aDOMEvent, nsPresContext *aPresContext, nsEventStatus *aEventStatus); \
  virtual nsIScriptContext * GetContextForEventHandlers(nsresult *aRv); \
  virtual JSContext * GetJSContextForEventHandlers(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMEVENTTARGET(_to) \
  NS_IMETHOD AddEventListener(const nsAString & type, nsIDOMEventListener *listener, bool useCapture, bool wantsUntrusted, uint8_t _argc) { return _to AddEventListener(type, listener, useCapture, wantsUntrusted, _argc); } \
  NS_IMETHOD AddSystemEventListener(const nsAString & type, nsIDOMEventListener *listener, bool aUseCapture, bool aWantsUntrusted, uint8_t _argc) { return _to AddSystemEventListener(type, listener, aUseCapture, aWantsUntrusted, _argc); } \
  NS_IMETHOD RemoveEventListener(const nsAString & type, nsIDOMEventListener *listener, bool useCapture) { return _to RemoveEventListener(type, listener, useCapture); } \
  NS_IMETHOD RemoveSystemEventListener(const nsAString & type, nsIDOMEventListener *listener, bool aUseCapture) { return _to RemoveSystemEventListener(type, listener, aUseCapture); } \
  NS_IMETHOD DispatchEvent(nsIDOMEvent *evt, bool *_retval) { return _to DispatchEvent(evt, _retval); } \
  virtual mozilla::dom::EventTarget * GetTargetForDOMEvent(void) { return _to GetTargetForDOMEvent(); } \
  virtual mozilla::dom::EventTarget * GetTargetForEventTargetChain(void) { return _to GetTargetForEventTargetChain(); } \
  virtual nsresult PreHandleEvent(nsEventChainPreVisitor & aVisitor) { return _to PreHandleEvent(aVisitor); } \
  virtual nsresult WillHandleEvent(nsEventChainPostVisitor & aVisitor) { return _to WillHandleEvent(aVisitor); } \
  virtual nsresult PostHandleEvent(nsEventChainPostVisitor & aVisitor) { return _to PostHandleEvent(aVisitor); } \
  virtual nsresult DispatchDOMEvent(mozilla::WidgetEvent *aEvent, nsIDOMEvent *aDOMEvent, nsPresContext *aPresContext, nsEventStatus *aEventStatus) { return _to DispatchDOMEvent(aEvent, aDOMEvent, aPresContext, aEventStatus); } \
  virtual nsIScriptContext * GetContextForEventHandlers(nsresult *aRv) { return _to GetContextForEventHandlers(aRv); } \
  virtual JSContext * GetJSContextForEventHandlers(void) { return _to GetJSContextForEventHandlers(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMEVENTTARGET(_to) \
  NS_IMETHOD AddEventListener(const nsAString & type, nsIDOMEventListener *listener, bool useCapture, bool wantsUntrusted, uint8_t _argc) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddEventListener(type, listener, useCapture, wantsUntrusted, _argc); } \
  NS_IMETHOD AddSystemEventListener(const nsAString & type, nsIDOMEventListener *listener, bool aUseCapture, bool aWantsUntrusted, uint8_t _argc) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddSystemEventListener(type, listener, aUseCapture, aWantsUntrusted, _argc); } \
  NS_IMETHOD RemoveEventListener(const nsAString & type, nsIDOMEventListener *listener, bool useCapture) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveEventListener(type, listener, useCapture); } \
  NS_IMETHOD RemoveSystemEventListener(const nsAString & type, nsIDOMEventListener *listener, bool aUseCapture) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveSystemEventListener(type, listener, aUseCapture); } \
  NS_IMETHOD DispatchEvent(nsIDOMEvent *evt, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->DispatchEvent(evt, _retval); } \
  virtual mozilla::dom::EventTarget * GetTargetForDOMEvent(void); \
  virtual mozilla::dom::EventTarget * GetTargetForEventTargetChain(void); \
  virtual nsresult PreHandleEvent(nsEventChainPreVisitor & aVisitor) { return !_to ? NS_ERROR_NULL_POINTER : _to->PreHandleEvent(aVisitor); } \
  virtual nsresult WillHandleEvent(nsEventChainPostVisitor & aVisitor) { return !_to ? NS_ERROR_NULL_POINTER : _to->WillHandleEvent(aVisitor); } \
  virtual nsresult PostHandleEvent(nsEventChainPostVisitor & aVisitor) { return !_to ? NS_ERROR_NULL_POINTER : _to->PostHandleEvent(aVisitor); } \
  virtual nsresult DispatchDOMEvent(mozilla::WidgetEvent *aEvent, nsIDOMEvent *aDOMEvent, nsPresContext *aPresContext, nsEventStatus *aEventStatus) { return !_to ? NS_ERROR_NULL_POINTER : _to->DispatchDOMEvent(aEvent, aDOMEvent, aPresContext, aEventStatus); } \
  virtual nsIScriptContext * GetContextForEventHandlers(nsresult *aRv); \
  virtual JSContext * GetJSContextForEventHandlers(void); 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMEventTarget : public nsIDOMEventTarget
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMEVENTTARGET

  nsDOMEventTarget();

private:
  ~nsDOMEventTarget();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMEventTarget, nsIDOMEventTarget)

nsDOMEventTarget::nsDOMEventTarget()
{
  /* member initializers and constructor code */
}

nsDOMEventTarget::~nsDOMEventTarget()
{
  /* destructor code */
}

/* [optional_argc] void addEventListener (in DOMString type, in nsIDOMEventListener listener, [optional] in boolean useCapture, [optional] in boolean wantsUntrusted); */
NS_IMETHODIMP nsDOMEventTarget::AddEventListener(const nsAString & type, nsIDOMEventListener *listener, bool useCapture, bool wantsUntrusted, uint8_t _argc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,optional_argc] void addSystemEventListener (in DOMString type, in nsIDOMEventListener listener, [optional] in boolean aUseCapture, [optional] in boolean aWantsUntrusted); */
NS_IMETHODIMP nsDOMEventTarget::AddSystemEventListener(const nsAString & type, nsIDOMEventListener *listener, bool aUseCapture, bool aWantsUntrusted, uint8_t _argc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeEventListener (in DOMString type, in nsIDOMEventListener listener, [optional] in boolean useCapture); */
NS_IMETHODIMP nsDOMEventTarget::RemoveEventListener(const nsAString & type, nsIDOMEventListener *listener, bool useCapture)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void removeSystemEventListener (in DOMString type, in nsIDOMEventListener listener, [optional] in boolean aUseCapture); */
NS_IMETHODIMP nsDOMEventTarget::RemoveSystemEventListener(const nsAString & type, nsIDOMEventListener *listener, bool aUseCapture)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean dispatchEvent (in nsIDOMEvent evt) raises (DOMException); */
NS_IMETHODIMP nsDOMEventTarget::DispatchEvent(nsIDOMEvent *evt, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [nostdcall,notxpcom] EventTargetPtr GetTargetForDOMEvent (); */
mozilla::dom::EventTarget * nsDOMEventTarget::GetTargetForDOMEvent()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [nostdcall,notxpcom] EventTargetPtr GetTargetForEventTargetChain (); */
mozilla::dom::EventTarget * nsDOMEventTarget::GetTargetForEventTargetChain()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,nostdcall] void PreHandleEvent (in nsEventChainPreVisitorRef aVisitor); */
nsresult nsDOMEventTarget::PreHandleEvent(nsEventChainPreVisitor & aVisitor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,nostdcall] void WillHandleEvent (in nsEventChainPostVisitorRef aVisitor); */
nsresult nsDOMEventTarget::WillHandleEvent(nsEventChainPostVisitor & aVisitor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,nostdcall] void PostHandleEvent (in nsEventChainPostVisitorRef aVisitor); */
nsresult nsDOMEventTarget::PostHandleEvent(nsEventChainPostVisitor & aVisitor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,nostdcall] void DispatchDOMEvent (in WidgetEventPtr aEvent, in nsIDOMEvent aDOMEvent, in nsPresContextPtr aPresContext, in nsEventStatusPtr aEventStatus); */
nsresult nsDOMEventTarget::DispatchDOMEvent(mozilla::WidgetEvent *aEvent, nsIDOMEvent *aDOMEvent, nsPresContext *aPresContext, nsEventStatus *aEventStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [nostdcall,notxpcom] nsIScriptContext GetContextForEventHandlers (out nsresult aRv); */
nsIScriptContext * nsDOMEventTarget::GetContextForEventHandlers(nsresult *aRv)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [nostdcall,notxpcom] JSContextPtr GetJSContextForEventHandlers (); */
JSContext * nsDOMEventTarget::GetJSContextForEventHandlers()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#define NS_IMPL_DOMTARGET_DEFAULTS(_class) \
mozilla::dom::EventTarget* _class::GetTargetForDOMEvent() { return this; } \
mozilla::dom::EventTarget* _class::GetTargetForEventTargetChain() { return this; } \
nsresult _class::WillHandleEvent(nsEventChainPostVisitor& aVisitor) { return NS_OK; } \
JSContext* _class::GetJSContextForEventHandlers() { return nullptr; }
#define NS_IMPL_REMOVE_SYSTEM_EVENT_LISTENER(aClass) \
NS_IMETHODIMP \
aClass::RemoveSystemEventListener(const nsAString& aType, \
                                  nsIDOMEventListener *aListener, \
                                  bool aUseCapture) \
{ \
  mozilla::EventListenerManager* listenerManager = \
    GetExistingListenerManager(); \
  if (!listenerManager) { \
    return NS_OK; \
  } \
  mozilla::EventListenerFlags flags; \
  flags.mInSystemGroup = true; \
  flags.mCapture = aUseCapture; \
  listenerManager->RemoveEventListenerByType(aListener, aType, flags); \
  return NS_OK; \
}

#endif /* __gen_nsIDOMEventTarget_h__ */
