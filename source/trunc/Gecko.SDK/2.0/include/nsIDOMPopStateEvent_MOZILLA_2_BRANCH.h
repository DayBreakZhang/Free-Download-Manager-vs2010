/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/dom/interfaces/events/nsIDOMPopStateEvent_MOZILLA_2_BRANCH.idl
 */

#ifndef __gen_nsIDOMPopStateEvent_MOZILLA_2_BRANCH_h__
#define __gen_nsIDOMPopStateEvent_MOZILLA_2_BRANCH_h__


#ifndef __gen_nsIDOMPopStateEvent_h__
#include "nsIDOMPopStateEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMPopStateEvent_MOZILLA_2_BRANCH */
#define NS_IDOMPOPSTATEEVENT_MOZILLA_2_BRANCH_IID_STR "a0273086-e5da-4da6-a219-930235f9bfef"

#define NS_IDOMPOPSTATEEVENT_MOZILLA_2_BRANCH_IID \
  {0xa0273086, 0xe5da, 0x4da6, \
    { 0xa2, 0x19, 0x93, 0x02, 0x35, 0xf9, 0xbf, 0xef }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMPopStateEvent_MOZILLA_2_BRANCH : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMPOPSTATEEVENT_MOZILLA_2_BRANCH_IID)

  /**
   * initial is true if the event is being fired due to an onload, and false
   * otherwise.
   */
  /* readonly attribute boolean initial; */
  NS_SCRIPTABLE NS_IMETHOD GetInitial(PRBool *aInitial) = 0;

  /* void initPopStateEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in nsIVariant stateArg, [optional] in boolean isInitial); */
  NS_SCRIPTABLE NS_IMETHOD InitPopStateEvent(const nsAString & typeArg, PRBool canBubbleArg, PRBool cancelableArg, nsIVariant *stateArg, PRBool isInitial) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMPopStateEvent_MOZILLA_2_BRANCH, NS_IDOMPOPSTATEEVENT_MOZILLA_2_BRANCH_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMPOPSTATEEVENT_MOZILLA_2_BRANCH \
  NS_SCRIPTABLE NS_IMETHOD GetInitial(PRBool *aInitial); \
  NS_SCRIPTABLE NS_IMETHOD InitPopStateEvent(const nsAString & typeArg, PRBool canBubbleArg, PRBool cancelableArg, nsIVariant *stateArg, PRBool isInitial); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMPOPSTATEEVENT_MOZILLA_2_BRANCH(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetInitial(PRBool *aInitial) { return _to GetInitial(aInitial); } \
  NS_SCRIPTABLE NS_IMETHOD InitPopStateEvent(const nsAString & typeArg, PRBool canBubbleArg, PRBool cancelableArg, nsIVariant *stateArg, PRBool isInitial) { return _to InitPopStateEvent(typeArg, canBubbleArg, cancelableArg, stateArg, isInitial); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMPOPSTATEEVENT_MOZILLA_2_BRANCH(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetInitial(PRBool *aInitial) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInitial(aInitial); } \
  NS_SCRIPTABLE NS_IMETHOD InitPopStateEvent(const nsAString & typeArg, PRBool canBubbleArg, PRBool cancelableArg, nsIVariant *stateArg, PRBool isInitial) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitPopStateEvent(typeArg, canBubbleArg, cancelableArg, stateArg, isInitial); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMPopStateEvent_MOZILLA_2_BRANCH : public nsIDOMPopStateEvent_MOZILLA_2_BRANCH
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMPOPSTATEEVENT_MOZILLA_2_BRANCH

  nsDOMPopStateEvent_MOZILLA_2_BRANCH();

private:
  ~nsDOMPopStateEvent_MOZILLA_2_BRANCH();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMPopStateEvent_MOZILLA_2_BRANCH, nsIDOMPopStateEvent_MOZILLA_2_BRANCH)

nsDOMPopStateEvent_MOZILLA_2_BRANCH::nsDOMPopStateEvent_MOZILLA_2_BRANCH()
{
  /* member initializers and constructor code */
}

nsDOMPopStateEvent_MOZILLA_2_BRANCH::~nsDOMPopStateEvent_MOZILLA_2_BRANCH()
{
  /* destructor code */
}

/* readonly attribute boolean initial; */
NS_IMETHODIMP nsDOMPopStateEvent_MOZILLA_2_BRANCH::GetInitial(PRBool *aInitial)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initPopStateEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in nsIVariant stateArg, [optional] in boolean isInitial); */
NS_IMETHODIMP nsDOMPopStateEvent_MOZILLA_2_BRANCH::InitPopStateEvent(const nsAString & typeArg, PRBool canBubbleArg, PRBool cancelableArg, nsIVariant *stateArg, PRBool isInitial)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMPopStateEvent_MOZILLA_2_BRANCH_h__ */
