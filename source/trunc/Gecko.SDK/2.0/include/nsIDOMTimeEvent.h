/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/dom/interfaces/smil/nsIDOMTimeEvent.idl
 */

#ifndef __gen_nsIDOMTimeEvent_h__
#define __gen_nsIDOMTimeEvent_h__


#ifndef __gen_nsIDOMEvent_h__
#include "nsIDOMEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMTimeEvent */
#define NS_IDOMTIMEEVENT_IID_STR "0d309c26-ddbb-44cb-9af1-3008972349e3"

#define NS_IDOMTIMEEVENT_IID \
  {0x0d309c26, 0xddbb, 0x44cb, \
    { 0x9a, 0xf1, 0x30, 0x08, 0x97, 0x23, 0x49, 0xe3 }}

/**
 * The SMIL TimeEvent interface.
 *
 * For more information please refer to:
 * http://www.w3.org/TR/SMIL/smil-timing.html#Events-TimeEvent
 * http://www.w3.org/TR/SVG/animate.html#InterfaceTimeEvent
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMTimeEvent : public nsIDOMEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMTIMEEVENT_IID)

  /* readonly attribute long detail; */
  NS_SCRIPTABLE NS_IMETHOD GetDetail(PRInt32 *aDetail) = 0;

  /* readonly attribute nsIDOMAbstractView view; */
  NS_SCRIPTABLE NS_IMETHOD GetView(nsIDOMAbstractView **aView) = 0;

  /* void initTimeEvent (in DOMString typeArg, in nsIDOMAbstractView viewArg, in long detailArg); */
  NS_SCRIPTABLE NS_IMETHOD InitTimeEvent(const nsAString & typeArg, nsIDOMAbstractView *viewArg, PRInt32 detailArg) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMTimeEvent, NS_IDOMTIMEEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMTIMEEVENT \
  NS_SCRIPTABLE NS_IMETHOD GetDetail(PRInt32 *aDetail); \
  NS_SCRIPTABLE NS_IMETHOD GetView(nsIDOMAbstractView **aView); \
  NS_SCRIPTABLE NS_IMETHOD InitTimeEvent(const nsAString & typeArg, nsIDOMAbstractView *viewArg, PRInt32 detailArg); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMTIMEEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetDetail(PRInt32 *aDetail) { return _to GetDetail(aDetail); } \
  NS_SCRIPTABLE NS_IMETHOD GetView(nsIDOMAbstractView **aView) { return _to GetView(aView); } \
  NS_SCRIPTABLE NS_IMETHOD InitTimeEvent(const nsAString & typeArg, nsIDOMAbstractView *viewArg, PRInt32 detailArg) { return _to InitTimeEvent(typeArg, viewArg, detailArg); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMTIMEEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetDetail(PRInt32 *aDetail) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDetail(aDetail); } \
  NS_SCRIPTABLE NS_IMETHOD GetView(nsIDOMAbstractView **aView) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetView(aView); } \
  NS_SCRIPTABLE NS_IMETHOD InitTimeEvent(const nsAString & typeArg, nsIDOMAbstractView *viewArg, PRInt32 detailArg) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitTimeEvent(typeArg, viewArg, detailArg); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMTimeEvent : public nsIDOMTimeEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMTIMEEVENT

  nsDOMTimeEvent();

private:
  ~nsDOMTimeEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMTimeEvent, nsIDOMTimeEvent)

nsDOMTimeEvent::nsDOMTimeEvent()
{
  /* member initializers and constructor code */
}

nsDOMTimeEvent::~nsDOMTimeEvent()
{
  /* destructor code */
}

/* readonly attribute long detail; */
NS_IMETHODIMP nsDOMTimeEvent::GetDetail(PRInt32 *aDetail)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMAbstractView view; */
NS_IMETHODIMP nsDOMTimeEvent::GetView(nsIDOMAbstractView **aView)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initTimeEvent (in DOMString typeArg, in nsIDOMAbstractView viewArg, in long detailArg); */
NS_IMETHODIMP nsDOMTimeEvent::InitTimeEvent(const nsAString & typeArg, nsIDOMAbstractView *viewArg, PRInt32 detailArg)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMTimeEvent_h__ */
